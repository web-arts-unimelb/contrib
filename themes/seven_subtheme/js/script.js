/* Local JavaScript additions. */
(function ($) 
{
	Drupal.behaviors.unimelb = 
	{
    	attach: function(context, settings)
		{
			// Start ----------------------------------------------------- for language and linguistic only
			// Wait for it until the dom is ready
			$(document).ready(function(){
				// Start --------------------------------------------------- Academic staff checkbox
				var role_tag = "#edit-roles-6";

				// Academic staff type				
				var academic_staff_category_tag = "#edit-field-academic-staff-type-und";
				var academic_staff_category_value = "18";

				// Academic administor
				var academic_administrator_role_session = "#edit-field-academic-admin-role";
				var academic_administrator_role_tag = "#edit-field-academic-admin-role-und-0-value";

				// Academic staff fields
				var academic_staff_sessions = [
					"edit-field-academic-staff-type", // academic staff category session					
					"edit-field-profile-image",
					"edit-field-account-document",
					"edit-field-account-image",
				
					"edit-field-discipline",
					"edit-field-qualifications",

					"user_user_form_group_research_interest",
					"user_user_form_group_biography",
					"user_user_form_group_research_projects",
					"user_user_form_group_publications",

					"user_user_form_group_awards_and_grants",
					"user_user_form_group_teaching",
					"user_user_form_group_presentations",
					"user_user_form_group_bibliography"
				];

				// Initial page loads
				if( $(role_tag).is(':checked') )
				{
				    // Is the checkbox been checked, when it is loaded, but show no check?
				    jQuery.each(academic_staff_sessions, function(index, value){
				    	$("#" + this).show();
				    });

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
				}
				else
				{
					jQuery.each(academic_staff_sessions, function(index, value){
						$("#" + this).hide();
					});

					// Hide
					$(academic_administrator_role_session).hide();
					$(academic_administrator_role_tag).attr("value", "");
				}


				// Listen to academic staff checkbox
				$(role_tag).change(function(){
				    if(this.checked)
				    {
				        jQuery.each(academic_staff_sessions, function(index, value){
				        	$("#" + this).show();
				        });
					
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
				    }
				    else
				    {
				        jQuery.each(academic_staff_sessions, function(index, value){
				                $("#" + this).hide();
				        });
		
						// Hide
						$(academic_administrator_role_session).hide();
						$(academic_administrator_role_tag).attr("disabled", "disabled");
						$(academic_administrator_role_tag).attr("value", "");
				    }
				});

				
				// Listen to academic staff category dropdown				
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

				// End --------------------------------------------------- Academic staff checkbox


				// Start --------------------------------------------------- Professional staff checkbox
				var role_tag_1 = "#edit-roles-7";

				// Professional staff fields
				var professional_staff_fields = [
				        "edit-field-responsibilities"
				];

				// Initial page loads
				if( $(role_tag_1).is(':checked') )
				{
					// Is the checkbox been checked, when it is loaded, but show no check?
					jQuery.each(professional_staff_fields, function(index, value){
							$("#" + this).show();
					});
				}
				else
				{
				    jQuery.each(professional_staff_fields, function(index, value){
				            $("#" + this).hide();
				    });
				}


				// Listen to professional staff checkbox
				$(role_tag_1).change(function(){
					if(this.checked)
					{
					    jQuery.each(professional_staff_fields, function(index, value){
					            $("#" + this).show();
					    });
					}
					else
					{
					    jQuery.each(professional_staff_fields, function(index, value){
					            $("#" + this).hide();
						});
					}
			   });
			   // End --------------------------------------------------- Academic staff checkbox
			});
		}
		// End ----------------------------------------------------- for language and linguistic only
	}
})(jQuery);

