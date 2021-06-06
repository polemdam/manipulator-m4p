#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "connection.h"
#include "wykresy.h"
#include "Data.h"

#include <QBoxLayout>
#include <QMessageBox>
#include <QDesktopServices>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/// This is the main class for my aplication.
///
/// This class is created automatically. It create application main window which is definite by Qt designer.
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_actionPo_czenie_triggered();

    void on_SendConf_clicked();

    void on_actionWykresy_triggered();

private:
    Ui::MainWindow *ui;


    Connection *myConnection;
    Wykresy *myWykresy;


};
#endif // MAINWINDOW_H
