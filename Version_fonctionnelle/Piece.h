/*
* Chess Game.
* \file   Piece.h
* \author Andreea Maria Ghioltan et Maria Bourouisa
* \date   20 avril 2023
* Créé le 10 avril 2023
*/

#pragma once

#include <iostream>
#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <qstring.h>
#include <QMessageBox>
#include <string>
#include "Position.h"

enum class pieceName
{
	PIECE,
	KING,
	ROOK,
	BISHOP,
	PAWN,
	QUEEN,
	KNIGHT
};

enum class pieceColour 
{
	WHITE,
	BLACK
};

namespace png 
{
	const QString kingIconBlack = "./photos/KingBlack.png";			 /*drawing by Artist: Andreea Maria Ghioltan and Maria Bourouisa*/
	const QString kingIconWhite = "./photos/KingWhite.png";          /*drawing by Artist: Andreea Maria Ghioltan and Maria Bourouisa*/
	const QString bishopIconWhite = "./photos/BishopWhite.png";      /*drawing by Artist: Andreea Maria Ghioltan and Maria Bourouisa*/
	const QString bishopIconBlack = "./photos/BishopBlack.png";      /*drawing by Artist: Andreea Maria Ghioltan and Maria Bourouisa*/
	const QString pawnIconWhite = "./photos/WhitePawn.png";          /*drawing by Artist: Andreea Maria Ghioltan and Maria Bourouisa*/
	const QString pawnIconBlack = "./photos/BlackPawn.png";          /*drawing by Artist: Andreea Maria Ghioltan and Maria Bourouisa*/
	const QString rookIconWhite = "./photos/RookWhite.png";          /*drawing by Artist: Andreea Maria Ghioltan and Maria Bourouisa*/
	const QString rookIconBlack = "./photos/RookBlack.png";          /*drawing by Artist: Andreea Maria Ghioltan and Maria Bourouisa*/
	const QString queenIconWhite = "./photos/QueenWhite.png";        /*drawing by Artist: Andreea Maria Ghioltan and Maria Bourouisa*/
	const QString queenIconBlack = "./photos/QueenBlack.png";        /*drawing by Artist: Andreea Maria Ghioltan and Maria Bourouisa*/
	const QString knightIconWhite = "./photos/KnightWhite.png";      /*drawing by Artist: Andreea Maria Ghioltan and Maria Bourouisa*/
	const QString knightIconBlack = "./photos/KnightBlack.png";      /*drawing by Artist: Andreea Maria Ghioltan and Maria Bourouisa*/
}

class Piece 
{

public:
	Piece(pieceColour colour, int x, int y, pieceName name, QString icon);
	virtual ~Piece() {}

	virtual bool isValidMove(Position newPosition) const = 0;
	void setPos(int newX, int newY);

	Position getPositionPiece() const;
	QString getIcon() { return icon_; };
	bool isWhite() const;

protected:
	pieceName name_;
	pieceColour colour_;
	QString icon_;
	Position positionPiece_;
};

class Rook : public Piece 
{
public:
	Rook(pieceColour colour, int x, int y, pieceName name, QString icon);
	bool isValidMove(Position newPosition) const override;
};

class Bishop : public Piece 
{
public:
	Bishop(pieceColour colour, int x, int y, pieceName name, QString icon);
	bool isValidMove(Position newPosition) const override;
};

class King : public Piece 
{
public:
	King(pieceColour colour, int x, int y, pieceName name, QString icon);
	~King();
	bool isValidMove(Position newPosition) const override;

private:
	static int count_;
};

class Pawn : public Piece 
{
public:
	Pawn(pieceColour colour, int x, int y, pieceName name, QString icon);
	bool isValidMove (Position newPosition) const override;
};

class Queen : public Piece 
{
public:
	Queen(pieceColour colour, int x, int y, pieceName name, QString icon);
	bool isValidMove(Position newPosition) const override;
};

class Knight : public Piece 
{
public:
	Knight(pieceColour colour, int x, int y, pieceName, QString icon);
	bool isValidMove(Position newPosition) const override;
};
