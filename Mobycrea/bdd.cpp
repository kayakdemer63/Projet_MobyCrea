#include "bdd.h"
/// @file bdd.cpp
/// @author Louan DESHAYES
/// @version 1.1
/// @class BDD


BDD::BDD()
{
    bddMobycrea = QSqlDatabase::addDatabase("QMYSQL");

    // Définition des paramètres de connexion à la base de données
    bddMobycrea.setHostName("172.21.28.26"); // @ip serveur MySQL
    bddMobycrea.setUserName("mobycrea"); // Nom utilisateur
    bddMobycrea.setPassword("lafayette"); // Mot de passe
    bddMobycrea.setDatabaseName("mobycrea"); // Nom de la base
}

QString BDD::executRequest(QString request)
{
    if(bddMobycrea.open())
    {
        qDebug() << "Ok - ouverture de la base de donnée";
        QSqlQuery requete;
        if(request.right(4) == "test") //table test
        {
            if(request.left(6) == "SELECT" || request.left(6) == "select" || request.left(6) == "Select")
            {
                if(requete.exec(request))
                {
                    qDebug() << "Ok - requete";
                    // Boucle qui permet de parcourir les enregistrements renvoyés par la requête
                    QString rep;
                    while(requete.next()) {
                        // On accède ici aux différents champs par leurs noms, il est également possible
                        // d'y accéder par leur index : requete.value(0)
                        qDebug() << requete.value("id") << " ; " << requete.value("valeur");
                        rep.append("id : " + requete.value("id").toString() + " ; valeur : " + requete.value("valeur").toString() + "\n");
                    }
                    return rep;
                }
                else
                {
                    qDebug() << "Echec de la requête";
                    // La méthode lastError permet d'afficher un message
                    // plus explicite sur les causes de l'erreur
                    qDebug() << requete.lastError();
                    return "Cet attribut n'existe pas.\n";
                }
            }
            else
            {
                return "Cette requête n'est pas executable.\n";
            }
        }
        else if(request.right(12) == "data_moteurs") //table data_moteurs
        {
            if(requete.exec(request))
            {
                if(request.left(6) == "SELECT" || request.left(6) == "select" || request.left(6) == "Select")
                {
                    qDebug() << "Ok - requete";
                    // Boucle qui permet de parcourir les enregistrements renvoyés par la requête
                    QString rep;
                    while(requete.next()) {
                        // On accède ici aux différents champs par leurs noms, il est également possible
                        // d'y accéder par leur index : requete.value(0)
                        qDebug() << requete.value("id") << " ; " << requete.value("date") << " ; " << requete.value("intensite_horizontale") << " ; " << requete.value("intensite_verticale") << " ; " << requete.value("tension_horizontale") << " ; " << requete.value("tension_vertical");
                        rep.append("id : " + requete.value("id").toString() + " ; date : " + requete.value("date").toString() + " ; intensite_horizontale : " + requete.value("intensite_horizontale").toString() + " ; intensite_verticale : " + requete.value("intensite_verticale").toString() + " ; tension_horizontale : " + requete.value("tension_horizontale").toString() + " ; tension_vertical : " + requete.value("tension_vertical").toString() + "\n");
                    }
                    return rep;
                }
                else {
                    qDebug() << "Echec de la requête";
                    // La méthode lastError permet d'afficher un message
                    // plus explicite sur les causes de l'erreur
                    qDebug() << requete.lastError();
                    return "Cet attribut n'existe pas.\n";
                }
            }
            else
            {
                return "Cette requête n'est pas executable.\n";
            }
        }
        else
        {
            return "Cette table n'existe pas.\n";
        }

        bddMobycrea.close(); // Fermeture de la base de données
    }
    else {
        qDebug() << "Echec d'ouverture de la base de donnée";
        qDebug() << bddMobycrea.lastError();
    }
}

void BDD::newIP(QString ip)
{
    bddMobycrea.setHostName(ip); // @ip serveur MySQL
}

void BDD::addData(double tensVert, double intVert, double tensHori, double intHori)
{
    QString date = dateTime.currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString request = "INSERT INTO data_moteurs(tension_vertical, intensite_verticale, tension_horizontale, intensite_horizontale, date_heure) VALUES (" + QString::number(tensVert) + "," + QString::number(intVert) + "," + QString::number(tensHori) + "," + QString::number(intHori) + ",'" + date + "')";
    if(bddMobycrea.open())
    {
        qDebug() << "Ok - ouverture de la base de donnée";
        QSqlQuery requete;
        if(requete.exec(request))
        {
            qDebug() << "Ok - requete";
            while(requete.next()) {
                qDebug() << requete.value("id") << " ; " << requete.value("date_heure") << " ; " << requete.value("intensite_horizontale") << " ; " << requete.value("intensite_verticale") << " ; " << requete.value("tension_horizontale") << " ; " << requete.value("tension_vertical");
            }
            return;
        }
        bddMobycrea.close(); // Fermeture de la base de données
    }
    else
    {
        qDebug() << "Echec d'ouverture de la base de donnée";
        qDebug() << bddMobycrea.lastError();
    }
}
