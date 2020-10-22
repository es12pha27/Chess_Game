#include "board.h"
#include "ui_board.h"


Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
   BoardIcon.load("/Documents/Ajedrez_Prueba/Imagenes/tablero.png");

}

Board::~Board()
{
    delete ui;
}

void Board::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),width(),BoardIcon);
}
