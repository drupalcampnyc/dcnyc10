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
  // Exported menu link: primary-links:node/12
  $menu_links['primary-links:node/12'] = array(
    'menu_name' => 'primary-links',
    'router_path' => 'node/%',
    'link_title' => 'How to Sponsor',
    'options' => array(
      'attributes' => array(
        'title' => 'How to Sponsor',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
    'parent_path' => 'node/13',
    'parent_uuid' => FALSE,
    'uuid' => FALSE,
  );
  // Exported menu link: primary-links:node/13
  $menu_links['primary-links:node/13'] = array(
    'menu_name' => 'primary-links',
    'router_path' => 'node/%',
    'link_title' => 'Sponsors',
    'options' => array(
      'attributes' => array(
        'title' => 'Sponsors',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '0',
    'uuid' => FALSE,
  );
  // Exported menu link: primary-links:our-sponsors
  $menu_links['primary-links:our-sponsors'] = array(
    'menu_name' => 'primary-links',
    'link_path' => 'our-sponsors',
    'router_path' => 'our-sponsors',
    'link_title' => 'Our Sponsors',
    'options' => array(
      'attributes' => array(
        'title' => 'A listing of Sponsor profiles',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'parent_path' => 'node/13',
    'parent_uuid' => FALSE,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('How to Sponsor');
  t('Our Sponsors');
  t('Sponsor moderation');
  t('Sponsors');


  return $menu_links;
}
