/*
* Chess Game.
* \file   RAII.h
* \author Andreea Maria Ghioltan et Maria Bourouisa
* \date   20 avril 2023
* Créé le 10 avril 2023
*/

#pragma once

#include <memory>
#include "Piece.h"
#include "ChessBoard.h"

class RAII {
public:
	RAII(std::shared_ptr<ChessBoard> board);
	~RAII();
private:
	std::shared_ptr<ChessBoard> chessBoard_;
	std::shared_ptr<Piece> piece_;
};
