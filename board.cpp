#include "board.h"
#include "Locker.h"
#include "game.h"
#include "queen.h"
#include "tower.h"
#include "pawn.h"
#include "king.h"
#include "knight.h"
#include "bishop.h"
#include <QColor>
#include <QRect>
#include <QDebug>

extern Game *game;
Board::Board()
{
    initializeBlack();  //inicializar las fichas negras
    initializeWhite();  //inicializar las fichas blancas
}

//dibujando los cuadros
void Board::initializeBoard(int x,int y)
{
    uint16_t sizeCell = 80;
    QString darkStyle="Locker { font-weight: bold;font-size: 20px;background-color : "
                              "darkslategray;color : white;  border: 1px solid black; }";
    QString whiteStyle="Locker { font-weight: bold;font-size: 20px;background-color : white;color : white;"
                               "  border: 1px solid black; }";

    int k=0,l=0;
    int m=8,n=8;
    for(uint16_t i = 0; i < NumLocker; i++) {
        for(uint16_t j = 0; j < NumLocker; j++)
        {   Locker *cell = new Locker("");
            game->collection[i][j] = cell;
            cell->rowLoc = i;
            cell->colLoc = j;
            cell->setPos(x+sizeCell*j,y+sizeCell*i);
            if(i==0 || i==9 || j==0 || j==9){
                cell->setOriginalColor(QColor(47, 79, 79));
                if(i==0 && j==0|| i==9 && j==9 || i==9 && j==0 || i==0 && j==9)
                    cell->setText("");
                else if(i==0 || i==9 ){
                       if(i==9){
                     cell->setText(letters[k]);
                     k++;}
                       else{
                           cell->setText(letters[l]);
                           l++;

                       }
                }
                else if(j==0 || j==9){
                    if(j==9){
                    cell->setText(QString::number(m));
                    m--;}
                    else{
                     cell->setText(QString::number(n));
                      n--;
                    }


                }

            }
            else{
                if(i<9 & j<9)
                cell->name=names[i-1][j-1];
                //qDebug()<<cell->name<<cell->rowLoc<<"-"<<cell->colLoc;

            if((i+j)%2==0)
                cell->setOriginalColor( QColor(255, 255, 255));
            else
                cell->setOriginalColor(QColor(47, 79, 79));}
                game->aggregateToScene(cell);
        }
    }

}

//agregando las piezas en las listas
void Board::addPieces() {
    for(uint16_t i = 1; i < 9; i++) {
        for(uint16_t j = 1; j < 9; j++)
        {

            Locker *cell =game->collection[i][j];
            if(i < 3 ) {
                static uint16_t k;
                cell->placePiece(blackPieces[k]);
                game->piecesIngame.append(blackPieces[k]);
                game->aggregateToScene(blackPieces[k++]);
            }
            if(i > 6 ) {
                static uint16_t h;
                cell->placePiece(whitePieces[h]);
                game->piecesIngame.append(whitePieces[h]);
                game->aggregateToScene(whitePieces[h++]);
            }

        }
    }
}

//inicializar las fichas blancas
void Board::initializeWhite()
{
    Piece *pieceToAdd;
    for(int i = 1; i < 9; i++) {
        pieceToAdd = new Pawn("WHITE");
        whitePieces.append(pieceToAdd);
    }
    pieceToAdd = new Tower("WHITE");
    whitePieces.append(pieceToAdd);
    pieceToAdd = new Knight("WHITE");
    whitePieces.append(pieceToAdd);
    pieceToAdd = new Bishop("WHITE");
    whitePieces.append(pieceToAdd);
    pieceToAdd = new Queen("WHITE");
    whitePieces.append(pieceToAdd);
    pieceToAdd = new King("WHITE");
    whitePieces.append(pieceToAdd);
    pieceToAdd = new Bishop("WHITE");
    whitePieces.append(pieceToAdd);
    pieceToAdd = new Knight("WHITE");
    whitePieces.append(pieceToAdd);
    pieceToAdd = new Tower("WHITE");
    whitePieces.append(pieceToAdd);

}

//inicializando las piezas negras
void Board::initializeBlack()
{
    Piece *pieceToAdd;
    pieceToAdd = new Tower("BLACK");
    blackPieces.append(pieceToAdd);
    pieceToAdd = new Knight("BLACK");
    blackPieces.append(pieceToAdd);
    pieceToAdd = new Bishop("BLACK");
    blackPieces.append(pieceToAdd);
    pieceToAdd = new Queen("BLACK");
    blackPieces.append(pieceToAdd);
    pieceToAdd = new King("BLACK");
    blackPieces.append(pieceToAdd);
    pieceToAdd = new Bishop("BLACK");
    blackPieces.append(pieceToAdd);
    pieceToAdd = new Knight("BLACK");
    blackPieces.append(pieceToAdd);
    pieceToAdd = new Tower("BLACK");
    blackPieces.append(pieceToAdd);
    for(int i = 0; i < 8; i++) {
        pieceToAdd = new Pawn("BLACK");
        blackPieces.append(pieceToAdd);
    }
}

//resetea el board una vez haya ganado uno de los jugadores
void Board::reset() {
    initializeWhite();
    initializeBlack();

    int k = 0; int h = 0;
        for(int i = 1; i < 9; i++) {
            for(int j = 1; j < 9; j++)
            {

                Locker *box =game->collection[i][j];
                box->setHasPiece(false);
                box->setPieceColor("NONE");
                box->currentPiece = NULL;
                if(i < 3 ) {

                    box->placePiece(blackPieces[k]);
                    blackPieces[k]->setMoved(true);
                    blackPieces[k]->firstMove = true;
                    game->piecesIngame.append(blackPieces[k++]);

                }
                if(i > 6  ) {

                    box->placePiece(whitePieces[h]);
                    whitePieces[h]->setMoved(true);
                    whitePieces[h]->firstMove = true;
                    game->piecesIngame.append(whitePieces[h++]);


                }

            }
        }
}
