
/**
 * @file
 * Helper functions and behaviors for the UC Variable Price product feature.
 */

/**
 * Add the override checkbox behavior to the product feature form.
 */
Drupal.behaviors.ucVarPriceOverride = function(context) {
  $('.override-checkbox:not(.ucVarPriceOverride-processed)', context).addClass('ucVarPriceOverride-processed').each(
    function() {
      // If the override box is not checked, hide the associated form field.
      if (this.checked == false) {
        $('#edit-' + this.id.substr(14) + '-wrapper').hide();
      }

      // Add an onchange function to show the associated field when required.
      $(this).change(
        function() {
          if (this.checked == true) {
            $('#edit-' + this.id.substr(14) + '-wrapper').show('fast');
          }
          else {
            $('#edit-' + this.id.substr(14) + '-wrapper').hide('fast');
          }
        }
      );
    }
  );
}

