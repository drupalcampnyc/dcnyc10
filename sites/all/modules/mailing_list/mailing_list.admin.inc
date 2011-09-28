<?php

/**
 * @file
 * Mailing list admin UI.
 */

/**
 * Menu callback; displays all mailing lists in a table.
 */
function mailing_list_lists() {
  $header = array(
    array('data' => t('Name'), 'field' => 'name', 'sort' => 'asc'),
    array('data' => t('Operations'), 'colspan' => '5')
  );

  $query  = "SELECT * FROM {mailing_list}";
  $result = db_query($query);
  $rows = array();
  $destination = drupal_get_destination();
  while ($list = db_fetch_object($result)) {
    $row = array(l(check_plain($list->name), "admin/build/mailing-list/$list->mlid"), l(t('list e-mails'), "admin/build/mailing-list/$list->mlid"), l(t('import e-mails'), "admin/build/mailing-list/$list->mlid/import", array('query' => $destination)), l(t('export list'), "admin/build/mailing-list/$list->mlid/export", array('query' => $destination)), l(t('rename list'), "admin/build/mailing-list/$list->mlid/edit", array('query' => $destination)), l(t('delete list'), "admin/build/mailing-list/$list->mlid/delete", array('query' => $destination)));
    $rows[] = $row;
  }

  if (empty($rows)) {
    $empty_message = t('No mailing lists found.');
    $rows[] = array(array('data' => $empty_message, 'colspan' => 6));
  }

  $output = theme('table', $header, $rows);
  $output .= theme('pager', NULL, 50, 0);

  return $output;
}

/**
 * Menu callback; displays all e-mails for the specified mailing list in a
 * table.
 */
function mailing_list_emails($list = NULL) {
  if (empty($list)) {
    return;
  }
  else {
    drupal_set_title(check_plain($list->name));
  }

  $sql = 'SELECT * FROM {mailing_list_emails} WHERE mlid = %d';

  $header = array(
    array('data' => t('E-mail'), 'field' => 'mail', 'sort' => 'asc'),
    array('data' => t('Name'), 'field' => 'name'),
    array('data' => t('Operations'), 'colspan' => '2')
  );
  $sql .= tablesort_sql($header);
  $result = pager_query($sql, 50, 0 , NULL, array($list->mlid));

  $rows = array();
  $destination = drupal_get_destination();
  while ($data = db_fetch_object($result)) {
    $row = array(check_plain($data->mail), (!empty($data->name) ? check_plain($data->name) : theme('placeholder', t('none'))), l(t('edit'), "admin/build/mailing-list/$list->mlid/$data->eid", array('query' => $destination)), l(t('delete'), "admin/build/mailing-list/$list->mlid/$data->eid/delete", array('query' => $destination)));
    $rows[] = $row;
  }

  if (empty($rows)) {
    $empty_message = t('No e-mails found.');
    $rows[] = array(array('data' => $empty_message, 'colspan' => 4));
  }

  $output = theme('table', $header, $rows);
  $output .= theme('pager', NULL, 50, 0);

  return $output;
}

/**
 * Form for adding / renaming a mailing list.
 */
function mailing_list_form(&$form_state, $list = null) {
  if (empty($list)) {
    drupal_set_title(t('Add mailing list'));
  }
  else {
    drupal_set_title(t('Edit mailing list'));
  }

  $form = array();
  if (isset($form_state['values']['mlid']) || isset($list)) {
    $form['mlid'] = array(
      '#type' => 'hidden',
      '#value' => isset($form_state['values']['mlid']) ? $form_state['values']['mlid'] : isset($list) ? $list->mlid: null,
    );
  }

  $form['name'] = array(
    '#title' => t('List name'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value'=> isset($form_state['values']['name']) ? $form_state['values']['name']: isset($list)?$list->name : '',
  );
  $form['submit'] = array(
    '#value' => t('Save'),
    '#type' => 'submit',
    '#submit' => array('mailing_list_form_submit'),
  );
  $form['#redirect'] = 'admin/build/mailing-list';

  return $form;
}

/**
 * Submit handler for the add / rename mailing list form.
 */
function mailing_list_form_submit($form, &$form_state) {
//    drupal_set_message('<pre>'. print_r($form_state['values'],1 ) . '</pre>');
  if (isset($form_state['values']['mlid'])) {
    $query = "UPDATE {mailing_list} SET name = '%s' WHERE mlid = %d";
    $result = db_query($query, $form_state['values']['name'], $form_state['values']['mlid']);
  }
  else {
    $query = "INSERT INTO {mailing_list} (name) VALUES ('%s')";
    $result = db_query($query, $form_state['values']['name']);
  }

  if ($result) {
    if (isset($form_state['values']['mlid']) ) {
      drupal_set_message(t('Renamed mailing list %name', array('%name' => $form_state['values']['name'])));
      watchdog('mailing_list', 'Mailing list: renamed %name.', array('%name' => $form_state['values']['name']), WATCHDOG_NOTICE, l(t('view'), 'admin/build/mailing-list/'. $form_state['values']['mlid']));
    }
    else {
      drupal_set_message(t('Created mailing list %name', array('%name' => $form_state['values']['name'])));
      watchdog('mailing_list', 'Mailing list: created %name.', array('%name' => $form_state['values']['name']), WATCHDOG_NOTICE, l(t('view'), 'admin/build/mailing-list/'. db_last_insert_id('mailing_list', 'mlid')));
    }
  }
  else {
    if (isset($form_state['values']['mlid'])) {
      drupal_set_message(t('Failed to update mailing list %name', array('%name' => $form_state['values']['name'])), 'error');
    }
    else {
      drupal_set_message(t('Failed to create mailing list %name', array('%name' => $form_state['values']['name'])), 'error');
    }
  }
}

/**
 * Form to add / edit an e-mail in a mailing list.
 */
function mailing_list_email_form(&$form_state, $list = null, $email = null) {
  if (empty($list)) {
    return;
  }

  if (empty($email)) {
    drupal_set_title(t('Add e-mail'));
  }
  else {
    drupal_set_title(t('Edit e-mail'));
  }

  $form = array();
  if (isset($form_state['values']['mlid']) || isset($list)) {
    $form['mlid']   = array(
      '#type' => 'hidden',
      '#value' => isset($form_state['values']['mlid']) ? $form_state['values']['mlid'] : isset($list) ? $list->mlid: null,
    );
  }
  if (isset($form_state['values']['ml_name']) || isset($list)) {
    $form['ml_name']   = array(
      '#type' => 'hidden',
      '#value' => isset($form_state['values']['ml_name']) ? $form_state['values']['ml_name'] : isset($list) ? $list->name: null,
    );
  }
  if (isset($form_state['values']['eid']) || isset($email)) {
    $form['eid'] = array(
      '#type' => 'hidden',
      '#value' => isset($form_state['values']['eid']) ? $form_state['values']['eid'] : isset($email) ? $email->eid: null,
    );
  }
  $form['mail'] = array(
    '#title' => t('E-mail'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value'=> isset($form_state['values']['mail']) ? $form_state['values']['mail']: isset($email) ? $email->mail : '',
  );
  $form['name'] = array(
    '#title' => t('Name'),
    '#type' => 'textfield',
    '#default_value'=> isset($form_state['values']['name']) ? $form_state['values']['name']: isset($email) ? $email->name : '',
  );
  $form['submit'] = array(
    '#value' => t('Save'),
    '#type' => 'submit',
    '#submit' => array('mailing_list_email_form_submit'),
  );
  $form['#validate'][] = 'mailing_list_subscription_form_validate';
  $form['#redirect'] = 'admin/build/mailing-list/'. $list->mlid;
  return $form;
}

/**
 * Submit handler for the add / edit e-mail form.
 */
function mailing_list_email_form_submit($form, &$form_state) {
  if (isset($form_state['values']['eid'])) {
    $query = "UPDATE {mailing_list_emails} SET name = '%s', mail = '%s' WHERE eid = %d";
    $result = db_query($query, $form_state['values']['name'], $form_state['values']['mail'], $form_state['values']['eid']);
  }
  else {
    $query = "INSERT INTO {mailing_list_emails} (mlid, name, mail) VALUES (%d, '%s', '%s')";
    $result = db_query($query, $form_state['values']['mlid'], $form_state['values']['name'], $form_state['values']['mail']);
  }

  $name = mailing_list_email_get_name($form_state['values']);
  if ($result) {
    if (isset($form_state['values']['eid']) ) {
      drupal_set_message(t('Updated e-mail for %name', array('%name' => $name)));
      watchdog('mailing_list', 'Mailing list: updated e-mail for %name.', array('%name' => $name), WATCHDOG_NOTICE, l(t('view'), 'admin/build/mailing-list/'. $form_state['values']['mlid'] .'/'. $form_state['values']['eid']));
    }
    else {
      drupal_set_message(t('Added e-mail for %name', array('%name' => $name)));
      watchdog('mailing_list', 'Mailing list: added e-mail for %name.', array('%name' => $name));
    }
  }
  else {
    if (isset($form_state['values']['eid'])) {
      drupal_set_message(t('Failed to update e-mail for %name', array('%name' => $name)), 'error');
    }
    else {
      drupal_set_message(t('Failed to add e-mail for %name', array('%name' => $name)), 'error');
    }
  }
}

/**
 * Mailing list deletion form.
 */
function mailing_list_delete_confirm($form_state, $list) {
  if (user_access('administer mailing lists')) {
    $form['mlid'] = array('#type' => 'value', '#value' => $list->mlid);
    $form['name'] = array('#type' => 'value', '#value' => $list->name);
    $output = confirm_form($form,
      t('Are you sure you want to delete mailing list %name? All e-mails in this list will be deleted too.', array('%name' => $list->name)),
      isset($_GET['destination']) ? $_GET['destination'] : 'admin/build/mailing-list');
  }
  return $output;
}

/**
 * Submit handler for the mailing list deletion form.
 */
function mailing_list_delete_confirm_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    mailing_list_delete($form_state['values']['mlid']);
    drupal_set_message(t('Deleted mailing list %name.', array('%name' => $form_state['values']['name'])));
    watchdog('mailing list', 'Mailing list: deleted list %name.', array('%name' => $form_state['values']['name']));
    $form_state['redirect'] = 'admin/build/mailing-list';
    return;
  }
}

/**
 * E-mail deletion form.
 */
function mailing_list_email_delete_confirm($form_state, $list, $email) {
  if (user_access('administer mailing lists')) {
    $name = mailing_list_email_get_name($email);
    $form['mlid'] = array('#type' => 'value', '#value' => $list->mlid);
    $form['eid'] = array('#type' => 'value', '#value' => $email->eid);
    $form['name'] = array('#type' => 'value', '#value' => $name);
    $output = confirm_form($form,
      t('Are you sure you want to delete the e-mail for %name?', array('%name' => $name)),
      isset($_GET['destination']) ? $_GET['destination'] : 'admin/build/mailing-list/'. $list->mlid);
  }
  return $output;
}

/**
 * Submit handler for the e-mail deletion form.
 */
function mailing_list_email_delete_confirm_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    mailing_list_email_delete($form_state['values']['eid']);
    drupal_set_message(t('E-mail deleted for %name', array('%name' => $form_state['values']['name'])));
    $form_state['redirect'] = 'admin/build/mailing-list/'. $form_state['values']['mlid'];
    watchdog('mailing list', 'Mailing list: deleted e-mail %name.', array('%name' => $form_state['values']['name']));
    return;
  }
}

/**
 * Deletes a mailing list and all its e-mails.
 *
 * @param $mlid
 *   The ID of the mailing list.
 */
function mailing_list_delete($mlid) {
  db_query('DELETE FROM {mailing_list_emails} WHERE mlid = %d', $mlid);
  db_query('DELETE FROM {mailing_list} WHERE mlid = %d', $mlid);
}

/**
 * Deletes an e-mail.
 *
 * @param $eid
 *   The ID of the e-mail.
 */
function mailing_list_email_delete($eid) {
  db_query('DELETE FROM {mailing_list_emails} WHERE eid = %d', $eid);
}

/**
 * Form for importing a mailing list from a CSV file.
 */
function mailing_list_import_form($form_state, $list) {
  if (empty($list)) {
    return;
  }

  drupal_set_title(t('Import e-mails'));

  $form = array();
  $form['#attributes'] = array('enctype' => "multipart/form-data");
  if ( isset($form_state['values']['mlid']) || isset($list) ) {
    $form['mlid']   = array(
      '#type'       => 'hidden',
      '#value'      => isset($form_state['values']['mlid']) ? $form_state['values']['mlid'] : isset($list) ? $list->mlid: null,
    );
  }
  if ( isset($form_state['values']['name']) || isset($list) ) {
    $form['name']   = array(
      '#type'       => 'hidden',
      '#value'      => isset($form_state['values']['name']) ? $form_state['values']['name'] : isset($list) ? $list->name: null,
    );
  }
  $form['file_upload'] = array(
    '#title'      => t('CSV file'),
    '#type'       => 'file',
  );
  $form['submit'] = array(
    '#value'      => t('Import'),
    '#type'       => 'submit',
  );
  return $form;
}

/**
 * Submit handler for the mailing list import form.
 */
function mailing_list_import_form_submit($form, &$form_state) {
  $num_imported = 0;

  if ($file = file_save_upload('file_upload', array('file_validate_extensions' => array('csv')))) {
    ini_set('auto_detect_line_endings',TRUE);
    $handle = @fopen($file->filepath, 'r');

    while (($data = fgetcsv($handle)) !== FALSE) {
      $num_fields = count($data);
      $is_existing = db_fetch_object(db_query("SELECT * from {mailing_list_emails} WHERE mlid = %d AND mail = '%s'", $form_state['values']['mlid'], $data[0]));
      if (!$is_existing && $num_fields == 2) {
        db_query("INSERT INTO {mailing_list_emails} (mlid, mail, name) VALUES (%d, '%s', '%s')", $form_state['values']['mlid'], $data[0], $data[1]);
        $num_imported++;
      }
    }

    fclose($handle);

    if ($num_imported) {
      drupal_set_message(t('Import complete: %num-imported added to mailing list %name.', array('%num-imported' => format_plural($num_imported, '1 e-mail', '@count e-mails'), '%name' => $form_state['values']['name'])));
    }
  }

  if (!$num_imported) {
    drupal_set_message(t('No e-mails added to mailing list: invalid or empty file.'), 'error');
  }

  $form_state['redirect'] = 'admin/build/mailing-list/'. $form_state['values']['mlid'];

  return;
}

/**
 * Menu callback; exports a mailing list directly to the user as a CSV file.
 */
function mailing_list_export($list) {
	$path = file_directory_path();

	// create file to hold email list
	$filename = drupal_strtolower(str_replace(' ', '_', $list->name)). '.csv';
	$full_path = $path.'/'.$filename;

	$query = "SELECT * FROM {mailing_list_emails} WHERE mlid = '%d'";
	$result = db_query($query, $list->mlid);

	// create string with all the emails
	$emails = array();
	while ($row = db_fetch_object($result)) {
		$emails[] = '"'. trim($row->mail) .'","'. trim($row->name) .'"';
	}

	$emails = implode("\n", $emails) ."\n";

	// write resultant string to file
	file_save_data($emails, $full_path, FILE_EXISTS_REPLACE);

	// set headers for file transfer
	$headers = array(
		'Content-Type: application/octet-stream',
		'Content-Disposition: attachment; filename="' . basename($full_path) . '";',
		'Content-Length: ' . sprintf('%u', filesize($full_path)),
	);

	file_transfer($full_path, $headers);
}
