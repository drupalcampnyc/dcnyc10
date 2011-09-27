<?php
function drupalcampnyc10_preprocess_page(&$vars, $hook) {
  // hide Flash of Unstyled Text from FF & IE 9 see http://www.extensis.com/en/WebINK/fout-b-gone/
  if(drupal_is_front_page()) {
    $headscript = '<script type="text/javascript">fbg.hideFOUT("asap", 400);</script>';
    $vars['scripts'] .= $headscript;
  }
}