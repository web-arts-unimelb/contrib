<?php
/**
 * @file
 * award.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function award_taxonomy_default_vocabularies() {
  return array(
    'site' => array(
      'name' => 'Site',
      'machine_name' => 'site',
      'description' => 'This taxonomy us used to tack which site an item of content should be syndicated to.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'voocab' => array(
      'name' => 'Voocab',
      'machine_name' => 'voocab',
      'description' => 'This is a taxonomy vocabulary',
      'hierarchy' => '2',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
