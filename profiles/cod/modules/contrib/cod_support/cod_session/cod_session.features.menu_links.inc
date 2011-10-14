<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function cod_session_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-quick-links:program/session-schedule/your-schedule
  $menu_links['menu-quick-links:program/session-schedule/your-schedule'] = array(
    'menu_name' => 'menu-quick-links',
    'link_path' => 'program/session-schedule/your-schedule',
    'router_path' => 'program/session-schedule/your-schedule',
    'link_title' => 'Your schedule',
    'options' => array(
      'attributes' => array(
        'title' => 'Your personal conference schedule',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: primary-links:program/session-schedule
  $menu_links['primary-links:program/session-schedule'] = array(
    'menu_name' => 'primary-links',
    'link_path' => 'program/session-schedule',
    'router_path' => 'program/session-schedule',
    'link_title' => 'Session schedule',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
    'parent_path' => 'node/2',
    'parent_uuid' => FALSE,
  );
  // Exported menu link: primary-links:program/sessions
  $menu_links['primary-links:program/sessions'] = array(
    'menu_name' => 'primary-links',
    'link_path' => 'program/sessions',
    'router_path' => 'program/sessions',
    'link_title' => 'Sessions',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'parent_path' => 'node/2',
    'parent_uuid' => FALSE,
  );
  // Exported menu link: primary-links:program/speakers
  $menu_links['primary-links:program/speakers'] = array(
    'menu_name' => 'primary-links',
    'link_path' => 'program/speakers',
    'router_path' => 'program/speakers',
    'link_title' => 'Speakers',
    'options' => array(
      'attributes' => array(
        'title' => 'A list of those speaking at DrupalCampNYC',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
    'parent_path' => 'node/2',
    'parent_uuid' => FALSE,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Session schedule');
  t('Sessions');
  t('Speakers');
  t('Your schedule');


  return $menu_links;
}
