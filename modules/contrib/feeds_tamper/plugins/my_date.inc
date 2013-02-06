<?php

$plugin = array(
  'form' => 'my_date_form',
  // Optional validation callback.
  'validate' => 'my_date_validate',
  'callback' => 'my_date_callback',
  'name' => 'My date',
  'multi' => 'skip',
  'category' => 'Other',
);

function my_date_form($importer, $element_key, $settings) {
  $form = array();
  
  $form['separator'] = array(
    '#type' => 'textfield',
    '#title' => t('String separator'),
    '#required' => TRUE,	
    '#default_value' => isset($settings['separator']) ? $settings['separator'] : 'to',
    '#description' => t('separator'),
  );
  
  $form['part'] = array(
    '#type' => 'select',
    '#title' => t('Which part you want'),
    '#description' => t('Which part you want? Open date or close date.'),
    '#required' => TRUE,
    '#options' => array(
      'open date' =>  'open date',
      'close date' => 'close date',
    ),
    '#default_value' => isset($settings['part']) ? $settings['part'] : 'open date',
  );
  
  return $form;
}

function my_date_validate(&$settings) {
  // Validate $settings.
}

function my_date_callback($source, $item_key, $element_key, &$field, $settings) {
	// e.g. $field == 2013-01-21 00:00:00 to 2013-03-25 00:00:00
	
	if(!empty($field))
	{
		$array = explode($settings['separator'], $field);
		if(is_array($array) && count($array) == 2)
		{
			if($settings['part'] == 'open date')
			{
				$field = trim($array[0]);
			}
			elseif($settings['part'] == 'close date')
			{
				$field = trim($array[1]);
			}
		}
	}
	else
	{
	
	}
}
?>
