/// @file mainwindow.h
/// @author Louan DESHAYES
/// @version 1.1
/// @class MainWindow

#ifndef MAINWINDOW_H
#define MAINWINDOW_H                        /// @def MAINWINDOW_H

#include <QMainWindow>                      /// @include <QMainWindow
#include <QAbstractButton>
#include "bdd.h"                            /// @include "bdd.h"
#include "mobycrea.h"                       /// @include "mobycrea.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }          /// @namespace ui
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    /** @public @fn MainWindow(QWidget *parent = nullptr)
     *  @brief Déclaration du Constructor.
     */

    ~MainWindow();
    /** @public @fn ~MainWindow()
     *  @brief Déclaration du Destructor.
     */

private:
    Ui::MainWindow *ui;
    /** @private @var Ui::MainWindow *ui
     *  @brief Déclaration de l'Attribut.
     */

    BDD bddMoby;
    /** @private @var  BDD bddMoby
     *  @brief Déclaration de l'Attribut.
     */

    MobyCrea mobycrea;
    /** @private @var MobyCrea mobycrea
     *  @brief Déclaration de l'Attribut.
     */

private slots:
    void RequestButton();
    /** @private @fn RequestButton()
     *  @brief Déclaration de la Méthode.
     */

    void ipChange();
    /** @private @fn ipChange()
     *  @brief Déclaration de la Méthode.
     */

    void ConnectButton();
    /** @private @fn ConnectButton()
     *  @brief Déclaration de la Méthode.
     */

    void portChange();
    /** @private @fn portChange()
     *  @brief Déclaration de la Méthode.
     */

    void portSearch();
    /** @private @fn portChange()
     *  @brief Déclaration de la Méthode.
     */

    void envoyerCommande();
    /** @private @fn envoyerCommande()
     *  @brief Déclaration de la Méthode.
     */

public slots:
    void checkButeeBasse();
    /** @private @fn checkButeeBasse()
     *  @brief Déclaration de la Méthode.
     */

    void checkButeeGauche();
    /** @private @fn checkButeeGauche()
     *  @brief Déclaration de la Méthode.
     */

};
#endif // MAINWINDOW_H
