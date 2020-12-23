#ifndef TOWER_H
#define TOWER_H
#include "chesspiece.h"
class Tower:public ChessPiece
{
public:
    Tower(QString team, QGraphicsItem *parent = 0);

    void setImage();
    void move();

};

#endif // TOWER_H
