#include "board.h"
#include "ui_board.h"


Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
  //  BoardIcon.load("C:\Users\Luis\Documents\Ajedrez_Prueba\tablero.jpg");

 //Board.load("C:/Users/Luis/Documents/Ajedrez_Prueba/tablero.jpg");
 //myicon=new QIcon("");

 //QIcon icon("C:/Users/Luis/Documents/Ajedrez_Prueba/tablero.jpg");
 //Board.setWindownIcon(icon);
 // QAction myicon = new QIcon("");




}

Board::~Board()
{
    delete ui;
}

//void Board::paintEvent(QPaintEvent *){
    //QPainter painter
//}
