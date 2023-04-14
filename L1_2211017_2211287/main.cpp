#include "CHESSGAME.h"
#include "ChessBoard.h"
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <memory>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    CHESSGAME w;
    //std::shared_ptr<Controller> controller = std::make_shared<Controller>();
    std::shared_ptr<ChessBoard> chessBoard = std::make_shared<ChessBoard>(/*controller*/);

    // Create a widget
    QWidget* widget = new QWidget();
    // Set the grid layout as a main layout
    widget->setLayout(chessBoard.get());
    // Window title
    widget->setWindowTitle("Chess Game");

    widget->show();
    return a.exec();
}
