#include "CHESSGAME.h"

CHESSGAME::CHESSGAME(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //m_button = new QPushButton("My Button", this);                      // Create the button, make "this" the parent
    //m_button->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));     // set size and location of the button

    //connect(m_button, &QPushButton::released, this, &CHESSGAME::handleButton);
    //b_button = new QPushButton("", this);
    //b_button->setGeometry(QRect(QPoint(200, 100), QSize(200, 100)));
}
//
//void CHESSGAME::handleButton()
//{
//    m_button->setText("Example");
//    m_button->resize(100, 100);
//}

