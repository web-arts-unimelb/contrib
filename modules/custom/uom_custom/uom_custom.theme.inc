<?php
/**
 * @file
 * UoM Custom theme functions.
 */

/**
 * Returns HTML for an inline link to an attached file.
 *
 * @param $variables
 *   An associative array containing:
 *   - item: file as an array.
 */
function theme_uom_custom_inline_file($variables) {
  $file = (object) $variables['item'];

  $url = file_create_url($file->uri);

  $options = array(
    'attributes' => array(
      'type' => $file->filemime . '; length=' . $file->filesize,
    ),
  );

  if (!empty($file->description)) {
    $link_text = $file->description;
    $options['attributes']['title'] = check_plain($file->filename);
  }
  else {
    $link_text = $file->filename;
  }

  // return '<span class="file">' . l($link_text, $url, $options) . '</span> <span class="filesize">(' . format_size($file->filesize) .')</span>';
  return '<span class="file">' . l($link_text, $url, $options) . '</span>';
}

/**
 * Returns HTML for an Colourbox image field formatter.
 *
 * @param $variables
 *   An associative array containing:
 *   - item: An array of image data.
 *   - image_style: An optional image style.
 *   - path: An array containing the link 'path' and link 'options'.
 *
 * @ingroup themeable
 */
function theme_uom_custom_colourbox_image_formatter($variables) {
  $item = $variables['item'];
  $node = $variables['node'];
  $field = $variables['field'];
  $settings = $variables['display_settings'];

  $image = array(
    'path' => $item['uri'],
    'alt' => $item['alt'],
    'title' => $item['title'],
    'style_name' => $settings['colorbox_node_style'],
    'attributes' => isset($item['attributes']) ? $item['attributes'] : array(),
    'align' => $settings['image_float'],
  );

  if (isset($item['width']) && isset($item['height'])) {
    $image['width'] = $item['width'];
    $image['height'] = $item['height'];
  }

  $class = isset($item['attributes']['class']) ? $item['attributes']['class'] : '';

  switch ($settings['colorbox_caption']) {
    case 'auto':
      // If the title is empty use alt or the node title in that order.
      if (!empty($image['title'])) {
        $caption = $image['title'];
      }
      elseif (!empty($image['alt'])) {
        $caption = $image['alt'];
      }
      elseif (!empty($node->title)) {
        $caption = $node->title;
      }
      else {
        $caption = '';
      }
      break;
    case 'title':
      $caption = $image['title'];
      break;
    case 'alt':
      $caption = $image['alt'];
      break;
    case 'node_title':
      $caption = $node->title;
      break;
    case 'custom':
      $caption = token_replace($settings['colorbox_caption_custom'], array('node' => $node));
      break;
    default:
      $caption = '';
  }

  // Shorten the caption for the example styles or when caption shortening is active.
  $colorbox_style = variable_get('colorbox_style', 'default');
  $trim_length = variable_get('colorbox_caption_trim_length', 75);
  if (((strpos($colorbox_style, 'colorbox/example') !== FALSE) || variable_get('colorbox_caption_trim', 0)) && (drupal_strlen($caption) > $trim_length)) {
    $caption = drupal_substr($caption, 0, $trim_length - 5) . '...';
  }

  // Build the gallery id.
  $nid = !empty($node->nid) ? $node->nid : 'nid';
  switch ($settings['colorbox_gallery']) {
    case 'post':
      $gallery_id = 'gallery-' . $nid;
      break;
    case 'page':
      $gallery_id = 'gallery-all';
      break;
    case 'field_post':
      $gallery_id = 'gallery-' . $nid . '-' . $field['field_name'];
      break;
    case 'field_page':
      $gallery_id = 'gallery-' . $field['field_name'];
      break;
    case 'custom':
      $gallery_id = $settings['colorbox_gallery_custom'];
      break;
    default:
      $gallery_id = '';
  }

  if ($style_name = $settings['colorbox_image_style']) {
    $path = image_style_url($style_name, $image['path']);
  }
  else {
    $path = file_create_url($image['path']);
  }

  return theme('uom_custom_colourbox_imagefield', array('image' => $image, 'path' => $path, 'title' => $caption, 'gid' => $gallery_id, 'class' => $class));
}

/**
 * Returns HTML for a floated image using a specific Colorbox image style.
 *
 * @param $variables
 *   An associative array containing:
 *   - image: image item as array.
 *   - path: The path of the image that should be displayed in the Colorbox.
 *   - title: The title text that will be used as a caption in the Colorbox.
 *   - gid: Gallery id for Colorbox image grouping.
 *   - class: Extra classes to be applied to the element.
 *
 * @ingroup themeable
 */
function theme_uom_custom_colourbox_imagefield($variables) {
  $class = array('colorbox');

  if ($variables['image']['style_name'] == 'hide') {
    $image = '';
    $class[] = 'js-hide';
  }
  else if (!empty($variables['image']['style_name'])) {
    $image = theme('image_style', $variables['image']);
  }
  else {
    $image = theme('image', $variables['image']);
  }

  $options = array(
    'html' => TRUE,
    'attributes' => array(
      'title' => $variables['title'],
      'class' => implode(' ', $class),
      'rel' => $variables['gid'],
    )
  );

  return l($image, $variables['path'], $options);
}
