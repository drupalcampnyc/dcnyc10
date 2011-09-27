/**
 * WebINK's Fout-B-Gone is a single object that offers various methods for using and
 * managing custom Web Fonts added to webpages through the @font-face CSS rule.
 *
 * Note:  This is a work in progress and other useful font-related methods may be added in the future
 * 
 * Current methods:
 * 
 * 		fbg.hideFOUT -- automatically gets rid of undesirable flash-of-unstyled-text
 * 								that occurs with some browsers, such as FF 3.6 and IE9
 * 								
 * 		fbg.isFontFaceSupported -- returns true or false indicating if browser supports @font-face
 * 								This is the code written by Diego Perini as reported by Paul Irish on
 * 								2010.11.02 at http://paulirish.com/2009/font-face-feature-detection
 * 								We've included this check here in the form of a method for convenience;
 * 								it is not necessary for other fbg methods.
 * 								
 * 		
 * @author		Jay Vilhena <jvilhena@extensis.com>
 * @version		0.1
 
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

 */	
/***************************************************************************************/


var fbg = new function()
{
	//private vars
	var self = this;
	var test_frequency = 20;		//how often (in ms) to check if test node has been styled with last custom font in list
	var giveup = 3000;				//number of ms before it stops checking (i.e., custom font style was not applied)
	var latency = 100;				//delay between test node being detected as styled and hidden nodes being exposed  

	//public vars
	this.rfu = null;				//user settings

	//private method declarations
	var init = null;
	var onWinLoad = null;

	//public method declarations
	this.hideFOUT = null;
	this.isFontFaceSupported = null;
	
	//public events (callbacks) -- to be defined by client code
	
	this.onFontFaceFailed = null;
	
	/****************************************************************************/

	//private method definitions:

	init = function()
	{
		//rfu
	};
	
	onWinLoad = function(callback)
	{
		if (window.addEventListener) addEventListener('load',callback,false);
		else attachEvent('onload',callback);
	};
	
	/****************************************************************************/

	//public method definitions:
		

	this.hideFOUT = function(when, delay)
	{
		//inventories custom fonts used on a page and selectively hides only DOM elements that would cause flash-of-unstyled-text
		//args:  when -- 'asap'|'domready'|'onload'	-- when hidden content will revert to visible (optimum varies by page and browser)
		
		if (navigator.appName != 'Microsoft Internet Explorer' && !/Firefox\/3/.test(navigator.userAgent))
			return;									//browser-specific test because IE and Firefox 3.x are those w/ FOUT problem
		
		delay = delay || latency;
		
		var fontnams = [];
		var fontruls = [];
		var selectrs = [];
		var iscompliant = true;
					
		//inventory all custom fonts declared through @font-face rules and make list of all non-in-line css style rules in page:
		for (var i = 0; i < document.styleSheets.length; i++)
		{
			var stylsheet = document.styleSheets[i];
			
			if (!stylsheet.cssRules) 
			{											//find @font-face rules "manually" for IE8, IE7, etc.
				iscompliant = false;
				var rls = stylsheet.cssText;
				rls.replace(/@font-face\s*\{([^\}]+)\}/ig, function(r, t){
					var fontnam = r.replace(/([\s\S]*)(font-family:\s*['"]?)([-_0-9a-zA-Z]+)([\s\S]*)/, "$3");
					fontnams.push(fontnam);
					return r;
				});
			}		
				
			var ffrules = stylsheet.cssRules || stylsheet.rules;
			
			for (var j = 0; j < ffrules.length; j++)
			{
				var rul = ffrules[j];
					
				if (iscompliant && rul instanceof CSSFontFaceRule)
				{
					var fontnam = rul.cssText.replace(/([\s\S]*)(font-family:\s*['"]?)([-_0-9a-zA-Z]+)([\s\S]*)/, "$3");
					fontnams.push(fontnam);
				}
				else  fontruls.push(rul);				//CSSStyleRule
			}
			
			//alert(fontnams);
			//alert(fontruls.length);
		}
		
		//make list of all style rules that use a custom font
		for (var i = 0; i < fontnams.length; i++)
		{
			for (var j = 0; j < fontruls.length; j++)
			{
				var csstxt = iscompliant ? fontruls[j].cssText : fontruls[j].style.cssText;
				if (csstxt.indexOf(fontnams[i]) != -1)
				{
					selectrs.push(fontruls[j].selectorText);
				}
			}
		}

	
		//create a span node to be used for measuring default-font-styled vs custom-font-styled
		//Note:  the span technique is modeled after code developed by Paul Irish (http://paulirish.com/2009/font-face-feature-detection)
		var body = document.body || document.documentElement;  //.appendChild(document.createElement('testhost'));
		var spn = document.createElement('span');
		spn.setAttribute('style','font:99px _,serif;position:absolute;visibility:hidden');
		spn.innerHTML = 'Hello World';
		spn.id = 'fonttest';
		body.appendChild(spn);
		
		//var wid = spn.offsetWidth;		//moved further down; even though innerHTML was already set above, this is too early for IE
		
		//create a new stylesheet to store new classes with visibility:hidden for all nodes with custom fonts 
		var stl1 = document.createElement('style');
		document.getElementsByTagName("head")[0].appendChild(stl1);
		var allhidden = '';
		for (var i = 0; i < selectrs.length; i++)
			allhidden += (selectrs[i] + (i < (selectrs.length - 1) ? ', ' : ' '));
		allhidden += '{visibility:hidden}';
		if (stl1.styleSheet) stl1.styleSheet.cssText = allhidden;						//IE8, IE7
		else stl1.textContent = allhidden;												//e.g., "h1,div.test{visibility:hidden}";
	
		spn.style.font = '99px "' + fontnams[fontnams.length-1] + '",_,serif';			//apply custom font to test node, e.g., 'URWGroteskT_LigNar'
	
		var wid = spn.offsetWidth;			//at this time, tests in newer browsers (not IE7/IE8) show this as still the width of the original default-font
		
		//alert('before: ' + spn.offsetWidth);											//test:  shows width for default font
		//setTimeout(function(){alert('after: ' + spn.offsetWidth);}, 1000);			//test:  shows width for custom font		
		
		var temp1 = '';
		var freq = test_frequency;
		
		var showHidden = function()
		{
			var fnttest = setInterval(function()
			{			
				if (!wid && document.body)												//for the benefit of IE7 and IE8
				{
					body.removeChild(spn);
					document.body.appendChild(spn);
					wid = spn.offsetWidth;
				}
				var nu_wid = spn.offsetWidth;
				temp1 += (nu_wid + '   ');												//temp1 is used for dev only
				giveup -= freq;
				if (wid != nu_wid || giveup <= 0)
				{	
					clearInterval(fnttest);
					setTimeout(function(){stl1.parentNode.removeChild(stl1);}, delay);	//even 'asap' needs a small delay
					if (giveup <= 0 && self.onFontFaceFailed) self.onFontFaceFailed();
					spn.parentNode.removeChild(spn);
				} 
			}, freq);
		}

		//decide when to start testing if custom font has been applied
		if (when == 'asap')	showHidden();
		//else if (when == 'domready') head.ready("dom", showHidden);		//'domready' requires head.js (temporarily not supported)
		else if (when == 'onload') onWinLoad(showHidden);
		else showHidden();													//default is same as ('asap',100)

		
		if (window.TESTCAPTURE)												//dev testing only (optional)
		{
			onWinLoad(function()
			{
				document.getElementById('hf_monitor_div').innerHTML = temp1;
				setTimeout(function(){ document.getElementById('hf_monitor_div').innerHTML += '<br>Final: ' + spn.offsetWidth; }, 1000);				
			});
		}
				
	};
	
	this.isFontFaceSupported = function()
	{
		//The code in this method was written by Diego Perini
		var 
		sheet, doc = document,
		head = doc.head || doc.getElementsByTagName('head')[0] || docElement,
		style = doc.createElement("style"),
		impl = doc.implementation || { hasFeature: function() { return false; } };
		 
		style.type = 'text/css';
		head.insertBefore(style, head.firstChild);
		sheet = style.sheet || style.styleSheet;
		 
		var supportAtRule = impl.hasFeature('CSS2', '') ?
		        function(rule) {
		            if (!(sheet && rule)) return false;
		            var result = false;
		            try {
		                sheet.insertRule(rule, 0);
		                result = !(/unknown/i).test(sheet.cssRules[0].cssText);
		                sheet.deleteRule(sheet.cssRules.length - 1);
		            } catch(e) { }
		            return result;
		        } :
		        function(rule) {
		            if (!(sheet && rule)) return false;
		            sheet.cssText = rule;
		 
		            return sheet.cssText.length !== 0 && !(/unknown/i).test(sheet.cssText) &&
		              sheet.cssText
		                    .replace(/\r+|\n+/g, '')
		                    .indexOf(rule.split(' ')[0]) === 0;
		        };
		 
		return supportAtRule('@font-face { font-family: "font"; src: "font.ttf"; }');		
	};


	/****************************************************************************/

	init();		//startup stuff

}();

