/// @file mobycrea.cpp
/// @author Louan DESHAYES
/// @version 1.1
/// @class MobyCrea

#include "mobycrea.h"

MobyCrea::MobyCrea()
{
    serial.setPortName(this->port);
    serial.setBaudRate(QSerialPort::Baud115200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    serial.open(QIODevice::ReadWrite);

    commande("H10#");
}

MobyCrea::~MobyCrea()
{
    commande("P050#P060#");
    commande("L10#");
    serial.close();
}

void MobyCrea::portChanged()
{
    commande("L10#");

    serial.close();

    //qDebug() << port;
    serial.setPortName(this->port);
    serial.setBaudRate(QSerialPort::Baud115200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    serial.open(QIODevice::ReadWrite);

    commande("H10#");
}

void MobyCrea::testco()
{
    commande("?#");

    for (int i=0; i<1000000; i++)
    {
        QString r = serial.readAll();
        if (r != "")
        {
            //qDebug() << r;
        }
    }
}

void MobyCrea::moteurs(int dir, int vitesse)
{
    QString qs = "P0" + QString::number(dir) + QString::number(vitesse) + "#";
    commande(qs);
}

void MobyCrea::commande(QString commande)
{
    std::string s = commande.toStdString();
    char data[s.length()+1];
    strcpy(data, s.c_str());
    qDebug() << data;
    serial.write(data);
    serial.waitForReadyRead(100);
}

bool MobyCrea::getButeeBasse()
{
    commande("I12#");
    QString r = serial.readAll();
    if (r == "1;")
    {
        qDebug() << r;
        return true;
    }
    else if (r == "0;")
    {
        qDebug() << r;
        return false;
    }
    else
    {
        qDebug() << r;
        return false;
    }
    QTimer::singleShot(5, this, [this](){});
}

bool MobyCrea::getButeeGauche()
{
    commande("I13#");
    QString r = serial.readAll();
    if (r == "0;")
    {
        qDebug() << r;
        return true;
    }
    else if (r == "1;")
    {
        qDebug() << r;
        return false;
    }
    else
    {
        qDebug() << r;
        return false;
    }
    QTimer::singleShot(5, this, [this](){});
}

bool getCapteurBas()
{

}

bool getCapteurGauche()
{

}

void MobyCrea::Conf_8()
{

}

void MobyCrea::Conf_O()
{

}

void MobyCrea::Conf_U()
{

}

void MobyCrea::Conf_n()
{

}
