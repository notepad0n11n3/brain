(function ($) {

"use strict";

  /**
 * Attaches menu styles to menu blocks. Currently only the "dropdown" style.
 */
Backdrop.behaviors.menuStyles = {
  attach: function(context, settings) {
    var $menus = $(context).find('[data-menu-style]').once('menu-style');
    $menus.each(function() {
      var element = this;
      var $menu = $(element);
      var style = $menu.data('menuStyle');
      var menuSettings = $menu.data('menuSettings');
      if ($menu.data('clickdown')) {
        menuSettings = $.extend(menuSettings, {
          noMouseOver: true
        });
      }
      menuSettings = $.extend(menuSettings, {
        collapsibleBehavior: ($menu.data('collapse')) ? ($menu.data('collapse')) : 'default'
      });
      if (Backdrop.menuStyles[style]) {
        Backdrop.menuStyles[style].attach(element, menuSettings);
      }
    });
  },
  detach: function(context, settings) {
    var $menus = $(context).find('[data-menu-style]').once('menu-style');
    $menus.each(function() {
      var element = this;
      var $menu = $(element);
      var style = $menu.data('menuStyle');
      var menuSettings = $menu.data('menuSettings');
      if (Backdrop.menuStyles[style] && Backdrop.menuStyles[style].detach) {
        Backdrop.menuStyles[style].detach(element, menuSettings);
      }
    });
  }
};

Backdrop.menuStyles = {};
Backdrop.menuStyles.dropdown = {
  attach: function(element, settings) {
    // Set defaults for the settings.
    settings = $.extend(settings, {
      subIndicatorsPos: 'append',
      subIndicatorsText: ''
    });
    $(element).addClass('sm').smartmenus(settings);
  }
};

/**
 * Adds a collapsible "hamburger" button to toggle links if enabled on a menu.
 */
Backdrop.behaviors.menuToggles = {
  attach: function(context, settings) {
    var $menus = $(context).find('[data-menu-toggle-id]').once('menu-toggles');
    $menus.each(function() {
      var element = this;
      var $menu = $(element);
      var id = $menu.data('menuToggleId');
      var $menuToggleState = $('#' + id);
      $menuToggleState.on('change', function(e) {
        // Animate mobile menu.
        if (this.checked) {
          $menu.hide().slideDown(250, function() { $menu.css('display', ''); });
        } else {
          $menu.show().slideUp(250, function() { $menu.css('display', ''); });
        }
      });
      // Hide mobile menu beforeunload.
      $(window).on('beforeunload unload', function() {
        if ($menuToggleState[0].checked) {
          $menuToggleState[0].click();
        }
      });
    });
  }
};

})(jQuery);
;
(function ($) {

"use strict";

/**
 * Add buttons to messages to allow users to dismiss them.
 */
Backdrop.behaviors.dismiss = {
  attach: function (context, settings) {

    $('.messages a.dismiss').on('click', function(event) {
      event.preventDefault();

      $(this).parent().fadeOut('fast', function() {
        if ($('.l-messages').children(':visible').length == 0) {
          $('.l-messages').hide();
        }
      });
    });

  }
};

})(jQuery);
;
