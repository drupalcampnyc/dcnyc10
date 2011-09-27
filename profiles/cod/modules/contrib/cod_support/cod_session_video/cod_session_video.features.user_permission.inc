<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function cod_session_video_user_default_permissions() {
  $permissions = array();

  // Exported permission: edit field_video
  $permissions['edit field_video'] = array(
    'name' => 'edit field_video',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: view field_video
  $permissions['view field_video'] = array(
    'name' => 'view field_video',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  return $permissions;
}
