<!DOCTYPE html>
<html lang="fr-FR">

    <?php include "variable.php";?>

    <head>
        <link rel="stylesheet" href="style.css" type="text/css">
        <meta charset="UTF-8"/>
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
          $int_v = array();
          $int_h = array();
          $ten_v = array();
          $ten_h = array();
          $labels = array();
          while ($row = mysqli_fetch_assoc($result)) {

              array_push($int_v, $row['intensite_vertical']);
              array_push($int_h, $row['intensite_horizontal']);

              array_push($ten_v, $row['tension_vertical']);
              array_push($ten_h, $row['tension_horizontal']);

              array_push($labels, $row['id']);

          }
          $int_v = json_encode($int_v);
          $int_h = json_encode($int_h);
          $ten_v = json_encode($ten_v);
          $ten_h = json_encode($ten_h);
          $labels = json_encode($labels);
        ?> 
          <h4>Tensions figées des moteurs</h4>
    <canvas id="tension"></canvas>
          <hr style='border-color: deepskyblue;'>
          <h4>Intensités figées des moteurs</h4>
    <canvas id="intensite"></canvas>
    
    <script>
        var ctx1 = document.getElementById('tension').getContext('2d');

        var int_v = <?php echo $int_v ?>;
        var int_h = <?php echo $int_h ?>;

        var ten_v = <?php echo $ten_v ?>;
        var ten_h = <?php echo $ten_h ?>;

        var labels = <?php echo $labels ?>;

        var tension = new Chart(ctx1, {
            type: 'line',
            data: {
                labels: labels,
                datasets: [
                  {
                    label: 'Tension vertical',
                    data: ten_v,
                    borderWidth: 2
                  },
                  {
                    label: 'Tension horizontal',
                    data: ten_h,
                    borderWidth: 2
                  },
                ]
            },
            options: {
                scales: {
                    y: {
                        suggestedMin : 0
                    }
                },
                animation: {
                    duration: 0
                }
            }
            }
        );


        var ctx2 = document.getElementById('intensite').getContext('2d');

        var intensite = new Chart(ctx2, {
            type: 'line',
            data: {
                labels: labels,
                datasets: [
                  {
                    label: 'Intensité vertical',
                    data: int_v,
                    borderWidth: 2
                  },
                  {
                    label: 'Intensité horizontal',
                    data: int_h,
                    borderWidth: 2
                  },
                ]
            },
            options: {
                scales: {
                    y: {
                        suggestedMin : 0
                    }
                },
                animation: {
                    duration: 0
                }
            }
            }
        );

    </script>

    </body>
</html>