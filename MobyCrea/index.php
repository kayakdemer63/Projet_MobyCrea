<!DOCTYPE html>
<html lang="fr-FR">

  <?php include "variable.php";?>

  <head>
    <link rel="stylesheet" href="style.css" type="text/css">
    <meta charset="UTF-8"/>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <title>MobyCrea</title>
  </head>

  <body>
    <header>
      <h3 class="logo">Moby<span id="animate-charcter">Crea</span></h3>
    </header>

    <main>
      <div id="Courbes">
        <hr>
        <h2>Courbes</h2> 
        <hr>
      </div>
      
      <div>
        <iframe src="graphique.php"></iframe>
      </div>
    </main>

    <footer>
      <p>Copyright © 2023 MobyCrea</p>
    </footer>
  </body>
</html>
