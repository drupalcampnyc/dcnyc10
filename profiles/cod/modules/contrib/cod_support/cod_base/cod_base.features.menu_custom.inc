<?php

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function cod_base_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-conference-admin
  $menus['menu-conference-admin'] = array(
    'menu_name' => 'menu-conference-admin',
    'title' => 'Conference management',
    'description' => '',
  );
  // Exported menu: menu-quick-links
  $menus['menu-quick-links'] = array(
    'menu_name' => 'menu-quick-links',
    'title' => 'Quick links - Authenticated',
    'description' => 'Utility links that display on every page of the site, such as "Your account" and "Your schedule"',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Conference management');
  t('Quick links - Authenticated');
  t('Utility links that display on every page of the site, such as "Your account" and "Your schedule"');


  return $menus;
}
