<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function cod_sponsors_user_default_permissions() {
  $permissions = array();

  // Exported permission: create sponsor content
  $permissions['create sponsor content'] = array(
    'name' => 'create sponsor content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: create supporter content
  $permissions['create supporter content'] = array(
    'name' => 'create supporter content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: delete any sponsor content
  $permissions['delete any sponsor content'] = array(
    'name' => 'delete any sponsor content',
    'roles' => array(
      '0' => 'sponsor organizer',
    ),
  );

  // Exported permission: delete any supporter content
  $permissions['delete any supporter content'] = array(
    'name' => 'delete any supporter content',
    'roles' => array(
      '0' => 'sponsor organizer',
    ),
  );

  // Exported permission: delete own supporter content
  $permissions['delete own supporter content'] = array(
    'name' => 'delete own supporter content',
    'roles' => array(),
  );

  // Exported permission: edit any sponsor content
  $permissions['edit any sponsor content'] = array(
    'name' => 'edit any sponsor content',
    'roles' => array(
      '0' => 'content manager',
      '1' => 'sponsor organizer',
    ),
  );

  // Exported permission: edit any supporter content
  $permissions['edit any supporter content'] = array(
    'name' => 'edit any supporter content',
    'roles' => array(
      '0' => 'sponsor organizer',
    ),
  );

  // Exported permission: edit field_logo
  $permissions['edit field_logo'] = array(
    'name' => 'edit field_logo',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'sponsor organizer',
    ),
  );

  // Exported permission: edit field_logo_high
  $permissions['edit field_logo_high'] = array(
    'name' => 'edit field_logo_high',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_related_attendees
  $permissions['edit field_related_attendees'] = array(
    'name' => 'edit field_related_attendees',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'sponsor organizer',
    ),
  );

  // Exported permission: edit field_supporter_display
  $permissions['edit field_supporter_display'] = array(
    'name' => 'edit field_supporter_display',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_url
  $permissions['edit field_url'] = array(
    'name' => 'edit field_url',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'sponsor organizer',
    ),
  );

  // Exported permission: edit own supporter content
  $permissions['edit own supporter content'] = array(
    'name' => 'edit own supporter content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: view field_logo
  $permissions['view field_logo'] = array(
    'name' => 'view field_logo',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_logo_high
  $permissions['view field_logo_high'] = array(
    'name' => 'view field_logo_high',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_related_attendees
  $permissions['view field_related_attendees'] = array(
    'name' => 'view field_related_attendees',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_sponsorship_level
  $permissions['view field_sponsorship_level'] = array(
    'name' => 'view field_sponsorship_level',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_supporter_display
  $permissions['view field_supporter_display'] = array(
    'name' => 'view field_supporter_display',
    'roles' => array(),
  );

  // Exported permission: view field_url
  $permissions['view field_url'] = array(
    'name' => 'view field_url',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  return $permissions;
}
