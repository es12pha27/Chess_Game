#include "pawn.h"
#include <QDebug>
#include <typeinfo>
#include "king.h"
#include "game.h"
extern Game *game;
Pawn::Pawn(QString team,QGraphicsItem *parent):Piece(team,parent)
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
        if(col > 1 && row > 1 && game->collection[row-1][col-1]->getPieceColor() == "BLACK") {
            location.append(game->collection[row-1][col-1]);
            CellSetup(location.last());
        }
        if(col < 8 && row > 1 && game->collection[row-1][col+1]->getPieceColor() == "BLACK") {
            location.append(game->collection[row-1][col+1]);
            CellSetup(location.last());
        }
        if(row>1 && (!game->collection[row-1][col]->getHasPiece())) {
            location.append(game->collection[row-1][col]);
            CellSetup(location.last());
            if(firstMove && !game->collection[row-2][col]->getHasPiece()){
                location.append(game->collection[row-2][col]);
                CellSetup(location.last());
            }
        }

    }
    else{
        if(col > 1 && row < 8 && game->collection[row+1][col-1]->getPieceColor() == "WHITE") {//left
            location.append(game->collection[row+1][col-1]);
            CellSetup(location.last());
        }
        if(col < 8 && row < 8 && game->collection[row+1][col+1]->getPieceColor() == "WHITE") {//right
            location.append(game->collection[row+1][col+1]);
            CellSetup(location.last());
        }
        if(row<8 && (!game->collection[row+1][col]->getHasPiece())) {
            location.append(game->collection[row+1][col]);
            CellSetup(location.last());
            if(firstMove && !game->collection[row+2][col]->getHasPiece()){
                location.append(game->collection[row+2][col]);
                CellSetup(location.last());
            }

        }

    }

}


