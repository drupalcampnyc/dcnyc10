<?php

/**
 * Implementation of hook_user_default_roles().
 */
function cod_events_user_default_roles() {
  $roles = array();

  // Exported role: attendee manager
  $roles['attendee manager'] = array(
    'name' => 'attendee manager',
  );

  return $roles;
}
