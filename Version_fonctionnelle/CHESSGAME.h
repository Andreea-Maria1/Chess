/********************************************************************************
** Form generated from reading UI file 'CHESSGAMETqqpNn.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CHESSGAMETQQPNN_H
#define CHESSGAMETQQPNN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CHESSGAMEClass
{
public:
    QWidget* centralWidget;
    QWidget* gridLayoutWidget;
    QGridLayout* gridLayout;
    QWidget* verticalLayoutWidget;
    QVBoxLayout* verticalLayout;
    QRadioButton* option1;
    QRadioButton* option2;
    QPushButton* confirmSelection;
    QMenuBar* menuBar;
    QToolBar* mainToolBar;
    QStatusBar* statusBar;

    void setupUi(QMainWindow* CHESSGAMEClass)
    {
        if (CHESSGAMEClass->objectName().isEmpty())
            CHESSGAMEClass->setObjectName("CHESSGAMEClass");
        CHESSGAMEClass->setMinimumSize(QSize(1000, 800));
        centralWidget = new QWidget(CHESSGAMEClass);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setMinimumSize(QSize(1000, 900));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(30, 10, 750, 750));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(800, 10, 171, 571));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        option1 = new QRadioButton(verticalLayoutWidget);
        option1->setObjectName("option1");
        QFont font;
        font.setFamilies({ QString::fromUtf8("Arial Narrow") });
        font.setPointSize(9);
        option1->setFont(font);

        verticalLayout->addWidget(option1);

        option2 = new QRadioButton(verticalLayoutWidget);
        option2->setObjectName("option2");
        option2->setFont(font);

        verticalLayout->addWidget(option2);

        confirmSelection = new QPushButton(verticalLayoutWidget);
        confirmSelection->setObjectName("confirmSelection");
        QFont font1;
        font1.setFamilies({ QString::fromUtf8("Arial Rounded MT Bold") });
        font1.setPointSize(12);
        confirmSelection->setFont(font1);
        confirmSelection->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(confirmSelection);

        CHESSGAMEClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CHESSGAMEClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1200, 22));
        CHESSGAMEClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CHESSGAMEClass);
        mainToolBar->setObjectName("mainToolBar");
        CHESSGAMEClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CHESSGAMEClass);
        statusBar->setObjectName("statusBar");
        CHESSGAMEClass->setStatusBar(statusBar);

        retranslateUi(CHESSGAMEClass);

        QMetaObject::connectSlotsByName(CHESSGAMEClass);
    } // setupUi

    void retranslateUi(QMainWindow* CHESSGAMEClass)
    {
        CHESSGAMEClass->setWindowTitle(QCoreApplication::translate("CHESSGAMEClass", "CHESSGAME", nullptr));
        option1->setText(QCoreApplication::translate("CHESSGAMEClass", "Naruto VS Sasuke (1247, Konoha)", nullptr));
        option2->setText(QCoreApplication::translate("CHESSGAMEClass", "Goku VS Vegeta (2700, Namek)", nullptr));
        confirmSelection->setText(QCoreApplication::translate("CHESSGAMEClass", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CHESSGAMEClass : public Ui_CHESSGAMEClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CHESSGAMETQQPNN_H
