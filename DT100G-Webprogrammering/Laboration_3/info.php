<?php include 'head.php' ?>
<div class="content">
  <ol>
    <li>
        Dagens tid och datum

        <ul>
          <li>
            <?php todaysDate(); ?>
          </li>
        </ul>
    </li>

    <li>
      Ip-adressen

      <ul>
        <li>
          <?php ipAdress(); ?>
        </li>
      </ul>
    </li>

    <li>
      Sökväg

      <ul>
        <li>
          <?php filePath(); ?>
        </li>
      </ul>
    </li>
    <li>
      Webagent

      <ul>
        <li>
          <?php agent(); ?>
        </li>
      </ul>
    </li>
  </ol>
</div>
<?php include 'footer.php' ?>
