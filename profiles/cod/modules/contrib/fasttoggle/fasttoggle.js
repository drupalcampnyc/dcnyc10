
Drupal.fasttoggle = {
  'className': function(data) {
     $(this)
       .attr('class', $(this).attr('class').replace(/\bfasttoggle-status-[^\s]+/, ''))
       .addClass(data.className);
  },

  'comment': function(data) {
    if (data.option == 'status') {
      $(this).parents('.comment')[data.status ? 'addClass' : 'removeClass']('comment-unpublished');
    }
  },

  'node': function(data) {
    var node = $(this).parents('.node');

    if (data.option == 'sticky') {
      node[data.status ? 'addClass' : 'removeClass']('sticky');
    }
    else if (data.option == 'status') {
      node[data.status ? 'removeClass' : 'addClass']('node-unpublished');
    }
  }
};

Drupal.behaviors.fasttoggle = function(context) {
  // Unbind is used to prevent dblclick module from interfering.
  $('a.fasttoggle', context).unbind('click').click(function() {
    // Add the throbber
    var link = $(this).addClass('throbbing');

    // Perform a request to the server
    jQuery.ajax({
      'url': this.href,
      'type': 'POST',
      'cache': false,
      'data': { confirm: true, javascript: true },
      'dataType': 'json',
      'success': function(data) {
        // Remove the throbber
        link.text(data.text).removeClass('throbbing');

        // Change the class name of the link after toggling it.
        if (data.className) {
          Drupal.fasttoggle.className.call(link[0], data);
        }

        // Call the callback function for altering the display of other elements
        if (data.callback && Drupal.fasttoggle[data.callback]) {
          Drupal.fasttoggle[data.callback].call(link[0], data);
        }
      },
      'error': function() {
        // Remove the throbber
        link.removeClass('throbbing');
        alert(Drupal.t('Toggling the setting failed.'));
      }
    });

    // Do not execute the regular functionality when the user clicks the link
    return false;
  });
};
