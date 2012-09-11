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

			/* Start academic staff category */
			__handle_academic_category();
			/* End academic staff category */

			/* Start fix style issues */
			__adjust_uploader();
			__adjust_group();
			__adjust_ungroup();
			/* End fix style issues */

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


function __handle_academic_category()
{
	// Academic staff category
	var academic_staff_category_tag = "#edit-field-academic-staff-type-und";
	var academic_staff_category_value = "18";

	// Academic administor input
	var academic_administrator_role_session = "#edit-field-academic-admin-role"; // The wrapper for the input
	var academic_administrator_role_tag = "#edit-field-academic-admin-role-und-0-value";

	// Initial 
	if($(academic_staff_category_tag).val() == academic_staff_category_value)		
	{
		$(academic_administrator_role_session).show();
		$(academic_administrator_role_tag).removeAttr('disabled');
	}
	else
	{
		$(academic_administrator_role_session).hide();
		$(academic_administrator_role_tag).attr("disabled", "disabled");
		$(academic_administrator_role_tag).attr("value", "");
	}

	// Listen
	$(academic_staff_category_tag).change(function(){
		// If "academic administrator" is selected in "Academic staff category"				
		if($(academic_staff_category_tag).val() == academic_staff_category_value)
		{
			$(academic_administrator_role_session).show();
			$(academic_administrator_role_tag).removeAttr('disabled');
		}
		else
		{
			$(academic_administrator_role_session).hide();
			$(academic_administrator_role_tag).attr("disabled", "disabled");
			$(academic_administrator_role_tag).attr("value", "");
		}
	});
}


