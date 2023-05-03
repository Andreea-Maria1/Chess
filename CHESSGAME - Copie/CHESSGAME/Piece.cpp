/*
* Chess Game.
* \file   Piece.cpp
* \author Andreea Maria Ghioltan et Maria Bourouisa
* \date   20 avril 2023
* Créé le 10 avril 2023
*/

#include "Piece.h"

Piece::Piece(pieceColour colour, int x, int y, pieceName name, QString icon) : name_(name),
																			   positionPiece_(x,y),
																			   colour_(colour),	
																			   icon_(icon) {}


void Piece::setPos(int newX, int newY)
{
	positionPiece_.x = newX;
	positionPiece_.y = newY;
}

Pawn::Pawn(pieceColour colour, int x, int y, pieceName name, QString icon)
	: Piece(colour, x, y, name, icon)
{
}

void Pawn::behaviour() const
{
}

Rook::Rook(pieceColour colour, int x, int y, pieceName name, QString icon)
	: Piece(colour, x, y, name, icon)
{
}

void Rook::behaviour() const
{
}

Bishop::Bishop(pieceColour colour, int x, int y, pieceName name, QString icon)
	: Piece(colour, x, y, name, icon)
{
}

void Bishop::behaviour() const
{
}

King::King(pieceColour colour, int x, int y, pieceName name, QString icon)
	: Piece(colour, x, y, name, icon)
{
	count_ += 1;
	if (count_ > 2) {
		QMessageBox msgBox;
		msgBox.setText("More than two Kings added.");
		msgBox.exec();
		throw ("Too many Kings");
	}
}

int King::count_ = 0;

void King::behaviour() const
{
}

Queen::Queen(pieceColour colour, int x, int y, pieceName name, QString icon)
	: Piece(colour, x, y, name, icon)
{
}

void Queen::behaviour() const
{
}

Knight::Knight(pieceColour colour, int x, int y, pieceName name, QString icon)
	: Piece(colour, x, y, name, icon)
{
}

void Knight::behaviour() const
{
}

Position Piece::getPositionPiece() const
{
	return positionPiece_;
}
