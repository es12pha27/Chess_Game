#include "Piece.h"

 Piece::Piece(QWidget *parent): QLabel(parent)
{
 PieceIcon.load("C:/Users/Luis/Documents/Prueba_2/Imagenes/CaballoNegro.png");
 this->setPixmap(PieceIcon.scaled(QSize(35,35),Qt::KeepAspectRatio));
}
