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
    QDesktopServices::openUrl(QUrl(QDir::currentPath()+"/UwAmp/UwAmp.exe"));
    QThread::sleep(5);
    ui->setupUi(this);
    portSearch();
    portChange();
    refreshGraph();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(checkButeeBasse()));
    connect(timer, SIGNAL(timeout()), this, SLOT(checkButeeGauche()));
    timer->start(100);
}

MainWindow::~MainWindow()
{
    //bddMoby.supprData("*");
    QProcess::execute("taskkill /im UwAmp.exe /f");
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
    QTimer::singleShot(2000, this, [this](){
        mobycrea.moteurs(5,0);
        mobycrea.moteurs(6,0);
    });
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
    //if (mobycrea.getButeeBasse())
    if (mobycrea.getCapteurHauteur())
    {
        ui->checkButeeBasse->setCheckState(Qt::Checked);
    }
    else
    {
        ui->checkButeeBasse->setCheckState(Qt::Unchecked);
    }
    QTimer::singleShot(5, this, [this](){});
}

void MainWindow::checkButeeGauche()
{
    //if (mobycrea.getButeeGauche())
    if (mobycrea.getCapteurLargeur())
    {
        ui->checkButeeGauche->setCheckState(Qt::Checked);
    }
    else
    {
        ui->checkButeeGauche->setCheckState(Qt::Unchecked);
    }
    QTimer::singleShot(5, this, [this](){});
}

void MainWindow::ButtonConf_8()
{
    Origine();
    mobycrea.moteurs(6, 225);
    QTimer::singleShot(150, this, [this](){
        mobycrea.moteurs(6, 0);
        mobycrea.Conf_8();
    });

}

void MainWindow::ButtonConf_O()
{
    Origine();
    mobycrea.moteurs(6, 225);
    QTimer::singleShot(150, this, [this](){
        mobycrea.moteurs(6, 0);
        mobycrea.Conf_O();
    });
}

void MainWindow::ButtonConf_U()
{
    Origine();
    mobycrea.moteurs(6, 225);
    QTimer::singleShot(500, this, [this](){
        mobycrea.moteurs(6, 0);
        mobycrea.Conf_U();
    });
}

void MainWindow::ButtonConf_n()
{
    Origine();
    mobycrea.Conf_n();
}

void MainWindow::Origine()
{
    /*mobycrea.moteurs(5, 255);
    mobycrea.moteurs(6, 225);
    while (mobycrea.getButeeBasse()==false || mobycrea.getButeeGauche()==false)
    {
        if (mobycrea.getButeeBasse())
        {
            mobycrea.moteurs(6, 0);
        }
        if (mobycrea.getButeeGauche())
        {
            mobycrea.moteurs(5, 0);
        }
        checkButeeBasse();
        checkButeeGauche();
    }*/

    mobycrea.moteurs(5, 255);
    mobycrea.moteurs(6, 225);
    while (mobycrea.getCapteurHauteur()==false || mobycrea.getCapteurLargeur()==false)
    {
        if (mobycrea.getCapteurHauteur())
        {
            mobycrea.moteurs(6, 0);
        }
        if (mobycrea.getCapteurLargeur())
        {
            mobycrea.moteurs(5, 0);
        }
        checkButeeBasse();
        checkButeeGauche();
    }
}

void MainWindow::refreshGraph()
{
    QMargins* margins = new QMargins(5,5,5,5);
    QFont font;
    font.setPixelSize(14);
    font.setBold(true);

    QXYSeries *series = bddMoby.graphTensHori();
    QXYSeries *series2 = bddMoby.graphTensVert();
    QChart *chart = new QChart();
    series->setName("Moteur Horizontale");
    series2->setName("Moteur Verticale");
    chart->setMargins(*margins);
    chart->legend()->setAlignment(Qt::AlignTop);
    chart->addSeries(series);
    chart->addSeries(series2);
    QDateTimeAxis *axisTensX = new QDateTimeAxis;
    axisTensX->setTickCount(8);
    axisTensX->setFormat("dd-MM-yyyy_hh:mm::ss");
    axisTensX->setTitleText("Date et heure");
    chart->addAxis(axisTensX, Qt::AlignBottom);
    QValueAxis *axisTensY = new QValueAxis;
    axisTensY->setTitleText("Tension (V)");
    axisTensY->setMax(5);
    axisTensY->setMin(0);
    chart->addAxis(axisTensY, Qt::AlignLeft);
    series->attachAxis(axisTensX);
    series->attachAxis(axisTensY);
    series2->attachAxis(axisTensX);
    series2->attachAxis(axisTensY);
    chart->setTitle("Tension");
    chart->setTitleFont(font);
    QChartView *chartView = new QChartView(chart);
    ui->gridLayout->addWidget(chartView,0,0);

    QXYSeries *series3 = bddMoby.graphIntHori();
    QXYSeries *series4 = bddMoby.graphIntVert();
    QChart *chart2 = new QChart();
    series3->setName("Moteur Horizontale");
    series4->setName("Moteur Verticale");
    chart2->setMargins(*margins);
    chart2->legend()->setAlignment(Qt::AlignTop);
    chart2->addSeries(series3);
    chart2->addSeries(series4);
    QDateTimeAxis *axisIntX = new QDateTimeAxis;
    axisIntX->setTickCount(8);
    axisIntX->setFormat("dd-MM-yyyy_hh:mm::ss");
    axisIntX->setTitleText("Date et heure");
    chart2->addAxis(axisIntX, Qt::AlignBottom);
    QValueAxis *axisIntY = new QValueAxis;
    axisIntY->setTitleText("Intensité (I)");
    axisIntY->setMax(1);
    axisIntY->setMin(0);
    chart2->addAxis(axisIntY, Qt::AlignLeft);
    series3->attachAxis(axisIntX);
    series3->attachAxis(axisIntY);
    series4->attachAxis(axisIntX);
    series4->attachAxis(axisIntY);
    chart2->setTitle("Intensite");
    chart2->setTitleFont(font);
    QChartView *chartView2 = new QChartView(chart2);
    ui->gridLayout_2->addWidget(chartView2,0,0);
}
