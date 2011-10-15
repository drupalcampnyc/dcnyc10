<?php
function drupalcampnyc10_preprocess_page(&$vars, $hook) {
  // hide Flash of Unstyled Text from FF & IE 9 see http://www.extensis.com/en/WebINK/fout-b-gone/
  //dpm($vars['setting_styles']);
  //$googlemeta = '<meta name="google-site-verification" content="1tO-IiukYTIwsIc_oB9DmYoaI0xBPqQFVFcStDLhYoI" />';
  $headscript = '<script type="text/javascript">fbg.hideFOUT("asap", 400);</script>';
  //$vars['head'] .= $googlemeta;
  $vars['scripts'] .= $headscript;
  // Remove the 
  unset($vars['setting_styles']);
  $vars['styles'] = drupal_get_css($vars['css']);
}

function drupalcampnyc10_uc_signup_event_text($node = NULL) {
  $date_field = signup_date_field($node->type);
  if (!empty($date_field)) {
    $date_field_name = $date_field['field_name'];
    $this_date_field = $node->$date_field_name;
    $date_formatted = ' - ' . content_format($date_field, $this_date_field[0]);

  }
  return check_plain($node->title) . $date_formatted;
}


