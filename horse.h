#ifndef HORSE_H
#define HORSE_H

#include "chesspiece.h"
class Horse:public ChessPiece
{
public:
    Horse(QString team,QGraphicsItem *parent = 0);
    void setImage();

    void move();

};

#endif // HORSE_H
