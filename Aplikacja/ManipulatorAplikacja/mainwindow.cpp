#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myConnection =new Connection(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionPo_czenie_triggered()
{

        myConnection->setModal(false);
        myConnection->show();
        myConnection->activateWindow();


}
