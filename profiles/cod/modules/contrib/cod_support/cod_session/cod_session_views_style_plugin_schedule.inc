<?php

/**
 * This file and class must exist for the calendar plugin
 * to be recognized by Views.
 *
 * @ingroup views_style_plugins
 */
class cod_session_views_style_plugin_schedule extends views_plugin_style {
  
  function init(&$view, &$display, $options = NULL) {
    parent::init($view, $display, $options);
    // Set COD-specific settings.
    $view->cod_schedule_interactive = $this->options['schedule_interactive'];
    if (!empty($this->options['schedule_days'])) {
      $all_schedule_days = cod_session_days();
      $schedule_days = array_filter($this->options['schedule_days']);
      if (!empty($schedule_days)) {
        $view->cod_schedule_days = array_intersect_key($all_schedule_days, $schedule_days);
      }
      else {
        $view->cod_schedule_days = !empty($all_schedule_days) ? array_keys($all_schedule_days) : array();
      }
    }
    else {
      $schedule_days = cod_session_days();
      $view->cod_schedule_days = !empty($schedule_days) ? array_keys($schedule_days) : array();
    }
    $interactive_type = $this->options['interactive_type'];
    $view->cod_interactive_type = !empty($view->cod_schedule_interactive) ? $interactive_type : FALSE;

    $view->cod_room_queue = $this->options['room_queue'];
    $view->cod_time_queue = $this->options['time_queue'];

    // Make sure views does't try to limit the number of items in this view.
    $this->view->pager['items_per_page'] = 0;
  }
  
  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['schedule_interactive'] = 0;
    $schedule_days = cod_session_days();
    $options['schedule_days'] = !empty($schedule_days) ? array_keys($schedule_days) : array();
    $options['interactive_type'] = 0;
    $options['room_queue'] = NULL;
    $options['time_queue'] = NULL;
    return $options;
  }

  /**
   * Style options.
   */
  function options_form(&$form, &$form_state) {
    $schedule_days = cod_session_days();
    if (!empty($schedule_days)) {
      $form['schedule_days'] = array(
        '#title' => t('Schedule days'),
        '#default_value' => !empty($this->options['schedule_days']) ? $this->options['schedule_days'] : array(),
        '#type' => 'checkboxes',
        '#options' => $schedule_days,
        '#description' => t('Select which days to show on this display. Defaults to all event days.'),
      );
    }
    // "interactive" is an internal name, in the UI it's referred to as the
    // scheduling mode.
    $form['schedule_interactive'] = array(
      '#title' => t('Schedule mode'),
      '#default_value' => isset($this->options['schedule_interactive']) ? $this->options['schedule_interactive'] : 0,
      '#type' => 'radios',
      '#options' => array(0 => t('Show schedule only'), 1 => t('Show schedule and scheduling controls')),
      '#description' => t('Include schedule slot availability and scheduling link controls or just the schedule.'),
    );
    $types = cod_session_schedulable_types();
    $options = array(0 => 'N/A');
    foreach ($types as $type => $content_type) {
      $options[$type] = check_plain($content_type['name']);
    }
    $form['interactive_type'] = array(
      '#title' => t('Content type that can be scheduled'),
      '#default_value' => isset($this->options['interactive_type']) ? $this->options['interactive_type'] : 0,
      '#type' => 'radios',
      '#options' => $options,
      '#description' => t("Set the content type to provide scheduling controls for. 'Show schedule and scheduling controls' mode must be enabled."),
    );

    // Provide nodequeues for room and timeslot ordering. If set this nodequeue
    // becomes the argument to the schedule_room_list view.
    if (module_exists('nodequeue')) {
      $options = array();
      $queues = nodequeue_load_queues(nodequeue_get_all_qids(NULL));
      if (!empty($queues)) {
        foreach ($queues as $queue) {
          $options[$queue->qid] = $queue->title;
        }
    
        $form['room_queue'] = array(
          '#type' => 'radios',
          '#title' => t('Room queue'),
          '#options' => $options,
          '#default_value' => $this->options['room_queue'],
          '#description' => t('Limit and order rooms to the nodes in a queue.'),
        );
        $form['time_queue'] = array(
          '#type' => 'radios',
          '#title' => t('Time queue'),
          '#options' => $options,
          '#default_value' => $this->options['time_queue'],
          '#description' => t('Limit and order times to the nodes in a queue.'),
        );
      }
    }
  }
}