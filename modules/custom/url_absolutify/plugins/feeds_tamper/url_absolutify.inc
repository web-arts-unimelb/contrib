<?php

/**
 * @file
 * Truncate text to a specified length.
 */

$plugin = array(
  'form' => 'url_absolutify_url_absolutify_form',
  'callback' => 'url_absolutify_url_absolutify_callback',
  'validate' => 'url_absolutify_url_absolutify_validate',
  'name' => 'Absolutify URL',
  'multi' => 'loop',
  'category' => 'Text',
);

function url_absolutify_url_absolutify_form($importer, $element_key, $settings) {
  $form = array();
  $form['origin'] = array(
    '#type' => 'textfield',
    '#title' => t('Site of origin'),
    '#default_value' => isset($settings['origin']) ? $settings['origin'] : '',
    '#description' => t('The URL of the originating site. If blank, the hostname from the Feed URL will be used.'),
  );
  $form['global'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use global files directory'),
    '#default_value' => isset($settings['global']) ? $settings['global'] : FALSE,
    '#description' => t('Make URLs point at the global /files/ directory and not the per-site directory at /sites/[sitename]/files/.'),
  );
  return $form;
}

function url_absolutify_url_absolutify_validate($settings) {
}

function url_absolutify_url_absolutify_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  // Source...
  if (empty($settings['origin'])) {
    $url = $source->config['FeedsHTTPFetcher']['source'];
  }
  else {
    $url = $settings['origin'];
  }

  // Target directory...
  if (!empty($settings['global'])) {
    $target = '/files/';
  }
  else {
    global $base_url;
    $target = file_create_url('public:///');
    $target = strtr($target, array($base_url => ''));
  }

  $uri = parse_url($url);

  // Make an array of replacements.
  $replace = array(
    $uri['scheme'] . '://' . $uri['host'] .'/sites/' . $uri['host'] . '/files/' => $target,
    '/sites/' . $uri['host'] . '/files/' => $target,
    $uri['scheme'] . '://' . $uri['host'] => '',
  );

  $field = strtr($field, $replace);
}
