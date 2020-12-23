#include "knight.h"
#include "game.h"
extern Game *game;
Knight::Knight(QString team,QGraphicsItem *parent):Piece(team,parent)
{
    name="C";
    //se inicializa poniendo su imagen
    setImage();
}
/*Se encarga de colocar la imagen al objeto mediante Qpixmap*/

void Knight::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/img/img/horse_w.png"));
    else
        setPixmap(QPixmap(":/img/img/horse_b.png"));
}
/*Se encarga de como se mueve la pieza*/

void Knight::move()
{
    int row = this->getCurrentCell()->rowLoc;
    int col = this->getCurrentCell()->colLoc;
    int i ,j;
    QString team  = this->getSide();

    //Hay 8 formas de mover al caballo
    // tomando en cuenta WASD como instrucciones
    //1st w w a
    i = row - 2;
    j = col - 1;
    if(i >=1 && j>=1 && (game->collection[i][j]->getPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkYellow);
    }

    //2nd w w d
    i = row - 2;
    j = col + 1;
    if(i >=1 && j<=8 && (game->collection[i][j]->getPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkYellow);
    }

    //3rd s s a
    i = row + 2;
    j = col - 1;
    if(i <= 8 && j>=1 && (game->collection[i][j]->getPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkYellow);
    }

    //4th  s s d
    i = row + 2;
    j = col + 1;
    if(i <=8 && j<=8 && (game->collection[i][j]->getPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkYellow);
    }

    //5th a a w
    i = row - 1;
    j = col - 2;
    if(i >=1 && j>=1 && (game->collection[i][j]->getPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkYellow);
    }

    //6th a a s
    i = row + 1;
    j = col - 2;
    if(i <=8 && j>=1 && (game->collection[i][j]->getPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkYellow);
    }

    //7th d d w
    i = row - 1;
    j = col + 2;
    if(i >=1 && j<=8 && (game->collection[i][j]->getPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkYellow);
    }

    //8th d d s
    i = row + 1;
    j = col +  2;
    if(i <=8 && j<=8 && (game->collection[i][j]->getPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkYellow);
    }

}

