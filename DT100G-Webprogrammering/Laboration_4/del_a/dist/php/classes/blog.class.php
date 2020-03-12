<?php
class Blog {

  // Laddar in all data från data-filen och printar ut detta till klienten.
  function load() {
    $counter = 0;

    // Går igenom filen rad för rad och skapar ett element för varje rad.
    foreach(file('data.txt') as $fileRow) {
      $splittedRow = explode('|', $fileRow);
      echo '<div class="post">';
        echo '<h1>' . $splittedRow[0] . '</h1>';
        echo '<p>Datum: ' . $splittedRow[1] . '</p>';
        echo '<p class="postContent">' . $splittedRow[2] . '</p>';
        echo '<a href="index.php?delPost=' . $counter . '">Radera inlägg</a>';
      echo '</div>';

      $counter++;
    }
  }

  // Skapa nytt inlägg
  function insert($insertData) {
    // Öppna datafilen
    $file = fopen($this->fileName, 'a');

    // Variabler
    $devider = '|';

    // Strängen som ska sättas in i filen
    $string = $insertData[0] . $devider . $insertData[1] . $devider . $insertData[2] . "\n";

    // Skriver till filen
    fwrite($file, $string);

    // Stänger filen
    fclose($file);
  }

  // Radera berört inlägg
  function delete($id) {
    $fileContent = array();

    // Öppna datafilen
    $file = fopen($this->fileName, 'a');

    // Hämta alla rader från filen och lägg in dom i en array.
    foreach(file($this->fileName) as $fileRow) {
      array_push($fileContent, $fileRow);
    }

    // Ta bort den berörda raden från arrayen.
    unset($fileContent[$id]);

    // Töm filen så att vi kan lägga in den modifierade arrayen.
    file_put_contents($this->fileName, '');

    // Skriv in datan från arrayen till filen
    foreach($fileContent as $row) {
      fwrite($file, $row);
    }

    // Stäng filen
    fclose($file);
  }

  private $fileName = 'data.txt';
}
?>
