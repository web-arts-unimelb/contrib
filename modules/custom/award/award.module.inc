<?php
/**
 * @file
 */

/**
 * Implements hook_form_alter()
 */
function award_form_alter(&$form, $form_state, $form_id) {
  // The views blocks whose exposed forms need modification.
  $views = array('views-exposed-form-awards-block-2', 'views-exposed-form-awards-block-3', 'views-exposed-form-awards-block-5');
  if ($form_id == 'views_exposed_form' && !empty($form['#id']) && in_array($form['#id'], $views)) {
    // Make the select list of study areas a bit smaller.
    $form['field_award_study_area_tid']['#size'] = 4;
  }
}

/**
 * Implements hook_views_pre_render().
 */
function award_views_pre_render(&$view) 
{
	$select_all = "select all";
	$select_all_display = "Any";

	if(isset($view->name))
	{
		if($view->name == "awards")
		{
			$results = &$view->result;
			
			foreach($results as $key => $result) 
			{
				foreach($results[$key]->field_field_award_study_area as $item)
				{
					if( strtolower($item['rendered']['#markup']) == $select_all )
					{
						$results[$key]->field_field_award_study_area = 
							array(
								0 => array(
									'rendered' => 
										array(
											'#markup' => $select_all_display
									) 
								)
							);
					}
					else
					{
					
					}
				}
			}
		}
	}
		
}
