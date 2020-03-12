<?php
include "header.php";
session_start();

if(!isset($_SESSION['logged_in']) OR $_SESSION['logged_in'] != TRUE) {
	header("Location: login.php");
}
?>
<header>
  <h3>Laboration 3 - Linus Sjöbro</h3>

  <nav>
    <ul>
      <li><a href="index.php">Frågor</a></li>
      <li><a href="info.php">Info</a></li>
      <li><a href="logout.php">Logga ut</a></li>
    </ul>
  </nav>
</header>
