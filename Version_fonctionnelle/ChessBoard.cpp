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
			std::shared_ptr<Button> button = std::make_shared<Button>(i, j);
			button->setStyleSheet("background-color: rgba(100,156,189,1); margin: -10px;");
			button->setBaseColour("blue");

			listOfButton_.push_back(button);

			if (i % 2 == 0)
			{
				if (j % 2 == 0)
				{
					button->setStyleSheet("background-color: rgba(255,250,240,1); margin: -10px;");
					button->setBaseColour("white;");
				}
			}
			else
			{
				if (j % 2 != 0)
				{
					button->setStyleSheet("background-color: rgba(255,250,240,1); margin: -10px;");
					button->setBaseColour("white;");
				}
			}
			addWidget(button.get(), i, j, 1, 1);
			connect(button.get(), &QPushButton::clicked, this, [this, button]() {this->click(button.get()); });
		}
	}
	chessBoard->listOfButton_ = listOfButton_;
}

void ChessBoard::addPieces(std::shared_ptr<Piece> piece)
{
	listOfPieces_.push_back(piece);
	for (std::shared_ptr<Button> button : listOfButton_)
	{
		if (button->getPositionButton() == piece->getPositionPiece())
		{
			button->setPiece(piece);
		}
	}
}

bool ChessBoard::isSameColour(Piece* p1, Piece* p2) const
{
	return p1->isWhite() == p2->isWhite();
}

Button* ChessBoard::getButton(Position position) const
{
	return getButton(position, listOfButton_);
}

Button* ChessBoard::getButton(Position position, std::vector<std::shared_ptr<Button>> listOfButton) const
{
	for (auto&& button : listOfButton)
	{
		if (button->getPositionButton() == position)
		{
			return button.get();
		}
	}
	return nullptr;
}

bool ChessBoard::isSomethingInWay(Position initialPosition, Position finalPosition) const 
{
	if (movementManagement::isVertical(initialPosition, finalPosition))
	{
		Position highestPosition = (initialPosition.y < finalPosition.y) ? initialPosition : finalPosition;
		Position lowestPosition = (initialPosition.y > finalPosition.y) ? initialPosition : finalPosition;

		const int x = highestPosition.x;

		for (int y = highestPosition.y + 1; y < lowestPosition.y; y++) 
		{
			auto currentButton = getButton({ x, y });

			if (currentButton->getPiece() != nullptr)
			{
				return true;
			}
		}
	}
	else if (movementManagement::isHorizontal(initialPosition, finalPosition))
	{
		Position leftPosition = (initialPosition.x < finalPosition.x) ? initialPosition : finalPosition;
		Position rightPosition = (initialPosition.x > finalPosition.x) ? initialPosition : finalPosition;

		const int y = leftPosition.y;

		for (int x = leftPosition.x + 1; x < rightPosition.x; x++)
		{
			auto currentButton = getButton({x, y});
			if (currentButton->getPiece() != nullptr) 
			{
				return true;
			}
		}

	}
	else
	{
		int xIncrement = (finalPosition.x > initialPosition.x) ? 1 : -1;
		int yIncrement = (finalPosition.y > initialPosition.y) ? 1 : -1; 

		int x = initialPosition.x + xIncrement;
		int y = initialPosition.y + yIncrement;

		while(x != finalPosition.x && y != finalPosition.y)
		{
			auto currentButton = getButton({x, y});
			if (currentButton->getPiece() != nullptr)
			{
				return true;
			}
			x += xIncrement;
			y += yIncrement;
		}
	}
	return false;
}

Button* ChessBoard::getKingButton(bool searchWhite) const
{

	for (auto&& button : listOfButton_) 
	{
		std::shared_ptr<Piece> buttonPiece = button->getPiece();

		if (buttonPiece && dynamic_cast<King*>(buttonPiece.get()) && buttonPiece->isWhite() == searchWhite)
		{
			return button.get();
		}
	}
	return nullptr;
}

bool ChessBoard::putsKingInDanger(Button* initialButton, Button* finalButton)
{
	std::shared_ptr<Piece> piece = initialButton->getPiece();

	auto meal = finalButton->getPiece();
	finalButton->setPiece(initialButton->getPiece());
	removePiece(initialButton);

	auto kingButton = getKingButton(piece->isWhite());

	bool isCheck = false;

	for (auto&& button : listOfButton_) 
	{
		if (button->getPiece() == nullptr || isSameColour(button->getPiece().get(), kingButton->getPiece().get()))
		{
			continue;
		}

		else if (isMovePossible(button.get(), kingButton))
		{
			isCheck = true;
		}
	}

	initialButton->setPiece(finalButton->getPiece());

	if (meal) 
	{
		finalButton->setPiece(meal);
	}
	else
	{
		removePiece(finalButton);
	}

	return isCheck;
}

bool ChessBoard::isMovePossible(Button* initialButton, Button* finalButton) 
{
	std::shared_ptr<Piece> piece = initialButton->getPiece();
	std::shared_ptr<Piece> meal = finalButton->getPiece();
	Position initialPosition = initialButton->getPositionButton();
	Position newPosition = finalButton->getPositionButton();

	bool isEatingTeammate = meal != nullptr && isSameColour(piece.get(), meal.get());

	return 	!isEatingTeammate && 
			!isSomethingInWay(initialPosition, newPosition) &&
			piece->isValidMove(newPosition);
}

bool ChessBoard::movePiece(Button* initialButton, Button* finalButton)
{
	std::shared_ptr<Piece> piece = initialButton->getPiece();

	if (piece != nullptr && isMovePossible(initialButton, finalButton) && !putsKingInDanger(initialButton, finalButton))
	{
		finalButton->setIcon(QIcon(piece->getIcon()));
		finalButton->setPiece(piece);
		removePiece(initialButton);
		return true;
	}
	return false;
}

void ChessBoard::removePiece(Button* button)
{
	button->setIcon(QIcon(""));
	button->resetColour();
	button->setPiece(nullptr);
}

void ChessBoard::deleteSpacing() 
{
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
	auto piece = lastClickedButton_->getPiece();

	for (auto&& button : listOfButton_)
	{	
		if (button->getPositionButton() == newPosition) {
			continue;
		}
		else if (isMovePossible(lastClickedButton_, button.get()) && !putsKingInDanger(lastClickedButton_, button.get()))
		{
			setButtonGreen(button.get());
		}
	}
	setButtonGrey(lastClickedButton_);
}

void ChessBoard::resetColoursBoard()
{
	for (auto&& button : listOfButton_)
		button->resetColour();
}

void ChessBoard::setButtonRed(Button* button) const
{
	button->setStyleSheet("background-color: rgba(230,67,67,1); margin: -10px;");
}

void ChessBoard::setButtonGrey(Button* button) const
{
	lastClickedButton_->setStyleSheet("background-color: rgba(156,152,152,1); margin: -10px;");
}

void ChessBoard::setButtonGreen(Button* button) const
{
	button->setStyleSheet("background-color: rgba(165,250,85,1); margin: -10px;");
}

void ChessBoard::click(Button* button) 
{
	resetColoursBoard();

	bool isFirstClick = lastClickedButton_ == nullptr;

	if (isFirstClick) {
		if (button->getPiece() == nullptr || button->getPiece()->isWhite() != isWhiteTurn_) 
		{
			return;
		}
		else 
		{
			lastClickedButton_ = button;
			changeColourValidMove(lastClickedButton_->getPositionButton());
		}
	}
	else {

		if (button->getPiece() && isSameColour(button->getPiece().get(), lastClickedButton_->getPiece().get())) 
		{
			lastClickedButton_ = button;
			changeColourValidMove(lastClickedButton_->getPositionButton());
			return;
		}

		if (lastClickedButton_->getPositionButton() == button->getPositionButton())
		{
			return;
		}

		bool moveSuccessful = movePiece(lastClickedButton_, button);

		if (moveSuccessful) 
		{
			isWhiteTurn_ = !isWhiteTurn_;
		}
		else 
		{
			setButtonRed(button);
		}

		lastClickedButton_ = nullptr;
	}
}
