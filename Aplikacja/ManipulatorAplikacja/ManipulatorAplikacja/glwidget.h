#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QGLWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLExtraFunctions>
#include <QGLViewer/qglviewer.h>

class GLWidget : public QOpenGLWidget, protected QOpenGLExtraFunctions
{
    Q_OBJECT
public:
    GLWidget(QWidget *parent=nullptr);
protected:

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

    QOpenGLContext *m_context;
private:
    unsigned int buffer, VAO, EBO;

};

#endif // GLWIDGET_H
