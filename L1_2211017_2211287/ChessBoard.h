#pragma once

#ifndef CHESSBOARD_H
#include <QPushButton>
#include <QGridLayout>
#include <QtWidgets/QMainWindow>
#include <vector>
#include <memory>
#include "Piece.h"
#include "Button.h"

class ChessBoard : public QGridLayout {
public:
    ChessBoard(/*Controller* controller,*/ QWidget* parent = nullptr);
    ~ChessBoard() = default;
    void initialisation();
    void addPieces(std::shared_ptr<Piece> piece);
    void removePieces(std::shared_ptr<Piece> piece);
    void movePieces(int x, int y, int newX, int newY);

private:
    std::vector<std::vector<std::shared_ptr<Square>>> squares_;
    std::vector<std::shared_ptr<Button>> listOfButton_;
    std::vector<std::shared_ptr<Piece>> listOfPieces_;
    std::shared_ptr<Square> board_[8][8];
};

#endif // CHESSBOARD_H