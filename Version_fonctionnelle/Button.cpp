/*
* Chess Game.
* \file   Button.cpp
* \author Andreea Maria Ghioltan et Maria Bourouisa
* \date   20 avril 2023
* Créé le 10 avril 2023
*/

#include "Button.h"

Button::Button(int x, int y, QWidget* parent) : positionButton_(x, y), QPushButton(parent)
{
	setIconSize(QSize(90, 90));
	setFixedSize(100, 100);
}

void Button::setPiece(std::shared_ptr<Piece> piece)
{
	pieceOnButton_ = piece;
	if (pieceOnButton_ == nullptr) 
	{
		setIcon(QIcon());
		return;
	}
	setIcon(QIcon(QString(piece->getIcon())));
	piece->setPos(positionButton_.x, positionButton_.y);
}

std::shared_ptr<Piece> Button::getPiece() const
{
	return pieceOnButton_;
}

Position Button::getPositionButton() const
{
	return positionButton_;
}

void Button::resetColour()
{
	if (baseColour_ == "blue")
	{
		setStyleSheet("background-color: rgba(100,156,189,1); margin: -10px;");
	}
	else
	{
		setStyleSheet("background-color: rgba(255, 250, 240, 1); margin: -10px;");
	}
}

void Button::setBaseColour(std::string colour)
{
	baseColour_ = colour;
}

std::string Button::getBaseColor() const
{
	return baseColour_;
}