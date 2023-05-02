/*
* Chess Game.
* \file   Button.cpp
* \author Andreea Maria Ghioltan et Maria Bourouisa
* \date   20 avril 2023
* Créé le 10 avril 2023
*/

#include "Button.h"

Button::Button(int x, int y, QWidget* parent) : position_(x,y), QPushButton(parent)
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
	piece->setPos(position_.x, position_.y);
}

std::shared_ptr<Piece> Button::getPiece() const {
	return pieceOfSquare_;
}

Position Button::getPosition() const
{
	return position_;
}