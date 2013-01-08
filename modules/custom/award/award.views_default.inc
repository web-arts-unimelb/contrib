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
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
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
  /* Filter criterion: Content: Award type (field_award_type) */
  $handler->display->display_options['filters']['field_award_type_value']['id'] = 'field_award_type_value';
  $handler->display->display_options['filters']['field_award_type_value']['table'] = 'field_data_field_award_type';
  $handler->display->display_options['filters']['field_award_type_value']['field'] = 'field_award_type_value';
  $handler->display->display_options['filters']['field_award_type_value']['value'] = array(
    'prize' => 'prize',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Grant name contains';
  $handler->display->display_options['filters']['title']['expose']['description'] = 'Enter one or more keywords to search grant names';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
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
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
  /* Filter criterion: Content: Award type (field_award_type) */
  $handler->display->display_options['filters']['field_award_type_value']['id'] = 'field_award_type_value';
  $handler->display->display_options['filters']['field_award_type_value']['table'] = 'field_data_field_award_type';
  $handler->display->display_options['filters']['field_award_type_value']['field'] = 'field_award_type_value';
  $handler->display->display_options['filters']['field_award_type_value']['value'] = array(
    'scholarship' => 'scholarship',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Scholarship name contains';
  $handler->display->display_options['filters']['title']['expose']['description'] = 'Enter one or more keywords to search scholarship names';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
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
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'scholarships/prize-list';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Prizes';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Page: Scholarships */
  $handler = $view->new_display('page', 'Page: Scholarships', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Scholarships';
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
  /* Header: Entity: Rendered entity */
  $handler->display->display_options['header']['entity']['id'] = 'entity';
  $handler->display->display_options['header']['entity']['table'] = 'entity__global';
  $handler->display->display_options['header']['entity']['field'] = 'entity';
  $handler->display->display_options['header']['entity']['label'] = 'Scholarships landing page';
  $handler->display->display_options['header']['entity']['empty'] = TRUE;
  $handler->display->display_options['header']['entity']['entity_id'] = '317';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Area of study */
  $handler->display->display_options['fields']['field_award_study_area']['id'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['table'] = 'field_data_field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['field'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['label'] = 'Areas of study';
  $handler->display->display_options['fields']['field_award_study_area']['exclude'] = TRUE;
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
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Eligibility';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<b>Available to:</b> [field_award_students]<br />
<b>Citizenship requirements:</b> [field_award_citizenship]<br />
[field_award_other]
<br />
[body]';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Scholarship';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alt'] = '[nothing]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Financial need */
  $handler->display->display_options['fields']['field_award_financial_need']['id'] = 'field_award_financial_need';
  $handler->display->display_options['fields']['field_award_financial_need']['table'] = 'field_data_field_award_financial_need';
  $handler->display->display_options['fields']['field_award_financial_need']['field'] = 'field_award_financial_need';
  $handler->display->display_options['fields']['field_award_financial_need']['alter']['text'] = '<b>Financial need:</b> [field_award_financial_need]<br />';
  $handler->display->display_options['fields']['field_award_financial_need']['element_label_colon'] = FALSE;
  /* Field: Content: Study level */
  $handler->display->display_options['fields']['field_award_study_level']['id'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['table'] = 'field_data_field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['field'] = 'field_award_study_level';
  $handler->display->display_options['fields']['field_award_study_level']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_level']['alter']['text'] = '[field_award_study_level]';
  $handler->display->display_options['fields']['field_award_study_level']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_award_study_level']['empty'] = 'All';
  $handler->display->display_options['fields']['field_award_study_level']['delta_offset'] = '0';
  /* Field: Content: Travel support */
  $handler->display->display_options['fields']['field_award_travel_support']['id'] = 'field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['table'] = 'field_data_field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['field'] = 'field_award_travel_support';
  $handler->display->display_options['fields']['field_award_travel_support']['alter']['text'] = '<b>Travel support:</b> [field_award_travel_support]<br />';
  $handler->display->display_options['fields']['field_award_travel_support']['element_label_colon'] = FALSE;
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
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['title']['expose']['description'] = 'Enter one or more keywords to search scholarships';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['title']['group_info']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['group_info']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['group_info']['group_items'] = array(
    1 => array(
      'title' => '',
      'operator' => 'allwords',
      'value' => '',
    ),
    2 => array(
      'title' => '',
      'operator' => 'allwords',
      'value' => '',
    ),
    3 => array(
      'title' => '',
      'operator' => 'allwords',
      'value' => '',
    ),
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
  /* Filter criterion: Content: Financial need (field_award_financial_need) */
  $handler->display->display_options['filters']['field_award_financial_need_value']['id'] = 'field_award_financial_need_value';
  $handler->display->display_options['filters']['field_award_financial_need_value']['table'] = 'field_data_field_award_financial_need';
  $handler->display->display_options['filters']['field_award_financial_need_value']['field'] = 'field_award_financial_need_value';
  $handler->display->display_options['filters']['field_award_financial_need_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_award_financial_need_value']['expose']['operator_id'] = 'field_award_financial_need_value_op';
  $handler->display->display_options['filters']['field_award_financial_need_value']['expose']['label'] = 'Financial need';
  $handler->display->display_options['filters']['field_award_financial_need_value']['expose']['operator'] = 'field_award_financial_need_value_op';
  $handler->display->display_options['filters']['field_award_financial_need_value']['expose']['identifier'] = 'field_award_financial_need_value';
  $handler->display->display_options['filters']['field_award_financial_need_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_award_financial_need_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_award_financial_need_value']['reduce_duplicates'] = TRUE;
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
    4 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_award_study_level_value']['reduce_duplicates'] = TRUE;
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
    4 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_award_travel_support_value']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['path'] = 'scholarships';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Scholarships';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['awards'] = $view;

  return $export;
}
