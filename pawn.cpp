#include "pawn.h"
#include <QDebug>
#include <typeinfo>
#include "king.h"
#include "core.h"
extern Core *core;
Pawn::Pawn(QString team,QGraphicsItem *parent):ChessPiece(team,parent)
{
    name=" ";
    //se inicializa poniendo su imagen
    setImage();
    firstMove = true;
}
/*Se encarga de colocar la imagen al objeto mediante Qpixmap*/

void Pawn::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/img/img/pawn_w.png"));
    else
        setPixmap(QPixmap(":/img/img/pawn_b.png"));
}

/*Se encarga de como se mueve la pieza*/

void Pawn::move()
{
    location.clear();
    int row = this->getCurrentCell()->rowLoc;
    int col = this->getCurrentCell()->colLoc;
    if(this->getSide() == "WHITE")  {
        if(col > 1 && row > 1 && core->collection[row-1][col-1]->getChessPieceColor() == "BLACK") {
            location.append(core->collection[row-1][col-1]);
            CellSetup(location.last());
        }
        if(col < 8 && row > 1 && core->collection[row-1][col+1]->getChessPieceColor() == "BLACK") {
            location.append(core->collection[row-1][col+1]);
            CellSetup(location.last());
        }
        if(row>1 && (!core->collection[row-1][col]->getHasChessPiece())) {
            location.append(core->collection[row-1][col]);
            CellSetup(location.last());
            if(firstMove && !core->collection[row-2][col]->getHasChessPiece()){
                location.append(core->collection[row-2][col]);
                CellSetup(location.last());
            }
        }

    }
    else{
        if(col > 1 && row < 8 && core->collection[row+1][col-1]->getChessPieceColor() == "WHITE") {//left
            location.append(core->collection[row+1][col-1]);
            CellSetup(location.last());
        }
        if(col < 8 && row < 8 && core->collection[row+1][col+1]->getChessPieceColor() == "WHITE") {//right
            location.append(core->collection[row+1][col+1]);
            CellSetup(location.last());
        }
        if(row<8 && (!core->collection[row+1][col]->getHasChessPiece())) {
            location.append(core->collection[row+1][col]);
            CellSetup(location.last());
            if(firstMove && !core->collection[row+2][col]->getHasChessPiece()){
                location.append(core->collection[row+2][col]);
                CellSetup(location.last());
            }

        }

    }

}


