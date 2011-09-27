<?php
// $Id: countdown.tpl.php,v 1.1.2.1 2008/05/12 15:29:47 deekayen Exp $

/**
 * @file countdown.tpl.php
 *
 * Theme implementation to display a list of related content.
 *
 * Available variables:
 * - $items: the list.
 */
$time = time();
$difference = variable_get('countdown_timestamp', $time) - $time;
if ($difference < 0) {
  $passed = 1;
  $difference = abs($difference);
}
else {
  $passed = 0;
}

$accuracy  = variable_get('countdown_accuracy', 'd');
$days_left = floor($difference/60/60/24);
$hrs_left  = floor(($difference - $days_left*60*60*24)/60/60);
$min_left  = floor(($difference - $days_left*60*60*24 - $hrs_left*60*60)/60);
$secs_left = floor(($difference - $days_left*60*60*24 - $hrs_left*60*60 - $min_left*60));

print t('%i days', array('%i' => $days_left));
if ($accuracy == 'h' || $accuracy == 'm' || $accuracy == 's') {
  print  t(', %i hours', array('%i' => $hrs_left));
}
if ($accuracy == 'm' || $accuracy == 's') {
  print  t(', %i minutes', array('%i' => $min_left));
}
if ($accuracy == 's') {
  print t(', %i seconds', array('%i' => $secs_left));
}
print t(($passed) ? ' since %s.' : ' until %s.', array('%s' => variable_get('countdown_event_name', '')));

if ($accuracy != 'd') {
  $path = drupal_get_path('module', 'countdown');
  drupal_add_js($path .'/countdown.js');

  print <<<___EOS___
<script type="text/javascript"><!--
  init_countdown('$accuracy');
// --></script>
___EOS___;
}
