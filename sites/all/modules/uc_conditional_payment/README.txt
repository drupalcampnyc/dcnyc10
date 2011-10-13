uc_conditional_payments
=======================

Developed by longwave <dave@longwaveconsulting.com>


This module adds Conditional Actions support to Ubercart payment methods, so
payment methods can be restricted by cart total, user role, or any other
conditions that Conditional Actions provides.

This does not override the standard payment methods page at
/admin/store/settings/payment/edit/methods - disabled payment methods will
never be available, and enabled payment methods will (unless a condition is
added) be available at checkout.


Example:

Restricting the "Other" payment method to cart totals of at least $100.00:

1. Enable the "Conditional payments", "Payment Method Pack" and "Conditional
   Actions" modules.

2. Visit the Conditional Actions administration page and note that a new
   predicate is listed for each available payment method.

3. Click "edit" for the "Payment via Other" predicate, then "Conditions".

4. Select "Compare the cart total to a specified price" from the dropdown
   list and click "Add condition".

5. Give the condition a title such as "Check cart total is at least $100".

6. Select "Greater than or equal to" for the operation and enter "100" in
   the price field.

7. Click "Save changes".


Now when users visit the checkout and less than $100 worth of items are in
their cart, the "Other" payment will not be available.
