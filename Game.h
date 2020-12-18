#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <board.h>

class Game:public QWidget
{
    Q_OBJECT
public:
    Game(QWidget *parent = 0);
    Locker *collection[10][10];
    void showBoard();
    int num=5;
    //Piece* pieceToMove;
    //QList <Piece*> piecesInGame;

private:
    Board *chess;
};

#endif // GAME_H
