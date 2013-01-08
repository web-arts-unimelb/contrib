<?php
/**
 * @file
 * award.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function award_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
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
function award_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function award_node_info() {
  $items = array(
    'award' => array(
      'name' => t('Award'),
      'base' => 'node_content',
      'description' => t('An award stores scholarship information.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
