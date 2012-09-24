<?php
/**
 * @file
 * equipment.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function equipment_field_default_fields() {
  $fields = array();

  // Exported field: 'node-equipment-body'.
  $fields['node-equipment-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'equipment',
      'default_value' => array(
        0 => array(
          'summary' => '',
          'value' => '',
          'format' => 'html_editor',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => 600,
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Description',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'html_editor' => 0,
            'php_code' => 0,
            'plain_text' => 'plain_text',
          ),
          'allowed_formats_toggle' => 1,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'html_editor' => array(
                'weight' => '0',
              ),
              'php_code' => array(
                'weight' => '11',
              ),
              'plain_text' => array(
                'weight' => '10',
              ),
            ),
          ),
        ),
        'display_summary' => 1,
        'text_processing' => '1',
        'user_register_form' => FALSE,
        'wysiwyg_fields' => array(
          'settings' => array(
            'advanced' => array(
              'delete' => 1,
              'hide' => 1,
            ),
            'formatters' => array(),
            'icon' => '6f7621a02161e347e66d99d8ace540a3',
            'label' => 'Body',
          ),
          'status' => 0,
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-equipment-field_equipment_booking_link'.
  $fields['node-equipment-field_equipment_booking_link'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_equipment_booking_link',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'link',
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'rel' => '',
          'target' => 'default',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
      ),
      'translatable' => '0',
      'type' => 'link_field',
    ),
    'field_instance' => array(
      'bundle' => 'equipment',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Link to the University of Melbourne library booking system where this item can be booked. On the front end will display as a button labelled <em>Book</em>.',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
          'weight' => '2',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_equipment_booking_link',
      'label' => 'Booking link',
      'required' => 1,
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'configurable_title' => 0,
          'rel' => 'nofollow',
          'target' => 'default',
          'title' => '',
        ),
        'display' => array(
          'url_cutoff' => '80',
        ),
        'enable_tokens' => 1,
        'title' => 'value',
        'title_maxlength' => '128',
        'title_value' => 'Book',
        'url' => 0,
        'user_register_form' => FALSE,
        'validate_url' => 1,
        'wysiwyg_fields' => array(
          'settings' => array(
            'advanced' => array(
              'delete' => 1,
              'hide' => 1,
            ),
            'formatters' => array(),
            'icon' => '6f7621a02161e347e66d99d8ace540a3',
            'label' => 'Booking link',
          ),
          'status' => 0,
        ),
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-equipment-field_equipment_image'.
  $fields['node-equipment-field_equipment_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_equipment_image',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'equipment',
      'deleted' => '0',
      'description' => 'Upload an image of the equipment. Will display as thumbnail in list and link to a full-size version when clicked.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => 'file',
            'image_style' => 'equipment_thumbnail',
          ),
          'type' => 'image',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_equipment_image',
      'label' => 'Image',
      'required' => 1,
      'settings' => array(
        'alt_field' => 1,
        'default_image' => 0,
        'file_directory' => 'equipment',
        'file_extensions' => 'png gif jpg jpeg',
        'focus' => 0,
        'focus_lock_ratio' => 0,
        'focus_min_size' => '',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 0,
        'user_register_form' => FALSE,
        'wysiwyg_fields' => array(
          'settings' => array(
            'advanced' => array(
              'delete' => 1,
              'hide' => 1,
            ),
            'formatters' => array(),
            'icon' => '6f7621a02161e347e66d99d8ace540a3',
            'label' => 'Image',
          ),
          'status' => 0,
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'caption_from_title' => 0,
          'insert' => 0,
          'insert_class' => '',
          'insert_default' => 'auto',
          'insert_styles' => array(
            'auto' => 0,
            'image' => 0,
            'image_large' => 0,
            'image_medium' => 0,
            'image_square_thumbnail' => 0,
            'image_thumbnail' => 0,
            'link' => 0,
          ),
          'insert_width' => '',
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-equipment-field_equipment_manual'.
  $fields['node-equipment-field_equipment_manual'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_equipment_manual',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'link',
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'rel' => '',
          'target' => 'default',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
      ),
      'translatable' => '0',
      'type' => 'link_field',
    ),
    'field_instance' => array(
      'bundle' => 'equipment',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Web link to the manual for this equipment. E.g. manual for a Sony DVC hosted on the Sony site. The name of the product will link to the manual.',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
          'weight' => '3',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_equipment_manual',
      'label' => 'Manual',
      'required' => 1,
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'configurable_title' => 0,
          'rel' => 'nofollow',
          'target' => 'default',
          'title' => '',
        ),
        'display' => array(
          'url_cutoff' => '80',
        ),
        'enable_tokens' => 0,
        'title' => 'value',
        'title_maxlength' => '128',
        'title_value' => '[node:title]',
        'url' => 0,
        'user_register_form' => FALSE,
        'validate_url' => 1,
        'wysiwyg_fields' => array(
          'settings' => array(
            'advanced' => array(
              'delete' => 1,
              'hide' => 1,
            ),
            'formatters' => array(),
            'icon' => '6f7621a02161e347e66d99d8ace540a3',
            'label' => 'Manual',
          ),
          'status' => 0,
        ),
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-equipment-field_equipment_resource'.
  $fields['node-equipment-field_equipment_resource'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_equipment_resource',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'link',
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'rel' => '',
          'target' => 'default',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
      ),
      'translatable' => '0',
      'type' => 'link_field',
    ),
    'field_instance' => array(
      'bundle' => 'equipment',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Link to resources, eg YouTube video with title field for description. You are able to add multiple resource links.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
          'weight' => '4',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_equipment_resource',
      'label' => 'Resource',
      'required' => 0,
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'configurable_title' => 0,
          'rel' => 'nofollow',
          'target' => 'default',
          'title' => '',
        ),
        'display' => array(
          'url_cutoff' => '80',
        ),
        'enable_tokens' => 1,
        'title' => 'required',
        'title_maxlength' => '128',
        'title_value' => '',
        'url' => 0,
        'user_register_form' => FALSE,
        'validate_url' => 1,
        'wysiwyg_fields' => array(
          'settings' => array(
            'advanced' => array(
              'delete' => 1,
              'hide' => 1,
            ),
            'formatters' => array(),
            'icon' => '6f7621a02161e347e66d99d8ace540a3',
            'label' => 'Resource',
          ),
          'status' => 0,
        ),
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'node-equipment-field_equipment_type'.
  $fields['node-equipment-field_equipment_type'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_equipment_type',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'audo_recorder' => 'Audio recorder',
          'stilL_camera' => 'Camera, still',
          'video_Camera' => 'Camera, video',
          'camera_lens' => 'Camera lens',
          'edit_suite' => 'Edit suite',
          'ipod_touch' => 'iPod touch',
          'mac_laptop' => 'Laptop, Mac',
          'pc_laptop' => 'Laptop, PC',
          'microphone' => 'Microphone',
          'microphone_mount' => 'Microphone mount',
          'production_kit' => 'Production kit',
          'tripod' => 'Tripod',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'equipment',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Some equipment can be categorised in multiple way. Eg, a search for a video camera would bring up products listed as “Camera, video” (standalone item) and “Production kit” (camera as part of the kit).',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_equipment_type',
      'label' => 'Type',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
        'wysiwyg_fields' => array(
          'settings' => array(
            'advanced' => array(
              'delete' => 1,
              'hide' => 1,
            ),
            'formatters' => array(),
            'icon' => '6f7621a02161e347e66d99d8ace540a3',
            'label' => 'Type',
          ),
          'status' => 0,
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '0',
      ),
    ),
  );

  // Exported field: 'node-equipment-field_syndication_site'.
  $fields['node-equipment-field_syndication_site'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_syndication_site',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'site',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'equipment',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_syndication_site',
      'label' => 'Site',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
        'wysiwyg_fields' => array(
          'settings' => array(
            'advanced' => array(
              'delete' => 1,
              'hide' => 1,
            ),
            'formatters' => array(),
            'icon' => '6f7621a02161e347e66d99d8ace540a3',
            'label' => 'Site',
          ),
          'status' => 0,
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '9',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Booking link');
  t('Description');
  t('Image');
  t('Link to resources, eg YouTube video with title field for description. You are able to add multiple resource links.');
  t('Link to the University of Melbourne library booking system where this item can be booked. On the front end will display as a button labelled <em>Book</em>.');
  t('Manual');
  t('Resource');
  t('Site');
  t('Some equipment can be categorised in multiple way. Eg, a search for a video camera would bring up products listed as “Camera, video” (standalone item) and “Production kit” (camera as part of the kit).');
  t('Type');
  t('Upload an image of the equipment. Will display as thumbnail in list and link to a full-size version when clicked.');
  t('Web link to the manual for this equipment. E.g. manual for a Sony DVC hosted on the Sony site. The name of the product will link to the manual.');

  return $fields;
}
