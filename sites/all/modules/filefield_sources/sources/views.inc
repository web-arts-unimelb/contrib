<?php

/**
 * @file
 * A FileField extension to allow referencing of existing files, search data
 * using views (customizable by UI).
 *
 * The "hooks" in this file are not true hooks, they're called individually
 * from the main filefield_sources.module in the corresponding hook by the
 * same name. Any of these hooks could be broken out into a separate module.
 */

/**
 * Implements hook_filefield_source_info().
 */
function filefield_source_views_info() {
  $source = array();
  $source['views'] = array(
    'name' => t('Reference existing, search by views'),
    'label' => t('Reference existing, search by views'),
    'description' => t('Use a views to search file to add.'),
    'process' => 'filefield_source_views_process',
    'value' => 'filefield_source_views_value',
  );
  return $source;
}

/**
 * Implements hook_theme().
 */
function filefield_source_views_theme() {
  return array(
    'filefield_source_views_element' => array(
      'render element' => 'element',
      'file' => 'sources/views.inc',
    ),
 );
}

/**
 * Implements hook_filefield_source_settings().
 */
function filefield_source_views_settings($op, $instance) {
  $return = array();

  if ($op == 'form') {
    if (!empty($instance['widget']['settings']['filefield_sources']['views'])) {
      $settings = $instance['widget']['settings']['filefield_sources']['views'];
    }
    else {
      $settings = array('views_filter' => 0);
    }

    $return['views'] = array(
      '#title' => t('Views reference options'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    // Populate views options
    $options = array();
    foreach (views_get_all_views() as $id => $view) {
      $options[$id] = $view->human_name ? $view->human_name : $id;
    }

    // Choise views to use to search image
    $return['views']['views_filter'] = array(
      '#title' => t('View to search image'),
      '#type' => 'select',
      '#options' => $options,
      '#empty_option' => '<' . t('no search') . '>',
      '#default_value' => $settings['views_filter'],
      '#description' => t('The views used to search image will be inserto in the content.'),
      '#weight' => 15,
    );
  }
  elseif ($op == 'save') {
    $return = array(
      'views' => array(
        'views_filter' => 0
      ),
    );
  }

  return $return;
}

/**
 * A #process callback to extend the filefield_widget element type.
 */
function filefield_source_views_process($element, &$form_state, $form) {
  $instance = field_widget_instance($element, $form_state);
  $settings = $instance['widget']['settings']['filefield_sources']['views'];

  $element['filefield_views'] = array(
    // TODO: check if required
    // '#access' => empty($element['fid']['#value']),
    '#settings' => $settings,
    '#weight' => 100.5,
    '#theme' => 'filefield_source_views_element',
    '#filefield_source' => TRUE, // Required for proper theming.
    '#attached' => array(
      'js' => array(
        drupal_get_path('module', 'filefield_sources') . '/js/views.js',
      ),
    ),
  );

  $element['filefield_views']['imagefid'] = array(
    '#type' => 'textfield',
  );

  $element['filefield_views']['select'] = array(
    '#name' => implode('_', $element['#array_parents']) . '_imagefid_select',
    '#type' => 'submit',
    '#value' => t('Select'),
    '#validate' => array(),
    '#submit' => array('filefield_sources_field_submit'),
    '#name' => $element['#name'] . '[filefield_views][button]',
    '#limit_validation_errors' => array($element['#parents']),
    '#ajax' => array(
      'path' => 'file/ajax/' . implode('/', $element['#array_parents']) . '/' . $form['form_build_id']['#value'],
      'wrapper' => $element['#id'] . '-ajax-wrapper',
      'effect' => 'fade',
    ),
  );

  return $element;
}

/**
 * A #filefield_value_callback function.
 */
function filefield_source_views_value($element, &$item) {
  if (isset($item['filefield_views']['imagefid'])) {
    $matches = array();
    if (preg_match('/\[fid:(\d+)\]/', $item['filefield_views']['imagefid'], $matches)) {
      $fid = $matches[1];
      if ($file = file_load($fid)) {

        // Run all the normal validations, minus file size restrictions.
        if (isset($element['#upload_validators']['file_validate_size'])) {
          unset($element['#upload_validators']['file_validate_size']);
        }

        if (filefield_sources_element_validate($element, (object) $file)) {
          $item = array_merge($item, (array) $file);
        }
      }
      else {
        form_error($element, t('The file could not be used because the file does not exist in the database.'));
      }
    }
    // No matter what happens, clear the value from the autocomplete.
    $item['filefield_views']['imagefid'] = '';
  }
}

/**
 * Theme the output of the field.
 */
function theme_filefield_source_views_element($variables) {
  $element = $variables['element'];

  $element['imagefid']['#field_suffix'] = drupal_render($element['select']);

  if (empty($element['#settings']['views_filter'])) {
    drupal_set_message(t('You need to configure a view to list images on this field.'), 'error');
    return;
  }

  // Load the view
  $view = views_get_view($element['#settings']['views_filter']);
  $view->set_use_ajax(TRUE); // Use AJAX

  // Generate output
  return '<div class="filefield-source filefield-source-views clear-block">' .
           '<div class="field-container">' . drupal_render($element['imagefid'])  . '</div>' .
           '<div>' . $view->render() . '</div>' .
         '</div>';
}
