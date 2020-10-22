#include "Board.h"
#include "ui_Board.h"
#include "Piece.h"

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
    BoardIcon.load("C:/Users/Luis/Documents/Prueba_2/Imagenes/tablero.png");
    //BoardIcon.scaled(QSize(90,90),Qt::KeepAspectRatio);

    piece = std::make_unique<Piece>(this);
    //piece->setText("Test");

    piece->move(40,43);
    piece->show();
}

Board::~Board()
{
    delete ui;
}
void Board::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),width(),BoardIcon);
}
