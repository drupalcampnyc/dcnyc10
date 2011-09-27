<?php

/**
 * Implementation of hook_uuid_features_default_content().
 */
function cod_base_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
  'type' => 'page',
  'language' => '',
  'uid' => '0',
  'status' => '1',
  'created' => '1295470463',
  'changed' => '1310438266',
  'comment' => '0',
  'promote' => '1',
  'moderate' => '0',
  'sticky' => '0',
  'tnid' => '0',
  'translate' => '0',
  'revision_uid' => '1',
  'title' => 'COD help',
  'body' => '<em>For the latest documentation, please visit <a href="http://drupal.org/documentation/build/cod">http://drupal.org/documentation/build/cod</a>.</em>
        
COD is the Conference Organizing Distribution, used for building conference and event sites in Drupal.  You may first be interested in an <a href="http://usecod.com/features">overview of COD\'s capabilities</a>. The primary project page is at http://drupal.org/project/cod_support.

This documentation is based on the packaged COD Beta 1 downloaded from <a href="http://usecod.com/download">usecod.com/download</a>, with some additional documentation that will be released in Beta 1.

While we have tried to make the interface and documentation useful, learning about fundamental Drupal concepts such as permissions and essential modules such as Views and Ubercart are necessary to get the most out of COD.

<h2>Getting started</h2>

<ol>
<li>Download COD. <a href="http://drupal.org/documentation/build/cod/download">Need help downloading COD?</a>
<li>Install COD as you would any other Drupal site, but choose "Conference Organizing Distribution". See the <a href="http://drupal.org/documentation/install">Drupal installation guide</a> for more details.
<li>Once installed and logged (you will be user 1, with administrative capabilities). Create a few test users.
<li>Note that COD ships with many default settings that you will override as you create your site:
<ul>
<li>These user roles are created automatically: session organizer, site administrator and sponsor organizer roles. You may want to add additional roles, such as "attendee" and "speaker", depending on how you want people to interact with the site. You can edit roles anytime.
<li>COD does not enable most permissions by default intentionally, so you\'ll need to add permissions for each of your roles or people won\'t be able to register, suggest sessions, vote, etc. You can edit permissions anytime.
<li>Comments are disabled by default on events, sponsors, rooms, time slots, and schedule items.
</ul>
<li>The default home page is the COD configuration instructions.  You should unpublish it before making the site available to non-admins.
<li>Create a new home page with Views, Panels or a single node that\'s configured to be the front page.
</ol>

<h2>Conference management menu</h2>
Common conference management tasks e.g. session moderation appear in the  Admin module menu

Collapsed, this looks like a small wrench in the upper left corner of your browser window. Clicking on it will expand it display an administration menu, which you\'ll use to administer your site. The menu items here can also be customized, as we have done with the \'Conference management\' section of the admin toolbar.

<h2>Display images</h2>
<ul>
<li>Be sure to enable ImageAPI GD2 or ImageAPI ImageMagick.
<li>Enable Imagecache UI (optional).
</ul>


<h2>Create an event for people to attend</h2>
<ol>
<li>First, create an event node (node/add/event). Title, SKU, and a sell price are required for paid events, but description, start date/time, and end date/time are highly recommended. Everything else is optional.
<li>Install and configure an Ubercart payment gateway, or disable/uninstall Ubercart if you aren\'t going to charge for your event.
<li>Ensure people can find the link to sign up, either by creating a block or primary menu link.
<li>Check permissions (as in, anonymous users have permission to sign up) and start promoting.
</ol>


<h2>Sponsor setup</h2>
<ol> 
<li>Enable the COD sponsors feature is enabled by default (admin/build/modules). This also enables the \'Conference administration\' admin menu.
<li>If needed, modify sponsor levels (e.g. platinum) in the allowed values list of the Sponsor content type (admin/content/node-type/sponsor/fields/field_sponsorship_level)
<li>Adjust permissions if you\'d like sponsors to create their own sponsor node (it will remain unpublished until an admin approves and publishes it).
<li>Modify Sponsor view if you\'d like additional sponsor levels to appear on the Sponsor page (by default, only platinum display)
<li>Or, arrange the blocks (admin/build/block) so the other levels. There are separate sponsor blocks for home page and internal pages
<li>If needed, rename sponsor levels in the view
<li>Assign Sponsor blocks to regions
<li>Check viewing and editing permissions are appropriate for your needs. Note that only published sponsor nodes display.
</ol>

<h2>Community configuration (attendees)</h2>
Full names and photos of attendees are displayed and filterable at /community. Only people who have signed up for the event (i.e. have a signup id associated with their user account) will appear in this list.
<ol> 
<li>The COD Community feature is enabled by default (admin/build/modules).
<li>You can perform Views Bulk Operations on anyone with an account
<li>The cod_community view displays name, photo and core profile fields of signed up users out of the box, with exposed filters.
<li>A  forum menu link also appears
</ol>

<h2>Attendee profiles</h2>
User accounts contain any personal information tab. First and last name are required because they display in the community page, and for presenters, their full name will display on schedules and session nodes.

Organization (company) name, job title and interests are optional. You can also modify these or create additional fields at /admin/user/profile.


<h2>Add signups manually without payment</h2>
In some cases, you may want to give away tickets, and not collect payment from them, like for keynote speakers, sponsors, organizers or other volunteers.
<ol> 
<li>To do this, you will need the \'administer user\'s and the \'administer signup\' permission
<li>Create a user account for the person if there isn\'t one already
<li>Go to the event node and click Signups
<li>Click <strong>add</strong> to create a signup
<li>Enter username
<li>Click <strong>Signup </strong>
<li>They will be added to the list of attendees, should get an email notification immediately, and will get a reminder notification before the event (if configured).
</ol>

<h2>Session collection</h2>
<ol>
<li>Enable the COD Session feature is enabled by default (admin/build/modules). This enables the \'Conference administration\' admin menu.
<li>Update the session Track field allowed values in the Session content type (admin/content/node-type/session/fields/field_track)
<li>As sessions are created, visit the Session administration (conference-admin/sessions) to manage sessions; review and publish submitted sessions so they are visible to the public
</ol>

<h2>Voting on sessions</h2>
<ol>
<li>Voting usually begins once you\'ve finished accepting new sessions, so votes are applied fairly.
<li>Adjust flag access on the Session vote flag (flags/manage/session_vote) to allow other roles to vote on sessions.
<li>You will probably want to do some additional theming to ensure the "Vote for this session" links are more prominent on session nodes, or build a view that shows all notes that haven\'t been voted on by the current user, filterable by track/experience level.
<li>Remove the flag access by role (flags/manage/session_vote) when you want to stop allowing people to vote.
</ol>


<h2>Create the schedule</h2>

The cod_schedule view is restricted by default to keep it private while organizers are still working on it. It doesn\'t display anything until rooms and time slots are created, and sessions are assigned to time slots.

<ol>
<li>Create Room and Time slot nodes. These will be the framework for your schedule.
<li>Sessions and Schedule items are different content types. A Schedule item is something like Lunch, that doesn\'t have a presenter or track, but needs to be assigned a room and time slot.
<li>Sessions and schedule items can be assigned to multiple rooms. Assign an item to all rooms for it span the width of the schedule grid and indicate there are not other sessions planned during that time (e.g. Registration)
<li>Sessions and Schedule items need to have a Room and Time slot assigned to them to appear in the schedule, as well as be Accepted and Published.
<li>You won\'t be able to schedule two sessions/schedule items in the same time slot and room; a warning message will appear, explaining the conflict.
<li>When you are happy with the schedule, change the View access restriction accordingly.
</ol>

<h2>"Your Schedule" display</h2>
<ol>
<li>When you\'re ready for people to add sessions to their personal schedule, go to admin/build/flags
<li>Edit the session_schedule flag, and assign access to this flag to one or more roles 
<li>You can add this flag to additional scheduleable content types (e.g. BoF or workshops)
<li>Make any other configuration changes you wish, then Save.
</ol>

<h2>Checking in attendees</h2>
The conference management menu has a "Check in attendees" link to conference-admin/checkin. You must have the Attendee manager role to use this list. This list shows everybody who has a signup ID, along with their full names, username, sign-up time and more.

When attendees arrive to collect their badge and other materials, simply put a checkbox next to their name and click “Mark signup attended”. 

You may want to make modifications to this view, including removing the button “Marked sign-up did not attend” if there is a chance the wrong button may be used inadvertently during a crowded registration morning, and you may want to display more than 100 attendee names at once.

<h2>Other configuration considerations</h2>
COD includes default empty text in the Views. You may want to review and change this text as needed.
',
  'teaser' => '<em>For the latest documentation, please visit <a href="http://drupal.org/documentation/build/cod">http://drupal.org/documentation/build/cod</a>.</em>
        
COD is the Conference Organizing Distribution, used for building conference and event sites in Drupal.  You may first be interested in an <a href="http://usecod.com/features">overview of COD\'s capabilities</a>. The primary project page is at http://drupal.org/project/cod_support.
',
  'log' => '',
  'revision_timestamp' => '1310438266',
  'format' => '2',
  'name' => '',
  'picture' => '',
  'data' => NULL,
  'path' => 'cod-help',
  'signup' => 0,
  'last_comment_timestamp' => '1295735036',
  'last_comment_name' => NULL,
  'comment_count' => '0',
  'taxonomy' => array(),
  'uuid' => '79f090a8-755e-102e-a8fe-4040db1cdced',
  'revision_uuid' => '79f12ce8-755e-102e-a8fe-4040db1cdced',
  'pathauto_perform_alias' => FALSE,
);
  return $nodes;
}
