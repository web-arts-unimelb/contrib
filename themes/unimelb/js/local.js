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

			/* Start academic self profile editing */
			
			/* Start account document uploader */
			var tag_name = "fieldset#edit-field-account-document-und";
			__adjust_uploader_style(tag_name);			
			/* End account document uploader */

			/* Start account document uploader */
			var tag_name = "fieldset#edit-field-account-image-und"; 
			__adjust_uploader_style(tag_name);
			/* End account document uploader */			

			/* End academic self profile editing */
		}
		
	}
})(jQuery);


function __adjust_uploader_style(tag_name)
{
	$(tag_name).css("background", "#ffffff");
	$(tag_name).css("border", "0px");
	$(tag_name).removeClass("collapsible");

}
