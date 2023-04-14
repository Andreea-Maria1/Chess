#include "Square.h"

Square::Square(std::shared_ptr<Piece> piece) : piece_(piece){}

std::shared_ptr<Piece> Square::getPiece() const { return piece_; }

void Square::setPiece(std::shared_ptr<Piece> piece) {
	piece_ = piece;	
}


