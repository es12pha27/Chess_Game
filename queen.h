#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"

class queen:public Piece
{
public:
    explicit queen(QWidget *parent );
    virtual ~queen(){};
};

#endif // QUEEN_H
