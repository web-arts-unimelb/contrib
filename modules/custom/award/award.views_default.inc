<?php
/**
 * @file
 * award.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function award_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'awards';
  $view->description = 'Provide lists of awards and scholarships.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Awards';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_award_study_area' => 'field_award_study_area',
    'field_award_citizenship' => 'field_award_citizenship',
    'field_award_financial_need' => 'field_award_financial_need',
    'field_award_other' => 'field_award_other',
    'field_award_students' => 'field_award_students',
    'field_award_study_level' => 'field_award_study_level',
    'field_award_travel_support' => 'field_award_travel_support',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_award_study_area' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_award_citizenship' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_award_financial_need' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_award_other' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_award_students' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_award_study_level' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_award_travel_support' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Entity: Rendered entity */
  $handler->display->display_options['header']['entity']['id'] = 'entity';
  $handler->display->display_options['header']['entity']['table'] = 'entity__global';
  $handler->display->display_options['header']['entity']['field'] = 'entity';
  $handler->display->display_options['header']['entity']['entity_id'] = '317';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Prize';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Area of study */
  $handler->display->display_options['fields']['field_award_study_area']['id'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['table'] = 'field_data_field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['field'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['label'] = 'Areas of study';
  $handler->display->display_options['fields']['field_award_study_area']['empty'] = '<ul><li class="first last">All</li></ul>';
  $handler->display->display_options['fields']['field_award_study_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_award_study_area']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_award_study_area']['multi_type'] = 'ul';
  /* Field: Content: Citizenship */
  $handler->display->display_options['fields']['field_award_citizenship']['id'] = 'field_award_citizenship';
  $handler->display->display_options['fields']['field_award_citizenship']['table'] = 'field_data_field_award_citizenship';
  $handler->display->display_options['fields']['field_award_citizenship']['field'] = 'field_award_citizenship';
  $handler->display->display_options['fields']['field_award_citizenship']['label'] = '';
  $handler->display->display_options['fields']['field_award_citizenship']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_citizenship']['alter']['text'] = 'Citizenship requirement: [field_award_citizenship]<br />';
  $handler->display->display_options['fields']['field_award_citizenship']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_award_citizenship']['empty'] = 'None';
  $handler->display->display_options['fields']['field_award_citizenship']['delta_offset'] = '0';
  /* Field: Content: Financial need */
  $handler->display->display_options['fields']['field_award_financial_need']['id'] = 'field_award_financial_need';
  $handler->display->display_options['fields']['field_award_financial_need']['table'] = 'field_data_field_award_financial_need';
  $handler->display->display_options['fields']['field_award_financial_need']['field'] = 'field_award_financial_need';
  $handler->display->display_options['fields']['field_award_financial_need']['label'] = '';
  $handler->display->display_options['fields']['field_award_financial_need']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_financial_need']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_financial_need']['alter']['text'] = '<b>Financial need:</b> [field_award_financial_need]<br />';
  $handler->display->display_options['fields']['field_award_financial_need']['element_label_colon'] = FALSE;
  /* Field: Content: Other */
  $handler->display->display_options['fields']['field_award_other']['id'] = 'field_award_other';
  $handler->display->display_options['fields']['field_award_other']['table'] = 'field_data_field_award_other';
  $handler->display->display_options['fields']['field_award_other']['field'] = 'field_award_other';
  $handler->display->display_options['fields']['field_award_other']['label'] = '';
  $handler->display->display_options['fields']['field_award_other']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_other']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_award_other']['element_label_colon'] = FALSE;
  /* Field: Content: Students */
  $handler->display->display_options['fields']['field_award_students']['id'] = 'field_award_students';
  $handler->display->display_options['fields']['field_award_students']['table'] = 'field_data_field_award_students';
  $handler->display->display_options['fields']['field_award_students']['field'] = 'field_award_students';
  $handler->display->display_options['fields']['field_award_students']['label'] = '';
  $handler->display->display_options['fields']['field_award_students']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_students']['alter']['text'] = '<b>Available to:</b> [field_award_students]<br />';
  $handler->display->display_options['fields']['field_award_students']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_award_students']['empty'] = 'All students';
  $handler->display->display_options['fields']['field_award_students']['delta_offset'] = '0';
  /* Field: Content: Study level */
  $handler->display->display_options['fields']['field_award_study_level']['id'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['table'] = 'field_data_field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['field'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['label'] = '';
  $handler->display->display_options['fields']['field_award_study_level']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['alter']['text'] = '[field_award_study_level]';
  $handler->display->display_options['fields']['field_award_study_level']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_award_study_level']['empty'] = 'All';
  $handler->display->display_options['fields']['field_award_study_level']['delta_offset'] = '0';
  /* Field: Content: Travel support */
  $handler->display->display_options['fields']['field_award_travel_support']['id'] = 'field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['table'] = 'field_data_field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['field'] = 'field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['label'] = '';
  $handler->display->display_options['fields']['field_award_travel_support']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_travel_support']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_travel_support']['alter']['text'] = '<b>Travel support:</b> [field_award_travel_support]<br />';
  $handler->display->display_options['fields']['field_award_travel_support']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Eligibility';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<b>Available to:</b> [field_award_students]<br />
<b>Study level:</b> [field_award_study_level]<br />
[field_award_travel_support]
<b>Citizenship requirements:</b> [field_award_citizenship]<br />
[field_award_financial_need]
[field_award_other]
';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'award' => 'award',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Award type (field_award_type) */
  $handler->display->display_options['filters']['field_award_type_value']['id'] = 'field_award_type_value';
  $handler->display->display_options['filters']['field_award_type_value']['table'] = 'field_data_field_award_type';
  $handler->display->display_options['filters']['field_award_type_value']['field'] = 'field_award_type_value';
  $handler->display->display_options['filters']['field_award_type_value']['value'] = array(
    'prize' => 'prize',
  );
  $handler->display->display_options['filters']['field_award_type_value']['group'] = 1;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['keys']['expose']['description'] = 'Enter one or more keywords to search for';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Area of study (field_award_study_area) */
  $handler->display->display_options['filters']['field_award_study_area_tid']['id'] = 'field_award_study_area_tid';
  $handler->display->display_options['filters']['field_award_study_area_tid']['table'] = 'field_data_field_award_study_area';
  $handler->display->display_options['filters']['field_award_study_area_tid']['field'] = 'field_award_study_area_tid';
  $handler->display->display_options['filters']['field_award_study_area_tid']['value'] = array(
    1 => '1',
    2 => '2',
    3 => '3',
    4 => '4',
    12 => '12',
    5 => '5',
    7 => '7',
    16 => '16',
    17 => '17',
    20 => '20',
    18 => '18',
    19 => '19',
    29 => '29',
    77 => '77',
    27 => '27',
    28 => '28',
    21 => '21',
    53 => '53',
    81 => '81',
    82 => '82',
    54 => '54',
    55 => '55',
    56 => '56',
    83 => '83',
    79 => '79',
    80 => '80',
    86 => '86',
    30 => '30',
    31 => '31',
    34 => '34',
    43 => '43',
    44 => '44',
    71 => '71',
    33 => '33',
    66 => '66',
    67 => '67',
    70 => '70',
    76 => '76',
    75 => '75',
    78 => '78',
    84 => '84',
  );
  $handler->display->display_options['filters']['field_award_study_area_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_award_study_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['operator_id'] = 'field_award_study_area_tid_op';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['label'] = 'Area of study';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['operator'] = 'field_award_study_area_tid_op';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['identifier'] = 'field_award_study_area_tid';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_award_study_area_tid']['vocabulary'] = 'study_area';
  $handler->display->display_options['filters']['field_award_study_area_tid']['hierarchy'] = 1;

  /* Display: Page: Grants */
  $handler = $view->new_display('page', 'Page: Grants', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Grants';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '100',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Grant';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Area of study */
  $handler->display->display_options['fields']['field_award_study_area']['id'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['table'] = 'field_data_field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['field'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['label'] = 'Areas of study';
  $handler->display->display_options['fields']['field_award_study_area']['empty'] = '<ul><li class="first last">All</li></ul>';
  $handler->display->display_options['fields']['field_award_study_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_award_study_area']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_award_study_area']['multi_type'] = 'ul';
  /* Field: Content: Citizenship */
  $handler->display->display_options['fields']['field_award_citizenship']['id'] = 'field_award_citizenship';
  $handler->display->display_options['fields']['field_award_citizenship']['table'] = 'field_data_field_award_citizenship';
  $handler->display->display_options['fields']['field_award_citizenship']['field'] = 'field_award_citizenship';
  $handler->display->display_options['fields']['field_award_citizenship']['label'] = '';
  $handler->display->display_options['fields']['field_award_citizenship']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_citizenship']['alter']['text'] = 'Citizenship requirement: [field_award_citizenship]<br />';
  $handler->display->display_options['fields']['field_award_citizenship']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_award_citizenship']['empty'] = 'None';
  $handler->display->display_options['fields']['field_award_citizenship']['delta_offset'] = '0';
  /* Field: Content: Financial need */
  $handler->display->display_options['fields']['field_award_financial_need']['id'] = 'field_award_financial_need';
  $handler->display->display_options['fields']['field_award_financial_need']['table'] = 'field_data_field_award_financial_need';
  $handler->display->display_options['fields']['field_award_financial_need']['field'] = 'field_award_financial_need';
  $handler->display->display_options['fields']['field_award_financial_need']['label'] = '';
  $handler->display->display_options['fields']['field_award_financial_need']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_financial_need']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_financial_need']['alter']['text'] = '<b>Financial need:</b> [field_award_financial_need]<br />';
  $handler->display->display_options['fields']['field_award_financial_need']['element_label_colon'] = FALSE;
  /* Field: Content: Other */
  $handler->display->display_options['fields']['field_award_other']['id'] = 'field_award_other';
  $handler->display->display_options['fields']['field_award_other']['table'] = 'field_data_field_award_other';
  $handler->display->display_options['fields']['field_award_other']['field'] = 'field_award_other';
  $handler->display->display_options['fields']['field_award_other']['label'] = '';
  $handler->display->display_options['fields']['field_award_other']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_other']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_award_other']['element_label_colon'] = FALSE;
  /* Field: Content: Students */
  $handler->display->display_options['fields']['field_award_students']['id'] = 'field_award_students';
  $handler->display->display_options['fields']['field_award_students']['table'] = 'field_data_field_award_students';
  $handler->display->display_options['fields']['field_award_students']['field'] = 'field_award_students';
  $handler->display->display_options['fields']['field_award_students']['label'] = '';
  $handler->display->display_options['fields']['field_award_students']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_students']['alter']['text'] = '<b>Available to:</b> [field_award_students]<br />';
  $handler->display->display_options['fields']['field_award_students']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_award_students']['empty'] = 'All students';
  $handler->display->display_options['fields']['field_award_students']['delta_offset'] = '0';
  /* Field: Content: Study level */
  $handler->display->display_options['fields']['field_award_study_level']['id'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['table'] = 'field_data_field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['field'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['label'] = '';
  $handler->display->display_options['fields']['field_award_study_level']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['alter']['text'] = '[field_award_study_level]';
  $handler->display->display_options['fields']['field_award_study_level']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_award_study_level']['empty'] = 'All';
  $handler->display->display_options['fields']['field_award_study_level']['delta_offset'] = '0';
  /* Field: Content: Travel support */
  $handler->display->display_options['fields']['field_award_travel_support']['id'] = 'field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['table'] = 'field_data_field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['field'] = 'field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['label'] = '';
  $handler->display->display_options['fields']['field_award_travel_support']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_travel_support']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_travel_support']['alter']['text'] = '<b>Travel support:</b> [field_award_travel_support]<br />';
  $handler->display->display_options['fields']['field_award_travel_support']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Eligibility';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<b>Available to:</b> [field_award_students]<br />
<b>Study level:</b> [field_award_study_level]<br />
[field_award_travel_support]
<b>Citizenship requirements:</b> [field_award_citizenship]<br />
[field_award_financial_need]
[field_award_other]
';
  $handler->display->display_options['path'] = 'scholarships/grants-list';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Grants';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Page: Scholarships */
  $handler = $view->new_display('page', 'Page: Scholarships', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Scholarships';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Scholarship';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Area of study */
  $handler->display->display_options['fields']['field_award_study_area']['id'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['table'] = 'field_data_field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['field'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['label'] = 'Areas of study';
  $handler->display->display_options['fields']['field_award_study_area']['empty'] = '<ul><li class="first last">All</li></ul>';
  $handler->display->display_options['fields']['field_award_study_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_award_study_area']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_award_study_area']['multi_type'] = 'ul';
  /* Field: Content: Citizenship */
  $handler->display->display_options['fields']['field_award_citizenship']['id'] = 'field_award_citizenship';
  $handler->display->display_options['fields']['field_award_citizenship']['table'] = 'field_data_field_award_citizenship';
  $handler->display->display_options['fields']['field_award_citizenship']['field'] = 'field_award_citizenship';
  $handler->display->display_options['fields']['field_award_citizenship']['label'] = '';
  $handler->display->display_options['fields']['field_award_citizenship']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_citizenship']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_award_citizenship']['empty'] = 'None';
  $handler->display->display_options['fields']['field_award_citizenship']['delta_offset'] = '0';
  /* Field: Content: Financial need */
  $handler->display->display_options['fields']['field_award_financial_need']['id'] = 'field_award_financial_need';
  $handler->display->display_options['fields']['field_award_financial_need']['table'] = 'field_data_field_award_financial_need';
  $handler->display->display_options['fields']['field_award_financial_need']['field'] = 'field_award_financial_need';
  $handler->display->display_options['fields']['field_award_financial_need']['label'] = '';
  $handler->display->display_options['fields']['field_award_financial_need']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_financial_need']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_financial_need']['alter']['text'] = '<b>Financial need:</b> [field_award_financial_need]<br />';
  $handler->display->display_options['fields']['field_award_financial_need']['element_label_colon'] = FALSE;
  /* Field: Content: Other */
  $handler->display->display_options['fields']['field_award_other']['id'] = 'field_award_other';
  $handler->display->display_options['fields']['field_award_other']['table'] = 'field_data_field_award_other';
  $handler->display->display_options['fields']['field_award_other']['field'] = 'field_award_other';
  $handler->display->display_options['fields']['field_award_other']['label'] = '';
  $handler->display->display_options['fields']['field_award_other']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_other']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_award_other']['element_label_colon'] = FALSE;
  /* Field: Content: Students */
  $handler->display->display_options['fields']['field_award_students']['id'] = 'field_award_students';
  $handler->display->display_options['fields']['field_award_students']['table'] = 'field_data_field_award_students';
  $handler->display->display_options['fields']['field_award_students']['field'] = 'field_award_students';
  $handler->display->display_options['fields']['field_award_students']['label'] = '';
  $handler->display->display_options['fields']['field_award_students']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_students']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_students']['alter']['text'] = '[field_award_students]';
  $handler->display->display_options['fields']['field_award_students']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_award_students']['empty'] = 'Any';
  $handler->display->display_options['fields']['field_award_students']['delta_offset'] = '0';
  /* Field: Content: Study level */
  $handler->display->display_options['fields']['field_award_study_level']['id'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['table'] = 'field_data_field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['field'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['label'] = '';
  $handler->display->display_options['fields']['field_award_study_level']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['alter']['text'] = '[field_award_study_level]';
  $handler->display->display_options['fields']['field_award_study_level']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_award_study_level']['empty'] = 'All';
  $handler->display->display_options['fields']['field_award_study_level']['delta_offset'] = '0';
  /* Field: Content: Travel support */
  $handler->display->display_options['fields']['field_award_travel_support']['id'] = 'field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['table'] = 'field_data_field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['field'] = 'field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['label'] = '';
  $handler->display->display_options['fields']['field_award_travel_support']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_travel_support']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_travel_support']['alter']['text'] = '<b>Travel support:</b> [field_award_travel_support]<br />';
  $handler->display->display_options['fields']['field_award_travel_support']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Eligibility';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<b>Available to:</b> [field_award_students]<br />
<b>Study level:</b> [field_award_study_level]<br />
[field_award_travel_support]
<b>Citizenship limitation:</b> [field_award_citizenship]<br />
[field_award_financial_need]
[field_award_other]
';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'award' => 'award',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Award type (field_award_type) */
  $handler->display->display_options['filters']['field_award_type_value']['id'] = 'field_award_type_value';
  $handler->display->display_options['filters']['field_award_type_value']['table'] = 'field_data_field_award_type';
  $handler->display->display_options['filters']['field_award_type_value']['field'] = 'field_award_type_value';
  $handler->display->display_options['filters']['field_award_type_value']['value'] = array(
    'scholarship' => 'scholarship',
  );
  $handler->display->display_options['filters']['field_award_type_value']['group'] = 1;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['keys']['expose']['description'] = 'Enter one of more keywords';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Area of study (field_award_study_area) */
  $handler->display->display_options['filters']['field_award_study_area_tid']['id'] = 'field_award_study_area_tid';
  $handler->display->display_options['filters']['field_award_study_area_tid']['table'] = 'field_data_field_award_study_area';
  $handler->display->display_options['filters']['field_award_study_area_tid']['field'] = 'field_award_study_area_tid';
  $handler->display->display_options['filters']['field_award_study_area_tid']['value'] = array(
    1 => '1',
    2 => '2',
    3 => '3',
    4 => '4',
    12 => '12',
    5 => '5',
    7 => '7',
    16 => '16',
    17 => '17',
    20 => '20',
    18 => '18',
    19 => '19',
    29 => '29',
    77 => '77',
    27 => '27',
    28 => '28',
    21 => '21',
    53 => '53',
    81 => '81',
    82 => '82',
    54 => '54',
    55 => '55',
    56 => '56',
    83 => '83',
    79 => '79',
    80 => '80',
    86 => '86',
    30 => '30',
    31 => '31',
    34 => '34',
    43 => '43',
    44 => '44',
    71 => '71',
    33 => '33',
    66 => '66',
    67 => '67',
    70 => '70',
    76 => '76',
    75 => '75',
    78 => '78',
    84 => '84',
  );
  $handler->display->display_options['filters']['field_award_study_area_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_award_study_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['operator_id'] = 'field_award_study_area_tid_op';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['label'] = 'Area of study';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['operator'] = 'field_award_study_area_tid_op';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['identifier'] = 'field_award_study_area_tid';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_award_study_area_tid']['vocabulary'] = 'study_area';
  $handler->display->display_options['filters']['field_award_study_area_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'scholarships/scholarship-list';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Scholarships';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Page: Prizes */
  $handler = $view->new_display('page', 'Page: Prizes', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Prizes';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'scholarships/prize-list';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Prizes';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Page: Search */
  $handler = $view->new_display('page', 'Page: Search', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Scholarships';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_award_study_area' => 'field_award_study_area',
    'field_award_citizenship' => 'field_award_citizenship',
    'field_award_other' => 'field_award_other',
    'field_award_students' => 'field_award_students',
    'nothing' => 'nothing',
    'title' => 'title',
    'field_award_financial_need' => 'field_award_financial_need',
    'field_award_study_level' => 'field_award_study_level',
    'field_award_travel_support' => 'field_award_travel_support',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'field_award_study_area' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_award_citizenship' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_award_other' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_award_students' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_award_financial_need' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_award_study_level' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_award_travel_support' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Scholarship';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['alt'] = '[body]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_class'] = 'the_column_1';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '120';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Study level */
  $handler->display->display_options['fields']['field_award_study_level']['id'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['table'] = 'field_data_field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['field'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['alter']['text'] = '<strong>Study level:</strong> [field_award_study_level]<br/>';
  $handler->display->display_options['fields']['field_award_study_level']['empty'] = 'All';
  $handler->display->display_options['fields']['field_award_study_level']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['delta_offset'] = '0';
  /* Field: Content: Travel support */
  $handler->display->display_options['fields']['field_award_travel_support']['id'] = 'field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['table'] = 'field_data_field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['field'] = 'field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_travel_support']['alter']['text'] = '<strong>Travel support:</strong> [field_award_travel_support]<br/>';
  $handler->display->display_options['fields']['field_award_travel_support']['empty'] = 'N/A';
  $handler->display->display_options['fields']['field_award_travel_support']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_award_travel_support']['empty_zero'] = TRUE;
  /* Field: Content: Area of study */
  $handler->display->display_options['fields']['field_award_study_area']['id'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['table'] = 'field_data_field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['field'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['label'] = 'Areas of study';
  $handler->display->display_options['fields']['field_award_study_area']['element_class'] = 'the_column_2';
  $handler->display->display_options['fields']['field_award_study_area']['empty'] = '<ul><li class="first last">Any</li></ul>';
  $handler->display->display_options['fields']['field_award_study_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_award_study_area']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_award_study_area']['multi_type'] = 'ul';
  /* Field: Content: Students */
  $handler->display->display_options['fields']['field_award_students']['id'] = 'field_award_students';
  $handler->display->display_options['fields']['field_award_students']['table'] = 'field_data_field_award_students';
  $handler->display->display_options['fields']['field_award_students']['field'] = 'field_award_students';
  $handler->display->display_options['fields']['field_award_students']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_students']['alter']['text'] = '<strong>Student type:</strong> [field_award_students]<br/>';
  $handler->display->display_options['fields']['field_award_students']['empty'] = 'All';
  $handler->display->display_options['fields']['field_award_students']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_award_students']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_award_students']['delta_offset'] = '0';
  /* Field: Content: Approximate value */
  $handler->display->display_options['fields']['field_award_value']['id'] = 'field_award_value';
  $handler->display->display_options['fields']['field_award_value']['table'] = 'field_data_field_award_value';
  $handler->display->display_options['fields']['field_award_value']['field'] = 'field_award_value';
  $handler->display->display_options['fields']['field_award_value']['label'] = 'Approx value';
  $handler->display->display_options['fields']['field_award_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_value']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_value']['alter']['text'] = '<strong>Approx value:</strong> $[field_award_value]';
  $handler->display->display_options['fields']['field_award_value']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_award_value']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_award_value']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Faculty of Arts: Multiple Fields */
  $handler->display->display_options['fields']['views_multiple_field']['id'] = 'views_multiple_field';
  $handler->display->display_options['fields']['views_multiple_field']['table'] = 'views';
  $handler->display->display_options['fields']['views_multiple_field']['field'] = 'views_multiple_field';
  $handler->display->display_options['fields']['views_multiple_field']['label'] = 'Study level';
  $handler->display->display_options['fields']['views_multiple_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field']['alter']['text'] = '<strong>Study level:</strong> [views_multiple_field]';
  $handler->display->display_options['fields']['views_multiple_field']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field']['views_multiple_field_field'] = 'field_field_award_study_level';
  /* Field: Faculty of Arts: Multiple Fields */
  $handler->display->display_options['fields']['views_multiple_field_1']['id'] = 'views_multiple_field_1';
  $handler->display->display_options['fields']['views_multiple_field_1']['table'] = 'views';
  $handler->display->display_options['fields']['views_multiple_field_1']['field'] = 'views_multiple_field';
  $handler->display->display_options['fields']['views_multiple_field_1']['label'] = 'Student type';
  $handler->display->display_options['fields']['views_multiple_field_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field_1']['alter']['text'] = '<strong>Student type:</strong> [views_multiple_field_1]';
  $handler->display->display_options['fields']['views_multiple_field_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field_1']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field_1']['views_multiple_field_field'] = 'field_field_award_students';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Information';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[views_multiple_field_1]<br/>
[views_multiple_field]<br/>
<strong>Travel support:</strong> [field_award_travel_support]<br/>
[field_award_value]';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'the_column_3';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Award type (field_award_type) */
  $handler->display->display_options['filters']['field_award_type_value']['id'] = 'field_award_type_value';
  $handler->display->display_options['filters']['field_award_type_value']['table'] = 'field_data_field_award_type';
  $handler->display->display_options['filters']['field_award_type_value']['field'] = 'field_award_type_value';
  $handler->display->display_options['filters']['field_award_type_value']['value'] = array(
    'scholarship' => 'scholarship',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'award' => 'award',
  );
  $handler->display->display_options['path'] = 'scholarships-search';
  $handler->display->display_options['menu']['title'] = 'Scholarships';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Page: Advanced Search */
  $handler = $view->new_display('page', 'Page: Advanced Search', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Scholarships';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_award_study_area' => 'field_award_study_area',
    'field_award_citizenship' => 'field_award_citizenship',
    'field_award_other' => 'field_award_other',
    'field_award_students' => 'field_award_students',
    'nothing' => 'nothing',
    'title' => 'title',
    'field_award_financial_need' => 'field_award_financial_need',
    'field_award_study_level' => 'field_award_study_level',
    'field_award_travel_support' => 'field_award_travel_support',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'field_award_study_area' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_award_citizenship' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_award_other' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_award_students' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_award_financial_need' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_award_study_level' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_award_travel_support' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Scholarship';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['alt'] = '[body]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_class'] = 'the_column_1';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '120';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Students */
  $handler->display->display_options['fields']['field_award_students']['id'] = 'field_award_students';
  $handler->display->display_options['fields']['field_award_students']['table'] = 'field_data_field_award_students';
  $handler->display->display_options['fields']['field_award_students']['field'] = 'field_award_students';
  $handler->display->display_options['fields']['field_award_students']['label'] = '';
  $handler->display->display_options['fields']['field_award_students']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_students']['alter']['text'] = '<b>Available to:</b> [field_award_students]<br />';
  $handler->display->display_options['fields']['field_award_students']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_award_students']['empty'] = 'All';
  $handler->display->display_options['fields']['field_award_students']['delta_offset'] = '0';
  /* Field: Content: Study level */
  $handler->display->display_options['fields']['field_award_study_level']['id'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['table'] = 'field_data_field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['field'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['alter']['text'] = '[field_award_study_level]';
  $handler->display->display_options['fields']['field_award_study_level']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_award_study_level']['empty'] = 'All';
  $handler->display->display_options['fields']['field_award_study_level']['delta_offset'] = '0';
  /* Field: Content: Travel support */
  $handler->display->display_options['fields']['field_award_travel_support']['id'] = 'field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['table'] = 'field_data_field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['field'] = 'field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['exclude'] = TRUE;
  /* Field: Content: Area of study */
  $handler->display->display_options['fields']['field_award_study_area']['id'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['table'] = 'field_data_field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['field'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['label'] = 'Areas of study';
  $handler->display->display_options['fields']['field_award_study_area']['element_class'] = 'the_column_2';
  $handler->display->display_options['fields']['field_award_study_area']['empty'] = '<ul><li class="first last">Any</li></ul>';
  $handler->display->display_options['fields']['field_award_study_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_award_study_area']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_award_study_area']['multi_type'] = 'ul';
  /* Field: Content: Approximate value */
  $handler->display->display_options['fields']['field_award_value']['id'] = 'field_award_value';
  $handler->display->display_options['fields']['field_award_value']['table'] = 'field_data_field_award_value';
  $handler->display->display_options['fields']['field_award_value']['field'] = 'field_award_value';
  $handler->display->display_options['fields']['field_award_value']['label'] = 'Approx value';
  $handler->display->display_options['fields']['field_award_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_value']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_value']['alter']['text'] = '<strong>Approx value:</strong> $[field_award_value]';
  $handler->display->display_options['fields']['field_award_value']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Faculty of Arts: Multiple Fields */
  $handler->display->display_options['fields']['views_multiple_field']['id'] = 'views_multiple_field';
  $handler->display->display_options['fields']['views_multiple_field']['table'] = 'views';
  $handler->display->display_options['fields']['views_multiple_field']['field'] = 'views_multiple_field';
  $handler->display->display_options['fields']['views_multiple_field']['label'] = 'Student type';
  $handler->display->display_options['fields']['views_multiple_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field']['alter']['text'] = '<strong>Student type:</strong> [views_multiple_field]';
  $handler->display->display_options['fields']['views_multiple_field']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field']['views_multiple_field_field'] = 'field_field_award_students';
  /* Field: Faculty of Arts: Multiple Fields */
  $handler->display->display_options['fields']['views_multiple_field_1']['id'] = 'views_multiple_field_1';
  $handler->display->display_options['fields']['views_multiple_field_1']['table'] = 'views';
  $handler->display->display_options['fields']['views_multiple_field_1']['field'] = 'views_multiple_field';
  $handler->display->display_options['fields']['views_multiple_field_1']['label'] = 'Study level';
  $handler->display->display_options['fields']['views_multiple_field_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field_1']['alter']['text'] = '<strong>Study level:</strong> [views_multiple_field_1]';
  $handler->display->display_options['fields']['views_multiple_field_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field_1']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field_1']['views_multiple_field_field'] = 'field_field_award_study_level';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Information';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[views_multiple_field]<br/>
[views_multiple_field_1]<br/>
<strong>Travel support:</strong> [field_award_travel_support]<br/>
[field_award_value]';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'the_column_3';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'award' => 'award',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Award type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Area of study (field_award_study_area) */
  $handler->display->display_options['filters']['field_award_study_area_tid']['id'] = 'field_award_study_area_tid';
  $handler->display->display_options['filters']['field_award_study_area_tid']['table'] = 'field_data_field_award_study_area';
  $handler->display->display_options['filters']['field_award_study_area_tid']['field'] = 'field_award_study_area_tid';
  $handler->display->display_options['filters']['field_award_study_area_tid']['value'] = array(
    59 => '59',
    61 => '61',
    60 => '60',
    62 => '62',
    63 => '63',
    64 => '64',
    65 => '65',
    66 => '66',
    67 => '67',
    68 => '68',
    69 => '69',
    70 => '70',
    71 => '71',
    72 => '72',
    73 => '73',
    74 => '74',
    75 => '75',
    86 => '86',
    87 => '87',
    88 => '88',
    92 => '92',
    89 => '89',
    90 => '90',
    91 => '91',
    76 => '76',
    77 => '77',
    78 => '78',
    79 => '79',
    80 => '80',
    81 => '81',
    82 => '82',
    83 => '83',
    84 => '84',
    85 => '85',
    58 => '58',
    93 => '93',
    94 => '94',
    95 => '95',
    96 => '96',
    98 => '98',
    99 => '99',
    97 => '97',
  );
  $handler->display->display_options['filters']['field_award_study_area_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_award_study_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['operator_id'] = 'field_award_study_area_tid_op';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['label'] = 'Area of study';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['operator'] = 'field_award_study_area_tid_op';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['identifier'] = 'field_award_study_area_tid';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_award_study_area_tid']['vocabulary'] = 'study_area';
  $handler->display->display_options['filters']['field_award_study_area_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Study level (field_award_study_level) */
  $handler->display->display_options['filters']['field_award_study_level_value']['id'] = 'field_award_study_level_value';
  $handler->display->display_options['filters']['field_award_study_level_value']['table'] = 'field_data_field_award_study_level';
  $handler->display->display_options['filters']['field_award_study_level_value']['field'] = 'field_award_study_level_value';
  $handler->display->display_options['filters']['field_award_study_level_value']['value'] = array(
    'undergraduate' => 'undergraduate',
    'honours' => 'honours',
    'graduate' => 'graduate',
    'RHD' => 'RHD',
    'fellowship' => 'fellowship',
  );
  $handler->display->display_options['filters']['field_award_study_level_value']['group'] = 1;
  $handler->display->display_options['filters']['field_award_study_level_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_level_value']['expose']['operator_id'] = 'field_award_study_level_value_op';
  $handler->display->display_options['filters']['field_award_study_level_value']['expose']['label'] = 'Study level';
  $handler->display->display_options['filters']['field_award_study_level_value']['expose']['operator'] = 'field_award_study_level_value_op';
  $handler->display->display_options['filters']['field_award_study_level_value']['expose']['identifier'] = 'field_award_study_level_value';
  $handler->display->display_options['filters']['field_award_study_level_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_award_study_level_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Travel support (field_award_travel_support) */
  $handler->display->display_options['filters']['field_award_travel_support_value']['id'] = 'field_award_travel_support_value';
  $handler->display->display_options['filters']['field_award_travel_support_value']['table'] = 'field_data_field_award_travel_support';
  $handler->display->display_options['filters']['field_award_travel_support_value']['field'] = 'field_award_travel_support_value';
  $handler->display->display_options['filters']['field_award_travel_support_value']['group'] = 1;
  $handler->display->display_options['filters']['field_award_travel_support_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_award_travel_support_value']['expose']['operator_id'] = 'field_award_travel_support_value_op';
  $handler->display->display_options['filters']['field_award_travel_support_value']['expose']['label'] = 'Travel support';
  $handler->display->display_options['filters']['field_award_travel_support_value']['expose']['operator'] = 'field_award_travel_support_value_op';
  $handler->display->display_options['filters']['field_award_travel_support_value']['expose']['identifier'] = 'field_award_travel_support_value';
  $handler->display->display_options['filters']['field_award_travel_support_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Award type (field_award_type) */
  $handler->display->display_options['filters']['field_award_type_value_1']['id'] = 'field_award_type_value_1';
  $handler->display->display_options['filters']['field_award_type_value_1']['table'] = 'field_data_field_award_type';
  $handler->display->display_options['filters']['field_award_type_value_1']['field'] = 'field_award_type_value';
  $handler->display->display_options['filters']['field_award_type_value_1']['value'] = array(
    'scholarship' => 'scholarship',
    'prize' => 'prize',
    'grant' => 'grant',
  );
  $handler->display->display_options['filters']['field_award_type_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_award_type_value_1']['expose']['operator_id'] = 'field_award_type_value_1_op';
  $handler->display->display_options['filters']['field_award_type_value_1']['expose']['label'] = 'Award type';
  $handler->display->display_options['filters']['field_award_type_value_1']['expose']['operator'] = 'field_award_type_value_1_op';
  $handler->display->display_options['filters']['field_award_type_value_1']['expose']['identifier'] = 'field_award_type_value_1';
  $handler->display->display_options['filters']['field_award_type_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_award_type_value_1']['group_info']['label'] = 'Award type (field_award_type)';
  $handler->display->display_options['filters']['field_award_type_value_1']['group_info']['identifier'] = 'field_award_type_value_1';
  $handler->display->display_options['filters']['field_award_type_value_1']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_award_type_value_1']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['path'] = 'scholarships-advanced-search';
  $handler->display->display_options['menu']['title'] = 'Scholarships';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Block: Details */
  $handler = $view->new_display('block', 'Block: Details', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Approximate value */
  $handler->display->display_options['fields']['field_award_value']['id'] = 'field_award_value';
  $handler->display->display_options['fields']['field_award_value']['table'] = 'field_data_field_award_value';
  $handler->display->display_options['fields']['field_award_value']['field'] = 'field_award_value';
  $handler->display->display_options['fields']['field_award_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_value']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_value']['alter']['text'] = '<strong>Approximate value: $[field_award_value]</strong><br />
<div class="award-value-caveat">The amount available for this award is approximate. It will be confirmed at the time of awarding and determined by the committee according to the terms of the award.</div>';
  $handler->display->display_options['fields']['field_award_value']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_award_value']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_award_value']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_award_value']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_award_value']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_award_value']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Application open and closing dates */
  $handler->display->display_options['fields']['field_award_application_date']['id'] = 'field_award_application_date';
  $handler->display->display_options['fields']['field_award_application_date']['table'] = 'field_data_field_award_application_date';
  $handler->display->display_options['fields']['field_award_application_date']['field'] = 'field_award_application_date';
  $handler->display->display_options['fields']['field_award_application_date']['label'] = 'Open';
  $handler->display->display_options['fields']['field_award_application_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_application_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_application_date']['alter']['text'] = '<strong>Open:</strong> [field_award_application_date]<br/>';
  $handler->display->display_options['fields']['field_award_application_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_award_application_date']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_award_application_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_award_application_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_award_application_date']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_award_application_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Application open and closing dates */
  $handler->display->display_options['fields']['field_award_application_date_1']['id'] = 'field_award_application_date_1';
  $handler->display->display_options['fields']['field_award_application_date_1']['table'] = 'field_data_field_award_application_date';
  $handler->display->display_options['fields']['field_award_application_date_1']['field'] = 'field_award_application_date';
  $handler->display->display_options['fields']['field_award_application_date_1']['label'] = 'Close';
  $handler->display->display_options['fields']['field_award_application_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_application_date_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_application_date_1']['alter']['text'] = '<strong>Close:</strong> [field_award_application_date_1]<br/>';
  $handler->display->display_options['fields']['field_award_application_date_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_award_application_date_1']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Area of study */
  $handler->display->display_options['fields']['field_award_study_area']['id'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['table'] = 'field_data_field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['field'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_area']['element_type'] = '0';
  $handler->display->display_options['fields']['field_award_study_area']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_award_study_area']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_award_study_area']['element_wrapper_class'] = 'inline-list';
  $handler->display->display_options['fields']['field_award_study_area']['empty'] = '<ul><li class="first last">Any</li></ul>';
  $handler->display->display_options['fields']['field_award_study_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_award_study_area']['delta_offset'] = '0';
  /* Field: Faculty of Arts: Multiple Fields */
  $handler->display->display_options['fields']['views_multiple_field']['id'] = 'views_multiple_field';
  $handler->display->display_options['fields']['views_multiple_field']['table'] = 'views';
  $handler->display->display_options['fields']['views_multiple_field']['field'] = 'views_multiple_field';
  $handler->display->display_options['fields']['views_multiple_field']['label'] = 'Area of study';
  $handler->display->display_options['fields']['views_multiple_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field']['alter']['text'] = '<strong>Area of study:</strong> [views_multiple_field]<br/>';
  $handler->display->display_options['fields']['views_multiple_field']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field']['views_multiple_field_field'] = 'field_field_award_study_area';
  /* Field: Content: Students */
  $handler->display->display_options['fields']['field_award_students']['id'] = 'field_award_students';
  $handler->display->display_options['fields']['field_award_students']['table'] = 'field_data_field_award_students';
  $handler->display->display_options['fields']['field_award_students']['field'] = 'field_award_students';
  $handler->display->display_options['fields']['field_award_students']['label'] = 'Available to';
  $handler->display->display_options['fields']['field_award_students']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_students']['alter']['text'] = '[field_award_students]';
  $handler->display->display_options['fields']['field_award_students']['element_type'] = '0';
  $handler->display->display_options['fields']['field_award_students']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_award_students']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_award_students']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_award_students']['delta_offset'] = '0';
  /* Field: Faculty of Arts: Multiple Fields */
  $handler->display->display_options['fields']['views_multiple_field_1']['id'] = 'views_multiple_field_1';
  $handler->display->display_options['fields']['views_multiple_field_1']['table'] = 'views';
  $handler->display->display_options['fields']['views_multiple_field_1']['field'] = 'views_multiple_field';
  $handler->display->display_options['fields']['views_multiple_field_1']['label'] = 'Available to';
  $handler->display->display_options['fields']['views_multiple_field_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field_1']['alter']['text'] = '<strong>Available to:</strong> [field_award_students]<br/>';
  $handler->display->display_options['fields']['views_multiple_field_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field_1']['views_multiple_field_field'] = 'field_field_award_students';
  /* Field: Content: Study level */
  $handler->display->display_options['fields']['field_award_study_level']['id'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['table'] = 'field_data_field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['field'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['alter']['text'] = '[field_award_study_level]<br />';
  $handler->display->display_options['fields']['field_award_study_level']['element_type'] = '0';
  $handler->display->display_options['fields']['field_award_study_level']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_award_study_level']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_award_study_level']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['delta_offset'] = '0';
  /* Field: Faculty of Arts: Multiple Fields */
  $handler->display->display_options['fields']['views_multiple_field_2']['id'] = 'views_multiple_field_2';
  $handler->display->display_options['fields']['views_multiple_field_2']['table'] = 'views';
  $handler->display->display_options['fields']['views_multiple_field_2']['field'] = 'views_multiple_field';
  $handler->display->display_options['fields']['views_multiple_field_2']['label'] = 'Study level';
  $handler->display->display_options['fields']['views_multiple_field_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field_2']['alter']['text'] = '<strong>Study level:</strong> [field_award_study_level]<br/>';
  $handler->display->display_options['fields']['views_multiple_field_2']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field_2']['views_multiple_field_field'] = 'field_field_award_study_level';
  /* Field: Content: Travel support */
  $handler->display->display_options['fields']['field_award_travel_support']['id'] = 'field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['table'] = 'field_data_field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['field'] = 'field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_travel_support']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_travel_support']['alter']['text'] = '<strong>Travel support:</strong> [field_award_travel_support]<br />';
  $handler->display->display_options['fields']['field_award_travel_support']['element_type'] = '0';
  $handler->display->display_options['fields']['field_award_travel_support']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_award_travel_support']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_award_travel_support']['hide_empty'] = TRUE;
  /* Field: Content: Citizenship */
  $handler->display->display_options['fields']['field_award_citizenship']['id'] = 'field_award_citizenship';
  $handler->display->display_options['fields']['field_award_citizenship']['table'] = 'field_data_field_award_citizenship';
  $handler->display->display_options['fields']['field_award_citizenship']['field'] = 'field_award_citizenship';
  $handler->display->display_options['fields']['field_award_citizenship']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_citizenship']['alter']['text'] = '[field_award_citizenship]';
  $handler->display->display_options['fields']['field_award_citizenship']['element_type'] = '0';
  $handler->display->display_options['fields']['field_award_citizenship']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_award_citizenship']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_award_citizenship']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_award_citizenship']['delta_offset'] = '0';
  /* Field: Faculty of Arts: Multiple Fields */
  $handler->display->display_options['fields']['views_multiple_field_3']['id'] = 'views_multiple_field_3';
  $handler->display->display_options['fields']['views_multiple_field_3']['table'] = 'views';
  $handler->display->display_options['fields']['views_multiple_field_3']['field'] = 'views_multiple_field';
  $handler->display->display_options['fields']['views_multiple_field_3']['label'] = 'Citizenship';
  $handler->display->display_options['fields']['views_multiple_field_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field_3']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field_3']['alter']['text'] = '<strong>Citizenship:</strong> [field_award_citizenship]<br/>';
  $handler->display->display_options['fields']['views_multiple_field_3']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['views_multiple_field_3']['views_multiple_field_field'] = 'field_field_award_citizenship';
  /* Field: Content: Financial need */
  $handler->display->display_options['fields']['field_award_financial_need']['id'] = 'field_award_financial_need';
  $handler->display->display_options['fields']['field_award_financial_need']['table'] = 'field_data_field_award_financial_need';
  $handler->display->display_options['fields']['field_award_financial_need']['field'] = 'field_award_financial_need';
  $handler->display->display_options['fields']['field_award_financial_need']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_financial_need']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_financial_need']['alter']['text'] = '<strong>Financial need:</strong> [field_award_financial_need]<br />';
  $handler->display->display_options['fields']['field_award_financial_need']['element_type'] = '0';
  $handler->display->display_options['fields']['field_award_financial_need']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_award_financial_need']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_award_financial_need']['hide_empty'] = TRUE;
  /* Field: Content: University trust record */
  $handler->display->display_options['fields']['field_award_uni_trust_record']['id'] = 'field_award_uni_trust_record';
  $handler->display->display_options['fields']['field_award_uni_trust_record']['table'] = 'field_data_field_award_uni_trust_record';
  $handler->display->display_options['fields']['field_award_uni_trust_record']['field'] = 'field_award_uni_trust_record';
  $handler->display->display_options['fields']['field_award_uni_trust_record']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_uni_trust_record']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_uni_trust_record']['alter']['text'] = '<strong>University trust record:</strong> [field_award_uni_trust_record]<br />';
  $handler->display->display_options['fields']['field_award_uni_trust_record']['element_type'] = '0';
  $handler->display->display_options['fields']['field_award_uni_trust_record']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_award_uni_trust_record']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_award_uni_trust_record']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_award_uni_trust_record']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_award_uni_trust_record']['click_sort_column'] = 'url';
  /* Field: Content: Other */
  $handler->display->display_options['fields']['field_award_other']['id'] = 'field_award_other';
  $handler->display->display_options['fields']['field_award_other']['table'] = 'field_data_field_award_other';
  $handler->display->display_options['fields']['field_award_other']['field'] = 'field_award_other';
  $handler->display->display_options['fields']['field_award_other']['label'] = '';
  $handler->display->display_options['fields']['field_award_other']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_other']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_other']['alter']['text'] = '<br/>[field_award_other]';
  $handler->display->display_options['fields']['field_award_other']['element_type'] = '0';
  $handler->display->display_options['fields']['field_award_other']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_award_other']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_award_other']['hide_empty'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_award_value]
<!--open-->[field_award_application_date]
<!--close-->[field_award_application_date_1]
<!--study area-->[views_multiple_field]
<!--student type-->[views_multiple_field_1]
<!--study level-->[views_multiple_field_2]
[field_award_travel_support]
<!--citizenship-->[views_multiple_field_3]
[field_award_financial_need]
[field_award_uni_trust_record]

[field_award_other]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'award' => 'award',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Block: Grants Advanced */
  $handler = $view->new_display('block', 'Block: Grants Advanced', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Grant';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['alt'] = '[body]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_class'] = 'the_column_1';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '120';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Area of study */
  $handler->display->display_options['fields']['field_award_study_area']['id'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['table'] = 'field_data_field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['field'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['label'] = 'Areas of study';
  $handler->display->display_options['fields']['field_award_study_area']['element_class'] = 'the_column_2';
  $handler->display->display_options['fields']['field_award_study_area']['empty'] = '<ul><li class="first last">Any</li></ul>';
  $handler->display->display_options['fields']['field_award_study_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_award_study_area']['delta_offset'] = '0';
  /* Field: Content: Study level */
  $handler->display->display_options['fields']['field_award_study_level']['id'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['table'] = 'field_data_field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['field'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_award_study_level']['element_wrapper_class'] = 'inline-list';
  $handler->display->display_options['fields']['field_award_study_level']['empty'] = 'All';
  $handler->display->display_options['fields']['field_award_study_level']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['delta_offset'] = '0';
  /* Field: Content: Approximate value */
  $handler->display->display_options['fields']['field_award_value']['id'] = 'field_award_value';
  $handler->display->display_options['fields']['field_award_value']['table'] = 'field_data_field_award_value';
  $handler->display->display_options['fields']['field_award_value']['field'] = 'field_award_value';
  $handler->display->display_options['fields']['field_award_value']['label'] = 'Approx value';
  $handler->display->display_options['fields']['field_award_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_value']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_value']['alter']['text'] = '<strong>Approx value:</strong> $[field_award_value]';
  $handler->display->display_options['fields']['field_award_value']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Information';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<strong>Study level:</strong> [field_award_study_level]<br/>
[field_award_value]';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'the_column_3';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'award' => 'award',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Area of study (field_award_study_area) */
  $handler->display->display_options['filters']['field_award_study_area_tid']['id'] = 'field_award_study_area_tid';
  $handler->display->display_options['filters']['field_award_study_area_tid']['table'] = 'field_data_field_award_study_area';
  $handler->display->display_options['filters']['field_award_study_area_tid']['field'] = 'field_award_study_area_tid';
  $handler->display->display_options['filters']['field_award_study_area_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_award_study_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['operator_id'] = 'field_award_study_area_tid_op';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['label'] = 'Area of study';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['operator'] = 'field_award_study_area_tid_op';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['identifier'] = 'field_award_study_area_tid';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_award_study_area_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_award_study_area_tid']['vocabulary'] = 'study_area';
  $handler->display->display_options['filters']['field_award_study_area_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Study level (field_award_study_level) */
  $handler->display->display_options['filters']['field_award_study_level_value']['id'] = 'field_award_study_level_value';
  $handler->display->display_options['filters']['field_award_study_level_value']['table'] = 'field_data_field_award_study_level';
  $handler->display->display_options['filters']['field_award_study_level_value']['field'] = 'field_award_study_level_value';
  $handler->display->display_options['filters']['field_award_study_level_value']['group'] = 1;
  $handler->display->display_options['filters']['field_award_study_level_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_level_value']['expose']['operator_id'] = 'field_award_study_level_value_op';
  $handler->display->display_options['filters']['field_award_study_level_value']['expose']['label'] = 'Study level';
  $handler->display->display_options['filters']['field_award_study_level_value']['expose']['operator'] = 'field_award_study_level_value_op';
  $handler->display->display_options['filters']['field_award_study_level_value']['expose']['identifier'] = 'field_award_study_level_value';
  $handler->display->display_options['filters']['field_award_study_level_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Award type (field_award_type) */
  $handler->display->display_options['filters']['field_award_type_value_1']['id'] = 'field_award_type_value_1';
  $handler->display->display_options['filters']['field_award_type_value_1']['table'] = 'field_data_field_award_type';
  $handler->display->display_options['filters']['field_award_type_value_1']['field'] = 'field_award_type_value';
  $handler->display->display_options['filters']['field_award_type_value_1']['value'] = array(
    'scholarship' => 'scholarship',
    'prize' => 'prize',
    'grant' => 'grant',
  );
  $handler->display->display_options['filters']['field_award_type_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_award_type_value_1']['expose']['operator_id'] = 'field_award_type_value_1_op';
  $handler->display->display_options['filters']['field_award_type_value_1']['expose']['label'] = 'Award type';
  $handler->display->display_options['filters']['field_award_type_value_1']['expose']['operator'] = 'field_award_type_value_1_op';
  $handler->display->display_options['filters']['field_award_type_value_1']['expose']['identifier'] = 'field_award_type_value_1';
  $handler->display->display_options['filters']['field_award_type_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_award_type_value_1']['expose']['reduce'] = TRUE;

  /* Display: Block: Scholarships Advanced */
  $handler = $view->new_display('block', 'Block: Scholarships Advanced', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '120';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Scholarship';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['alt'] = '[body]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_class'] = 'the_column_1';
  /* Field: Content: Area of study */
  $handler->display->display_options['fields']['field_award_study_area']['id'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['table'] = 'field_data_field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['field'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['label'] = 'Areas of study';
  $handler->display->display_options['fields']['field_award_study_area']['element_class'] = 'the_column_2';
  $handler->display->display_options['fields']['field_award_study_area']['empty'] = '<ul><li class="first last">Any</li></ul>';
  $handler->display->display_options['fields']['field_award_study_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_award_study_area']['delta_offset'] = '0';
  /* Field: Content: Study level */
  $handler->display->display_options['fields']['field_award_study_level']['id'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['table'] = 'field_data_field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['field'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_award_study_level']['element_wrapper_class'] = 'inline-list';
  $handler->display->display_options['fields']['field_award_study_level']['empty'] = 'Any';
  $handler->display->display_options['fields']['field_award_study_level']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['delta_offset'] = '0';
  /* Field: Content: Citizenship */
  $handler->display->display_options['fields']['field_award_citizenship']['id'] = 'field_award_citizenship';
  $handler->display->display_options['fields']['field_award_citizenship']['table'] = 'field_data_field_award_citizenship';
  $handler->display->display_options['fields']['field_award_citizenship']['field'] = 'field_award_citizenship';
  $handler->display->display_options['fields']['field_award_citizenship']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_citizenship']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_citizenship']['alter']['text'] = '[field_award_citizenship]';
  $handler->display->display_options['fields']['field_award_citizenship']['element_type'] = '0';
  $handler->display->display_options['fields']['field_award_citizenship']['element_class'] = 'inline-list';
  $handler->display->display_options['fields']['field_award_citizenship']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_award_citizenship']['delta_offset'] = '0';
  /* Field: Content: Financial need */
  $handler->display->display_options['fields']['field_award_financial_need']['id'] = 'field_award_financial_need';
  $handler->display->display_options['fields']['field_award_financial_need']['table'] = 'field_data_field_award_financial_need';
  $handler->display->display_options['fields']['field_award_financial_need']['field'] = 'field_award_financial_need';
  $handler->display->display_options['fields']['field_award_financial_need']['label'] = '';
  $handler->display->display_options['fields']['field_award_financial_need']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_financial_need']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_financial_need']['alter']['text'] = '<b>Financial need:</b> [field_award_financial_need]<br />';
  $handler->display->display_options['fields']['field_award_financial_need']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_award_financial_need']['hide_empty'] = TRUE;
  /* Field: Content: Travel support */
  $handler->display->display_options['fields']['field_award_travel_support']['id'] = 'field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['table'] = 'field_data_field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['field'] = 'field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['label'] = '';
  $handler->display->display_options['fields']['field_award_travel_support']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_travel_support']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_travel_support']['alter']['text'] = '<b>Travel support:</b> [field_award_travel_support]<br />';
  $handler->display->display_options['fields']['field_award_travel_support']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_award_travel_support']['hide_empty'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Eligibility';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<b>Study level:</b> [field_award_study_level]<br />
[field_award_travel_support]
<b>Citizenship:</b> [field_award_citizenship]
';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'the_column_3';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'award' => 'award',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Award type (field_award_type) */
  $handler->display->display_options['filters']['field_award_type_value']['id'] = 'field_award_type_value';
  $handler->display->display_options['filters']['field_award_type_value']['table'] = 'field_data_field_award_type';
  $handler->display->display_options['filters']['field_award_type_value']['field'] = 'field_award_type_value';
  $handler->display->display_options['filters']['field_award_type_value']['value'] = array(
    'scholarship' => 'scholarship',
  );
  $handler->display->display_options['filters']['field_award_type_value']['group'] = 1;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['keys']['expose']['description'] = 'Enter one or more keywords to search for';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Area of study (field_award_study_area) */
  $handler->display->display_options['filters']['field_award_study_area_tid']['id'] = 'field_award_study_area_tid';
  $handler->display->display_options['filters']['field_award_study_area_tid']['table'] = 'field_data_field_award_study_area';
  $handler->display->display_options['filters']['field_award_study_area_tid']['field'] = 'field_award_study_area_tid';
  $handler->display->display_options['filters']['field_award_study_area_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_award_study_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['operator_id'] = 'field_award_study_area_tid_op';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['label'] = 'Area of study';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['operator'] = 'field_award_study_area_tid_op';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['identifier'] = 'field_award_study_area_tid';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_award_study_area_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_award_study_area_tid']['vocabulary'] = 'study_area';
  $handler->display->display_options['filters']['field_award_study_area_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Citizenship (field_award_citizenship) */
  $handler->display->display_options['filters']['field_award_citizenship_value']['id'] = 'field_award_citizenship_value';
  $handler->display->display_options['filters']['field_award_citizenship_value']['table'] = 'field_data_field_award_citizenship';
  $handler->display->display_options['filters']['field_award_citizenship_value']['field'] = 'field_award_citizenship_value';
  $handler->display->display_options['filters']['field_award_citizenship_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_award_citizenship_value']['expose']['operator_id'] = 'field_award_citizenship_value_op';
  $handler->display->display_options['filters']['field_award_citizenship_value']['expose']['label'] = 'Citizenship';
  $handler->display->display_options['filters']['field_award_citizenship_value']['expose']['operator'] = 'field_award_citizenship_value_op';
  $handler->display->display_options['filters']['field_award_citizenship_value']['expose']['identifier'] = 'field_award_citizenship_value';
  $handler->display->display_options['filters']['field_award_citizenship_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Study level (field_award_study_level) */
  $handler->display->display_options['filters']['field_award_study_level_value']['id'] = 'field_award_study_level_value';
  $handler->display->display_options['filters']['field_award_study_level_value']['table'] = 'field_data_field_award_study_level';
  $handler->display->display_options['filters']['field_award_study_level_value']['field'] = 'field_award_study_level_value';
  $handler->display->display_options['filters']['field_award_study_level_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_level_value']['expose']['operator_id'] = 'field_award_study_level_value_op';
  $handler->display->display_options['filters']['field_award_study_level_value']['expose']['label'] = 'Study level';
  $handler->display->display_options['filters']['field_award_study_level_value']['expose']['operator'] = 'field_award_study_level_value_op';
  $handler->display->display_options['filters']['field_award_study_level_value']['expose']['identifier'] = 'field_award_study_level_value';
  $handler->display->display_options['filters']['field_award_study_level_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Travel support (field_award_travel_support) */
  $handler->display->display_options['filters']['field_award_travel_support_value']['id'] = 'field_award_travel_support_value';
  $handler->display->display_options['filters']['field_award_travel_support_value']['table'] = 'field_data_field_award_travel_support';
  $handler->display->display_options['filters']['field_award_travel_support_value']['field'] = 'field_award_travel_support_value';
  $handler->display->display_options['filters']['field_award_travel_support_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_award_travel_support_value']['expose']['operator_id'] = 'field_award_travel_support_value_op';
  $handler->display->display_options['filters']['field_award_travel_support_value']['expose']['label'] = 'Travel support';
  $handler->display->display_options['filters']['field_award_travel_support_value']['expose']['operator'] = 'field_award_travel_support_value_op';
  $handler->display->display_options['filters']['field_award_travel_support_value']['expose']['identifier'] = 'field_award_travel_support_value';
  $handler->display->display_options['filters']['field_award_travel_support_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Block: Prizes Advanced */
  $handler = $view->new_display('block', 'Block: Prizes Advanced', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Prize';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['alt'] = '[body]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_class'] = 'the_column_1';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '120';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Area of study */
  $handler->display->display_options['fields']['field_award_study_area']['id'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['table'] = 'field_data_field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['field'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['label'] = 'Areas of study';
  $handler->display->display_options['fields']['field_award_study_area']['element_class'] = 'the_column_2';
  $handler->display->display_options['fields']['field_award_study_area']['empty'] = '<ul><li class="first last">Any</li></ul>';
  $handler->display->display_options['fields']['field_award_study_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_award_study_area']['delta_offset'] = '0';
  /* Field: Content: Study level */
  $handler->display->display_options['fields']['field_award_study_level']['id'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['table'] = 'field_data_field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['field'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_award_study_level']['element_wrapper_class'] = 'inline-list';
  $handler->display->display_options['fields']['field_award_study_level']['empty'] = 'Any';
  $handler->display->display_options['fields']['field_award_study_level']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['delta_offset'] = '0';
  /* Field: Content: Approximate value */
  $handler->display->display_options['fields']['field_award_value']['id'] = 'field_award_value';
  $handler->display->display_options['fields']['field_award_value']['table'] = 'field_data_field_award_value';
  $handler->display->display_options['fields']['field_award_value']['field'] = 'field_award_value';
  $handler->display->display_options['fields']['field_award_value']['label'] = 'Approx value';
  $handler->display->display_options['fields']['field_award_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_value']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_value']['alter']['text'] = '<strong>Approx value:</strong> $[field_award_value]';
  $handler->display->display_options['fields']['field_award_value']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_award_value']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_award_value']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Information';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<strong>Study level:</strong> [field_award_study_level]<br/>
[field_award_value]
';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'the_column_3';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'award' => 'award',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Area of study (field_award_study_area) */
  $handler->display->display_options['filters']['field_award_study_area_tid']['id'] = 'field_award_study_area_tid';
  $handler->display->display_options['filters']['field_award_study_area_tid']['table'] = 'field_data_field_award_study_area';
  $handler->display->display_options['filters']['field_award_study_area_tid']['field'] = 'field_award_study_area_tid';
  $handler->display->display_options['filters']['field_award_study_area_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_award_study_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['operator_id'] = 'field_award_study_area_tid_op';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['label'] = 'Area of study';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['operator'] = 'field_award_study_area_tid_op';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['identifier'] = 'field_award_study_area_tid';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_award_study_area_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_award_study_area_tid']['vocabulary'] = 'study_area';
  $handler->display->display_options['filters']['field_award_study_area_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Study level (field_award_study_level) */
  $handler->display->display_options['filters']['field_award_study_level_value']['id'] = 'field_award_study_level_value';
  $handler->display->display_options['filters']['field_award_study_level_value']['table'] = 'field_data_field_award_study_level';
  $handler->display->display_options['filters']['field_award_study_level_value']['field'] = 'field_award_study_level_value';
  $handler->display->display_options['filters']['field_award_study_level_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_level_value']['expose']['operator_id'] = 'field_award_study_level_value_op';
  $handler->display->display_options['filters']['field_award_study_level_value']['expose']['label'] = 'Study level';
  $handler->display->display_options['filters']['field_award_study_level_value']['expose']['operator'] = 'field_award_study_level_value_op';
  $handler->display->display_options['filters']['field_award_study_level_value']['expose']['identifier'] = 'field_award_study_level_value';
  $handler->display->display_options['filters']['field_award_study_level_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Award type (field_award_type) */
  $handler->display->display_options['filters']['field_award_type_value_1']['id'] = 'field_award_type_value_1';
  $handler->display->display_options['filters']['field_award_type_value_1']['table'] = 'field_data_field_award_type';
  $handler->display->display_options['filters']['field_award_type_value_1']['field'] = 'field_award_type_value';
  $handler->display->display_options['filters']['field_award_type_value_1']['value'] = array(
    'scholarship' => 'scholarship',
    'prize' => 'prize',
    'grant' => 'grant',
  );
  $handler->display->display_options['filters']['field_award_type_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_award_type_value_1']['expose']['operator_id'] = 'field_award_type_value_1_op';
  $handler->display->display_options['filters']['field_award_type_value_1']['expose']['label'] = 'Award type';
  $handler->display->display_options['filters']['field_award_type_value_1']['expose']['operator'] = 'field_award_type_value_1_op';
  $handler->display->display_options['filters']['field_award_type_value_1']['expose']['identifier'] = 'field_award_type_value_1';
  $handler->display->display_options['filters']['field_award_type_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_award_type_value_1']['expose']['reduce'] = TRUE;

  /* Display: Block: Grants */
  $handler = $view->new_display('block', 'Block: Grants', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Grant';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['alt'] = '[body]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_class'] = 'the_column_1';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '120';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Area of study */
  $handler->display->display_options['fields']['field_award_study_area']['id'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['table'] = 'field_data_field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['field'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['label'] = 'Areas of study';
  $handler->display->display_options['fields']['field_award_study_area']['element_class'] = 'the_column_2';
  $handler->display->display_options['fields']['field_award_study_area']['empty'] = '<ul><li class="first last">Any</li></ul>';
  $handler->display->display_options['fields']['field_award_study_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_award_study_area']['delta_offset'] = '0';
  /* Field: Content: Study level */
  $handler->display->display_options['fields']['field_award_study_level']['id'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['table'] = 'field_data_field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['field'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_award_study_level']['element_wrapper_class'] = 'inline-list';
  $handler->display->display_options['fields']['field_award_study_level']['empty'] = 'All';
  $handler->display->display_options['fields']['field_award_study_level']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['delta_offset'] = '0';
  /* Field: Content: Approximate value */
  $handler->display->display_options['fields']['field_award_value']['id'] = 'field_award_value';
  $handler->display->display_options['fields']['field_award_value']['table'] = 'field_data_field_award_value';
  $handler->display->display_options['fields']['field_award_value']['field'] = 'field_award_value';
  $handler->display->display_options['fields']['field_award_value']['label'] = 'Approx value';
  $handler->display->display_options['fields']['field_award_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_value']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_value']['alter']['text'] = '<strong>Approx value:</strong> $[field_award_value]';
  $handler->display->display_options['fields']['field_award_value']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Information';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<strong>Study level:</strong> [field_award_study_level]<br/>
[field_award_value]
';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'the_column_3';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'award' => 'award',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Award type (field_award_type) */
  $handler->display->display_options['filters']['field_award_type_value']['id'] = 'field_award_type_value';
  $handler->display->display_options['filters']['field_award_type_value']['table'] = 'field_data_field_award_type';
  $handler->display->display_options['filters']['field_award_type_value']['field'] = 'field_award_type_value';
  $handler->display->display_options['filters']['field_award_type_value']['value'] = array(
    'grant' => 'grant',
  );
  $handler->display->display_options['filters']['field_award_type_value']['group'] = 1;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Block: Scholarships */
  $handler = $view->new_display('block', 'Block: Scholarships', 'block_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '120';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Scholarship';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['alt'] = '[body]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_class'] = 'the_column_1';
  /* Field: Content: Area of study */
  $handler->display->display_options['fields']['field_award_study_area']['id'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['table'] = 'field_data_field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['field'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['label'] = 'Areas of study';
  $handler->display->display_options['fields']['field_award_study_area']['element_class'] = 'the_column_2';
  $handler->display->display_options['fields']['field_award_study_area']['empty'] = '<ul><li class="first last">Any</li></ul>';
  $handler->display->display_options['fields']['field_award_study_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_award_study_area']['delta_offset'] = '0';
  /* Field: Content: Study level */
  $handler->display->display_options['fields']['field_award_study_level']['id'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['table'] = 'field_data_field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['field'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_award_study_level']['element_wrapper_class'] = 'inline-list';
  $handler->display->display_options['fields']['field_award_study_level']['empty'] = 'Any';
  $handler->display->display_options['fields']['field_award_study_level']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['delta_offset'] = '0';
  /* Field: Content: Citizenship */
  $handler->display->display_options['fields']['field_award_citizenship']['id'] = 'field_award_citizenship';
  $handler->display->display_options['fields']['field_award_citizenship']['table'] = 'field_data_field_award_citizenship';
  $handler->display->display_options['fields']['field_award_citizenship']['field'] = 'field_award_citizenship';
  $handler->display->display_options['fields']['field_award_citizenship']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_citizenship']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_citizenship']['alter']['text'] = '[field_award_citizenship]';
  $handler->display->display_options['fields']['field_award_citizenship']['element_type'] = '0';
  $handler->display->display_options['fields']['field_award_citizenship']['element_class'] = 'inline-list';
  $handler->display->display_options['fields']['field_award_citizenship']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_award_citizenship']['delta_offset'] = '0';
  /* Field: Content: Financial need */
  $handler->display->display_options['fields']['field_award_financial_need']['id'] = 'field_award_financial_need';
  $handler->display->display_options['fields']['field_award_financial_need']['table'] = 'field_data_field_award_financial_need';
  $handler->display->display_options['fields']['field_award_financial_need']['field'] = 'field_award_financial_need';
  $handler->display->display_options['fields']['field_award_financial_need']['label'] = '';
  $handler->display->display_options['fields']['field_award_financial_need']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_financial_need']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_financial_need']['alter']['text'] = '<b>Financial need:</b> [field_award_financial_need]<br />';
  $handler->display->display_options['fields']['field_award_financial_need']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_award_financial_need']['hide_empty'] = TRUE;
  /* Field: Content: Travel support */
  $handler->display->display_options['fields']['field_award_travel_support']['id'] = 'field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['table'] = 'field_data_field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['field'] = 'field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['label'] = '';
  $handler->display->display_options['fields']['field_award_travel_support']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_travel_support']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_travel_support']['alter']['text'] = '<b>Travel support:</b> [field_award_travel_support]<br />';
  $handler->display->display_options['fields']['field_award_travel_support']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_award_travel_support']['hide_empty'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Eligibility';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<b>Study level:</b> [field_award_study_level]<br />
[field_award_travel_support]
<b>Citizenship:</b> [field_award_citizenship]
';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'the_column_3';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'award' => 'award',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Award type (field_award_type) */
  $handler->display->display_options['filters']['field_award_type_value']['id'] = 'field_award_type_value';
  $handler->display->display_options['filters']['field_award_type_value']['table'] = 'field_data_field_award_type';
  $handler->display->display_options['filters']['field_award_type_value']['field'] = 'field_award_type_value';
  $handler->display->display_options['filters']['field_award_type_value']['value'] = array(
    'scholarship' => 'scholarship',
  );
  $handler->display->display_options['filters']['field_award_type_value']['group'] = 1;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['keys']['expose']['description'] = 'Enter one or more keywords to search for';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Block: Prizes */
  $handler = $view->new_display('block', 'Block: Prizes', 'block_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Prize';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['alt'] = '[body]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_class'] = 'the_column_1';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '120';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Area of study */
  $handler->display->display_options['fields']['field_award_study_area']['id'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['table'] = 'field_data_field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['field'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['label'] = 'Areas of study';
  $handler->display->display_options['fields']['field_award_study_area']['element_class'] = 'the_column_2';
  $handler->display->display_options['fields']['field_award_study_area']['empty'] = '<ul><li class="first last">Any</li></ul>';
  $handler->display->display_options['fields']['field_award_study_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_award_study_area']['delta_offset'] = '0';
  /* Field: Content: Study level */
  $handler->display->display_options['fields']['field_award_study_level']['id'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['table'] = 'field_data_field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['field'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_award_study_level']['element_wrapper_class'] = 'inline-list';
  $handler->display->display_options['fields']['field_award_study_level']['empty'] = 'Any';
  $handler->display->display_options['fields']['field_award_study_level']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['delta_offset'] = '0';
  /* Field: Content: Approximate value */
  $handler->display->display_options['fields']['field_award_value']['id'] = 'field_award_value';
  $handler->display->display_options['fields']['field_award_value']['table'] = 'field_data_field_award_value';
  $handler->display->display_options['fields']['field_award_value']['field'] = 'field_award_value';
  $handler->display->display_options['fields']['field_award_value']['label'] = 'Approx value';
  $handler->display->display_options['fields']['field_award_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_value']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_value']['alter']['text'] = '<strong>Approx value:</strong> $[field_award_value]';
  $handler->display->display_options['fields']['field_award_value']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Information';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<strong>Study level:</strong> [field_award_study_level]<br/>
[field_award_value]';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'the_column_3';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'award' => 'award',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Award type (field_award_type) */
  $handler->display->display_options['filters']['field_award_type_value']['id'] = 'field_award_type_value';
  $handler->display->display_options['filters']['field_award_type_value']['table'] = 'field_data_field_award_type';
  $handler->display->display_options['filters']['field_award_type_value']['field'] = 'field_award_type_value';
  $handler->display->display_options['filters']['field_award_type_value']['value'] = array(
    'prize' => 'prize',
  );
  $handler->display->display_options['filters']['field_award_type_value']['group'] = 1;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $export['awards'] = $view;

  return $export;
}
