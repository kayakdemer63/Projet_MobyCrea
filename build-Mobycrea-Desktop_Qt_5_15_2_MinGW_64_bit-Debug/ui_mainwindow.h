/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QDoubleSpinBox *vitesse;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_3;
    QDoubleSpinBox *tension_a;
    QLabel *label_3;
    QPushButton *pushButton_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *mesurer;
    QPushButton *stop;
    QPushButton *graphique;
    QPushButton *enregistrer;
    QPushButton *pushButton;
    QLabel *label2;
    QPushButton *pushButton_2;
    QDoubleSpinBox *tension_v;
    QDoubleSpinBox *time;
    QDoubleSpinBox *courant_v;
    QLabel *label_2;
    QPushButton *pushButton_5;
    QLCDNumber *temps;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(750, 399);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(110, 50, 571, 291));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        vitesse = new QDoubleSpinBox(gridLayoutWidget);
        vitesse->setObjectName(QString::fromUtf8("vitesse"));
        vitesse->setEnabled(false);

        gridLayout->addWidget(vitesse, 8, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout_2->addWidget(pushButton_3);


        gridLayout->addLayout(verticalLayout_2, 10, 1, 1, 1);

        tension_a = new QDoubleSpinBox(gridLayoutWidget);
        tension_a->setObjectName(QString::fromUtf8("tension_a"));
        tension_a->setEnabled(false);
        QFont font;
        font.setFamily(QString::fromUtf8("Bookman Old Style"));
        tension_a->setFont(font);
        tension_a->setMaximum(1000.000000000000000);

        gridLayout->addWidget(tension_a, 7, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bookman Old Style"));
        font1.setBold(false);
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 7, 1, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 14, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mesurer = new QPushButton(gridLayoutWidget);
        mesurer->setObjectName(QString::fromUtf8("mesurer"));
        mesurer->setFont(font);

        horizontalLayout->addWidget(mesurer);

        stop = new QPushButton(gridLayoutWidget);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setFont(font);

        horizontalLayout->addWidget(stop);

        graphique = new QPushButton(gridLayoutWidget);
        graphique->setObjectName(QString::fromUtf8("graphique"));
        graphique->setFont(font);

        horizontalLayout->addWidget(graphique);

        enregistrer = new QPushButton(gridLayoutWidget);
        enregistrer->setObjectName(QString::fromUtf8("enregistrer"));
        enregistrer->setFont(font);

        horizontalLayout->addWidget(enregistrer);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout, 14, 0, 1, 1);

        label2 = new QLabel(gridLayoutWidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setFont(font);

        gridLayout->addWidget(label2, 10, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 9, 1, 1, 1);

        tension_v = new QDoubleSpinBox(gridLayoutWidget);
        tension_v->setObjectName(QString::fromUtf8("tension_v"));
        tension_v->setEnabled(false);
        tension_v->setFont(font);

        gridLayout->addWidget(tension_v, 3, 0, 1, 1);

        time = new QDoubleSpinBox(gridLayoutWidget);
        time->setObjectName(QString::fromUtf8("time"));
        time->setEnabled(false);

        gridLayout->addWidget(time, 9, 0, 1, 1);

        courant_v = new QDoubleSpinBox(gridLayoutWidget);
        courant_v->setObjectName(QString::fromUtf8("courant_v"));
        courant_v->setEnabled(false);
        courant_v->setFont(font);
        courant_v->setMaximum(1000.000000000000000);

        gridLayout->addWidget(courant_v, 6, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 8, 1, 1, 1);

        temps = new QLCDNumber(gridLayoutWidget);
        temps->setObjectName(QString::fromUtf8("temps"));

        gridLayout->addWidget(temps, 15, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 750, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        vitesse->setPrefix(QCoreApplication::translate("MainWindow", "vitesse : ", nullptr));
        vitesse->setSuffix(QCoreApplication::translate("MainWindow", " m/s", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "U", nullptr));
        tension_a->setPrefix(QCoreApplication::translate("MainWindow", "Tension d'alimentation  = ", nullptr));
        tension_a->setSuffix(QCoreApplication::translate("MainWindow", " V", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Mouvement :", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "U invers\303\251", nullptr));
        mesurer->setText(QCoreApplication::translate("MainWindow", "Mesurer", nullptr));
        stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        graphique->setText(QCoreApplication::translate("MainWindow", "Graphique", nullptr));
        enregistrer->setText(QCoreApplication::translate("MainWindow", "Enregistrer", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Fichier", nullptr));
        label2->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Circulaire", nullptr));
        tension_v->setPrefix(QCoreApplication::translate("MainWindow", "Tension verticale = ", nullptr));
        tension_v->setSuffix(QCoreApplication::translate("MainWindow", " V", nullptr));
        time->setPrefix(QCoreApplication::translate("MainWindow", "time = ", nullptr));
        courant_v->setPrefix(QCoreApplication::translate("MainWindow", "Courant vertical = ", nullptr));
        courant_v->setSuffix(QCoreApplication::translate("MainWindow", " A", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Mesures : ", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Infini", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
