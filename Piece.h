#ifndef PIECE_H
#define PIECE_H
#include <QLabel>
#include <QPixmap>
#include <iostream>
#include <cassert>
#include <map>
#include "Locker.h"

namespace ui{
class Piece;
}

class Piece :public QLabel{

    Q_OBJECT
public:
   explicit Piece(QWidget *parent =nullptr);   
    virtual ~Piece(){};
    QString getName();
    std::map<QString,int> mo;
    friend QDataStream& operator>>(QDataStream &s, Piece *&piece_ptr);
    friend QDataStream& operator<<(QDataStream &s, const Piece *piece_ptr);
protected:
    ui::Piece *ui;
    QString name=" ";
    QPixmap PieceIcon;
    bool color;
    bool can_move;
    bool status;
    bool getCan_move();
    bool getStatus();
    bool getColor();
    virtual  void movePiece();
    virtual void getPath();
};

#endif // PIECE_H
