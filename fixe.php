<!DOCTYPE html>
<html lang="fr-FR">

  <head>
    <link rel="stylesheet" href="styleF.css" type="text/css">
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
          <li><a href="index.php">Courbes Temps Réel</a></li>
          <li><a class="active" href="fixe.php">Courbes figées</a></li>
        </ul>
      </nav>
      
      <div>
        <iframe src="graphiqueFixe.php"></iframe>
      </div>
    </main>

    <footer>
      <p>Copyright © 2023 MobyCrea</p>
    </footer>
  </body>
</html>