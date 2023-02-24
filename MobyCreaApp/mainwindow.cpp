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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::RequestButton()
{
    qDebug() << ui->Request->toPlainText();
    bddMoby.executRequest(ui->Request->toPlainText());
}

void MainWindow::ipChange()
{
    qDebug() << ui->adresseIP->toPlainText();
    bddMoby.newIP(ui->adresseIP->toPlainText());
}

void MainWindow::ConnectButton()
{
    mobycrea.testco();
}
