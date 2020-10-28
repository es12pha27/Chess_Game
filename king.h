#ifndef KING_H
#define KING_H
#include "Piece.h"

class king:public Piece
{
public:
    explicit king(QWidget *parent );
    virtual ~king(){};
};


#endif // KING_H
