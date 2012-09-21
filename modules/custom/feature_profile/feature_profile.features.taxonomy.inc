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
    'site' => array(
      'name' => 'Site',
      'machine_name' => 'site',
      'description' => 'This taxonomy us used to tack which site an item of content should be syndicated to.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
