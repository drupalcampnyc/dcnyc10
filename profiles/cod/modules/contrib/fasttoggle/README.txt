fasttoggle.module
=================

This module is a result of SoC 2006 from the Administration usability project.
It adds "fast toggling" capabilities to Drupal so that you can perform common
tasks a lot quicker because they are managed via AJAX callbacks instead of
loading new pages every time you unpublish a node for example.

Currently, fasttoggle.module has these functionalites:

* Add publish/unpublish, sticky/not sticky and promoted/not promoted links to
  each node
* Add publish/unpublish links to the content listing in the administration
  section
* Add block/unblock links to the user listing in the administration section
  and to the user profile of each user
* Adds publish/unpublish links to each comment
* Adds a field type "Fasttoggle" to views which allows fasttoggling of nodes.


CUSTOMIZING LABELS
==================
In addition to selecting a different predefined set of labels that show
actions instead of the current state, you can also define your own set of
labels. In your settings.php, you can add:

$conf['fasttoggle_labels'] = array(
  'node_status' => array(0 => 'show', 1 => 'hide'),
);

to change the label for toggling the node status. The fasttoggle options this
module ships with by default are:
    - node_status
    - node_sticky
    - node_promote
    - comment_admin
    - user_status
    - comment_status

For further details on the syntax, see the fasttoggle_fasttoggle_labels()
function. Additionally, you can write modules that override these strings by
implementing hook_fasttoggle_labels().

After you added your custom strings, make sure to select them on the
configuration page.


THEMING LINKS
=============
There is no dedicated theme function for altering the HTML code of fasttoggle
links, however, the module applies classes to the <a> tag in the form
"fasttoggle-status-<type>-<option>-<status>" with status being 0, 1 or 2.
The status number always refers to the current state of the option (e.g. it's
0 for an unpublished node's "publish" link). Make sure that the throbbing
graphic is appropriately displayed when overriding the background image.


PERMISSIONS
===========
It is possible to control what links are displayed in a very fine-grained way.
Only users who have the ability to toggle a specific setting may update this
setting. They can only change nodes they have admin access to. This means that
fasttoggle.module plays nicely with node access modules as well.
