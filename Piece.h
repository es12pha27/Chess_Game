#ifndef Piece_H
#define Piece_H
#include "Locker.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
struct Move_piece{
   QString origin;
   QString destiny;
   QString name="";
};
class Locker;
class Piece:public QGraphicsPixmapItem
{
public:
    Piece(QString team = "",QGraphicsItem *parent = 0);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setCurrentCell(Locker *Cell);
    Locker *getCurrentCell() ;
    QString getSide() ;
    void setSide( QString value);
    virtual void setImage() = 0;
    bool getMoved() ;
    void setMoved(bool value);
    QList <Locker *> moveLocation();
    virtual void move() = 0;
    void recolor();
    bool firstMove;
    bool CellSetup(Locker *Cell);
    Move_piece control;
    QString name;
protected:
    Locker *currentCell;
    QString side;
    bool Moved;
    QList <Locker *> location;


};

#endif // Piece_H
