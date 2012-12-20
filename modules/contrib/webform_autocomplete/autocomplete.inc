<?php

/**
 * @file
 * Autocomplete component.
 */

// We treat textfield as a sort of "parent class"
module_load_include('inc', 'webform', 'components/textfield');

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_autocomplete() {
  return array(
    'name' => '',
    'form_key' => NULL,
    'pid' => 0,
    'weight' => 0,
    'value' => '',
    'mandatory' => 0,
    'extra' => array(
      'items' => '',
      'width' => '',
      'field_prefix' => '',
      'field_suffix' => '',
      'unique' => 0,
      'autocomplete_existing' => 0,
      'autocomplete_restrict' => 0,
      'title_display' => 0,
      'description' => '',
      'attributes' => array(),
      'private' => FALSE,
    ),
  );
}

/**
 * Implements _webform_edit_component().
 */
function _webform_edit_autocomplete($component) {
  $form = array();
  $form['value'] = array(
    '#type' => 'textfield',
    '#title' => t('Default value'),
    '#default_value' => $component['value'],
    '#description' => t('The default value of the field.') . theme('webform_token_help'),
    '#size' => 60,
    '#maxlength' => 1024,
    '#weight' => 0,
  );
  $form['options']['items'] = array(
    '#type' => 'textarea',
    '#title' => t('Options'),
    '#default_value' => $component['extra']['items'],
    '#description' => t('One value per line. Unlike select elements, this field does not use key|value pairs - enter values only.'),
    '#cols' => 60,
    '#rows' => 5,
    '#weight' => 0,
    '#required' => FALSE,
    '#wysiwyg' => FALSE,
    '#parents' => array('extra', 'items'),
  );
  $form['display']['width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#default_value' => $component['extra']['width'],
    '#description' => t('Width of the textfield.') . ' ' . t('Leaving blank will use the default size.'),
    '#size' => 5,
    '#maxlength' => 10,
    '#weight' => 0,
    '#parents' => array('extra', 'width'),
  );
  $form['display']['field_prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('Label placed to the left of the textfield'),
    '#default_value' => $component['extra']['field_prefix'],
    '#description' => t('Examples: $, #, -.'),
    '#size' => 20,
    '#maxlength' => 127,
    '#weight' => 1.1,
    '#parents' => array('extra', 'field_prefix'),
  );
  $form['display']['field_suffix'] = array(
    '#type' => 'textfield',
    '#title' => t('Label placed to the right of the textfield'),
    '#default_value' => $component['extra']['field_suffix'],
    '#description' => t('Examples: lb, kg, %.'),
    '#size' => 20,
    '#maxlength' => 127,
    '#weight' => 1.2,
    '#parents' => array('extra', 'field_suffix'),
  );
  $form['options']['autocomplete_existing'] = array(
    '#type' => 'checkbox',
    '#title' => t('Autocomplete from existing submissions'),
    '#return_value' => 1,
    '#description' => t('Autocomplete values from previous form submissions. If options are entered above, autocomplete will select from both.'),
    '#weight' => 1,
    '#default_value' => $component['extra']['autocomplete_existing'],
    '#parents' => array('extra', 'autocomplete_existing'),
  );
  $form['validation']['unique'] = array(
    '#type' => 'checkbox',
    '#title' => t('Unique'),
    '#return_value' => 1,
    '#description' => t('Require all entered values for this field to be unique. The same value will not autocomplete twice.'),
    '#weight' => 1,
    '#default_value' => $component['extra']['unique'],
    '#parents' => array('extra', 'unique'),
  );
  $form['validation']['autocomplete_restrict'] = array(
    '#type' => 'checkbox',
    '#title' => t('Restrict to listed values'),
    '#return_value' => 1,
    '#description' => t('Only allow options entered here to be chosen. Other input will be rejected.'),
    '#weight' => 1,
    '#default_value' => $component['extra']['autocomplete_restrict'],
    '#parents' => array('extra', 'autocomplete_restrict'),
  );
  $form['#validate'][] = '_webform_autocomplete_admin_validate';
  return $form;
}

/**
 * Validation callback for component edit form.
 */
function _webform_autocomplete_admin_validate($form, &$form_state) {
  $extra = $form_state['values']['extra'];
  if ($extra['autocomplete_restrict'] && !$extra['items']) {
    form_error($form['validation']['autocomplete_restrict'], t('You have chosen to restrict submissions to listed options, but have not entered any options.'));
  }
  if ($extra['autocomplete_restrict'] && $extra['autocomplete_existing']) {
    form_error($form['validation']['autocomplete_restrict'], t('You cannot choose both "Restrict to listed values" and "Autocomplete from existing submissions."'));
  }
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_autocomplete($component, $value = NULL, $filter = TRUE) {
  $node = isset($component['nid']) ? node_load($component['nid']) : NULL;

  $element = array(
    '#type' => 'textfield',
    '#title' => $filter ? _webform_filter_xss($component['name']) : $component['name'],
    '#title_display' => $component['extra']['title_display'] ? $component['extra']['title_display'] : 'before',
    '#default_value' => $filter ? _webform_filter_values($component['value'], $node, NULL, NULL, FALSE) : $component['value'],
    '#required' => $component['mandatory'],
    '#weight' => $component['weight'],
    '#field_prefix' => empty($component['extra']['field_prefix']) ? NULL : ($filter ? _webform_filter_xss($component['extra']['field_prefix']) : $component['extra']['field_prefix']),
    '#field_suffix' => empty($component['extra']['field_suffix']) ? NULL : ($filter ? _webform_filter_xss($component['extra']['field_suffix']) : $component['extra']['field_suffix']),
    '#description' => $filter ? _webform_filter_descriptions($component['extra']['description'], $node) : $component['extra']['description'],
    '#attributes' => $component['extra']['attributes'],
    '#theme_wrappers' => array('webform_element'),
    '#translatable' => array('title', 'description', 'field_prefix', 'field_suffix'),
  );
  // Autocomplete callback
  if ($node && !empty($component['cid'])) {
    $element['#autocomplete_path'] = 'webform_autocomplete/js/' . $node->nid . '/' . $component['cid'];
  }

  // Enforce uniqueness.
  if ($component['extra']['unique']) {
    $element['#element_validate'][] = 'webform_validate_unique';
  }

  // Restrict to listed options.
  if ($component['extra']['autocomplete_restrict']) {
    $element['#element_validate'][] = 'webform_autocomplete_validate_restricted';
  }

  // Change the 'width' option to the correct 'size' option.
  if ($component['extra']['width'] > 0) {
    $element['#size'] = $component['extra']['width'];
  }

  if (isset($value)) {
    $element['#default_value'] = $value[0];
  }

  return $element;
}

/**
 * Implements _webform_display_component().
 */
function _webform_display_autocomplete($component, $value, $format = 'html') {
  return _webform_display_textfield($component, $value, $format);
}

/**
 * Implements _webform_analysis_component().
 */
function _webform_analysis_autocomplete($component, $sids = array()) {
  return _webform_analysis_textfield($component, $sids);
}

/**
 * Implements _webform_table_component().
 */
function _webform_table_autocomplete($component, $value) {
  return _webform_table_textfield($component, $value);
}

/**
 * Implements _webform_csv_headers_component().
 */
function _webform_csv_headers_autocomplete($component, $export_options) {
  return _webform_csv_headers_textfield($component, $export_options);
}

/**
 * Implements _webform_csv_data_component().
 */
function _webform_csv_data_autocomplete($component, $export_options, $value) {
  return _webform_csv_data_textfield($component, $export_options, $value);
}

/**
 * Autocomplete callback.
 */
function webform_autocomplete_js($node, $cid, $str = '') {
  if ($str) {
    $component = $node->webform['components'][$cid];
    $results = array();
    $count = 0;
    // Search from prepulated options
    if (!empty($component['extra']['items'])) {
      $items = explode("\n", $component['extra']['items']);
      foreach ($items as $val) {
        if (stripos($val, $str) !== FALSE) {
          $results[$val] = $val;
          // Limit to 20 results
          if (++$count >= 20) {
            break;
          }
        }
      }
    }
    // Search from existing submissions
    // Only fire the query if we have fewer than 20 results already
    if (!empty($component['extra']['autocomplete_existing']) && $count < 20) {
      $db = db_query("SELECT DISTINCT data 
        FROM {webform_submitted_data}
        WHERE nid = :nid AND cid = :cid AND data LIKE :str LIMIT " . (20 - $count),
        array(':nid' => $node->nid, ':cid' => $cid, ':str' => '%' . db_like($str) . '%')
      );
      foreach ($db as $row) {
        $results[$row->data] = $row->data;
      }
    }
    // Sort php and sql results together
    natcasesort($results);
    drupal_json_output($results);
  }
  exit();
}

/**
 * Implements _webform_form_builder_map_component().
 */
function _webform_form_builder_map_autocomplete() {
  return array(
    'form_builder_type' => 'autocomplete',
    'properties' => array(
      'size' => array(
        'form_parents' => array('display', 'width'),
        'storage_parents' => array('extra', 'width'),
      ),
      'maxlength' => array(
        'form_parents' => array('display', 'maxlength'),
        'storage_parents' => array('extra', 'maxlength'),
      ),
      'field_prefix' => array(
        'form_parents' => array('display', 'field_prefix'),
        'storage_parents' => array('extra', 'field_prefix'),
      ),
      'field_suffix' => array(
        'form_parents' => array('display', 'field_suffix'),
        'storage_parents' => array('extra', 'field_suffix'),
      ),
      'items' => array(
        'form_parents' => array('options', 'items'),
        'storage_parents' => array('extra', 'items'),
      ),
      'autocomplete_existing' => array(
        'form_parents' => array('options', 'autocomplete_existing'),
        'storage_parents' => array('extra', 'autocomplete_existing'),
      ),
      'autocomplete_restrict' => array(
        'form_parents' => array('validation', 'autocomplete_restrict'),
        'storage_parents' => array('extra', 'autocomplete_restrict'),
      ),
    ),
  );
}
