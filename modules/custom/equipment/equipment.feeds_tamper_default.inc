<?php
/**
 * @file
 * equipment.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function equipment_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'equipment_xml_importer-xpathparser_1-explode';
  $feeds_tamper->importer = 'equipment_xml_importer';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['equipment_xml_importer-xpathparser_1-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'equipment_xml_importer-xpathparser_3-url_absolutify';
  $feeds_tamper->importer = 'equipment_xml_importer';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'url_absolutify';
  $feeds_tamper->settings = array(
    'origin' => '',
    'global' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Absolutify URL';
  $export['equipment_xml_importer-xpathparser_3-url_absolutify'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'equipment_xml_importer-xpathparser_7-explode';
  $feeds_tamper->importer = 'equipment_xml_importer';
  $feeds_tamper->source = 'xpathparser:7';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['equipment_xml_importer-xpathparser_7-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'equipment_xml_importer-xpathparser_8-explode';
  $feeds_tamper->importer = 'equipment_xml_importer';
  $feeds_tamper->source = 'xpathparser:8';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['equipment_xml_importer-xpathparser_8-explode'] = $feeds_tamper;

  return $export;
}
