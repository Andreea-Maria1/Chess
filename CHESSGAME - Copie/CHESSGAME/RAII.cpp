/*
* Chess Game.
* \file   RAII.cpp
* \author Andreea Maria Ghioltan et Maria Bourouisa
* \date   20 avril 2023
* Créé le 10 avril 2023
*/

#include "RAII.h"

RAII::RAII(std::shared_ptr<ChessBoard> board) : chessBoard_(board) {
	piece_ = std::make_unique<Bishop>(PieceColour::WHITE, 3, 4, BISHOP, bishopIconWhite);
	for (std::shared_ptr <Button> button : chessBoard_->getListOfButton()) {
		if (button->getPosX() == piece_->getX() && button->getPosY() == piece_->getY()) {
			button->setPiece(piece_);
			chessBoard_->addPieces(piece_);
		}
		
	}
}

RAII::~RAII() {
	for (std::shared_ptr <Button> button : chessBoard_->getListOfButton()) {
		if (button->getPosX() == piece_->getX() && button->getPosY() == piece_->getY()) {
			button->setPiece(nullptr);
		}

	}
}