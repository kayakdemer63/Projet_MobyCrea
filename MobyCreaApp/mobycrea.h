/// @file mobycrea.h
/// @author Louan DESHAYES
/// @version 1.1
/// @class MobyCrea

#ifndef MOBYCREA_H
#define MOBYCREA_H              /// @def MOBYCREA_H

#include <QSerialPort>          /// @include <QSerialPort
#include <QSerialPortInfo>      /// @include <QSerialPortInfo
#include <QDebug>               /// @include <QDebug
#include <QThread>              /// @include <QThread

class MobyCrea
{
public:
    MobyCrea();
    /** @public @fn Butees()
     *  @brief Déclaration du Constructor.
     */

    QSerialPort serial;
    /** @private @var  QSerialPort serial
     *  @brief Déclaration de l'Attribut.
     */

    void testco();
    /** @public @fn testco()
     *  @brief Déclaration de la fonction.
     */

};

#endif // MOBYCREA_H
