<?php

/**
 * Implementation of hook_strongarm().
 */
function cod_session_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_time_slot';
  $strongarm->value = '[field_slot_datetime-d] [field_slot_datetime-month] [field_slot_datetime-time] - [field_slot_datetime-to-time]';
  $export['ant_pattern_time_slot'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_time_slot';
  $strongarm->value = '1';
  $export['ant_time_slot'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cod_unique_schedule_item';
  $strongarm->value = 'multiple';
  $export['cod_unique_schedule_item'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cod_unique_session';
  $strongarm->value = 'single';
  $export['cod_unique_session'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_page';
  $strongarm->value = 0;
  $export['comment_anonymous_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_room';
  $strongarm->value = 0;
  $export['comment_anonymous_room'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_schedule_item';
  $strongarm->value = 0;
  $export['comment_anonymous_schedule_item'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_session';
  $strongarm->value = 0;
  $export['comment_anonymous_session'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_time_slot';
  $strongarm->value = 0;
  $export['comment_anonymous_time_slot'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_page';
  $strongarm->value = '3';
  $export['comment_controls_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_room';
  $strongarm->value = '3';
  $export['comment_controls_room'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_schedule_item';
  $strongarm->value = '3';
  $export['comment_controls_schedule_item'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_session';
  $strongarm->value = '3';
  $export['comment_controls_session'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_time_slot';
  $strongarm->value = '3';
  $export['comment_controls_time_slot'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_page';
  $strongarm->value = '4';
  $export['comment_default_mode_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_room';
  $strongarm->value = '4';
  $export['comment_default_mode_room'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_schedule_item';
  $strongarm->value = '4';
  $export['comment_default_mode_schedule_item'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_session';
  $strongarm->value = '4';
  $export['comment_default_mode_session'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_time_slot';
  $strongarm->value = '4';
  $export['comment_default_mode_time_slot'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_page';
  $strongarm->value = '1';
  $export['comment_default_order_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_room';
  $strongarm->value = '1';
  $export['comment_default_order_room'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_schedule_item';
  $strongarm->value = '1';
  $export['comment_default_order_schedule_item'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_session';
  $strongarm->value = '1';
  $export['comment_default_order_session'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_time_slot';
  $strongarm->value = '1';
  $export['comment_default_order_time_slot'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_page';
  $strongarm->value = '50';
  $export['comment_default_per_page_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_room';
  $strongarm->value = '50';
  $export['comment_default_per_page_room'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_schedule_item';
  $strongarm->value = '50';
  $export['comment_default_per_page_schedule_item'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_session';
  $strongarm->value = '50';
  $export['comment_default_per_page_session'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_time_slot';
  $strongarm->value = '50';
  $export['comment_default_per_page_time_slot'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_page';
  $strongarm->value = '0';
  $export['comment_form_location_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_room';
  $strongarm->value = '0';
  $export['comment_form_location_room'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_schedule_item';
  $strongarm->value = '0';
  $export['comment_form_location_schedule_item'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_session';
  $strongarm->value = '0';
  $export['comment_form_location_session'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_time_slot';
  $strongarm->value = '0';
  $export['comment_form_location_time_slot'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_page';
  $strongarm->value = '2';
  $export['comment_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_page';
  $strongarm->value = '1';
  $export['comment_preview_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_room';
  $strongarm->value = '1';
  $export['comment_preview_room'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_schedule_item';
  $strongarm->value = '1';
  $export['comment_preview_schedule_item'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_session';
  $strongarm->value = '1';
  $export['comment_preview_session'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_time_slot';
  $strongarm->value = '1';
  $export['comment_preview_time_slot'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_room';
  $strongarm->value = '0';
  $export['comment_room'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_schedule_item';
  $strongarm->value = '0';
  $export['comment_schedule_item'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_session';
  $strongarm->value = '2';
  $export['comment_session'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_page';
  $strongarm->value = '1';
  $export['comment_subject_field_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_room';
  $strongarm->value = '1';
  $export['comment_subject_field_room'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_schedule_item';
  $strongarm->value = '1';
  $export['comment_subject_field_schedule_item'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_session';
  $strongarm->value = '1';
  $export['comment_subject_field_session'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_time_slot';
  $strongarm->value = '1';
  $export['comment_subject_field_time_slot'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_time_slot';
  $strongarm->value = '0';
  $export['comment_time_slot'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_room';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-2',
    'revision_information' => '1',
    'author' => '0',
    'options' => '2',
    'comment_settings' => '5',
    'menu' => '3',
    'path' => '6',
    'path_redirect' => '4',
  );
  $export['content_extra_weights_room'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_session';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-2',
    'revision_information' => '4',
    'author' => '3',
    'options' => '5',
    'comment_settings' => '7',
    'menu' => '-4',
    'path' => '8',
    'path_redirect' => '6',
  );
  $export['content_extra_weights_session'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_page';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_page'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_room';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_room'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_schedule_item';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_schedule_item'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_session';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_session'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_time_slot';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_time_slot'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_userreference';
  $strongarm->value = array(
    'session' => array(
      'field_speakers' => array(
        'referenced' => array(
          'view' => 'view',
          'update' => 'update',
          'delete' => 0,
        ),
        'author' => array(
          'view' => 'view',
          'update' => 'update',
          'delete' => 'delete',
        ),
        'all' => array(
          'view' => 'view',
        ),
        'priority' => '0',
      ),
    ),
  );
  $export['nodeaccess_userreference'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_room_pattern';
  $strongarm->value = 'rooms/[title-raw]';
  $export['pathauto_node_room_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_session_pattern';
  $strongarm->value = 'sessions/[title-raw]';
  $export['pathauto_node_session_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_message_sessions_admin_contact:page_1';
  $strongarm->value = 'Hello [views-send-users_node_data_field_speakers_profile_values_profile_first_value],

Thank you for proposing the session session, "[views-send-node_title]".

We are happy to inform you that your session has been accepted for the conference.

Please confirm that you are able to present this session at the scheduled date and time by visiting [site-url]/user .

Thanks!

Conference organizing team';
  $export['views_send_message_sessions_admin_contact:page_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_message_sessions_admin_contact:page_2';
  $strongarm->value = 'Thank you for proposing the session session, "[views-send-node_title]".

We are happy to inform you that your session has been accepted for the conference.

Please confirm that you are able to present this session at the scheduled date and time by visiting [site-url]user .

Thanks!

Conference organizing team';
  $export['views_send_message_sessions_admin_contact:page_2'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_message_sessions_admin_contact:page_3';
  $strongarm->value = 'Hello [views-send-users_node_data_field_speakers_profile_values_profile_first_value],

Thank you for proposing the session session, "[views-send-node_title]".

Unfortunately, we are unable to offer you a spot to present at the conference. We thank you for your submission and hope that you\'ll submit a proposal in the future.

Thanks,

Conference organizing team';
  $export['views_send_message_sessions_admin_contact:page_3'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_message_sessions_admin_contact:page_4';
  $strongarm->value = 'Hello [views-send-users_node_data_field_speakers_profile_values_profile_first_value],

Thank you for submitting the session proposal titled, "[views-send-node_title]".

We are reviewing session proposals and will let you know whether your session has been accepted by (date).

Thanks,

Conference organizing team';
  $export['views_send_message_sessions_admin_contact:page_4'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_message_sessions_admin_contact:page_5';
  $strongarm->value = 'Thank you for proposing the session session, "[views-send-node_title]".

We are happy to inform you that your session has been accepted for the conference.

Please confirm that you are able to present this session at the scheduled date and time by visiting [site-url]user . If you do not confirm by [date], your session may be cancelled.

Thanks!

Conference organizing team';
  $export['views_send_message_sessions_admin_contact:page_5'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_remember_sessions_admin_contact:page_1';
  $strongarm->value = 1;
  $export['views_send_remember_sessions_admin_contact:page_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_remember_sessions_admin_contact:page_2';
  $strongarm->value = 1;
  $export['views_send_remember_sessions_admin_contact:page_2'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_remember_sessions_admin_contact:page_3';
  $strongarm->value = 1;
  $export['views_send_remember_sessions_admin_contact:page_3'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_remember_sessions_admin_contact:page_4';
  $strongarm->value = 1;
  $export['views_send_remember_sessions_admin_contact:page_4'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_remember_sessions_admin_contact:page_5';
  $strongarm->value = 1;
  $export['views_send_remember_sessions_admin_contact:page_5'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_remember_sessions_admin_contact:page_6';
  $strongarm->value = 1;
  $export['views_send_remember_sessions_admin_contact:page_6'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_subject_sessions_admin_contact:page_1';
  $strongarm->value = 'Your Session Submission';
  $export['views_send_subject_sessions_admin_contact:page_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_subject_sessions_admin_contact:page_2';
  $strongarm->value = 'Presenter confirmation';
  $export['views_send_subject_sessions_admin_contact:page_2'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_subject_sessions_admin_contact:page_3';
  $strongarm->value = 'Your session submission';
  $export['views_send_subject_sessions_admin_contact:page_3'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_subject_sessions_admin_contact:page_4';
  $strongarm->value = 'Your session submission';
  $export['views_send_subject_sessions_admin_contact:page_4'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_subject_sessions_admin_contact:page_5';
  $strongarm->value = 'Please confirm your session';
  $export['views_send_subject_sessions_admin_contact:page_5'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_subject_sessions_admin_contact:page_6';
  $strongarm->value = 'Thanks for confirming your session!';
  $export['views_send_subject_sessions_admin_contact:page_6'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_to_mail_sessions_admin_contact:page_1';
  $strongarm->value = 'users_node_data_field_speakers_mail';
  $export['views_send_to_mail_sessions_admin_contact:page_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_to_mail_sessions_admin_contact:page_2';
  $strongarm->value = 'users_node_data_field_speakers_mail';
  $export['views_send_to_mail_sessions_admin_contact:page_2'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_to_mail_sessions_admin_contact:page_3';
  $strongarm->value = 'users_node_data_field_speakers_mail';
  $export['views_send_to_mail_sessions_admin_contact:page_3'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_to_mail_sessions_admin_contact:page_4';
  $strongarm->value = 'users_node_data_field_speakers_mail';
  $export['views_send_to_mail_sessions_admin_contact:page_4'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_to_mail_sessions_admin_contact:page_5';
  $strongarm->value = 'users_node_data_field_speakers_mail';
  $export['views_send_to_mail_sessions_admin_contact:page_5'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_to_mail_sessions_admin_contact:page_6';
  $strongarm->value = 'users_node_data_field_speakers_name';
  $export['views_send_to_mail_sessions_admin_contact:page_6'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_to_name_sessions_admin_contact:page_1';
  $strongarm->value = 'users_node_data_field_speakers_name';
  $export['views_send_to_name_sessions_admin_contact:page_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_to_name_sessions_admin_contact:page_2';
  $strongarm->value = 'users_node_data_field_speakers_name';
  $export['views_send_to_name_sessions_admin_contact:page_2'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_to_name_sessions_admin_contact:page_3';
  $strongarm->value = 'users_node_data_field_speakers_name';
  $export['views_send_to_name_sessions_admin_contact:page_3'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_to_name_sessions_admin_contact:page_4';
  $strongarm->value = 'users_node_data_field_speakers_name';
  $export['views_send_to_name_sessions_admin_contact:page_4'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_to_name_sessions_admin_contact:page_5';
  $strongarm->value = 'users_node_data_field_speakers_name';
  $export['views_send_to_name_sessions_admin_contact:page_5'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_send_to_name_sessions_admin_contact:page_6';
  $strongarm->value = 'users_node_data_field_speakers_name';
  $export['views_send_to_name_sessions_admin_contact:page_6'] = $strongarm;

  return $export;
}
