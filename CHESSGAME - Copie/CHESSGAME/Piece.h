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

namespace pieceName {
	const std::string PIECE = "PIECE";
	const std::string KING = "KING";
	const std::string ROOK = "ROOK";
	const std::string BISHOP = "BISHOP";
	const std::string PAWN = "PAWN";
	const std::string QUEEN = "QUEEN";
	const std::string KNIGHT = "KNIGHT";
}

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

enum class PieceColour {
	WHITE,
	BLACK
};

class Piece {

public:
	virtual ~Piece() = default;
	Piece(PieceColour colour, int x, int y, std::string name, QString icon);
	virtual void behaviour() const = 0;
	void setPos(int newX, int newY);
	bool validMove() { return movement_(x_, y_); };
	//void affichage(); // affiche les pieces

	QString getIcon() { return icon_; };
	int getX() { return x_; };
	int getY() { return y_; };

protected:
	std::string name_;
	PieceColour colour_;
	QString icon_;
	std::function<bool(int x, int y)> movement_;
	int x_;
	int y_;
};

class Rook : public Piece {
public:
	Rook() = default;
	Rook(PieceColour colour, int x, int y, std::string name, QString icon);
	void behaviour() const override;
};

class Bishop : public Piece {
public:
	Bishop() = default;
	Bishop(PieceColour colour, int x, int y, std::string name, QString icon);
	void behaviour() const override;
};

class King : public Piece {
public:
	King() = default;
	King(PieceColour colour, int x, int y, std::string name, QString icon);
	void behaviour() const override;
private:
	static int count_;
};

class Pawn : public Piece {
	public:
	Pawn() = default;
	Pawn(PieceColour colour, int x, int y, std::string name, QString icon);
	void behaviour() const override;
};

class Queen : public Piece {
public:
	Queen() = default;
	Queen(PieceColour colour, int x, int y, std::string name, QString icon);
	void behaviour() const override;
};

class Knight : public Piece {
	public:
	Knight() = default;
	Knight(PieceColour colour, int x, int y, std::string name, QString icon);
	void behaviour() const override;
};
