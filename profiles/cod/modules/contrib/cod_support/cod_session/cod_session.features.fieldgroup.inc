<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function cod_session_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_schedule
  $groups['schedule_item-group_schedule'] = array(
    'group_type' => 'standard',
    'type_name' => 'schedule_item',
    'group_name' => 'group_schedule',
    'label' => 'Schedule info',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '-2',
    'fields' => array(
      '0' => 'field_accepted',
      '1' => 'field_session_slot',
      '2' => 'field_session_room',
    ),
  );

  // Exported group: group_audience
  $groups['session-group_audience'] = array(
    'group_type' => 'standard',
    'type_name' => 'session',
    'group_name' => 'group_audience',
    'label' => 'Audience',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '1',
        'label' => 'hidden',
        'teaser' => array(
          'format' => 'hidden',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'hidden',
          'exclude' => 0,
        ),
        'description' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '1',
    'fields' => array(
      '0' => 'field_track',
      '1' => 'field_experience',
    ),
  );

  // Exported group: group_schedule
  $groups['session-group_schedule'] = array(
    'group_type' => 'standard',
    'type_name' => 'session',
    'group_name' => 'group_schedule',
    'label' => 'Schedule info',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '0',
        'label' => 'above',
        'teaser' => array(
          'format' => 'simple',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'simple',
          'exclude' => 0,
        ),
        'description' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '0',
    'fields' => array(
      '0' => 'field_session_slot',
      '1' => 'field_session_room',
      '2' => 'field_accepted',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Audience');
  t('Schedule info');

  return $groups;
}
