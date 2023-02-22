/// @file bdd.h
/// @author Louan DESHAYES
/// @version 1.1
/// @class BDD

#ifndef BDD_H
#define BDD_H               /// @def BDD_H

#include <QtSql>            /// @include <QtSql


class BDD                   /// @brief Définition de la classe BDD.
{
public:
    BDD();
    /** @public @fn BDD()
     *  @brief Déclaration du Constructor.
     */

    void read();
    /** @public @fn read()
     *  @brief Déclaration de la fonction.
     */

private:
    QSqlDatabase bddMobycrea;
    /** @private @var QSqlDatabase bddMobycrea
     *  @brief Déclaration de l'Attribut.
     *  @code{.cpp}
     *

     *  @endcode
     */

    //QString table_test = "test";
};

#endif // BDD_H
