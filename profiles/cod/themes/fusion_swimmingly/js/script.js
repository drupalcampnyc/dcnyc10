Drupal.behaviors.fusionSuperfish = function (context) {
  $("#primary-menu ul.sf-menu").superfish({
    hoverClass:    'sfHover',
    pathClass:     'active-trail', 
    pathLevels:    1, 
    dropShadows:   false,               // completely disable drop shadows by setting this to false 
    disableHI:     false,
    animation:     {height: 'show'},
    speend:        'fast'              // set to true to disable hoverIntent detection  
  }).supposition();
};

Drupal.behaviors.fusionEqualheightsSidebars = function (context) {
  if(parseFloat($.browser.version) == 6) {
  } else{
    var $mainHeight = $('#main-group').innerHeight();

    $('.sidebar-last-inner').css('min-height', $mainHeight);
    $('.sidebar-first-inner').css('min-height', $mainHeight);
  }
}

Drupal.behaviors.fusionNavbarWidth= function (context) {
  var $mainWidth = $('#main-group').innerWidth();
  
  $('.sf-navbar li ul').css('width', $mainWidth);
   
    $('.sf-navbar li.expanded ul').each(function(index){
  
    var parent = $(this).parent('li.expanded');
    var position = parent.position();
    var space = 960 - position.left;
    var childWidth = $(this).outerWidth();
    
      if(space > childWidth){
        $(this).css({
         'left' : position.left * -1,
        });
      } else {
        $(this).css({
         'left' : (position.left * -1) - 15, 
        });
      }
  
    });
     $('.sf-navbar li.active-trail ul').show(); 
  
  }