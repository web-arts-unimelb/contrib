<?php
/**
 * @file
 * feature_profile.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function feature_profile_field_default_fields() {
  $fields = array();

  // Exported field: 'node-feature_profile-body'.
  $fields['node-feature_profile-body'] = array(
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
      'bundle' => 'feature_profile',
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
          'weight' => '4',
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
      'label' => 'About',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'html_editor' => 'html_editor',
            'plain_text' => 0,
          ),
          'allowed_formats_toggle' => 1,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'html_editor' => array(
                'weight' => '0',
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
          'rows' => '20',
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'node-feature_profile-field_profile_area'.
  $fields['node-feature_profile-field_profile_area'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_profile_area',
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
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'feature_profile',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '11',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_area',
      'label' => 'Research area',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'html_editor' => 'html_editor',
            'plain_text' => 'plain_text',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'html_editor' => array(
                'weight' => '0',
              ),
              'plain_text' => array(
                'weight' => '10',
              ),
            ),
          ),
        ),
        'text_processing' => '0',
        'user_register_form' => FALSE,
        'wysiwyg_fields' => array(
          'settings' => array(
            'advanced' => array(
              'delete' => 1,
              'hide' => 1,
            ),
            'formatters' => array(),
            'icon' => '6f7621a02161e347e66d99d8ace540a3',
            'label' => 'Research area',
          ),
          'status' => 0,
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '12',
      ),
    ),
  );

  // Exported field: 'node-feature_profile-field_profile_further_studies'.
  $fields['node-feature_profile-field_profile_further_studies'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_profile_further_studies',
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
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'feature_profile',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '13',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_further_studies',
      'label' => 'Further studies',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'html_editor' => 'html_editor',
            'plain_text' => 'plain_text',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'html_editor' => array(
                'weight' => '0',
              ),
              'plain_text' => array(
                'weight' => '10',
              ),
            ),
          ),
        ),
        'text_processing' => '0',
        'user_register_form' => FALSE,
        'wysiwyg_fields' => array(
          'settings' => array(
            'advanced' => array(
              'delete' => 1,
              'hide' => 1,
            ),
            'formatters' => array(),
            'icon' => '6f7621a02161e347e66d99d8ace540a3',
            'label' => 'Further studies',
          ),
          'status' => 0,
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '14',
      ),
    ),
  );

  // Exported field: 'node-feature_profile-field_profile_grad_course'.
  $fields['node-feature_profile-field_profile_grad_course'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_profile_grad_course',
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
          0 => '',
          1 => '',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'feature_profile',
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '8',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_grad_course',
      'label' => 'Graduate, coursework',
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
            'label' => 'Graduate, coursework',
          ),
          'status' => 0,
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'node-feature_profile-field_profile_grad_res'.
  $fields['node-feature_profile-field_profile_grad_res'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_profile_grad_res',
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
          0 => '',
          1 => '',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'feature_profile',
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '10',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_grad_res',
      'label' => 'Graduate, research',
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
            'label' => 'Graduate, research',
          ),
          'status' => 0,
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '11',
      ),
    ),
  );

  // Exported field: 'node-feature_profile-field_profile_graduating_year'.
  $fields['node-feature_profile-field_profile_graduating_year'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_profile_graduating_year',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'date',
      'settings' => array(
        'cache_count' => '4',
        'cache_enabled' => 0,
        'granularity' => array(
          'day' => 0,
          'hour' => 0,
          'minute' => 0,
          'month' => 0,
          'second' => 0,
          'year' => 'year',
        ),
        'timezone_db' => '',
        'todate' => '',
        'tz_handling' => 'none',
      ),
      'translatable' => '0',
      'type' => 'datetime',
    ),
    'field_instance' => array(
      'bundle' => 'feature_profile',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
          ),
          'type' => 'date_default',
          'weight' => '14',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_graduating_year',
      'label' => 'Graduating year',
      'required' => 0,
      'settings' => array(
        'default_value' => 'strtotime',
        'default_value2' => 'same',
        'default_value_code' => '+2 years',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
        'wysiwyg_fields' => array(
          'settings' => array(
            'advanced' => array(
              'delete' => 1,
              'hide' => 1,
            ),
            'formatters' => array(),
            'icon' => '6f7621a02161e347e66d99d8ace540a3',
            'label' => 'Graduating year',
          ),
          'status' => 0,
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'increment' => '15',
          'input_format' => 'Y-m-d H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'text_parts' => array(),
          'year_range' => '1900:+8',
        ),
        'type' => 'date_select',
        'weight' => '15',
      ),
    ),
  );

  // Exported field: 'node-feature_profile-field_profile_image'.
  $fields['node-feature_profile-field_profile_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_profile_image',
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
      'bundle' => 'feature_profile',
      'deleted' => '0',
      'description' => 'Attach an image of this person, to be displayed wherever this profile is shown.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => 'thumbnail',
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
      'field_name' => 'field_profile_image',
      'label' => 'Profile image',
      'required' => 1,
      'settings' => array(
        'alt_field' => 1,
        'default_image' => 0,
        'file_directory' => 'feature_profile',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 1,
        'user_register_form' => FALSE,
        'wysiwyg_fields' => array(
          'settings' => array(
            'advanced' => array(
              'delete' => 1,
              'hide' => 1,
            ),
            'formatters' => array(),
            'icon' => '6f7621a02161e347e66d99d8ace540a3',
            'label' => 'Profile image',
          ),
          'status' => 0,
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'caption_from_title' => 1,
          'insert' => 0,
          'insert_class' => '',
          'insert_default' => 'auto',
          'insert_styles' => array(
            'auto' => 'auto',
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
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-feature_profile-field_profile_images'.
  $fields['node-feature_profile-field_profile_images'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_profile_images',
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
      'bundle' => 'feature_profile',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'hidden',
          'weight' => 16,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_images',
      'label' => 'Image',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'file_directory' => '',
        'file_extensions' => 'png gif jpg jpeg',
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
            'formatters' => array(
              'image' => 'image',
            ),
            'icon' => 'd50522754f0bc7cc44d2f5231a467fe8',
            'label' => 'Insert images',
          ),
          'status' => 1,
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'media',
        'settings' => array(
          'allowed_schemes' => array(
            'public' => 'public',
            'youtube' => 0,
          ),
          'allowed_types' => array(
            'audio' => 0,
            'default' => 0,
            'image' => 'image',
            'video' => 0,
          ),
          'progress_indicator' => 'throbber',
        ),
        'type' => 'media_generic',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-feature_profile-field_profile_jobtitle'.
  $fields['node-feature_profile-field_profile_jobtitle'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_profile_jobtitle',
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
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'feature_profile',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
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
      'field_name' => 'field_profile_jobtitle',
      'label' => 'Job title',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'html_editor' => 'html_editor',
            'plain_text' => 'plain_text',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'html_editor' => array(
                'weight' => '0',
              ),
              'plain_text' => array(
                'weight' => '10',
              ),
            ),
          ),
        ),
        'text_processing' => '0',
        'user_register_form' => FALSE,
        'wysiwyg_fields' => array(
          'settings' => array(
            'advanced' => array(
              'delete' => 1,
              'hide' => 1,
            ),
            'formatters' => array(),
            'icon' => '6f7621a02161e347e66d99d8ace540a3',
            'label' => 'Job title',
          ),
          'status' => 0,
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-feature_profile-field_profile_major'.
  $fields['node-feature_profile-field_profile_major'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_profile_major',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'feature_profile',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '7',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_major',
      'label' => 'Major',
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
            'label' => 'Major',
          ),
          'status' => 0,
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'node-feature_profile-field_profile_previous_studies'.
  $fields['node-feature_profile-field_profile_previous_studies'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_profile_previous_studies',
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
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'feature_profile',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '12',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_previous_studies',
      'label' => 'Previous studies',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'html_editor' => 'html_editor',
            'plain_text' => 'plain_text',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'html_editor' => array(
                'weight' => '0',
              ),
              'plain_text' => array(
                'weight' => '10',
              ),
            ),
          ),
        ),
        'text_processing' => '0',
        'user_register_form' => FALSE,
        'wysiwyg_fields' => array(
          'settings' => array(
            'advanced' => array(
              'delete' => 1,
              'hide' => 1,
            ),
            'formatters' => array(),
            'icon' => '6f7621a02161e347e66d99d8ace540a3',
            'label' => 'Previous studies',
          ),
          'status' => 0,
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '13',
      ),
    ),
  );

  // Exported field: 'node-feature_profile-field_profile_program'.
  $fields['node-feature_profile-field_profile_program'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_profile_program',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'feature_profile',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '9',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_program',
      'label' => 'Program',
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
            'label' => 'Program',
          ),
          'status' => 0,
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '10',
      ),
    ),
  );

  // Exported field: 'node-feature_profile-field_profile_title'.
  $fields['node-feature_profile-field_profile_title'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_profile_title',
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
          'Dr' => 'Dr',
          'Mr' => 'Mr',
          'Ms' => 'Ms',
          'Mrs' => 'Mrs',
          'Miss' => 'Miss',
          'Professor' => 'Professor',
          'Associate Professor' => 'Associate Professor',
          'Emeritus Professor' => 'Emeritus Professor',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'feature_profile',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
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
      'field_name' => 'field_profile_title',
      'label' => 'Title',
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
            'label' => 'Title',
          ),
          'status' => 0,
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-feature_profile-field_profile_type'.
  $fields['node-feature_profile-field_profile_type'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_profile_type',
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
          'staff' => 'Staff',
          'student' => 'Student',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'feature_profile',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_profile_type',
      'label' => 'Profile type',
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
            'label' => 'Profile type',
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

  // Exported field: 'node-feature_profile-field_profile_undergrad'.
  $fields['node-feature_profile-field_profile_undergrad'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_profile_undergrad',
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
          0 => '',
          1 => '',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'feature_profile',
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
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
      'field_name' => 'field_profile_undergrad',
      'label' => 'Undergraduate',
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
            'label' => 'Undergraduate',
          ),
          'status' => 0,
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'node-feature_profile-field_profile_video'.
  $fields['node-feature_profile-field_profile_video'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_profile_video',
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
      'module' => 'file',
      'settings' => array(
        'display_default' => 0,
        'display_field' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'file',
    ),
    'field_instance' => array(
      'bundle' => 'feature_profile',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_default',
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
      'field_name' => 'field_profile_video',
      'label' => 'Video',
      'required' => 0,
      'settings' => array(
        'description_field' => 0,
        'file_directory' => '',
        'file_extensions' => 'txt',
        'max_filesize' => '',
        'user_register_form' => FALSE,
        'wysiwyg_fields' => array(
          'settings' => array(
            'advanced' => array(
              'delete' => 1,
              'hide' => 1,
            ),
            'formatters' => array(),
            'icon' => '6f7621a02161e347e66d99d8ace540a3',
            'label' => 'Video',
          ),
          'status' => 0,
        ),
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'media',
        'settings' => array(
          'allowed_schemes' => array(
            'public' => 0,
            'youtube' => 'youtube',
          ),
          'allowed_types' => array(
            'audio' => 0,
            'default' => 0,
            'image' => 0,
            'video' => 'video',
          ),
          'progress_indicator' => 'throbber',
        ),
        'type' => 'media_generic',
        'weight' => '4',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Attach an image of this person, to be displayed wherever this profile is shown.');
  t('Further studies');
  t('Graduate, coursework');
  t('Graduate, research');
  t('Graduating year');
  t('Image');
  t('Job title');
  t('Major');
  t('Previous studies');
  t('Profile image');
  t('Profile type');
  t('Program');
  t('Research area');
  t('Title');
  t('Undergraduate');
  t('Video');

  return $fields;
}
