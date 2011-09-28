<?php
/**
 * implementation of hook_admin_settings
 * @return <type>
 */
function mailchimp_admin_settings() {
  module_load_include('php', 'mailchimp', 'MCAPI.class');

  $form = array();

  $form['mailchimp_account_info'] = array(
      '#type'       => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#title'      => 'MailChimp API Key',
  );
  $form['mailchimp_account_info']['mailchimp_api_key'] = array(
      '#type' => 'textfield',
      '#title' => t('Mailchimp API Key'),
      '#required' => TRUE,
      '#default_value' => variable_get('mailchimp_api_key', ''),
      '#description' => t('The API key for your MailChimp account. Get or generate a valid API key at your !apilink.', array('!apilink' => l(t('MailChimp API Dashboard'), 'http://admin.mailchimp.com/account/api')))
  );
  
  // only show the list selection forms if account info provided
  $api_key = variable_get('mailchimp_api_key', FALSE);
  if ($api_key) {
    $q = new MCAPI($api_key);

    if (!$q->errorCode) {
      $lists = $q->lists();
      if (!empty($lists)) {
        $form['mailchimp_lists'] = array(
            '#type'       => 'fieldset',
            '#collapsible' => FALSE,
            '#title'      => t('MailChimp Subscription Lists'),
            '#tree'         => TRUE
        );
        $saved_lists = variable_get('mailchimp_lists', NULL);
        foreach ($lists as $list) {
          $saved_list = $saved_lists[$list['id']];

          $form['mailchimp_lists']['mailchimp_list_'. $list['id']] = array(
              '#type'       => 'fieldset',
              '#collapsible' => TRUE,
              '#collapsed' => TRUE,
              '#title'      => $list['name'],
              '#tree'         => TRUE,
          );

          $form['mailchimp_lists']['mailchimp_list_'. $list['id']]['list_id'] = array(
              '#type'       => 'value',
              '#value'      => $list['id'],
          );

          $form['mailchimp_lists']['mailchimp_list_'. $list['id']]['name'] = array(
              '#type'       => 'value',
              '#value'      => $list['name'],
          );

          // Add a row of checkboxes for role enabling.
          $form['mailchimp_lists']['mailchimp_list_'. $list['id']]['roles'] = array(
              '#type'         => 'fieldset',
              '#title'        => t('Roles'),
              '#description'  => t('Choose which roles may subscribe to this list. All users will see the lists they\'re eligble for at the !subscribe and in the subscription block. Lists assigned to the Authenticated role may also apear in the registration form if that option is selected below. Authenticated user may also manage their list settings from their profile.', array('!subscribe' => l(t('newsletter subscription page'), 'mailchimp/subscribe'))),
              '#tree'         => TRUE,
          );

          foreach (user_roles() as $rid => $name) {
            $form['mailchimp_lists']['mailchimp_list_'. $list['id']]['roles'][$rid] = array(
                '#type'           => 'checkbox',
                '#title'          => $name,
                '#default_value'  => ($saved_list &&  !empty($saved_list->roles[$rid])) ? $saved_list->roles[$rid] : FALSE,
            );
          }

          $form['mailchimp_lists']['mailchimp_list_'. $list['id']]['label'] = array(
              '#type'           => 'textfield',
              '#title'          => t('List Label'),
              '#default_value'  => isset($saved_list->label) ? t($saved_list->label) : t('Subscribe to the @newsletter newsletter',  array('@newsletter' => $list['name'])),
              '#description'    => t('Enter the text to display next to the checkbox for this list on the registration and user account settings pages.  If you have only one list enabled, this text will also act as the default title for the Mailchimp block (which can be further overridden in the block settings).')
          );

          $form['mailchimp_lists']['mailchimp_list_'. $list['id']]['description'] = array(
              '#type'           => 'textarea',
              '#title'          => t('List Description'),
              '#default_value'  => $saved_list ? $saved_list->description : '',
              '#description'    => t('This description will be shown to the user on the list signup and user account settings pages')
          );

          $form['mailchimp_lists']['mailchimp_list_'. $list['id']]['listtype'] = array(
              '#type'           => 'select',
              '#title'          => t('Subscription Method'),
              '#options'        => array(MAILCHIMP_LISTTYPE_OPTIN => "Opt-in", MAILCHIMP_LISTTYPE_OPTOUT => 'Opt-out', MAILCHIMP_LISTTYPE_REQUIRED => 'Required'),
              '#default_value'  => ($saved_list) ?  $saved_list->listtype : MAILCHIMP_LISTTYPE_OPTOUT,
              '#description'    => t('<strong>Opt-in:</strong> Users must sign up to receive messages.<br/><strong>Opt-out: </strong> Users are automatically signed up but may unsubscribe.<br/><strong>Required: </strong> Users will remain on the list as long as they have an account and cannot unsubscribe.')
          );

          $form['mailchimp_lists']['mailchimp_list_'. $list['id']]['doublein'] = array(
              '#type'           => 'checkbox',
              '#title'          => t('Require subscribers to Double Opt-in'),
              '#default_value'  => $saved_list ? $saved_list->doublein : FALSE,
              '#description'    => t('New subscribers will be sent a link with an email they must follow to confirm their subscription.'),
          );
          $mergevars = $q->listMergeVars($list['id']);
          if ($mergevars) {
          // Merge var fieldset
            $form['mailchimp_lists']['mailchimp_list_'. $list['id']]['mergevars'] = array(
                '#type'         => 'fieldset',
                '#title'        => t('Merge Variables'),
                '#description'  => t('Select Drupal user variables to send to Mailchimp as Merge Variables. Available Drupal variables are any Profile or Token variables for the given user. For more information on Merge Variables, see the !doc. Not that some fields, such as ADDRESS fields which are multi-part, cannot be merged with a single token value.', array('!doc' => l(t('Mailchimp Documentation'), 'http://server.iad. liveperson.net/hc/s-31286565/cmd/kbresource/kb-8214439208090042855/view_question!PAGETYPE?sq=merge%2bvariables&sf=101113&sg=0&st=188569&documentid=143258&action=view'))),
                '#tree'         => TRUE,
            );
            $mergeoptions = mailchimp_get_merge_keys();
            foreach ($mergevars as $mergevar) {
              // filter out emails and addresses
              if (!in_array($mergevar['tag'], array('EMAIL', 'ADDRESS'))) {
                $form['mailchimp_lists']['mailchimp_list_'. $list['id']]['mergevars'][$mergevar['tag']] = array(
                    '#type'           => 'select',
                    '#title'          => $mergevar['name'],
                    '#options'        => $mergeoptions,
                    '#required'       => is_bool($mergevar['req']) ? $mergevar['req'] : FALSE,
                    '#default_value'  => ($saved_list && isset($saved_list->mergevars[$mergevar['tag']])) ? $saved_list->mergevars[$mergevar['tag']] : ''
                );
              }
            }
          }
        }

        $form['mailchimp_messages'] = array(
            '#type'       => 'fieldset',
            '#collapsible' => TRUE,
            '#collapsed' => TRUE,
            '#title'      => t('Anonymous Lists Messaging'),
        );
        $form['mailchimp_messages']['mailchimp_subscription_success_message'] = array(
            '#type'           => 'textarea',
            '#title'          => t('Subscription Success Message'),
            '#default_value'  => variable_get('mailchimp_subscription_success_message', t('Thank you, you have been successfully subscribed.'))
        );
        $form['mailchimp_messages']['mailchimp_subscription_failure_message'] = array(
            '#type'           => 'textarea',
            '#title'          => t('Subscription Failure Message'),
            '#default_value'  => variable_get('mailchimp_subscription_failure_message', t('We were unable to subscribe you at this time. Please try again later.'))
        );
        $form['mailchimp_page_settings'] = array(
            '#type'       => 'fieldset',
            '#collapsible' => TRUE,
            '#collapsed' => TRUE,
            '#title'      => t('Page titles and descriptions'),
        );        
        $form['mailchimp_page_settings']['mailchimp_subscribe_page_title'] = array(
            '#type'           => 'textfield',
            '#title'          => t('Subscribe page title'),
            '#description'    => t('The page title to display on the !subscribe_page.', array('!subscribe_page' => l(t('Subscribe page'), 'mailchimp/subscribe'))),
            '#default_value'  => t(variable_get('mailchimp_subscribe_page_title', 'Newsletter Subscription'))
        );
        
        $form['mailchimp_page_settings']['mailchimp_unsubscribe_page_title'] = array(
            '#type'           => 'textfield',
            '#title'          => t('Unsubscribe page title'),
            '#description'    => t('The page title to display on the !unsubscribe_page.', array('!unsubscribe_page' => l(t('Unsubscribe page'), 'mailchimp/unsubscribe'))),
            '#default_value'  => t(variable_get('mailchimp_unsubscribe_page_title', 'Newsletter Unsubscribe'))
        );
        
        $form['mailchimp_page_settings']['mailchimp_unsubscribe_page_description'] = array(
            '#type'           => 'textarea',
            '#title'          => t('Unsubscribe page description'),
            '#description'    => t('The text to display above the form on the !unsubscribe_page.', array('!unsubscribe_page' => l(t('Unsubscribe page'), 'mailchimp/unsubscribe'))),
            '#default_value'  => variable_get('mailchimp_unsubscribe_page_description', t('Use this form to unsubscribe from all of our newsletters.'))
        );
        $form['mailchimp_user_settings'] = array(
            '#type'       => 'fieldset',
            '#collapsible' => TRUE,
            '#collapsed' => TRUE,
            '#title'      => t('User settings'),
        );        
        $form['mailchimp_user_settings']['mailchimp_user_register'] = array(
            '#type'           => 'checkbox',
            '#title'          => t('Show subscription options on the user registration form.'),
            '#description'    => t('This will only apply for lists granted to the authenticated role.'),
            '#default_value'  => variable_get('mailchimp_user_register', TRUE)
        );
        $form['mailchimp_user_settings']['mailchimp_user_edit'] = array(
            '#type'           => 'checkbox',
            '#title'          => t('Show Subscription Options on User Edit Screen'),
            '#description'    => t('If set, a tab will be presented for managing newsletter subscriptions when editing an account.'),
            '#default_value'  => variable_get('mailchimp_user_edit', TRUE)
        );
        $form['mailchimp_user_settings']['mailchimp_user_settings_title'] = array(
            '#type'           => 'textfield',
            '#title'          => t('User settings title'),
            '#description'    => t('If you\'ve enabled subscription options on the user registration form or the user edit screen, this text will be used as the fieldset and page title respectively.'),
            '#default_value'  => t(variable_get('mailchimp_user_settings_title', 'Newsletter Subscriptions'))
        );
        $form['mailchimp_user_settings']['mailchimp_interest_groups_user_forms'] = array(
            '#type'           => 'checkbox',
            '#title'          => t('Show Interest Groups on Registration and Account Forms'),
            '#default_value'  => variable_get('mailchimp_interest_groups_user_forms', FALSE),
            '#description'    => t('If set, users will be able to select applicable interest groups when signing up for newsletters.')
        );

        $form['cron'] = array(
          '#type' => 'fieldset',
          '#title' => t('Mailchimp Cron'),
        );
        $form['cron']['info'] = array(
          '#value' => t('Updates to Mailchimp can be done when the user is added or edited, or deferred until the next cron run. Deferring these updates to cron will speed up the user interface when accounts are added, edited, or deleted. You need to ensure cron is running correctly, and that it keeping up with the number of user edits on your site. You may need to !rebuild when switching to cron processing. There are currently !count users with pending updates in the queue.', 
          array(
            '!count' => '<strong>' . db_result(db_query('SELECT COUNT(*) FROM {mailchimp_user} WHERE status = \'%s\'', MAILCHIMP_USERSTATUS_PENDING)) . '</strong>',
            '!rebuild' => l('rebuild the MailChimp User table', 'admin/settings/mailchimp/rebuild'))),
        );
        $form['cron']['mailchimp_cron'] = array(
            '#type'           => 'checkbox',
            '#title'          => t('Sync Required Lists During Cron'),
            '#default_value'  => variable_get('mailchimp_cron', FALSE),
            '#description'    => t('If this is set, users will be subscribed to the required list during cron runs. Otherwise subscription will take place when a user is added/edited.'),
        );
        // NB: This is the maximum number of users to update, but unless you have required lists,
        // the actual number of users subscribed and therefore updated will likely be signficantly less.
        $form['cron']['mailchimp_batch_limit'] = array(
          '#type' => 'select',
          '#options' => array(
            '1' => '1',
            '10' => '10',
            '25' => '25',
            '50' => '50',
            '75' => '75',
            '100' => '100',
            '250' => '250',
            '500' => '500',
            '750' => '750',
            '1000' => '1000',
            '2500' => '2500',
            '5000' => '5000',
            '7500' => '7500',
            '10000' => '10000',
          ),
          '#title' => t('Batch limit'),
          '#description' => t('Maximum number of users to process in a single cron run. Mailchimp suggest keeping this below 5000-10000. Ignored if updates take place on user add / edit.'),
          '#default_value' => variable_get('mailchimp_batch_limit', 100),
        );
      }
      else {
        drupal_set_message(t('You do not have any valid MailChimp mailing lists.'));
      }
    }
    else if (FALSE && $q->errorCode === 'INVALID_LOGIN') {
        drupal_set_message(t('Could not login to mailchimp. Please check your username and password.'), "error");
      }
      else if ($q->errorMessage) {
          drupal_set_message(t('Could not retrieve info for mailchimp. The following error was returned: %error.', array('%error' => $q->errorMessage)), "error");
        }
        else {
          drupal_set_message(t('Could not retrieve info for mailchimp for an unknown reason. Please try again later'), "error");
        }
  }

  $form['#submit'][] = 'mailchimp_admin_settings_submit';

  return system_settings_form($form);
}

/**
 * Serialize the saved lists and notify users of the need to rebuild the user's table.
 */
function mailchimp_admin_settings_submit($form, &$form_state) {
  // no lists selected or first time here
  if(empty($form_state['values']['mailchimp_lists'])){
    return;
  }
  
  $required = FALSE;
  $lists = array();
  foreach ($form_state['values']['mailchimp_lists'] as $form_list) {
    $list = new stdClass();
    $list->id = $form_list['list_id'];
    $list->name = $form_list['name'];
    $list->roles = array_filter($form_list['roles']);
    $list->description = $form_list['description'];
    $list->label = $form_list['label'];
    $list->listtype = $form_list['listtype'];
    $list->doublein = $form_list['doublein'];
    $list->mergevars  = $form_list['mergevars'];
    $lists[$form_list['list_id']] = $list;
    
    $required = ($form_list['listtype'] == MAILCHIMP_LISTTYPE_REQUIRED && $form_state['values']['mailchimp_cron']);
  }
  
  // remove lists from the form_state so they are not saved twice
  unset($form_state['values']['mailchimp_lists']);
  variable_set('mailchimp_lists', $lists);
  
  // let users know they may need to rebuild the user's table
  if ($required) {
    drupal_set_message(t('At least one list is marked as required and updates are handled via cron. You may need to !rebuild.', 
      array('!rebuild' => l('rebuid the MailChimp users table', 'admin/settings/mailchimp/rebuild'))));
  }  
}