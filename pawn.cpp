#include "pawn.h"

pawn::pawn(QWidget *parent ):Piece(parent)
{
    PieceIcon.load("C:/Users/Estephany/Documents/Proyecto/img/reina.png");
    this->setPixmap(PieceIcon.scaled(QSize(50,50),Qt::KeepAspectRatio));
}
