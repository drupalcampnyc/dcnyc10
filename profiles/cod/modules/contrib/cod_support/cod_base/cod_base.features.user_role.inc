<?php

/**
 * Implementation of hook_user_default_roles().
 */
function cod_base_user_default_roles() {
  $roles = array();

  // Exported role: site administrator
  $roles['site administrator'] = array(
    'name' => 'site administrator',
  );

  return $roles;
}
