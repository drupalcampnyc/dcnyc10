<?php
function drupalcampnyc10_preprocess_page(&$vars, $hook) {
  // hide Flash of Unstyled Text from FF & IE 9 see http://www.extensis.com/en/WebINK/fout-b-gone/
  //dpm($vars['ie8_styles']);
  //$googlemeta = '<meta name="google-site-verification" content="1tO-IiukYTIwsIc_oB9DmYoaI0xBPqQFVFcStDLhYoI" />';
  $headscript = '<script type="text/javascript">fbg.hideFOUT("asap", 400);</script>';
  //$vars['head'] .= $googlemeta;
  $vars['scripts'] .= $headscript;
  // Remove the Grid
  unset($vars['setting_styles']);
  $vars['styles'] = drupal_get_css($vars['css']);
  
  /*
  // Added the global style to the beginning of the conditional comments (should be in a function but TO DO)
  $vars['ie8_styles_append'] = $vars['ie8_styles'];
  $vars['ie7_styles_append'] = $vars['ie7_styles'];
  $vars['ie6_styles_append'] = $vars['ie6_styles'];
  unset($vars['ie8_styles'], $vars['ie7_styles'], $vars['ie6_styles']);
   
  $vars['ie8_styles'] .= "  <link type=\"text/css\" rel=\"stylesheet\" media=\"all\" href=\"".base_path().path_to_theme()."/css/default-normal.css\" />\r" . $vars['ie8_styles_append'];
  $vars['ie7_styles'] .= "  <link type=\"text/css\" rel=\"stylesheet\" media=\"all\" href=\"".base_path().path_to_theme()."/css/default-normal.css\" />\r" . $vars['ie7_styles_append'];
  $vars['ie6_styles'] .= "  <link type=\"text/css\" rel=\"stylesheet\" media=\"all\" href=\"".base_path().path_to_theme()."/css/default-normal.css\" />\r" . $vars['ie6_styles_append'];
  */
  
  // Add Meta Viewport tag for mobile
  $vars['head'] .= drupal_set_html_head("<meta name=\"viewport\" content=\"width=devide-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no\" />\r");
}

function drupalcampnyc10_uc_signup_event_text($node = NULL) {
  $date_field = signup_date_field($node->type);
  if (!empty($date_field)) {
    $date_field_name = $date_field['field_name'];
    $this_date_field = $node->$date_field_name;
    $date_formatted = ' ' . content_format($date_field, $this_date_field[0]);

  }
  return check_plain($node->title) . $date_formatted;
}


