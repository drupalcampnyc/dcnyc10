<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function cod_session_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_program';
  $context->description = 'Provide for program sub-menu block on program section pages';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'program/sessions' => 'program/sessions',
        'program/community-spotlights' => 'program/community-spotlights',
        'program/sessions/accepted*' => 'program/sessions/accepted*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-1' => array(
          'module' => 'menu_block',
          'delta' => 1,
          'region' => 'sidebar_first',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Provide for program sub-menu block on program section pages');
  $export['context_program'] = $context;

  return $export;
}
