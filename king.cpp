#include "king.h"
#include "pawn.h"
#include "game.h"
extern Game *game;
King::King(QString team,QGraphicsItem *parent):Piece(team,parent)
{
    name="R";
    //se inicializa poniendo su imagen
    setImage();
}
/*Se encarga de colocar la imagen al objeto mediante Qpixmap*/

void King::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/img/img/king_w.png"));
    else
        setPixmap(QPixmap(":/img/img/king_b.png"));
}

/*Se encarga de como se mueve la pieza*/

void King::move()
{

    location.clear();
    int row = this->getCurrentCell()->rowLoc;
    int col = this->getCurrentCell()->colLoc;
    QString team = this->getSide();

        if(col > 1 && row > 1 && !(game->collection[row-1][col-1]->getPieceColor() == team)) {//up left
            location.append(game->collection[row-1][col-1]);
            game->collection[row-1][col-1]->setColor(Qt::darkYellow);
            if(location.last()->getHasPiece()){
                location.last()->setColor(Qt::red);
            }
        }
        if(col < 8 && row > 1 && !(game->collection[row-1][col+1]->getPieceColor() == team)) { // up right
            location.append(game->collection[row-1][col+1]);
            game->collection[row-1][col+1]->setColor(Qt::darkYellow);
            if(location.last()->getHasPiece()){
                location.last()->setColor(Qt::red);
            }
        }
        if(row>1 && !(game->collection[row-1][col]->getPieceColor() == team)) {//up
            location.append(game->collection[row-1][col]);
            game->collection[row-1][col]->setColor(Qt::darkYellow);
            if(location.last()->getHasPiece()){
                location.last()->setColor(Qt::red);
            }
        }
        if(row<8 && !(game->collection[row+1][col]->getPieceColor() == team)) {//down
            location.append(game->collection[row+1][col]);
            game->collection[row+1][col]->setColor(Qt::darkYellow);
            if(location.last()->getHasPiece()){
                location.last()->setColor(Qt::red);
            }
        }
        if(col>1 && !(game->collection[row][col-1]->getPieceColor() == team)) {// left
            location.append(game->collection[row][col-1]);
            game->collection[row][col-1]->setColor(Qt::darkYellow);
            if(location.last()->getHasPiece()){
                location.last()->setColor(Qt::red);
            }
        }
        if(col<8 && !(game->collection[row][col+1]->getPieceColor() == team)) {//right
            location.append(game->collection[row][col+1]);
            game->collection[row][col+1]->setColor(Qt::darkYellow);
            if(location.last()->getHasPiece()){
                location.last()->setColor(Qt::red);
            }
        }
        if(col > 1 && row < 8  && !(game->collection[row+1][col-1]->getPieceColor() == team)) {//down left
            location.append(game->collection[row+1][col-1]);
            game->collection[row+1][col-1]->setColor(Qt::darkYellow);
            if(location.last()->getHasPiece()){
                location.last()->setColor(Qt::red);
            }
        }
        if(col < 8 && row < 8 && !(game->collection[row+1][col+1]->getPieceColor() == team)) {//down right
            location.append(game->collection[row+1][col+1]);
            game->collection[row+1][col+1]->setColor(Qt::darkYellow);
            if(location.last()->getHasPiece()){
                location.last()->setColor(Qt::red);
            }
        }
        /*if(col < 8 && row == 8 && !(game->collection[row][col+1]->getPieceColor() == team)) {//down right
            location.append(game->collection[row+1][col+1]);
            game->collection[row+1][col+1]->setColor(Qt::darkYellow);
            if(location.last()->getHasPiece()){
                location.last()->setColor(Qt::red);
            }
        }*/


            findUnSafeLocation();

}
/*se encarga de realizar un check para ver si el rey se encuentra en jaque*/
void King::findUnSafeLocation() {
    QList <Piece *> pList = game->piecesIngame;
    for(size_t i = 0,n = pList.size(); i < n; i++) {

        if(pList[i]->getSide() != this->getSide())
        {
            QList <Locker *> bList = pList[i]->moveLocation();

            for(size_t j = 0, n = bList.size(); j < n; j++) {
                Pawn *c = dynamic_cast<Pawn *> (pList[i]) ;
                if(c)
                    continue;
                for(size_t k = 0, n = location.size(); k < n; k++) {
                   if(bList[j] == location [k]) {
                       location[k]->setColor(Qt::blue);
                   }
                }
            }
        }
    }
}
