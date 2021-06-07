#include "connection.h"
#include "ui_connection.h"
#include <math.h>

static uint8_t sht75_crc_table[] = {

    0,   49,  98,  83,  196, 245, 166, 151, 185, 136, 219, 234, 125, 76,  31,  46,
    67,  114, 33,  16,  135, 182, 229, 212, 250, 203, 152, 169, 62,  15,  92,  109,
    134, 183, 228, 213, 66,  115, 32,  17,  63,  14,  93,  108, 251, 202, 153, 168,
    197, 244, 167, 150, 1,   48,  99,  82,  124, 77,  30,  47,  184, 137, 218, 235,
    61,  12,  95,  110, 249, 200, 155, 170, 132, 181, 230, 215, 64,  113, 34,  19,
    126, 79,  28,  45,  186, 139, 216, 233, 199, 246, 165, 148, 3,   50,  97,  80,
    187, 138, 217, 232, 127, 78,  29,  44,  2,   51,  96,  81,  198, 247, 164, 149,
    248, 201, 154, 171, 60,  13,  94,  111, 65,  112, 35,  18,  133, 180, 231, 214,
    122, 75,  24,  41,  190, 143, 220, 237, 195, 242, 161, 144, 7,   54,  101, 84,
    57,  8,   91,  106, 253, 204, 159, 174, 128, 177, 226, 211, 68,  117, 38,  23,
    252, 205, 158, 175, 56,  9,   90,  107, 69,  116, 39,  22,  129, 176, 227, 210,
    191, 142, 221, 236, 123, 74,  25,  40,  6,   55,  100, 85,  194, 243, 160, 145,
    71,  118, 37,  20,  131, 178, 225, 208, 254, 207, 156, 173, 58,  11,  88,  105,
    4,   53,  102, 87,  192, 241, 162, 147, 189, 140, 223, 238, 121, 72,  27,  42,
    193, 240, 163, 146, 5,   52,  103, 86,  120, 73,  26,  43,  188, 141, 222, 239,
    130, 179, 224, 209, 70,  119, 36,  21,  59,  10,  89,  104, 255, 206, 157, 172
};

Connection::Connection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connection)
{
    ui->setupUi(this);
    this->device = new QSerialPort(this);
    Angles1=0;
    Angles2=0;
    Angles3=0;
    Time=0;
}

Connection::~Connection()
{
    delete ui;
}

void Connection::addToLogs(QString message){
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
    ui->textEditLogs->append(currentDateTime + "\t" + message + "\r\n");
}

uint8_t Connection::checkCrc_8(char *input_str, size_t num_bytes)
{
    size_t a;
    uint8_t crc;
    char *ptr;

        crc = 0x00;
        ptr = input_str;

        if ( ptr != NULL ) for (a=0; a<num_bytes; a++) {

            crc = sht75_crc_table[(*ptr++) ^ crc];
        }

        return crc;

}

void Connection::addValuesOfAngles(int joint1, int joint2, int joint3)
{
    Data newData;
    Angles1=joint1;
    newData.Angle1=joint1;
    emit  changedAngle1(joint1);
    Angles2=joint2;
    newData.Angle2=joint2;
    emit  changedAngle2(joint2);
    Angles3=joint3;
    newData.Angle3=joint3;
    newData.Time=++Time;
    emit  changedAngle3(joint3);
    emit newDataToRead(newData);

}

void Connection::SendConfiguration(int joint1, int joint2, int joint3)
{
    QString message1="A";
    if(joint1 >= 0){
        message1+="+";
    }
    else{
        message1+="-";
    }
    if(abs(joint1) > 99){
        message1+=QString::number(abs(joint1));
    }
    else if(abs(joint1) > 9){
         message1+="0"+QString::number(abs(joint1));
    }
    else{
        message1+="00"+QString::number(abs(joint1));
    }


    message1+="B";
    if(joint2 >= 0){
        message1+="+";
    }
    else{
        message1+="-";
    }
    if(abs(joint1) > 9){
         message1+="0"+QString::number(abs(joint2));
    }
    else{
        message1+="00"+QString::number(abs(joint2));
    }



    message1+="C";
    if(joint3 >= 0){
        message1+="+";
    }
    else{
        message1+="-";
    }
    if(abs(joint1) > 9){
         message1+="0"+QString::number(abs(joint3));
    }
    else{
        message1+="00"+QString::number(abs(joint3));
    }


    qDebug() << message1;
    if(this->device->isOpen() && this->device->isWritable()) {
        this->device->write(message1.toStdString().c_str());
      } else {
        this->addToLogs("Nie mogę wysłać wiadomości. Port nie jest otwarty!");
      }





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
    int k, val1, val2, val3;
    char Tab[12];
    while(this->device->canReadLine()) {
        QByteArray message = this->device->readAll();
       k=(message[12]-48)*100+(message[13]-48)*10+(message[14]-48);

        for(int i=0; i<12; i++){
            Tab[i]=message[i];
        }
        int p=checkCrc_8(Tab,12);

        if(k == p){
            val1=(message[1]-48)*100+(message[2]-48)*10+(message[3]-48);
            val2=(message[5]-48)*100+(message[6]-48)*10+(message[7]-48);
            val3=(message[9]-48)*100+(message[10]-48)*10+(message[11]-48);
            addValuesOfAngles(val1,val2,val3);
        }

        this->addToLogs(message);
      }
}
