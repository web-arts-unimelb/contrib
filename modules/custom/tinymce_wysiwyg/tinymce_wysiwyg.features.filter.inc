<?php
/**
 * @file
 * tinymce_wysiwyg.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function tinymce_wysiwyg_filter_default_formats() {
  $formats = array();

  // Exported format: HTML Editor.
  $formats['html_editor'] = array(
    'format' => 'html_editor',
    'name' => 'HTML Editor',
    'cache' => '1',
    'status' => '1',
    'weight' => '0',
    'filters' => array(
      'filter_html' => array(
        'weight' => '-10',
        'status' => '1',
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <p> <h1> <h2> <h3> <h4> <h5> <h6> <img> <div> <table> <tbody> <tr> <td>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'caption_filter' => array(
        'weight' => '20',
        'status' => '1',
        'settings' => array(),
      ),
      'wysiwyg_fields' => array(
        'weight' => '50',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
