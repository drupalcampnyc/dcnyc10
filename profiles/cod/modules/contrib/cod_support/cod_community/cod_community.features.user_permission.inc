<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function cod_community_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer site-wide contact form
  $permissions['administer site-wide contact form'] = array(
    'name' => 'administer site-wide contact form',
    'roles' => array(
      '0' => 'site administrator',
    ),
  );

  return $permissions;
}
