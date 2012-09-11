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
			__adjust_uploader();
			
			__adjust_group();
			__adjust_ungroup()
			/* End academic self profile editing */

		}
		
	}
})(jQuery);


// Define your functions here
function __adjust_uploader()
{
	/* Account document uploader */
	var tag_name = "fieldset#edit-field-account-document-und";
	__adjust_uploader_style(tag_name);			

	/* Account document uploader */
	var tag_name = "fieldset#edit-field-account-image-und"; 
	__adjust_uploader_style(tag_name);
}

function __adjust_group()
{
	var tag_name = "fieldset.group-research-interest";
	__adjust_group_style(tag_name);

	var tag_name = "fieldset.group-biography";
	__adjust_group_style(tag_name);

	var tag_name = "fieldset.group-research-projects";
	__adjust_group_style(tag_name);

	var tag_name = "fieldset.group-publications";
	__adjust_group_style(tag_name);

	var tag_name = "fieldset.group-teaching";
	__adjust_group_style(tag_name);

	var tag_name = "fieldset.group-awards-and-grants";
	__adjust_group_style(tag_name);

	var tag_name = "fieldset.group-presentations";
	__adjust_group_style(tag_name);

	var tag_name = "fieldset.group-bibliography";
	__adjust_group_style(tag_name);
}

function __adjust_ungroup()
{
	var tag_name = "div#edit-field-qualifications";
	__adjust_ungroup_style(tag_name);

	var tag_name = "div#edit-field-other-information";
	__adjust_ungroup_style(tag_name);
}


function __adjust_uploader_style(tag_name)
{
	$(tag_name).css("background", "#ffffff");
	$(tag_name).css("border", "0px");
	$(tag_name).removeClass("collapsible");

}

function __adjust_group_style(tag_name)
{
	var width = "650px";
	
	$(tag_name).width(width);
	$(tag_name).removeClass("collapsible");
	$(tag_name).removeClass("collapsed");
	
	$(tag_name).css("background", "#ffffff");	
	$(tag_name).css("border", "0px");	
	$(tag_name).css("margin-bottom", "-10px");
}

function __adjust_ungroup_style(tag_name)
{
	var width = "650px";
	
	$(tag_name).width(width);
	$(tag_name).css("padding-top", "10px");
}
