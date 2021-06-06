#ifndef VIEWERMAN_H
#define VIEWERMAN_H
#include <QGLViewer/qglviewer.h>

class ViewerMan:  public QGLViewer
{
public:
  ViewerMan(QWidget *pParent = nullptr): QGLViewer(pParent) {}

 protected :
    virtual void draw();
    virtual void init();


  GLUquadricObj *silnik;

};

#endif // VIEWERMAN_H
