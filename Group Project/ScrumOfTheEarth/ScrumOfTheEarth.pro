#-------------------------------------------------
#
# Project created by QtCreator 2018-11-06T21:12:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ScrumOfTheEarth
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        window.cpp \
    rectangle.cpp \
    square.cpp \
    polygon.cpp \
    contactus.cpp \
    text.cpp \
    shape_parser.cpp \
    mainwindow.cpp \
    circle.cpp \
    ellipse.cpp \
    line.cpp \
    polyline.cpp


HEADERS += \
        window.h \
    vector.h \
    shape.h \
    rectangle.h \
    line.h \
    circle.h \
    ellipse.h \
    contactus.h \
    square.h \
    polyline.h \
    polygon.h \
    text.h \
    mainwindow.h \
    renderarea.h


FORMS += \
        window.ui \
   contactus.ui \
    mainwindow.ui

RESOURCES += \
    logo.qrc

DISTFILES +=
