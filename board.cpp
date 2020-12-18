#include "Board.h"
#include "ui_Board.h"
#include <QGridLayout>
#include <QDebug>
#include <iostream>
#include "mainwindow.h"

extern MainWindow *qmain;

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{  ui->setupUi(this);
    initializeBlack();  //inicializar las fichas negras
    initializeWhite();
}
void Board::initializeBoard()
{
   /* QString darkStyle="Locker { font-weight: bold;font-size: 20px;background-color : "
                      "darkslategray;color : white;  border: 1px solid black; }";
    QString whiteStyle="Locker { font-weight: bold;font-size: 20px;background-color : white;color : white;"
                       "  border: 1px solid black; }";

    QGridLayout *mainLayout = new QGridLayout;
    for(uint16_t i = 1; i <NumLocker-1; i++) {
        for(uint16_t j = 1; j < NumLocker-1; j++)
        {
            Locker *cell = new Locker(i,j,"");
            cell->setName(names[i-1][j-1]);
            qmain->collection[i][j] = cell;
            if((i+j)%2==0){
            qmain->collection[i][j]-> setStyleSheet(whiteStyle);
            }
            else{
            qmain->collection[i][j]->setStyleSheet(darkStyle);
            }
        }
        for (unsigned i = 0; i < NumLocker; ++i){
                for (int j = 0; j < NumLocker; ++j){

                mainLayout->addWidget(qmain->collection[i][j], i, j);
                mainLayout->setSpacing(0);
            }
            }


        qmain->collection[0][0] = new Locker(0,0,"");
        qmain->collection[0][9] =new Locker(0,9,"");
        qmain->collection[9][0] = new Locker(9,0,"");
        qmain->collection[9][9] =new Locker(9,9,"");
        qmain->collection[0][0]->setStyleSheet(darkStyle);
        qmain->collection[0][9]->setStyleSheet(darkStyle);
        qmain->collection[9][0]->setStyleSheet(darkStyle);
        qmain->collection[9][9]->setStyleSheet(darkStyle);



        //Dibujando las letras del tablero
        int  j=0;
         for (unsigned i = 1; i < NumLocker-1; ++i){
             qmain->collection[0][i] =new Locker(0,i,letters[j]);
             qmain->collection[0][i]->setStyleSheet(darkStyle);
             qmain->collection[0][i]->setMaximumSize(qmain->collection[0][i]->size().rwidth(),30);


             qmain->collection[0][i] =new Locker(9,i,letters[j]);
             qmain->collection[0][i]->setStyleSheet(darkStyle);
             qmain->collection[0][i]->setMaximumSize(qmain->collection[9][i]->size().rwidth(),30);

             if(j<8)j++;
         }
         //Dibujando los numeros del tablero
       j=NumLocker-2;
        for (unsigned i = 1; i < NumLocker-1; ++i){
            qmain->collection[i][0] =new Locker(i,0,QString::number(j));
            qmain->collection[i][0]->setStyleSheet(darkStyle);

            qmain->collection[i][9] = new Locker(i,9,QString::number(j));
            qmain->collection[i][9]->setStyleSheet(darkStyle);
            j--;
        }
        for (unsigned i = 0; i < NumLocker; ++i){
                for (int j = 0; j < NumLocker; ++j){

                mainLayout->addWidget(qmain->collection[i][j], i, j);
                mainLayout->setSpacing(0);
            }
            }

    setLayout(mainLayout);

    setWindowTitle(tr("Board"));
    }*/
    qmain=new MainWindow();
    qDebug()<<qmain->num<<"\n";

}

void Board::addPieces(){}
void Board::initializeWhite(){}
void Board::initializeBlack(){}
void Board::reset(){}
Board::~Board(){
 delete ui;
}












        /*this->setMaximumSize(999,999);
        //Dibujar tablero

        //Estilos de las celdas
        QString darkStyle="Locker { font-weight: bold;font-size: 20px;background-color : "
                          "darkslategray;color : white;  border: 1px solid black; }";
        QString whiteStyle="Locker { font-weight: bold;font-size: 20px;background-color : white;color : white;"
                           "  border: 1px solid black; }";
        int iter=0;
        QGridLayout *mainLayout = new QGridLayout;
        mainLayout->setSizeConstraint(QLayout::SetMinimumSize);
        for (unsigned i = 1; i < NumLocker-1; ++i){
            for (unsigned j = 1; j < NumLocker-1; ++j){
                board[i][j] = createLocker("",i,j);
                board[i][j]->setName(names[i-1][j-1]);
                if((i+j)%2==0){
                board[i][j]-> setStyleSheet(whiteStyle);
                }
                else{
                  board[i][j]->setStyleSheet(darkStyle);

                }

            }            
        }

        //Dibujando las esquinas del tablero
        board[0][0] = createLocker("",0,0);
        board[0][9] = createLocker("",0,9);
        board[9][0] = createLocker("",9,0);
        board[9][9] = createLocker("",9,9);
        board[0][0]->setStyleSheet(darkStyle);
        board[0][9]->setStyleSheet(darkStyle);
        board[9][0]->setStyleSheet(darkStyle);
        board[9][9]->setStyleSheet(darkStyle);



        //Dibujando las letras del tablero
        int  j=0;
         for (unsigned i = 1; i < NumLocker-1; ++i){
             board[0][i] = createLocker(letters[j],0,i);
             board[0][i]->setStyleSheet(darkStyle);
             board[0][i]->setMaximumSize(board[0][i]->size().rwidth(),30);

             board[9][i] = createLocker(letters[j],9,i);
             board[9][i]->setStyleSheet(darkStyle);

             board[9][i]->setMaximumSize(board[9][i]->size().rwidth(),30);

             if(j<8)j++;
         }
         //Dibujando los numeros del tablero
       j=NumLocker-2;
        for (unsigned i = 1; i < NumLocker-1; ++i){
            board[i][0] = createLocker(QString::number(j),i,0);
            board[i][0]->setStyleSheet(darkStyle);

            board[i][9] = createLocker(QString::number(j),i,9);
            board[i][9]->setStyleSheet(darkStyle);
            j--;
        }
        for (unsigned i = 0; i < NumLocker; ++i){
                for (int j = 0; j < NumLocker; ++j){

                mainLayout->addWidget(board[i][j], i, j);
                mainLayout->setSpacing(0);
            }
            }



    setLayout(mainLayout);

    setWindowTitle(tr("Board"));




}

Board::~Board()
{
    delete ui;
}


Locker *Board::createLocker(const QString &text, int ib,int jb)
{
    Locker *button = new Locker(ib,jb,text);
    return button;
}
*/
