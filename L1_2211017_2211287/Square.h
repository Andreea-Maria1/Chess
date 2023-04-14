#pragma once
#include <QPushButton>
#include <Qsize>
#include <memory>
#include "Piece.h"

class Square
{
public:
    Square() = default;
    Square(std::shared_ptr<Piece> piece);
    std::shared_ptr<Piece> getPiece() const;
    void setPiece(std::shared_ptr<Piece> piece);
private:
    std::shared_ptr<Piece> piece_ = nullptr;
};
