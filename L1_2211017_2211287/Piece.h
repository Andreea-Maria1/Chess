#pragma once

#include <iostream>
#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include <QGridLayout>

enum class PieceName {
	KING,
	BISHOP,
	ROOK
};

enum class PieceColour {
	WHITE,
	BLACK
};

class Piece {

public:
	virtual ~Piece() = default;
	Piece(PieceColour colour, int x, int y, PieceName name);
	virtual void behaviour() const = 0;
	void setPos(int newX, int newY);
	bool validMove() { return movement_(x_, y_); };
	//void affichage(); // affiche les pieces

	QString getIcon() { return icon_; };
	int getX() { return x_; };
	int getY() { return y_; };

protected:
	PieceName name_;
	PieceColour colour_;
	QString icon_;
	std::function<bool(int x, int y)> movement_;
	int x_;
	int y_;
};

class Rook : public Piece {
public:
	Rook() = default;
	Rook(PieceColour colour, int x, int y);
	void behaviour() const override;
};

class Bishop : public Piece {
public:
	Bishop() = default;
	Bishop(PieceColour colour, int x, int y);
	void behaviour() const override;
};

class King : public Piece {
public:
	King() = default;
	King(PieceColour colour, int x, int y);
	void behaviour() const override;
};