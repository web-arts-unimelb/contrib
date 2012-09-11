<?php
/**
 * @file template.php
 *
 * Thanks to Aaron Tan and team at the Faculty of Architecture, Building and
 * Planning, University of Melbourne, and Paul Tagell and team at Marketing
 * and Communications, University of Melbourne - Media Insights 2011
 */

/**
 * Implements hook_preprocess_html().
 */
function unimelb_preprocess_html(&$variables) {
  $variables['site_name'] = _unimelb_space_tags(variable_get('site_name'));
  $variables['page_title'] = _unimelb_space_tags(drupal_get_title());

  if (empty($variables['page_title'])) {
    $variables['page_title'] = $variables['site_name'];
  }

  // Body class that is used by templates to show or not show the university logo.
  $variables['brand_logo'] = theme_get_setting('unimelb_settings_custom_logo') ? 'logo' : 'no-logo';

  // Generate the meta tag content here, simply print the content in the tpl.php.
  if ($keywords = theme_get_setting('unimelb_settings_meta-keywords')) {
    $keywords[] = theme_get_setting('unimelb_settings_meta-keywords');
  }
  $keywords[] = $variables['page_title'];
  $keywords[] = $variables['site_name'];
  $variables['unimelb_meta_keywords']  = implode(', ', $keywords);

  $variables['unimelb_meta_description'] = $variables['site_name'] . ': ' . $variables['page_title'];
  if ($variables['is_front'] && $description = theme_get_setting('unimelb_settings_ht-right')) {
    $variables['unimelb_meta_description'] .= ' - ' . $description;
  }

  if ($creator = theme_get_setting('unimelb_settings_maint-name')) {
    $creators[] = theme_get_setting('unimelb_settings_maint-name');
  }
  $creators[] = $variables['site_name'];
  $variables['unimelb_meta_creator'] = implode(', ', $creators);

  $variables['unimelb_meta_authoriser'] = theme_get_setting('unimelb_settings_auth-name');

  $variables['unimelb_meta_email'] = theme_get_setting('unimelb_settings_ad-email');

  $variables['unimelb_meta_date'] = theme_get_setting('unimelb_settings_date-created');
  if (empty($variables['unimelb_meta_date'])) {
    $variables['unimelb_meta_date'] = format_date(time(), 'custom', 'Y-m-d');
  }

  // Including injector CSS and JS via HTTP throws up a warning if the site is
  // on HTTPS. Detect and adjust the protocol accordingly.
  global $is_https;

  $variables['protocol'] = 'http://';

  if ($is_https) {
    $variables['protocol'] = 'https://';
  }
}

/**
 * Implements hook_preprocess_page().
 *
 * Use as a wrapper function. This runs on each request anyway and this way
 * I can test for syntax errors via the CLI without getting a bunch of
 * undefined function errors.
 */
function unimelb_preprocess_page(&$variables) {

  /**
   * If looking at a node with a redirect field, redirect now. Not later.
   */
  if (isset($variables['node']) && !empty($variables['node']->field_external_url[$variables['node']->language][0])) {
    if (valid_url($variables['node']->field_external_url[$variables['node']->language][0]['safe_value'])) {
      header("Location: {$variables['node']->field_external_url[$variables['node']->language][0]['safe_value']}");
      die;
    }
  }

  /**
   * making Unimelb Settings variables available to js
   */
  // Body class that is used by templates to show or not show the university logo.
  $variables['brand_logo'] = theme_get_setting('unimelb_settings_custom_logo', '') ? 'logo' : 'no-logo';

  $variables['unimelb_ht_right'] = theme_get_setting('unimelb_settings_ht-right', '');
  $variables['unimelb_ht_left'] = theme_get_setting('unimelb_settings_ht-left', '');

  $vars = array();
  if ($value = theme_get_setting('unimelb_settings_site-name-short')){
    $vars['sitename'] = $variables['unimelb_site_name_short'] = $value;
  }

  if ($value = theme_get_setting('unimelb_settings_parent-org-short')) {
    $vars['parentorg'] = $variables['unimelb_parent_org_short'] = $value;
  }

  if ($value = theme_get_setting('unimelb_settings_parent-org-url')) {
    $vars['parentorgurl'] = $variables['unimelb_parent_org_url'] = $value;
  }

  if (!empty($vars)) {
    drupal_add_js($vars, 'setting');
  }
}

/**
 * Implements theme_date_display_range()
 *
 * Returns HTML for a date element formatted as a range. Override for
 * the theme function in date.module to output according to the UoM
 * style guide.
 */
function unimelb_date_display_range($variables) {
  $date1 = $variables['date1'];
  $date2 = $variables['date2'];
  $timezone = $variables['timezone'];
  $attributes_start = $variables['attributes_start'];
  $attributes_end = $variables['attributes_end'];

  // Wrap the result with the attributes.
  return t('!start-date–!end-date', array(
    '!start-date' => '<span class="date-display-start"' . drupal_attributes($attributes_start) . '>' . $date1 . '</span>',
    '!end-date' => '<span class="date-display-end"' . drupal_attributes($attributes_end) . '>' . $date2 . $timezone .'</span>',
  ));
}

/*
 * Implements theme_colorbox_imagefield().
 *
 * @param $variables
 *   An associative array containing:
 *   - image: image item as array.
 *   - path: The path of the image that should be displayed in the Colorbox.
 *   - title: The title text that will be used as a caption in the Colorbox.
 *   - gid: Gallery id for Colorbox image grouping.
 */
function unimelb_colorbox_imagefield($variables) {
  $class = array('colorbox', $variables['gid']);

  if ($variables['image']['style_name'] == 'hide') {
    $image = '';
    $class[] = 'js-hide';
  }
  else if (!empty($variables['image']['style_name'])) {
    $image = theme('image_style', $variables['image']);
  }
  else {
    $image = theme('image', $variables['image']);
  }

  $options = array(
    'html' => TRUE,
    'attributes' => array(
      'title' => $variables['title'],
      'class' => implode(' ', $class),
      'rel' => $variables['gid'],
    )
  );

  return l($image, $variables['path'], $options);
}

/**
 * Implements hook_preprocess_views_view_grid().
 *
 * Our own implementation removes the complete.css grid class names from
 * the views grid and uses different ones instead.
 *
 * Specifically: col-N => view-col-N
 */
function unimelb_preprocess_views_view_grid(&$vars) {
  $columns = isset($vars['options']['columns']) ? $vars['options']['columns'] : $vars['view']->style_options['columns'];
  $replace = array();
  for ($i = 1; $i <= $columns; $i++) {
    $replace['col-'. $i .' '] = 'view-col-' . $i . ' ';
    $replace['col-'. $i] = 'view-col-' . $i;
  }

  foreach ($vars['column_classes'] as &$row) {
    foreach ($row as $column => &$classes) {
      $classes = strtr($classes, $replace);
    }
  }
}

/**
 * Helper to replace tags in page title with spaces.
 *
 * This is the last function in this file because the ?> tag in the regex
 * upsets the syntax hilighter.
 *
 * @param $text
 *   A string.
 *
 * @return
 *   A string without HTML tags.
 */
function _unimelb_space_tags($text) {
  // May contain encoded entities from drupal_get_title().
  $text = html_entity_decode($text);
  $text = preg_replace('/<[^>]*?>/', ' ', $text);
  return check_plain($text);
}


