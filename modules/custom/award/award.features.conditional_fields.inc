<?php
/**
 * @file
 * award.features.conditional_fields.inc
 */

/**
 * Implements hook_conditional_fields_default_fields().
 */
function award_conditional_fields_default_fields() {
  $items = array();

  $items[] = array(
    'entity' => 'node',
    'bundle' => 'award',
    'dependent' => 'field_award_year_level',
    'dependee' => 'field_award_study_level',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => '1',
        2 => '2',
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => '1',
          2 => '2',
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => '1',
          2 => '2',
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        3 => array(
          1 => '1',
          2 => '2',
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => '1',
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => '1',
          3 => 0,
        ),
        2 => array(
          1 => '1',
          3 => 0,
        ),
        3 => array(
          1 => '1',
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => '1',
      'value_form' => array(
        'undergraduate' => 'undergraduate',
        'honours' => NULL,
        'graduate' => NULL,
        'RHD' => NULL,
        'fellowship' => NULL,
      ),
      'value' => array(
        0 => array(
          'value' => 'undergraduate',
        ),
      ),
      'values' => array(),
    ),
  );

  return $items;
}
