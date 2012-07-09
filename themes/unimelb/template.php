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
  $variables['site_name'] = _unimelb_space_tags(variable_get('site_name', ''));
  $variables['page_title'] = _unimelb_space_tags(drupal_get_title());
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
 * Implements hook_preprocess_views_view_grid().
 *
 * Our own implementation removes the injectors grid class names from the
 * views grid and uses different ones instead.
 *
 * Specifically: col-N => views-col-N
 */
function unimelb_preprocess_views_view_grid(&$vars) {
  $view     = $vars['view'];
  $result   = $view->result;
  $options  = $view->style_plugin->options;
  $handler  = $view->style_plugin;
  $default_row_class = isset($options['default_row_class']) ? $options['default_row_class'] : TRUE;
  $row_class_special = isset($options['row_class_special']) ? $options['row_class_special'] : TRUE;

  $columns  = $options['columns'];

  $rows = array();
  $row_indexes = array();

  if ($options['alignment'] == 'horizontal') {
    $row = array();
    $col_count = 0;
    $row_count = 0;
    $count = 0;
    foreach ($vars['rows'] as $row_index => $item) {
      $count++;
      $row[] = $item;
      $row_indexes[$row_count][$col_count] = $row_index;
      $col_count++;
      if ($count % $columns == 0) {
        $rows[] = $row;
        $row = array();
        $col_count = 0;
        $row_count++;
      }
    }
    if ($row) {
      // Fill up the last line only if it's configured, but this is default.
      if (!empty($handler->options['fill_single_line']) && count($rows)) {
        for ($i = 0; $i < ($columns - $col_count); $i++) {
          $row[] = '';
        }
      }
      $rows[] = $row;
    }
  }
  else {
    $num_rows = floor(count($vars['rows']) / $columns);
    // The remainders are the 'odd' columns that are slightly longer.
    $remainders = count($vars['rows']) % $columns;
    $row = 0;
    $col = 0;
    foreach ($vars['rows'] as $count => $item) {
      $rows[$row][$col] = $item;
      $row_indexes[$row][$col] = $count;
      $row++;

      if (!$remainders && $row == $num_rows) {
        $row = 0;
        $col++;
      }
      elseif ($remainders && $row == $num_rows + 1) {
        $row = 0;
        $col++;
        $remainders--;
      }
    }
    for ($i = 0; $i < count($rows[0]); $i++) {
      // This should be string so that's okay :)
      if (!isset($rows[count($rows) - 1][$i])) {
        $rows[count($rows) - 1][$i] = '';
      }
    }
  }

  // Apply the row classes
  foreach ($rows as $row_number => $row) {
    $row_classes = array();
    if ($default_row_class) {
      $row_classes[] =  'row-' . ($row_number + 1);
    }
    if ($row_class_special) {
      if ($row_number == 0) {
        $row_classes[] =  'row-first';
      }
      if (count($rows) == ($row_number + 1)) {
        $row_classes[] =  'row-last';
      }
    }
    $vars['row_classes'][$row_number] = implode(' ', $row_classes);
    foreach ($rows[$row_number] as $column_number => $item) {
      $column_classes = array();
      if ($default_row_class) {
        $column_classes[] = 'view-col-' . ($column_number + 1);
      }
      if ($row_class_special) {
        if ($column_number == 0) {
          $column_classes[] = 'col-first';
        }
        elseif (count($rows[$row_number]) == ($column_number + 1)) {
          $column_classes[] = 'col-last';
        }
      }
      if (isset($row_indexes[$row_number][$column_number]) && $column_class = $view->style_plugin->get_row_class($row_indexes[$row_number][$column_number])) {
        $column_classes[] = $column_class;
      }
      $vars['column_classes'][$row_number][$column_number] = implode(' ', $column_classes);
    }
  }
  $vars['rows'] = $rows;
  $vars['class'] = 'views-view-grid cols-' . $columns;
  if (!empty($handler->options['summary'])) {
    $vars['attributes_array'] = array('summary' => $handler->options['summary']);
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


