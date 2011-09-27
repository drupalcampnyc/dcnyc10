<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function cod_sponsor_sales_user_default_permissions() {
  $permissions = array();

  // Exported permission: create sponsorship products
  $permissions['create sponsorship products'] = array(
    'name' => 'create sponsorship products',
    'roles' => array(
      '0' => 'sponsor organizer',
    ),
  );

  // Exported permission: delete all sponsorship products
  $permissions['delete all sponsorship products'] = array(
    'name' => 'delete all sponsorship products',
    'roles' => array(),
  );

  // Exported permission: delete own sponsor content
  $permissions['delete own sponsor content'] = array(
    'name' => 'delete own sponsor content',
    'roles' => array(),
  );

  // Exported permission: delete own sponsorship products
  $permissions['delete own sponsorship products'] = array(
    'name' => 'delete own sponsorship products',
    'roles' => array(),
  );

  // Exported permission: edit all sponsorship products
  $permissions['edit all sponsorship products'] = array(
    'name' => 'edit all sponsorship products',
    'roles' => array(
      '0' => 'sponsor organizer',
    ),
  );

  // Exported permission: edit field_sponsorship_level
  $permissions['edit field_sponsorship_level'] = array(
    'name' => 'edit field_sponsorship_level',
    'roles' => array(
      '0' => 'sponsor organizer',
    ),
  );

  // Exported permission: edit own sponsor content
  $permissions['edit own sponsor content'] = array(
    'name' => 'edit own sponsor content',
    'roles' => array(),
  );

  // Exported permission: edit own sponsorship products
  $permissions['edit own sponsorship products'] = array(
    'name' => 'edit own sponsorship products',
    'roles' => array(
      '0' => 'sponsor organizer',
    ),
  );

  return $permissions;
}
