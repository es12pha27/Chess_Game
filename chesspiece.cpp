
#include "chesspiece.h"
#include "core.h"
#include <QDebug>
#include <memory>
#include "king.h"
#include <QColor>

extern Core *core;

ChessPiece::ChessPiece(QString team, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    side = team;
    Moved = true;
    firstMove = true;
}
//evento al presionar una chesspiece
void ChessPiece::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //Deselect
    if(this == core->pieceToMove){
        core->pieceToMove->getCurrentCell()->resetOriginalColor();
        core->pieceToMove->recolor();
        core->pieceToMove = NULL;
       return;
    }
    //para saber si ya paso su turno
    if((!getMoved() )|| ( (core->getTurn() != this->getSide())&& (!core->pieceToMove)) )
        return;
    if(!core->pieceToMove){

        core->pieceToMove = this;
        core->pieceToMove->getCurrentCell()->setColor(QColor(42,157,143));
        core->pieceToMove->move();
    }
    else if(this->getSide() != core->pieceToMove->getSide()){
        this->getCurrentCell()->mousePressEvent(event);
    }


}
/*Cambia la celda actual en donde se encuentra el obj*/
void ChessPiece::setCurrentCell(ChessCell *Cell)
{

    currentCell = Cell;
}
/*Obtiene la celda actual en donde se encuentra el obj*/
ChessCell *ChessPiece::getCurrentCell()
{
    return currentCell;
}
/*obtiene el bando (equipo) donde se encuentra black or white*/
QString ChessPiece::getSide()
{
    return side;
}
/*asigna el bando (equipo) donde se encuentra black or white*/
void ChessPiece::setSide( QString value)
{
    side = value;
}

//retornamos el valor moved
bool ChessPiece::getMoved()
{
    return Moved;
}

//cambiamos el valor de moved
void ChessPiece::setMoved(bool value)
{
    Moved = value;

}

//retornamos la location en la que estamos
QList<ChessCell *> ChessPiece::moveLocation()
{
    return location;
}

//reseteamos el color
void ChessPiece::recolor()
{
    for(size_t i = 0, n = location.size(); i < n;i++) {
         location[i]->resetOriginalColor();
    }
}


bool ChessPiece::CellSetup(ChessCell *Cell)
{
    if(Cell->getHasChessPiece()) {
        King *q = dynamic_cast<King*>(location.last()->currentPiece);
        if(q){
            Cell->setColor(Qt::blue);
        }
        else
            Cell->setColor(Qt::red);
        return true;
    }
    else
        location.last()->setColor(Qt::darkRed);
    return false;
}



