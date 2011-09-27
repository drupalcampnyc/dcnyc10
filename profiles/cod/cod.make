; Conference Organizing Distribution dev snapshot makefile
; The purpose of this makefile is to make it easier for people to install
; the dev version of COD and its dependencies, including patches, before
; a new full release of the distribution is rolled.  

api = 2
core = 6.x

; Required versions of Drupal contributed projects.
projects[admin][subdir] = contrib

projects[cck][subdir] = contrib

projects[auto_nodetitle][subdir] = contrib

projects[comment_notify][subdir] = contrib

projects[context][subdir] = contrib
projects[context][version] = 3.0

projects[ctools][subdir] = contrib
projects[ctools][version] = 1.8

projects[strongarm][subdir] = contrib
; http://drupal.org/node/792472#comment-3538100
projects[strongarm][patch][] = "http://drupal.org/files/issues/792472_15_node_pipe.patch"

projects[link][subdir] = contrib

projects[date][subdir] = contrib

projects[diff][subdir] = contrib

projects[checkbox_validate][subdir] = contrib

projects[emfield][subdir] = contrib

projects[fasttoggle][subdir] = contrib

projects[flag][subdir] = contrib
projects[flag][version] = 2.0-beta5

; git checkout of Features 6.x-1.x
projects[features][subdir] = contrib
projects[features][download][type] = "git"
projects[features][download][branch] = "6.x-1.x"
projects[features][download][url] = "http://git.drupal.org/project/features.git"
; http://drupal.org/node/968826#comment-3863422
projects[features][patch][] = "http://drupal.org/files/issues/968826-features-menu-uuid.patch"
; http://drupal.org/node/912716#comment-3899924
projects[features][patch][] ="http://drupal.org/files/issues/features-profile-fields-912716-11.patch"
; http://drupal.org/node/860974#comment-3505484
projects[features][patch][] = "http://drupal.org/files/issues/features.860974.patch"


projects[filefield][subdir] = contrib

projects[globalredirect][subdir] = contrib

projects[imagefield][subdir] = contrib

projects[imageapi][subdir] = contrib

projects[imagecache][subdir] = contrib

projects[jquery_ui][subdir] = contrib

projects[markdown][subdir] = contrib

projects[nodeaccess_userreference][subdir] = contrib

projects[pathauto][subdir] = contrib

projects[panels][subdir] = contrib

projects[path_redirect][subdir] = contrib

projects[skinr][subdir] = contrib

projects[signup][subdir] = contrib

projects[signup_profile][subdir] = contrib

projects[skinr][subdir = contrib

projects[token][subdir] = contrib

projects[uc_signup][subdir] = contrib

projects[uc_node_checkout][subdir] = contrib

projects[uuid][subdir] = contrib
projects[uuid][download][type] = "git"
projects[uuid][download][url] = "http://git.drupal.org/project/uuid.git"
projects[uuid][download][revision] = "6.x-1.x"

projects[uuid_features][subdir] = contrib
projects[uuid_features][download][type] = "git"
projects[uuid_features][download][url] = "http://git.drupal.org/project/uuid_features.git"
projects[uuid_features][download][revision] = "6.x-1.x"


projects[ubercart][subdir] = contrib

projects[views][subdir] = contrib

projects[views_bulk_operations][subdir] = contrib

projects[views_send][subdir] = contrib

projects[fusion_swimmingly][type] = theme

projects[fusion][type] = theme
projects[fusion][download][type] = git
projects[fusion][download][url] = "http://git.drupal.org/project/fusion.git"
projects[fusion][download][revision] = "6.x-1.x"

; COD feature modules.
projects[cod_support][subdir] = contrib 
projects[cod_support][download][type] = git
projects[cod_support][download][url] = "http://git.drupal.org/project/cod_support.git"
projects[cod_support][download][revision] = "6.x-1.x"

; Libraries
libraries[jquery_ui][download][type] = "get"
libraries[jquery_ui][destination] = "modules/contrib/jquery_ui"
libraries[jquery_ui][download][url] = "http://jquery-ui.googlecode.com/files/jquery.ui-1.6.zip"
libraries[jquery_ui][directory_name] = "jquery.ui"

