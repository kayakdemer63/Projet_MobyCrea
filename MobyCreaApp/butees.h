/// @file butees.h
/// @author Louan DESHAYES
/// @version 1.1
/// @class Butees

#ifndef BUTEES_H
#define BUTEES_H                /// @def BUTEES_H

#include "mobycrea.h"           /// @include "mobycrea.h"

class Butees : public MobyCrea
{
public:
    Butees();
    /** @public @fn Butees()
     *  @brief Déclaration du Constructor.
     */

    void getButeeBasse();
    /** @public @fn getButeeBasse()
     *  @brief Déclaration de la fonction.
     */

    void getButeeGauche();
    /** @public @fn getButeeGauche()
     *  @brief Déclaration de la fonction.
     */

};

#endif // BUTEES_H
