/// @file bdd.h
/// @author Louan DESHAYES
/// @version 1.1
/// @class BDD

#ifndef BDD_H
#define BDD_H               /// @def BDD_H

#include <QtSql>            /// @include <QtSql
#include <QtCharts>


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

    QLineSeries* graphIntVert();
    /** @public @fn graphIntVert()
     *  @brief Déclaration de la fonction.
     */

    QLineSeries* graphTensVert();
    /** @public @fn graphTensVert()
     *  @brief Déclaration de la fonction.
     */

    QLineSeries* graphIntHori();
    /** @public @fn graphIntHori()
     *  @brief Déclaration de la fonction.
     */

    QLineSeries* graphTensHori();
    /** @public @fn graphTensHori()
     *  @brief Déclaration de la fonction.
     */

    int id();
    /** @public @fn id()
     *  @brief Déclaration de la fonction.
     */

private:
    QSqlDatabase bddMobycrea;
    /** @private @var QSqlDatabase bddMobycrea
     *  @brief Déclaration de l'Attribut.
     */

};

#endif // BDD_H
