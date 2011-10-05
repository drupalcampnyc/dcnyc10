<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function about_dcny_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: primary-links:1c38f6f2-ed33-11e0-9f00-3d6a5b8caab1
  $menu_links['primary-links:1c38f6f2-ed33-11e0-9f00-3d6a5b8caab1'] = array(
    'menu_name' => 'primary-links',
    'router_path' => 'node/%',
    'link_title' => 'The Camp',
    'options' => array(
      'attributes' => array(
        'title' => 'The Camp',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
    'parent_path' => 'node/15',
    'parent_uuid' => 'c0f1f910-ed32-11e0-9f00-3d6a5b8caab1',
    'uuid' => '1c38f6f2-ed33-11e0-9f00-3d6a5b8caab1',
  );
  // Exported menu link: primary-links:66450c18-ed33-11e0-9f00-3d6a5b8caab1
  $menu_links['primary-links:66450c18-ed33-11e0-9f00-3d6a5b8caab1'] = array(
    'menu_name' => 'primary-links',
    'router_path' => 'node/%',
    'link_title' => 'Venue',
    'options' => array(
      'attributes' => array(
        'title' => 'Venue',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'parent_path' => 'node/15',
    'parent_uuid' => 'c0f1f910-ed32-11e0-9f00-3d6a5b8caab1',
    'uuid' => '66450c18-ed33-11e0-9f00-3d6a5b8caab1',
  );
  // Exported menu link: primary-links:8393c46c-ed33-11e0-9f00-3d6a5b8caab1
  $menu_links['primary-links:8393c46c-ed33-11e0-9f00-3d6a5b8caab1'] = array(
    'menu_name' => 'primary-links',
    'router_path' => 'node/%',
    'link_title' => 'Getting There',
    'options' => array(
      'attributes' => array(
        'title' => 'Getting There',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
    'parent_path' => 'node/15',
    'parent_uuid' => 'c0f1f910-ed32-11e0-9f00-3d6a5b8caab1',
    'uuid' => '8393c46c-ed33-11e0-9f00-3d6a5b8caab1',
  );
  // Exported menu link: primary-links:c0f1f910-ed32-11e0-9f00-3d6a5b8caab1
  $menu_links['primary-links:c0f1f910-ed32-11e0-9f00-3d6a5b8caab1'] = array(
    'menu_name' => 'primary-links',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'attributes' => array(
        'title' => 'About',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '3',
    'uuid' => 'c0f1f910-ed32-11e0-9f00-3d6a5b8caab1',
  );
  // Exported menu link: primary-links:c1e1c142-ed33-11e0-9f00-3d6a5b8caab1
  $menu_links['primary-links:c1e1c142-ed33-11e0-9f00-3d6a5b8caab1'] = array(
    'menu_name' => 'primary-links',
    'router_path' => 'node/%',
    'link_title' => 'Drupal in NYC',
    'options' => array(
      'attributes' => array(
        'title' => 'Drupal in NYC',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
    'parent_path' => 'node/15',
    'parent_uuid' => 'c0f1f910-ed32-11e0-9f00-3d6a5b8caab1',
    'uuid' => 'c1e1c142-ed33-11e0-9f00-3d6a5b8caab1',
  );
  // Exported menu link: primary-links:faq
  $menu_links['primary-links:faq'] = array(
    'menu_name' => 'primary-links',
    'link_path' => 'faq',
    'router_path' => 'faq',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(
        'title' => 'Frequently asked questions about DrupalCampNYC',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
    'parent_path' => 'node/15',
    'parent_uuid' => 'c0f1f910-ed32-11e0-9f00-3d6a5b8caab1',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Drupal in NYC');
  t('FAQ');
  t('Getting There');
  t('The Camp');
  t('Venue');


  return $menu_links;
}
