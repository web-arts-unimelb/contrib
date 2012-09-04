<?php
/**
 * @file
 * Preprocess functions and theme overrides for the unimelb_gshss theme.
 */

/**
 * Implements hook_preprocess_html().
 */
function unimelb_gshss_preprocess_html(&$variables) {
  $variables['overlay'] = FALSE;
  if (module_exists('overlay') && in_array('overlay', $variables['page']['#theme_wrappers'])) {
    $variables['overlay'] = TRUE;
  }
}
