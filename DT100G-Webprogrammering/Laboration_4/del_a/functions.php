<?php
include "dist/php/classes/blog.class.php";

$posts = new Blog();

// När vi klickar på "Posta inlägg" så skickar vi iväg en request till servern med vår data
if(isset($_REQUEST['insertPostBtn'])) {

  // Skapa en array med fältdata och datum för inläget.
  $arr = array(
    $_REQUEST['nameInput'],
    date('Y-m-d H:i:s'),
    $_REQUEST['contentInput']
  );

  // Lägg in datan i datafilen.
  $posts->insert($arr);

  // Ladda om index.php för att se ändringarna.
  header('location: index.php');
  exit();
}

// När vi klickar på knappen 'Rader inlägg'
if(isset($_REQUEST['delPost'])) {
  // Ta bort inlägget från datafilen
  $posts->delete($_REQUEST['delPost']);

  // Ladda om index.php för att se ändringarna
  header('location: index.php');
  exit();
}
?>
