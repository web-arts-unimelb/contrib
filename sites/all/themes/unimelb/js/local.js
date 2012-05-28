/* Local JavaScript additions. */
(function ($) {
  Drupal.behaviors.unimelb = {
    attach: function(context, settings) {

      $('ul.jquerymenu-processed li.parent.closed').attr('title', 'Expand this menu item');
      $('ul.jquerymenu-processed li.parent.open').attr('title', 'Collapse this menu item');

      $('ul.jquerymenu-processed li.parent').bind('click', function() {
        if ($(this).is('.open')) {
          $(this).attr('title', 'Collapse this menu item');
        }
        else {
          $(this).attr('title', 'Expand this menu item');
        }
      });
    }
  }
})(jQuery);
