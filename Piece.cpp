
#include "Piece.h"
#include "game.h"
#include <QDebug>
#include <memory>
#include "king.h"
#include <QColor>

extern Game *game;

Piece::Piece(QString team, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    side = team;
    Moved = true;
    firstMove = true;
}
//evento al presionar una Piece
void Piece::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //Deselect
    if(this == game->pieceToMove){
        game->pieceToMove->getCurrentCell()->resetOriginalColor();
        game->pieceToMove->recolor();
        game->pieceToMove = NULL;
       return;
    }
    //para saber si ya paso su turno
    if((!getMoved() )|| ( (game->getTurn() != this->getSide())&& (!game->pieceToMove)) )
        return;
    if(!game->pieceToMove){

        game->pieceToMove = this;
        game->pieceToMove->getCurrentCell()->setColor(QColor(42,157,143));
        game->pieceToMove->move();
    }
    else if(this->getSide() != game->pieceToMove->getSide()){
        this->getCurrentCell()->mousePressEvent(event);
    }


}
/*Cambia la celda actual en donde se encuentra el obj*/
void Piece::setCurrentCell(Locker *Cell)
{

    currentCell = Cell;
}
/*Obtiene la celda actual en donde se encuentra el obj*/
Locker *Piece::getCurrentCell()
{
    return currentCell;
}
/*obtiene el bando (equipo) donde se encuentra black or white*/
QString Piece::getSide()
{
    return side;
}
/*asigna el bando (equipo) donde se encuentra black or white*/
void Piece::setSide( QString value)
{
    side = value;
}

//retornamos el valor moved
bool Piece::getMoved()
{
    return Moved;
}

//cambiamos el valor de moved
void Piece::setMoved(bool value)
{
    Moved = value;

}

//retornamos la location en la que estamos
QList<Locker *> Piece::moveLocation()
{
    return location;
}

//reseteamos el color
void Piece::recolor()
{
    for(size_t i = 0, n = location.size(); i < n;i++) {
         location[i]->resetOriginalColor();
    }
}


bool Piece::CellSetup(Locker *Cell)
{
    if(Cell->getHasPiece()) {
        King *q = dynamic_cast<King*>(location.last()->currentPiece);
        if(q){
            Cell->setColor(Qt::blue);
        }
        else
            Cell->setColor(Qt::red);
        return true;
    }
    else
        location.last()->setColor(Qt::darkYellow);
    return false;
}



