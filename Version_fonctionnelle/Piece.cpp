/*
* Chess Game.
* \file   Piece.cpp
* \author Andreea Maria Ghioltan et Maria Bourouisa
* \date   20 avril 2023
* Créé le 10 avril 2023
*/
#include "Piece.h"
#include "MovementManager.h"

Piece::Piece(pieceColour colour, int x, int y, pieceName name, QString icon) : name_(name),
																			   positionPiece_(x,y),
																			   colour_(colour),	
																			   icon_(icon) {}

void Piece::setPos(int newX, int newY)
{
	positionPiece_.x = newX;
	positionPiece_.y = newY;
}

bool Piece::isWhite() const
{
	return colour_ == pieceColour::WHITE;
}

Pawn::Pawn(pieceColour colour, int x, int y, pieceName name, QString icon) : Piece(colour, x, y, name, icon) {}

bool Pawn::isValidMove(Position newPosition) const
{
	return true;
}

Rook::Rook(pieceColour colour, int x, int y, pieceName name, QString icon) : Piece(colour, x, y, name, icon) {}

bool Rook::isValidMove(Position newPosition) const
{
	return movementManagement::isCross(newPosition, positionPiece_);
}

Bishop::Bishop(pieceColour colour, int x, int y, pieceName name, QString icon) : Piece(colour, x, y, name, icon) {}

bool Bishop::isValidMove(Position newPosition) const
{
	return movementManagement::isDiagonal(newPosition, positionPiece_);
}

King::King(pieceColour colour, int x, int y, pieceName name, QString icon) : Piece(colour, x, y, name, icon)
{
	count_ += 1;
	if (count_ > 2) 
	{
		QMessageBox msgBox;
		msgBox.setText("More than two Kings added.");
		msgBox.exec();
		throw ("Too many Kings");
	}
}

int King::count_ = 0;

bool King::isValidMove(Position newPosition) const
{
	return movementManagement::isNeighbour(newPosition, positionPiece_);
}

Queen::Queen(pieceColour colour, int x, int y, pieceName name, QString icon) : Piece(colour, x, y, name, icon) {}

bool Queen::isValidMove(Position newPosition) const
{
	return true;
}

Knight::Knight(pieceColour colour, int x, int y, pieceName name, QString icon) : Piece(colour, x, y, name, icon) {}

bool Knight::isValidMove(Position newPosition) const
{
	return true;
}

Position Piece::getPositionPiece() const
{
	return positionPiece_;
}
