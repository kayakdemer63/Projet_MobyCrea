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
      <div>
        <h2>Courbes</h2> 
        <hr>
      
        <?php
          // Connexion à la base de données
          error_reporting(0); // Enlève les erreurs du php (tableau)
          $con = mysqli_connect($host, $user, $password, $dbname);
          // Vérification de la connexion
          if(!$con){
              echo "Connexion ❌";
          }
          else { echo "Connexion ✅";}
        
          // Récupération des données de la table 
          $query = "SELECT id , valeur FROM test";
          $result = mysqli_query($con, $query);
        
          // Organisation des données pour Chart.js
          $data = array();
          $labels = array();
          while ($row = mysqli_fetch_assoc($result)) {
              array_push($data, $row['valeur']);
              array_push($labels, $row['id']);
          }
          $data = json_encode($data);
          $labels = json_encode($labels);
        ?> 

        </div>

      <canvas id="myChart"  width="60" height="20"></canvas>

      <script>
          var ctx = document.getElementById('myChart').getContext('2d');
          var data = <?php echo $data ?>;
          var labels = <?php echo $labels ?>;
          var myChart = new Chart(ctx, {
              type: 'line',
              data: {
                  labels: labels,
                  datasets: [{
                      label: 'Tension',
                      data: data,
                      borderWidth: 2
                  }]
              },
              options: {
                  scales: {
                      yAxes: [{
                          ticks: {
                              beginAtZero: true
                          }
                      }]
                  }
              }
          });
      </script>
    </main>

    <footer>
      <p>Copyright © 2023 MobyCrea</p>
    </footer>

  </body>
</html>
