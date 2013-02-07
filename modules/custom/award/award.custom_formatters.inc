<?php
/**
 * @file
 * award.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function award_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'award_close_date';
  $formatter->label = 'award_close_date';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'datetime';
  $formatter->code = '$output = "";
foreach($variables[\'#items\'] as $item) {
	if(empty($item[\'value2\']))
	{
		$output = "";
	}
	else
	{
		$output = $item[\'value2\'];
	}
	
	break;
}

print $output;';
  $formatter->fapi = '';
  $export['award_close_date'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'award_open_date';
  $formatter->label = 'award_open_date';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'datetime';
  $formatter->code = '$output = "";
foreach($variables[\'#items\'] as $item) {
	if(empty($item[\'value\']))
	{
		$output = "";
	}
	else
	{
		$output = $item[\'value\'];
	}
	
	break;
}

print $output;';
  $formatter->fapi = '';
  $export['award_open_date'] = $formatter;

  return $export;
}
