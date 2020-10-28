#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"

class pawn:public Piece
{
public:
    explicit pawn(QWidget *parent );
    virtual ~pawn(){};
};

#endif // PAWN_H
