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

    std::string s = "H10#";
    char data[s.length()+1];
    strcpy(data, s.c_str());
    //qDebug() << data;
    serial.write(data);
    serial.waitForReadyRead(100);
}

MobyCrea::~MobyCrea()
{
    std::string s = "L10#";
    char data10[s.length()+1];
    strcpy(data10, s.c_str());
    //qDebug() << data10;
    serial.write(data10);
    serial.waitForReadyRead(100);

    serial.close();
}

void MobyCrea::portChanged()
{
    std::string s = "L10#";
    char data10[s.length()+1];
    strcpy(data10, s.c_str());
    //qDebug() << data10;
    serial.write(data10);
    serial.waitForReadyRead(100);

    serial.close();

    //qDebug() << port;
    serial.setPortName(this->port);
    serial.setBaudRate(QSerialPort::Baud115200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    serial.open(QIODevice::ReadWrite);

    s = "H10#";
    char data[s.length()+1];
    strcpy(data, s.c_str());
    //qDebug() << data;
    serial.write(data);
    serial.waitForReadyRead(100);
}

void MobyCrea::testco()
{
    std::string s = "?#";
    char data[s.length()+1];
    strcpy(data, s.c_str());
    //qDebug() << data;
    serial.write(data);
    serial.waitForReadyRead(100);
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
    std::string dirStr = std::to_string(dir);
    std::string vitesseStr = std::to_string(vitesse);

    std::string s = "P0" + dirStr + vitesseStr + "#";
    char data[s.length()+1];
    strcpy(data, s.c_str());
    //qDebug() << data;
    serial.write(data);
    serial.waitForReadyRead(100);
}

void MobyCrea::commande(QString commande)
{
    std::string s = commande.toStdString();
    char data[s.length()+1];
    strcpy(data, s.c_str());
    //qDebug() << data;
    serial.write(data);
    serial.waitForReadyRead(100);
}

bool MobyCrea::getButeeBasse()
{
    std::string s = "I12#";
    char data[s.length()+1];
    strcpy(data, s.c_str());
    //qDebug() << data;
    serial.write(data);
    serial.waitForReadyRead(100);
    QString r;
    r = serial.readAll();
    if (r == "1;")
    {
        //qDebug() << r;
        return true;
    }
    else if (r == "0;")
    {
        //qDebug() << r;
        return false;
    }
    else
    {
        //qDebug() << r;
        return false;
    }
    QThread::msleep(5);
}

bool MobyCrea::getButeeGauche()
{
    std::string s = "I13#";
    char data[s.length()+1];
    strcpy(data, s.c_str());
    //qDebug() << data;
    serial.write(data);
    serial.waitForReadyRead(100);
    QString r;
    r = serial.readAll();
    if (r == "0;")
    {
        //qDebug() << r;
        return true;
    }
    else if (r == "1;")
    {
        //qDebug() << r;
        return false;
    }
    else
    {
        //qDebug() << r;
        return false;
    }
    QThread::msleep(5);
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
