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

namespace pieceCharacteristics
{


};

enum class pieceName {
	PIECE,
	KING,
	ROOK,
	BISHOP,
	PAWN,
	QUEEN,
	KNIGHT
};

enum class pieceColour {
	WHITE,
	BLACK
};

namespace png {
	const QString kingIconBlack = "./photos/KingBlack.png";			/*drawing by Artist: Andreea Maria Ghioltan and Maria Bourouisa*/
	const QString kingIconWhite = "./photos/KingWhite.png";         /*drawing by Artist: Andreea Maria Ghioltan and Maria Bourouisa*/
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

class Piece {

public:
	virtual ~Piece() = default;
	Piece(pieceColour colour, int x, int y, pieceName name, QString icon);
	virtual void behaviour() const = 0;
	void setPos(int newX, int newY);
	bool validMove() { return movement_(x_, y_); };
	//void affichage(); // affiche les pieces

	QString getIcon() { return icon_; };
	int getX() { return x_; };
	int getY() { return y_; };

protected:
	pieceName name_;
	pieceColour colour_;
	QString icon_;
	std::function<bool(int x, int y)> movement_;
	int x_;
	int y_;
};

class Rook : public Piece {
public:
	Rook() = default;
	Rook(pieceColour colour, int x, int y, pieceName name, QString icon);
	void behaviour() const override;
};

class Bishop : public Piece {
public:
	Bishop() = default;
	Bishop(pieceColour colour, int x, int y, pieceName name, QString icon);
	void behaviour() const override;
};

class King : public Piece {
public:
	King() = default;
	King(pieceColour colour, int x, int y, pieceName name, QString icon);
	void behaviour() const override;
private:
	static int count_;
};

class Pawn : public Piece {
public:
	Pawn() = default;
	Pawn(pieceColour colour, int x, int y, pieceName name, QString icon);
	void behaviour() const override;
};

class Queen : public Piece {
public:
	Queen() = default;
	Queen(pieceColour colour, int x, int y, pieceName name, QString icon);
	void behaviour() const override;
};

class Knight : public Piece {
public:
	Knight() = default;
	Knight(pieceColour colour, int x, int y, pieceName, QString icon);
	void behaviour() const override;
};
