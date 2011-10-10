<?php
function drupalcampnyc10_preprocess_page(&$vars, $hook) {
  // hide Flash of Unstyled Text from FF & IE 9 see http://www.extensis.com/en/WebINK/fout-b-gone/
  //dpm($vars);
  $googlemeta = '<meta name="google-site-verification" content="1tO-IiukYTIwsIc_oB9DmYoaI0xBPqQFVFcStDLhYoI" />';
  $headscript = '<script type="text/javascript">fbg.hideFOUT("asap", 400);</script>';
  $vars['head'] .= $googlemeta;
  $vars['scripts'] .= $headscript;
}

