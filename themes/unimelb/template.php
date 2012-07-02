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
  $variables['site_name'] = variable_get('site_name', '');
  $variables['page_title'] = check_plain(strip_tags(drupal_get_title()));
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

  if(variable_get('unimelb_settings_site-name-short') && variable_get('unimelb_settings_site-name-short', '') != ''){
    $site_name = variable_get('unimelb_settings_site-name-short');
    $vars1 = array('sitename' => $site_name);
    drupal_add_js($vars1, 'setting');
  }

  if(variable_get('unimelb_settings_parent-org-short') && variable_get('unimelb_settings_parent-org-short', '') != ''){
    $parent_org = variable_get('unimelb_settings_parent-org-short');
    $vars2 = array('parentorg' => $parent_org);
    drupal_add_js($vars2, 'setting');
  }

  if(variable_get('unimelb_settings_parent-org-url') && variable_get('unimelb_settings_parent-org-url', '') != ''){
    $parent_orgurl = variable_get('unimelb_settings_parent-org-url');
    $vars3 = array('parentorgurl' => $parent_orgurl);
    drupal_add_js($vars3, 'setting');
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
