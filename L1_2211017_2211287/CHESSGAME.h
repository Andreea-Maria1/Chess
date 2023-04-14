#pragma once

#include <iostream>
#include <QPushButton>
#include <QGridLayout>
#include <vector>
#include <QtWidgets/QMainWindow>
#include "ui_CHESSGAME.h"
#include "Piece.h"

class CHESSGAME : public QMainWindow
{
    Q_OBJECT

public:
    CHESSGAME(QWidget* parent = nullptr);
    ~CHESSGAME() = default;

private slots:/*
    void handleButton();*/

private:
    Ui::CHESSGAMEClass ui;/*
    QPushButton* m_button;
    QPushButton* b_button;*/
};
