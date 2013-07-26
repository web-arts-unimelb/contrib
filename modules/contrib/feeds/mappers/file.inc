<?php

/**
 * @file
 * On behalf implementation of Feeds mapping API for file.module and
 * image.module.
 */

/**
 * Replace existing files if they are different
 */
define('FEEDS_FILE_EXISTS_REPLACE_DIFFERENT', 3);

/**
 * Skip Existing Files
 */
define('FEEDS_FILE_EXISTS_SKIP', 4);

/**
 * Implements hook_feeds_processor_targets_alter().
 *
 * @see FeedsNodeProcessor::getMappingTargets()
 */
function file_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  foreach (field_info_instances($entity_type, $bundle_name) as $name => $instance) {
    $info = field_info_field($name);

    if (in_array($info['type'], array('file', 'image'))) {
      $targets[$name . ':uri'] = array(
        'name' => t('@label: URI', array('@label' => $instance['label'])),
        'callback' => 'file_feeds_set_target',
        'description' => t('The URI of the @label field.', array('@label' => $instance['label'])),
        'real_target' => $name,
        'summary_callback' => 'file_feeds_summary_callback',
        'form_callback' => 'file_feeds_form_callback',
      );

      if ($info['type'] == 'image') {
        $targets[$name . ':alt'] = array(
          'name' => t('@label: Alt', array('@label' => $instance['label'])),
          'callback' => 'file_feeds_set_target',
          'description' => t('The alt tag of the @label field.', array('@label' => $instance['label'])),
          'real_target' => $name,
        );
        $targets[$name . ':title'] = array(
          'name' => t('@label: Title', array('@label' => $instance['label'])),
          'callback' => 'file_feeds_set_target',
          'description' => t('The title of the @label field.', array('@label' => $instance['label'])),
          'real_target' => $name,
        );
      }
    }
  }
}

/**
 * Callback for mapping. Here is where the actual mapping happens.
 *
 * When the callback is invoked, $target contains the name of the field the
 * user has decided to map to and $value contains the value of the feed item
 * element the user has picked as a source.
 */
function file_feeds_set_target($source, $entity, $target, $value, $mapping) {

  $mapping += array('file_exists' => FILE_EXISTS_RENAME);

	// Gary
  if ( empty($value) || (is_array($value) && empty($value[0])) ) {
    return;
  }

  // Make sure $value is an array of objects of type FeedsEnclosure.
  if (!is_array($value)) {
    $value = array($value);
  }

  // Add default of uri for backwards compatibility.
  list($field_name, $sub_field) = explode(':', $target . ':uri');
  $info = field_info_field($field_name);

  if ($sub_field == 'uri') {

    foreach ($value as $k => $v) {
      if (!($v instanceof FeedsEnclosure)) {
        if (is_string($v)) {
          $value[$k] = new FeedsEnclosure($v, file_get_mimetype($v));
        }
        else {
          unset($value[$k]);
        }
      }
    }
    if (empty($value)) {
      return;
    }

    static $destination;
    if (!$destination) {
      $entity_type = $source->importer->processor->entityType();
      $bundle = $source->importer->processor->bundle();

      $instance_info = field_info_instance($entity_type, $field_name, $bundle);

      // Determine file destination.
      // @todo This needs review and debugging.
      $data = array();
      if (!empty($entity->uid)) {
        $data[$entity_type] = $entity;
      }
      $destination = file_field_widget_uri($info, $instance_info, $data);
    }
  }

  // Populate entity.
  $field = isset($entity->$field_name) ? $entity->$field_name : array(LANGUAGE_NONE => array());
  $delta = 0;
  foreach ($value as $v) {
    if ($info['cardinality'] == $delta) {
      break;
    }

    if (!isset($field[LANGUAGE_NONE][$delta])) {
      $field[LANGUAGE_NONE][$delta] = array();
    }

    switch ($sub_field) {
      case 'alt':
      case 'title':
        $field[LANGUAGE_NONE][$delta][$sub_field] = $v;
        break;

      case 'uri':
        $skip = FALSE;
        if ($mapping['file_exists'] == FEEDS_FILE_EXISTS_SKIP) {
          if (file_exists($destination . '/' . basename($v->getValue()))) {
            $skip = TRUE;
          }
          else {
            // We already know the file doesn't exist so we don't have to
            // worry about anything being renamed, but we do need a valid
            // replace value for file_save()
            $mapping['file_exists'] = FILE_EXISTS_RENAME;
          }
        }
        if ($mapping['file_exists'] == FEEDS_FILE_EXISTS_REPLACE_DIFFERENT && file_exists($destination . '/' . basename($v->getValue()))) {
          if (file_feeds_file_compare($v->getValue(), $destination . '/' . basename($v->getValue()))) {
            $skip = TRUE;
          }
          else {
            $mapping['file_exists'] = FILE_EXISTS_REPLACE;
          }
        }
        if ($skip) {
          // Create a new dummy feeds enclosure where the value is the file
          // already in the file system (it will be skipped by getFile())
          $existing_path = $destination . '/' . basename($v->getValue());
          $v = new FeedsEnclosure($existing_path, file_get_mimetype($existing_path));
        }
        try {
          $file = $v->getFile($destination, $mapping['file_exists']);
          $field[LANGUAGE_NONE][$delta] += (array) $file;
          // @todo: Figure out how to properly populate this field.
          $field[LANGUAGE_NONE][$delta]['display'] = 1;
        }
        catch (Exception $e) {
          watchdog_exception('Feeds', $e, nl2br(check_plain($e)));
        }
        break;
    }

    $delta++;
  }

  $entity->$field_name = $field;
}

/**
 * Mapping configuration summary callback.
 */
function file_feeds_summary_callback($mapping, $target, $form, $form_state) {
  $mapping += array('file_exists' => FILE_EXISTS_RENAME);
  switch ($mapping['file_exists']) {
    case FILE_EXISTS_REPLACE:
      return t('Replace existing files');

    case FILE_EXISTS_RENAME:
      return t('Rename if file exists');

    case FEEDS_FILE_EXISTS_REPLACE_DIFFERENT:
      return t('Replace if file exists but is different');

    case FEEDS_FILE_EXISTS_SKIP:
      return t('Skip if file exists');
  }
}

/**
 * Settings form callback.
 */
function file_feeds_form_callback($mapping, $target, $form, $form_state) {
  return array(
    'file_exists' => array(
      '#type' => 'select',
      '#title' => t('Replacement method'),
      '#default_value' => !empty($mapping['file_exists']) ? $mapping['file_exists'] : FILE_EXISTS_RENAME,
      '#options' => array(
        FILE_EXISTS_RENAME => t('Rename'),
        FILE_EXISTS_REPLACE => t('Replace'),
        FEEDS_FILE_EXISTS_REPLACE_DIFFERENT => t('Replace if different'),
        FEEDS_FILE_EXISTS_SKIP => t('Skip existing'),
      ),
    ),
  );
}

/**
 * Compares two files to determine if they are the same.
 *
 * @param string $file1
 *   The path to the first file to compare
 *
 * @param string $file2
 *   The path to the second file to compare
 *
 * @return boolean
 *   Returns TRUE if the files are the same or FALSE if they're different
 */
function file_feeds_file_compare($file1, $file2) {

  // Simple file size check first
  if (filesize($file1) !== filesize($file2)) {
    return FALSE;
  }

  // Calculate md5
  if (md5_file($file1) !== md5_file($file2)) {
    return FALSE;
  }

  return TRUE;
}
