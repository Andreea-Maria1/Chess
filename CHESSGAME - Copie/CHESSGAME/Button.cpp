/*
* Chess Game.
* \file   Button.cpp
* \author Andreea Maria Ghioltan et Maria Bourouisa
* \date   20 avril 2023
* Créé le 10 avril 2023
*/

#include "Button.h"

Button::Button( int x, int y, QWidget* parent) : posX_(x), posY_(y), QPushButton(parent)
{
	setIconSize(QSize(90, 90));
	setFixedSize(100, 100);
	connect(this, SIGNAL(clicked()), this, SLOT(handleClick()));
}

void Button::handleClick() {
	
}

void Button::setPiece(std::shared_ptr<Piece> piece) {
	pieceOfSquare_ = piece;
	if (piece == nullptr) {
		setIcon(QIcon());
		return;
	}
	setIcon(QIcon(QString(piece->getIcon())));
	piece->setPos(posX_, posY_);
}

std::shared_ptr<Piece> Button::getPiece() const {
	return pieceOfSquare_;
}

int Button::getPosX() const {
	return posX_;
}

int Button::getPosY() const {
	return posY_;
}