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

    //connect(this, SIGNAL(BoolChange(ButeeBasse)), this, SLOT(checkButeeBasse2()));
    //connect(this, SIGNAL(BoolChange(ButeeGauche)), this, SLOT(checkButeeGauche2()));
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

void MainWindow::BoolChange(bool boolVar)
{

}

void MainWindow::checkButeeBasse()
{
    connect(this, SIGNAL(BoolChange(ButeeBasse)), this, SLOT(checkButeeBasse2()));

    if (ui->checkButeeBasse->isChecked() == false)
    {
    this->ButeeBasse = false;
    }
    else if (ui->checkButeeBasse->isChecked())
    {
    this->ButeeBasse = true;
    }
    //checkButeeBasse2();
}

void MainWindow::checkButeeBasse2()
{
    //ui->checkButeeBasse->setChecked();
    qDebug() << "check";
    int c = 0;
        while (ui->checkButeeBasse->isChecked() )
        {
            c++;
            if (mobycrea.getButeeBasse())
            {
                ui->checkButeeBasse2->setCheckState(Qt::Checked);
            }
            else
            {
                ui->checkButeeBasse2->setCheckState(Qt::Unchecked);
            }
            QThread::msleep(100);
        }
}

void MainWindow::checkButeeGauche()
{
    if (ui->checkButeeGauche->isChecked())
    {
        while (ui->checkButeeGauche->isChecked())
        {
            if (mobycrea.getButeeBasse())
            {
                ui->checkButeeGauche2->setCheckState(Qt::Checked);
            }
            else
            {
                ui->checkButeeGauche2->setCheckState(Qt::Unchecked);
            }
        }
    }
}

void MainWindow::checkButeeGauche2()
{
    if (ui->checkButeeGauche->isChecked())
    {
        while (ui->checkButeeGauche->isChecked())
        {
            if (mobycrea.getButeeBasse())
            {
                ui->checkButeeGauche2->setCheckState(Qt::Checked);
            }
            else
            {
                ui->checkButeeGauche2->setCheckState(Qt::Unchecked);
            }
        }
    }
}
