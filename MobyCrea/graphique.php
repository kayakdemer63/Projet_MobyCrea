<!DOCTYPE html>
<html lang="fr-FR">

    <?php include "variable.php";?>

    <head>
        <link rel="stylesheet" href="style.css" type="text/css">
        <meta charset="UTF-8"/>
        <meta http-equiv="refresh" content="1">
        <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    </head>

    <body>

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
          $query = "SELECT * FROM data_moteurs";
          $result = mysqli_query($con, $query);
        
          // Organisation des données pour Chart.js
          $data1 = array();
          $data2 = array();
          $data3 = array();
          $data4 = array();
          $labels = array();
          while ($row = mysqli_fetch_assoc($result)) {

              array_push($data1, $row['intensite_vertical']);
              array_push($data3, $row['intensite_horizontal']);

              array_push($data2, $row['tension_vertical']);
              array_push($data4, $row['tension_horizontal']);

              array_push($labels, $row['id']);

          }
          $data1 = json_encode($data1);
          $data2 = json_encode($data2);
          $data3 = json_encode($data3);
          $data4 = json_encode($data4);
          $labels = json_encode($labels);
        ?> 
          <h4>Tension</h4>
    <canvas id="tension"></canvas>
          <h4>Intensité</h4>
    <canvas id="intensite"></canvas>
    
    <script>
        var ctx = document.getElementById('tension').getContext('2d');
        var data1 = <?php echo $data1 ?>;
        var data2 = <?php echo $data2 ?>;
        var data3 
        = <?php echo $data3 ?>;
        var data4 = <?php echo $data4 ?>;
        var labels = <?php echo $labels ?>;
        var tension = new Chart(ctx, {
            type: 'line',
            data: {
                labels: labels,
                datasets: [
                  {
                    label: 'Tension vertical',
                    data: data2,
                    borderWidth: 2
                  },
                  {
                    label: 'Tension horizontal',
                    data: data4,
                    borderWidth: 2
                  },
                ]
            },
            options: {
                scales: {
                    yAxes: [{
                        ticks: {
                            beginAtZero: true
                        }
                    }]
                },
                animation: {
                    duration: 0
                }
            }
            }
        );


        var ctx = document.getElementById('intensite').getContext('2d');

        var intensite = new Chart(ctx, {
            type: 'line',
            data: {
                labels: labels,
                datasets: [
                  {
                    label: 'Intensité vertical',
                    data: data1,
                    borderWidth: 2
                  },
                  {
                    label: 'Intensité horizontal',
                    data: data3,
                    borderWidth: 2
                  },
                ]
            },
            options: {
                scales: {
                    yAxes: [{
                        ticks: {
                            beginAtZero: true
                        }
                    }]
                },
                animation: {
                    duration: 0
                }
            }
            }
        );

        
    </script>

    </body>