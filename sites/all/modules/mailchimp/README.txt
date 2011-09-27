$Id:
This module provides integration with the MailChimp email delivery service. While tools for sending email from your own server, like SimpleNews, are great, they lack the sophistication and ease of use of dedicated email providers like MailChimp. Other players in this field are Constant Contact and Campaign Monitor.

This module is still in active development, and here are the current features:

   1. Support for an unlimited number of mailing lists
   2. Having an anonymous sign up form to enroll users in a general newsletter.
   3. list access by role
   4. editing of user list subscriptions on the user's edit page
   5. list subscribe on register page
   6. customizable merge vars with token, profile and bio.module integreation
   7. opt-in, opt-out and required lists
   8. standalone subscribe and unsubscribe forms
   9. subscriptions can be maintained via cron or real time.

The new 5.2 and 6.x branches use the latest MailChimp API and have plenty of usability improvements.

Installing Mailchimp:
  Download the Mailchimp release for your version.
  Untar it in the modules directory.
  Activate the module through drupals administrative interface.
  IMPORTANT: Please ensure you have at least one active list created in MailChimp.
  