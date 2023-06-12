<!DOCTYPE html>
<html lang="fr-FR">

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
      <nav>
        <ul>
          <li><a class="active" href="index.php">Courbes TempsRéel</a></li>
          <li><a href="fixe.php">Courbes figées</a></li>
        </ul>
      </nav>
      
      <div>
        <iframe src="graphique.php"></iframe>
      </div>
    </main>

    <footer>
      <p>Copyright © 2023 MobyCrea</p>
    </footer>
  </body>
</html>
