<?php

/**
 * @file
 * Contains the administration forms for fasttoggle.module.
 */

/**
 * (Menu callback) Configures what fast toggling options are available.
 */
function fasttoggle_settings_form() {
  $form = array();

  $form['fasttoggle_label_style'] = array(
    '#type' => 'radios',
    '#title' => t('Label style'),
    '#description' => t('Select what kind of labels you want for fasttoggle links. See the README.txt for information about providing your own labels.'),
    '#options' => array(
      FASTTOGGLE_LABEL_STATUS => t('Status (reflects the current state, e.g. "published", "active")'),
      FASTTOGGLE_LABEL_ACTION => t('Action (shows what happens upon a click, e.g. "unpublish", "block")'),
    ),
    '#default_value' => variable_get('fasttoggle_label_style', FASTTOGGLE_LABEL_STATUS),
  );

  $custom_labels = variable_get('fasttoggle_labels', '');
  if (!empty($custom_labels)) {
    $form['fasttoggle_label_style']['#options'][FASTTOGGLE_LABEL_CUSTOM] = t('Custom (configure in your settings.php)');
  }

  $form['nodes'] = array(
    '#type' => 'fieldset',
    '#title' => t('Posts'),
    '#description' => t('Select what options for fast toggling of post settings are available.'),
    '#access' => user_access('administer fasttoggle'),
  );

  $form['nodes']['fasttoggle_node_settings'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Available settings'),
    '#options' => array(
      'status' => t('Status <small>(published/unpublished)</small>'),
      'sticky' => t('Sticky <small>(stays at the top of listings)</small>'),
      'promote' => t('Promoted <small>(visible on the front page)</small>'),
      'comment' => t('Topic opened/closed <small>(users are allowed/disallowed to post comments)</small>'),
    ),
    '#default_value' => array_keys(array_filter(variable_get('fasttoggle_node_settings', array('status' => TRUE, 'sticky' => TRUE, 'promote' => TRUE, 'comment' => FALSE)))),
  );

  $form['nodes']['help_text'] = array(
    '#value' => t('Configure access restrictions for these settings on the <a href="@url">access control</a> page.', array('@url' => url('admin/user/permissions', array('fragment' => 'module-fasttoggle')))),
    '#prefix' => '<div>',
    '#suffix' => '</div>',
  );


  $form['comments'] = array(
    '#type' => 'fieldset',
    '#title' => t('Comments'),
    '#description' => t('Select what options for fast toggling of comment settings are available.'),
    '#access' => user_access('administer fasttoggle'),
  );

  $form['comments']['fasttoggle_comment_settings'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Available settings'),
    '#options' => array(
      'status' => t('Status <small>(published/unpublished)</small>'),
    ),
    '#default_value' => array_keys(array_filter(variable_get('fasttoggle_comment_settings', array('status' => TRUE)))),
  );

  $form['comments']['help_text'] = array(
    '#value' => t('Configure access restrictions for these settings on the <a href="@url">access control</a> page.', array('@url' => url('admin/user/permissions', array('fragment' => 'module-fasttoggle')))),
    '#prefix' => '<div>',
    '#suffix' => '</div>',
  );


  $form['users'] = array(
    '#type' => 'fieldset',
    '#title' => t('Users'),
    '#description' => t('Select what options for fast toggling of user settings are available.'),
    '#access' => user_access('administer fasttoggle'),
  );

  $form['users']['fasttoggle_user_settings'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Available settings'),
    '#options' => array(
      'status' => t('Status <small>(unblocked/blocked)</small>'),
    ),
    '#default_value' => array_keys(array_filter(variable_get('fasttoggle_user_settings', array('status' => TRUE)))),
  );

  $form['users']['help_text'] = array(
    '#value' => t('Get a listing of all users on the <a href="@url">user overview</a> page.', array('@url' => url('admin/user/user'))),
    '#prefix' => '<div>',
    '#suffix' => '</div>',
  );

  return system_settings_form($form);
}
