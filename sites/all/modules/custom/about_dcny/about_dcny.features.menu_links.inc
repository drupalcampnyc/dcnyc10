<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function about_dcny_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: primary-links:about/faq
  $menu_links['primary-links:about/faq'] = array(
    'menu_name' => 'primary-links',
    'link_path' => 'about/faq',
    'router_path' => 'about/faq',
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
    'parent_path' => 'node/17',
    'parent_uuid' => FALSE,
  );
  // Exported menu link: primary-links:node/14
  $menu_links['primary-links:node/14'] = array(
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
    'parent_path' => 'node/17',
    'parent_uuid' => FALSE,
    'uuid' => FALSE,
  );
  // Exported menu link: primary-links:node/15
  $menu_links['primary-links:node/15'] = array(
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
    'parent_path' => 'node/17',
    'parent_uuid' => FALSE,
    'uuid' => FALSE,
  );
  // Exported menu link: primary-links:node/16
  $menu_links['primary-links:node/16'] = array(
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
    'parent_path' => 'node/17',
    'parent_uuid' => FALSE,
    'uuid' => FALSE,
  );
  // Exported menu link: primary-links:node/17
  $menu_links['primary-links:node/17'] = array(
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
    'expanded' => '1',
    'weight' => '3',
    'uuid' => FALSE,
  );
  // Exported menu link: primary-links:node/18
  $menu_links['primary-links:node/18'] = array(
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
    'parent_path' => 'node/17',
    'parent_uuid' => FALSE,
    'uuid' => FALSE,
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
