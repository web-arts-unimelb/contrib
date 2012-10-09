<?php
/**
 * @file
 * feature_profile.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feature_profile_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_teach_or_study|node|feature_profile|form';
  $field_group->group_name = 'group_profile_teach_or_study';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'feature_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Teaching or Studying',
    'weight' => '8',
    'children' => array(
      0 => 'field_profile_further_studies',
      1 => 'field_profile_grad_course',
      2 => 'field_profile_grad_res',
      3 => 'field_profile_graduating_year',
      4 => 'field_profile_major',
      5 => 'field_profile_previous_studies',
      6 => 'field_profile_undergrad',
      7 => 'field_profile_program',
      8 => 'field_profile_research_area',
      9 => 'field_profile_alumna',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_profile_teach_or_study|node|feature_profile|form'] = $field_group;

  return $export;
}
