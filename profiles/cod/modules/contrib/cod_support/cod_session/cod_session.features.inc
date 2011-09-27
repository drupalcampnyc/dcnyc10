<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cod_session_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_flag_default_flags().
 */
function cod_session_flag_default_flags() {
  $flags = array();
  // Exported flag: "Speaker confirmation flag".
  $flags['session_confirm'] = array(
    'content_type' => 'node',
    'title' => 'Speaker confirmation flag',
    'global' => '0',
    'types' => array(
      '0' => 'session',
    ),
    'flag_short' => 'I confirm that I can present this sesssion at the listed date and time.',
    'flag_long' => 'Once confirmed, you cannot unconfirm without contacting the session organizers.',
    'flag_message' => 'Thanks for confirming that you can present [title] at this date and time!',
    'unflag_short' => 'Cancel confirmation',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => 'You have confirmed that you will be presenting for this session.',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        '0' => 2,
      ),
      'unflag' => array(),
    ),
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'cod_session',
    'locked' => array(
      '0' => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Session Attending".
  $flags['session_schedule'] = array(
    'content_type' => 'node',
    'title' => 'Session Attending',
    'global' => '0',
    'types' => array(
      '0' => 'schedule_item',
      '1' => 'session',
    ),
    'flag_short' => 'Add to your schedule',
    'flag_long' => 'Add this session to your personal session attendance.',
    'flag_message' => 'Session added',
    'unflag_short' => 'Remove from your schedule',
    'unflag_long' => 'Remove this session from your schedule',
    'unflag_message' => 'Session removed',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(),
      'unflag' => array(),
    ),
    'show_on_page' => 0,
    'show_on_teaser' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'cod_session',
    'locked' => array(
      '0' => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Session Vote".
  $flags['session_vote'] = array(
    'content_type' => 'node',
    'title' => 'Session Vote',
    'global' => '0',
    'types' => array(
      '0' => 'session',
    ),
    'flag_short' => 'Vote for this session',
    'flag_long' => 'Vote for this session',
    'flag_message' => 'Your vote has been recorded!',
    'unflag_short' => 'Retract vote',
    'unflag_long' => 'Retract your vote for this session.',
    'unflag_message' => 'Your vote has been retracted.',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        '0' => 3,
      ),
      'unflag' => array(
        '0' => 3,
      ),
    ),
    'show_on_page' => 1,
    'show_on_teaser' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'cod_session',
    'locked' => array(
      '0' => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;
}

/**
 * Implementation of hook_node_info().
 */
function cod_session_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Page'),
      'module' => 'features',
      'description' => t('Use the <em>Page</em> content type for mostly static content like the "About us" section of a website. By default, a <em>page</em> entry does not allow comments and is not featured on the site\'s home page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'room' => array(
      'name' => t('Room'),
      'module' => 'features',
      'description' => t('Rooms provide a location for each session.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => t('What type of space is this? How is the seating arranged? Are there any other information to be shared?'),
    ),
    'schedule_item' => array(
      'name' => t('Schedule Item'),
      'module' => 'features',
      'description' => t('Use schedule items for content you wish to have in the schedule but not be part of any session submission workflows. Examples include scheduling lunch or breaks.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'session' => array(
      'name' => t('Session'),
      'module' => 'features',
      'description' => t('Use this content type to propose sessions at the event. Users can vote on proposed sessions and add sessions to their individual session agendas.'),
      'has_title' => '1',
      'title_label' => t('Session Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '1',
      'help' => '',
    ),
    'time_slot' => array(
      'name' => t('Time slot'),
      'module' => 'features',
      'description' => t('Use time slots to define when sessions will occur.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function cod_session_views_api() {
  return array(
    'api' => '2',
  );
}
