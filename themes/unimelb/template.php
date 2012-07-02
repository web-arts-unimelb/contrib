<?php
/**
 * @file template.php
 *
 * Thanks to Aaron Tan and team at the Faculty of Architecture, Building and
 * Planning, University of Melbourne, and Paul Tagell and team at Marketing
 * and Communications, University of Melbourne - Media Insights 2011
 */

/**
*  * Implements hook_element_info().
*   */
function unimelb_element_info() {
  $types['theme_styles'] = array(
    '#items' => array(),
    '#pre_render' => array('drupal_pre_render_styles'),
    '#group_callback' => 'drupal_group_css',
    '#aggregate_callback' => 'drupal_aggregate_css',
  );
  return $types;
}

/**
 * Implements hook_css_alter().
 */
function unimelb_css_alter(&$css) {
  // Remove theme-specific CSS.
  foreach ($css as $key => $item) {
    if ($item['group'] == CSS_THEME) {
      unset($css[$key]);
    }
  }
}

/**
 * Implements hook_preprocess_html().
 */
function unimelb_preprocess_html(&$variables) {
  $variables['site_name'] = variable_get('site_name', '');
  $variables['page_title'] = check_plain(strip_tags(drupal_get_title()));

  $variables['theme_styles'] = unimelb_get_css(CSS_THEME);
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


/**
 * Return CSS from a specific group only.
 *
 * Based on drupal_get_css().
 */
function unimelb_get_css($group = CSS_THEME) {
  $css = drupal_add_css();

  // Sort CSS items, so that they appear in the correct order.
  uasort($css, 'drupal_sort_css_js');

  if (!empty($css)) {
    // Cast the array to an object to be on the safe side even if not empty.
    $setting['ajaxPageState']['css'] = (object) array_fill_keys(array_keys($css), 1);
  }

  // Remove the overridden CSS files. Later CSS files override former ones.
  $previous_item = array();
  foreach ($css as $key => $item) {
    // Do not process if not in the correct group.
    if ($item['group'] != $group) {
      unset($css[$key]);
      continue;
    }
    if ($item['type'] == 'file') {
      // If defined, force a unique basename for this file.
      $basename = isset($item['basename']) ? $item['basename'] : drupal_basename($item['data']);
      if (isset($previous_item[$basename])) {
        // Remove the previous item that shared the same base name.
        unset($css[$previous_item[$basename]]);
      }
      $previous_item[$basename] = $key;
    }
  }

  // Render the HTML needed to load the CSS.
  $styles = array(
    '#type' => 'theme_styles',
    '#items' => $css,
  );

  if (!empty($setting)) {
    $styles['#attached']['js'][] = array(
      'type' => 'setting',
      'data' => $setting,
    );
  }

  return drupal_render($styles);
}

