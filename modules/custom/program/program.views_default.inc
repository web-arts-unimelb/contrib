<?php
/**
 * @file
 * program.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function program_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'profile_program_tag_test';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'profile_and_program_tag';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Feature Profile';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No joy.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Profile';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Profile image */
  $handler->display->display_options['fields']['field_profile_image']['id'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['table'] = 'field_data_field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['field'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['label'] = '';
  $handler->display->display_options['fields']['field_profile_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Job title */
  $handler->display->display_options['fields']['field_profile_jobtitle']['id'] = 'field_profile_jobtitle';
  $handler->display->display_options['fields']['field_profile_jobtitle']['table'] = 'field_data_field_profile_jobtitle';
  $handler->display->display_options['fields']['field_profile_jobtitle']['field'] = 'field_profile_jobtitle';
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['anyall'] = '+';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['vocabularies'] = array(
    'program' => 'program',
    'research_area' => 'research_area',
  );
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  $handler->display->display_options['arguments']['tid']['add_table'] = TRUE;
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = TRUE;
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
    'feature_profile' => 'feature_profile',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Job title */
  $handler->display->display_options['fields']['field_profile_jobtitle']['id'] = 'field_profile_jobtitle';
  $handler->display->display_options['fields']['field_profile_jobtitle']['table'] = 'field_data_field_profile_jobtitle';
  $handler->display->display_options['fields']['field_profile_jobtitle']['field'] = 'field_profile_jobtitle';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Profile';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Profile image */
  $handler->display->display_options['fields']['field_profile_image']['id'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['table'] = 'field_data_field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['field'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['label'] = '';
  $handler->display->display_options['fields']['field_profile_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $export['profile_program_tag_test'] = $view;

  $view = new view();
  $view->name = 'programs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Programs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Programs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_fee_domestic' => 'field_fee_domestic',
    'field_fee_international' => 'field_fee_international',
    'field_austudy' => 'field_austudy',
    'field_commonwealth_supported' => 'field_commonwealth_supported',
    'field_fee_help' => 'field_fee_help',
    'field_graduate_access' => 'field_graduate_access',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_fee_domestic' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_fee_international' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_austudy' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_commonwealth_supported' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_fee_help' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_graduate_access' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Program';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_fee_domestic']['id'] = 'field_fee_domestic';
  $handler->display->display_options['fields']['field_fee_domestic']['table'] = 'field_data_field_fee_domestic';
  $handler->display->display_options['fields']['field_fee_domestic']['field'] = 'field_fee_domestic';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_fee_international']['id'] = 'field_fee_international';
  $handler->display->display_options['fields']['field_fee_international']['table'] = 'field_data_field_fee_international';
  $handler->display->display_options['fields']['field_fee_international']['field'] = 'field_fee_international';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_austudy']['id'] = 'field_austudy';
  $handler->display->display_options['fields']['field_austudy']['table'] = 'field_data_field_austudy';
  $handler->display->display_options['fields']['field_austudy']['field'] = 'field_austudy';
  $handler->display->display_options['fields']['field_austudy']['label'] = 'Austudy';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_commonwealth_supported']['id'] = 'field_commonwealth_supported';
  $handler->display->display_options['fields']['field_commonwealth_supported']['table'] = 'field_data_field_commonwealth_supported';
  $handler->display->display_options['fields']['field_commonwealth_supported']['field'] = 'field_commonwealth_supported';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_fee_help']['id'] = 'field_fee_help';
  $handler->display->display_options['fields']['field_fee_help']['table'] = 'field_data_field_fee_help';
  $handler->display->display_options['fields']['field_fee_help']['field'] = 'field_fee_help';
  $handler->display->display_options['fields']['field_fee_help']['label'] = 'Fee help';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_graduate_access']['id'] = 'field_graduate_access';
  $handler->display->display_options['fields']['field_graduate_access']['table'] = 'field_data_field_graduate_access';
  $handler->display->display_options['fields']['field_graduate_access']['field'] = 'field_graduate_access';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_career_outcomes_tid']['id'] = 'field_career_outcomes_tid';
  $handler->display->display_options['arguments']['field_career_outcomes_tid']['table'] = 'field_data_field_career_outcomes';
  $handler->display->display_options['arguments']['field_career_outcomes_tid']['field'] = 'field_career_outcomes_tid';
  $handler->display->display_options['arguments']['field_career_outcomes_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_career_outcomes_tid']['title'] = 'Programs for %1';
  $handler->display->display_options['arguments']['field_career_outcomes_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_career_outcomes_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_career_outcomes_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_career_outcomes_tid']['summary_options']['items_per_page'] = '25';
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
    'program' => 'program',
  );
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_austudy_value']['id'] = 'field_austudy_value';
  $handler->display->display_options['filters']['field_austudy_value']['table'] = 'field_data_field_austudy';
  $handler->display->display_options['filters']['field_austudy_value']['field'] = 'field_austudy_value';
  $handler->display->display_options['filters']['field_austudy_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_austudy_value']['expose']['operator_id'] = 'field_austudy_value_op';
  $handler->display->display_options['filters']['field_austudy_value']['expose']['label'] = 'Austudy?';
  $handler->display->display_options['filters']['field_austudy_value']['expose']['operator'] = 'field_austudy_value_op';
  $handler->display->display_options['filters']['field_austudy_value']['expose']['identifier'] = 'field_austudy_value';
  $handler->display->display_options['filters']['field_austudy_value']['expose']['remember'] = TRUE;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_commonwealth_supported_value']['id'] = 'field_commonwealth_supported_value';
  $handler->display->display_options['filters']['field_commonwealth_supported_value']['table'] = 'field_data_field_commonwealth_supported';
  $handler->display->display_options['filters']['field_commonwealth_supported_value']['field'] = 'field_commonwealth_supported_value';
  $handler->display->display_options['filters']['field_commonwealth_supported_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_commonwealth_supported_value']['expose']['operator_id'] = 'field_commonwealth_supported_value_op';
  $handler->display->display_options['filters']['field_commonwealth_supported_value']['expose']['label'] = 'Supported?';
  $handler->display->display_options['filters']['field_commonwealth_supported_value']['expose']['operator'] = 'field_commonwealth_supported_value_op';
  $handler->display->display_options['filters']['field_commonwealth_supported_value']['expose']['identifier'] = 'field_commonwealth_supported_value';
  $handler->display->display_options['filters']['field_commonwealth_supported_value']['expose']['remember'] = TRUE;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_fee_help_value']['id'] = 'field_fee_help_value';
  $handler->display->display_options['filters']['field_fee_help_value']['table'] = 'field_data_field_fee_help';
  $handler->display->display_options['filters']['field_fee_help_value']['field'] = 'field_fee_help_value';
  $handler->display->display_options['filters']['field_fee_help_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_fee_help_value']['expose']['operator_id'] = 'field_fee_help_value_op';
  $handler->display->display_options['filters']['field_fee_help_value']['expose']['label'] = 'Fee help?';
  $handler->display->display_options['filters']['field_fee_help_value']['expose']['operator'] = 'field_fee_help_value_op';
  $handler->display->display_options['filters']['field_fee_help_value']['expose']['identifier'] = 'field_fee_help_value';
  $handler->display->display_options['filters']['field_fee_help_value']['expose']['remember'] = TRUE;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_graduate_access_value']['id'] = 'field_graduate_access_value';
  $handler->display->display_options['filters']['field_graduate_access_value']['table'] = 'field_data_field_graduate_access';
  $handler->display->display_options['filters']['field_graduate_access_value']['field'] = 'field_graduate_access_value';
  $handler->display->display_options['filters']['field_graduate_access_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_graduate_access_value']['expose']['operator_id'] = 'field_graduate_access_value_op';
  $handler->display->display_options['filters']['field_graduate_access_value']['expose']['label'] = 'Graduate?';
  $handler->display->display_options['filters']['field_graduate_access_value']['expose']['operator'] = 'field_graduate_access_value_op';
  $handler->display->display_options['filters']['field_graduate_access_value']['expose']['identifier'] = 'field_graduate_access_value';
  $handler->display->display_options['filters']['field_graduate_access_value']['expose']['remember'] = TRUE;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_career_outcomes_tid']['id'] = 'field_career_outcomes_tid';
  $handler->display->display_options['filters']['field_career_outcomes_tid']['table'] = 'field_data_field_career_outcomes';
  $handler->display->display_options['filters']['field_career_outcomes_tid']['field'] = 'field_career_outcomes_tid';
  $handler->display->display_options['filters']['field_career_outcomes_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_career_outcomes_tid']['expose']['operator_id'] = 'field_career_outcomes_tid_op';
  $handler->display->display_options['filters']['field_career_outcomes_tid']['expose']['label'] = 'Career Outcomes?';
  $handler->display->display_options['filters']['field_career_outcomes_tid']['expose']['operator'] = 'field_career_outcomes_tid_op';
  $handler->display->display_options['filters']['field_career_outcomes_tid']['expose']['identifier'] = 'field_career_outcomes_tid';
  $handler->display->display_options['filters']['field_career_outcomes_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_career_outcomes_tid']['expose']['multiple'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'program' => 'program',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'program';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Program List';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Metadata */
  $handler = $view->new_display('block', 'Metadata', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Metadata';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_fee_domestic']['id'] = 'field_fee_domestic';
  $handler->display->display_options['fields']['field_fee_domestic']['table'] = 'field_data_field_fee_domestic';
  $handler->display->display_options['fields']['field_fee_domestic']['field'] = 'field_fee_domestic';
  $handler->display->display_options['fields']['field_fee_domestic']['label'] = '';
  $handler->display->display_options['fields']['field_fee_domestic']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fee_domestic']['alter']['text'] = 'Fee: [field_fee_domestic] (Domestic)';
  $handler->display->display_options['fields']['field_fee_domestic']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_fee_international']['id'] = 'field_fee_international';
  $handler->display->display_options['fields']['field_fee_international']['table'] = 'field_data_field_fee_international';
  $handler->display->display_options['fields']['field_fee_international']['field'] = 'field_fee_international';
  $handler->display->display_options['fields']['field_fee_international']['label'] = 'Fees';
  $handler->display->display_options['fields']['field_fee_international']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_fee_international']['alter']['text'] = '[field_fee_domestic] (Domestic)<br />
[field_fee_international] (International)';
  $handler->display->display_options['fields']['field_fee_international']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_austudy']['id'] = 'field_austudy';
  $handler->display->display_options['fields']['field_austudy']['table'] = 'field_data_field_austudy';
  $handler->display->display_options['fields']['field_austudy']['field'] = 'field_austudy';
  $handler->display->display_options['fields']['field_austudy']['label'] = '';
  $handler->display->display_options['fields']['field_austudy']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_austudy']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_commonwealth_supported']['id'] = 'field_commonwealth_supported';
  $handler->display->display_options['fields']['field_commonwealth_supported']['table'] = 'field_data_field_commonwealth_supported';
  $handler->display->display_options['fields']['field_commonwealth_supported']['field'] = 'field_commonwealth_supported';
  $handler->display->display_options['fields']['field_commonwealth_supported']['label'] = '';
  $handler->display->display_options['fields']['field_commonwealth_supported']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_commonwealth_supported']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_fee_help']['id'] = 'field_fee_help';
  $handler->display->display_options['fields']['field_fee_help']['table'] = 'field_data_field_fee_help';
  $handler->display->display_options['fields']['field_fee_help']['field'] = 'field_fee_help';
  $handler->display->display_options['fields']['field_fee_help']['label'] = '';
  $handler->display->display_options['fields']['field_fee_help']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fee_help']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_graduate_access']['id'] = 'field_graduate_access';
  $handler->display->display_options['fields']['field_graduate_access']['table'] = 'field_data_field_graduate_access';
  $handler->display->display_options['fields']['field_graduate_access']['field'] = 'field_graduate_access';
  $handler->display->display_options['fields']['field_graduate_access']['label'] = 'Support';
  $handler->display->display_options['fields']['field_graduate_access']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_graduate_access']['alter']['text'] = 'Austudy?  <strong>[field_austudy]</strong><br />
Commonwealth?  <strong>[field_commonwealth_supported]</strong><br />
Fee help?   <strong>[field_fee_help]</strong><br />
Graduate access?  <strong>[field_graduate_access]</strong><br />';
  $handler->display->display_options['fields']['field_graduate_access']['element_label_colon'] = FALSE;
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

  /* Display: Careers by Program */
  $handler = $view->new_display('block', 'Careers by Program', 'block_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'careers-by-program-row';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'http://gshss.dev.arts.unimelb.edu.au/#';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_career_outcomes']['id'] = 'field_career_outcomes';
  $handler->display->display_options['fields']['field_career_outcomes']['table'] = 'field_data_field_career_outcomes';
  $handler->display->display_options['fields']['field_career_outcomes']['field'] = 'field_career_outcomes';
  $handler->display->display_options['fields']['field_career_outcomes']['label'] = '';
  $handler->display->display_options['fields']['field_career_outcomes']['element_label_colon'] = FALSE;
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
    'program' => 'program',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $export['programs'] = $view;

  return $export;
}
