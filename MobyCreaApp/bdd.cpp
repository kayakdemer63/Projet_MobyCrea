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
                    QString rep;
                    while(requete.next()) {
                        qDebug() << requete.value("id") << " ; " << requete.value("valeur");
                        rep.append("id : " + requete.value("id").toString() + " ; valeur : " + requete.value("valeur").toString() + "\n");
                    }
                    return rep;
                }
                else
                {
                    qDebug() << "Echec de la requête";
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
                    QString rep;
                    while(requete.next()) {
                        qDebug() << requete.value("id") << " ; " << requete.value("date") << " ; " << requete.value("intensite_horizontale") << " ; " << requete.value("intensite_verticale") << " ; " << requete.value("tension_horizontale") << " ; " << requete.value("tension_vertical");
                        rep.append("id : " + requete.value("id").toString() + " ; date : " + requete.value("date").toString() + " ; intensite_horizontale : " + requete.value("intensite_horizontale").toString() + " ; intensite_verticale : " + requete.value("intensite_verticale").toString() + " ; tension_horizontale : " + requete.value("tension_horizontale").toString() + " ; tension_vertical : " + requete.value("tension_vertical").toString() + "\n");
                    }
                    return rep;
                }
                else {
                    qDebug() << "Echec de la requête";
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

QLineSeries* BDD::graphIntVert()
{
    QString requestGraph = "SELECT * FROM data_moteurs";
    if(bddMobycrea.open())
    {
        qDebug() << "Ok - ouverture de la base de donnée";
        QSqlQuery requeteGraph;
        if(requeteGraph.exec(requestGraph))
        {
            qDebug() << "Ok - requete";
            QLineSeries *rep = new QLineSeries;
            while(requeteGraph.next())
            {
                qDebug() << requeteGraph.value("id") << " ; " << requeteGraph.value("intensite_verticale");
                rep->append(requeteGraph.value("id").toReal(), requeteGraph.value("intensite_verticale").toReal());
            }
            return rep;
        }
        bddMobycrea.close(); // Fermeture de la base de données
    }
    else
    {
        qDebug() << "Echec d'ouverture de la base de donnée";
        qDebug() << bddMobycrea.lastError();
    }
}

QLineSeries* BDD::graphTensVert()
{
    QString requestGraph = "SELECT * FROM data_moteurs";
    if(bddMobycrea.open())
    {
        qDebug() << "Ok - ouverture de la base de donnée";
        QSqlQuery requeteGraph;
        if(requeteGraph.exec(requestGraph))
        {
            qDebug() << "Ok - requete";
            QLineSeries *rep = new QLineSeries;
            while(requeteGraph.next())
            {
                qDebug() << requeteGraph.value("id") << " ; " << requeteGraph.value("tension_vertical");
                rep->append(requeteGraph.value("id").toReal(), requeteGraph.value("tension_vertical").toReal());
            }
            return rep;
        }
        bddMobycrea.close(); // Fermeture de la base de données
    }
    else
    {
        qDebug() << "Echec d'ouverture de la base de donnée";
        qDebug() << bddMobycrea.lastError();
    }
}

QLineSeries* BDD::graphIntHori()
{
    QString requestGraph = "SELECT * FROM data_moteurs";
    if(bddMobycrea.open())
    {
        qDebug() << "Ok - ouverture de la base de donnée";
        QSqlQuery requeteGraph;
        if(requeteGraph.exec(requestGraph))
        {
            qDebug() << "Ok - requete";
            QLineSeries *rep = new QLineSeries;
            while(requeteGraph.next())
            {
                qDebug() << requeteGraph.value("id") << " ; " << requeteGraph.value("intensite_horizontale");
                rep->append(requeteGraph.value("id").toReal(), requeteGraph.value("intensite_horizontale").toReal());
            }
            return rep;
        }
        bddMobycrea.close(); // Fermeture de la base de données
    }
    else
    {
        qDebug() << "Echec d'ouverture de la base de donnée";
        qDebug() << bddMobycrea.lastError();
    }
}

QLineSeries* BDD::graphTensHori()
{
    QString requestGraph = "SELECT * FROM data_moteurs";
    if(bddMobycrea.open())
    {
        qDebug() << "Ok - ouverture de la base de donnée";
        QSqlQuery requeteGraph;
        if(requeteGraph.exec(requestGraph))
        {
            qDebug() << "Ok - requete";
            QLineSeries *rep = new QLineSeries;
            while(requeteGraph.next())
            {
                qDebug() << requeteGraph.value("id") << " ; " << requeteGraph.value("tension_horizontale");
                rep->append(requeteGraph.value("id").toReal(), requeteGraph.value("tension_horizontale").toReal());
            }
            return rep;
        }
        bddMobycrea.close(); // Fermeture de la base de données
    }
    else
    {
        qDebug() << "Echec d'ouverture de la base de donnée";
        qDebug() << bddMobycrea.lastError();
    }
}

int BDD::id()
{
    QString request = "SELECT MAX(id) FROM data_moteurs";
    if(bddMobycrea.open())
    {
        qDebug() << "Ok - ouverture de la base de donnée";
        QSqlQuery requete;
        if(requete.exec(request))
        {
            qDebug() << "Ok - requete";
            int rep;
            while(requete.next())
            {
                qDebug() << requete.value("MAX(id)");
                rep = requete.value("MAX(id)").toInt();
            }
            return rep;
        }
        bddMobycrea.close(); // Fermeture de la base de données
    }
    else
    {
        qDebug() << "Echec d'ouverture de la base de donnée";
        qDebug() << bddMobycrea.lastError();
    }
}
