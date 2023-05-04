/*
* Chess Game.
* \file   Button.cpp
* \author Andreea Maria Ghioltan et Maria Bourouisa
* \date   20 avril 2023
* Créé le 10 avril 2023
*/

#include "Button.h"
#include "ChessBoard.h"

Button::Button(int x, int y, std::shared_ptr<ChessBoard> chessBoard, QWidget* parent) : positionButton_(x, y), chessBoard_(chessBoard), QPushButton(parent)
{
	setIconSize(QSize(90, 90));
	setFixedSize(100, 100);
	connect(this, SIGNAL(clicked()), this, SLOT(handleButton()));
}


void Button::setPiece(std::shared_ptr<Piece> piece)
{
	pieceOfButton_ = piece;
	if (piece == nullptr) {
		setIcon(QIcon());
		return;
	}
	setIcon(QIcon(QString(piece->getIcon())));
	piece->setPos(positionButton_.x, positionButton_.y);
}

std::shared_ptr<Piece> Button::getPiece() const
{
	return pieceOfButton_;
}

Position Button::getPositionButton() const
{
	return positionButton_;
}

void Button::handleButton()
{
	chessBoard_->click(this);
}

void Button::setBaseColor(std::string colour)
{
	baseColour_ = colour;
}

std::string Button::getBaseColor() const
{
	return baseColour_;
}