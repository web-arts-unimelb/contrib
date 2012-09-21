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
    'weight' => '6',
    'children' => array(
      0 => 'field_profile_grad_res',
      1 => 'field_profile_grad_course',
      2 => 'field_profile_undergrad',
      3 => 'field_profile_major',
      4 => 'field_profile_program',
      5 => 'field_profile_area',
      6 => 'field_profile_previous_studies',
      7 => 'field_profile_further_studies',
      8 => 'field_profile_graduating_year',
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_shared_syndication|node|award|form';
  $field_group->group_name = 'group_shared_syndication';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'award';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Syndication Details',
    'weight' => '21',
    'children' => array(
      0 => 'field_syndication_site',
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
  $export['group_shared_syndication|node|award|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_shared_syndication|node|feature_profile|form';
  $field_group->group_name = 'group_shared_syndication';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'feature_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Syndication Details',
    'weight' => '35',
    'children' => array(
      0 => 'field_syndication_site',
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
  $export['group_shared_syndication|node|feature_profile|form'] = $field_group;

  return $export;
}
