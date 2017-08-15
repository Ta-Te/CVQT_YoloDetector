#-------------------------------------------------
#
# Project created by QtCreator 2017-08-14T13:04:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = YoloDetector
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
        yolodetector.cpp

INCLUDEPATH += D:/opencv32/build/install/include \
               "$$PWD/Yolo/include"  \

LIBS += D:/opencv32/build/install/x64/vc12/lib/*.lib \
        "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v8.0/lib/x64/*.lib" \
        "$$PWD/Yolo/lib/*.lib"  \

HEADERS += \
        yolodetector.h

FORMS += \
        yolodetector.ui

