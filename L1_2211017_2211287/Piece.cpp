#include "Piece.h"

Piece::Piece(PieceColour colour, int x, int y, PieceName name)	: name_(name),
																  colour_(colour),
																  x_(x),
																  y_(y)
{
	switch (name_) {
	case PieceName::KING:
		icon_ = "king.png";
		break;
	case PieceName::BISHOP:
		icon_ = "bishop.png";
		break;
	case PieceName::ROOK:
		icon_ = "rook.png";
		break;
	}
}

void Piece::setPos(int newX, int newY)
{
	x_ = newX;
	y_ = newY;
}

Rook::Rook(PieceColour colour, int x, int y)
	: Piece(colour, x, y, PieceName::ROOK)
{
}

void Rook::behaviour() const
{
	// Define the behavior for the Rook piece
}

Bishop::Bishop(PieceColour colour, int x, int y)
	: Piece(colour, x, y, PieceName::BISHOP)
{
}

void Bishop::behaviour() const
{
	// Define the behavior for the Bishop piece
}


King::King(PieceColour colour, int x, int y)
	: Piece(colour, x, y, PieceName::KING)
{
}

void King::behaviour() const
{
	// Define the behavior for the King piece
}