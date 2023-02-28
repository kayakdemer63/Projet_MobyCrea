/// @file mobycrea.cpp
/// @author Louan DESHAYES
/// @version 1.1
/// @class MobyCrea

#include "mobycrea.h"

MobyCrea::MobyCrea()
{
    serial.setPortName("COM8");
    serial.setBaudRate(QSerialPort::Baud115200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
}

void MobyCrea::testco()
{   /// @bug Aucune réaction du MobyCrea.
    serial.open(QIODevice::ReadWrite);

    std::string s = "H10#";
    char data[s.length()+1];
    strcpy(data, s.c_str());
    qDebug() << data;
    serial.write(data);
    serial.waitForReadyRead(100);

    QThread::msleep(1000);

    s = "?#";
    char data2[s.length()+1];
    strcpy(data2, s.c_str());
    qDebug() << data2;
    serial.write(data2);
    serial.waitForReadyRead(100);
    for (int i=0; i<1000000; i++)
    {
        QString r = serial.readAll();
        if (r != "")
        {
            qDebug() << r;
        }
    }

    s = "L10#";
    char data10[s.length()+1];
    strcpy(data10, s.c_str());
    qDebug() << data10;
    serial.write(data10);
    serial.waitForReadyRead(100);

    serial.close();
}
