<?php

/**
 * Implementation of hook_views_default_views().
 */
function data_export_views_default_views() {
  $views = array();

  // Exported view: cod_signup_export
  $view = new view;
  $view->name = 'cod_signup_export';
  $view->description = 'Export data for name tags and such';
  $view->tag = 'signup';
  $view->base_table = 'signup_log';
  $view->core = 6;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'nid' => array(
      'label' => 'Signup node',
      'required' => 1,
      'id' => 'nid',
      'table' => 'signup_log',
      'field' => 'nid',
      'relationship' => 'none',
    ),
    'uid' => array(
      'label' => 'Signup user',
      'required' => 1,
      'id' => 'uid',
      'table' => 'signup_log',
      'field' => 'uid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'value' => array(
      'label' => 'First name',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_user' => 1,
      'exclude' => 0,
      'id' => 'value',
      'table' => 'profile_values_profile_first',
      'field' => 'value',
      'relationship' => 'uid',
    ),
    'value_1' => array(
      'label' => 'Last name',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_user' => 1,
      'exclude' => 0,
      'id' => 'value_1',
      'table' => 'profile_values_profile_last',
      'field' => 'value',
      'relationship' => 'uid',
    ),
  ));
  $handler->override_option('sorts', array(
    'value' => array(
      'order' => 'ASC',
      'id' => 'value',
      'table' => 'profile_values_profile_last',
      'field' => 'value',
      'relationship' => 'uid',
    ),
  ));
  $handler->override_option('arguments', array(
    'nid' => array(
      'default_action' => 'ignore',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'signup_status',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'relationship' => 'nid',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(),
      'validate_argument_type' => 'tid',
      'validate_argument_signup_status' => 'any',
      'validate_argument_signup_node_access' => 1,
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('filters', array(
    'uid' => array(
      'operator' => 'not in',
      'value' => array(
        0 => 0,
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'uid',
      'table' => 'users',
      'field' => 'uid',
      'relationship' => 'uid',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'perm',
    'perm' => 'administer all signups',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Check-in attendees');
  $handler->override_option('items_per_page', 0);
  $handler->override_option('use_pager', 0);
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->override_option('items_per_page', '0');
  $handler->override_option('style_plugin', 'views_data_export_csv');
  $handler->override_option('style_options', array(
    'mission_description' => FALSE,
    'description' => '',
    'attach_text' => 'CSV',
    'provide_file' => 0,
    'filename' => '%view.csv',
    'help' => '',
    'parent_sort' => 0,
    'separator' => ',',
    'quote' => 1,
    'trim' => 0,
    'replace_newlines' => 0,
    'newline_replacement' => ', ',
    'header' => 1,
    'encoding' => '',
  ));
  $handler->override_option('row_plugin', '');
  $handler->override_option('path', 'attendee-export/%/csv');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('displays', array());
  $handler->override_option('sitename_title', FALSE);
  $handler->override_option('use_batch', TRUE);

  $views[$view->name] = $view;

  return $views;
}
