<?php
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $language->language; ?>" xml:lang="<?php print $language->language; ?>">

<head>
  <title><?php print $head_title; ?></title>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=8">
  <meta name="author" content="Google">
  <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no, target-densitydpi=240">
  <script src="//ajax.googleapis.com/ajax/libs/jquery/1.4.2/jquery.min.js"></script>
  <style>
    * {
      font-family: sans-serif;
      margin: 0;
      padding: 0;
      font-size: 27px;
      line-height: 36px;
    }
    span {
      padding: 15px;
      border-top: 1px solid #ccc;
      border-bottom: 3px solid #ccc;
      background: #eee;
      display: block;
    }
    * + span {
      margin-top: 60px;
    }
    p, .button-link, ul,
    .vert-item {
      margin: 15px;
    }
    li {
      margin-left: 30px;
      list-style: disc;
    }
    span a {
      display: block;
      text-decoration: none;
      font-weight: bold;
      text-align: center;
      background-color: #29549f;
      color: #fff;
      padding: 15px;
      border-radius: 9px;
    }
    a.active {
      background-color: #132648;
      outline: 0;
    }
  </style>
</head>

<body id="<?php print $body_id; ?>" class="<?php print $body_classes; ?>">
  <?php if ($content): ?>
    <?php print $content; ?>
  <?php endif; ?>
  </div><!-- /page -->
  <script>
    $('a')
      .bind('touchstart', function(e) {
        $(this).addClass('active');
      })
      .bind('touchend touchcancel', function(e) {
        $(this).removeClass('active');
      });
  </script>
</body>
</html>
