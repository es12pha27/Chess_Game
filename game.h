#ifndef Game_H
#define Game_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <board.h>
#include "Piece.h"
#include <QGridLayout>
#include <QTableWidget>
#include <QLCDNumber>
#include <QTime>
#include <QTimer>
#include <QPushButton>
class Game:public QGraphicsView
{
    Q_OBJECT
public:
    //Constructor
    Game(QWidget *parent = 0);

    void displayDeadsFrame( int x, int y);
    void showBoard();
    void showDeadWhites();
    void showDeadBlack();
    void placeInDeadPlace(Piece *piece);

    //metodos para manejar la escena
    void aggregateToScene(QGraphicsItem *item);      //agrega a la escena
    void deleteToScene(QGraphicsItem *item); //elminina de la escena

    //pieza a mover
    Piece *pieceToMove;

    //conocer el turno
    QString getTurn() ;
    //setea de turno
    void setTurn( QString value);



    //coleccion de celdas
    Locker *collection[10][10];
    QGraphicsTextItem *check;
    //verifica las piezas vivas
    QList <Piece *> piecesIngame;
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
     int rowCountb=0;
     int colCountb=1;
     int rowCountw=0;
     int colCountw=0;
     QTime *time;
     QTimer *timer;
     bool timestop=false;

     //cambia de turno
     void changeTurn();

public slots:
    void start();
    void startTime();
    void stopTime();
    void resetTime();
    void showTime();




private:

    QGraphicsScene *chessScene;
    QGraphicsScene * chessSceneWhite;
    QList <Piece *> whiteDead;
    QList <Piece *> blackDead;
    QGraphicsRectItem * deadHolder;
    QGraphicsTextItem* textTurn;
    QString turn;
    Board *chess;
    QList <QGraphicsItem *> listG;
    QGraphicsTextItem * frameTurn;
    QGraphicsRectItem * Turn;
    QStringList hlabels;
    //Cronometro
    QLCDNumber *num;
    QPushButton *resetButton;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *finishButton;

    int seconds;
    int seconds_limit=10000;
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;
    QGridLayout *mainLayout;


};

#endif // Game_H
