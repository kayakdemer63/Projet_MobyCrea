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

    ~MobyCrea();
    /** @public @fn ~MainWindow()
     *  @brief Déclaration du Destructor.
     */

    QSerialPort serial;
    /** @public @var  QSerialPort serial
     *  @brief Déclaration de l'Attribut.
     */

    void testco();
    /** @public @fn testco()
     *  @brief Déclaration de la fonction.
     */

    void moteurs(int, int);
    /** @public @fn moteurs(int, int)
     *  @brief Déclaration de la fonction.
     */

    QString port;
    /** @public @var  QString port
     *  @brief Déclaration de l'Attribut.
     */

    void portChanged();
    /** @public @fn portChange()
     *  @brief Déclaration de la fonction.
     */

    void commande(QString);
    /** @public @fn commande(Qstring)
     *  @brief Déclaration de la fonction.
     */

};

#endif // MOBYCREA_H
