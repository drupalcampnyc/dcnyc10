<?php

/**
 * @file
 *   Views Send cron rotuines.
 *
 * @ingroup views_send
 */

/**
 * Process the spool queue at cron run.
 */
function views_send_send_from_spool() {
  $limit = variable_get('views_send_throttle', 20);
  $ok = $fail = $check = 0;

  // Get PHP maximum execution time. 30 seconds default.
  $max_execution_time = ini_get('max_execution_time') ? ini_get('max_execution_time') : VIEWS_SEND_MAX_EXECUTION_TIME;

  // Reset a Drupal timer.
  timer_start('views_send');

  // Retrieve messages to be send.
  $query = "SELECT * FROM {views_send_spool} WHERE status = %d ORDER BY tentatives ASC, timestamp ASC";
  $result = $limit ? db_query_range($query, 0, 0, $limit) : db_query($query, 0);
  while ($message = db_fetch_object($result)) {

    // Send the message.
    $status = views_send_deliver($message);

    if ($status) {
      // Update the spool status.
      db_query("UPDATE {views_send_spool} SET status = %d WHERE eid = %d", 1, $message->eid);
      $ok++;
    }
    else {
      // Increment tentatives so that next time this message
      // will be scheduled with low priority.
      db_query("UPDATE {views_send_spool} SET tentatives = tentatives + 1 WHERE eid = %d", $message->eid);
      $fail++;
    }

    // Check the elapsed time and break if we've spent more than 80%.
    // We check every 50 messages.
    if (++$check >= 50) {
      // Reset the counter.
      $check = 0;

      // Break if exceded.
      if (timer_read('views_send') > .8 * $max_execution_time) {
        watchdog('views_send', 'PHP maximum execution time almost exceeded. Remaining E-mail messages will be sent during the next cron run. If this warning occurs regularly you should reduce the cron throttle setting.', NULL, WATCHDOG_WARNING);
        break;
      }
    }
  }

  if ($ok + $fail > 0) {
    // Log results and exit.
    watchdog('views_send', '%ok messages sent in %sec seconds, %fail failed sending.', array('%ok' => $ok, '%sec' => timer_read('views_send'), '%fail' => $fail));
  }
}

/**
 * Sending the message take from spool.
 *
 * @param $message
 *   Database object containing the spooled message being send.
 *
 * @return
 *   Boolean indicating if the message was sent successfully.
 */
function views_send_deliver($message) {
  $headers = unserialize($message->headers);
  $to = _views_send_format_address($message->to_mail, $message->to_name);
  $from = _views_send_format_address($message->from_mail, $message->from_name);

  if (VIEWS_SEND_MIMEMAIL) {
    $mail = array(
      'address' => $to,
      'subject' => mime_header_encode($message->subject),
      'body' => $message->body,
      'sender' => $from,
      'headers' => $headers,
    );
    return mimemail_send_message($mail);
  }
  else {
    $mail = array(
      'to' => $to,
      'subject' => $message->subject,
      'body' => $message->body,
      'from' => $from,
      'headers' => $headers,
    );
    return drupal_mail_send($mail);
  }
}

/**
 * Clear the expired items from spool.
 */
function views_send_clear_spool() {
  // TODO: Drupal 7: replace time() with REQUEST_TIME.
  $expiration_time = time() - variable_get('views_send_spool_expire', 0) * 86400;
  db_query("DELETE FROM {views_send_spool} WHERE status = %d AND timestamp <= %d", 1, $expiration_time);
}
