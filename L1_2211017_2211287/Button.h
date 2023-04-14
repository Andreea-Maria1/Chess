#pragma once

#include <iostream>
#include <QPushButton>
#include <Qsize>
#include <memory>
#include "Piece.h"
#include "Square.h"

class Button : public QPushButton {
    Q_OBJECT

public:
    Button(/*std::shared_ptr<Square> square,*/ int x = 0, int y = 0, QWidget* parent = nullptr);
    //std::shared_ptr<Square> getSquare() const;
    ~Button() = default;

public slots:
    void handleClick();

private:
    //std::shared_ptr<Square> square_;
    QPoint pos_;

};