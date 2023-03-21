/// @file mainwindow.cpp
/// @author Louan DESHAYES
/// @version 1.1
/// @class MainWindow

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    portSearch();
    portChange();

    checkButeeBasse();
    checkButeeGauche();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::RequestButton()
{
    qDebug() << ui->Request->toPlainText();
    QString rep = bddMoby.executRequest(ui->Request->toPlainText());
    ui->sqlRep->insertPlainText(rep);
}

void MainWindow::ipChange()
{
    qDebug() << ui->adresseIP->toPlainText();
    bddMoby.newIP(ui->adresseIP->toPlainText());
}

void MainWindow::ConnectButton()
{
    mobycrea.testco();
    mobycrea.moteurs(5,255);
    mobycrea.moteurs(6,100);
    QThread::msleep(2000);
    mobycrea.moteurs(5,0);
    mobycrea.moteurs(6,0);
}

void MainWindow::portSearch()
{
    ui->boxPort->clear();
    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts())
    {
        ui->boxPort->addItem(port.portName());
    }
}

void MainWindow::portChange()
{
    mobycrea.port = ui->boxPort->currentText();
    qDebug() << mobycrea.port;
    mobycrea.portChanged();
}

void MainWindow::envoyerCommande()
{
    mobycrea.commande(ui->Commande->toPlainText());
}

void MainWindow::checkButeeBasse()
{
    if (mobycrea.getButeeBasse())
    {
        ui->checkButeeBasse->setCheckState(Qt::Checked);
    }
    else
    {
        ui->checkButeeBasse->setCheckState(Qt::Unchecked);
    }
    QThread::msleep(100);
}

void MainWindow::checkButeeGauche()
{
    if (mobycrea.getButeeBasse())
    {
        ui->checkButeeGauche->setCheckState(Qt::Checked);
    }
    else
    {
        ui->checkButeeGauche->setCheckState(Qt::Unchecked);
    }
}
