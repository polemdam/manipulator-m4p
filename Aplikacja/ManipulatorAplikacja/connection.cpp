#include "connection.h"
#include "ui_connection.h"



Connection::Connection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connection)
{
    ui->setupUi(this);
    this->device = new QSerialPort(this);
}

Connection::~Connection()
{
    delete ui;
}

void Connection::addToLogs(QString message){
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
    ui->textEditLogs->append(currentDateTime + "\t" + message);
}


void Connection::on_pushButtonSearch_clicked()
{
    ui->comboBoxDevices->clear();
    this->addToLogs("Szukam urządzeń...");
    QList<QSerialPortInfo> devices;
    devices = QSerialPortInfo::availablePorts();

    for(int i = 0; i < devices.count(); i++) {
        this->addToLogs("Znalazłem urządzenie: " + devices.at(i).portName() + " " + devices.at(i).description());
        ui->comboBoxDevices->addItem(devices.at(i).portName() + "\t" + devices.at(i).description());
    }

}

void Connection::on_pushButtonOn_clicked()
{
    if(ui->comboBoxDevices->count() == 0) {
      this->addToLogs("Nie wykryto żadnych urządzeń!");
      return;
    }

    QString portName = ui->comboBoxDevices->currentText().split("\t").first();
    this->device->setPortName(portName);

    // OTWÓRZ I SKONFIGURUJ PORT:

    if(!device->isOpen()) {
        if(device->open(QSerialPort::ReadWrite)) {
          this->device->setBaudRate(QSerialPort::Baud115200);
          this->device->setDataBits(QSerialPort::Data8);
          this->device->setParity(QSerialPort::NoParity);
          this->device->setStopBits(QSerialPort::OneStop);
          this->device->setFlowControl(QSerialPort::NoFlowControl);

          connect(this->device, SIGNAL(readyRead()), this, SLOT(readFromPort()));

          this->addToLogs("Otwarto port szeregowy.");
        } else {
          this->addToLogs("Otwarcie porty szeregowego się nie powiodło!");
        }
    }
    else{
        this->addToLogs("Port już jest otwarty!");
        return;
    }
}

void Connection::on_pushButtonOff_clicked()
{
    if(this->device->isOpen()) {
      this->device->close();
      this->addToLogs("Zamknięto połączenie.");
    }
    else {
      this->addToLogs("Port nie jest otwarty!");
      return;
    }
}

void Connection::readFromPort()
{
    while(this->device->canReadLine()) {
        QString line = this->device->readLine();
        //qDebug() << line;

        QString terminator = "\r";
        int pos = line.lastIndexOf(terminator);
        //qDebug() << line.left(pos);

        this->addToLogs(line.left(pos));
      }
}
