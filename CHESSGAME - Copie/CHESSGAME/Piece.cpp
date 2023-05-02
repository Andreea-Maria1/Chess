/*
* Chess Game.
* \file   Piece.cpp
* \author Andreea Maria Ghioltan et Maria Bourouisa
* \date   20 avril 2023
* Créé le 10 avril 2023
*/

#include "Piece.h"

Piece::Piece(PieceColour colour, int x, int y, std::string name, QString icon)	:	name_(name),
																					x_(x),
																					y_(y),
																					colour_(colour),	
																					icon_(icon) {}


void Piece::setPos(int newX, int newY)
{
	x_ = newX;
	y_ = newY;
}

Pawn::Pawn(PieceColour colour, int x, int y, std::string name, QString icon)
	: Piece(colour, x, y, name, icon)
{
}

void Pawn::behaviour() const
{
}

Rook::Rook(PieceColour colour, int x, int y, std::string name, QString icon)
	: Piece(colour, x, y, name, icon)
{
}

void Rook::behaviour() const
{
}

Bishop::Bishop(PieceColour colour, int x, int y, std::string name, QString icon)
	: Piece(colour, x, y, name, icon)
{
}

void Bishop::behaviour() const
{
}

King::King(PieceColour colour, int x, int y, std::string name, QString icon)
	: Piece(colour, x, y, name, icon)
{
	count_ += 1;
	if(count_ >2){
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

Queen::Queen(PieceColour colour, int x, int y, std::string name, QString icon)
	: Piece(colour, x, y, name, icon)
{
}

void Queen::behaviour() const
{
}

Knight::Knight(PieceColour colour, int x, int y, std::string name, QString icon)
	: Piece(colour, x, y, name, icon)
{
}

void Knight::behaviour() const
{
}

