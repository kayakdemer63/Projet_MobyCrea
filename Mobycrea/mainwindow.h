#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QSerialPort>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QtCharts>
#include <QLineSeries>
#include <QSqlDatabase>
#include "mobycrea.h"
#include "bdd.h"

//#define PORT "COM14"
#define U_alim "A06#F#" // mesure de la tension d'alimentation sur A06
#define U_vert "A03#F#"
#define I_vert "A04#F#"
#define tension_vert "P06200#F#" // moteur vertical
#define tension_hor "P05200#F#" // moteur horizontal
#define stop_vert "P06000#F#" // arrêt moteur vertical
#define stop_hor "P05000#F#" // arrêt moteur vertical


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    MobyCrea moby;
    BDD donnee;


private slots:
    void writeData(const QByteArray &data);
    void on_mesurer_clicked();
    void on_graphique_clicked();
    void on_stop_clicked();
//    void on_enregistrer_clicked();
//    void timerEvent(QTimerEvent *evt);




private:
    Ui::MainWindow *ui;
    QSerialPort *port;

    QByteArray data;
    QChartView *graphique; // widget pour afficher un graphique
    QChart *graphe; // représentation de graphe
    QLineSeries *courbe; //les données
    QSqlDatabase bddMobycrea;
    QTimer *timer;
    int secondes;
    QValueAxis *axeX;
    QValueAxis *axeY;

//    qreal step;
//    qreal x;
//    qreal y;

};
#endif // MAINWINDOW_H
