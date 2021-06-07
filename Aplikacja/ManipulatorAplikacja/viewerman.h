#ifndef VIEWERMAN_H
#define VIEWERMAN_H
#include <QGLViewer/qglviewer.h>
#include "Data.h"


class ViewerMan:  public QGLViewer
{
public:
  ViewerMan(QWidget *pParent = nullptr): QGLViewer(pParent) {}
   ~ViewerMan();
 protected :
    virtual void draw();
    virtual void init();
 public:
    void newAngles(Data newData);

 private :
    GLUquadricObj *silnik;
    int Angles[3];

};

#endif // VIEWERMAN_H
