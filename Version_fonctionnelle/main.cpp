/*
* Chess Game.
* \file   main.cpp
* \author Andreea Maria Ghioltan et Maria Bourouisa
* \date   20 avril 2023
* Créé le 10 avril 2023
*/

#include "CHESSGAME.h"
#include "ChessBoard.h"
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <memory>
#include "RAII.h"
#include <iostream>

using namespace png;

int main(int argc, char *argv[])
{   
    std::cout << "imma cry" << std::endl;
    QApplication a(argc, argv);
    CHESSGAME w;
    
    std::shared_ptr<ChessBoard> chessBoard = std::make_shared<ChessBoard>();
    std::vector<std::shared_ptr<Piece>> piecesAdded;
    try 
    {
    piecesAdded.push_back(std::make_shared<King>(pieceColour::WHITE, 7, 4, pieceName::KING, kingIconWhite));
    piecesAdded.push_back(std::make_shared<King>(pieceColour::BLACK, 0, 4, pieceName::KING, kingIconBlack));
    }
    catch (...) {

    }
    piecesAdded.push_back(std::make_shared<Bishop>(pieceColour::WHITE, 7, 2, pieceName::BISHOP, bishopIconWhite));
    piecesAdded.push_back(std::make_shared<Bishop>(pieceColour::BLACK, 0, 5, pieceName::BISHOP, bishopIconBlack));
    piecesAdded.push_back(std::make_shared<Bishop>(pieceColour::WHITE, 7, 5, pieceName::BISHOP, bishopIconWhite));
    piecesAdded.push_back(std::make_shared<Bishop>(pieceColour::BLACK, 0, 2, pieceName::BISHOP, bishopIconBlack));

    piecesAdded.push_back(std::make_shared<Pawn>(pieceColour::WHITE, 6, 0, pieceName::PAWN, pawnIconWhite));
    piecesAdded.push_back(std::make_shared<Pawn>(pieceColour::WHITE, 6, 1, pieceName::PAWN, pawnIconWhite));
    piecesAdded.push_back(std::make_shared<Pawn>(pieceColour::WHITE, 6, 2, pieceName::PAWN, pawnIconWhite));
    piecesAdded.push_back(std::make_shared<Pawn>(pieceColour::WHITE, 6, 3, pieceName::PAWN, pawnIconWhite));
    piecesAdded.push_back(std::make_shared<Pawn>(pieceColour::WHITE, 6, 4, pieceName::PAWN, pawnIconWhite));
    piecesAdded.push_back(std::make_shared<Pawn>(pieceColour::WHITE, 6, 5, pieceName::PAWN, pawnIconWhite));
    piecesAdded.push_back(std::make_shared<Pawn>(pieceColour::WHITE, 6, 6, pieceName::PAWN, pawnIconWhite));
    piecesAdded.push_back(std::make_shared<Pawn>(pieceColour::WHITE, 6, 7, pieceName::PAWN, pawnIconWhite));

    piecesAdded.push_back(std::make_shared<Pawn>(pieceColour::BLACK, 1, 0, pieceName::PAWN, pawnIconBlack));
    piecesAdded.push_back(std::make_shared<Pawn>(pieceColour::BLACK, 1, 1, pieceName::PAWN, pawnIconBlack));
    piecesAdded.push_back(std::make_shared<Pawn>(pieceColour::BLACK, 1, 2, pieceName::PAWN, pawnIconBlack));
    piecesAdded.push_back(std::make_shared<Pawn>(pieceColour::BLACK, 1, 3, pieceName::PAWN, pawnIconBlack));
    piecesAdded.push_back(std::make_shared<Pawn>(pieceColour::BLACK, 1, 4, pieceName::PAWN, pawnIconBlack));
    piecesAdded.push_back(std::make_shared<Pawn>(pieceColour::BLACK, 1, 5, pieceName::PAWN, pawnIconBlack));
    piecesAdded.push_back(std::make_shared<Pawn>(pieceColour::BLACK, 1, 6, pieceName::PAWN, pawnIconBlack));
    piecesAdded.push_back(std::make_shared<Pawn>(pieceColour::BLACK, 1, 7, pieceName::PAWN, pawnIconBlack));

    piecesAdded.push_back(std::make_shared<Rook>(pieceColour::WHITE, 7, 0, pieceName::ROOK, rookIconWhite));
    piecesAdded.push_back(std::make_shared<Rook>(pieceColour::WHITE, 7, 7, pieceName::ROOK, rookIconWhite));
    piecesAdded.push_back(std::make_shared<Rook>(pieceColour::BLACK, 0, 0, pieceName::ROOK, rookIconBlack));
    piecesAdded.push_back(std::make_shared<Rook>(pieceColour::BLACK, 0, 7, pieceName::ROOK, rookIconBlack));

    piecesAdded.push_back(std::make_shared<Knight>(pieceColour::WHITE, 7, 1, pieceName::KNIGHT, knightIconWhite));
    piecesAdded.push_back(std::make_shared<Knight>(pieceColour::WHITE, 7, 6, pieceName::KNIGHT, knightIconWhite));
    piecesAdded.push_back(std::make_shared<Knight>(pieceColour::BLACK, 0, 1, pieceName::KNIGHT, knightIconBlack));
    piecesAdded.push_back(std::make_shared<Knight>(pieceColour::BLACK, 0, 6, pieceName::KNIGHT, knightIconBlack));

    piecesAdded.push_back(std::make_shared<Queen>(pieceColour::WHITE, 7, 3, pieceName::QUEEN, queenIconWhite));
    piecesAdded.push_back(std::make_shared<Queen>(pieceColour::BLACK, 0, 3, pieceName::QUEEN, queenIconBlack));

    for (auto& piece : piecesAdded) 
    {
		chessBoard->addPieces(piece);
	}

    {
        RAII raii(chessBoard);
    }

    // Create a widget
    QWidget* widget = new QWidget();
    // Set the grid layout as a main layout
    widget->setLayout(chessBoard.get());
    // Window title
    widget->setWindowTitle("Chess Game");

    widget->show();
    return a.exec();
}
