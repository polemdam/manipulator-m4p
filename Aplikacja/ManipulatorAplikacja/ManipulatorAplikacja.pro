QT       += core gui
QT += serialport
QT += opengl
QT += widgets
QT += xml opengl
QT+= widgets printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    glwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    wykresy.cpp

HEADERS += \
    Data.h \
    connection.h \
    glwidget.h \
    mainwindow.h \
    qcustomplot.h \
    wykresy.h

FORMS += \
    connection.ui \
    mainwindow.ui \
    wykresy.ui

# Default rules for deployment.   d
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += -lglut -lGLU
INCLUDEPATH += /usr/include/c++/{gcc_version}/
INCLUDEPATH += /home/wiktor/libQGLViewer-2.7.2
LIBS += -L/home/wiktor/libQGLViewer-2.7.2/QGLViewer  -lQGLViewer-qt5
