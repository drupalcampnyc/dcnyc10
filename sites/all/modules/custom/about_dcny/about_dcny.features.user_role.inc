<?php

/**
 * Implementation of hook_user_default_roles().
 */
function about_dcny_user_default_roles() {
  $roles = array();

  // Exported role: content manager
  $roles['content manager'] = array(
    'name' => 'content manager',
  );

  return $roles;
}
