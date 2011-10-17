<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function about_dcny_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_about';
  $context->description = 'Provide for about sub-menu block on about section pages';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'about*' => 'about*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-3' => array(
          'module' => 'menu_block',
          'delta' => 3,
          'region' => 'sidebar_first',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Provide for about sub-menu block on about section pages');
  $export['context_about'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
  $context->description = 'A sitewide-authenticated user context to activate the shopping cart block and anything else we need site wide for users';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
        '~admin/*' => '~admin/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'uc_cart-0' => array(
          'module' => 'uc_cart',
          'delta' => 0,
          'region' => 'sidebar_first',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('A sitewide-authenticated user context to activate the shopping cart block and anything else we need site wide for users');
  $export['sitewide'] = $context;

  return $export;
}
