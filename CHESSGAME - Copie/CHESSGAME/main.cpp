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

using namespace pieceName;
using namespace png;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    CHESSGAME w;
    
    std::shared_ptr<ChessBoard> chessBoard = std::make_shared<ChessBoard>();
    std::vector<std::shared_ptr<Piece>> piecesAdded;
    try 
    {
    piecesAdded.push_back(std::make_shared<King>(PieceColour::WHITE, 7, 4, KING, kingIconWhite));
    piecesAdded.push_back(std::make_shared<King>(PieceColour::BLACK, 0, 4, KING, kingIconBlack));
    }
    catch (...) {

    }
    piecesAdded.push_back(std::make_shared<Bishop>(PieceColour::WHITE, 7, 2, BISHOP, bishopIconWhite));
    piecesAdded.push_back(std::make_shared<Bishop>(PieceColour::BLACK, 0, 5, BISHOP, bishopIconBlack));
    piecesAdded.push_back(std::make_shared<Bishop>(PieceColour::WHITE, 7, 5, BISHOP, bishopIconWhite));
    piecesAdded.push_back(std::make_shared<Bishop>(PieceColour::BLACK, 0, 2, BISHOP, bishopIconBlack));

    piecesAdded.push_back(std::make_shared<Pawn>(PieceColour::WHITE, 6, 0, PAWN, pawnIconWhite));
    piecesAdded.push_back(std::make_shared<Pawn>(PieceColour::WHITE, 6, 1, PAWN, pawnIconWhite));
    piecesAdded.push_back(std::make_shared<Pawn>(PieceColour::WHITE, 6, 2, PAWN, pawnIconWhite));
    piecesAdded.push_back(std::make_shared<Pawn>(PieceColour::WHITE, 6, 3, PAWN, pawnIconWhite));
    piecesAdded.push_back(std::make_shared<Pawn>(PieceColour::WHITE, 6, 4, PAWN, pawnIconWhite));
    piecesAdded.push_back(std::make_shared<Pawn>(PieceColour::WHITE, 6, 5, PAWN, pawnIconWhite));
    piecesAdded.push_back(std::make_shared<Pawn>(PieceColour::WHITE, 6, 6, PAWN, pawnIconWhite));
    piecesAdded.push_back(std::make_shared<Pawn>(PieceColour::WHITE, 6, 7, PAWN, pawnIconWhite));

    piecesAdded.push_back(std::make_shared<Pawn>(PieceColour::BLACK, 1, 0, PAWN, pawnIconBlack));
    piecesAdded.push_back(std::make_shared<Pawn>(PieceColour::BLACK, 1, 1, PAWN, pawnIconBlack));
    piecesAdded.push_back(std::make_shared<Pawn>(PieceColour::BLACK, 1, 2, PAWN, pawnIconBlack));
    piecesAdded.push_back(std::make_shared<Pawn>(PieceColour::BLACK, 1, 3, PAWN, pawnIconBlack));
    piecesAdded.push_back(std::make_shared<Pawn>(PieceColour::BLACK, 1, 4, PAWN, pawnIconBlack));
    piecesAdded.push_back(std::make_shared<Pawn>(PieceColour::BLACK, 1, 5, PAWN, pawnIconBlack));
    piecesAdded.push_back(std::make_shared<Pawn>(PieceColour::BLACK, 1, 6, PAWN, pawnIconBlack));
    piecesAdded.push_back(std::make_shared<Pawn>(PieceColour::BLACK, 1, 7, PAWN, pawnIconBlack));

    piecesAdded.push_back(std::make_shared<Rook>(PieceColour::WHITE, 7, 0, ROOK, rookIconWhite));
    piecesAdded.push_back(std::make_shared<Rook>(PieceColour::WHITE, 7, 7, ROOK, rookIconWhite));
    piecesAdded.push_back(std::make_shared<Rook>(PieceColour::BLACK, 0, 0, ROOK, rookIconBlack));
    piecesAdded.push_back(std::make_shared<Rook>(PieceColour::BLACK, 0, 7, ROOK, rookIconBlack));

    piecesAdded.push_back(std::make_shared<Knight>(PieceColour::WHITE, 7, 1, KNIGHT, knightIconWhite));
    piecesAdded.push_back(std::make_shared<Knight>(PieceColour::WHITE, 7, 6, KNIGHT, knightIconWhite));
    piecesAdded.push_back(std::make_shared<Knight>(PieceColour::BLACK, 0, 1, KNIGHT, knightIconBlack));
    piecesAdded.push_back(std::make_shared<Knight>(PieceColour::BLACK, 0, 6, KNIGHT, knightIconBlack));

    piecesAdded.push_back(std::make_shared<Queen>(PieceColour::WHITE, 7, 3, QUEEN, queenIconWhite));
    piecesAdded.push_back(std::make_shared<Queen>(PieceColour::BLACK, 0, 3, QUEEN, queenIconBlack));
 

    for (auto& piece : piecesAdded) {
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
