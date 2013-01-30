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
	if($vars['form']['#id'] == 'views-exposed-form-awards-page-5') 
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
	$option_html = "";
	
	$is_select_all_condi = true;
	
	$doc = new DOMDocument();
	$doc->loadHTML($input);

	$xpath = new DOMXpath($doc);
	$options = $xpath->query("*/div/select/option");

	foreach($options as $option) 
	{
  	$option_value = $option->getAttribute('value');
  	$option_content = $option->nodeValue;
  
  	if( $is_select_all_condi && _is_select_all($option_content) )
  	{
  		$is_select_all_condi = false;
  		// Skip to generate the option tag
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
