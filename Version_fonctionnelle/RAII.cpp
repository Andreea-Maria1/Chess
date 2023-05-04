/*
* Chess Game.
* \file   RAII.cpp
* \author Andreea Maria Ghioltan et Maria Bourouisa
* \date   20 avril 2023
* Créé le 10 avril 2023
*/

#include "RAII.h"

RAII::RAII(std::shared_ptr<ChessBoard> board) : chessBoard_(board) {
	piece_ = std::make_unique<Bishop>(pieceColour::WHITE, 3, 4, pieceName::BISHOP, png::bishopIconWhite);
	for (std::shared_ptr <Button> button : chessBoard_->getListOfButton()) {
		if (button->getPositionButton().x == piece_->getPositionPiece().x && button->getPositionButton().y == piece_->getPositionPiece().y) {
			button->setPiece(piece_);
			chessBoard_->addPieces(piece_);
		}
		
	}
}

RAII::~RAII() {
	for (std::shared_ptr <Button> button : chessBoard_->getListOfButton()) {
		if (button->getPositionButton().x == piece_->getPositionPiece().x && button->getPositionButton().y == piece_->getPositionPiece().y) {
			button->setPiece(nullptr);
		}

	}
}