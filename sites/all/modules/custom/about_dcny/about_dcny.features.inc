<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function about_dcny_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function about_dcny_node_info() {
  $items = array(
    'faq' => array(
      'name' => t('Frequently Asked Question'),
      'module' => 'features',
      'description' => t('A question and answer about DrupalCampNYC'),
      'has_title' => '1',
      'title_label' => t('Question'),
      'has_body' => '1',
      'body_label' => t('Answer'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function about_dcny_views_api() {
  return array(
    'api' => '2',
  );
}
