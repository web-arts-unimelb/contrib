<?php
/**
 * @file
 * arts_faq.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function arts_faq_taxonomy_default_vocabularies() {
  return array(
    'section' => array(
      'name' => 'Site Section',
      'machine_name' => 'section',
      'description' => 'Used to associate items of content with specific parts of web sites.',
      'hierarchy' => '1',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
