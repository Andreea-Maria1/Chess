/********************************************************************************
** Form generated from reading UI file 'CHESSGAME.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSGAME_H
#define UI_CHESSGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CHESSGAMEClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CHESSGAMEClass)
    {
        if (CHESSGAMEClass->objectName().isEmpty())
            CHESSGAMEClass->setObjectName("CHESSGAMEClass");
        CHESSGAMEClass->resize(600, 400);
        menuBar = new QMenuBar(CHESSGAMEClass);
        menuBar->setObjectName("menuBar");
        CHESSGAMEClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CHESSGAMEClass);
        mainToolBar->setObjectName("mainToolBar");
        CHESSGAMEClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(CHESSGAMEClass);
        centralWidget->setObjectName("centralWidget");
        CHESSGAMEClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CHESSGAMEClass);
        statusBar->setObjectName("statusBar");
        CHESSGAMEClass->setStatusBar(statusBar);

        retranslateUi(CHESSGAMEClass);

        QMetaObject::connectSlotsByName(CHESSGAMEClass);
    } // setupUi

    void retranslateUi(QMainWindow *CHESSGAMEClass)
    {
        CHESSGAMEClass->setWindowTitle(QCoreApplication::translate("CHESSGAMEClass", "CHESSGAME", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CHESSGAMEClass: public Ui_CHESSGAMEClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSGAME_H
