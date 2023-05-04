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
#include "Position.h"
class ChessBoard;
class Button : public QPushButton {
    Q_OBJECT

public:

    Button(int x, int y, std::shared_ptr<ChessBoard> chessBoard, QWidget* parent = nullptr);
    ~Button() = default;
    std::shared_ptr<Piece> getPiece() const;
    void setPiece(std::shared_ptr<Piece> piece);
    Position getPositionButton() const;
    void setBaseColor(std::string colour);
    std::string getBaseColor() const;

public slots:
    void handleButton();

private:
    std::shared_ptr<Piece> pieceOfButton_ = nullptr;
    Position positionButton_;
    std::shared_ptr<ChessBoard> chessBoard_;
    std::string baseColour_;
};