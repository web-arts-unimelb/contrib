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
