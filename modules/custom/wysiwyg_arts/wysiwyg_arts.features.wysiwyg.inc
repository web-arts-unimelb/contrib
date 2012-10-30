<?php
/**
 * @file
 * wysiwyg_arts.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function wysiwyg_arts_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: full_html
  $profiles['full_html'] = array(
    'format' => 'full_html',
    'editor' => 'tinymce',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 0,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'bold' => 1,
          'italic' => 1,
          'justifyleft' => 1,
          'justifycenter' => 1,
          'justifyright' => 1,
          'bullist' => 1,
          'numlist' => 1,
          'outdent' => 1,
          'indent' => 1,
          'link' => 1,
          'unlink' => 1,
          'anchor' => 1,
          'formatselect' => 1,
          'styleselect' => 1,
          'blockquote' => 1,
          'code' => 1,
          'removeformat' => 1,
        ),
      ),
      'toolbar_loc' => 'top',
      'toolbar_align' => 'left',
      'path_loc' => 'bottom',
      'resizing' => 1,
      'verify_html' => 1,
      'preformatted' => 1,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 1,
      'apply_source_formatting' => 1,
      'paste_auto_cleanup_on_paste' => 0,
      'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6,div,blockquote,address,pre,code,dt,dd,img',
      'css_setting' => 'self',
      'css_path' => 'profiles/foa/modules/custom/wysiwyg_arts/css/wysiwyg_arts.css',
      'css_classes' => 'Image float left=wysiwyg-left
Image float right=wysiwyg-right
Paragraph Notice=notice
Paragraph Important Notice=importantnotice'
    ),
    'rdf_mapping' => array(),
  );

  return $profiles;
}
