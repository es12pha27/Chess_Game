#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"

class bishop:public Piece
{
public:
    explicit bishop(QWidget *parent );
    virtual ~bishop(){};
};

#endif // BISHOP_H
