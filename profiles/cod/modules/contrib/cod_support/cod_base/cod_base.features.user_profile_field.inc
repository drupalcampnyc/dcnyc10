<?php

/**
 * Implementation of hook_user_default_profile_fields().
 */
function cod_base_user_default_profile_fields() {
  $profile_fields = array();

  $profile_fields['profile_first'] = array(
  'title' => 'First name',
  'name' => 'profile_first',
  'explanation' => '',
  'category' => 'Personal information',
  'page' => '',
  'type' => 'textfield',
  'weight' => '-10',
  'required' => '1',
  'register' => '1',
  'visibility' => '3',
  'autocomplete' => '0',
  'options' => '',
);
  $profile_fields['profile_interests'] = array(
  'title' => 'Interests',
  'name' => 'profile_interests',
  'explanation' => 'Share your interests. This information can be used to find others.',
  'category' => 'Personal information',
  'page' => 'People who are interested in %value',
  'type' => 'list',
  'weight' => '-5',
  'required' => '0',
  'register' => '0',
  'visibility' => '3',
  'autocomplete' => '1',
  'options' => '',
);
  $profile_fields['profile_job_title'] = array(
  'title' => 'Job title',
  'name' => 'profile_job_title',
  'explanation' => 'Share your job title / job keywords. Others will be able to find you by your job title.',
  'category' => 'Personal information',
  'page' => 'People who have the job title %value',
  'type' => 'textfield',
  'weight' => '-7',
  'required' => '0',
  'register' => '0',
  'visibility' => '2',
  'autocomplete' => '0',
  'options' => '',
);
  $profile_fields['profile_last'] = array(
  'title' => 'Last name',
  'name' => 'profile_last',
  'explanation' => '',
  'category' => 'Personal information',
  'page' => '',
  'type' => 'textfield',
  'weight' => '-9',
  'required' => '1',
  'register' => '1',
  'visibility' => '3',
  'autocomplete' => '0',
  'options' => '',
);
  $profile_fields['profile_org'] = array(
  'title' => 'Organization',
  'name' => 'profile_org',
  'explanation' => '',
  'category' => 'Personal information',
  'page' => '',
  'type' => 'textfield',
  'weight' => '-8',
  'required' => '0',
  'register' => '0',
  'visibility' => '3',
  'autocomplete' => '0',
  'options' => '',
);
return $profile_fields;
}
