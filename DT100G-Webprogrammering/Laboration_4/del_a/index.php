<?php include 'header.php' ?>
  <div class="content">
    <div class="posts">
      <?php
      // Vi skapar objektet i filen functions.php
      // vi kallar på load-metoden här för att vi ska få ut inläggen på rätt ställe.
      $posts->load();
      ?>
    </div>

    <div class="newPost">
      <h4>Skapa inlägg</h4>
      <form class="" action="index.php" method="post">
       <input type="text" name="nameInput" placeholder="Namn">
       <textarea name="contentInput" rows="8" cols="80"></textarea>
       <input type="submit" name="insertPostBtn" value="Posta inlägg">
      </form>

    </div>
  </div>
<?php include 'footer.php' ?>
