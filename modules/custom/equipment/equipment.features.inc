<?php
/**
 * @file
 * equipment.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function equipment_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function equipment_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function equipment_image_default_styles() {
  $styles = array();

  // Exported image style: equipment_thumbnail.
  $styles['equipment_thumbnail'] = array(
    'name' => 'equipment_thumbnail',
    'effects' => array(
      1 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '32',
          'height' => '32',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function equipment_node_info() {
  $items = array(
    'equipment' => array(
      'name' => t('Equipment'),
      'base' => 'node_content',
      'description' => t('A/V equipment is listed for the benefit of students and staff who might want to borrow it.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
