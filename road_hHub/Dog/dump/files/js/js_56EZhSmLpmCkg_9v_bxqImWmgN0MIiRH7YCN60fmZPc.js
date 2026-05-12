(function ($) {

/**
 * A progressbar object. Initialized with the given id. Must be inserted into
 * the DOM afterwards through progressBar.element.
 *
 * method is the function which will perform the HTTP request to get the
 * progress bar state. Either "GET" or "POST".
 *
 * e.g. pb = new progressBar('myProgressBar');
 *      some_element.appendChild(pb.element);
 */
Backdrop.progressBar = function (id, updateCallback, method, errorCallback) {
  this.id = id;
  this.method = method || 'GET';
  this.updateCallback = updateCallback;
  this.errorCallback = errorCallback;

  // The WAI-ARIA setting aria-live="polite" will announce changes after users
  // have completed their current activity and not interrupt the screen reader.
  this.element = $('<div class="progress" aria-live="polite"></div>').attr('id', id);
  this.element.html('<div class="bar"><div class="filled"></div></div>' +
                    '<div class="percentage"></div>' +
                    '<div class="message">&nbsp;</div>');
};

/**
 * Set the percentage and status message for the progressbar.
 */
Backdrop.progressBar.prototype.setProgress = function (percentage, message) {
  if (percentage >= 0 && percentage <= 100) {
    $('div.filled', this.element).css('width', percentage + '%');
    $('div.percentage', this.element).html(percentage + '%');
  }
  $('div.message', this.element).html(message);
  if (this.updateCallback) {
    this.updateCallback(percentage, message, this);
  }
};

/**
 * Start monitoring progress via Ajax.
 */
Backdrop.progressBar.prototype.startMonitoring = function (uri, delay) {
  this.delay = delay;
  this.uri = uri;
  this.sendPing();
};

/**
 * Stop monitoring progress via Ajax.
 */
Backdrop.progressBar.prototype.stopMonitoring = function () {
  clearTimeout(this.timer);
  // This allows monitoring to be stopped from within the callback.
  this.uri = null;
};

/**
 * Request progress data from server.
 */
Backdrop.progressBar.prototype.sendPing = function () {
  if (this.timer) {
    clearTimeout(this.timer);
  }
  if (this.uri) {
    var pb = this;
    // When doing a post request, you need non-null data. Otherwise a
    // HTTP 411 or HTTP 406 (with Apache mod_security) error may result.
    $.ajax({
      type: this.method,
      url: this.uri,
      data: '',
      dataType: 'json',
      success: function (progress) {
        // Display errors.
        if (progress.status == 0) {
          pb.displayError(progress.data);
          return;
        }
        // Update display.
        pb.setProgress(progress.percentage, progress.message);
        // Schedule next timer.
        pb.timer = setTimeout(function () { pb.sendPing(); }, pb.delay);
      },
      error: function (xmlhttp) {
        pb.displayError(Backdrop.ajaxError(xmlhttp, pb.uri));
      }
    });
  }
};

/**
 * Display errors on the page.
 */
Backdrop.progressBar.prototype.displayError = function (string) {
  var error = $('<div class="messages error"></div>').html(string);
  $(this.element).before(error).hide();

  if (this.errorCallback) {
    this.errorCallback(this);
  }
};

})(jQuery);
;

/**
 * @file
 * Provides JavaScript additions to the managed file field type.
 *
 * This file provides progress bar support (if available), popup windows for
 * file previews, and disabling of other file fields during Ajax uploads (which
 * prevents separate file fields from accidentally uploading files).
 */

(function ($) {

/**
 * Attach behaviors to managed file element upload fields.
 */
Backdrop.behaviors.fileUploadChange = {
  attach: function (context, settings) {
    $(context).find('input[data-file-extensions]').once('validate-extension').on('change', Backdrop.file.validateExtension);
    $(context).find('input[data-file-auto-upload]').once('auto-upload').on('change', Backdrop.file.autoUpload).each(function() {
      $(this).closest('.form-item').find('.file-upload-button').hide();
    });
  }
};

/**
 * Attach behaviors to the file upload and remove buttons.
 */
Backdrop.behaviors.fileButtons = {
  attach: function (context) {
    $('input.form-submit', context).once('file-disable-fields').on('mousedown', Backdrop.file.disableFields);
    $('div.form-managed-file input.form-submit', context).once('file-progress-bar').on('mousedown', Backdrop.file.progressBar);
  }
};

/**
 * Attach behaviors to links within managed file elements.
 */
Backdrop.behaviors.filePreviewLinks = {
  attach: function (context) {
    $('.file-preview-link', context).once('file-preview-link').on('click', Backdrop.file.openInNewWindow);
  },
  detach: function (context){
    $('.file-preview-link', context).off('click', Backdrop.file.openInNewWindow);
  }
};

/**
 * Attach behaviors to Vertical tabs on file administration pages.
 */
Backdrop.behaviors.fileFieldsetSummaries = {
  attach: function (context) {
    $('fieldset.file-form-destination', context).backdropSetSummary(function (context) {
      var scheme = $('.form-item-scheme input:checked', context).parent().text();
      return Backdrop.t('Destination: @scheme', { '@scheme': scheme });
    });
    $('fieldset.file-form-user', context).backdropSetSummary(function (context) {
      var name = $('.form-item-name input', context).val() || Backdrop.settings.anonymous;
      return Backdrop.t('By @name', { '@name': name });
    });
  }
};

/**
 * File upload utility functions.
 */
Backdrop.file = Backdrop.file || {
  /**
   * Client-side file input validation of file extensions.
   */
  validateExtension: function (event) {
    // Add client side validation for the input[type=file].
    var extensionList = $(this).data('file-extensions');
    var extensionPattern = extensionList.replace(/,\s*/g, '|');
    if (extensionPattern.length > 1 && this.value.length > 0) {
      // Remove any previous errors.
      $('.file-upload-js-error').remove();

      var acceptableMatch = new RegExp('\\.(' + extensionPattern + ')$', 'gi');
      if (!acceptableMatch.test(this.value)) {
        var error = Backdrop.t("The selected file %filename cannot be uploaded. Only files with the following extensions are allowed: %extensions.", {
          // According to the specifications of HTML5, a file upload control
          // should not reveal the real local path to the file that a user
          // has selected. Some web browsers implement this restriction by
          // replacing the local path with "C:\fakepath\", which can cause
          // confusion by leaving the user thinking perhaps Backdrop could not
          // find the file because it messed up the file path. To avoid this
          // confusion, therefore, we strip out the bogus fakepath string.
          '%filename': this.value.replace('C:\\fakepath\\', ''),
          '%extensions': extensionPattern.replace(/\|/g, ', ')
        });
        $(this).closest('div.form-managed-file').prepend('<div class="messages error file-upload-js-error" aria-live="polite">' + error + '</div>');
        this.value = '';
        event.filePreValidation = false;
        return false;
      }
      else {
        event.filePreValidation = true;
      }
    }
  },
  /**
   * Automatically upload files by clicking the Upload button on file selection.
   */
  autoUpload: function (event) {
    // This value is set in Backdrop.file.validateExtension().
    if (event.filePreValidation === undefined || event.filePreValidation === true) {
      $(this).closest('.form-item').find('.file-upload-button').trigger('mousedown').trigger('mouseup').trigger('click');
    }
  },
  /**
   * Prevent file uploads when using buttons not intended to upload.
   */
  disableFields: function (event){
    var clickedButton = this;

    // Only disable upload fields for Ajax buttons.
    if (!$(clickedButton).hasClass('ajax-processed')) {
      return;
    }

    // Check if we're working with an "Upload" button.
    var $enabledFields = [];
    if ($(this).is('.file-upload-button')) {
      $enabledFields = $(this).closest('div.form-managed-file').find('input.form-file');
    }

    // Temporarily disable upload fields other than the one we're currently
    // working with. Filter out fields that are already disabled so that they
    // do not get enabled when we re-enable these fields at the end of behavior
    // processing. Re-enable in a setTimeout set to a relatively short amount
    // of time (1 second). All the other mousedown handlers (like Backdrop's
    // AJAX behaviors) are executed before any timeout functions are called, so
    // we don't have to worry about the fields being re-enabled too soon.
    // @todo If the previous sentence is true, why not set the timeout to 0?
    var $fieldsToTemporarilyDisable = $('div.form-managed-file input.form-file').not($enabledFields).not(':disabled');
    $fieldsToTemporarilyDisable.prop('disabled', true);
    setTimeout(function (){
      $fieldsToTemporarilyDisable.prop('disabled', false);
    }, 1000);
  },
  /**
   * Add progress bar support if possible.
   */
  progressBar: function (event) {
    var clickedButton = this;
    var $progressId = $(clickedButton).closest('div.form-managed-file').find('input.file-progress');
    if ($progressId.length) {
      var originalName = $progressId.attr('name');

      // Replace the name with the required identifier.
      $progressId.attr('name', originalName.match(/APC_UPLOAD_PROGRESS|UPLOAD_IDENTIFIER/)[0]);

      // Restore the original name after the upload begins.
      setTimeout(function () {
        $progressId.attr('name', originalName);
      }, 1000);
    }
    // Show the progress bar if the upload takes longer than half a second.
    setTimeout(function () {
      $(clickedButton).closest('div.form-managed-file').find('div.ajax-progress-bar').slideDown();
    }, 500);
  },
  /**
   * Open links to files within forms in a new window.
   */
  openInNewWindow: function (event) {
    $(this).attr('target', '_blank');
    window.open(this.href, 'filePreview', 'toolbar=0,scrollbars=1,location=1,statusbar=1,menubar=0,resizable=1,width=500,height=550');
    return false;
  },

  /**
   * Provide events for files in the file browser dialog.
   */
  dialogOpenEvent: function(e, dialog, $element, settings) {
    var $browserContainer = $element.find(".file-browser");
    $browserContainer.once('file-browser').on('click', '[data-fid]', function () {
      var $selectedElement = $(this);
      if ($selectedElement.is('img')) {
        $browserContainer.find('.image-library-image-selected').removeClass('image-library-image-selected');
        $selectedElement.parent('.image-library-choose-file').addClass('image-library-image-selected');
      }
      else {
        $browserContainer.find('.file-browser-selected').removeClass('file-browser-selected');
        $selectedElement.parent('.file-browser-file').addClass('file-browser-selected');
      }
      var selectedFid = $(this).data('fid');
      // Set the FID in the modal submit form.
      $('form.file-managed-file-browser-form [name="fid"]').val(selectedFid);
    }).on('dblclick', '.image-library-choose-file', function() {
      var $selectedElement = $(this);
      $selectedElement.click();
      var $form = $selectedElement.closest('.ui-dialog-content').find('form');
      var $submit = $form.find('.form-actions input[type=submit]:first');
      $submit.trigger('mousedown').trigger('click').trigger('mouseup');
    });
  },

  /**
   * After closing a dialog, check if the file ID needs to be updated..
   */
  dialogCloseEvent: function(e, dialog, $element) {
    var $browserContainer = $element.find(".file-browser");
    if ($browserContainer.length > 0) {
      // These two variables are set server-side when submitting the dialog, in
      // file_managed_file_browser_submit().
      var selectedFid = Backdrop.settings.file.browser.selectedFid;
      var $fidElement = $(Backdrop.settings.file.browser.currentFidElement);

      var $parentElement = $fidElement.closest('.form-type-managed-file');
      var $fileInputField = $parentElement.find('input[type="file"]');
      var $uploadButton = $parentElement.find('.file-upload-button');

      if ($fidElement.length && selectedFid) {
        // Clear any selected file (in the event it was selected before opening).
        $fileInputField.val('');

        // Set this hidden FID value to the selected file.
        $fidElement.val(selectedFid);

        // Then click the "Upload" button, which will utilize the given file.
        $uploadButton
          .trigger('mousedown')
          .trigger('click')
          .trigger('mouseup');
      }
    }
  }
};

/**
 * Attach dialog behaviors for the file browser.
 */
$(window).on('dialog:aftercreate.fileBrowser', Backdrop.file.dialogOpenEvent);
$(window).on('dialog:afterclose.fileBrowser', Backdrop.file.dialogCloseEvent);

})(jQuery);
;

(function ($) {

/**
 * Auto-hide summary textarea if empty and show hide and unhide links.
 */
Backdrop.behaviors.textSummary = {
  attach: function (context, settings) {
    $('.text-summary', context).once('text-summary', function () {
      var $widget = $(this).closest('div.field-type-text-with-summary');
      var $summaries = $widget.find('div.text-summary-wrapper');

      $summaries.once('text-summary-wrapper').each(function(index) {
        var $summary = $(this);
        var $summaryLabel = $summary.find('label').first();
        var $full = $widget.find('.text-full').eq(index).closest('.form-item');
        var $fullLabel = $full.find('label').first();

        // Create a placeholder label when the field cardinality is
        // unlimited or greater than 1.
        if ($fullLabel.length == 0) {
          $fullLabel = $('<label></label>').prependTo($full);
        }

        // Setup the edit/hide summary link.
        var $link = $('<span class="field-edit-link">(<a class="link-edit-summary" href="#">' + Backdrop.t('Hide summary') + '</a>)</span>');
        var $a = $link.find('a');
        var toggleClick = true;
        $link.on('click', function (e) {
          if (toggleClick) {
            $summary.hide();
            $a.html(Backdrop.t('Edit summary'));
            $link.appendTo($fullLabel);
          }
          else {
            $summary.show();
            $a.html(Backdrop.t('Hide summary'));
            $link.appendTo($summaryLabel);
          }
          toggleClick = !toggleClick;
          return false;
        }).appendTo($summaryLabel);

        // If no summary is set, hide the summary field.
        if ($(this).find('.text-summary').val() == '') {
          $link.trigger('click');
        }
      });
    });
  }
};

})(jQuery);
;
(function ($) {

/**
 * Toggle the visibility of a fieldset using smooth animations.
 */
Backdrop.toggleFieldset = function (fieldset) {
  var $fieldset = $(fieldset);
  if ($fieldset.is('.collapsed')) {
    var $content = $('> .fieldset-wrapper', fieldset).hide();
    var insideDialog = Boolean($fieldset.parents('.ui-dialog-content').length);
    $fieldset
      .removeClass('collapsed')
      .find('> legend span.fieldset-legend-prefix').html(Backdrop.t('Hide'));
    $content.slideDown({
      duration: 'fast',
      easing: 'linear',
      complete: function () {
        $fieldset.trigger({ type: 'collapsed', value: false });
        $(window).triggerHandler('resize');
        Backdrop.optimizedResize.trigger();
        if (insideDialog === false) {
          Backdrop.collapseScrollIntoView(fieldset);
        }
        fieldset.animating = false;
      }
    });
  }
  else {
    $('> .fieldset-wrapper', fieldset).slideUp('fast', function () {
      $fieldset
        .addClass('collapsed')
        .find('> legend span.fieldset-legend-prefix').html(Backdrop.t('Show'));
      $fieldset.trigger({ type: 'collapsed', value: true });
      $(window).triggerHandler('resize');
      Backdrop.optimizedResize.trigger();
      fieldset.animating = false;
    });
  }
};

/**
 * Scroll a given fieldset into view as much as possible.
 */
Backdrop.collapseScrollIntoView = function (node) {
  var h = document.documentElement.clientHeight || document.body.clientHeight || 0;
  var offset = document.documentElement.scrollTop || document.body.scrollTop || 0;
  var posY = $(node).offset().top;
  if (posY + node.offsetHeight > h + offset) {
    if (node.offsetHeight > h) {
      node.scrollIntoView({behavior: "smooth"});
    }
    else {
      node.scrollIntoView({behavior: "smooth", block: "end"});
    }
  }
};

Backdrop.behaviors.collapse = {
  attach: function (context, settings) {
    var hasHash = location.hash && location.hash != '#' && $(window).find(location.hash).length;
    $('fieldset.collapsible', context).once('collapse', function () {
      var $fieldset = $(this);
      // Expand fieldset if there are errors inside, or if it contains an
      // element that is targeted by the URI fragment identifier.
      var anchor = hasHash ? ', ' + location.hash : '';
      if ($fieldset.find('.error' + anchor).length) {
        $fieldset.removeClass('collapsed');
      }

      var summary = $('<span class="summary"></span>');
      $fieldset.
        on('summaryUpdated', function () {
          var text = $fieldset.backdropGetSummary();
          summary.html(text ? text : '');
        })
        .trigger('summaryUpdated');

      // Turn the legend into a clickable link, but retain span.fieldset-legend
      // for CSS positioning.
      var $legend = $('> legend .fieldset-legend', this);

      $('<span class="fieldset-legend-prefix element-invisible"></span>')
        .append($fieldset.hasClass('collapsed') ? Backdrop.t('Show') : Backdrop.t('Hide'))
        .prependTo($legend)
        .after(document.createTextNode(' '));

      // .wrapInner() does not retain bound events.
      var $link = $('<a class="fieldset-title" href="#"></a>')
        .prepend($legend.contents())
        .appendTo($legend)
        .on('click', function () {
          var fieldset = $fieldset.get(0);
          // Don't animate multiple times.
          if (!fieldset.animating) {
            fieldset.animating = true;
            Backdrop.toggleFieldset(fieldset);
          }
          return false;
        });

      $legend.append(summary);
    });
  }
};

})(jQuery);
;
(function ($) {

/**
 * Attaches the autocomplete behavior to all required fields.
 */
Backdrop.behaviors.autocomplete = {
  attach: function (context, settings) {
    var acdb = [];
    $('input.autocomplete', context).once('autocomplete', function () {
      var uri = this.value;
      if (!acdb[uri]) {
        acdb[uri] = new Backdrop.ACDB(uri);
      }
      var $input = $('#' + this.id.substr(0, this.id.length - 13))
        .attr('autocomplete', 'OFF')
        .attr('aria-autocomplete', 'list');
      $($input[0].form).on('submit', Backdrop.autocompleteSubmit);
      $input.parent()
        .attr('role', 'application')
        .append($('<span class="element-invisible" aria-live="assertive"></span>')
          .attr('id', $input[0].id + '-autocomplete-aria-live')
        );
      new Backdrop.jsAC($input, acdb[uri]);
    });
  }
};

/**
 * Prevents the form from submitting if the suggestions popup is open
 * and closes the suggestions popup when doing so.
 */
Backdrop.autocompleteSubmit = function () {
  var $autocomplete = $('#autocomplete');
  if ($autocomplete.length !== 0) {
    $autocomplete[0].owner.hidePopup();
  }
  return $autocomplete.length === 0;
};

/**
 * An AutoComplete object.
 */
Backdrop.jsAC = function ($input, db) {
  var ac = this;
  this.input = $input[0];
  this.ariaLive = $('#' + this.input.id + '-autocomplete-aria-live');
  this.db = db;

  $input
    .on('keydown', function (event) { return ac.onkeydown(this, event); })
    .on('keyup', function (event) { ac.onkeyup(this, event); })
    .on('blur', function () { ac.hidePopup(); ac.db.cancel(); });
};

/**
 * Handler for the "keydown" event.
 */
Backdrop.jsAC.prototype.onkeydown = function (input, e) {
  if (!e) {
    e = window.event;
  }
  switch (e.keyCode) {
    case 40: // down arrow.
      this.selectDown();
      return false;
    case 38: // up arrow.
      this.selectUp();
      return false;
    default: // All other keys.
      return true;
  }
};

/**
 * Handler for the "keyup" event.
 */
Backdrop.jsAC.prototype.onkeyup = function (input, e) {
  if (!e) {
    e = window.event;
  }
  switch (e.keyCode) {
    case 16: // Shift.
    case 17: // Ctrl.
    case 18: // Alt.
    case 20: // Caps lock.
    case 33: // Page up.
    case 34: // Page down.
    case 35: // End.
    case 36: // Home.
    case 37: // Left arrow.
    case 38: // Up arrow.
    case 39: // Right arrow.
    case 40: // Down arrow.
      return true;

    case 9:  // Tab.
    case 13: // Enter.
    case 27: // Esc.
      this.hidePopup(e.keyCode);
      return true;

    default: // All other keys.
      if (input.value.length > 0 && !input.readOnly) {
        this.populatePopup();
      }
      else {
        this.hidePopup(e.keyCode);
      }
      return true;
  }
};

/**
 * Puts the currently highlighted suggestion into the autocomplete field.
 */
Backdrop.jsAC.prototype.select = function (node) {
  this.input.value = $(node).data('autocompleteValue');
};

/**
 * Highlights the next suggestion.
 */
Backdrop.jsAC.prototype.selectDown = function () {
  if (this.selected && this.selected.nextSibling) {
    this.highlight(this.selected.nextSibling);
  }
  else if (this.popup) {
    var lis = $('li', this.popup);
    if (lis.length > 0) {
      this.highlight(lis.get(0));
    }
  }
};

/**
 * Highlights the previous suggestion.
 */
Backdrop.jsAC.prototype.selectUp = function () {
  if (this.selected && this.selected.previousSibling) {
    this.highlight(this.selected.previousSibling);
  }
};

/**
 * Highlights a suggestion.
 */
Backdrop.jsAC.prototype.highlight = function (node) {
  // Unhighlights a suggestion for "keyup" and "keydown" events.
  if (this.selected !== false) {
    $(this.selected).removeClass('selected');
  }
  $(node).addClass('selected');
  this.selected = node;
  $(this.ariaLive).html($(this.selected).html());
};

/**
 * Unhighlights a suggestion.
 */
Backdrop.jsAC.prototype.unhighlight = function (node) {
  $(node).removeClass('selected');
  this.selected = false;
  $(this.ariaLive).empty();
};

/**
 * Hides the autocomplete suggestions.
 */
Backdrop.jsAC.prototype.hidePopup = function (keycode) {
  // Select item if the right key or mouse button was pressed.
  if (this.selected && ((keycode && keycode !== 46 && keycode !== 8 && keycode !== 27) || !keycode)) {
    this.input.value = $(this.selected).data('autocompleteValue');
  }
  // Hide popup.
  var popup = this.popup;
  if (popup) {
    this.popup = null;
    $(popup).fadeOut('fast', function () { $(popup).remove(); });
  }
  this.selected = false;
  $(this.ariaLive).empty();
};

/**
 * Positions the suggestions popup and starts a search.
 */
Backdrop.jsAC.prototype.populatePopup = function () {
  var $input = $(this.input);

  // Show popup.
  if (this.popup) {
    $(this.popup).remove();
  }
  this.selected = false;
  this.popup = $('<div id="autocomplete"></div>')[0];
  this.popup.owner = this;

  // Add the popup to the page and position.
  $("body").prepend(this.popup);
  var autocompleteInstance = this;
  positionPopup();
  Backdrop.optimizedResize.add(positionPopup, 'autocompletePopup');

  // Do search.
  this.db.owner = this;
  this.db.search(this.input.value);

  function positionPopup() {
    // If the popup has been removed, remove this resize handler.
    if (!autocompleteInstance.popup) {
      Backdrop.optimizedResize.remove('autocompletePopup');
      return;
    }

    var offset = $input.offset();
    var paddingLeft = parseInt($input.css('padding-left').replace('px', ''), 10);
    var paddingRight = parseInt($input.css('padding-right').replace('px', ''), 10);
    var paddingWidth = paddingLeft + paddingRight;

    // Position "absolute" instead of "fixed" for mobile Safari compatibility.
    // See https://github.com/backdrop/backdrop-issues/issues/6050
    $(autocompleteInstance.popup).css({
      top: ($input.outerHeight() + offset.top) + 'px',
      left: offset.left + 'px',
      width: ($input.width() + paddingWidth) + 'px',
      position: 'absolute'
    });
  }
};

/**
 * Fills the suggestion popup with any matches received.
 */
Backdrop.jsAC.prototype.found = function (matches) {
  // If no value in the textfield, do not show the popup.
  if (!this.input.value.length) {
    return false;
  }

  // Prepare matches.
  var ac = this;
  var ul = $('<ul></ul>')
    .on('mousedown', 'li', function (e) { ac.select(this); })
    .on('mouseover', 'li', function (e) { ac.highlight(this); })
    .on('mouseout', 'li', function (e) { ac.unhighlight(this); });
  for (var key in matches) {
    if (matches.hasOwnProperty(key)) {
      $('<li></li>')
        .html($('<div></div>').html(matches[key]))
        .data('autocompleteValue', key)
        .appendTo(ul);
    }
  }

  // Show popup with matches, if any.
  if (this.popup) {
    if (ul.children().length) {
      $(this.popup).empty().append(ul).show();
      $(this.ariaLive).html(Backdrop.t('Autocomplete popup'));
    }
    else {
      $(this.popup).css({ visibility: 'hidden' });
      this.hidePopup();
    }
  }
};

Backdrop.jsAC.prototype.setStatus = function (status) {
  switch (status) {
    case 'begin':
      $(this.input).addClass('throbbing');
      $(this.ariaLive).html(Backdrop.t('Searching for matches...'));
      break;
    case 'cancel':
    case 'error':
    case 'found':
      $(this.input).removeClass('throbbing');
      break;
  }
};

/**
 * An AutoComplete DataBase object.
 */
Backdrop.ACDB = function (uri) {
  this.uri = uri;
  this.delay = 300;
  this.cache = {};
};

/**
 * Performs a cached and delayed search.
 */
Backdrop.ACDB.prototype.search = function (searchString) {
  var db = this;
  this.searchString = searchString;

  // See if this string needs to be searched for anyway. The pattern ../ is
  // stripped since it may be misinterpreted by the browser.
  searchString = searchString.replace(/^\s+|\.{2,}\/|\s+$/g, '');
  // Skip empty search strings, or search strings ending with a comma, since
  // that is the separator between search terms.
  if (searchString.length <= 0 ||
    searchString.charAt(searchString.length - 1) === ',') {
    return;
  }

  // See if this key has been searched for before.
  if (this.cache[searchString]) {
    return this.owner.found(this.cache[searchString]);
  }

  // Initiate delayed search.
  if (this.timer) {
    clearTimeout(this.timer);
  }
  this.timer = setTimeout(function () {
    db.owner.setStatus('begin');

    // Ajax GET request for autocompletion.
    $.ajax({
      type: 'GET',
      url: Backdrop.sanitizeAjaxUrl(db.uri + '/' + encodeURIComponent(searchString)),
      dataType: 'json',
      jsonp: false,
      success: function (matches) {
        if (typeof matches.status === 'undefined' || matches.status !== 0) {
          db.cache[searchString] = matches;
          // Verify if these are still the matches the user wants to see.
          if (db.searchString === searchString) {
            db.owner.found(matches);
          }
          db.owner.setStatus('found');
        }
      },
      error: function (xmlhttp) {
        Backdrop.displayAjaxError(Backdrop.ajaxError(xmlhttp, db.uri));
      }
    });
  }, this.delay);
};

/**
 * Cancels the current autocomplete request.
 */
Backdrop.ACDB.prototype.cancel = function () {
  if (this.owner) {
    this.owner.setStatus('cancel');
  }
  if (this.timer) {
    clearTimeout(this.timer);
  }
  this.searchString = '';
};

})(jQuery);
;

(function ($) {

Backdrop.behaviors.nodeFieldsetSummaries = {
  attach: function (context) {
    $('fieldset.node-form-revision-information', context).backdropSetSummary(function (context) {
      var revisionCheckbox = $('.form-item-revision input', context);

      // Return 'New revision' if the 'Create new revision' checkbox is checked,
      // or if the checkbox doesn't exist, but the revision log does. For users
      // without the "Administer content" permission the checkbox won't appear,
      // but the revision log will if the content type is set to auto-revision.
      if (revisionCheckbox.is(':checked') || (!revisionCheckbox.length && $('.form-item-log textarea', context).length)) {
        return Backdrop.t('New revision');
      }

      return Backdrop.t('No revision');
    });

    $('fieldset.node-form-author', context).backdropSetSummary(function (context) {
      var name = $('.form-item-name input', context).val() || Backdrop.settings.anonymous;
      var dateParts = [];
      $('.form-item-date input', context).each(function() {
        var datePart = $(this).val();
        if (datePart) {
          dateParts.push(datePart);
        }
      });
      var date = dateParts.join(' ');
      return date ?
        Backdrop.t('By @name on @date', { '@name': name, '@date': date }) :
        Backdrop.t('By @name', { '@name': name });
    });

    $('fieldset.node-form-options', context).backdropSetSummary(function (context) {
      var vals = [];

      // Status radio button.
      var $status = $(context).find('input[name="status"]:checked');
      if ($status.val() == 2) {
        var dateParts = [];
        $('.form-item-scheduled input', context).each(function() {
          var datePart = $(this).val();
          if (datePart) {
            dateParts.push(datePart);
          }
        });
        var date = dateParts.join(' ');
        vals.push(Backdrop.t('Scheduled for @date', { '@date': date }));
      }
      else {
        var statusLabel = $status.parent().find('label').text().trim();
        vals.push(Backdrop.checkPlain(statusLabel));
      }

      // Other checkboxes like Promoted and Sticky.
      $(context).find('input:checked').not($status).parent().each(function () {
        vals.push(Backdrop.checkPlain($(this).text().trim()));
      });

      return vals.join(', ');
    });
  }
};

})(jQuery);
;
/**
 * @file
 * Attaches behaviors for the Path module.
 */
(function ($) {

"use strict";

Backdrop.behaviors.pathFieldsetSummaries = {
  attach: function (context) {
    $(context).find('fieldset.path-form').backdropSetSummary(function (element) {
      var $element = $(element);
      var path = $element.find('[name="path[alias]"]').val();
      var automatic = $element.find('[name="path[auto]"]').prop('checked');

      if (automatic) {
        return Backdrop.t('Automatic alias');
      }
      if (path) {
        return Backdrop.t('Alias: @alias', { '@alias': path });
      }
      else {
        return Backdrop.t('No alias');
      }
    });
  }
};

})(jQuery);
;
/**
 * @file
 * Attaches comment behaviors to the node form.
 */

(function ($) {

Backdrop.behaviors.commentFieldsetSummaries = {
  attach: function (context) {
    var $context = $(context);
    $context.find('fieldset.comment-node-settings-form').backdropSetSummary(function () {
      var vals = [];
      var status = $context.find('.form-item-comment input:checked').next('label').text().replace(/^\s+|\s+$/g, '');
      vals.push(Backdrop.checkPlain(status));
      if (status.trim() != 'Open') {
        if ($context.find(".form-item-comment-hidden input:checked").length) {
          vals.push(Backdrop.t('Hidden'));
        }
      }
      return Backdrop.checkPlain(vals.join(', '));
    });

    // Provide the summary for the node type form.
    $context.find('fieldset.comment-node-type-settings-form').backdropSetSummary(function() {
      var vals = [];

      // Default comment setting.
      vals.push($context.find(".form-item-comment-default input:checked").parent().find('label').text().replace(/^\s+|\s+$/g, ''));

      // Comments per page.
      var number = parseInt($context.find(".form-item-comment-per-page input").val());
      vals.push(Backdrop.t('@number comments per page', {'@number': number}));

      // Threading.
      if ($context.find(".form-item-comment-mode input:checked").length) {
        vals.push(Backdrop.t('Threaded'));
      }
      else {
        vals.push(Backdrop.t('Flat list'));
      }

      // Automatic comment closer setting.
      if ($context.find(".form-item-comment-close-enabled input:checked").length) {
        var number = parseInt($context.find(".form-item-comment-close-days input").val());
        vals.push(Backdrop.t('Automatically close comments after @number days', {'@number': number}));
      }

      return Backdrop.checkPlain(vals.join(', '));
    });
  }
};

})(jQuery);
;
