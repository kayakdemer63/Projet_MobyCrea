/// @file mobycrea.cpp
/// @author Louan DESHAYES
/// @version 1.1
/// @class MobyCrea

#include "mobycrea.h"

MobyCrea::MobyCrea()
{
    /*
    from serial import *
    import time

    portSerie = Serial(port="COM8",baudrate=115200)
    time.sleep(2)

    portSerie.write(b'H10#') #relais mode piloté

    portSerie.write(b'?#')
    retour = portSerie.readline()
    print(retour)

    portSerie.write(b'L10#') #relais mode piloté
    portSerie.close()
    */
    serial.setPortName("COM8");
    serial.setBaudRate(QSerialPort::Baud115200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
}

void MobyCrea::testco()
{   /// @bug Envoie des commandes qui ne sont pas au bon format et ne sont donc pas comprises par la machine.
    serial.open(QIODevice::ReadWrite);

    QString data = "H10#F#";
    QByteArray dataByte = data.toUtf8();
    qDebug() << data.toUtf8();
    serial.write(data.toUtf8());

    QThread::msleep(100);

    data = "?#F#";
    dataByte = data.toUtf8();
    qDebug() << data.toUtf8();
    serial.write(data.toUtf8());

    data = "L10#F#";
    dataByte = data.toUtf8();
    qDebug() << data.toUtf8();
    serial.write(data.toUtf8());

    qDebug() << serial.readAll();
    serial.close();
}
