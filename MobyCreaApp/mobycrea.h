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
#include <QObject>              /// @include <QObject

class MobyCrea : public QObject
{
public:
    MobyCrea();
    /** @public @fn MobyCrea()
     *  @brief Déclaration du Constructor.
     */

    ~MobyCrea();
    /** @public @fn ~MobyCrea()
     *  @brief Déclaration du Destructor.
     */

    QSerialPort serial;
    /** @public @var QSerialPort serial
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
    /** @public @var QString port
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

    bool getButeeBasse();
    /** @public @fn getButeeBasse()
     *  @brief Déclaration de la fonction.
     */

    bool getButeeGauche();
    /** @public @fn getButeeGauche()
     *  @brief Déclaration de la fonction.
     */

    void Conf_8();
    /** @public @fn Conf_8()
     *  @brief Déclaration de la fonction.
     */

    void Conf_O();
    /** @public @fn Conf_O()
     *  @brief Déclaration de la fonction.
     */

    void Conf_U();
    /** @public @fn Conf_U()
     *  @brief Déclaration de la fonction.
     */

    void Conf_n();
    /** @public @fn Conf_n()
     *  @brief Déclaration de la fonction.
     */

};

#endif // MOBYCREA_H
