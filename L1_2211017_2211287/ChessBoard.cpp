#include "ChessBoard.h"

ChessBoard::ChessBoard(/*Controller* controller,*/ QWidget* parent) : QGridLayout(parent)
{
	//controller_ = controller;
	initialisation();
}

void ChessBoard::initialisation()
{
	//Initialisation du plateau de jeu
	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 8; j++)
		{
			//std::shared_ptr<Square> square = std::make_shared<Square>();
			//std::shared_ptr<Button> button = std::make_shared<Button>(square, i, j);
			Button* button = new Button(/*square,*/ i, j);
			button->setStyleSheet("background-color: rgba(100,156,189,1); margin: -10px;");

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
			addWidget(button, i, j, 1, 1);
		}
	}
}


void ChessBoard::movePieces(int x, int y, int newx, int newy)
{
	/*if (board_[x][y] != nullptr) 
	{
		if (board_[x][y]->validmove()) 
		{
			board_[newx][newy] = board_[x][y];
			board_[x][y] = nullptr;
		}
	}*/
}

void ChessBoard::addPieces(std::shared_ptr<Piece> piece)
{
	/*board_[piece->getx()][piece->gety()] = piece;*/
}

void ChessBoard::removePieces(std::shared_ptr<Piece> piece)
{
	/*board_[piece->getx()][piece->gety()] = nullptr;*/
}
