<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function anon_user_menu_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'anon_user_menu';
  $context->description = 'Quick links for those not logged in';
  $context->tag = '';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'user-0' => array(
          'module' => 'user',
          'delta' => 0,
          'region' => 'userbar_last',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Quick links for those not logged in');
  $export['anon_user_menu'] = $context;

  return $export;
}
