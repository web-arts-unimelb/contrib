<?php
/**
 * @file
 * award.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function award_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'scholarship_search';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Scholarship search';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'awards',
      'display' => 'page_4',
      'args' => '',
      'title' => 'Search',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'awards',
      'display' => 'page_5',
      'args' => '',
      'title' => 'Advanced search',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Advanced search');
  t('Scholarship search');
  t('Search');

  $export['scholarship_search'] = $quicktabs;

  return $export;
}
