#ifndef Knight_H
#define Knight_H

#include "Piece.h"
class Knight:public Piece
{
public:
    Knight(QString team,QGraphicsItem *parent = 0);
    void setImage();

    void move();

};

#endif // Knight_H
