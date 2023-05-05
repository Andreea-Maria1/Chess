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

class ChessBoard : public QGridLayout 
{
public:
    ChessBoard(ChessBoard* chessBoard);
    ChessBoard(QWidget* parent = nullptr);
    ~ChessBoard() = default;

    void initialisation();
    void addPieces(std::shared_ptr<Piece> piece);
    void removePiece(Button* button);
    void deleteSpacing();
    void changeColourValidMove(Position newPosition);
    void resetColoursBoard();
    void click(Button* button);

    bool movePiece(Button* initialButton, Button* finalButton);
    bool isMovePossible(Button* initialButton, Button* finalButton);

    bool isSameColour(Piece* p1, Piece* p2) const;
    bool isSomethingInWay(Position initialPosition, Position finalPosition) const;
    
    Button* getButton(Position position) const;
    std::vector<std::shared_ptr<Button>> getListOfButton() const;
    std::vector<std::shared_ptr<Piece>> getlistOfPieces() const;

    bool isPositionEmpty = true;

private:
    std::vector<std::shared_ptr<Button>> listOfButton_;
    std::vector<std::shared_ptr<Piece>> listOfPieces_;
    std::shared_ptr<Piece> clickedPiece_ = nullptr;
    Button* lastClickedButton_ = nullptr;
    bool isWhiteTurn_ = true;
};