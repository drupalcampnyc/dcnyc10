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
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-Sponsors-block_4' => array(
          'module' => 'views',
          'delta' => 'Sponsors-block_4',
          'weight' => 19,
          'region' => 'right',
          'status' => '0',
          'label' => 'Sponsors: Home Page Platinum Featured',
          'type' => 'context_ui',
        ),
        'views-attendees-block_1' => array(
          'module' => 'views',
          'delta' => 'attendees-block_1',
          'weight' => 20,
          'region' => 'right',
          'status' => '0',
          'label' => 'Attendee block',
          'type' => 'context_ui',
        ),
        'views-featured_sessions-block_1' => array(
          'module' => 'views',
          'delta' => 'featured_sessions-block_1',
          'weight' => 19,
          'region' => 'content',
          'status' => '0',
          'label' => 'featured_sessions: Featured Sessions',
          'type' => 'context_ui',
        ),
        'views-news-block_1' => array(
          'module' => 'views',
          'delta' => 'news-block_1',
          'weight' => 20,
          'region' => 'content',
          'status' => '0',
          'label' => 'news: Single news item block',
          'type' => 'context_ui',
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
