<?php foreach ($fields as $id => $field): ?>
  <<?php print $field->element_type; ?>><?php print $field->content; ?></<?php print $field->element_type; ?>>
<?php endforeach; ?>
