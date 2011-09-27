
Views Send allow sending mass mailing using Views Bulk Operations - VBO
(http://drupal.org/project/views_bulk_operations). The messages are queued in a
spool table and delivered only on cron. You can control how many messages will
be send per cron run.

INSTALLATION

Proceed as with all modules in Drupal (see http://drupal.org/node/70151). Views
Bulk Operations must be enabled before.

CONFIGURATION

General settings can be configured at: Site Configuration > Views Send

USAGE

 1. Create a view and add at least one column containing E-mail addresses.
 2. [Optional] Expose Views filters to let the user easily build list of
    recipients using UI.
 3. Create a "Page" display and set the Style to "Bulk Operations".
 4. On "Bulk Operations" Style configuration, under "Selected operations",
    select Send mass mail (views_send_mail_action).
 5. Save the view, load the page, use exposed filters to build the list, select
    all or some rows and choose "Send mass mail".
 6. Fill the message form to configure the E-mail. Use tokens to personalize
    your E-mail.
 7. Preview and send the message.

DEPENDENCIES & INTEGRATION

 * Views Send depends on Views Bulk Operations.
 * The module integrates features from:
  o Mime Mail. When Mime Mail module is enabled, the user can choose to send
    rich HTML messages.
  o Tokens. When Tokens module is enabled, the user can insert context tokens
    into the subject or body of the message. Note that row-based tokens are
    available even if Tokens module is disabled.

SIMILAR MODULES

You may want to try also:

 * Views Mail | http://drupal.org/project/views_mail
   See what's different: http://drupal.org/node/795782
 * Simplenews | http://drupal.org/project/simplenews
   Some pieces of code were inspired by Simplenews module.

HOW CAN YOU GET INVOLVED?

 * Write a review for this module on http://drupalmodules.com/module/views-send
 * Help translate this module at Drupal Localize Server
   http://localize.drupal.org/translate/projects/views_send

MAINTAINERS & SPONSORS

 * Module author & maintainer
   Claudiu Cristea (claudiu.cristea) | http://drupal.org/user/56348
 * This module is sponsored by Grafit SRL | http://www.grafitsolutions.ro
