#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLCDNumber>
#include <QDebug>
#include <QDateTime>
#include <QString>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QAbstractAxis>
#include <QLineSeries>
#include "mobycrea.h"


//#define PORT "COM7"
QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
      ui->setupUi(this);
//      startTimer(1000);
//      secondes = 0;

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::writeData(const QByteArray &data){
    //port->write(data);
}
void MainWindow::on_graphique_clicked()
{


    // Les données
        courbe = new QLineSeries();

//        courbe->append(0, r); // x et y
//        courbe->append(2, r);
//        courbe->append(3, r);
//        courbe->append(4, r);
//        courbe->append(5, r);
//        courbe->append(6,r);
//        courbe->append(7, r);
//        courbe->append(8, r);
//        courbe->append(9, r);
//        courbe->append(10, r);
        courbe->setName(QString::fromUtf8("Uverticale"));
        QPen pen(0x059605);
        pen.setWidth(3);
        pen.setStyle(Qt::DashLine);
        courbe->setPen(pen);;

        // Le graphe
        graphe = new QChart();
        graphe->addSeries(courbe);
        graphe->setTitle("Mobycrea Mesures");
        // Les axes
        graphe->createDefaultAxes();
        graphe->axes(Qt::Horizontal).first()->setRange(0, 10);
        graphe->axes(Qt::Vertical).first()->setRange(0, 30);
        // Le widget
            graphique = new QChartView(graphe);
            graphique->setRenderHint(QPainter::Antialiasing);
            setCentralWidget(graphique);
            resize(640, 480);
}

void MainWindow::on_mesurer_clicked()
{

    qDebug()<<"Lancement de mesures";
    float Ivert, Ihor, arret_moteur, pilotage_v, pilotage_h, UAlim,Uvert, Uhor;
    pilotage_v = moby.commande(tension_vert);//moteur vertical en marche
    QThread::msleep(100); // attendre 2s
    pilotage_h = moby.commande(tension_hor);


    float reponse = moby.commande(U_alim); // Lecture de la reponse de la tension d'alimentation
    qDebug() <<reponse;
    //mesure de la tension d'alimentation
    UAlim = 3.3*5*reponse/1023.0;
    qDebug() << "Tension d'alimentation:"<<UAlim<<"V";
    ui->tension_a->setValue(UAlim);
    QThread::msleep(100);


    reponse = moby.commande(U_vert);
    qDebug() << reponse;
    //mesure de la tension du moteur vertical
    Uvert= 13-3.3*5*reponse/1023.0; // q= Uref/2^10-1 = 5/1023,
    qDebug() <<"Tension verticale :" <<Uvert<<"V";
    ui->tension_v->setValue(Uvert);

    QThread::msleep(100);

    //mesure du courant du moteur vertical
    reponse = moby.commande(I_vert);
    qDebug() << reponse;
    Ivert=((5*reponse/1023.0)-2.5)/0.185;
    qDebug() <<"Courant vertical:"<< Ivert<<"V";
    ui->courant_v->setValue(Ivert);

  //donnee.addData(Uvert, Ivert, Uhor, Ihor); //mettre les valeurs dans la BDD

}
void time(){

}
void MainWindow::on_stop_clicked()
{
    // Arrêt des moteurs
float arret_v, arret_h;
arret_v = moby.commande(stop_vert);
arret_h = moby.commande(stop_hor);
qDebug()<< "Arrêt des moteurs";

}







