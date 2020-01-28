<?php
include "header.php";
$loginUsername = "admin";
$loginPassword = "root";
$faultMessage = "";


if(isset($_POST['loginButton'])) {
  // Stämmer användarnamn och lösenord?
  // I så fall startar vi en sessions och skickar oss vidare till index.php
  if(strtolower($_POST["usernameField"]) == $loginUsername && $_POST["passwordField"] == $loginPassword) {
    session_start();
    $_SESSION['logged_in'] = TRUE;
    header("Location: index.php");
  }
    // Däremot om uppgifterna inte stämmer så visar vi ett felmeddelande.
    else {
      //Variabeln används för att skriva ut ett felmeddelande i inloggningsrutan ifall inloggning misslyckas
      $faultMessage = "Anvädarnamn eller lösenord stämmer inte.";
    }
}
?>

<div class="login">
  <h2>Logga in</h2>

  <form method="post" action="login.php">
		<input class="textfield" type="text" name="usernameField" placeholder="Användarnamn: admin" autofocus>
		<input class="textfield" type="password" name="passwordField" placeholder="Lösenord: root">

		<button name="loginButton">Logga in</button>
	</form>

  <h4><?php echo $faultMessage; ?></h4>
</div>

<?php
include "footer.php";
?>
