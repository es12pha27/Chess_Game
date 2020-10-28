#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"

class rook:public Piece
{
public:
    explicit rook(QWidget *parent );
    virtual ~rook(){};
};

#endif // ROOK_H
