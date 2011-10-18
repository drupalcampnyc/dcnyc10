<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function cod_front_page_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_ui-section-front';
  $context->description = 'Front Page';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-1' => array(
          'module' => 'block',
          'delta' => 1,
          'region' => 'sidebar_last',
          'weight' => 0,
        ),
        'block-2' => array(
          'module' => 'block',
          'delta' => 2,
          'region' => 'sidebar_last',
          'weight' => 1,
        ),
        'countdown-0' => array(
          'module' => 'countdown',
          'delta' => 0,
          'region' => 'sidebar_last',
          'weight' => 2,
        ),
        'block-3' => array(
          'module' => 'block',
          'delta' => 3,
          'region' => 'sidebar_last',
          'weight' => 3,
        ),
        'views-news-block_1' => array(
          'module' => 'views',
          'delta' => 'news-block_1',
          'region' => 'content',
          'weight' => 0,
        ),
        'views-sponsors_front_page-block_1' => array(
          'module' => 'views',
          'delta' => 'sponsors_front_page-block_1',
          'region' => 'sponsors',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Front Page');
  $export['context_ui-section-front'] = $context;

  return $export;
}
