<?php
class fasttoggle_views_handler_field_node_link extends views_handler_field_node_link {
  var $fasttoggle_key = 'status';

  function construct() {
    parent::construct();

    // We need these fields for access checking later in the render() function.
    $this->additional_fields['uid'] = 'uid';
    $this->additional_fields['status'] = 'status';
    $this->additional_fields['type'] = 'type';
    $this->additional_fields['format'] = array('table' => 'node_revisions', 'field' => 'format');

    if (isset($this->definition['fasttoggle'])) {
      if (isset($this->definition['fasttoggle']['additional_fields'])) {
        $this->additional_fields += $this->definition['fasttoggle']['additional_fields'];
      }
      if (isset($this->definition['fasttoggle']['key'])) {
        $this->fasttoggle_key = $this->definition['fasttoggle']['key'];
      }
    }
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    unset($form['text']);
  }

  function render($values) {
    // ensure user has access to edit this node.
    $node = new stdClass();
    foreach (array('nid', 'uid', 'type', 'format') as $key) {
      $node->$key = $values->{$this->aliases[$key]};
    }

    // node_access() ignores access control for unpublished nodes. Since
    // this is a faked node object anyway, we can set status to 1 safely.
    $node->status = 1;
    if (!node_access('update', $node)) {
      return '';
    }

    // Now we set the status to the actual value so that we get the
    // correct labels.
    $node->status = $values->{$this->aliases['status']};
    $options = fasttoggle_get_options('node', $node);

    $key = $this->fasttoggle_key;

    if (!empty($options[$key])) {
      $node->$key = $values->{$this->aliases[$key]};
      return fasttoggle($options[$key][intval($node->$key)], 'node/'. $node->nid .'/toggle/'. $key, TRUE, $key .'_'. $node->nid);
    }
  }
}
