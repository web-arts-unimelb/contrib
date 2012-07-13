/* Local JavaScript additions. */
(function ($) {
	Drupal.behaviors.unimelb = {
    		attach: function(context, settings) {

			$('ul.jquerymenu-processed li.parent span.closed').attr('title', 'Expand this menu item');
      			$('ul.jquerymenu-processed li.parent span.open').attr('title', 'Collapse this menu item');

      			$('ul.jquerymenu-processed li.parent span').bind('click', function() {
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


