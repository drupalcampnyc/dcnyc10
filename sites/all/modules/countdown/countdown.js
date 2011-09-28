// $Id: countdown.js,v 1.2.2.2 2008/05/12 15:29:47 deekayen Exp $

var _countdown_accuracy, _countdown_freq, _countdown_interval, _countdown_direction, _countdown_this;

function init_countdown(accuracy) {
  _countdown_accuracy = String('dhms').indexOf(accuracy);
  _countdown_interval = [24, 60, 60, 1];
  _countdown_freq = [86400, 3600, 60, 1];
  _countdown_direction = -1;
}

if (Drupal.jsEnabled) {
  function countUp() {
    _countdown_this.objDirText.nodeValue = _countdown_this.objDirText.nodeValue.replace(' until', ' since');
    _countdown_direction = 1;
    _countdown_this.initTime[0] = 0;
    _countdown_this.initTime[1] = 0;
    _countdown_this.initTime[2] = 0;
    _countdown_this.initTime[3] = 0;
    _countdown_this.objEM[0].innerHTML = String('0');
    _countdown_this.objEM[1].innerHTML = String('0');
    _countdown_this.objEM[2].innerHTML = String('0');
    _countdown_this.objEM[3].innerHTML = String('0');
  }

  jQuery.fn.extend({
    onready : function() { return this.each(function() { 
      this.objEM = new Array();
      this.initTime = new Array();
      for (i = 0; i < this.childNodes.length; i ++) {
        thisChild = this.childNodes.item(i);
        if (thisChild.tagName == 'EM') {
          this.objEM[this.objEM.length] = thisChild;
          this.initTime[this.initTime.length] = parseInt(thisChild.innerHTML);
        }
        else if (thisChild.nodeName == '#text') {
          if (thisChild.nodeValue.indexOf(' since') >= 0) {
            _countdown_direction = 1;
            this.objDirText = thisChild;
          }
          else if (thisChild.nodeValue.indexOf(' until') >= 0) {
            this.objDirText = thisChild;
          }
        }
      }

      _countdown_this = this;
      setInterval(function() {
        more = 1;
        for (accuracy = _countdown_accuracy; accuracy >= 0 && more; accuracy --) {
          value = _countdown_this.initTime[accuracy];
          if (_countdown_direction == 1) {
            if (accuracy > 0 && value >= _countdown_interval[accuracy - 1] - 1) {
              newValue = 0;
            }
            else {
              newValue = value + 1;
              more = 0;
            }
          }
          else {
            if (value) {
              newValue = value - 1;
              more = 0;
            }
            else if (accuracy == 0) {
              countUp();
              accuracy = _countdown_accuracy + 1;
              continue;
            }
            else {
              newValue = _countdown_interval[accuracy - 1] - 1;
            }
          }
          _countdown_this.initTime[accuracy] = newValue;
          _countdown_this.objEM[accuracy].innerHTML = String(newValue);
        }
      }, _countdown_freq[_countdown_accuracy] * 1000);
    }); }
  });

  $(document).ready(function() {
      $(".block-countdown .content").onready();
    }
  );
}