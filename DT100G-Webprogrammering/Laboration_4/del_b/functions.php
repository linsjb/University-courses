<?php
include "dist/php/classes/blog.class.php";
include "dist/php/classes/connection.class.php";

$dbConn = new Connection();
$blog = new Blog($dbConn);


if(isset($_POST['insertPostBtn'])) {
  $arr = array(
    $_POST['nameInput'],
    date('Y-m-d H:i:s'),
    $_POST['contentInput']
  );
  $blog->insert($arr);

  // Ladda om index.php för att se ändringarna
  header('location: index.php');
  exit();
}

if(isset($_POST['delPost'])) {
  // Ta bort inlägget från databasen
  $blog->delete($_GET['delPost']);

  // Ladda om index.php för att se ändringarna
  header('location: index.php');
  exit();
}
?>
