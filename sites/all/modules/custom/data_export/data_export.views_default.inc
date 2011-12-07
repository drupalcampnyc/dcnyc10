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
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'breadcrumb' => '',
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
      'default_argument_fixed' => '44',
      'default_argument_php' => '',
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(),
      'validate_argument_type' => 'tid',
      'validate_argument_signup_status' => 'any',
      'validate_argument_signup_node_access' => 0,
      'validate_argument_php' => '',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        2 => 0,
        11 => 0,
        4 => 0,
        10 => 0,
        7 => 0,
        12 => 0,
        5 => 0,
        3 => 0,
        6 => 0,
        8 => 0,
      ),
      'validate_argument_node_type' => array(
        'news' => 0,
        'page' => 0,
        'room' => 0,
        'schedule_item' => 0,
        'session' => 0,
        'time_slot' => 0,
        'product' => 0,
        'event' => 0,
        'sponsorship' => 0,
        'faq' => 0,
        'sponsor' => 0,
        'supporter' => 0,
        'webform' => 0,
      ),
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_node_flag_name' => '*relationship*',
      'validate_argument_node_flag_test' => 'flaggable',
      'validate_argument_node_flag_id_type' => 'id',
      'validate_argument_user_flag_name' => '*relationship*',
      'validate_argument_user_flag_test' => 'flaggable',
      'validate_argument_user_flag_id_type' => 'id',
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
  $handler->override_option('arguments', array(
    'nid' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'breadcrumb' => '',
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
      'default_argument_fixed' => '44',
      'default_argument_php' => '',
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(),
      'validate_argument_type' => 'tid',
      'validate_argument_signup_status' => 'any',
      'validate_argument_signup_node_access' => 0,
      'validate_argument_php' => '',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        2 => 0,
        11 => 0,
        4 => 0,
        10 => 0,
        7 => 0,
        12 => 0,
        5 => 0,
        3 => 0,
        6 => 0,
        8 => 0,
      ),
      'override' => array(
        'button' => 'Use default',
      ),
      'validate_argument_node_type' => array(
        'news' => 0,
        'page' => 0,
        'room' => 0,
        'schedule_item' => 0,
        'session' => 0,
        'time_slot' => 0,
        'product' => 0,
        'event' => 0,
        'sponsorship' => 0,
        'faq' => 0,
        'sponsor' => 0,
        'supporter' => 0,
        'webform' => 0,
      ),
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_node_flag_name' => '*relationship*',
      'validate_argument_node_flag_test' => 'flaggable',
      'validate_argument_node_flag_id_type' => 'id',
      'validate_argument_user_flag_name' => '*relationship*',
      'validate_argument_user_flag_test' => 'flaggable',
      'validate_argument_user_flag_id_type' => 'id',
    ),
  ));
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
  $handler = $view->new_display('views_data_export', 'Data export full', 'views_data_export_2');
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
    'value_2' => array(
      'label' => 'Dietary',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
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
      'empty' => 'None',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'exclude' => 0,
      'id' => 'value_2',
      'table' => 'profile_values_profile_diet',
      'field' => 'value',
      'relationship' => 'uid',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'value_3' => array(
      'label' => 'T-Shirt',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
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
      'exclude' => 0,
      'id' => 'value_3',
      'table' => 'profile_values_profile_shirt',
      'field' => 'value',
      'relationship' => 'uid',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('title', 'Attendee: All Data');
  $handler->override_option('items_per_page', '0');
  $handler->override_option('style_plugin', 'views_data_export_csv');
  $handler->override_option('style_options', array(
    'mission_description' => FALSE,
    'description' => '',
  ));
  $handler->override_option('row_plugin', '');
  $handler->override_option('path', 'attendee-all/%/csv');
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
  $handler->override_option('sitename_title', 0);
  $handler->override_option('use_batch', TRUE);
  $handler = $view->new_display('views_data_export', 'Data export late', 'views_data_export_3');
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
    'value_2' => array(
      'label' => 'Dietary',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
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
      'empty' => 'None',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'exclude' => 0,
      'id' => 'value_2',
      'table' => 'profile_values_profile_diet',
      'field' => 'value',
      'relationship' => 'uid',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'value_3' => array(
      'label' => 'T-Shirt',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
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
      'exclude' => 0,
      'id' => 'value_3',
      'table' => 'profile_values_profile_shirt',
      'field' => 'value',
      'relationship' => 'uid',
      'override' => array(
        'button' => 'Use default',
      ),
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
    'signup_time' => array(
      'operator' => '>',
      'value' => array(
        'type' => 'date',
        'value' => '2011-12-06 00:00:00',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'signup_time',
      'table' => 'signup_log',
      'field' => 'signup_time',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'uid',
    ),
  ));
  $handler->override_option('title', 'Attendee: All Data');
  $handler->override_option('items_per_page', '0');
  $handler->override_option('style_plugin', 'views_data_export_csv');
  $handler->override_option('style_options', array(
    'mission_description' => FALSE,
    'description' => '',
  ));
  $handler->override_option('row_plugin', '');
  $handler->override_option('path', 'attendee-all/%/csv');
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
  $handler->override_option('sitename_title', 0);
  $handler->override_option('use_batch', TRUE);

  $views[$view->name] = $view;

  return $views;
}
