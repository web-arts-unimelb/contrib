<?php

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
