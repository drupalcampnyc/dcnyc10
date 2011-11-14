<?php

/**
 * Implementation of hook_views_default_views().
 */
function cod_base_views_default_views() {
  $views = array();

  // Exported view: diet_requirements
  $view = new view;
  $view->name = 'diet_requirements';
  $view->description = 'Attendee dietary requirements';
  $view->tag = '';
  $view->base_table = 'users';
  $view->core = 6;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'value' => array(
      'label' => '',
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
      'id' => 'value',
      'table' => 'profile_values_profile_diet',
      'field' => 'value',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'value' => array(
      'id' => 'value',
      'table' => 'profile_values_profile_diet',
      'field' => 'value',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'role',
    'role' => array(
      10 => 10,
    ),
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Total Number of Meal Options Selected');
  $handler->override_option('style_plugin', 'views_calc');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'summary' => '',
    'columns' => array(
      'value' => 'value',
    ),
    'info' => array(
      'value' => array(
        'sortable' => 0,
        'separator' => '',
        'justification' => 'views_calc_justify_none',
        'has_calc' => 1,
        'calc' => array(
          'COUNT' => 'COUNT',
        ),
      ),
    ),
    'default' => '-1',
    'detailed_values' => '1',
  ));
  $handler = $view->new_display('page', 'Total', 'page_1');
  $handler->override_option('fields', array(
    'value' => array(
      'label' => '',
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
      'id' => 'value',
      'table' => 'profile_values_profile_diet',
      'field' => 'value',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('items_per_page', 0);
  $handler->override_option('path', 'conference-admin/diet');
  $handler->override_option('menu', array(
    'type' => 'normal',
    'title' => 'Diet Totals',
    'description' => '',
    'weight' => '3',
    'name' => 'menu-conference-admin',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler = $view->new_display('attachment', 'Vegan', 'attachment_1');
  $handler->override_option('filters', array(
    'value' => array(
      'operator' => 'in',
      'value' => array(
        'Vegan' => 'Vegan',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'value',
      'table' => 'profile_values_profile_diet',
      'field' => 'value',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('title', 'Total Number of Vegan Options Selected');
  $handler->override_option('header', '<strong>Vegan</strong>');
  $handler->override_option('header_format', '1');
  $handler->override_option('header_empty', 1);
  $handler->override_option('attachment_position', 'after');
  $handler->override_option('inherit_arguments', TRUE);
  $handler->override_option('inherit_exposed_filters', FALSE);
  $handler->override_option('inherit_pager', FALSE);
  $handler->override_option('render_pager', TRUE);
  $handler->override_option('displays', array(
    'page_1' => 'page_1',
    'default' => 0,
  ));
  $handler = $view->new_display('attachment', 'Vegetarian', 'attachment_2');
  $handler->override_option('filters', array(
    'value' => array(
      'operator' => 'in',
      'value' => array(
        'Vegetarian' => 'Vegetarian',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'value',
      'table' => 'profile_values_profile_diet',
      'field' => 'value',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('title', 'Total Number of Vegetarian Options Selected');
  $handler->override_option('header', '<strong>Vegetarian</strong>');
  $handler->override_option('header_format', '1');
  $handler->override_option('header_empty', 1);
  $handler->override_option('attachment_position', 'after');
  $handler->override_option('inherit_arguments', TRUE);
  $handler->override_option('inherit_exposed_filters', FALSE);
  $handler->override_option('inherit_pager', FALSE);
  $handler->override_option('render_pager', TRUE);
  $handler->override_option('displays', array(
    'page_1' => 'page_1',
    'default' => 0,
  ));
  $handler = $view->new_display('attachment', 'Kosher / Hallal', 'attachment_3');
  $handler->override_option('filters', array(
    'value' => array(
      'operator' => 'in',
      'value' => array(
        'Kosher / Hallal' => 'Kosher / Hallal',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'value',
      'table' => 'profile_values_profile_diet',
      'field' => 'value',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('title', 'Total Number of Kosher / Hallal Options Selected');
  $handler->override_option('header', '<strong>Kosher / Hallal</strong>');
  $handler->override_option('header_format', '1');
  $handler->override_option('header_empty', 1);
  $handler->override_option('attachment_position', 'after');
  $handler->override_option('inherit_arguments', TRUE);
  $handler->override_option('inherit_exposed_filters', FALSE);
  $handler->override_option('inherit_pager', FALSE);
  $handler->override_option('render_pager', TRUE);
  $handler->override_option('displays', array(
    'page_1' => 'page_1',
    'default' => 0,
  ));
  $handler = $view->new_display('attachment', 'Gluten Free', 'attachment_4');
  $handler->override_option('filters', array(
    'value' => array(
      'operator' => 'in',
      'value' => array(
        'Gluten Free' => 'Gluten Free',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'value',
      'table' => 'profile_values_profile_diet',
      'field' => 'value',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('title', 'Total Number of Gluten Free Options Selected');
  $handler->override_option('header', '<strong>Gluten Free</strong>');
  $handler->override_option('header_format', '1');
  $handler->override_option('header_empty', 1);
  $handler->override_option('attachment_position', 'after');
  $handler->override_option('inherit_arguments', TRUE);
  $handler->override_option('inherit_exposed_filters', FALSE);
  $handler->override_option('inherit_pager', FALSE);
  $handler->override_option('render_pager', TRUE);
  $handler->override_option('displays', array(
    'page_1' => 'page_1',
    'default' => 0,
  ));

  $views[$view->name] = $view;

  // Exported view: tshirt_sizes
  $view = new view;
  $view->name = 'tshirt_sizes';
  $view->description = 'Attendee t-shirt size selection totals';
  $view->tag = '';
  $view->base_table = 'users';
  $view->core = 6;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'value' => array(
      'label' => '',
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
      'empty' => 'No Selection Made',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'value',
      'table' => 'profile_values_profile_shirt',
      'field' => 'value',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'value' => array(
      'operator' => 'not in',
      'value' => array(
        'No thanks!' => 'No thanks!',
        'Small' => 'Small',
        'Medium' => 'Medium',
        'Large' => 'Large',
        'X-Large' => 'X-Large',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'value',
      'table' => 'profile_values_profile_shirt',
      'field' => 'value',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'role',
    'role' => array(
      10 => 10,
    ),
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Total Number of T-Shirt Options Selected');
  $handler->override_option('style_plugin', 'views_calc');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'summary' => '',
    'columns' => array(
      'value' => 'value',
    ),
    'info' => array(
      'value' => array(
        'sortable' => 0,
        'separator' => '',
        'justification' => 'views_calc_justify_none',
        'has_calc' => 1,
        'calc' => array(
          'COUNT' => 'COUNT',
        ),
      ),
    ),
    'default' => '-1',
    'detailed_values' => '1',
  ));
  $handler = $view->new_display('page', 'Total', 'page_1');
  $handler->override_option('filters', array());
  $handler->override_option('items_per_page', 0);
  $handler->override_option('path', 'conference-admin/tshirt');
  $handler->override_option('menu', array(
    'type' => 'normal',
    'title' => 'T-Shirt Totals',
    'description' => '',
    'weight' => '4',
    'name' => 'menu-conference-admin',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler = $view->new_display('attachment', 'No thanks', 'attachment_1');
  $handler->override_option('filters', array(
    'value' => array(
      'operator' => 'in',
      'value' => array(
        'No thanks!' => 'No thanks!',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'value',
      'table' => 'profile_values_profile_shirt',
      'field' => 'value',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('title', 'Total Number of "No thanks!" Selected');
  $handler->override_option('header', '<strong>No thanks!</strong>');
  $handler->override_option('header_format', '1');
  $handler->override_option('header_empty', 1);
  $handler->override_option('attachment_position', 'after');
  $handler->override_option('inherit_arguments', TRUE);
  $handler->override_option('inherit_exposed_filters', FALSE);
  $handler->override_option('inherit_pager', FALSE);
  $handler->override_option('render_pager', TRUE);
  $handler->override_option('displays', array(
    'page_1' => 'page_1',
    'default' => 0,
  ));
  $handler = $view->new_display('attachment', 'Small', 'attachment_2');
  $handler->override_option('filters', array(
    'value' => array(
      'operator' => 'in',
      'value' => array(
        'Small' => 'Small',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'value',
      'table' => 'profile_values_profile_shirt',
      'field' => 'value',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('title', 'Total Number of Small Selected');
  $handler->override_option('header', '<strong>Small</strong>');
  $handler->override_option('header_format', '1');
  $handler->override_option('header_empty', 1);
  $handler->override_option('attachment_position', 'after');
  $handler->override_option('inherit_arguments', TRUE);
  $handler->override_option('inherit_exposed_filters', FALSE);
  $handler->override_option('inherit_pager', FALSE);
  $handler->override_option('render_pager', TRUE);
  $handler->override_option('displays', array(
    'page_1' => 'page_1',
    'default' => 0,
  ));
  $handler = $view->new_display('attachment', 'Medium', 'attachment_3');
  $handler->override_option('filters', array(
    'value' => array(
      'operator' => 'in',
      'value' => array(
        'Medium' => 'Medium',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'value',
      'table' => 'profile_values_profile_shirt',
      'field' => 'value',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('title', 'Total Number of Medium Selected');
  $handler->override_option('header', '<strong>Medium</strong>');
  $handler->override_option('header_format', '1');
  $handler->override_option('header_empty', 1);
  $handler->override_option('attachment_position', 'after');
  $handler->override_option('inherit_arguments', TRUE);
  $handler->override_option('inherit_exposed_filters', FALSE);
  $handler->override_option('inherit_pager', FALSE);
  $handler->override_option('render_pager', TRUE);
  $handler->override_option('displays', array(
    'page_1' => 'page_1',
    'default' => 0,
  ));
  $handler = $view->new_display('attachment', 'Large', 'attachment_4');
  $handler->override_option('filters', array(
    'value' => array(
      'operator' => 'in',
      'value' => array(
        'Large' => 'Large',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'value',
      'table' => 'profile_values_profile_shirt',
      'field' => 'value',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('title', 'Total Number of Large Selected');
  $handler->override_option('header', '<strong>Large</strong>');
  $handler->override_option('header_format', '1');
  $handler->override_option('header_empty', 1);
  $handler->override_option('attachment_position', 'after');
  $handler->override_option('inherit_arguments', TRUE);
  $handler->override_option('inherit_exposed_filters', FALSE);
  $handler->override_option('inherit_pager', FALSE);
  $handler->override_option('render_pager', TRUE);
  $handler->override_option('displays', array(
    'page_1' => 'page_1',
    'default' => 0,
  ));
  $handler = $view->new_display('attachment', 'X-Large', 'attachment_5');
  $handler->override_option('filters', array(
    'value' => array(
      'operator' => 'in',
      'value' => array(
        'X-Large' => 'X-Large',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'value',
      'table' => 'profile_values_profile_shirt',
      'field' => 'value',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('title', 'Total Number of X-Large Selected');
  $handler->override_option('header', '<strong>X-Large</strong>');
  $handler->override_option('header_format', '1');
  $handler->override_option('header_empty', 1);
  $handler->override_option('attachment_position', 'after');
  $handler->override_option('inherit_arguments', TRUE);
  $handler->override_option('inherit_exposed_filters', FALSE);
  $handler->override_option('inherit_pager', FALSE);
  $handler->override_option('render_pager', TRUE);
  $handler->override_option('displays', array(
    'page_1' => 'page_1',
    'default' => 0,
  ));

  $views[$view->name] = $view;

  return $views;
}
