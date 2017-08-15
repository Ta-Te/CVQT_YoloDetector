/********************************************************************************
** Form generated from reading UI file 'yolodetector.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YOLODETECTOR_H
#define UI_YOLODETECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_YoloDetector
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionDetect_Object;
    QWidget *centralWidget;
    QLabel *label;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuDetect;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *YoloDetector)
    {
        if (YoloDetector->objectName().isEmpty())
            YoloDetector->setObjectName(QStringLiteral("YoloDetector"));
        YoloDetector->resize(660, 780);
        actionOpen = new QAction(YoloDetector);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(YoloDetector);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExit = new QAction(YoloDetector);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionDetect_Object = new QAction(YoloDetector);
        actionDetect_Object->setObjectName(QStringLiteral("actionDetect_Object"));
        centralWidget = new QWidget(YoloDetector);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 640, 480));
        label->setStyleSheet(QLatin1String("background-color: rgb(215, 215, 215);\n"
"border-color: rgb(8, 8, 8);"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 500, 641, 201));
        YoloDetector->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(YoloDetector);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 660, 17));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuDetect = new QMenu(menuBar);
        menuDetect->setObjectName(QStringLiteral("menuDetect"));
        YoloDetector->setMenuBar(menuBar);
        mainToolBar = new QToolBar(YoloDetector);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        YoloDetector->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(YoloDetector);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        YoloDetector->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuDetect->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuDetect->addAction(actionDetect_Object);

        retranslateUi(YoloDetector);

        QMetaObject::connectSlotsByName(YoloDetector);
    } // setupUi

    void retranslateUi(QMainWindow *YoloDetector)
    {
        YoloDetector->setWindowTitle(QApplication::translate("YoloDetector", "Yolo Object Detector", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("YoloDetector", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("YoloDetector", "Save", Q_NULLPTR));
        actionExit->setText(QApplication::translate("YoloDetector", "Exit", Q_NULLPTR));
        actionDetect_Object->setText(QApplication::translate("YoloDetector", "Detect Object", Q_NULLPTR));
        label->setText(QString());
        menuFile->setTitle(QApplication::translate("YoloDetector", "File", Q_NULLPTR));
        menuDetect->setTitle(QApplication::translate("YoloDetector", "Detect", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class YoloDetector: public Ui_YoloDetector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YOLODETECTOR_H
