<?php
/**
 * @file
 * uom_slider.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uom_slider_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'slider';
  $view->description = '';
  $view->tag = 'default, sliider';
  $view->base_table = 'node';
  $view->human_name = 'Slider';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_slider_pager' => 'field_slider_pager',
    'path' => 0,
    'body' => 0,
    'field_slider_image' => 0,
    'nothing' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_hover'] = 1;
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'path' => 0,
    'field_slider_pager' => 0,
    'body' => 0,
    'field_slider_image' => 0,
    'nothing' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['transition_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['fixed_height'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_slider_link_target_id']['id'] = 'field_slider_link_target_id';
  $handler->display->display_options['relationships']['field_slider_link_target_id']['table'] = 'field_data_field_slider_link';
  $handler->display->display_options['relationships']['field_slider_link_target_id']['field'] = 'field_slider_link_target_id';
  $handler->display->display_options['relationships']['field_slider_link_target_id']['label'] = 'Slider Link';
  $handler->display->display_options['relationships']['field_slider_link_target_id']['required'] = 0;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_slider_link_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['path']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['path']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['path']['alter']['external'] = 0;
  $handler->display->display_options['fields']['path']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['path']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['path']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['path']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['path']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['path']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['path']['alter']['html'] = 0;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['path']['hide_empty'] = 0;
  $handler->display->display_options['fields']['path']['empty_zero'] = 0;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['path']['absolute'] = 0;
  /* Field: Content: Pager Label */
  $handler->display->display_options['fields']['field_slider_pager']['id'] = 'field_slider_pager';
  $handler->display->display_options['fields']['field_slider_pager']['table'] = 'field_data_field_slider_pager';
  $handler->display->display_options['fields']['field_slider_pager']['field'] = 'field_slider_pager';
  $handler->display->display_options['fields']['field_slider_pager']['label'] = '';
  $handler->display->display_options['fields']['field_slider_pager']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_slider_pager']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slider_pager']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_slider_pager']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slider_pager']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slider_pager']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slider_pager']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_slider_pager']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slider_pager']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slider_pager']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slider_pager']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_slider_pager']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slider_pager']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slider_pager']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slider_pager']['element_class'] = 'pager-text';
  $handler->display->display_options['fields']['field_slider_pager']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slider_pager']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_slider_pager']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slider_pager']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slider_pager']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_slider_pager']['field_api_classes'] = 0;
  /* Field: Content: Image Caption */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_slider_image']['id'] = 'field_slider_image';
  $handler->display->display_options['fields']['field_slider_image']['table'] = 'field_data_field_slider_image';
  $handler->display->display_options['fields']['field_slider_image']['field'] = 'field_slider_image';
  $handler->display->display_options['fields']['field_slider_image']['label'] = '';
  $handler->display->display_options['fields']['field_slider_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_slider_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_slider_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slider_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slider_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slider_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slider_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slider_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_slider_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_slider_image']['settings'] = array(
    'image_style' => 'slider',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_slider_image']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_slider_image]
<div class="caption">[body]</div>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'slider-item';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
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
    'slider' => 'slider',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['slider'] = $view;

  return $export;
}
