<?php
/**
 * @file
 * equipment.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function equipment_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'equipment';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Equipment';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Equipment';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    1 => '1',
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'body' => 'body',
    'field_equipment_type' => 'field_equipment_type',
    'title' => 'title',
    'field_equipment_image' => 'field_equipment_image',
    'field_equipment_booking_link' => 'field_equipment_booking_link',
    'field_equipment_manual' => 'field_equipment_booking_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_equipment_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_equipment_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_equipment_booking_link' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '  ',
      'empty_column' => 0,
    ),
    'field_equipment_manual' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_equipment_type']['id'] = 'field_equipment_type';
  $handler->display->display_options['fields']['field_equipment_type']['table'] = 'field_data_field_equipment_type';
  $handler->display->display_options['fields']['field_equipment_type']['field'] = 'field_equipment_type';
  $handler->display->display_options['fields']['field_equipment_type']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['alt'] = '[body]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_equipment_image']['id'] = 'field_equipment_image';
  $handler->display->display_options['fields']['field_equipment_image']['table'] = 'field_data_field_equipment_image';
  $handler->display->display_options['fields']['field_equipment_image']['field'] = 'field_equipment_image';
  $handler->display->display_options['fields']['field_equipment_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_equipment_image']['type'] = 'colorbox';
  $handler->display->display_options['fields']['field_equipment_image']['settings'] = array(
    'colorbox_node_style' => 'equipment_thumbnail',
    'colorbox_image_style' => '',
    'colorbox_gallery' => 'post',
    'colorbox_gallery_custom' => '',
    'colorbox_caption' => 'auto',
    'colorbox_caption_custom' => '',
  );
  /* Field: Content: Booking link */
  $handler->display->display_options['fields']['field_equipment_booking_link']['id'] = 'field_equipment_booking_link';
  $handler->display->display_options['fields']['field_equipment_booking_link']['table'] = 'field_data_field_equipment_booking_link';
  $handler->display->display_options['fields']['field_equipment_booking_link']['field'] = 'field_equipment_booking_link';
  $handler->display->display_options['fields']['field_equipment_booking_link']['label'] = 'Links';
  $handler->display->display_options['fields']['field_equipment_booking_link']['click_sort_column'] = 'url';
  /* Field: Content: Manual */
  $handler->display->display_options['fields']['field_equipment_manual']['id'] = 'field_equipment_manual';
  $handler->display->display_options['fields']['field_equipment_manual']['table'] = 'field_data_field_equipment_manual';
  $handler->display->display_options['fields']['field_equipment_manual']['field'] = 'field_equipment_manual';
  $handler->display->display_options['fields']['field_equipment_manual']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_equipment_manual']['alter']['text'] = 'View user manual';
  $handler->display->display_options['fields']['field_equipment_manual']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_equipment_manual']['alter']['path'] = '[field_equipment_manual-url]';
  $handler->display->display_options['fields']['field_equipment_manual']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_equipment_manual']['alter']['link_class'] = 'button';
  $handler->display->display_options['fields']['field_equipment_manual']['click_sort_column'] = 'url';
  /* Field: Content: Promoted to front page */
  $handler->display->display_options['fields']['promote']['id'] = 'promote';
  $handler->display->display_options['fields']['promote']['table'] = 'node';
  $handler->display->display_options['fields']['promote']['field'] = 'promote';
  $handler->display->display_options['fields']['promote']['label'] = 'Promoted';
  $handler->display->display_options['fields']['promote']['not'] = 0;
  /* Field: Content: Sticky */
  $handler->display->display_options['fields']['sticky']['id'] = 'sticky';
  $handler->display->display_options['fields']['sticky']['table'] = 'node';
  $handler->display->display_options['fields']['sticky']['field'] = 'sticky';
  $handler->display->display_options['fields']['sticky']['not'] = 0;
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
    'equipment' => 'equipment',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'equipment';
  $export['equipment'] = $view;

  return $export;
}
