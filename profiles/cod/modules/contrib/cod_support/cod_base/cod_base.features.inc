<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cod_base_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_uuid_node_features_export_render_alter().
 */
function cod_base_uuid_node_features_export_render_alter(&$export, $node, $module) {
  // Unset the submitted date on these default COD nodes as a workaround for
  // http://drupal.org/node/1185004 .
  if (in_array($export->uuid, array('79f090a8-755e-102e-a8fe-4040db1cdced', '82568654-06d2-11e0-a3ab-29212d7dea21'))) {
    unset($export->date);  
  }
}