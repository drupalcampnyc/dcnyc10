<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function cod_events_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer UC_Signup
  $permissions['administer UC_Signup'] = array(
    'name' => 'administer UC_Signup',
    'roles' => array(
      '0' => 'attendee manager',
    ),
  );

  // Exported permission: administer all signups
  $permissions['administer all signups'] = array(
    'name' => 'administer all signups',
    'roles' => array(
      '0' => 'attendee manager',
    ),
  );

  // Exported permission: administer signups for own content
  $permissions['administer signups for own content'] = array(
    'name' => 'administer signups for own content',
    'roles' => array(
      '0' => 'attendee manager',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: cancel own signups
  $permissions['cancel own signups'] = array(
    'name' => 'cancel own signups',
    'roles' => array(
      '0' => 'attendee manager',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: cancel signups
  $permissions['cancel signups'] = array(
    'name' => 'cancel signups',
    'roles' => array(
      '0' => 'attendee manager',
    ),
  );

  // Exported permission: edit own signups
  $permissions['edit own signups'] = array(
    'name' => 'edit own signups',
    'roles' => array(
      '0' => 'attendee manager',
    ),
  );

  // Exported permission: email all signed up users
  $permissions['email all signed up users'] = array(
    'name' => 'email all signed up users',
    'roles' => array(
      '0' => 'attendee manager',
    ),
  );

  // Exported permission: email users signed up for own content
  $permissions['email users signed up for own content'] = array(
    'name' => 'email users signed up for own content',
    'roles' => array(
      '0' => 'attendee manager',
    ),
  );

  // Exported permission: purchase signups for other users
  $permissions['purchase signups for other users'] = array(
    'name' => 'purchase signups for other users',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: sign up for content
  $permissions['sign up for content'] = array(
    'name' => 'sign up for content',
    'roles' => array(
      '0' => 'attendee manager',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view all signups
  $permissions['view all signups'] = array(
    'name' => 'view all signups',
    'roles' => array(
      '0' => 'attendee manager',
    ),
  );

  return $permissions;
}
