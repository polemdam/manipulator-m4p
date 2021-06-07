#ifndef WYKRESY_H
#define WYKRESY_H

#include <QDialog>
#include "Data.h"
namespace Ui {
class Wykresy;
}

class Wykresy : public QDialog
{
    Q_OBJECT

public:
    explicit Wykresy(QWidget *parent = nullptr);
    ~Wykresy();
private slots:
    void newDataToDraw(Data newData);
private:
    Ui::Wykresy *ui;
    double time;
};

#endif // WYKRESY_H
