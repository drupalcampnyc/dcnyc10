<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cod_events_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_uc_product_default_classes().
 */
function cod_events_uc_product_default_classes() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'module' => 'uc_product',
      'description' => t('Provides free and paid event registration on the Event content type.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function cod_events_views_api() {
  return array(
    'api' => '2',
  );
}
