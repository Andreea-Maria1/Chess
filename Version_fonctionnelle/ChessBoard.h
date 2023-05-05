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
#include <QString>
#include <Qsize>
#include <vector>
#include <memory>
#include "Piece.h"
#include "Button.h"
#include "MovementManager.h"

#include <iostream>

class ChessBoard : public QGridLayout 
{
    Q_OBJECT 

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

    bool movePiece(Button* initialButton, Button* finalButton);
    bool isMovePossible(Button* initialButton, Button* finalButton);

    bool putsKingInDanger(Button* initialButton, Button* finalButton);
    bool isSameColour(Piece* p1, Piece* p2) const;
    bool isSomethingInWay(Position initialPosition, Position finalPosition) const;
    
    Button* getButton(Position position) const;
    Button* getButton(Position position, std::vector<std::shared_ptr<Button>> listOfButton) const;
    Button* getKingButton(bool white) const;

    void setButtonRed(Button* button) const;
    void setButtonGrey(Button* button) const;
    void setButtonGreen(Button* button) const;

    std::vector<std::shared_ptr<Button>> getListOfButton() const;
    std::vector<std::shared_ptr<Piece>> getlistOfPieces() const;

public slots:
    void click(Button* button);

private:
    std::vector<std::shared_ptr<Button>> listOfButton_;
    std::vector<std::shared_ptr<Piece>> listOfPieces_;
    std::shared_ptr<Piece> clickedPiece_ = nullptr;
    Button* lastClickedButton_ = nullptr;
    bool isWhiteTurn_ = true;
};