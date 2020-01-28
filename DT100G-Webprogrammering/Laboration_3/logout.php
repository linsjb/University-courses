<?php
session_start();
unset($_SESSION["logged_in"]);

header('Refresh: 0; URL = login.php');
?>
