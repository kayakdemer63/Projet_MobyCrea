/// @file bdd.h
/// @author Louan DESHAYES
/// @version 1.1
/// @class BDD

#ifndef BDD_H
#define BDD_H               /// @def BDD_H

#include <QtSql>            /// @include <QtSql


class BDD
{
public:
    BDD();
    /** @public @fn BDD()
     *  @brief Déclaration du Constructor.
     */

    QString executRequest(QString);
    /** @public @fn executRequest(QString)
     *  @brief Déclaration de la fonction.
     */

    void newIP(QString);
    /** @public @fn newIP(QString)
     *  @brief Déclaration de la fonction.
     */
    void addData(double tensVert, double intVert, double tensHori, double intHori);

private:
    QSqlDatabase bddMobycrea;
    /** @private @var QSqlDatabase bddMobycrea
     *  @brief Déclaration de l'Attribut.
     */
    QDateTime dateTime;

};

#endif // BDD_H
