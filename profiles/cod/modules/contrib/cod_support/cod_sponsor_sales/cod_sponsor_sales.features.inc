<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cod_sponsor_sales_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_uc_product_default_classes().
 */
function cod_sponsor_sales_uc_product_default_classes() {
  $items = array(
    'sponsorship' => array(
      'name' => t('Sponsorship product'),
      'module' => 'uc_product',
      'description' => '',
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
function cod_sponsor_sales_views_api() {
  return array(
    'api' => '2',
  );
}
