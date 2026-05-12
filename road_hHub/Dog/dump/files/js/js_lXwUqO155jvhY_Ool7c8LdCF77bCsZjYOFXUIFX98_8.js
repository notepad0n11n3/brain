(function (CKEditor5) {

"use strict";

/**
 * Backdrop-specific plugin to alter the CKEditor 5 basic tags.
 */
class BackdropBasicStyles extends CKEditor5.core.Plugin {
  /**
   * @inheritdoc
   */
  static get pluginName() {
    return 'BackdropBasicStyles';
  }

  /**
   * @inheritdoc
   */
  init() {
    const editor = this.editor;

    // CKEditor prefers <i> but Backdrop prefers <em>.
    editor.conversion.for('downcast').attributeToElement({
      model: 'italic',
      view: 'em',
      converterPriority: 'high',
    });
    // CKEditor prefers <s> but Backdrop prefers <del>.
    editor.conversion.for('downcast').attributeToElement({
      model: 'strikethrough',
      view: 'del',
      converterPriority: 'high',
    });
    // Backdrop previously preferred <span class="underline">. This converts it
    // to <u> tags preferred by CKEditor 5.
    editor.conversion.for('upcast').elementToAttribute({
      model: 'underline',
      view: {
        name: 'span',
        classes: ['underline'],
      },
      converterPriority: 'low',
    });

    // Support a minimum height option on the editor.
    // See https://stackoverflow.com/a/56550285/845793
    // @todo: Move this functionality or rename the entire plugin?
    const minHeight = editor.config.get('minHeight');
    if (minHeight) {
      editor.ui.view.editable.extendTemplate({
        attributes: {
          style: {
            minHeight: minHeight,
          }
        }
      });
    }
  }
}

// Expose the plugin to the CKEditor5 namespace.
CKEditor5.backdropBasicStyles = {
  'BackdropBasicStyles': BackdropBasicStyles
};

})(CKEditor5);
;
(function (Backdrop, CKEditor5) {

"use strict";

/**
 * A plugin that overrides the CKEditor HTML writer.
 *
 * Overrides the CKEditor 5 HTML writer to properly escape HTML attributes.
 *
 * In particular this makes it so that `<` and `>` characters are escaped when
 * used within the data-caption attribute, allowing caption text to be linked
 * or styled as bold, italic, etc.
 *
 * @see https://github.com/ckeditor/ckeditor5/issues/15293
 * @see https://github.com/backdrop-contrib/ckeditor5/issues/68
 */
class BackdropHtmlEngine extends CKEditor5.core.Plugin {
  /**
   * @inheritdoc
   */
  static get pluginName() {
    return 'BackdropHtmlEngine';
  }

  /**
   * @inheritdoc
   */
  init() {
    this.editor.data.processor.htmlWriter = new BackdropHtmlWriter();
  }
}

// Expose the plugin to the CKEditor5 namespace.
CKEditor5.backdropHtmlEngine = {
  'BackdropHtmlEngine': BackdropHtmlEngine
};

/**
 * Custom HTML writer. It creates HTML by traversing DOM nodes.
 *
 * It differs to CKEditor's core BasicHtmlWriter in the way it encodes entities
 * in element attributes.
 *
 * @see https://ckeditor.com/docs/ckeditor5/latest/api/module_engine_dataprocessor_basichtmlwriter-BasicHtmlWriter.html
 */
class BackdropHtmlWriter {
  /**
   * Returns an HTML string created from the document fragment.
   *
   * @param {Element} fragment
   * @return {String}
   */
  getHtml(fragment) {
    return Backdrop.ckeditor5.elementGetHtml(fragment);
  }
}

})(Backdrop, CKEditor5);
;
/**
 * @file
 * Contains BackdropImage CKEditor 5 plugin and its dependent classes.
 */
(function (CKEditor5) {

"use strict";

/**
 * BackdropImage CKEditor 5 plugin.
 *
 * This complex plugin provides several pieces of key functionality:
 *
 * - Provides an image upload adapter to save images to Backdrop's file system.
 * - Saves data-file-id attributes on img tags which Backdrop uses to track
 *   where files are being used.
 * - Connects to a Backdrop-native dialog via an AJAX request.
 *
 * If this were developed under the normal CKEditor build process, this would
 * likely be split into multiple plugins and files. Backdrop does not use a
 * compilation step, so what is normally 5-8 files is all done in a single file.
 */
class BackdropImage extends CKEditor5.core.Plugin {
  /**
   * @inheritdoc
   */
  static get requires() {
    return ['ImageUtils', 'FileRepository', 'Image', 'WidgetToolbarRepository', 'ContextualBalloon'];
  }

  /**
   * @inheritdoc
   */
  static get pluginName() {
    return 'BackdropImage';
  }

  /**
   * @inheritdoc
   */
  init() {
    const editor = this.editor;
    const { conversion } = editor;
    const { schema } = editor.model;
    const config = editor.config.get('backdropImage');
    const editLabel = config.editLabel || 'Edit Image';
    const insertLabel = config.insertLabel || 'Insert Image';

    if (!config.extraAttributes) {
      return;
    }

    // Add extra supported attributes to the image models.
    if (schema.isRegistered('imageInline')) {
      schema.extend('imageInline', {
        allowAttributes: Object.keys(config.extraAttributes)
      });
    }
    if (schema.isRegistered('imageBlock')) {
      schema.extend('imageBlock', {
        allowAttributes: Object.keys(config.extraAttributes)
      });
    }

    // Upcast from the raw <img> element to the CKEditor model.
    conversion
      .for('upcast')
      .add(viewImageToModelImage(editor));

    // Upcast any wrapping <a> element to be part of the CKEditor model.
    if (editor.plugins.has('DataFilter')) {
      const dataFilter = editor.plugins.get('DataFilter');
      conversion
        .for('upcast')
        .add(upcastImageBlockLinkGhsAttributes(dataFilter));
    }

    // Downcast from the CKEditor model to an HTML <img> element. This generic
    // downcast runs both while editing and when saving the final HTML.
    conversion
      .for('downcast')
      // Convert the FileId to data-file-id attribute.
      .add(modelFileIdToDataAttribute());

    // Downcast from the CKEditor model to an HTML <img> element. A dataDowncast
    // conversion like this only runs on saving the final HTML, not while the
    // editor is being used.
    conversion
      .for('dataDowncast')
      // Pull out the caption if present. This needs to be done before other
      // conversions because afterward the caption element is eleminated.
      .add(viewCaptionToCaptionAttribute(editor))
      // Create a blank image element, removing any wrapping figure element.
      .elementToElement({
        model: 'imageBlock',
        view: (modelElement, { writer }) => {
          return writer.createEmptyElement('img');
        },
        converterPriority: 'high',
      })
      .elementToElement({
        model: 'imageInline',
        view: (modelElement, { writer }) => {
          return writer.createEmptyElement('img');
        },
        converterPriority: 'high',
      })
      // Convert ImageStyle to data-align attribute.
      .add(modelImageStyleToDataAttribute(editor))
      // Convert height and width attributes.
      .add(modelImageWidthAndHeightToAttributes(editor))
      // Convert any link to wrap the <img> tag.
      .add(downcastBlockImageLink());

    // Add the backdropImage command.
    editor.commands.add('backdropImage', new BackdropImageCommand(editor));

    // Add the editBackdropImage button, for use in the balloon toolbar.
    // This button has a different icon than the main toolbar button.
    editor.ui.componentFactory.add('editBackdropImage', (locale) => {
      const command = editor.commands.get('backdropImage');
      const buttonView = new CKEditor5.ui.ButtonView(locale);
      buttonView.set({
        label: editLabel,
        icon: CKEditor5.core.icons.pencil,
        tooltip: true
      });

      // When clicking the balloon button, execute the backdropImage command.
      buttonView.on('execute', () => {
        // See BackdropImageCommand::execute().
        command.execute();
      });

      return buttonView;
    });

    // Add the backdropImage button for use in the main toolbar. This can
    // insert a new image or edit an existing one if selected.
    editor.ui.componentFactory.add('backdropImage', (locale) => {
      const buttonView = new CKEditor5.ui.ButtonView(locale);
      const command = editor.commands.get('backdropImage');

      buttonView.set({
        label: insertLabel,
        icon: CKEditor5.core.icons.image,
        tooltip: true
      });

      // Highlight the image button when an image is selected.
      buttonView.bind('isOn').to(command, 'value');

      // Change the label when an image is selected.
      buttonView.bind('label').to(command, 'value', (value) => {
        return value ? editLabel : insertLabel
      });

      // Disable the button when the command is disabled by source mode.
      buttonView.bind('isEnabled').to(command, 'isEnabled');

      // When clicking the toolbar button, execute the backdropImage command.
      buttonView.on('execute', () => {
        // Remove focus from the toolbar button when opening the dialog.
        // Otherwise, the button may receive focus again after closing the
        // dialog.
        buttonView.element.blur();
        // See BackdropImageCommand::execute().
        command.execute();
      });

      return buttonView;
    });

    // Attach the file upload adapter to handle saving files.
    if (!config.uploadUrl) {
      throw new Error('Missing backdropImage.uploadUrl configuration option.');
    }
    editor.plugins.get('FileRepository').createUploadAdapter = (loader) => {
      return new BackdropImageUploadAdapter(loader, editor, config);
    };

    // Upon completing an uploaded file, save the returned File ID.
    const imageUploadEditing = editor.plugins.get('ImageUploadEditing');
    imageUploadEditing.on('uploadComplete', (evt, { data, imageElement }) => {
      editor.model.change((writer) => {
        writer.setAttribute('dataFileId', data.response.fileId, imageElement);
      });
    });
  }

}

// Expose the plugin to the CKEditor5 namespace.
CKEditor5.backdropImage = {
  'BackdropImage': BackdropImage
};

/**
 * Helper function for the downcast converter.
 *
 * Sets attributes on the given view element. This function is copied from
 * the General HTML Support plugin.
 * See https://ckeditor.com/docs/ckeditor5/latest/api/module_html-support_conversionutils.html#function-setViewAttributes
 *
 * @param writer The view writer.
 * @param viewAttributes The GHS attribute value.
 * @param viewElement The view element to update.
 */
function setViewAttributes(writer, viewAttributes, viewElement) {
  if (viewAttributes.attributes) {
    for (const [key, value] of Object.entries(viewAttributes.attributes)) {
      writer.setAttribute(key, value, viewElement);
    }
  }

  if (viewAttributes.styles) {
    writer.setStyle(viewAttributes.styles, viewElement);
  }

  if (viewAttributes.classes ) {
    writer.addClass(viewAttributes.classes, viewElement);
  }
}

/**
 * Generates a callback that saves the File ID to an attribute on downcast.
 *
 * @return {function}
 *  Callback that binds an event to its parameter.
 *
 * @private
 */
function modelFileIdToDataAttribute() {
  /**
   * Callback for the attribute:dataFileId event.
   *
   * Saves the File ID value to the data-file-id attribute.
   *
   * @param {Event} event
   * @param {object} data
   * @param {module:engine/conversion/downcastdispatcher~DowncastConversionApi} conversionApi
   */
  function converter(event, data, conversionApi) {
    const { item } = data;
    const { consumable, writer } = conversionApi;

    if (!consumable.consume(item, event.name)) {
      return;
    }

    const viewElement = conversionApi.mapper.toViewElement(item);
    const imageInFigure = Array.from(viewElement.getChildren()).find(
      (child) => child.name === 'img',
    );

    writer.setAttribute(
      'data-file-id',
      data.attributeNewValue,
      imageInFigure || viewElement,
    );
  }

  return (dispatcher) => {
    dispatcher.on('attribute:dataFileId', converter);
  };
}

/**
 * A mapping between the CKEditor model names and the data-align attribute.
 *
 * @type {Array.<{dataValue: string, modelValue: string}>}
 */
const alignmentMapping = [
  {
    modelValue: 'alignCenter',
    dataValue: 'center',
  },
  {
    modelValue: 'alignRight',
    dataValue: 'right',
  },
  {
    modelValue: 'alignLeft',
    dataValue: 'left',
  },
];

/**
 * Given an imageStyle, return the associated Backdrop data-align attribute.
 *
 * @param string imageStyle
 *   The image style such as alignLeft, alignCenter, or alignRight.
 * @returns {string|undefined}
 *   The data attribute value such as left, center, or right.
 * @private
 */
function _getDataAttributeFromModelImageStyle(imageStyle) {
  const mappedAlignment = alignmentMapping.find(
    (value) => value.modelValue === imageStyle,
  );
  return mappedAlignment ? mappedAlignment.dataValue : undefined;
}

/**
 * Given a data-attribute, return the associated CKEditor image style.
 *
 * @param string dataAttribute
 *   The data attribute value such as left, center, or right.
 * @returns {string|undefined}
 *   The image style such as alignLeft, alignCenter, or alignRight.
 * @private
 */
function _getModelImageStyleFromDataAttribute(dataAttribute) {
  const mappedAlignment = alignmentMapping.find(
    (value) => value.dataValue === dataAttribute,
  );
  return mappedAlignment ? mappedAlignment.modelValue : undefined;
}

/**
 * Given width, height, and resizedWidth, return updated width and height.
 *
 * @param string width
 *   The image attribute width in pixels, may contain a 'px' suffix.
 * @param string height
 *   The image attribute height in pixels, may contain a 'px' suffix.
 * @param string resizedWidth
 *   The displayed width after resizing, may contain a 'px' suffix.
 * @returns {Array}
 *   The calculated width and height based on the ratio from the resizedWidth.
 * @private
 */
function _getResizedWidthHeight(width, height, resizedWidth) {
  // Normalize each of the attributes.
  width = Number(width.toString().replace('px', ''));
  height = Number(height.toString().replace('px', ''));
  resizedWidth = Number(resizedWidth.toString().replace('px', ''));

  const ratio = width / resizedWidth;
  const newWidth = resizedWidth.toString();
  const newHeight = Math.round(height / ratio).toString();
  return [newWidth, newHeight];
}

/**
 * Downcasts `caption` model to `data-caption` attribute with its content
 * downcasted to plain HTML.
 *
 * This is needed because CKEditor 5 uses the `<caption>` element internally in
 * various places, which differs from Backdrop which uses an attribute. For now
 * to support that we have to manually repeat work done in the
 * DowncastDispatcher's private methods.
 *
 * @param {module:core/editor/editor~Editor} editor
 *  The editor instance to use.
 *
 * @return {function}
 *  Callback that binds an event to its parameter.
 *
 * @private
 */
function viewCaptionToCaptionAttribute(editor) {
  /**
   * Callback for the insert:caption event.
   */
  function converter(event, data, conversionApi) {
    const { consumable, writer, mapper } = conversionApi;
    const imageUtils = editor.plugins.get('ImageUtils');

    if (
      !imageUtils.isImage(data.item.parent) ||
      !consumable.consume(data.item, 'insert')
    ) {
      return;
    }

    const range = editor.model.createRangeIn(data.item);
    const viewDocumentFragment = writer.createDocumentFragment();

    // Bind caption model element to the detached view document fragment so
    // all content of the caption will be downcasted into that document
    // fragment.
    mapper.bindElements(data.item, viewDocumentFragment);

    // eslint-disable-next-line no-restricted-syntax
    for (const { item } of Array.from(range)) {
      const itemData = {
        item,
        range: editor.model.createRangeOn(item),
      };

      // The following lines are extracted from
      // DowncastDispatcher._convertInsertWithAttributes().
      const eventName = `insert:${item.name || '$text'}`;

      editor.data.downcastDispatcher.fire(
        eventName,
        itemData,
        conversionApi,
      );

      // eslint-disable-next-line no-restricted-syntax
      for (const key of item.getAttributeKeys()) {
        Object.assign(itemData, {
          attributeKey: key,
          attributeOldValue: null,
          attributeNewValue: itemData.item.getAttribute(key),
        });

        editor.data.downcastDispatcher.fire(
          `attribute:${key}`,
          itemData,
          conversionApi,
        );
      }
    }

    // Unbind all the view elements that were downcast to the document fragment.
    // eslint-disable-next-line no-restricted-syntax
    for (const child of writer
      .createRangeIn(viewDocumentFragment)
      .getItems()) {
      mapper.unbindViewElement(child);
    }

    mapper.unbindViewElement(viewDocumentFragment);

    // Stringify view document fragment to HTML string.
    const captionText = editor.data.processor.toData(viewDocumentFragment);

    if (captionText) {
      const imageViewElement = mapper.toViewElement(data.item.parent);

      writer.setAttribute('data-caption', captionText, imageViewElement);
    }
  }

  return (dispatcher) => {
    dispatcher.on('insert:caption', converter, { priority: 'high' });
  };
}

/**
 * Generates a callback that saves data-align attribute on data downcast.
 *
 * @return {function}
 *  Callback that binds an event to its parameter.
 *
 * @private
 */
function modelImageStyleToDataAttribute(editor) {
  /**
   * Callback for the attribute:imageStyle event.
   *
   * Saves the alignment value to the data-align attribute.
   */
  function converter(event, data, conversionApi) {
    const { item } = data;
    const { consumable, writer } = conversionApi;
    const alignAttribute = _getDataAttributeFromModelImageStyle(data.attributeNewValue);

    // Consume only for the values that can be converted into data-align.
    if (!alignAttribute || !consumable.consume(item, event.name)) {
      return;
    }

    const imageUtils = editor.plugins.get('ImageUtils');
    const viewElement = conversionApi.mapper.toViewElement(item);
    const img = imageUtils.findViewImgElement(viewElement);

    writer.setAttribute(
      'data-align',
      alignAttribute,
      img,
    );
  }

  return (dispatcher) => {
    dispatcher.on('attribute:imageStyle', converter, { priority: 'high' });
  };
}

/**
 * Generates a callback that handles the data downcast for img width and height.
 *
 * @return {function}
 *  Callback that binds an event to its parameter.
 *
 * @private
 */
function modelImageWidthAndHeightToAttributes(editor) {
  /**
   * Callback for the downcast event.
   *
   * This gets called once for every width, height, or resizedWidth attribute
   * that needs to be saved.
   */
  function converter(event, data, conversionApi) {
    const { item } = data;
    const { consumable, writer } = conversionApi;

    if (!consumable.consume(item, event.name)) {
      return;
    }
    const imageUtils = editor.plugins.get('ImageUtils');
    const viewElement = conversionApi.mapper.toViewElement(item);
    const img = imageUtils.findViewImgElement(viewElement);

    // For width and height, update the saved value, removing 'px' value.
    if (data.attributeKey === 'width' || data.attributeKey === 'height') {
      writer.setAttribute(
        data.attributeKey,
        data.attributeNewValue.toString().replace('px', ''),
        img,
      );
    }

    // For a resized image, only the width event fires and the height derives
    // from the width.
    if (data.attributeKey === 'resizedWidth') {
      const resizedWidth = data.attributeNewValue;
      const originalWidth = item.getAttribute('width');
      const originalHeight = item.getAttribute('height');
      const [newWidth, newHeight] = _getResizedWidthHeight(originalWidth, originalHeight, resizedWidth);
      writer.removeAttribute('resizedWidth', img);
      writer.setAttribute('width', newWidth, img);
      writer.setAttribute('height', newHeight, img);
    }
  }

  return (dispatcher) => {
    const listenerAttributes = [
      'width',
      'height',
      'resizedWidth',
      // CKEditor only fires resizedWidth changes when using resizing handles.
      //'resizedHeight',
    ];
    listenerAttributes.forEach((attributeName) => {
      dispatcher.on('attribute:' + attributeName + ':imageInline', converter, {
        priority: 'high',
      });
      dispatcher.on('attribute:' + attributeName + ':imageBlock', converter, {
        priority: 'high',
      });
    });
  };
}

/**
 * Generates a callback that handles the data upcast for the img element.
 *
 * @return {function}
 *  Callback that binds an event to its parameter.
 *
 * @private
 */
function viewImageToModelImage(editor) {
  /**
   * Callback for the element:img event.
   *
   * Handles the Backdrop specific attributes.
   */
  function converter(event, data, conversionApi) {
    const { viewItem } = data;
    const { writer, consumable, safeInsert, updateConversionResult, schema } =
      conversionApi;
    const attributesToConsume = [];

    let image;

    // Not only check if a given `img` view element has been consumed, but also
    // verify it has `src` attribute present.
    if (!consumable.test(viewItem, { name: true, attributes: 'src' })) {
      return;
    }

    const hasDataCaption = consumable.test(viewItem, {
      name: true,
      attributes: 'data-caption',
    });

    // Create image that's allowed in the given context. If the image has a
    // caption, the image must be created as a block image to ensure the caption
    // is not lost on conversion. This is based on the assumption that
    // preserving the image caption is more important to the content creator
    // than preserving the wrapping element that doesn't allow block images.
    if (schema.checkChild(data.modelCursor, 'imageInline') && !hasDataCaption) {
      image = writer.createElement('imageInline', {
        src: viewItem.getAttribute('src'),
      });
    } else {
      image = writer.createElement('imageBlock', {
        src: viewItem.getAttribute('src'),
      });
    }

    // If the view element has a `data-align` attribute, convert that to a
    // CKEditor 5 Image Style. Note these are not related to Backdrop Image
    // Styles provided by Image module.
    // See https://ckeditor.com/docs/ckeditor5/latest/features/images/images-styles.html
    if (
      editor.plugins.has('ImageStyleEditing') &&
      consumable.test(viewItem, { name: true, attributes: 'data-align' })
    ) {
      const dataAlign = viewItem.getAttribute('data-align');
      const imageStyle = _getModelImageStyleFromDataAttribute(dataAlign);

      if (imageStyle) {
        writer.setAttribute('imageStyle', imageStyle, image);

        // Make sure the attribute can be consumed after successful `safeInsert`
        // operation.
        attributesToConsume.push('data-align');
      }
    }

    // Check if the view element has still unconsumed `data-caption` attribute.
    if (hasDataCaption) {
      // Create `caption` model element. Thanks to that element the rest of the
      // `ckeditor5-plugin` converters can recognize this image as a block image
      // with a caption.
      const caption = writer.createElement('caption');

      // Parse HTML from data-caption attribute and upcast it to model fragment.
      const viewFragment = editor.data.processor.toView(
        viewItem.getAttribute('data-caption'),
      );

      // Consumable must know about those newly parsed view elements.
      conversionApi.consumable.constructor.createFrom(
        viewFragment,
        conversionApi.consumable,
      );
      conversionApi.convertChildren(viewFragment, caption);

      // Insert the caption element into image, as a last child.
      writer.append(caption, image);

      // Make sure the attribute can be consumed after successful `safeInsert`
      // operation.
      attributesToConsume.push('data-caption');
    }

    // Save the file ID to the model.
    if (
      consumable.test(viewItem, { name: true, attributes: 'data-file-id' })
    ) {
      writer.setAttribute(
        'dataFileId',
        viewItem.getAttribute('data-file-id'),
        image,
      );
      attributesToConsume.push('data-file-id');
    }

    // If the view src is updated, also update the model.
    if (consumable.test(viewItem, { name: true, attributes: 'src' })) {
      writer.setAttribute(
        'src',
        viewItem.getAttribute('src'),
        image,
      );
      attributesToConsume.push('src');
    }

    // Try to place the image in the allowed position.
    if (!safeInsert(image, data.modelCursor)) {
      return;
    }

    // Mark given element as consumed. Now other converters will not process it
    // anymore.
    consumable.consume(viewItem, {
      name: true,
      attributes: attributesToConsume,
    });

    // Make sure `modelRange` and `modelCursor` is up-to-date after inserting
    // new nodes into the model.
    updateConversionResult(image, data);
  }

  return (dispatcher) => {
    dispatcher.on('element:img', converter, { priority: 'high' });
  };
}

/**
 * General HTML Support integration for attributes on links wrapping images.
 *
 * This plugin needs to integrate with GHS manually because upstream image link
 * plugin GHS integration assumes that the `<a>` element is inside the
 * `<imageBlock>` which is not true in the case of Backdrop.
 *
 * @param {module:html-support/datafilter~DataFilter} dataFilter
 *   The General HTML support data filter.
 *
 * @return {function}
 *   Callback that binds an event to its parameter.
 */
function upcastImageBlockLinkGhsAttributes(dataFilter) {
  /**
   * Callback for the element:img upcast event.
   *
   * @type {converterHandler}
   */
  function converter(event, data, conversionApi) {
    if (!data.modelRange) {
      return;
    }

    const viewImageElement = data.viewItem;
    const viewContainerElement = viewImageElement.parent;

    if (!viewContainerElement.is('element', 'a')) {
      return;
    }
    if (!data.modelRange.getContainedElement().is('element', 'imageBlock')) {
      return;
    }

    const viewAttributes = dataFilter.processViewAttributes(
      viewContainerElement,
      conversionApi,
    );

    if (viewAttributes) {
      conversionApi.writer.setAttribute(
        'htmlLinkAttributes',
        viewAttributes,
        data.modelRange,
      );
    }
  }

  return (dispatcher) => {
    dispatcher.on('element:img', converter, {
      priority: 'high',
    });
  };
}

/**
 * Modified implementation of the linkimageediting.js downcastImageLink().
 *
 * @return {function}
 *  Callback that binds an event to its parameter.
 *
 * @private
 */
function downcastBlockImageLink() {
  /**
   * Callback for the attribute:linkHref event.
   */
  function converter(event, data, conversionApi) {
    if (!conversionApi.consumable.consume(data.item, event.name)) {
      return;
    }

    // The image will be already converted - so it will be present in the view.
    const image = conversionApi.mapper.toViewElement(data.item);
    const writer = conversionApi.writer;

    // 1. Create an empty link element.
    const linkElement = writer.createContainerElement('a', {
      href: data.attributeNewValue,
    });
    // 2. Insert link before the associated image.
    writer.insert(writer.createPositionBefore(image), linkElement);
    // 3. Move the image into the link.
    writer.move(
      writer.createRangeOn(image),
      writer.createPositionAt(linkElement, 0),
    );

    // Modified alternative implementation of Generic HTML Support's
    // addBlockImageLinkAttributeConversion(). This is happening here as well to
    // avoid a race condition with the link element not yet existing.
    if (conversionApi.consumable.consume(data.item, 'attribute:htmlLinkAttributes:imageBlock')) {
      setViewAttributes(
        conversionApi.writer,
        data.item.getAttribute('htmlLinkAttributes'),
        linkElement,
      );
    }
  }

  return (dispatcher) => {
    dispatcher.on('attribute:linkHref:imageBlock', converter, {
      // downcastImageLink specifies 'high', so we need to go higher.
      priority: 'highest',
    });
  };
}

/**
 * CKEditor command that opens the Backdrop image editing dialog.
 */
class BackdropImageCommand extends CKEditor5.core.Command {
  /**
   * @inheritdoc
   */
  refresh() {
    const editor = this.editor;
    const imageUtils = editor.plugins.get('ImageUtils');
    const element = imageUtils.getClosestSelectedImageElement(this.editor.model.document.selection);
    this.isEnabled = true;
    this.value = !!element;
  }

  /**
   * Executes the command.
   */
  execute() {
    const editor = this.editor;
    const config = editor.config.get('backdropImage');
    const imageUtils = editor.plugins.get('ImageUtils');
    const ImageCaptionUtils = editor.plugins.get('ImageCaptionUtils');
    const model = editor.model;
    const imageElement = imageUtils.getClosestSelectedImageElement(model.document.selection);

    // Convert attributes to map for easier looping.
    const extraAttributes = new Map(Object.entries(config.extraAttributes));

    const uploadsEnabled = true; // @todo Set dynamically.
    let existingValues = {};

    if (imageElement) {
      // Most attributes can be directly mapped from the model.
      extraAttributes.forEach((attributeName, modelName) => {
        existingValues[attributeName] = imageElement.getAttribute(modelName);
      });

      // Convert the 'resizedWidth' internal attribute to be the 'width'
      // attribute. Also update 'height' to match.
      const resizedWidth = imageElement.getAttribute('resizedWidth');
      if (existingValues['width'] && existingValues['height'] && resizedWidth) {
        const [newWidth, newHeight] = _getResizedWidthHeight(existingValues['width'], existingValues['height'], resizedWidth);
        existingValues['width'] = newWidth;
        existingValues['height'] = newHeight;
      }

      // Alignment is stored as a CKEditor Image Style.
      const imageStyle = imageElement.getAttribute('imageStyle');
      const alignAttribute = _getDataAttributeFromModelImageStyle(imageStyle);
      existingValues['data-align'] = alignAttribute;

      // The image caption is stored outside the imageElement model and must
      // be retrieved to get its value.
      const imageCaption = ImageCaptionUtils.getCaptionFromImageModelElement(imageElement);
      existingValues['data-has-caption'] = !!imageCaption;
      if (imageCaption && imageCaption.childCount) {
        const captionValue = editor.data.processor.toData(imageCaption.getChild(0));
        existingValues['data-caption'] = captionValue;
      }
    }

    const saveCallback = (dialogValues) => {
      // Map the submitted form values to the CKEditor image model.
      let imageAttributes = {};
      extraAttributes.forEach((attributeName, modelName) => {
        if (dialogValues.attributes[attributeName] !== undefined) {
          imageAttributes[modelName] = dialogValues.attributes[attributeName];
        }
      });

      // Set CKEditor Image Style from the data-align attribute as imageStyle.
      const imageStyle = _getModelImageStyleFromDataAttribute(dialogValues.attributes['data-align']);
      imageAttributes['imageStyle'] = imageStyle;
      if (imageAttributes.hasOwnProperty('dataAlign')) {
        delete imageAttributes['dataAlign'];
      }

      // For updating an existing element:
      if (imageElement) {
        model.change((writer) => {
          writer.removeAttribute('resizedWidth', imageElement);
          writer.setAttributes(imageAttributes, imageElement);
        });

        // If width/height are empty, set to their natural values.
        if (imageAttributes['width'] === '' && imageAttributes['height'] === '') {
          imageUtils.setImageNaturalSizeAttributes(imageElement);
        }

        const imageCaption = ImageCaptionUtils.getCaptionFromImageModelElement(imageElement);
        // Remove an existing caption if disabled.
        if (imageCaption && !dialogValues.attributes['data-has-caption']) {
          editor.execute('toggleImageCaption');
        }
        // Add a caption if enabled and none yet exists.
        if (!imageCaption && dialogValues.attributes['data-has-caption']) {
          editor.execute('toggleImageCaption', { focusCaptionOnShow: true });
        }
      }
      // Inserting a new element:
      else {
        // An imageStyle key (even if undefined) on image insert will cause
        // conflicts in the Image Style plugin, so remove the attribute entirely
        // from the object.
        if (imageAttributes.hasOwnProperty('imageStyle') && !imageAttributes['imageStyle']) {
          delete imageAttributes['imageStyle'];
        }

        // Inserting an image has an unusual way of passing the attributes.
        // See https://ckeditor.com/docs/ckeditor5/latest/api/module_image_image_insertimagecommand-InsertImageCommand.html
        editor.execute('insertImage', { source: [imageAttributes] });

        // Toggle showing the caption after the image is inserted.
        if (dialogValues.attributes['data-has-caption']) {
          editor.execute('toggleImageCaption', { focusCaptionOnShow: true });
        }
      }
    };

    const dialogSettings = {
      title: config.insertLabel || 'Insert Image',
      uploads: uploadsEnabled,
      dialogClass: 'editor-image-dialog'
    };
    Backdrop.ckeditor5.openDialog(editor, config.dialogUrl, existingValues, saveCallback, dialogSettings);
  }
}

/**
 * CKEditor upload adapter that sends a request to Backdrop on file upload.
 *
 * Adapted from @ckeditor5/ckeditor5-upload/src/adapters/simpleuploadadapter
 *
 * @private
 * @implements module:upload/filerepository~UploadAdapter
 */
class BackdropImageUploadAdapter {
  /**
   * Creates a new adapter instance.
   *
   * @param {module:upload/filerepository~FileLoader} loader
   *   The file loader.
   * @param {module:core/editor/editor~Editor} editor
   *  The editor instance.
   * @param {module:upload/adapters/simpleuploadadapter~SimpleUploadConfig} options
   *   The upload options.
   */
  constructor(loader, editor, options) {
    /**
     * FileLoader instance to use during the upload.
     *
     * @member {module:upload/filerepository~FileLoader} #loader
     */
    this.loader = loader;

    /**
     * The configuration of the adapter.
     *
     * @member {module:core/editor/editor~Editor} #editor
     */
    this.editor = editor;

    /**
     * The configuration of the adapter.
     *
     * @member {module:upload/adapters/simpleuploadadapter~SimpleUploadConfig} #options
     */
    this.options = options;
  }

  /**
   * Starts the upload process.
   *
   * @see module:upload/filerepository~UploadAdapter#upload
   * @return {Promise}
   *   Promise that the upload will be processed.
   */
  upload() {
    return this.loader.file.then(
      (file) =>
        new Promise((resolve, reject) => {
          this._initRequest();
          this._initListeners(resolve, reject, file);
          this._sendRequest(file);
        }),
    );
  }

  /**
   * Aborts the upload process.
   *
   * @see module:upload/filerepository~UploadAdapter#abort
   */
  abort() {
    if (this.xhr) {
      this.xhr.abort();
    }
  }

  /**
   * Initializes the `XMLHttpRequest` object using the URL specified as
   *
   * {@link module:upload/adapters/simpleuploadadapter~SimpleUploadConfig#uploadUrl `simpleUpload.uploadUrl`} in the editor's
   * configuration.
   */
  _initRequest() {
    this.xhr = new XMLHttpRequest();

    this.xhr.open('POST', this.options.uploadUrl, true);
    this.xhr.responseType = 'json';
  }

  /**
   * Initializes XMLHttpRequest listeners
   *
   * @private
   *
   * @param {Function} resolve
   *  Callback function to be called when the request is successful.
   * @param {Function} reject
   *  Callback function to be called when the request cannot be completed.
   * @param {File} file
   *  Native File object.
   */
  _initListeners(resolve, reject, file) {
    const xhr = this.xhr;
    const loader = this.loader;
    const editor = this.editor;
    const genericErrorText = `Couldn't upload file: ${file.name}.`;
    const notification = editor.plugins.get('Notification');

    xhr.addEventListener('error', () => reject(genericErrorText));
    xhr.addEventListener('abort', () => reject());
    xhr.addEventListener('load', () => {
      const response = xhr.response;

      if (!response || !response.uploaded) {
        return reject(
          response && response.error && response.error.message
            ? response.error.message
            : genericErrorText,
        );
      }
      // There still may be notifications on upload, like resized images.
      if (response.error && response.error.message) {
        // The warning from Backdrop may contain <em> tags for placeholders.
        const markup = new DOMParser().parseFromString(response.error.message, 'text/html');

        // Set a warning for remaining notifications. This currently renders
        // as a window.alert() call, but may change to be better presented in
        // future versions of CKEditor 5.
        // See https://github.com/ckeditor/ckeditor5/issues/8934
        notification.showWarning(markup.body.textContent, {
          namespace: 'upload:image',
        });
      }

      // Resolve with the `urls` property and pass the response
      // to allow customizing the behavior of features relying on the upload
      // adapters.
      resolve({
        response,
        urls: { default: response.url },
      });
    });

    // Upload progress when it is supported.
    if (xhr.upload) {
      xhr.upload.addEventListener('progress', (evt) => {
        if (evt.lengthComputable) {
          loader.uploadTotal = evt.total;
          loader.uploaded = evt.loaded;
        }
      });
    }
  }

  /**
   * Prepares the data and sends the request.
   *
   * @param {File} file
   *   File instance to be uploaded.
   */
  _sendRequest(file) {
    // Set headers if specified.
    const headers = this.options.headers || {};

    // Use the withCredentials flag if specified.
    const withCredentials = this.options.withCredentials || false;

    Object.keys(headers).forEach((headerName) => {
      this.xhr.setRequestHeader(headerName, headers[headerName]);
    });

    this.xhr.withCredentials = withCredentials;

    // Prepare the form data.
    const data = new FormData();

    data.append('upload', file);

    // Send the request.
    this.xhr.send(data);
  }
}

})(CKEditor5);
;
/**
 * @file
 * Backdrop Link plugin.
 */

(function (Backdrop, CKEditor5) {

"use strict";

/**
 * The BackdropLink plugin replaces and extends the CKEditor core Link plugin.
 *
 * - Adds its own buttons for backdropLink (main toolbar) and backdropLinkImage
 *   (in the image balloon toolbar).
 * - Modifies the balloon toolbar for links. Instead of the edit action using
 *   the balloon to enter the URL, the Backdrop link dialog is used instead.
 * - Extends the editor.execute('link') function to take a 3rd parameter to
 *   apply attributes such as id, rel, and class to links.
 */
class BackdropLink extends CKEditor5.core.Plugin {
  /**
   * @inheritdoc
   */
  static get requires() {
    return ['Link'];
  }

  /**
   * @inheritdoc
   */
  static get pluginName() {
    return 'BackdropLink';
  }

  /**
   * @inheritdoc
   */

  init() {
    const editor = this.editor;
    const config = editor.config.get('backdropLink');

    if (!config.extraAttributes) {
      return;
    }
    // Convert attributes to map for easier looping.
    const extraAttributes = new Map(Object.entries(config.extraAttributes));

    extraAttributes.forEach((attributeName, modelName) => {
      this._allowAndConvertExtraAttribute(modelName, attributeName);
      this._removeExtraAttributeOnUnlinkCommandExecute(modelName);
      this._refreshExtraAttributeValue(modelName);
    });

    this._addExtraAttributeOnLinkCommandExecute(extraAttributes);
    this._addBackdropLinkButtons();
    this._bindBalloon(extraAttributes);
  }

  _allowAndConvertExtraAttribute(modelName, viewName) {
    const editor = this.editor;

    editor.model.schema.extend('$text', { allowAttributes: modelName });

    // Model -> View (DOM)
    editor.conversion.for('downcast').attributeToElement({
      model: modelName,
      view: (value, { writer }) => {
        const linkViewElement = writer.createAttributeElement('a', {
          [ viewName ]: value
        }, { priority: 5 });

        // Without it the isLinkElement() will not recognize the link and the UI
        // will not show up when the user clicks a link.
        writer.setCustomProperty('link', true, linkViewElement);

        return linkViewElement;
      }
    });

    // View (DOM/DATA) -> Model
    // The class attribute should be passed using the special selector 'classes'
    // rather than attributes['class'].
    // See https://ckeditor.com/docs/ckeditor5/latest/support/error-codes.html#error-matcher-pattern-deprecated-attributes-class-key
    const upcastView = { name: 'a' };
    if (viewName === 'class') {
      upcastView['classes'] = true;
    }
    else {
      upcastView['attributes'] = { [ viewName ]: true }
    }
    editor.conversion.for('upcast').elementToAttribute({
      view: upcastView,
      model: {
        key: modelName,
        value: viewElement => viewElement.getAttribute(viewName)
      }
    });
  }

  _addExtraAttributeOnLinkCommandExecute(extraAttributes) {
    const editor = this.editor;
    const linkCommand = editor.commands.get( 'link' );
    let linkCommandExecuting = false;

    linkCommand.on('execute', (evt, args) => {
      // Custom handling is only required if an extra attribute was passed into
      // editor.execute('link', ...).
      if (args.length < 3) {
        return;
      }
      if (linkCommandExecuting) {
        linkCommandExecuting = false;
        return;
      }

      // If the additional attribute was passed, we stop the default execution
      // of the LinkCommand. We're going to create Model#change() block for undo
      // and execute the LinkCommand together with setting the extra attribute.
      evt.stop();

      // Prevent infinite recursion by keeping records of when link command is
      // being executed by this function.
      linkCommandExecuting = true;
      const extraAttributeValues = args[args.length - 1];
      const model = this.editor.model;
      const selection = model.document.selection;
      const imageUtils = editor.plugins.get('ImageUtils');
      const closestImage = imageUtils.getClosestSelectedImageElement(selection);

      // Wrapping the original command execution in a model.change() block to
      // make sure there's a single undo step when the extra attribute is added.
      model.change((writer) => {
        editor.execute('link', ...args);

        // If there is an image within this link, apply the link attributes to
        // the image model's htmlLinkAttributes attribute.
        if (closestImage) {
          const htmlLinkAttributes = { attributes: extraAttributeValues };
          writer.setAttribute('htmlLinkAttributes', htmlLinkAttributes, closestImage);
        }
        // Otherwise find the selected link and apply each attribute.
        else {
          extraAttributes.forEach((attributeName, modelName) => {
            let ranges = [];
            if (selection.isCollapsed) {
              const firstPosition = selection.getFirstPosition();
              const node = firstPosition.textNode || firstPosition.nodeBefore;
              ranges = [ writer.createRangeOn(node) ];
            }
            else {
              ranges = model.schema.getValidRanges(selection.getRanges(), modelName);
            }

            for (const range of ranges) {
              if (extraAttributeValues[attributeName]) {
                writer.setAttribute(modelName, extraAttributeValues[attributeName], range);
              } else {
                writer.removeAttribute(modelName, range);
              }
            }
            writer.removeSelectionAttribute(modelName);
          });
        }
      });
    }, { priority: 'highest' } );
  }

  _removeExtraAttributeOnUnlinkCommandExecute(modelName) {
    const editor = this.editor;
    const unlinkCommand = editor.commands.get('unlink');
    const model = this.editor.model;
    const selection = model.document.selection;

    let isUnlinkingInProgress = false;

    // Make sure all changes are in a single undo step so cancel the original unlink first in the high priority.
    unlinkCommand.on('execute', evt => {
      if (isUnlinkingInProgress) {
        return;
      }

      evt.stop();

      // This single block wraps all changes that should be in a single undo step.
      model.change(() => {
        // Now, in this single "undo block" let the unlink command flow naturally.
        isUnlinkingInProgress = true;

        // Do the unlinking within a single undo step.
        editor.execute('unlink');

        // Let's make sure the next unlinking will also be handled.
        isUnlinkingInProgress = false;

        // The actual integration that removes the extra attribute.
        model.change(writer => {
          // Get ranges to unlink.
          let ranges;

          if (selection.isCollapsed) {
            ranges = [CKEditor5.typing.findAttributeRange(
              selection.getFirstPosition(),
              modelName,
              selection.getAttribute( modelName ),
              model
            )];
          }
          else {
            ranges = model.schema.getValidRanges(selection.getRanges(), modelName);
          }

          // Remove the extra attribute from specified ranges.
          for (const range of ranges) {
            writer.removeAttribute(modelName, range);
          }
        });
      });
    }, { priority: 'high' });
  }

  _refreshExtraAttributeValue(modelName) {
    const editor = this.editor;
    const linkCommand = editor.commands.get('link');
    const model = this.editor.model;
    const selection = model.document.selection;

    linkCommand.set(modelName, null);

    model.document.on('change', () => {
      linkCommand[modelName] = selection.getAttribute(modelName);
    });
  }

  _addBackdropLinkButtons() {
    const editor = this.editor;
    const config = editor.config.get('backdropLink');
    const editLabel = config.editLabel || 'Edit Link';
    const insertLabel = config.insertLabel || 'Insert Link';

    // Add the backdropLink command.
    editor.commands.add('backdropLink', new BackdropLinkCommand(editor));
    const backdropLinkCommand = editor.commands.get('backdropLink');

    // Add the backdropLink button for use in the main toolbar. This can
    // insert a new link or edit an existing one if selected.
    editor.ui.componentFactory.add('backdropLink', (locale) => {
      const buttonView = new CKEditor5.ui.ButtonView(locale);

      buttonView.set({
        label: insertLabel,
        icon: backdropLinkIcon,
        tooltip: true
      });

      // Highlight the link button when a link is selected.
      buttonView.bind('isOn').to(backdropLinkCommand, 'value');

      // Change the label when an image is selected.
      buttonView.bind('label').to(backdropLinkCommand, 'value', (value) => {
        return value ? editLabel : insertLabel
      });

      // Disable the button when the command is disabled by source mode.
      buttonView.bind('isEnabled').to(backdropLinkCommand, 'isEnabled');

      // When clicking the toolbar button, execute the backdropLink command.
      buttonView.on('execute', () => {
        // Remove focus from the toolbar button when opening the dialog.
        // Otherwise, the button may receive focus again after closing the
        // dialog.
        buttonView.element.blur();
        // See BackdropLinkCommand::execute().
        backdropLinkCommand.execute();
      });

      return buttonView;
    });

    // Add the backdropLinkImage button for use in the image toolbar. This can
    // insert a new link or edit an existing one if selected.
    editor.ui.componentFactory.add('backdropLinkImage', (locale) => {
      const buttonView = new CKEditor5.ui.ButtonView(locale);
      const backdropLinkCommand = editor.commands.get('backdropLink');
      buttonView.set( {
        isEnabled: true,
        // Translation provided by CKEditor link plugin:
        label: editor.t('Link image'),
        icon: backdropLinkIcon,
        keystroke: 'Ctrl+K',
        tooltip: true,
        isToggleable: true
      });

      // Bind button to the command.
      buttonView.bind('isEnabled').to(backdropLinkCommand, 'isEnabled');
      buttonView.bind('isOn').to(backdropLinkCommand, 'value');

      this.listenTo(buttonView, 'execute', () => {
        // Show the normal link UI balloon if an image already has a link.
        // This allows unlinking an image or previewing the link URL.
        const selectedModelElement = editor.model.document.selection.getSelectedElement();
        const imageUtils = editor.plugins.get('ImageUtils');
        const linkUI = editor.plugins.get('LinkUI');
        if (imageUtils.isImage(selectedModelElement) && selectedModelElement.hasAttribute('linkHref')) {
          // This is not ideal to call an internal method to show the balloon,
          // but this is the same approach used by LinkImageUI.
          // See https://github.com/ckeditor/ckeditor5/blob/master/packages/ckeditor5-link/src/linkimageui.ts
          linkUI._addActionsView();
        }
        // For new links, open the link dialog directly.
        else {
          backdropLinkCommand.execute();
        }
      });

      return buttonView;
    });

    // Claim the keyboard shortcut for making a link to open the dialog rather
    // than CKEditor's bubble toolbar.
    editor.keystrokes.set('Ctrl+K', (keyEvtData, cancel) => {
      // Prevent focusing the search bar in FF, Chrome and Edge. See https://github.com/ckeditor/ckeditor5/issues/4811.
      cancel();
      if (editor.commands.get('backdropLink').isEnabled) {
        backdropLinkCommand.execute();
      }
    }, { priority: 'high' });
  }

  _bindBalloon() {
    const editor = this.editor;
    const contextualBalloonPlugin = editor.plugins.get('ContextualBalloon');
    const linkUI = editor.plugins.get('LinkUI');
    const backdropLinkCommand = editor.commands.get('backdropLink');
    let linkUiModified = false;

    // Bind to the balloon being shown and check for the link UI.
    this.listenTo(contextualBalloonPlugin, 'change:visibleView', (evt, name, visibleView) => {
      const actionsView = linkUI.actionsView;
      if (actionsView && visibleView === actionsView) {
        if (!linkUiModified) {
          linkUiModified = true;
          // Turn off the normal link editing action.
          // See LinkUI::_createActionsView().
          linkUI.stopListening(actionsView, 'edit');
          // Replace with firing the backdropLink action instead.
          this.listenTo(actionsView, 'edit', () => {
            contextualBalloonPlugin.remove(actionsView);
            backdropLinkCommand.execute();
          });
        }
      }
    });
  }
}

// Expose the plugin to the CKEditor5 namespace.
CKEditor5.backdropLink = {
  'BackdropLink': BackdropLink
};

/**
 * CKEditor command that opens the Backdrop link editing dialog.
 */
class BackdropLinkCommand extends CKEditor5.core.Command {
  /**
   * @inheritdoc
   */
  refresh() {
    const editor = this.editor;
    const linkCommand = editor.commands.get('link');
    this.isEnabled = linkCommand.isEnabled;
    this.value = linkCommand.value;
  }

  /**
   * @inheritdoc
   */
  execute() {
    const editor = this.editor;
    const config = editor.config.get('backdropLink');
    const selection = editor.model.document.selection;
    const linkCommand = editor.commands.get('link');
    const imageUtils = editor.plugins.get('ImageUtils');
    const linkUI = editor.plugins.get('LinkUI');

    const closestImage = imageUtils.getClosestSelectedImageElement(selection);
    const extraAttributes = new Map(Object.entries(config.extraAttributes));
    const dialogSettings = {
      dialogClass: 'editor-link-dialog'
    };

    // Pull in existing values from the model to be sent to the dialog.
    let existingValues = {
      'href': linkUI.formView ? linkUI.formView.urlInputView.fieldView.value : '',
    };

    // Images store link values in a special 'htmlLinkAttributes' attribute.
    if (closestImage) {
      const htmlLinkAttributes = closestImage.getAttribute('htmlLinkAttributes');
      if (htmlLinkAttributes && htmlLinkAttributes.attributes) {
        existingValues = Object.assign(existingValues, htmlLinkAttributes.attributes);
      }
    }
    // For normal links, pull link values from individual attributes.
    else {
      extraAttributes.forEach((attributeName, modelName) => {
        existingValues[attributeName] = linkCommand[modelName];
      });
    }

    // Prepare a save callback to be used upon saving the dialog.
    const saveCallback = function(returnValues) {
      const linkCommand = editor.commands.get('link');
      const newHref = returnValues.attributes.href;
      delete returnValues.href;
      // Ignore a disabled target attribute.
      if (returnValues.attributes.target === 0) {
        delete returnValues.attributes.target;
      }
      // Remove empty file IDs.
      if (!returnValues.attributes['data-file-id']) {
        delete returnValues.attributes['data-file-id'];
      }
      // Remove "text" key intended to update the link text (not supported).
      if (returnValues.attributes.hasOwnProperty('text')) {
        delete returnValues.attributes['text'];
      }

      // The normal link command does not support a 3rd argument natively.
      // This has been extended in _addExtraAttributeOnLinkCommandExecute()
      // to also accept an array of attributes to be saved.
      // See https://github.com/ckeditor/ckeditor5/blob/master/packages/ckeditor5-link/src/linkcommand.ts
      // There is also a feature request to make this native to CKEditor
      // here: https://github.com/ckeditor/ckeditor5/issues/9730
      linkCommand.execute(newHref, {}, returnValues.attributes);
    }

    Backdrop.ckeditor5.openDialog(editor, config.dialogUrl, existingValues, saveCallback, dialogSettings);
  }
}

// The CKEditor core link icon is not in a reusable location, so this is a
// duplicated version for Backdrop use.
const backdropLinkIcon = '<svg viewBox="0 0 20 20" xmlns="http://www.w3.org/2000/svg"><path d="m11.077 15 .991-1.416a.75.75 0 1 1 1.229.86l-1.148 1.64a.748.748 0 0 1-.217.206 5.251 5.251 0 0 1-8.503-5.955.741.741 0 0 1 .12-.274l1.147-1.639a.75.75 0 1 1 1.228.86L4.933 10.7l.006.003a3.75 3.75 0 0 0 6.132 4.294l.006.004zm5.494-5.335a.748.748 0 0 1-.12.274l-1.147 1.639a.75.75 0 1 1-1.228-.86l.86-1.23a3.75 3.75 0 0 0-6.144-4.301l-.86 1.229a.75.75 0 0 1-1.229-.86l1.148-1.64a.748.748 0 0 1 .217-.206 5.251 5.251 0 0 1 8.503 5.955zm-4.563-2.532a.75.75 0 0 1 .184 1.045l-3.155 4.505a.75.75 0 1 1-1.229-.86l3.155-4.506a.75.75 0 0 1 1.045-.184z"/></svg>';

})(Backdrop, CKEditor5);
;
/**
 * @file
 * Backdrop maximize plugin.
 */
(function (Backdrop, CKEditor5) {

  "use strict";

  class Maximize extends CKEditor5.core.Plugin {
    init() {
      const editor = this.editor;

      editor.ui.componentFactory.add( 'maximize', () => {
        const button = new CKEditor5.ui.ButtonView();
        const activeClass = 'ck-maximize-active';

        button.set( {
          label: editor.config.get('maximizeLabel'),
          tooltip: true,
          icon: '<svg width="20" height="20" version="1.1" viewBox="0 0 20 20" xmlns="http://www.w3.org/2000/svg"><path d="m7 2h-5v5l1.8-1.8 2.7 2.8 1.5-1.5-2.8-2.7zm6 0 1.8 1.8-2.8 2.7 1.5 1.5 2.7-2.7 1.8 1.7v-5zm.5 10-1.5 1.5 2.7 2.7-1.7 1.8h5v-5l-1.8 1.8zm-7 0-2.7 2.7-1.8-1.7v5h5l-1.8-1.8 2.8-2.7z"/></svg>',
          isToggleable: true,
          isOn: false
        });

        button.on( 'execute', () => {
          // Applying the class to the parent keeps the sticky toolbar working.
          const editorParent = editor.ui.view.element.parentNode;

          if (editorParent.classList.contains(activeClass)) {
            editorParent.classList.remove(activeClass);
            document.body.classList.remove('ck-scroll-prevented');
            button.isOn = false;
          }
          else {
            editorParent.classList.add(activeClass);
            document.body.classList.add('ck-scroll-prevented');
            button.isOn = true;
          }
          window.dispatchEvent(new Event('resize'));
          editor.editing.view.focus();
          editor.editing.view.scrollToTheSelection();
        });

        return button;
      });
    }
  }

  // Expose the plugin to the CKEditor5 namespace.
  CKEditor5.backdropMaximize = {
    'Maximize': Maximize
  };

})(Backdrop, CKEditor5);
;
(function (Backdrop, CKEditor5, $) {

  "use strict";

  Backdrop.editors.ckeditor5 = {

    attach: function (element, format) {
      // Bail out if the editor has already been attached to the element.
      if (typeof element.ckeditor5AttachedEditor != 'undefined') {
        return;
      }

      if (!$('#ckeditor5-modal').length) {
        $('<div id="ckeditor5-modal" />').hide().appendTo('body');
      }

      // Set a title on the CKEditor instance that includes the text field's
      // label so that screen readers say something that is understandable
      // for end users.
      const label = $('label[for=' + element.getAttribute('id') + ']').text();
      const editorSettings = format.editorSettings;
      editorSettings.title = Backdrop.t("Rich Text Editor, !label field", {'!label': label});

      // CKEditor initializes itself in a read-only state if the 'disabled'
      // attribute is set. It does not respect the 'readonly' attribute,
      // however, so we set the 'readOnly' configuration property manually in
      // that case, for the CKEditor instance that's about to be created.
      editorSettings.readOnly = element.hasAttribute('readonly');

      // Try to match the textarea height on which we're replacing. Note this
      // minHeight property is enforced by the BackdropBasicStyles plugin.
      editorSettings.minHeight = $(element).height() + 'px';

      // The source element value is managed manually to apply code formatting.
      editorSettings.updateSourceElementOnDestroy = false;

      editorSettings.licenseKey = '';

      // If filter_html is turned on, and the htmlSupport plugin is available,
      // we prevent on* attributes.
      if (editorSettings.pluginList.includes('htmlSupport.GeneralHtmlSupport')) {
        if (editorSettings.htmlSupport.allow.length) {
          let onEventsPattern = {
            'name': /.*/,
            'attributes': /^on.*/
          }
          editorSettings.htmlSupport.disallow.push(onEventsPattern);
        }
        // If filter_html if off, allow all elements and attributes to be used.
        else {
          let patternAllowAll = {
            name: /.*/,
            attributes: true,
            classes: true,
            styles: true
          }
          editorSettings.htmlSupport.allow.push(patternAllowAll);
        }
      }

      // Convert the plugin list from strings to variable names. Each CKEditor
      // plugin is located under "CKEditor5.[packageName].[moduleName]". So
      // we convert the list of strings to match the expected variable name.
      editorSettings.plugins = [];
      editorSettings.pluginList.forEach(function(pluginItem) {
        const [packageName,moduleName] = pluginItem.split('.');
        if (typeof CKEditor5[packageName] != 'undefined') {
          editorSettings.plugins.push(CKEditor5[packageName][moduleName]);
        }
      });

      // Hide the resizable grippie while CKEditor is active.
      $(element).siblings('.grippie').hide();

      const beforeAttachValue = element.value;
      CKEditor5.editorClassic.ClassicEditor
        .create(element, editorSettings)
        .then(editor => {
          Backdrop.ckeditor5.setEditorOffset(editor);
          Backdrop.ckeditor5.instances.set(editor.id, editor);
          Backdrop.ckeditor5.watchEditorChanges(editor, element);
          element.ckeditor5AttachedEditor = editor;
          const valueModified = Backdrop.ckeditor5.checkValueModified(beforeAttachValue, editor.getData());
          if (valueModified && !Backdrop.ckeditor5.bypassContentWarning) {
            Backdrop.ckeditor5.detachWithWarning(element, format, beforeAttachValue);
          }
          return true;
        })
        .catch(error => {
          console.error('The CKEditor instance could not be initialized.');
          console.error(error);
          return false;
        });
    },

    detach: function (element, format, trigger) {
      // Remove any content modification warning.
      if (element.ckeditor5AttachedWarning && trigger !== 'serialize') {
        element.ckeditor5AttachedWarning.remove();
        delete element.ckeditor5AttachedWarning;
      }

      // Save content and remove any CKEditor 5 instances.
      const editor = element.ckeditor5AttachedEditor;
      if (!editor) {
        return false;
      }

      // CKEditor 5 does not pretty-print HTML source. Format the source
      // before saving it into the source field.
      let newData = editor.getData();
      newData = Backdrop.ckeditor5.formatHtml(newData);

      // Destroy the instance if fully detaching.
      if (trigger !== 'serialize') {
        editor.destroy();
        Backdrop.ckeditor5.instances.delete(editor.id);
        delete element.ckeditor5AttachedEditor;
      }

      // Save formatted value after destroying the editor, which can also
      // update the element value.
      element.value = newData;

      // Restore the resize grippie.
      $(element).siblings('.grippie').show();
      return !!editor;
    },

    onChange: function (element, callback) {
      const editor = element.ckeditor5AttachedEditor;
      if (editor) {
        const debouncedCallback = Backdrop.debounce(callback, 400);
        editor.model.document.on('change:data', function() {
          debouncedCallback(editor.getData());
        });
      }
      return !!editor;
    }
  };

  Backdrop.ckeditor5 = {
    /**
     * Variable storing the current dialog's save callback.
     */
    saveCallback: null,

    /**
     * Key-value map of all active instances of CKEditor 5.
     */
    instances: new Map(),

    /**
     * Boolean indicating if CKEditor instances should be attached even if they
     * modify content by the act of initializing the editor.
     */
    bypassContentWarning: false,

    /**
     * Open a dialog for a Backdrop-based plugin.
     *
     * This dynamically loads jQuery UI (if necessary) using the Backdrop AJAX
     * framework, then opens a dialog at the specified Backdrop path.
     *
     * @param {Editor} editor
     *   The CKEditor instance that is opening the dialog.
     * @param {String} url
     *   The URL that contains the contents of the dialog.
     * @param {Object} existingValues
     *   Existing values that will be sent via POST to the url for the dialog
     *   contents.
     * @param {Function} saveCallback
     *   A function to be called upon saving the dialog.
     * @param {Object} dialogSettings
     *   An object containing settings to be passed to the jQuery UI.
     */
    openDialog: function (editor, url, existingValues, saveCallback, dialogSettings) {
      // Locate a suitable place to display our loading indicator.
      const $toolbar = $(editor.ui.view.toolbar.element);

      // Remove any previous loading indicator.
      $toolbar.find('.ckeditor5-dialog-loading').remove();

      // Add a consistent dialog class.
      const classes = dialogSettings.dialogClass ? dialogSettings.dialogClass.split(' ') : [];
      classes.push('editor-dialog');
      dialogSettings.dialogClass = classes.join(' ');
      dialogSettings.autoResize = true;
      dialogSettings.modal = true;
      dialogSettings.target = '#ckeditor5-modal';

      // Add a "Loading…" message, hide it underneath the CKEditor toolbar, create
      // a Backdrop.ajax instance to load the dialog and trigger it.
      const $content = $('<div class="ck-reset_all-excluded ckeditor5-dialog-loading-wrapper" style="display: none;"><div class="ckeditor5-dialog-loading"><span class="ckeditor5-dialog-loading-link"><a>' + Backdrop.t('Loading...') + '</a></span></div></div>');
      $toolbar.append($content);
      new Backdrop.ajax('ckeditor5-dialog', $content.find('a').get(0), {
        accepts: 'application/vnd.backdrop-dialog',
        dialog: dialogSettings,
        selector: '.ckeditor5-dialog-loading-link',
        url: url,
        event: 'ckeditor5-internal.ckeditor5',
        progress: {'type': 'throbber'},
        submit: {
          editor_object: existingValues
        }
      });
      $content.find('a')
          .on('click', function () { return false; })
          .trigger('ckeditor5-internal.ckeditor5');

      // After a short delay, show "Loading…" message.
      window.setTimeout(function () {
        $content.css('display', 'block');
      }, 500);

      // Store the save callback to be executed when this dialog is closed.
      Backdrop.ckeditor5.saveCallback = saveCallback;
    },

    /**
     * Calculates the top of window offset.
     *
     * The "data-offset-top" attribute is used on the admin toolbar and sticky
     * table headers. Add up the offsets to determine the editor toolbar offset.
     *
     * @returns
     *   The vertical offset in pixels.
     */
    computeOffsetTop: function () {
      const $offsets = $('[data-offset-top]');
      let value, sum = 0;
      for (let i = 0, il = $offsets.length; i < il; i++) {
        value = parseInt($offsets[i].getAttribute('data-offset-top'), 10);
        sum += !isNaN(value) ? value : 0;
      }
      this.offsetTop = sum;
      return sum;
    },

    /**
     * Sets the CKEditor 5 toolbar offset.
     *
     * Setting the offset makes the editor toolbar floats below the admin
     * toolbar and any sticky table headers.
     *
     * @param editor
     *   The CKEditor 5 instance.
     */
    setEditorOffset: function (editor) {
      editor.ui.viewportOffset = {
        'bottom': 0,
        'left': 0,
        'right': 0,
        'top': Backdrop.ckeditor5.computeOffsetTop()
      };
    },

    /**
     * Binds an on change event to the editor to watch for value changes.
     *
     * Updating the source element regularly can prevent data-loss when a
     * browser window is closed or reloaded.
     *
     * @param editor
     *   The CKEditor 5 instance.
     * @param {Element} element
     *   The underlying textarea DOM element.
     */
    watchEditorChanges: function (editor, element) {
      // Create a debounced callback that only fires intermittently, since
      // editor changes can happen on every key up.
      const updateValue = Backdrop.debounce(() => {
        const newData = editor.getData();
        element.value = Backdrop.ckeditor5.formatHtml(newData);
      }, 1000);
      editor.model.document.on('change:data', updateValue);
    },

    /**
     * Compare the data before CKEditor 5 is attached and after attachment.
     *
     * This comparison reformats both the before and after values to the same
     * consistent format before doing a string comparison.
     *
     * @param beforeAttachValue
     *   The element value before CKEditor was attached.
     * @param afterAttachValue
     *   The element value after CKEditor was attached.
     *
     * @return {boolean}
     *   Returns true if values have been modified, false if unchanged.
     */
    checkValueModified: function (beforeAttachValue, afterAttachValue) {
      // Pass the before value through elementGetHtml() to standardize
      // attribute order and self-closing tags. For example, two <img> tags with
      // src, width, and height attributes should be equal, even if one uses the
      // order height, src, width. Similarly, <hr /> and <hr> should be
      // considered the same. Passing in an out of the DOM makes these two
      // values use the same order and tag closing.
      const beforeElement = document.createElement('template');
      beforeElement.innerHTML = beforeAttachValue;
      beforeAttachValue = Backdrop.ckeditor5.elementGetHtml(beforeElement.content);

      // Then run both strings through the same whitespace formatting.
      const formattedBeforeValue = Backdrop.ckeditor5.formatHtml(beforeAttachValue);
      const formattedAfterValue = Backdrop.ckeditor5.formatHtml(afterAttachValue);
      return formattedBeforeValue !== formattedAfterValue;
    },

    /**
     * Attach an alert to the editor if the value has been modified.
     *
     * This disables the editor and restores the plain textarea element. The
     * warning can be dismissed to load the editor anyway.
     *
     * @param element
     *   The DOM element to which the editor was attached.
     * @param format
     *   The text format configuration with which the editor was attached.
     * @param beforeAttachValues
     *   The element value before CKEditor was attached.
     *
     * @return {boolean}
     *   Returns true if values have been modified, false if unchanged.
     */
    detachWithWarning: function (element, format, beforeAttachValues) {
      // Detach the editor.
      Backdrop.filterEditorDetach(element, format);
      // Restore the value to what it was previously.
      element.value = beforeAttachValues;
      // Attach a warning before the field.
      const $warning = $($.parseHTML(Backdrop.theme('ckeditor5ContentModifiedWarning')));
      $warning.insertBefore(element);
      // On click of the link within the warning, attach the editor anyway and
      // remove the warning.
      $warning.find('a').on('click', function(e) {
        // Setting this bypass flag prevents the warning from being re-added.
        Backdrop.ckeditor5.bypassContentWarning = true;
        Backdrop.filterEditorAttach(element, format);
        $warning.remove();
        e.preventDefault();
      });
      element.ckeditor5AttachedWarning = $warning[0];
    }
  };

  // Respond to new dialogs that are opened by CKEditor, closing the AJAX loader.
  $(window).on('dialog:beforecreate', function (e, dialog, $element, settings) {
    $('.ckeditor5-dialog-loading-wrapper').remove();
  });

  // Respond to dialogs that are saved, sending data back to CKEditor.
  $(window).on('editor:dialogsave', function (e, values) {
    if (Backdrop.ckeditor5.saveCallback) {
      Backdrop.ckeditor5.saveCallback(values);
    }
  });

  // Respond to dialogs that are closed, removing the current save handler.
  $(window).on('dialog:afterclose', function (e, dialog, $element) {
    if (Backdrop.ckeditor5.saveCallback) {
      Backdrop.ckeditor5.saveCallback = null;
    }
  });

  // Set the offset to account for admin toolbar.
  $(document).on('offsettopchange', function() {
    Backdrop.ckeditor5.instances.forEach(function(instance) {
      Backdrop.ckeditor5.setEditorOffset(instance);
    });
  });

  /**
   * Display a warning message that loading the editor may modify content.
   */
  Backdrop.theme.prototype.ckeditor5ContentModifiedWarning = function() {
    let warningMessage = '';
    warningMessage += '<div class="ckeditor5-content-modified-warning messages warning">';
    warningMessage += '<span class="ckeditor5-content-modified-message">' + Backdrop.t('Activating CKEditor 5 will reformat the content of this field. Review content carefully after activating.') + '</span> ';
    warningMessage += '<a class="ckeditor5-content-modified-activate" href="#">' + Backdrop.t('Click to activate editor') + '</a>.';
    warningMessage += '</div>';
    return warningMessage;
  }

})(Backdrop, CKEditor5, jQuery);
;
/**
 * @file
 *
 * Contains HTML exporting and formatting code for CKEditor 5 module.
 */
(function (Backdrop) {
  "use strict";

  /**
   * A simple (and naive) HTML code formatter that returns a formatted HTML
   * markup that can be easily parsed by human eyes. It beautifies the HTML code
   * by adding new lines between elements that behave like block elements
   * (https://developer.mozilla.org/en-US/docs/Web/HTML/Block-level_elements
   * and a few more like `tr`, `td`, and similar ones) and inserting indents for
   * nested content.
   *
   * WARNING: This function works only on a text that does not contain any
   * indentations or new lines. Calling this function on the already formatted
   * text will damage the formatting.
   *
   * @param {String} input
   *   An HTML string to format.
   * @param {String} input
   *   A chunk of unformatted HTML.
   * @returns {String}
   *   The same HTML formatted for easier readability and diffing.
   */
  Backdrop.ckeditor5.formatHtml = function(input) {
    const htmlFormatter = new BackdropHtmlFormatter();
    return htmlFormatter.formatHtml(input);
  };

  /**
   * Convert an Element into an HTML string, with attributes properly escaped.
   *
   * In some cases, the value returned from this function may want to be
   * formatted using Backdrop.ckeditor5.formatHtml().
   *
   * @param {Element|DocumentFragment} element
   *   The DOM Element from which HTML should be exported.
   * @returns {String}
   *   An unformatted HTML string.
   */
  Backdrop.ckeditor5.elementGetHtml = function(element) {
    const htmlBuilder = new BackdropHtmlBuilder();
    htmlBuilder.appendNode(element);
    return htmlBuilder.build();
  };

  /**
   * HTML formatting utility for use by Backdrop's CKEditor 5 integration.
   *
   * This formatter is based off CKEditor 5 source code for HTML Source Editing.
   *
   * See https://github.com/ckeditor/ckeditor5/blob/master/packages/ckeditor5-source-editing/src/utils/formathtml.ts
   *
   * Eventually the code in this file may not be necessary, in the event that
   * CKEditor 5 allows public API access to the HTML formatter.
   *
   * See https://github.com/ckeditor/ckeditor5/issues/8668
   */
  class BackdropHtmlFormatter {
    /**
     * Constructs a new object.
     */
    constructor() {
      // A list of block-like elements around which the new lines should be
      // inserted, and within which the indentation of their children should be
      // increased. The list is partially based on
      // https://developer.mozilla.org/en-US/docs/Web/HTML/Block-level_elements
      // that contains a full list of HTML block-level elements.
      // A void element is an element that cannot have any child:
      // https://html.spec.whatwg.org/multipage/syntax.html#void-elements.
      // Note that <pre> element is not listed on this list to avoid breaking
      // whitespace formatting.
      // Note that <br> element is not listed and handled separately so no
      // additional white spaces are injected.
      this.elementsToFormat = [
        { name: 'address', isVoid: false },
        { name: 'article', isVoid: false },
        { name: 'aside', isVoid: false },
        { name: 'blockquote', isVoid: false },
        { name: 'details', isVoid: false },
        { name: 'dialog', isVoid: false },
        { name: 'dd', isVoid: false },
        { name: 'div', isVoid: false },
        { name: 'dl', isVoid: false },
        { name: 'dt', isVoid: false },
        { name: 'fieldset', isVoid: false },
        { name: 'figcaption', isVoid: false },
        { name: 'figure', isVoid: false },
        { name: 'footer', isVoid: false },
        { name: 'form', isVoid: false },
        { name: 'h1', isVoid: false },
        { name: 'h2', isVoid: false },
        { name: 'h3', isVoid: false },
        { name: 'h4', isVoid: false },
        { name: 'h5', isVoid: false },
        { name: 'h6', isVoid: false },
        { name: 'header', isVoid: false },
        { name: 'hgroup', isVoid: false },
        { name: 'hr', isVoid: true },
        { name: 'li', isVoid: false },
        { name: 'main', isVoid: false },
        { name: 'nav', isVoid: false },
        { name: 'ol', isVoid: false },
        { name: 'p', isVoid: false },
        { name: 'section', isVoid: false },
        { name: 'table', isVoid: false },
        { name: 'tbody', isVoid: false },
        { name: 'td', isVoid: false },
        { name: 'th', isVoid: false },
        { name: 'thead', isVoid: false },
        { name: 'tr', isVoid: false },
        { name: 'ul', isVoid: false }
      ];
    }

    /**
     * Format an HTML string with indentation and newlines for readability.
     * @param {String} input
     *   A chunk of unformatted HTML.
     * @returns {String}
     *   The same HTML formatted for easier readability and diffing.
     */
    formatHtml(input) {
      const elementNamesToFormat = this.elementsToFormat.map(element => element.name).join('|');

      // It is not the fastest way to format the HTML markup but the performance
      // should be good enough.
      const lines = input
        // Add new line before and after `<tag>` and `</tag>`. It may separate
        // individual elements with two new lines, but this will be fixed below.
        .replace(new RegExp( `</?(${ elementNamesToFormat })( .*?)?>`, 'g' ), '\n$&\n')
        // Keep `<br>`s at the end of line to avoid adding additional whitespaces
        // before `<br>`.
        .replace(/<br[^>]*>/g, '$&\n')
        // Divide input string into lines, which start with either an opening tag,
        // a closing tag, or just a text.
        .split('\n');

      let indentCount = 0;

      return lines
        .filter((line) => { return line.trim().length })
        .map((line) => {
          if (this._isNonVoidOpeningTag(line)) {
            return this._indentLine(line, indentCount++);
          }

          if (this._isClosingTag(line)) {
            return this._indentLine(line, --indentCount);
          }

          return this._indentLine(line, indentCount);
        })
        .join('\n');
    }

    /**
     * Checks if an argument is an opening tag of a non-void element.
     *
     * @param {String} line
     *   String to check.
     */
    _isNonVoidOpeningTag(line) {
      return this.elementsToFormat.some((element) => {
        if (element.isVoid) {
          return false;
        }

        if (!new RegExp('<' + element.name  + '( .*?)?>').test(line)) {
          return false;
        }

        return true;
      });
    }

    /**
     * Checks if an argument is a closing tag.
     *
     * @param {String} line
     *   String to check.
     */
    _isClosingTag(line) {
      return this.elementsToFormat.some((element) => {
        return new RegExp('</' + element.name + '>').test(line);
      });
    }

    /**
     * Indents a line by a specified number of characters.
     *
     * @param {String} line
     *   Line to indent.
     * @param {Number} indentCount
     *   Number of characters to use for indentation.
     * @param {String} indentChar
     *   Indentation character(s). 4 spaces by default.
     */
    _indentLine(line, indentCount, indentChar = '    ' ) {
      // More about Math.max() here in https://github.com/ckeditor/ckeditor5/issues/10698.
      return indentChar.repeat(Math.max(0, indentCount)) + line.trim();
    }
  }

  /**
   * HTML builder that converts document fragments into strings.
   *
   * Escapes ampersand characters (`&`) and angle brackets (`<` and `>`) when
   * transforming data to HTML. This is required because filter_xss() fails to
   * parse element attributes values containing unescaped HTML entities.
   */
  class BackdropHtmlBuilder {
    /**
     * Constructs a new object.
     */
    constructor() {
      this.chunks = [];
      // @see https://html.spec.whatwg.org/multipage/syntax.html#elements-2
      this.selfClosingTags = [
        'area',
        'base',
        'br',
        'col',
        'embed',
        'hr',
        'img',
        'input',
        'link',
        'meta',
        'param',
        'source',
        'track',
        'wbr',
      ];
    }

    /**
     * Returns the current HTML string built from document fragments.
     *
     * @return {string}
     *   The HTML string built from document fragments.
     */
    build() {
      return this.chunks.join('');
    }

    /**
     * Converts a document fragment into an HTML string appended to the value.
     *
     * @param {Element|DocumentFragment} node
     *   A DOM element to be appended to the value.
     */
    appendNode(node) {
      if (node.nodeType === Node.TEXT_NODE) {
        this._appendText(node);
      } else if (node.nodeType === Node.ELEMENT_NODE) {
        this._appendElement(node);
      } else if (node.nodeType === Node.DOCUMENT_FRAGMENT_NODE) {
        this._appendChildren(node);
      }
    }

    /**
     * Appends an element node to the value.
     *
     * @param {Element} node
     *   A DOM element to be appended to the value.
     */
    _appendElement(node) {
      const nodeName = node.nodeName.toLowerCase();

      this._append('<');
      this._append(nodeName);
      this._appendAttributes(node);
      this._append('>');
      if (!this.selfClosingTags.includes(nodeName)) {
        this._appendChildren(node);
        this._append('</');
        this._append(nodeName);
        this._append('>');
      }
    }

    /**
     * Appends child nodes to the value.
     *
     * @param {Element|DocumentFragment} node
     *  A DOM element to be appended to the value.
     */
    _appendChildren(node) {
      Object.keys(node.childNodes).forEach((child) => {
        this.appendNode(node.childNodes[child]);
      });
    }

    /**
     * Appends attributes to the value.
     *
     * @param {Element} node
     *  A DOM element to be appended to the value.
     */
    _appendAttributes(node) {
      // Sort attributes alphabetically for consistent output across browsers.
      const sortedAttributes = Object.values(node.attributes).sort((a, b) => {
        return a.name > b.name;
      });
      sortedAttributes.forEach((attribute) => {
        this._append(' ');
        this._append(attribute.name);
        this._append('="');
        this._append(
          this._escapeAttribute(attribute.value),
        );
        this._append('"');
      });
    }

    /**
     * Appends text to the value.
     *
     * @param {Element} node
     *  A DOM element to be appended to the value.
     */
    _appendText(node) {
      // Repack the text into another node and extract using innerHTML. This
      // works around text nodes not having an innerHTML property and textContent
      // not encoding entities.
      // entities. That's why the text is repacked into another node and extracted
      // using innerHTML.
      const doc = document.implementation.createHTMLDocument('');
      const container = doc.createElement('p');
      container.textContent = node.textContent;

      this._append(container.innerHTML);
    }

    /**
     * Appends a string to the value.
     *
     * @param {string} str
     *  A string to be appended to the value.
     */
    _append(str) {
      this.chunks.push(str);
    }

    /**
     * Escapes attribute value for compatibility with Backdrop's XSS filtering.
     *
     * Backdrop's XSS filtering does not handle entities inside element attribute
     * values. The XSS filtering was written based on W3C XML recommendations
     * which constituted that the ampersand character (&) and the angle
     * brackets (< and >) must not appear in their literal form in attribute
     * values. This differs from the HTML living standard which permits (but
     * discourages) unescaped angle brackets.
     *
     * @param {string} text
     *  A string to be escaped.
     *
     * @return {string}
     *  Escaped string.
     *
     * @see https://www.w3.org/TR/2008/REC-xml-20081126/#NT-AttValue
     * @see https://html.spec.whatwg.org/multipage/parsing.html#attribute-value-(single-quoted)-state
     * @see https://github.com/whatwg/html/issues/6235
     */
    _escapeAttribute(text) {
      return text
        .replace(/&/g, '&amp;')
        .replace(/'/g, '&apos;')
        .replace(/"/g, '&quot;')
        .replace(/</g, '&lt;')
        .replace(/>/g, '&gt;')
        .replace(/\r\n/g, '&#13;')
        .replace(/[\r\n]/g, '&#13;');
    }
  }

})(Backdrop);
;
/*!
 * jQuery Form Plugin
 * version: 4.3.0
 * Requires jQuery v1.7.2 or later
 * Project repository: https://github.com/jquery-form/form

 * Copyright 2017 Kevin Morris
 * Copyright 2006 M. Alsup

 * Dual licensed under the LGPL-2.1+ or MIT licenses
 * https://github.com/jquery-form/form#license

 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 */
!function(r){"function"==typeof define&&define.amd?define(["jquery"],r):"object"==typeof module&&module.exports?module.exports=function(e,t){return void 0===t&&(t="undefined"!=typeof window?require("jquery"):require("jquery")(e)),r(t),t}:r(jQuery)}(function(q){"use strict";var m=/\r?\n/g,S={};S.fileapi=void 0!==q('<input type="file">').get(0).files,S.formdata=void 0!==window.FormData;var _=!!q.fn.prop;function o(e){var t=e.data;e.isDefaultPrevented()||(e.preventDefault(),q(e.target).closest("form").ajaxSubmit(t))}function i(e){var t=e.target,r=q(t);if(!r.is("[type=submit],[type=image]")){var a=r.closest("[type=submit]");if(0===a.length)return;t=a[0]}var n,o=t.form;"image"===(o.clk=t).type&&(void 0!==e.offsetX?(o.clk_x=e.offsetX,o.clk_y=e.offsetY):"function"==typeof q.fn.offset?(n=r.offset(),o.clk_x=e.pageX-n.left,o.clk_y=e.pageY-n.top):(o.clk_x=e.pageX-t.offsetLeft,o.clk_y=e.pageY-t.offsetTop)),setTimeout(function(){o.clk=o.clk_x=o.clk_y=null},100)}function N(){var e;q.fn.ajaxSubmit.debug&&(e="[jquery.form] "+Array.prototype.join.call(arguments,""),window.console&&window.console.log?window.console.log(e):window.opera&&window.opera.postError&&window.opera.postError(e))}q.fn.attr2=function(){if(!_)return this.attr.apply(this,arguments);var e=this.prop.apply(this,arguments);return e&&e.jquery||"string"==typeof e?e:this.attr.apply(this,arguments)},q.fn.ajaxSubmit=function(M,e,t,r){if(!this.length)return N("ajaxSubmit: skipping submit process - no element selected"),this;var O,a,n,o,X=this;"function"==typeof M?M={success:M}:"string"==typeof M||!1===M&&0<arguments.length?(M={url:M,data:e,dataType:t},"function"==typeof r&&(M.success=r)):void 0===M&&(M={}),O=M.method||M.type||this.attr2("method"),n=(n=(n="string"==typeof(a=M.url||this.attr2("action"))?q.trim(a):"")||window.location.href||"")&&(n.match(/^([^#]+)/)||[])[1],o=/(MSIE|Trident)/.test(navigator.userAgent||"")&&/^https/i.test(window.location.href||"")?"javascript:false":"about:blank",M=q.extend(!0,{url:n,success:q.ajaxSettings.success,type:O||q.ajaxSettings.type,iframeSrc:o},M);var i={};if(this.trigger("form-pre-serialize",[this,M,i]),i.veto)return N("ajaxSubmit: submit vetoed via form-pre-serialize trigger"),this;if(M.beforeSerialize&&!1===M.beforeSerialize(this,M))return N("ajaxSubmit: submit aborted via beforeSerialize callback"),this;var s=M.traditional;void 0===s&&(s=q.ajaxSettings.traditional);var u,c,C=[],l=this.formToArray(M.semantic,C,M.filtering);if(M.data&&(c=q.isFunction(M.data)?M.data(l):M.data,M.extraData=c,u=q.param(c,s)),M.beforeSubmit&&!1===M.beforeSubmit(l,this,M))return N("ajaxSubmit: submit aborted via beforeSubmit callback"),this;if(this.trigger("form-submit-validate",[l,this,M,i]),i.veto)return N("ajaxSubmit: submit vetoed via form-submit-validate trigger"),this;var f=q.param(l,s);u&&(f=f?f+"&"+u:u),"GET"===M.type.toUpperCase()?(M.url+=(0<=M.url.indexOf("?")?"&":"?")+f,M.data=null):M.data=f;var d,m,p,h=[];M.resetForm&&h.push(function(){X.resetForm()}),M.clearForm&&h.push(function(){X.clearForm(M.includeHidden)}),!M.dataType&&M.target?(d=M.success||function(){},h.push(function(e,t,r){var a=arguments,n=M.replaceTarget?"replaceWith":"html";q(M.target)[n](e).each(function(){d.apply(this,a)})})):M.success&&(q.isArray(M.success)?q.merge(h,M.success):h.push(M.success)),M.success=function(e,t,r){for(var a=M.context||this,n=0,o=h.length;n<o;n++)h[n].apply(a,[e,t,r||X,X])},M.error&&(m=M.error,M.error=function(e,t,r){var a=M.context||this;m.apply(a,[e,t,r,X])}),M.complete&&(p=M.complete,M.complete=function(e,t){var r=M.context||this;p.apply(r,[e,t,X])});var v=0<q("input[type=file]:enabled",this).filter(function(){return""!==q(this).val()}).length,g="multipart/form-data",x=X.attr("enctype")===g||X.attr("encoding")===g,y=S.fileapi&&S.formdata;N("fileAPI :"+y);var b,T=(v||x)&&!y;!1!==M.iframe&&(M.iframe||T)?M.closeKeepAlive?q.get(M.closeKeepAlive,function(){b=w(l)}):b=w(l):b=(v||x)&&y?function(e){for(var r=new FormData,t=0;t<e.length;t++)r.append(e[t].name,e[t].value);if(M.extraData){var a=function(e){var t,r,a=q.param(e,M.traditional).split("&"),n=a.length,o=[];for(t=0;t<n;t++)a[t]=a[t].replace(/\+/g," "),r=a[t].split("="),o.push([decodeURIComponent(r[0]),decodeURIComponent(r[1])]);return o}(M.extraData);for(t=0;t<a.length;t++)a[t]&&r.append(a[t][0],a[t][1])}M.data=null;var n=q.extend(!0,{},q.ajaxSettings,M,{contentType:!1,processData:!1,cache:!1,type:O||"POST"});M.uploadProgress&&(n.xhr=function(){var e=q.ajaxSettings.xhr();return e.upload&&e.upload.addEventListener("progress",function(e){var t=0,r=e.loaded||e.position,a=e.total;e.lengthComputable&&(t=Math.ceil(r/a*100)),M.uploadProgress(e,r,a,t)},!1),e});n.data=null;var o=n.beforeSend;return n.beforeSend=function(e,t){M.formData?t.data=M.formData:t.data=r,o&&o.call(this,e,t)},q.ajax(n)}(l):q.ajax(M),X.removeData("jqxhr").data("jqxhr",b);for(var j=0;j<C.length;j++)C[j]=null;return this.trigger("form-submit-notify",[this,M]),this;function w(e){var t,r,l,f,o,d,m,p,a,n,h,v,i=X[0],g=q.Deferred();if(g.abort=function(e){p.abort(e)},e)for(r=0;r<C.length;r++)t=q(C[r]),_?t.prop("disabled",!1):t.removeAttr("disabled");(l=q.extend(!0,{},q.ajaxSettings,M)).context=l.context||l,o="jqFormIO"+(new Date).getTime();var s=i.ownerDocument,u=X.closest("body");if(l.iframeTarget?(n=(d=q(l.iframeTarget,s)).attr2("name"))?o=n:d.attr2("name",o):(d=q('<iframe name="'+o+'" src="'+l.iframeSrc+'" />',s)).css({position:"absolute",top:"-1000px",left:"-1000px"}),m=d[0],p={aborted:0,responseText:null,responseXML:null,status:0,statusText:"n/a",getAllResponseHeaders:function(){},getResponseHeader:function(){},setRequestHeader:function(){},abort:function(e){var t="timeout"===e?"timeout":"aborted";N("aborting upload... "+t),this.aborted=1;try{m.contentWindow.document.execCommand&&m.contentWindow.document.execCommand("Stop")}catch(e){}d.attr("src",l.iframeSrc),p.error=t,l.error&&l.error.call(l.context,p,t,e),f&&q.event.trigger("ajaxError",[p,l,t]),l.complete&&l.complete.call(l.context,p,t)}},(f=l.global)&&0==q.active++&&q.event.trigger("ajaxStart"),f&&q.event.trigger("ajaxSend",[p,l]),l.beforeSend&&!1===l.beforeSend.call(l.context,p,l))return l.global&&q.active--,g.reject(),g;if(p.aborted)return g.reject(),g;(a=i.clk)&&(n=a.name)&&!a.disabled&&(l.extraData=l.extraData||{},l.extraData[n]=a.value,"image"===a.type&&(l.extraData[n+".x"]=i.clk_x,l.extraData[n+".y"]=i.clk_y));var x=1,y=2;function b(t){var r=null;try{t.contentWindow&&(r=t.contentWindow.document)}catch(e){N("cannot get iframe.contentWindow document: "+e)}if(r)return r;try{r=t.contentDocument?t.contentDocument:t.document}catch(e){N("cannot get iframe.contentDocument: "+e),r=t.document}return r}var c=q("meta[name=csrf-token]").attr("content"),T=q("meta[name=csrf-param]").attr("content");function j(){var e=X.attr2("target"),t=X.attr2("action"),r=X.attr("enctype")||X.attr("encoding")||"multipart/form-data";i.setAttribute("target",o),O&&!/post/i.test(O)||i.setAttribute("method","POST"),t!==l.url&&i.setAttribute("action",l.url),l.skipEncodingOverride||O&&!/post/i.test(O)||X.attr({encoding:"multipart/form-data",enctype:"multipart/form-data"}),l.timeout&&(v=setTimeout(function(){h=!0,A(x)},l.timeout));var a=[];try{if(l.extraData)for(var n in l.extraData)l.extraData.hasOwnProperty(n)&&(q.isPlainObject(l.extraData[n])&&l.extraData[n].hasOwnProperty("name")&&l.extraData[n].hasOwnProperty("value")?a.push(q('<input type="hidden" name="'+l.extraData[n].name+'">',s).val(l.extraData[n].value).appendTo(i)[0]):a.push(q('<input type="hidden" name="'+n+'">',s).val(l.extraData[n]).appendTo(i)[0]));l.iframeTarget||d.appendTo(u),m.attachEvent?m.attachEvent("onload",A):m.addEventListener("load",A,!1),setTimeout(function e(){try{var t=b(m).readyState;N("state = "+t),t&&"uninitialized"===t.toLowerCase()&&setTimeout(e,50)}catch(e){N("Server abort: ",e," (",e.name,")"),A(y),v&&clearTimeout(v),v=void 0}},15);try{i.submit()}catch(e){document.createElement("form").submit.apply(i)}}finally{i.setAttribute("action",t),i.setAttribute("enctype",r),e?i.setAttribute("target",e):X.removeAttr("target"),q(a).remove()}}T&&c&&(l.extraData=l.extraData||{},l.extraData[T]=c),l.forceSync?j():setTimeout(j,10);var w,S,k,D=50;function A(e){if(!p.aborted&&!k){if((S=b(m))||(N("cannot access response document"),e=y),e===x&&p)return p.abort("timeout"),void g.reject(p,"timeout");if(e===y&&p)return p.abort("server abort"),void g.reject(p,"error","server abort");if(S&&S.location.href!==l.iframeSrc||h){m.detachEvent?m.detachEvent("onload",A):m.removeEventListener("load",A,!1);var t,r="success";try{if(h)throw"timeout";var a="xml"===l.dataType||S.XMLDocument||q.isXMLDoc(S);if(N("isXml="+a),!a&&window.opera&&(null===S.body||!S.body.innerHTML)&&--D)return N("requeing onLoad callback, DOM not available"),void setTimeout(A,250);var n=S.body?S.body:S.documentElement;p.responseText=n?n.innerHTML:null,p.responseXML=S.XMLDocument?S.XMLDocument:S,a&&(l.dataType="xml"),p.getResponseHeader=function(e){return{"content-type":l.dataType}[e.toLowerCase()]},n&&(p.status=Number(n.getAttribute("status"))||p.status,p.statusText=n.getAttribute("statusText")||p.statusText);var o,i,s,u=(l.dataType||"").toLowerCase(),c=/(json|script|text)/.test(u);c||l.textarea?(o=S.getElementsByTagName("textarea")[0])?(p.responseText=o.value,p.status=Number(o.getAttribute("status"))||p.status,p.statusText=o.getAttribute("statusText")||p.statusText):c&&(i=S.getElementsByTagName("pre")[0],s=S.getElementsByTagName("body")[0],i?p.responseText=i.textContent?i.textContent:i.innerText:s&&(p.responseText=s.textContent?s.textContent:s.innerText)):"xml"===u&&!p.responseXML&&p.responseText&&(p.responseXML=F(p.responseText));try{w=E(p,u,l)}catch(e){r="parsererror",p.error=t=e||r}}catch(e){N("error caught: ",e),r="error",p.error=t=e||r}p.aborted&&(N("upload aborted"),r=null),p.status&&(r=200<=p.status&&p.status<300||304===p.status?"success":"error"),"success"===r?(l.success&&l.success.call(l.context,w,"success",p),g.resolve(p.responseText,"success",p),f&&q.event.trigger("ajaxSuccess",[p,l])):r&&(void 0===t&&(t=p.statusText),l.error&&l.error.call(l.context,p,r,t),g.reject(p,"error",t),f&&q.event.trigger("ajaxError",[p,l,t])),f&&q.event.trigger("ajaxComplete",[p,l]),f&&!--q.active&&q.event.trigger("ajaxStop"),l.complete&&l.complete.call(l.context,p,r),k=!0,l.timeout&&clearTimeout(v),setTimeout(function(){l.iframeTarget?d.attr("src",l.iframeSrc):d.remove(),p.responseXML=null},100)}}}var F=q.parseXML||function(e,t){return window.ActiveXObject?((t=new ActiveXObject("Microsoft.XMLDOM")).async="false",t.loadXML(e)):t=(new DOMParser).parseFromString(e,"text/xml"),t&&t.documentElement&&"parsererror"!==t.documentElement.nodeName?t:null},L=q.parseJSON||function(e){return window.eval("("+e+")")},E=function(e,t,r){var a=e.getResponseHeader("content-type")||"",n=("xml"===t||!t)&&0<=a.indexOf("xml"),o=n?e.responseXML:e.responseText;return n&&"parsererror"===o.documentElement.nodeName&&q.error&&q.error("parsererror"),r&&r.dataFilter&&(o=r.dataFilter(o,t)),"string"==typeof o&&(("json"===t||!t)&&0<=a.indexOf("json")?o=L(o):("script"===t||!t)&&0<=a.indexOf("javascript")&&q.globalEval(o)),o};return g}},q.fn.ajaxForm=function(e,t,r,a){if(("string"==typeof e||!1===e&&0<arguments.length)&&(e={url:e,data:t,dataType:r},"function"==typeof a&&(e.success=a)),(e=e||{}).delegation=e.delegation&&q.isFunction(q.fn.on),e.delegation||0!==this.length)return e.delegation?(q(document).off("submit.form-plugin",this.selector,o).off("click.form-plugin",this.selector,i).on("submit.form-plugin",this.selector,e,o).on("click.form-plugin",this.selector,e,i),this):(e.beforeFormUnbind&&e.beforeFormUnbind(this,e),this.ajaxFormUnbind().on("submit.form-plugin",e,o).on("click.form-plugin",e,i));var n={s:this.selector,c:this.context};return!q.isReady&&n.s?(N("DOM not ready, queuing ajaxForm"),q(function(){q(n.s,n.c).ajaxForm(e)})):N("terminating; zero elements found by selector"+(q.isReady?"":" (DOM not ready)")),this},q.fn.ajaxFormUnbind=function(){return this.off("submit.form-plugin click.form-plugin")},q.fn.formToArray=function(e,t,r){var a=[];if(0===this.length)return a;var n,o,i,s,u,c,l,f,d,m,p=this[0],h=this.attr("id"),v=(v=e||void 0===p.elements?p.getElementsByTagName("*"):p.elements)&&q.makeArray(v);if(h&&(e||/(Edge|Trident)\//.test(navigator.userAgent))&&(n=q(':input[form="'+h+'"]').get()).length&&(v=(v||[]).concat(n)),!v||!v.length)return a;for(q.isFunction(r)&&(v=q.map(v,r)),o=0,c=v.length;o<c;o++)if((m=(u=v[o]).name)&&!u.disabled)if(e&&p.clk&&"image"===u.type)p.clk===u&&(a.push({name:m,value:q(u).val(),type:u.type}),a.push({name:m+".x",value:p.clk_x},{name:m+".y",value:p.clk_y}));else if((s=q.fieldValue(u,!0))&&s.constructor===Array)for(t&&t.push(u),i=0,l=s.length;i<l;i++)a.push({name:m,value:s[i]});else if(S.fileapi&&"file"===u.type){t&&t.push(u);var g=u.files;if(g.length)for(i=0;i<g.length;i++)a.push({name:m,value:g[i],type:u.type});else a.push({name:m,value:"",type:u.type})}else null!=s&&(t&&t.push(u),a.push({name:m,value:s,type:u.type,required:u.required}));return e||!p.clk||(m=(d=(f=q(p.clk))[0]).name)&&!d.disabled&&"image"===d.type&&(a.push({name:m,value:f.val()}),a.push({name:m+".x",value:p.clk_x},{name:m+".y",value:p.clk_y})),a},q.fn.formSerialize=function(e){return q.param(this.formToArray(e))},q.fn.fieldSerialize=function(n){var o=[];return this.each(function(){var e=this.name;if(e){var t=q.fieldValue(this,n);if(t&&t.constructor===Array)for(var r=0,a=t.length;r<a;r++)o.push({name:e,value:t[r]});else null!=t&&o.push({name:this.name,value:t})}}),q.param(o)},q.fn.fieldValue=function(e){for(var t=[],r=0,a=this.length;r<a;r++){var n=this[r],o=q.fieldValue(n,e);null==o||o.constructor===Array&&!o.length||(o.constructor===Array?q.merge(t,o):t.push(o))}return t},q.fieldValue=function(e,t){var r=e.name,a=e.type,n=e.tagName.toLowerCase();if(void 0===t&&(t=!0),t&&(!r||e.disabled||"reset"===a||"button"===a||("checkbox"===a||"radio"===a)&&!e.checked||("submit"===a||"image"===a)&&e.form&&e.form.clk!==e||"select"===n&&-1===e.selectedIndex))return null;if("select"!==n)return q(e).val().replace(m,"\r\n");var o=e.selectedIndex;if(o<0)return null;for(var i=[],s=e.options,u="select-one"===a,c=u?o+1:s.length,l=u?o:0;l<c;l++){var f=s[l];if(f.selected&&!f.disabled){var d=(d=f.value)||(f.attributes&&f.attributes.value&&!f.attributes.value.specified?f.text:f.value);if(u)return d;i.push(d)}}return i},q.fn.clearForm=function(e){return this.each(function(){q("input,select,textarea",this).clearFields(e)})},q.fn.clearFields=q.fn.clearInputs=function(r){var a=/^(?:color|date|datetime|email|month|number|password|range|search|tel|text|time|url|week)$/i;return this.each(function(){var e=this.type,t=this.tagName.toLowerCase();a.test(e)||"textarea"===t?this.value="":"checkbox"===e||"radio"===e?this.checked=!1:"select"===t?this.selectedIndex=-1:"file"===e?/MSIE/.test(navigator.userAgent)?q(this).replaceWith(q(this).clone(!0)):q(this).val(""):r&&(!0===r&&/hidden/.test(e)||"string"==typeof r&&q(this).is(r))&&(this.value="")})},q.fn.resetForm=function(){return this.each(function(){var t=q(this),e=this.tagName.toLowerCase();switch(e){case"input":this.checked=this.defaultChecked;case"textarea":return this.value=this.defaultValue,!0;case"option":case"optgroup":var r=t.parents("select");return r.length&&r[0].multiple?"option"===e?this.selected=this.defaultSelected:t.find("option").resetForm():r.resetForm(),!0;case"select":return t.find("option").each(function(e){if(this.selected=this.defaultSelected,this.defaultSelected&&!t[0].multiple)return t[0].selectedIndex=e,!1}),!0;case"label":var a=q(t.attr("for")),n=t.find("input,select,textarea");return a[0]&&n.unshift(a[0]),n.resetForm(),!0;case"form":return"function"!=typeof this.reset&&("object"!=typeof this.reset||this.reset.nodeType)||this.reset(),!0;default:return t.find("form,input,label,select,textarea").resetForm(),!0}})},q.fn.enable=function(e){return void 0===e&&(e=!0),this.each(function(){this.disabled=!e})},q.fn.selected=function(r){return void 0===r&&(r=!0),this.each(function(){var e,t=this.type;"checkbox"===t||"radio"===t?this.checked=r:"option"===this.tagName.toLowerCase()&&(e=q(this).parent("select"),r&&e[0]&&"select-one"===e[0].type&&e.find("option").selected(!1),this.selected=r)})},q.fn.ajaxSubmit.debug=!1});
;
(function ($) {

"use strict";

/**
 * Attach the tableResponsive function to Backdrop.behaviors.
 */
Backdrop.behaviors.tableResponsive = {
  attach: function (context, settings) {
    var $tables = $(context).find('table.responsive-enabled').once('tableresponsive');
    if ($tables.length) {
      for (var i = 0, il = $tables.length; i < il; i++) {
        TableResponsive.tables.push(new TableResponsive($tables[i]));
      }
    }
  }
};

/**
 * The TableResponsive object optimizes table presentation for all screen sizes.
 *
 * A responsive table hides columns at small screen sizes, leaving the most
 * important columns visible to the end user. Users should not be prevented from
 * accessing all columns, however. This class adds a toggle to a table with
 * hidden columns that exposes the columns. Exposing the columns will likely
 * break layouts, but it provides the user with a means to access data, which
 * is a guiding principle of responsive design.
 */
function TableResponsive (table) {
  this.table = table;
  this.$table = $(table);
  this.showText = Backdrop.t('Show all columns');
  this.hideText = Backdrop.t('Hide less important columns');
  // Store a reference to the header elements of the table so that the DOM is
  // traversed only once to find them.
  this.$headers = this.$table.find('th');
  // Add a link before the table for users to show or hide weight columns.
  this.$link = $('<a href="#" class="tableresponsive-toggle">' + this.showText + '</a>')
    .attr({
      'title': Backdrop.t('Toggle visibility of table cells, that were hidden to make the table fit within a small screen.')
    })
    .on('click', $.proxy(this, 'eventhandlerToggleColumns'));

  this.$table.before($('<div class="tableresponsive-toggle-columns"></div>').append(this.$link));

  var _this = this;
  Backdrop.optimizedResize.add(function() {
    $.proxy(_this, 'eventhandlerEvaluateColumnVisibility');
    $(window).trigger('resize.tableresponsive');
  });
}

/**
 * Extend the TableResponsive function with a list of managed tables.
 */
$.extend(TableResponsive, {
  tables: []
});

/**
 * Associates an action link with the table that will show hidden columns.
 *
 * Columns are assumed to be hidden if their header has the class priority-low
 * or priority-medium.
 */
$.extend(TableResponsive.prototype, {
  eventhandlerEvaluateColumnVisibility: function (e) {
    var pegged = parseInt(this.$link.data('pegged'), 10);
    var hiddenLength = this.$headers.filter('.priority-medium:hidden, .priority-low:hidden').length;

    // If the table is not at all visible, do not manipulate the link.
    var tableVisible = this.$table.is(':visible');
    if (!tableVisible) {
      return;
    }

    // If the table has hidden columns, associate an action link with the table
    // to show the columns.
    if (hiddenLength > 0) {
      this.$link.show().text(this.showText);
    }
    // When the toggle is pegged, its presence is maintained because the user
    // has interacted with it. This is necessary to keep the link visible if the
    // user adjusts screen size and changes the visibility of columns.
    if (!pegged && hiddenLength === 0) {
      this.$link.hide().text(this.hideText);
    }
  },
  // Toggle the visibility of columns classed with either 'priority-low' or
  // 'priority-medium'.
  eventhandlerToggleColumns: function (e) {
    e.preventDefault();
    var self = this;
    var $hiddenHeaders = this.$headers.filter('.priority-medium:hidden, .priority-low:hidden');
    this.$revealedCells = this.$revealedCells || $();
    // Reveal hidden columns.
    if ($hiddenHeaders.length > 0) {
      $hiddenHeaders.each(function (index, element) {
        var $header = $(this);
        var position = $header.prevAll('th').length;
        self.$table.find('tbody tr').each(function () {
          var $cells = $(this).find('td:eq(' + position + ')');
          $cells.show();
          // Keep track of the revealed cells, so they can be hidden later.
          self.$revealedCells = $().add(self.$revealedCells).add($cells);
        });
        $header.show();
        // Keep track of the revealed headers, so they can be hidden later.
        self.$revealedCells = $().add(self.$revealedCells).add($header);
      });
      this.$link.text(this.hideText).data('pegged', 1);
    }
    // Hide revealed columns.
    else {
      this.$revealedCells.hide();
      // Strip the 'display:none' declaration from the style attributes of
      // the table cells that .hide() added.
      this.$revealedCells.css('display', '');
      this.$link.text(this.showText).data('pegged', 0);
      // Refresh the toggle link.
      $(window).trigger('resize.tableresponsive');
    }
  }
});
// Make the TableResponsive object available in the Backdrop namespace.
Backdrop.TableResponsive = TableResponsive;

})(jQuery);
;
(function ($) {

/**
 * This script transforms a set of fieldsets into a stack of vertical
 * tabs. Another tab pane can be selected by clicking on the respective
 * tab.
 *
 * Each tab may have a summary which can be updated by another
 * script. For that to work, each fieldset has an associated
 * 'verticalTabCallback' (with jQuery.data() attached to the fieldset),
 * which is called every time the user performs an update to a form
 * element inside the tab pane.
 */
Backdrop.behaviors.verticalTabs = {
  attach: function (context) {
    $('.vertical-tabs-panes', context).once('vertical-tabs', function () {
      var focusID = $(':hidden.vertical-tabs-active-tab', this).val();
      var tab_focus;

      // Check if there are some fieldsets that can be converted to vertical-tabs
      var $fieldsets = $('> fieldset', this);
      if ($fieldsets.length <= 1) {
        return;
      }

      // Create the tab column.
      var tab_list = $('<ul class="vertical-tabs-list"></ul>');
      $(this).wrap('<div class="vertical-tabs clearfix"></div>').before(tab_list);

      // Transform each fieldset into a tab.
      $fieldsets.each(function () {
        var vertical_tab = new Backdrop.verticalTab({
          title: $('> legend', this).text(),
          fieldset: $(this),
        });
        tab_list.append(vertical_tab.item);
        $(this)
          .removeClass('collapsible collapsed')
          .addClass('vertical-tabs-pane')
          .data('verticalTab', vertical_tab);
        if (this.id == focusID) {
          tab_focus = $(this);
        }
      });

      $('> li:first', tab_list).addClass('first');
      $('> li:last', tab_list).addClass('last');

      if (!tab_focus) {
        // If the current URL has a fragment and one of the tabs contains an
        // element that matches the URL fragment, activate that tab.
        if (window.location.hash && $(this).find(window.location.hash).length) {
          tab_focus = $(this).find(window.location.hash).closest('.vertical-tabs-pane');
        }
        else {
          tab_focus = $fieldsets.first();
        }
      }
      if (tab_focus.length) {
        tab_focus.data('verticalTab').focus();
      }
    });
  }
};

/**
 * The vertical tab object represents a single tab within a tab group.
 *
 * @param settings
 *   An object with the following keys:
 *   - title: The name of the tab.
 *   - fieldset: The jQuery object of the fieldset that is the tab pane.
 */
Backdrop.verticalTab = function (settings) {
  var self = this;
  $.extend(this, settings, Backdrop.theme('verticalTab', settings));

  this.link.on('click', function () {
    self.focus();
    return false;
  });

  this.fieldset.children('legend').on('click', function () {
    self.focus();
    return false;
  });

  // Keyboard events added:
  // Pressing the Enter key will open the tab pane.
  this.link.on('keydown', function(event) {
    if (event.keyCode == 13) {
      self.focus();
      // Set focus on the first input field of the visible fieldset/tab pane.
      $("fieldset.vertical-tabs-pane :input:visible:enabled:first").focus();
      return false;
    }
  });

  // Add summary to legend which is seen on smaller breakpoints
  var $legend = this.fieldset.children('legend');
  $legend.append(this.legendSummary = $('<span class="summary"></span>'));
  $legend.addClass('vertical-tab-link');

  this.fieldset
    .on('summaryUpdated', function () {
      self.updateSummary();
    })
    .trigger('summaryUpdated');
};

Backdrop.verticalTab.prototype = {
  /**
   * Displays the tab's content pane.
   */
  focus: function () {
    // Update tab control for desktop
    this.item.siblings('.vertical-tab-selected').removeClass('vertical-tab-selected');
    this.item
      .addClass('vertical-tab-selected')
      .siblings(':hidden.vertical-tabs-active-tab')
        .val(this.fieldset.attr('id'));
    // Update classes on previous active and new active pane
    this.fieldset.siblings('.vertical-tab-selected').removeClass('vertical-tab-selected');
    this.fieldset.addClass('vertical-tab-selected');
    // Mark the active tab for screen readers.
    $('#active-vertical-tab').remove();
    this.link.append('<span id="active-vertical-tab" class="element-invisible">' + Backdrop.t('(active tab)') + '</span>');
  },

  /**
   * Updates the tab's summary.
   */
  updateSummary: function () {
    var summaryText = this.fieldset.backdropGetSummary();
    this.summary.html(summaryText);
    this.legendSummary.html(summaryText);
  },

  /**
   * Shows a vertical tab pane.
   */
  tabShow: function () {
    // Show the tab.
    this.item.show();

    // Update .first marker for items. We need recurse from parent to retain the
    // actual DOM element order as jQuery implements sortOrder, but not as public
    // method.
    var $allTabs = this.item.parent().children('.vertical-tab-item');
    $allTabs.removeClass('first').filter(':visible:first').addClass('first');

    // Remove hidden class, in case tabHide was run on this tab.
    this.fieldset.removeClass('vertical-tab-hidden').show();

    // Focus this tab if it is the only one.
    if ($allTabs.length === 1) {
      $allTabs.first().data('verticalTab').focus();
    }

    return this;
  },

  /**
   * Hides a vertical tab pane.
   */
  tabHide: function () {
    // Hide the tab.
    this.item.hide();

    // Update .first marker for items. We need recurse from parent to retain the
    // actual DOM element order as jQuery implements sortOrder, but not as public
    // method.
    this.item.parent().children('.vertical-tab-item').removeClass('first')
      .filter(':visible:first').addClass('first');

    // Hide the fieldset.
    this.fieldset.addClass('vertical-tab-hidden').hide();

    // Focus the first visible tab (if there is one).
    var $firstTab = this.fieldset.siblings('.vertical-tabs-pane:not(.vertical-tab-hidden):first');
    if ($firstTab.length) {
      $firstTab.data('verticalTab').focus();
    }
    return this;
  }
};

/**
 * Theme function for a vertical tab.
 *
 * @param settings
 *   An object with the following keys:
 *   - title: The name of the tab.
 * @return
 *   This function has to return an object with at least these keys:
 *   - item: The root tab jQuery element
 *   - link: The anchor tag that acts as the clickable area of the tab
 *       (jQuery version)
 *   - summary: The jQuery element that contains the tab summary
 */
Backdrop.theme.prototype.verticalTab = function (settings) {
  var tab = {};
  // Calculating height in em so CSS has a chance to update height
  tab.item = $('<li class="vertical-tab-item" tabindex="-1"></li>')
    .append(tab.link = $('<a href="#" class="vertical-tab-link"></a>')
      .append(tab.title = $('<strong></strong>').text(settings.title))
      .append(tab.summary = $('<span class="summary"></span>')
    )
  );
  return tab;
};

})(jQuery);
;
/**
 * @file
 * Attaches behaviors for the Contextual module.
 */

(function ($) {

Backdrop.contextualLinks = Backdrop.contextualLinks || {};

/**
 * Attaches outline behavior for regions associated with contextual links.
 */
Backdrop.behaviors.contextualLinks = {
  attach: function (context) {
    $('.contextual-links-wrapper', context).once('contextual-links', function () {
      var $wrapper = $(this);
      var $region = $wrapper.closest('.contextual-links-region');
      var $links = $wrapper.find('ul.contextual-links');
      var $trigger = $('<a class="contextual-links-trigger" href="#" />').text(Backdrop.t('Configure')).on('click',
        function () {
          $links.stop(true, true).slideToggle(100);
          $wrapper.toggleClass('contextual-links-active');
          return false;
        }
      );

      // Attach hover behavior to trigger and ul.contextual-links.
      $trigger.add($links).on('mouseenter', function () {
        $region.addClass('contextual-links-region-active');
      });
      $trigger.add($links).on('mouseleave', function () {
        $region.removeClass('contextual-links-region-active');
      });

      // Hide the contextual links when user clicks a link or rolls out of the
      // .contextual-links-region.
      $region.on('mouseleave click', Backdrop.contextualLinks.mouseleave);
      $region.on('mouseenter', function() {
        $trigger.addClass('contextual-links-trigger-active');
      });
      $region.on('mouseleave', function() {
        $trigger.removeClass('contextual-links-trigger-active');
      });

      // Prepend the trigger.
      $wrapper.prepend($trigger);
    });

    /**
     * Adjusts trigger positions in contextual links to avoid overlaps.
     */
    function adjustContextualLinks() {
      // Get all wrappers anywhere on the page and some info about each.
      var allWrappers = [];
      $('.contextual-links-wrapper', context).each(function() {
        allWrappers.push({
          '$wrapper': $(this),
          'regionOffsetBottom': $(this).parent().offset().top + $(this).parent().height(),
          'hShift': 0,
          'vShift': 0
        });
      });

      // Reset margins on all wrappers.
      allWrappers.forEach(function(info) {
        info.$wrapper.css('margin', '0');
      });

      // Recalculate margins to avoid collisions.
      var dir = $('html').attr('dir');
      const hSize = 28; // width of trigger wrapper
      const vSize = 19; // height of trigger wrapper
      var n = allWrappers.length;
      for (let i = 0; i < n; i++) {
        var follower = allWrappers[i];
        // Compare follower against all of its predecessors in the list (any of
        // which may have already been adjusted).
        for (let j = 0; j < i; j++) {
          var leader = allWrappers[j];
          // Adjust the position of follower if necessary to avoid collision
          // with leader.
          var leaderOffset = leader.$wrapper.offset();
          var followerOffset = follower.$wrapper.offset();
          // Check vertical overlap.
          if (!(followerOffset.top >= leaderOffset.top && followerOffset.top < leaderOffset.top + vSize)) {
            continue;
          }
          if (dir == 'ltr') {
            // Check horizontal overlap.
            if (followerOffset.left >= leaderOffset.left - hSize && followerOffset.left < leaderOffset.left + hSize) {
              // We have a collision; shift the follower down if there's room,
              // otherwise left.
              if (followerOffset.top + 2 * vSize <= follower.regionOffsetBottom) {
                // Shift down
                follower.vShift += vSize;
                follower.$wrapper.css('margin-top', follower.vShift);
              }
              else {
                // Shift left and start a new column.
                follower.vShift = 0;
                follower.hShift += hSize;
                follower.$wrapper.css('margin-top', follower.vShift);
                follower.$wrapper.css('margin-right', follower.hShift);
              }
            }
          }
          else { // rtl
            // Check horizontal overlap.
            if (followerOffset.left > leaderOffset.left - hSize && followerOffset.left <= leaderOffset.left + hSize) {
              // We have a collision; shift the follower down if there's room,
              // otherwise right.
              if (followerOffset.top + 2 * vSize <= follower.regionOffsetBottom) {
                // Shift down
                follower.vShift += vSize;
                follower.$wrapper.css('margin-top', follower.vShift);
              }
              else {
                // Shift right and start a new column.
                follower.vShift = 0;
                follower.hShift += hSize;
                follower.$wrapper.css('margin-top', follower.vShift);
                follower.$wrapper.css('margin-left', follower.hShift);
              }
            }
          }
        }
      }
    }
    $(document).ready(adjustContextualLinks);

    // Usually Backdrop.optimizedResize() would be used for a window resize
    // event, but this potentially expensive operation should be limited to
    // firing infrequently, so Backdrop.debounce() is used here instead.
    $(window).on('resize', Backdrop.debounce(adjustContextualLinks, 500));
  }
};

/**
 * Disables outline for the region contextual links are associated with.
 */
Backdrop.contextualLinks.mouseleave = function () {
  $(this)
    .find('.contextual-links-active').removeClass('contextual-links-active')
    .find('ul.contextual-links').hide();
};

})(jQuery);
;
(function ($) {

/**
 * Retrieves the summary for the first element.
 */
$.fn.backdropGetSummary = function () {
  var callback = this.data('summaryCallback');
  var returnValue = (this[0] && callback) ? callback(this[0]) : '';
  return typeof returnValue === 'string' ? returnValue.trim() : '';
};

/**
 * Sets the summary for all matched elements.
 *
 * @param callback
 *   Either a function that will be called each time the summary is
 *   retrieved or a string (which is returned each time).
 */
$.fn.backdropSetSummary = function (callback) {
  var self = this;

  // To facilitate things, the callback should always be a function. If it's
  // not, we wrap it into an anonymous function which just returns the value.
  if (typeof callback != 'function') {
    var val = callback;
    callback = function () { return val; };
  }

  return this
    .data('summaryCallback', callback)
    // To prevent duplicate events, the handlers are first removed and then
    // (re-)added.
    .off('formUpdated.summary')
    .on('formUpdated.summary', function () {
      self.trigger('summaryUpdated');
    })
    // The actual summaryUpdated handler doesn't fire when the callback is
    // changed, so we have to do this manually.
    .trigger('summaryUpdated');
};

/**
 * Sends a 'formUpdated' event each time a form element is modified.
 */
Backdrop.behaviors.formUpdated = {
  attach: function (context) {
    // These events are namespaced so that we can remove them later.
    var events = 'change.formUpdated click.formUpdated blur.formUpdated keyup.formUpdated';
    $(context)
      // Since context could be an input element itself, it's added back to
      // the jQuery object and filtered again.
      .find(':input').addBack().filter(':input')
      // To prevent duplicate events, the handlers are first removed and then
      // (re-)added.
      .off(events).on(events, function () {
        $(this).trigger('formUpdated');
      });
  }
};

/**
 * Prevents consecutive form submissions of identical form values.
 *
 * Repetitive form submissions that would submit the identical form values are
 * prevented, unless the form values are different from the previously
 * submitted values.
 *
 * This is a simplified re-implementation of a user-agent behavior that should
 * be natively supported by major web browsers, but at this time, only Firefox
 * has a built-in protection.
 *
 * A form value-based approach ensures that the constraint is triggered for
 * consecutive, identical form submissions only. Compared to that, a form
 * button-based approach would (1) rely on [visible] buttons to exist where
 * technically not required and (2) require more complex state management if
 * there are multiple buttons in a form.
 *
 * This implementation is based on form-level submit events only, and relies on
 * jQuery's serialize() method to determine submitted form values. As such, the
 * following limitations exist:
 *
 * - Event handlers on form buttons that preventDefault() do not receive a
 *   double-submit protection. That is deemed to be fine, since such button
 *   events typically trigger reversible client-side or server-side operations
 *   that are local to the context of a form only.
 * - Changed values in advanced form controls, such as file inputs, are not part
 *   of the form values being compared between consecutive form submits (due to
 *   limitations of jQuery.serialize()). That is deemed to be acceptable,
 *   because if the user forgot to attach a file, then the size of HTTP payload
 *   will most likely be small enough to be fully passed to the server endpoint
 *   within (milli)seconds. If a user mistakenly attached a wrong file and is
 *   technically versed enough to cancel the form submission (and HTTP payload)
 *   in order to attach a different file, then that edge-case is not supported
 *   here.
 *
 * Lastly, all forms submitted via HTTP GET are idempotent by definition of HTTP
 * standards, so excluded in this implementation.
 */
Backdrop.behaviors.formSingleSubmit = {
  attach: function () {
    function onFormSubmit (e) {
      // Prevent this from firing multiple times per request.
      e.stopImmediatePropagation();
      if (e.isDefaultPrevented()) {
        // Don't act on form submissions that have been prevented by other JS.
        return;
      }
      var $form = $(e.currentTarget);
      var formValues = $form.serialize();
      var previousValues = $form.attr('data-backdrop-form-submit-last');
      if (previousValues === formValues) {
        e.preventDefault();
      }
      else {
        $form.attr('data-backdrop-form-submit-last', formValues);
      }
    }

    $('body').once('form-single-submit')
      .on('submit.singleSubmit', 'form:not([method~="GET"])', onFormSubmit);

  }
};

/**
 * Prepopulate form fields with information from the visitor cookie.
 */
Backdrop.behaviors.fillUserInfoFromCookie = {
  attach: function (context, settings) {
    $('form.user-info-from-cookie').once('user-info-from-cookie', function () {
      var formContext = this;
      $.each(['name', 'mail', 'homepage'], function () {
        var $element = $('[name=' + this + ']', formContext);
        var cookie = $.cookie('Backdrop.visitor.' + this);
        if ($element.length && cookie) {
          $element.val(cookie);
        }
      });
    });
  }
};

})(jQuery);
;
(function ($) {

/**
 * The base States namespace.
 *
 * Having the local states variable allows us to use the States namespace
 * without having to always declare "Backdrop.states".
 */
var states = Backdrop.states = {
  // An array of functions that should be postponed.
  postponed: []
};

/**
 * Attaches the states.
 */
Backdrop.behaviors.states = {
  attach: function (context, settings) {
    var $context = $(context);
    for (var selector in settings.states) {
      if (settings.states.hasOwnProperty(selector)) {
        for (var state in settings.states[selector]) {
          if (settings.states[selector].hasOwnProperty(state)) {
            new states.Dependent({
              element: $context.find(selector),
              state: states.State.sanitize(state),
              constraints: settings.states[selector][state]
            });
          }
        }
      }
    }

    // Execute all postponed functions now.
    while (states.postponed.length) {
      (states.postponed.shift())();
    }
  }
};

/**
 * Object representing an element that depends on other elements.
 *
 * @param args
 *   Object with the following keys (all of which are required):
 *   - element: A jQuery object of the dependent element
 *   - state: A State object describing the state that is dependent
 *   - constraints: An object with dependency specifications. Lists all elements
 *     that this element depends on. It can be nested and can contain arbitrary
 *     AND and OR clauses.
 */
states.Dependent = function (args) {
  $.extend(this, { values: {}, oldValue: null }, args);

  this.dependees = this.getDependees();
  for (var selector in this.dependees) {
    if (this.dependees.hasOwnProperty(selector)) {
      this.initializeDependee(selector, this.dependees[selector]);
    }
  }
};

/**
 * Comparison functions for comparing the value of an element with the
 * specification from the dependency settings. If the object type can't be
 * found in this list, the === operator is used by default.
 */
states.Dependent.comparisons = {
  'RegExp': function (reference, value) {
    return reference.test(value);
  },
  'Function': function (reference, value) {
    // The "reference" variable is a comparison function.
    return reference(value);
  },
  'Number': function (reference, value) {
    // If "reference" is a number and "value" is a string, then cast reference
    // as a string before applying the strict comparison in compare(). Otherwise
    // numeric keys in the form's #states array fail to match string values
    // returned from jQuery's val().
    return (typeof value === 'string') ? compare(reference.toString(), value) : compare(reference, value);
  }
};

states.Dependent.prototype = {
  /**
   * Initializes one of the elements this dependent depends on.
   *
   * @param selector
   *   The CSS selector describing the dependee.
   * @param dependeeStates
   *   The list of states that have to be monitored for tracking the
   *   dependee's compliance status.
   */
  initializeDependee: function (selector, dependeeStates) {
    var state, self = this;

    function stateEventHandler(e) {
      self.update(e.data.selector, e.data.state, e.value);
    }

    // Cache for the states of this dependee.
    this.values[selector] = {};

    for (var i in dependeeStates) {
      if (dependeeStates.hasOwnProperty(i)) {
        state = dependeeStates[i];
        // Make sure we're not initializing this selector/state combination twice.
        if ($.inArray(state, dependeeStates) === -1) {
          continue;
        }

        state = states.State.sanitize(state);

        // Initialize the value of this state.
        this.values[selector][state.name] = null;

        // Monitor state changes of the specified state for this dependee.
        $(selector).on('state:' + state, {selector: selector, state: state}, stateEventHandler);

        // Make sure the event we just bound ourselves to is actually fired.
        new states.Trigger({ selector: selector, state: state });
      }
    }
  },

  /**
   * Compares a value with a reference value.
   *
   * @param reference
   *   The value used for reference.
   * @param selector
   *   CSS selector describing the dependee.
   * @param state
   *   A State object describing the dependee's updated state.
   *
   * @return
   *   true or false.
   */
  compare: function (reference, selector, state) {
    var value = this.values[selector][state.name];
    if (reference.constructor.name in states.Dependent.comparisons) {
      // Use a custom compare function for certain reference value types.
      return states.Dependent.comparisons[reference.constructor.name](reference, value);
    }
    else {
      // Do a plain comparison otherwise.
      return compare(reference, value);
    }
  },

  /**
   * Update the value of a dependee's state.
   *
   * @param selector
   *   CSS selector describing the dependee.
   * @param state
   *   A State object describing the dependee's updated state.
   * @param value
   *   The new value for the dependee's updated state.
   */
  update: function (selector, state, value) {
    // Only act when the 'new' value is actually new.
    if (value !== this.values[selector][state.name]) {
      this.values[selector][state.name] = value;
      this.reevaluate();
    }
  },

  /**
   * Triggers change events in case a state changed.
   */
  reevaluate: function () {
    // Check whether any constraint for this dependent state is satisfied.
    var value = this.verifyConstraints(this.constraints);

    // Only invoke a state change event when the value actually changed.
    if (value !== this.oldValue) {
      // Store the new value so that we can compare later whether the value
      // actually changed.
      this.oldValue = value;

      // Normalize the value to match the normalized state name.
      value = invert(value, this.state.invert);

      // By adding "trigger: true", we ensure that state changes don't go into
      // infinite loops.
      this.element.trigger({ type: 'state:' + this.state, value: value, trigger: true });
    }
  },

  /**
   * Evaluates child constraints to determine if a constraint is satisfied.
   *
   * @param constraints
   *   A constraint object or an array of constraints.
   * @param selector
   *   The selector for these constraints. If undefined, there isn't yet a
   *   selector that these constraints apply to. In that case, the keys of the
   *   object are interpreted as the selector if encountered.
   *
   * @return
   *   true or false, depending on whether these constraints are satisfied.
   */
  verifyConstraints: function(constraints, selector) {
    var result;
    if (Array.isArray(constraints)) {
      // This constraint is an array (OR or XOR).
      var hasXor = $.inArray('xor', constraints) === -1;
      for (var i = 0, len = constraints.length; i < len; i++) {
        if (constraints[i] != 'xor') {
          var constraint = this.checkConstraints(constraints[i], selector, i);
          // Return if this is OR and we have a satisfied constraint or if this
          // is XOR and we have a second satisfied constraint.
          if (constraint && (hasXor || result)) {
            return hasXor;
          }
          result = result || constraint;
        }
      }
    }
    // Make sure we don't try to iterate over things other than objects. This
    // shouldn't normally occur, but in case the condition definition is bogus,
    // we don't want to end up with an infinite loop.
    else if ($.isPlainObject(constraints)) {
      // This constraint is an object (AND).
      for (var n in constraints) {
        if (constraints.hasOwnProperty(n)) {
          result = ternary(result, this.checkConstraints(constraints[n], selector, n));
          // False and anything else will evaluate to false, so return when any
          // false condition is found.
          if (result === false) { return false; }
        }
      }
    }
    return result;
  },

  /**
   * Checks whether the value matches the requirements for this constraint.
   *
   * @param value
   *   Either the value of a state or an array/object of constraints. In the
   *   latter case, resolving the constraint continues.
   * @param selector
   *   The selector for this constraint. If undefined, there isn't yet a
   *   selector that this constraint applies to. In that case, the state key is
   *   propagates to a selector and resolving continues.
   * @param state
   *   The state to check for this constraint. If undefined, resolving
   *   continues.
   *   If both selector and state aren't undefined and valid non-numeric
   *   strings, a lookup for the actual value of that selector's state is
   *   performed. This parameter is not a State object but a pristine state
   *   string.
   *
   * @return
   *   true or false, depending on whether this constraint is satisfied.
   */
  checkConstraints: function(value, selector, state) {
    // Normalize the last parameter. If it's non-numeric, we treat it either as
    // a selector (in case there isn't one yet) or as a trigger/state.
    if (typeof state !== 'string' || (/[0-9]/).test(state[0])) {
      state = null;
    }
    else if (typeof selector === 'undefined') {
      // Propagate the state to the selector when there isn't one yet.
      selector = state;
      state = null;
    }

    if (state !== null) {
      // constraints is the actual constraints of an element to check for.
      state = states.State.sanitize(state);
      return invert(this.compare(value, selector, state), state.invert);
    }
    else {
      // Resolve this constraint as an AND/OR operator.
      return this.verifyConstraints(value, selector);
    }
  },

  /**
   * Gathers information about all required triggers.
   */
  getDependees: function() {
    var cache = {};
    // Swivel the lookup function so that we can record all available selector-
    // state combinations for initialization.
    var _compare = this.compare;
    this.compare = function(reference, selector, state) {
      (cache[selector] || (cache[selector] = [])).push(state.name);
      // Return nothing (=== undefined) so that the constraint loops are not
      // broken.
    };

    // This call doesn't actually verify anything but uses the resolving
    // mechanism to go through the constraints array, trying to look up each
    // value. Since we swivelled the compare function, this comparison returns
    // undefined and lookup continues until the very end. Instead of lookup up
    // the value, we record that combination of selector and state so that we
    // can initialize all triggers.
    this.verifyConstraints(this.constraints);
    // Restore the original function.
    this.compare = _compare;

    return cache;
  }
};

states.Trigger = function (args) {
  $.extend(this, args);

  if (this.state in states.Trigger.states) {
    this.element = $(this.selector);

    // Only call the trigger initializer when it wasn't yet attached to this
    // element. Otherwise we'd end up with duplicate events.
    if (!this.element.data('trigger:' + this.state)) {
      this.initialize();
    }
  }
};

states.Trigger.prototype = {
  initialize: function () {
    var trigger = states.Trigger.states[this.state];

    if (typeof trigger == 'function') {
      // We have a custom trigger initialization function.
      trigger.call(window, this.element);
    }
    else {
      for (var event in trigger) {
        if (trigger.hasOwnProperty(event)) {
          this.defaultTrigger(event, trigger[event]);
        }
      }
    }

    // Mark this trigger as initialized for this element.
    this.element.data('trigger:' + this.state, true);
  },

  defaultTrigger: function (event, valueFn) {
    var oldValue = valueFn.call(this.element);

    // Attach the event callback.
    this.element.on(event, $.proxy(function (e) {
      var value = valueFn.call(this.element, e);
      // Only trigger the event if the value has actually changed.
      if (oldValue !== value) {
        this.element.trigger({ type: 'state:' + this.state, value: value, oldValue: oldValue });
        oldValue = value;
      }
    }, this));

    states.postponed.push($.proxy(function () {
      // Trigger the event once for initialization purposes.
      this.element.trigger({ type: 'state:' + this.state, value: oldValue, oldValue: null });
    }, this));
  }
};

/**
 * This list of states contains functions that are used to monitor the state
 * of an element. Whenever an element depends on the state of another element,
 * one of these trigger functions is added to the dependee so that the
 * dependent element can be updated.
 */
states.Trigger.states = {
  // 'empty' describes the state to be monitored
  empty: {
    // 'keyup' is the (native DOM) event that we watch for.
    'keyup': function () {
      // The function associated to that trigger returns the new value for the
      // state.
      return this.val() == '';
    }
  },

  checked: {
    'change': function () {
      // prop() and attr() only takes the first element into account. To support
      // selectors matching multiple checkboxes, iterate over all and return
      // whether any is checked.
      var checked = false;
      this.each(function () {
        // Use prop() here as we want a boolean of the checkbox state.
        // @see http://api.jquery.com/prop/
        checked = $(this).prop('checked');
        // Break the each() loop if this is checked.
        return !checked;
      });
      return checked;
    }
  },

  // For radio buttons, only return the value if the radio button is selected.
  value: {
    'keyup': function () {
      // Radio buttons share the same :input[name="key"] selector.
      if (this.length > 1) {
        // Initial checked value of radios is undefined, so we return false.
        return this.filter(':checked').val() || false;
      }
      return this.val();
    },
    'change': function () {
      // Radio buttons share the same :input[name="key"] selector.
      if (this.length > 1) {
        // Initial checked value of radios is undefined, so we return false.
        return this.filter(':checked').val() || false;
      }
      return this.val();
    }
  },

  collapsed: {
    'collapsed': function(e) {
      return (typeof e !== 'undefined' && 'value' in e) ? e.value : this.is('.collapsed');
    }
  }
};


/**
 * A state object is used for describing the state and performing aliasing.
 */
states.State = function(state) {
  // We may need the original unresolved name later.
  this.pristine = this.name = state;

  // Normalize the state name.
  while (true) {
    // Iteratively remove exclamation marks and invert the value.
    while (this.name.charAt(0) == '!') {
      this.name = this.name.substring(1);
      this.invert = !this.invert;
    }

    // Replace the state with its normalized name.
    if (this.name in states.State.aliases) {
      this.name = states.State.aliases[this.name];
    }
    else {
      break;
    }
  }
};

/**
 * Creates a new State object by sanitizing the passed value.
 */
states.State.sanitize = function (state) {
  if (state instanceof states.State) {
    return state;
  }
  else {
    return new states.State(state);
  }
};

/**
 * This list of aliases is used to normalize states and associates negated names
 * with their respective inverse state.
 */
states.State.aliases = {
  'enabled': '!disabled',
  'invisible': '!visible',
  'invalid': '!valid',
  'untouched': '!touched',
  'optional': '!required',
  'filled': '!empty',
  'unchecked': '!checked',
  'irrelevant': '!relevant',
  'expanded': '!collapsed',
  'readwrite': '!readonly'
};

states.State.prototype = {
  invert: false,

  /**
   * Ensures that just using the state object returns the name.
   */
  toString: function() {
    return this.name;
  }
};

/**
 * Global state change handlers. These are bound to "document" to cover all
 * elements whose state changes. Events sent to elements within the page
 * bubble up to these handlers. We use this system so that themes and modules
 * can override these state change handlers for particular parts of a page.
 */

$(document).on('state:disabled', function(e) {
  // Only act when this change was triggered by a dependency and not by the
  // element monitoring itself.
  if (e.trigger) {
    $(e.target)
      .prop('disabled', e.value)
        .closest('.form-item, .form-submit, .form-wrapper').toggleClass('form-disabled', e.value)
        .find('select, input, textarea').prop('disabled', e.value);

    // Note: WebKit nightlies don't reflect that change correctly.
    // See https://bugs.webkit.org/show_bug.cgi?id=23789
  }
});

$(document).on('state:required', function(e) {
  if (e.trigger) {
    if (e.value) {
      var $label = $(e.target).closest('.form-item, .form-wrapper').find('label');
      // Avoids duplicate required markers on initialization.
      if (!$label.find('.form-required').length) {
        $label.append('<abbr class="form-required" title="' + Backdrop.t('This field is required.') + '">*</abbr>');
      }
    }
    else {
      $(e.target).closest('.form-item, .form-wrapper').find('label .form-required').remove();
    }
  }
});

$(document).on('state:visible', function(e) {
  if (e.trigger) {
    $(e.target).closest('.form-item, .form-submit, .form-wrapper').toggle(e.value);
  }
});

$(document).on('state:checked', function(e) {
  if (e.trigger) {
    $(e.target).prop('checked', e.value);
  }
});

$(document).on('state:collapsed', function(e) {
  if (e.trigger) {
    if ($(e.target).is('.collapsed') !== e.value) {
      $('> legend a', e.target).trigger('click');
    }
  }
});


/**
 * These are helper functions implementing addition "operators" and don't
 * implement any logic that is particular to states.
 */

// Bitwise AND with a third undefined state.
function ternary (a, b) {
  return typeof a === 'undefined' ? b : (typeof b === 'undefined' ? a : a && b);
}

// Inverts a (if it's not undefined) when invertState is true.
function invert (a, invertState) {
  return (invertState && typeof a !== 'undefined') ? !a : a;
}

// Compares two values while ignoring undefined values.
function compare (a, b) {
  return (a === b) ? (typeof a === 'undefined' ? a : true) : (typeof a === 'undefined' || typeof b === 'undefined');
}

})(jQuery);
;
