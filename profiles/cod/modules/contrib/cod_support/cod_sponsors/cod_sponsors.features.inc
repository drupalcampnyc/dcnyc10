<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cod_sponsors_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function cod_sponsors_imagecache_default_presets() {
  $items = array(
    'sponsor_logo_bronze' => array(
      'presetname' => 'sponsor_logo_bronze',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '100',
            'height' => '',
          ),
        ),
      ),
    ),
    'sponsor_logo_callout' => array(
      'presetname' => 'sponsor_logo_callout',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '200',
            'height' => '',
          ),
        ),
      ),
    ),
    'sponsor_logo_gold' => array(
      'presetname' => 'sponsor_logo_gold',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '150',
            'height' => '',
          ),
        ),
      ),
    ),
    'sponsor_logo_platinum' => array(
      'presetname' => 'sponsor_logo_platinum',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '200',
            'height' => '',
          ),
        ),
      ),
    ),
    'sponsor_logo_silver' => array(
      'presetname' => 'sponsor_logo_silver',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '125',
            'height' => '',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function cod_sponsors_node_info() {
  $items = array(
    'sponsor' => array(
      'name' => t('Sponsor'),
      'module' => 'features',
      'description' => t('An event sponsor'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function cod_sponsors_views_api() {
  return array(
    'api' => '2',
  );
}
