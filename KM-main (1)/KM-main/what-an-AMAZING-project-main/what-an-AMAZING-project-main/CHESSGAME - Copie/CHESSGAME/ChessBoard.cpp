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
ChessBoard::ChessBoard(ChessBoard* chessBoard) 
{
	listOfButton_ = chessBoard->getListOfButton();
	listOfPieces_ = chessBoard->getlistOfPieces();
}

void ChessBoard::initialisation()
{
	std::shared_ptr<ChessBoard> chessBoard = std::make_shared<ChessBoard>(this);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::shared_ptr<Button> button = std::make_shared<Button>(i, j, chessBoard);
			button->setStyleSheet("background-color: rgba(100,156,189,1); margin: -10px;");
			//button->color(blue)
			listOfButton_.push_back(button);
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
				{
					button->setStyleSheet("background-color: rgba(255,250,240,1); margin: -10px;");
					//button->color(white)
				}
			}
			else
			{
				if (j % 2 != 0)
				{
					button->setStyleSheet("background-color: rgba(255,250,240,1); margin: -10px;");
					//button->color(white)
				}
			}
			addWidget(button.get(), i, j, 1, 1);
		}

	}
}

void ChessBoard::movePiece(Position newPosition, std::shared_ptr<Piece> piece)
{
	if (piece->isValidMove(newPosition) && isPositionEmpty)
	{
		piece->setPos(newPosition.x, newPosition.y);
	}
}

void ChessBoard::addPieces(std::shared_ptr<Piece> piece)
{
	listOfPieces_.push_back(piece);
	for (std::shared_ptr<Button> button : listOfButton_)
	{
		if (button->getPositionButton().x == piece->getPositionPiece().x && button->getPositionButton().y == piece->getPositionPiece().y)
		{
			button->setPiece(piece);
			isPositionEmpty = false;
		}
	}
}

void ChessBoard::removePiece(std::shared_ptr<Piece> piece, Position newPosition)
{
	//if (piece->isValidMove(newPosition) && !isPositionEmpty)
	//{
	//	piece->setPos(newPosition.x, newPosition.y);
	//	isPositionEmpty = true;
	//}
}

void ChessBoard::deleteSpacing() {
	setHorizontalSpacing(0);
	setVerticalSpacing(0);
}

std::vector<std::shared_ptr<Button>> ChessBoard::getListOfButton() const
{
	return listOfButton_;
}

std::vector<std::shared_ptr<Piece>> ChessBoard::getlistOfPieces() const
{
	return listOfPieces_;
}


void ChessBoard::changeColourValidMove(Position newPosition)
{
	for (auto&& button : listOfButton_)
	{
		if (button.get()->getPiece()->isValidMove(newPosition))
		{
			button->setStyleSheet("background-color: rgba(255,255,153,1); margin: -10px;");
		}
	}
}

void ChessBoard::click(Button* button) {
	// select piece you want to play
	if (clickedPiece_ == nullptr)
	{
		if (button->getPiece() != nullptr)
		{
			clickedPiece_ = button->getPiece();
			clickedButton_ = button;
			clickedButton_->setStyleSheet("background-color: rgba(102,102,0,1); margin: -10px;");
			//filters 
			//changeColourValidMove(newPosition);
		}
		// select new position
	}
	else
	{
		//movePiece(button->getPositionButton(), clickedPiece_); //change to movePiece afterwards,
		button->setPiece(clickedPiece_);
		button->setIcon(QIcon(clickedPiece_->getIcon()));
		clickedButton_-> setIcon(QIcon(""));
		clickedButton_->setPiece(nullptr);
		//clickedButton_->setStyleSheet(button->getBaseColor());
		clickedPiece_ = nullptr;
		clickedPiece_ = nullptr;
		
	}
}
	