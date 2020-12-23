#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
class Bishop:public Piece
{
public:
    Bishop(QString team,QGraphicsItem *parent = 0);
    void setImage();
    void move();

};


#endif // BISHOP_H
