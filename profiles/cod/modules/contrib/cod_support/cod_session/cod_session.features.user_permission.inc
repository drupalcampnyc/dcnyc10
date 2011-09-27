<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function cod_session_user_default_permissions() {
  $permissions = array();

  // Exported permission: create room content
  $permissions['create room content'] = array(
    'name' => 'create room content',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: create schedule_item content
  $permissions['create schedule_item content'] = array(
    'name' => 'create schedule_item content',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: create session content
  $permissions['create session content'] = array(
    'name' => 'create session content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: create time_slot content
  $permissions['create time_slot content'] = array(
    'name' => 'create time_slot content',
    'roles' => array(
      '0' => 'site administrator',
    ),
  );

  // Exported permission: delete any room content
  $permissions['delete any room content'] = array(
    'name' => 'delete any room content',
    'roles' => array(
      '0' => 'site administrator',
    ),
  );

  // Exported permission: delete any schedule_item content
  $permissions['delete any schedule_item content'] = array(
    'name' => 'delete any schedule_item content',
    'roles' => array(
      '0' => 'site administrator',
    ),
  );

  // Exported permission: delete any session content
  $permissions['delete any session content'] = array(
    'name' => 'delete any session content',
    'roles' => array(
      '0' => 'site administrator',
    ),
  );

  // Exported permission: delete any time_slot content
  $permissions['delete any time_slot content'] = array(
    'name' => 'delete any time_slot content',
    'roles' => array(
      '0' => 'site administrator',
    ),
  );

  // Exported permission: delete own room content
  $permissions['delete own room content'] = array(
    'name' => 'delete own room content',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: delete own schedule_item content
  $permissions['delete own schedule_item content'] = array(
    'name' => 'delete own schedule_item content',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: delete own session content
  $permissions['delete own session content'] = array(
    'name' => 'delete own session content',
    'roles' => array(
      '0' => 'site administrator',
    ),
  );

  // Exported permission: delete own time_slot content
  $permissions['delete own time_slot content'] = array(
    'name' => 'delete own time_slot content',
    'roles' => array(
      '0' => 'site administrator',
    ),
  );

  // Exported permission: edit any room content
  $permissions['edit any room content'] = array(
    'name' => 'edit any room content',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: edit any schedule_item content
  $permissions['edit any schedule_item content'] = array(
    'name' => 'edit any schedule_item content',
    'roles' => array(
      '0' => 'site administrator',
    ),
  );

  // Exported permission: edit any session content
  $permissions['edit any session content'] = array(
    'name' => 'edit any session content',
    'roles' => array(
      '0' => 'site administrator',
    ),
  );

  // Exported permission: edit any time_slot content
  $permissions['edit any time_slot content'] = array(
    'name' => 'edit any time_slot content',
    'roles' => array(
      '0' => 'site administrator',
    ),
  );

  // Exported permission: edit field_accepted
  $permissions['edit field_accepted'] = array(
    'name' => 'edit field_accepted',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: edit field_experience
  $permissions['edit field_experience'] = array(
    'name' => 'edit field_experience',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: edit field_speakers
  $permissions['edit field_speakers'] = array(
    'name' => 'edit field_speakers',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'session organizer',
      '2' => 'site administrator',
    ),
  );

  // Exported permission: edit field_session_room
  $permissions['edit field_session_room'] = array(
    'name' => 'edit field_session_room',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'session organizer',
      '2' => 'site administrator',
    ),
  );

  // Exported permission: edit field_session_slot
  $permissions['edit field_session_slot'] = array(
    'name' => 'edit field_session_slot',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'session organizer',
      '2' => 'site administrator',
    ),
  );

  // Exported permission: edit field_slides
  $permissions['edit field_slides'] = array(
    'name' => 'edit field_slides',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: edit field_slot_datetime
  $permissions['edit field_slot_datetime'] = array(
    'name' => 'edit field_slot_datetime',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: edit field_track
  $permissions['edit field_track'] = array(
    'name' => 'edit field_track',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: edit own room content
  $permissions['edit own room content'] = array(
    'name' => 'edit own room content',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: edit own schedule_item content
  $permissions['edit own schedule_item content'] = array(
    'name' => 'edit own schedule_item content',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: edit own session content
  $permissions['edit own session content'] = array(
    'name' => 'edit own session content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: edit own time_slot content
  $permissions['edit own time_slot content'] = array(
    'name' => 'edit own time_slot content',
    'roles' => array(
      '0' => 'site administrator',
    ),
  );

  // Exported permission: schedule schedule_item
  $permissions['schedule schedule_item'] = array(
    'name' => 'schedule schedule_item',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: schedule session
  $permissions['schedule session'] = array(
    'name' => 'schedule session',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: view field_accepted
  $permissions['view field_accepted'] = array(
    'name' => 'view field_accepted',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: view field_experience
  $permissions['view field_experience'] = array(
    'name' => 'view field_experience',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'site administrator',
    ),
  );

  // Exported permission: view field_speakers
  $permissions['view field_speakers'] = array(
    'name' => 'view field_speakers',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'site administrator',
    ),
  );

  // Exported permission: view field_session_room
  $permissions['view field_session_room'] = array(
    'name' => 'view field_session_room',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'session organizer',
      '3' => 'site administrator',
    ),
  );

  // Exported permission: view field_session_slot
  $permissions['view field_session_slot'] = array(
    'name' => 'view field_session_slot',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'session organizer',
      '3' => 'site administrator',
    ),
  );

  // Exported permission: view field_slides
  $permissions['view field_slides'] = array(
    'name' => 'view field_slides',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'site administrator',
    ),
  );

  // Exported permission: view field_slot_datetime
  $permissions['view field_slot_datetime'] = array(
    'name' => 'view field_slot_datetime',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'session organizer',
      '3' => 'site administrator',
    ),
  );

  // Exported permission: view field_track
  $permissions['view field_track'] = array(
    'name' => 'view field_track',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'session organizer',
      '3' => 'site administrator',
    ),
  );

  return $permissions;
}
