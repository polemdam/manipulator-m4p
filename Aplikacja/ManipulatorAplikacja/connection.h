#ifndef CONNECTION_H
#define CONNECTION_H

#include <QDialog>
#include <QList>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QDebug>
#include <QDateTime>

namespace Ui {
class Connection;
}

class Connection : public QDialog
{
    Q_OBJECT

public:
    explicit Connection(QWidget *parent = nullptr);
    ~Connection();

private slots:
    void on_pushButtonSearch_clicked();

    void on_pushButtonOn_clicked();

    void on_pushButtonOff_clicked();

    void readFromPort();

private:
    Ui::Connection *ui;
    void addToLogs(QString message);
    QSerialPort *device;

};

#endif // CONNECTION_H
