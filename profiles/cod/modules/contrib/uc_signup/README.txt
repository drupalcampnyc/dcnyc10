UC_Signup - README - http://drupal.org/project/uc_signup

UC_Signup provides integration between Signup.module and Ubercart, allowing users to purchase signups for events.
This module was written by <a href="http://drupal.org/user/69959/">ezra-g</a> from <a href="http://growingventuresolutions.com/">Growing Venture Solutions</a>, working in association with <a href="http://dtek.net">D-Tek Digital Media</a>, and has been sponsored by <a href="http://www.aussiepd.com/">AUSSIE</a> and the <a href="http://www.wearepowershift.org/">2011 PowerShift conference</a>.

Approach:
Signup-enabled nodes are configured as Ubercart products. When an order is submitted, if it contains any signup-enabled products, the user associated with the order is automatically signed up for each event in the cart. Once checkout is complete, if the order balance is not cleared, the signups are cancelled. If the balance is cleared, the signups are converted from temporary to final signups. UC_Signup stores this distinction in the form_data column of signup_log, where it also records the order id.
Signup IDs are displayed when viewing Ubercart orders as both an order pane visible to customers and through administrative comments on the order, which are preserved even if the signups are deleted.


UC_Signup uses the Ubercart Conditional Actions system to finalize and cancel signups for an order.

Setup:
1) Create one or more Ubercart product classes at admin/store/products/classes
2) Make the resulting content types signup-enabled by editing the content type(s) at admin/content/types
3) Add a date field to the resulting content types at admin/content/types
4) Fill out the "Date field to use with signup" inside the "Signup settings" fieldset when configuring
   the content type at http://localhost/dev/gvs/aussie/admin/content/node-type/[type-name]
5) You must have at least one core user profile field configured with the "Visible in uc_signup attendee information form" option at admin/user/profile.
This option is useful for controlling which profile fields display as part of the uc_signup checkout process and which ones do not.
 
Optional Configuration:
Most settings for the uc_signup module are available at admin/settings/signup.

Some configuration steps that are possible with uc_signup:

- One main benefit of uc_signup is that it allows one user to signup on behalf of multiple users. If you want to take advantage of this benefit, authenticated users must have the "purchase signups for other users" permission.

- Specify the text that should appear in the "Add to cart" button, such as "Sign up", as well as the text to use for this button when signups are disabled for a node.
-  Skip checkout for free signup-enabled products
If checked, users can sign up for free events without passing through the checkout process by clicking the Signup button. If checked, the signup button is hidden and the user must pass through the checkout process, even for free events. 

- Send account notification emails when accounts are created
When enabled account activation emails will be sent when uc_signup automatically creates accounts.

- Display user profile fields to authenticated users.
When enabled and a single user signs herself up via uc_signup, she can change existing or enter new profile field values.


- Configure the uc_signup_admin_list view for use as the Signup.module administrative view.
  This View contains a link to the signup associated with an order and does not include the Signup.module's "extra information"
  field which is generally supercedeed by user profile fields.
  Browse to admin/settings/signup , open the "Advanced settings" fieldset
  and for the "View to embed for the signup administrative list" option, select the page display of the
  uc_signup_admin_list view.

- Add user profile fields to display on this view.

- Prevent the signup tab from displaying to non-administrators
  on signup-enabled nodes (admin/settings/signup).

Cancelling/Changing Signups:
  Users can edit their profile fields (as long as they have permission),
  but any changes to a signup, such as who is attending, which event is being attended
  or cancellations must be made by an administrator. Refunds can be handled through Ubercart,
  and Signup.module provides the following administrator permisisons:
  "cancel signups" "administer all signups", "view all signups" .
  The Signups tab will display to administrators on signup-enabled nodes
  and provides acccess to these administrative features.
   from the signup tab provided 