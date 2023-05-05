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

class Button : public QPushButton 
{
    Q_OBJECT

public:
    Button(int x, int y, std::shared_ptr<ChessBoard> chessBoard, QWidget* parent = nullptr);
    ~Button() = default;

    std::string getBaseColor() const;
    std::shared_ptr<Piece> getPiece() const;
    Position getPositionButton() const;
    void setPiece(std::shared_ptr<Piece> piece);
    void setBaseColour(std::string colour);

    void resetColour();

public slots:
    void handleButton();

private:
    std::shared_ptr<Piece> pieceOnButton_ = nullptr;
    Position positionButton_;
    std::shared_ptr<ChessBoard> chessBoard_;
    std::string baseColour_;

};