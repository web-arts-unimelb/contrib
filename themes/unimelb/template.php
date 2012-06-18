<?php
/**
 * @file template.php
 *
 * Thanks to Aaron Tan and team at the Faculty of Architecture, Building and
 * Planning, University of Melbourne, and Paul Tagell and team at Marketing
 * and Communications, University of Melbourne - Media Insights 2011
 */

/**
 * Implements hook_preprocess_page()
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
