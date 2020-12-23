#ifndef CORE_H
#define CORE_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <board.h>
#include "chesspiece.h"
#include <QGridLayout>
#include <QTableWidget>
class Core:public QGraphicsView
{
    Q_OBJECT
public:
    //Constructor
    Core(QWidget *parent = 0);

    void displayDeadsFrame( int x, int y);
    void showBoard();
    void showDeadWhites();
    void showDeadBlack();
    void placeInDeadPlace(ChessPiece *piece);

    //metodos para manejar la escena
    void aggregateToScene(QGraphicsItem *item);      //agrega a la escena
    void deleteToScene(QGraphicsItem *item); //elminina de la escena

    //pieza a mover
    ChessPiece *pieceToMove;

    //conocer el turno
    QString getTurn() ;
    //setea de turno
    void setTurn( QString value);
    //cambia de turno
    void changeTurn();


    //coleccion de celdas
    ChessCell *collection[10][10];
    QGraphicsTextItem *check;
    //verifica las piezas vivas
    QList <ChessPiece *> piecesInGame;
    void displayDeadWhite();
    void displayDeadBlack();

    //dibuja el menu principal
    void displayMainMenu();
    //to implement, cuando el juego acabe
    void gameOver();
    //elimina todo
    void removeAll();
     QTableWidgetItem *newItem;
     QTableWidget *tableWidget;
     int rowCount;
     int colCount;

public slots:
    void start();
private:

    QGraphicsScene *chessScene;
    QGraphicsScene * chessSceneWhite;
    QTimer *timer;
    QList <ChessPiece *> whiteDead;
    QList <ChessPiece *> blackDead;
    QGraphicsRectItem * deadHolder;
    QString turn;
    Board *chess;
    QList <QGraphicsItem *> listG;
    QGraphicsTextItem * frameTurn;
    QGraphicsRectItem * Turn;


};

#endif // CORE_H
