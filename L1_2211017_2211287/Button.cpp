#include "Button.h"

Button::Button(/*std::shared_ptr<Square> square,*/ int x, int y, QWidget* parent) : /*square_(square), */pos_(x, y), QPushButton(parent)
{
	setFixedSize(100, 100);
	connect(this, SIGNAL(clicked()), this, SLOT(handleClick()));
}/*
std::shared_ptr<Square> Button::getSquare() const {
	return square_; 
}*/

void Button::handleClick() {
	
}