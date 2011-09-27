<?php

function fusion_swimmingly_tablesort_indicator($style) {
  if ($style == "asc") {
    return '<span class="desc">click to toggle sort</span>';
  }
  else {
    return '<span class="asc">click to toggle sort</span>';
  }
}

function fusion_swimmingly_grid_block($element, $name, $classes='') {
  $output = '';
  if ($element) {
    $output .= '<div id="' . $name . '" class="' . $name . ' '. $classes .' block">' . "\n";
    $output .= '<div id="' . $name . '-inner" class="' . $name . '-inner inner clearfix">' . "\n";
    $output .= $element;
    $output .= '</div><!-- /' . $name . '-inner -->' . "\n";
    $output .= '</div><!-- /' . $name . ' -->' . "\n";
  }
  return $output;
}
