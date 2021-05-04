#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
class Pawn:public Piece
{
public:
    Pawn(QString team,QGraphicsItem *parent = 0);
    void setImage();
    void move();

 private:
//Modifique el pawn Del ajedrez Vamos a ver si se modifica
// Juana la cubana esto es un a prueba

};

#endif // PAWN_H
