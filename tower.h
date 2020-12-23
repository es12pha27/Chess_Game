#ifndef TOWER_H
#define TOWER_H
#include "Piece.h"
class Tower:public Piece
{
public:
    Tower(QString team, QGraphicsItem *parent = 0);

    void setImage();
    void move();

};

#endif // TOWER_H
