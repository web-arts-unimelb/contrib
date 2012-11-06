<?php
/**
 * @file
 * program.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function program_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_program_tags|node|program|form';
  $field_group->group_name = 'group_program_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'program';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Program Tags',
    'weight' => '15',
    'children' => array(
      0 => 'field_career_outcomes',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Program Tags',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'These tags and categories are used to display programs and link them to awards and feature profiles.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_program_tags|node|program|form'] = $field_group;

  return $export;
}
