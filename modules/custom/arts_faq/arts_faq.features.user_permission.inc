<?php
/**
 * @file
 * arts_faq.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function arts_faq_user_default_permissions() {
  $permissions = array();

  // Exported permission: create faq content.
  $permissions['create faq content'] = array(
    'name' => 'create faq content',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any faq content.
  $permissions['delete any faq content'] = array(
    'name' => 'delete any faq content',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own faq content.
  $permissions['delete own faq content'] = array(
    'name' => 'delete own faq content',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any faq content.
  $permissions['edit any faq content'] = array(
    'name' => 'edit any faq content',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own faq content.
  $permissions['edit own faq content'] = array(
    'name' => 'edit own faq content',
    'roles' => array(
      0 => 'admin',
      1 => 'editor',
      2 => 'site admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
