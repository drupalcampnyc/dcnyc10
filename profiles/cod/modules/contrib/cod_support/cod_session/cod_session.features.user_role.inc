<?php

/**
 * Implementation of hook_user_default_roles().
 */
function cod_session_user_default_roles() {
  $roles = array();

  // Exported role: attendee
  $roles['attendee'] = array(
    'name' => 'attendee',
  );

  // Exported role: session organizer
  $roles['session organizer'] = array(
    'name' => 'session organizer',
  );

  // Exported role: volunteer
  $roles['volunteer'] = array(
    'name' => 'volunteer',
  );

  return $roles;
}
