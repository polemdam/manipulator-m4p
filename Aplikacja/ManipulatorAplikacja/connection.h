#ifndef CONNECTION_H
#define CONNECTION_H

#include <QDialog>
#include <QList>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QDebug>
#include <QDateTime>
#include <QString>
#include <QByteArray>
#include <cstdlib>
#include <iostream>
#include "Data.h"


namespace Ui {
class Connection;
}

///  This is class created to communicate with COM port and to read information about angles values
///
///
class Connection : public QDialog
{
    Q_OBJECT

public:
    explicit Connection(QWidget *parent = nullptr);
    ~Connection();

signals:
    void changedAngle1(int Value1);
    void changedAngle2(int Value2);
    void changedAngle3(int Value3);
    void newDataToRead(Data data);

private slots:
    void on_pushButtonSearch_clicked();

    void on_pushButtonOn_clicked();

    void on_pushButtonOff_clicked();

    void readFromPort();


private:
    Ui::Connection *ui;
    void addToLogs(QString message);
    QSerialPort *device;
    uint8_t checkCrc_8( char *input_str, size_t num_bytes );
    void addValuesOfAngles(int joint1, int joint2, int joint3);
public:
    int Angles1;
    int Angles2;
    int Angles3;
    int Time;
    void SendConfiguration(int joint1, int joint2, int joint3);

};

#endif // CONNECTION_H
