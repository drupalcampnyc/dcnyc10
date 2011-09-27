<?php

/**
 * @file
 * Handles toggling of options.
 */

/**
 * Menu callback. Toggle options for a node if the action is confirmed via
 * POST. Otherwise, display a confirmation form.
 */
function fasttoggle_node_option($node, $option) {
  $options = fasttoggle_get_options('node', $node);

  // Check if the action is valid. This is essential to ensure the user has
  // access to the action.
  if (isset($options[$option]) && isset($_GET['token']) && drupal_valid_token($_GET['token'], $option .'_'. $node->nid, TRUE)) {
    // The action is confirmed: either via form submit or via AJAX/POST
    if (isset($_POST['confirm']) && $_POST['confirm']) {
      // Get the next ID.
      while (key($options[$option]) != $node->$option) next($options[$option]);
      if (next($options[$option]) === FALSE) reset($options[$option]);

      // Save the node.
      $node->$option = key($options[$option]);
      node_save($node);

      // Let other modules respond.
      module_invoke_all('fasttoggle_toggle', 'node', $node, $option);

      // Output the new status for the updated link text on AJAX changes
      if (isset($_POST['javascript']) && $_POST['javascript']) {
        drupal_set_header('Content-Type: text/javascript; charset=utf-8');
        echo drupal_to_js(array(
          'text' => $options[$option][intval($node->$option)],
          'callback' => 'node',
          'option' => $option,
          'status' => $node->$option,
          'className' => 'fasttoggle-status-node-'. $option .'-'. intval($node->$option),
        ));
        exit;
      }
      else {
        drupal_goto();
      }
    }
    else {
      // The action is not confirmed. The user came here through a regular link;
      // no AJAX was involved. That means, we need a confirmation form so that
      // we get a POST form.
      $labels = _fasttoggle_get_label('node_'. $option, FASTTOGGLE_LABEL_STATUS);
      return drupal_get_form('fasttoggle_node_option_confirm', $node, $labels[intval(!$node->$option)]);
    }
  }
  else {
    return MENU_NOT_FOUND;
  }
}


/**
 * Confirmation form for the option change of a node.
 */
function fasttoggle_node_option_confirm($form_state, $node, $option) {
  return confirm_form(array(),
    t('Are you sure you want to set the post %title to %option?', array('%title' => $node->title, '%option' => $option)),
    $_GET['destination'] ? $_GET['destination'] : 'node/'. $node->nid,
    '',
    t('Change'), t('Cancel')
  );
}


/**
 * Menu callback. Toggle the status of a user if the action is confirmed via
 * POST. Otherwise, display a confirmation form.
 */
function fasttoggle_user_option($user, $option) {
  $options = fasttoggle_get_options('user', $user);

  // Check if the action is valid. This is essential to ensure the user has
  // access to the action.
  if (isset($options[$option]) && isset($_GET['token']) && drupal_valid_token($_GET['token'], $option .'_'. $user->uid, TRUE)) {
    if (isset($_POST['confirm']) && $_POST['confirm']) {
      $array = array($option => !$user->$option);
      $user = user_save($user, $array);

      // Let other modules respond.
      module_invoke_all('fasttoggle_toggle', 'user', $user, $option);

      // Output the new option for the updated link text on AJAX changes
      if (isset($_POST['javascript']) && $_POST['javascript']) {
        drupal_set_header('Content-Type: text/javascript; charset=utf-8');
        echo drupal_to_js(array(
          'text' => $options[$option][intval($user->$option)],
          'className' => 'fasttoggle-status-user-'. $option .'-'. intval($user->$option),
        ));
        exit;
      }
      else {
        drupal_goto();
      }
    }
    else {
      // The action is not confirmed. The user came here through a regular link;
      // no AJAX was involved. That means, we need a confirmation form so that
      // we get a POST form.
      $labels = _fasttoggle_get_label('user_'. $option, FASTTOGGLE_LABEL_STATUS);
      return drupal_get_form('fasttoggle_user_option_confirm', $user, $labels[intval(!$user->$option)]);
    }
  }
  else {
    return MENU_NOT_FOUND;
  }
}


/**
 * Confirmation form for the status change of a user.
 */
function fasttoggle_user_option_confirm($form_state, $user, $option) {
  return confirm_form(array(),
    t('Are you sure you want to set the user %user to %option?', array('%user' => $user->name, '%option' => $option)),
    $_GET['destination'] ? $_GET['destination'] : 'user/'. $user->uid,
    '',
    t('Change'), t('Cancel')
  );
}


/**
 * Menu callback. Toggle options for a comment if the action is confirmed via
 * POST. Otherwise, display a confirmation form.
 */
function fasttoggle_comment_option($comment, $option) {
  $options = fasttoggle_get_options('comment', $comment);

  // Check if the action is valid. This is essential to ensure the user has
  // access to the action.
  if (isset($options[$option]) && isset($_GET['token']) && drupal_valid_token($_GET['token'], $option .'_'. $comment->cid, TRUE)) {
    // The action is confirmed: either via form submit or via AJAX/POST
    if (isset($_POST['confirm']) && $_POST['confirm']) {
      $comment->$option = !$comment->$option;
      comment_save((array)$comment);

      // Let other modules respond.
      module_invoke_all('fasttoggle_toggle', 'comment', $comment, $option);

      // Output the new status for the updated link text on AJAX changes
      if (isset($_POST['javascript']) && $_POST['javascript']) {
        drupal_set_header('Content-Type: text/javascript; charset=utf-8');
        echo drupal_to_js(array(
          'text' => $options[$option][intval($comment->$option)],
          'callback' => 'comment',
          'option' => $option,
          'status' => $comment->$option,
          'className' => 'fasttoggle-status-comment-'. $option .'-'. (1 - intval($comment->$option)),
        ));
        exit;
      }
      else {
        drupal_goto();
      }
    }
    else {
      // The action is not confirmed. The user came here through a regular link;
      // no AJAX was involved. That means, we need a confirmation form so that
      // we get a POST form.
      $labels = _fasttoggle_get_label('comment_'. $option, FASTTOGGLE_LABEL_STATUS);
      return drupal_get_form('fasttoggle_comment_option_confirm', $comment, $labels[intval(!$comment->$option)]);
    }
  }
  else {
    return MENU_NOT_FOUND;
  }
}


/**
 * Confirmation form for the option change of a comment.
 */
function fasttoggle_comment_option_confirm($form_state, $comment, $option) {
  return confirm_form(array(),
    t('Are you sure you want to set the comment %title to %option?', array('%title' => $comment->subject, '%option' => $option)),
    $_GET['destination'] ? $_GET['destination'] : 'comment/'. $comment->cid,
    '',
    t('Change'), t('Cancel')
  );
}
