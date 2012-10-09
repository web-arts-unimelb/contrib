<?php
/**
 * @file
 * feature_profile.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function feature_profile_taxonomy_default_vocabularies() {
  return array(
    'program' => array(
      'name' => 'Program',
      'machine_name' => 'program',
      'description' => 'This vocabulary is used to tag programs on the GSHSS site as well as Feature Profile content.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'research_area' => array(
      'name' => 'Research area',
      'machine_name' => 'research_area',
      'description' => 'Research areas',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
