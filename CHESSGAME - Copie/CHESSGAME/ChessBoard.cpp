/*
* Chess Game.
* \file   ChessBoard.cpp
* \author Andreea Maria Ghioltan et Maria Bourouisa
* \date   20 avril 2023
* Créé le 10 avril 2023
*/

#include "ChessBoard.h"

ChessBoard::ChessBoard(QWidget* parent) : QGridLayout(parent)
{
	setSizeConstraint(QLayout::SetMinAndMaxSize);
	initialisation();
	deleteSpacing();

}

void ChessBoard::initialisation()
{
	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 8; j++)
		{
			std::shared_ptr<Button> button = std::make_shared<Button>(i, j);
			button->setStyleSheet("background-color: rgba(100,156,189,1); margin: -10px;");
			listOfButton_.push_back(button);	
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
				{
					button->setStyleSheet("background-color: rgba(255,250,240,1); margin: -10px;");
				}
			}
			else
			{
				if (j % 2 != 0)
				{
					button->setStyleSheet("background-color: rgba(255,250,240,1); margin: -10px;");
				}
			}
			addWidget(button.get(), i, j, 1, 1);
		}
		
	}
}

void ChessBoard::movePieces(int x, int y, int newx, int newy)
{
}

void ChessBoard::addPieces(std::shared_ptr<Piece> piece)
{
	listOfPieces_.push_back(piece);
	for (std::shared_ptr<Button> button : listOfButton_)
	{
		if (button->getPositionButton().x == piece->getPositionPiece().x && button->getPositionButton().y == piece->getPositionPiece().y)
			{
			button->setPiece(piece);
			} 
	}

}

void ChessBoard::removePieces(std::shared_ptr<Piece> piece)
{
}

void ChessBoard::deleteSpacing() {
	setHorizontalSpacing(0);
	setVerticalSpacing(0);
}

std::vector<std::shared_ptr<Button>> ChessBoard::getListOfButton() const
{
	return listOfButton_;
}

