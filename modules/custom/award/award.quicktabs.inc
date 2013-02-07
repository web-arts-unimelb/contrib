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
  $quicktabs->machine_name = 'grant_search';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Grant search';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'awards',
      'display' => 'block_3',
      'args' => '',
      'title' => 'Search',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'awards',
      'display' => 'block_2',
      'args' => '',
      'title' => 'Advanced Search',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'accordion';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array(
    'history' => 1,
    'jquery_ui' => array(
      'autoHeight' => 0,
      'collapsible' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Advanced Search');
  t('Grant search');
  t('Search');

  $export['grant_search'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'scholarship_search';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Scholarships';
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
  $quicktabs->renderer = 'accordion';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array(
    'history' => 1,
    'jquery_ui' => array(
      'autoHeight' => 0,
      'collapsible' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Advanced search');
  t('Scholarships');
  t('Search');

  $export['scholarship_search'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'scholarship_sub_search';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Scholarship search';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'awards',
      'display' => 'block_6',
      'args' => '',
      'title' => 'Search',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'awards',
      'display' => 'block_4',
      'args' => '',
      'title' => 'Advanced Search',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'accordion';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array(
    'history' => 1,
    'jquery_ui' => array(
      'autoHeight' => 0,
      'collapsible' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Advanced Search');
  t('Scholarship search');
  t('Search');

  $export['scholarship_sub_search'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'scholarships_prizes';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Prize search';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'awards',
      'display' => 'block_7',
      'args' => '',
      'title' => 'Search',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'awards',
      'display' => 'block_5',
      'args' => '',
      'title' => 'Advanced Search',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'accordion';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array(
    'history' => 1,
    'jquery_ui' => array(
      'autoHeight' => 0,
      'collapsible' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Advanced Search');
  t('Prize search');
  t('Search');

  $export['scholarships_prizes'] = $quicktabs;

  return $export;
}
