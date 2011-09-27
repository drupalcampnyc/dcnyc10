<?php

/**
 * Implementation of hook_node_info().
 */
function cod_sponsor_sales_node_info() {
  $items = array(
    'sponsorship' => array(
      'name' => t('Sponsorship'),
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
