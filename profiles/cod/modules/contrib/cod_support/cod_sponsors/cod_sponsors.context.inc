<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function cod_sponsors_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_sponsors';
  $context->description = 'Provide for sponsors sub-menu block on sponsor section pages';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'sponsors*' => 'sponsors*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-2' => array(
          'module' => 'menu_block',
          'delta' => 2,
          'region' => 'sidebar_first',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Provide for sponsors sub-menu block on sponsor section pages');
  $export['context_sponsors'] = $context;

  return $export;
}
