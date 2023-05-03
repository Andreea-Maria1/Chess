/*
* Chess Game.
* \file   ChessBoard.h
* \author Andreea Maria Ghioltan et Maria Bourouisa
* \date   20 avril 2023
* Créé le 10 avril 2023
*/

#pragma once

#include <QPushButton>
#include <QGridLayout>
#include <QtWidgets/QMainWindow>
#include <vector>
#include <memory>
#include "Piece.h"
#include "Button.h"

class ChessBoard : public QGridLayout {
public:
    ChessBoard(QWidget* parent = nullptr);
    ~ChessBoard() = default;
    void initialisation();
    void addPieces(std::shared_ptr<Piece> piece);
    void removePiece(std::shared_ptr<Piece> piece);
    void movePieces(int x, int y, int newX, int newY);
    void deleteSpacing();
    std::vector<std::shared_ptr<Button>> getListOfButton() const;

private:
    std::vector<std::shared_ptr<Button>> listOfButton_;
    std::vector<std::shared_ptr<Piece>> listOfPieces_;
    bool isPositionEmpty_;
};
