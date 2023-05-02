/*
* Chess Game.
* \file   Button.h
* \author Andreea Maria Ghioltan et Maria Bourouisa
* \date   20 avril 2023
* Créé le 10 avril 2023
*/

#pragma once

#include <iostream>
#include <QPushButton>
#include <Qsize>
#include <memory>
#include "Piece.h"


class Button : public QPushButton {
    Q_OBJECT

public:
    Button( int x = 0, int y = 0, QWidget* parent = nullptr);
    ~Button() = default;
    std::shared_ptr<Piece> getPiece() const;
    void setPiece(std::shared_ptr<Piece> piece);
    int getPosX() const;
    int getPosY() const;

public slots:
    void handleClick();

private:
    std::shared_ptr<Piece> pieceOfSquare_ = nullptr;
    int posX_;
    int posY_;
};