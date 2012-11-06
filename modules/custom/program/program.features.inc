<?php
/**
 * @file
 * program.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function program_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function program_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function program_node_info() {
  $items = array(
    'program' => array(
      'name' => t('Program'),
      'base' => 'node_content',
      'description' => t('Add a <em>program</em> to expand the list of course and career information available to prospective students. Programs contain speciality and fee information, as well as course outcomes.'),
      'has_title' => '1',
      'title_label' => t('Program Name'),
      'help' => '',
    ),
  );
  return $items;
}
