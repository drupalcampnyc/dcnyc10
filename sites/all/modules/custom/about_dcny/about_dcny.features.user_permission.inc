<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function about_dcny_user_default_permissions() {
  $permissions = array();

  // Exported permission: create faq content
  $permissions['create faq content'] = array(
    'name' => 'create faq content',
    'roles' => array(
      '0' => 'volunteer',
    ),
  );

  // Exported permission: edit any faq content
  $permissions['edit any faq content'] = array(
    'name' => 'edit any faq content',
    'roles' => array(
      '0' => 'content manager',
    ),
  );

  // Exported permission: edit any page content
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      '0' => 'content manager',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: revert revisions
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      '0' => 'content manager',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: view revisions
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      '0' => 'content manager',
      '1' => 'site administrator',
    ),
  );

  return $permissions;
}
