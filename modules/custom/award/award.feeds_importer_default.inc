<?php
/**
 * @file
 * award.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function award_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'award_xml_importer';
  $feeds_importer->config = array(
    'name' => 'Award XML Importer',
    'description' => 'Imports Awards from XML feeds into the site.',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'Uuid',
          'xpathparser:1' => 'Name',
          'xpathparser:2' => 'Process',
          'xpathparser:3' => 'Background',
          'xpathparser:4' => 'Students',
          'xpathparser:5' => 'StudyLevel',
          'xpathparser:6' => 'YearLevel',
          'xpathparser:8' => 'TravelSupport',
          'xpathparser:9' => 'Citizenship',
          'xpathparser:10' => 'FinancialNeed',
          'xpathparser:11' => 'Other',
          'xpathparser:12' => 'Conditions',
          'xpathparser:13' => 'ApplicationProcess',
          'xpathparser:14' => 'Submissions',
          'xpathparser:15' => 'OpenDate',
          'xpathparser:16' => 'ClosingDate',
          'xpathparser:17' => 'Term',
          'xpathparser:18' => 'Frequency',
          'xpathparser:19' => 'UniversityTrustRecord',
          'xpathparser:20' => 'EnquireNow',
          'xpathparser:21' => 'ResearchArea',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
          'xpathparser:13' => 0,
          'xpathparser:14' => 0,
          'xpathparser:15' => 0,
          'xpathparser:16' => 0,
          'xpathparser:17' => 0,
          'xpathparser:18' => 0,
          'xpathparser:19' => 0,
          'xpathparser:20' => 0,
          'xpathparser:21' => 0,
        ),
        'context' => '//node',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
            'xpathparser:13' => 0,
            'xpathparser:14' => 0,
            'xpathparser:15' => 0,
            'xpathparser:16' => 0,
            'xpathparser:17' => 0,
            'xpathparser:18' => 0,
            'xpathparser:19' => 0,
            'xpathparser:20' => 0,
            'xpathparser:21' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'award',
        'expire' => '-1',
        'author' => '2',
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'title',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_award_process',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'body',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_award_students',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_award_study_level',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_award_year_level',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_award_travel_support',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_award_citizenship',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_award_financial_need',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_award_other',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_award_conditions',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_award_application_process',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'xpathparser:14',
            'target' => 'field_award_submissions:url',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'xpathparser:15',
            'target' => 'field_award_application_date:start',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'xpathparser:16',
            'target' => 'field_award_application_date:end',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'xpathparser:17',
            'target' => 'field_award_term',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'xpathparser:18',
            'target' => 'field_award_frequency',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'xpathparser:19',
            'target' => 'field_award_uni_trust_record:url',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'xpathparser:20',
            'target' => 'field_award_enquire_now',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'xpathparser:21',
            'target' => 'field_award_research_area',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['award_xml_importer'] = $feeds_importer;

  return $export;
}
