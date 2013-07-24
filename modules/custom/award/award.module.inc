<?php
/**
 * @file
 */

/**
 * Implements hook_form_alter()
 */
function award_form_alter(&$form, &$form_state, $form_id) {
  // The views blocks whose exposed forms need modification.
  $views = array('views-exposed-form-awards-block-2', 'views-exposed-form-awards-block-3', 'views-exposed-form-awards-block-5');
  
  if ($form_id == 'views_exposed_form' && !empty($form['#id']) && in_array($form['#id'], $views)) {
    // Make the select list of study areas a bit smaller.
    $form['field_award_study_area_tid']['#size'] = 4;
  }
  
  // Set default search term in award type filter
  if(isset($form['#id']))
  {
  	if($form['#id'] == 'views-exposed-form-awards-page-5') 
		{
			// Advance search scholarship
		
			// Reset if select Any in study area filter
			_reset_study_area_filter($form_state);
		
			// Set default award type search to scholarship
	 		if(empty($_GET['field_award_type_value_1']))
	 		{
				$form_state['input']['field_award_type_value_1'] = 'scholarship';
			}
	 	}
	 	else if($form['#id'] == 'views-exposed-form-awards-block-7')
	 	{
	 		// Normal prize search
	 		_correct_form_action_url($form);
		}
	 	else if($form['#id'] == 'views-exposed-form-awards-block-5') 
		{
			// Advance prize search
			_reset_study_area_filter($form_state);
		
			// Set default award type search to prize
	 		if(empty($_GET['field_award_type_value_1']))
	 		{
				$form_state['input']['field_award_type_value_1'] = 'prize';
			}
			
			_correct_form_action_url($form);
	 	}
		else if($form['#id'] == 'views-exposed-form-awards-block-2') 
		{
			// Advance grant search
		
			_reset_study_area_filter($form_state);
		
			// Set default award type search to grant
	 		if(empty($_GET['field_award_type_value_1']))
	 		{
				$form_state['input']['field_award_type_value_1'] = 'grant';
			}
	 	}
 	}
 	
}

/**
 * Implements hook_views_pre_render().
 */
function award_views_pre_render(&$view) {
  $select_all = 'select all';
  $select_all_display = t('Any');

  if($view->name == "awards") {
    $results = &$view->result;

    foreach($results as $key => $result) {
      foreach($results[$key]->field_field_award_study_area as $item) {
        if( strtolower($item['rendered']['#markup']) == $select_all ) {
          $results[$key]->field_field_award_study_area = array(
            0 => array(
              'rendered' => array(
                '#markup' => $select_all_display
              ),
            ),
          );
        }
      }
    }
  }
}

function unimelb_preprocess_views_exposed_form(&$vars, $hook) 
{
	if(
		$vars['form']['#id'] == 'views-exposed-form-awards-page-5' or
		$vars['form']['#id'] == 'views-exposed-form-awards-block-5' or
		$vars['form']['#id'] == 'views-exposed-form-awards-block-2'
	) 
	{
		foreach($vars['widgets'] as $id => &$widget) 
		{
  		switch ($id) 
  		{
        case 'filter-field_award_study_area_tid':
     			$widget->widget = _build_taxonomy_dropdown($widget->widget);
          break;

      }
  	}
	}
}

function _build_taxonomy_dropdown($input)
{
	$html = "";
	$option_html = _build_dropdown_option($input);

	// NOTE: Hard code
	$html = '
		<div class="form-item form-type-select form-item-field-award-study-area-tid">
			<select multiple="multiple" name="field_award_study_area_tid[]" id="edit-field-award-study-area-tid" size="9" class="form-select">
	';	
	
	$html .= $option_html;	
		
	$html .= '
			</select>
		</div>	
	';

	return $html;
}

function _build_dropdown_option($input)
{
	$option_html = "<option value='All'>- Any -</option>";
	//$option_html = "";
	
	$is_select_all_condi = true;
	
	$doc = new DOMDocument();
	$doc->loadHTML($input);

	$xpath = new DOMXpath($doc);
	$options = $xpath->query("*/div/select/option");

	$has_any_child_condi = _does_it_has_any_child($options);

	foreach($options as $option) 
	{
  	$option_value = $option->getAttribute('value');
  	$option_content = $option->nodeValue;
  
  	if( $is_select_all_condi && _is_select_all($option_content) )
  	{
  		// Skip to generate the option tag
  		$is_select_all_condi = false;
  	}
  	elseif(empty($option_content))
  	{
  		// Skip if node value is empty
  	}
		elseif(!$has_any_child_condi)
    {
      // Has no child at all
      $option_html .= "<option value=\"$option_value\">$option_content</option>";
    }
		elseif( _is_child($option_content) )
		{
			$option_html .= "<option value=\"$option_value\">&nbsp;&nbsp;$option_content</option>";
		}
		else
		{
			$option_html .= "<option style=\"font-weight: bold\" value=\"$option_value\">$option_content</option>";	
		}
	}
	
	return $option_html;
}

function _is_select_all($value = "")
{
	if(strtolower($value) == "select all")
	{
		return true;
	}
	else
	{
		return false;
	}
}

function _is_child($value = "")
{
	if($value[0] == "-")
	{
		return true;
	}
	else
	{
		return false;
	}
}

function _does_it_has_any_child($options = null) {
  $counter = 0;
  foreach($options as $option) {
    $option_content = $option->nodeValue;
    if(_is_child($option_content)) {
      ++$counter;
    }
  }

  if($counter > 0)
    return true;
  else
    return false;
}

function _reset_study_area_filter(&$form_state)
{
	if(isset($form_state['input']['field_award_study_area_tid'][0]))
	{
		if($form_state['input']['field_award_study_area_tid'][0] == 'All')
		{
			$form_state['input']['field_award_study_area_tid'] = array();
		}
	}
}

// Not the exact issue, but with the idea
// http://drupal.org/node/1783968
function _correct_form_action_url(&$form)
{
	if($form['#action'] == "/scholarships/grants-list")
	{
		$form['#action'] = "/scholarships/prize-list";	
	}
}
