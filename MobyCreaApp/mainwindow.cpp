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

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(checkButeeBasse()));
    connect(timer, SIGNAL(timeout()), this, SLOT(checkButeeGauche()));
    timer->start((1/100)*1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::RequestButton()
{
    //qDebug() << ui->Request->toPlainText();
    QString rep = bddMoby.executRequest(ui->Request->toPlainText());
    ui->sqlRep->insertPlainText(rep);
}

void MainWindow::ipChange()
{
    //qDebug() << ui->adresseIP->toPlainText();
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
    //qDebug() << mobycrea.port;
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
    QThread::msleep(5);
}

void MainWindow::checkButeeGauche()
{
    if (mobycrea.getButeeGauche())
    {
        ui->checkButeeGauche->setCheckState(Qt::Checked);
    }
    else
    {
        ui->checkButeeGauche->setCheckState(Qt::Unchecked);
    }
    QThread::msleep(5);
}

void MainWindow::ButtonConf_8()
{

}

void MainWindow::ButtonConf_O()
{

}

void MainWindow::ButtonConf_U()
{

}

void MainWindow::ButtonConf_n()
{

}
