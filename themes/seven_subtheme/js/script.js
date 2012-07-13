/* Local JavaScript additions. */
(function ($) 
{
	Drupal.behaviors.unimelb = 
	{
    	attach: function(context, settings)
		{

			// Wait for it until the dom is ready
			$(document).ready(function(){
				// Start --------------------------------------------------- Academic staff checkbox
				var input_tag = "#edit-roles-6";

				// Academic staff fields
				var academic_staff_fields = [
					"edit-field-academic-staff-type",	
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
				if( $(input_tag).is(':checked') )
				{
				    // Is the checkbox been checked, when it is loaded, but show no check?
				    jQuery.each(academic_staff_fields, function(index, value){
				            $("#" + this).show();
				    });
				}
				else
				{
					jQuery.each(academic_staff_fields, function(index, value){
						    $("#" + this).hide();
					});
				}


				// Listen to academic staff checkbox
				$(input_tag).change(function(){
				    if(this.checked)
				    {
				        jQuery.each(academic_staff_fields, function(index, value){
				                $("#" + this).show();
				        });
				    }
				    else
				    {
				        jQuery.each(academic_staff_fields, function(index, value){
				                $("#" + this).hide();
				        });
				    }
				});
				// End --------------------------------------------------- Academic staff checkbox


				// Start --------------------------------------------------- Professional staff checkbox
				var input_tag_1 = "#edit-roles-7";

				// Professional staff fields
				var professional_staff_fields = [
				        "edit-field-responsibilities"
				];

				// Initial page loads
				if( $(input_tag_1).is(':checked') )
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
				$(input_tag_1).change(function(){
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
	}
})(jQuery);

