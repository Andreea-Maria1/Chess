/*
* Chess Game.
* \file   CHESSGAME.h
* \author Andreea Maria Ghioltan et Maria Bourouisa
* \date   20 avril 2023
* Créé le 10 avril 2023
*/

#pragma once

#include <iostream>
#include <QPushButton>
#include <QGridLayout>
#include <vector>
#include <QtWidgets/QMainWindow>
#include "Piece.h"

class CHESSGAME : public QMainWindow
{
    Q_OBJECT

public:
    CHESSGAME(QWidget* parent = nullptr);
    ~CHESSGAME() = default;
};
