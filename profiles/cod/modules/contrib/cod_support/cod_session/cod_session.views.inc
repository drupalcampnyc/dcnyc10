<?php
/**
 * @file
 * Views hooks for cod_session feature
 */

/**
 * Implementation of hook_views_plugins().
 */
function cod_session_views_plugins() {
  return array(
    'style' => array(
      'cod_session_schedule' => array(
        'title' => t('Session schedule'),
        'help' => t('Display view as a table with room columns and time slot rows'),
        'handler' => 'cod_session_views_style_plugin_schedule',
        'theme' => 'cod_session_schedule',
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'uses grouping' => TRUE,
        'uses options' => TRUE,
        'use sort' => FALSE,
        'use pager' => FALSE, 
        'use ajax' => FALSE, 
        'use more' => FALSE, 
        'type' => 'normal',
        'help topic' => 'style-unformatted',
        'even empty' => TRUE, // Make the View render when there are no results.
        ),
      ),
    );
}


