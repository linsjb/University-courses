<?php
class Blog {

  function __construct($setDbConn) {

    // Sätter den ansluta databasen till en privat variabel specifikt för klassen
    $this->dbConnection = $setDbConn;
  }

  // Laddar in data och presenterar denna
  function load() {
    // Hämtar valt data från databasen.
    $data = $this->dbConnection->select('SELECT * FROM guestbookPosts');

    // Loopar igenom $data och presenterar dess data hos klienten.
    for ($i=0; $i <sizeof($data) ; $i++) {
      echo '<div class="post">';
        echo '<h1>' . $data[$i]->username . '</h1>';
        echo '<p>Datum: ' . $data[$i]->postDate . '</p>';
        echo '<p class="postContent">' . $data[$i]->postContent. '</p>';

        echo '<form method="POST" action="index.php?delPost=' . $data[$i]->id . '"/>';
          echo '<input type="submit" value="Radera inlägg" name="delPost"/>';
        echo '</form>';

      echo '</div>';
    }
  }

  // Skapa nytt inlägg
  function insert($insertData) {
    $this->dbConnection->update(
      "INSERT INTO guestbookPosts (username, postDate, postContent) VALUES ('$insertData[0]', '$insertData[1]', '$insertData[2]')"
    );
  }

  // Radera berört inlägg
  function delete($id) {
    $this->dbConnection->update(
      "DELETE FROM guestbookPosts WHERE id='$id'"
    );
  }

  private $dbConnection;
}
?>
