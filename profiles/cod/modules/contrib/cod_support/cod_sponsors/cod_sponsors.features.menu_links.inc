<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function cod_sponsors_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-conference-admin:conference-admin/sponsors
  $menu_links['menu-conference-admin:conference-admin/sponsors'] = array(
    'menu_name' => 'menu-conference-admin',
    'link_path' => 'conference-admin/sponsors',
    'router_path' => 'conference-admin/sponsors',
    'link_title' => 'Sponsor moderation',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '1',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Sponsor moderation');


  return $menu_links;
}
