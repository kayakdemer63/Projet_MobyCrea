/// @file bdd.cpp
/// @author Louan DESHAYES
/// @version 1.1
/// @class BDD

#include "bdd.h"

BDD::BDD()
{
    bddMobycrea = QSqlDatabase::addDatabase("QMYSQL");

    // Définition des paramètres de connexion à la base de données
    bddMobycrea.setHostName("172.21.28.26"); // @ip serveur MySQL
    bddMobycrea.setUserName("mobycrea"); // Nom utilisateur
    bddMobycrea.setPassword("lafayette"); // Mot de passe
    bddMobycrea.setDatabaseName("mobycrea"); // Nom de la base
}

void BDD::read()
{
    if(bddMobycrea.open()) {
        qDebug() << "Ok - ouverture de la base de donnée";

        // Exécution d'une requête
        QSqlQuery requete;
        if(requete.exec("SELECT * FROM test")) {
            qDebug() << "Ok - requete";

            // Boucle qui permet de parcourir les enregistrements renvoyés par la requête
            while(requete.next()) {
                // On accède ici aux différents champs par leurs noms, il est également possible
                // d'y accéder par leur index : requete.value(0)
                qDebug() << requete.value("id") << " ; " << requete.value("valeur");
            }
        }
        else {
            qDebug() << "Echec de la requête";
            // La méthode lastError permet d'afficher un message
            // plus explicite sur les causes de l'erreur
            qDebug() << requete.lastError();
        }
        bddMobycrea.close(); // Fermeture de la base de données
    }
    else {
        qDebug() << "Echec d'ouverture de la base de donnée";
        qDebug() << bddMobycrea.lastError();
    }
}
