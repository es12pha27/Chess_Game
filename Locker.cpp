#include "Locker.h"
#include "game.h"
#include <memory>
#include <QDebug>
#include "king.h"
#include <QLabel>
#include <QMessageBox>

extern Game *game;
Locker::Locker(QString text,QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    //dibujar la celda
    setRect(0,0,100,100);
    QPainter *painter=new QPainter();
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
    setHasPiece(false);
    setPieceColor("NONE");
    currentPiece = NULL;
}

Locker::~Locker()
{
    delete this;
}
void Locker::setText(QString text){
    texto = new QGraphicsTextItem(text, this);
    int xPos = rect().width()/2 - texto->boundingRect().width()/2;
    int yPos = rect().height()/2 - texto->boundingRect().height()/2;
    texto->setZValue(0.5);
    texto->setDefaultTextColor(Qt::white);
    texto->setFont(QFont("",20));
    texto->setPos(xPos-10,20 );
    texto->setDefaultTextColor(Qt::white);
}
void Locker::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
        if(currentPiece == game->pieceToMove && currentPiece){

            currentPiece->mousePressEvent(event);

            return;
        }

        //se seleeciona pieza
        if(game->pieceToMove){

            //si esta en el mismo equipo no se puede mover si ya ha movido
            if(this->getPieceColor() == game->pieceToMove->getSide()){
                 qDebug()<<"prueba donde come"<<game->pieceToMove->getSide();
                return;}

            //eliminando si esta muerta esta pieza
            QList <Locker *> movLoc = game->pieceToMove->moveLocation();

            //chekea que esta en una de las celdas donde si se puede mover
            int check = 0;
            for(size_t i = 0, n = movLoc.size(); i < n;i++) {
                if(movLoc[i] == this) {
                    check++;

                }
            }

            // si no retorna
            if(check == 0)
                return;
            //cambia el color a normal
             game->pieceToMove->recolor();
             //hace el primer movimiento falta para peones
             game->pieceToMove->firstMove = false;
             //realiza la accion de comer una ficha

            if(this->getHasPiece()){
                this->currentPiece->setMoved(false);
                this->currentPiece->setCurrentCell(NULL);
                game->placeInDeadPlace(this->currentPiece);
                game->pieceToMove->control.name="x";
            }

            game->pieceToMove->control.destiny=this->name;
            QTableWidgetItem *newItem = new QTableWidgetItem();
            newItem->setText(game->pieceToMove->name +game->pieceToMove->control.name+ game->pieceToMove->control.destiny);
            if(game->pieceToMove->getSide()=="BLACK"){
            game->tableWidget->setItem( game->rowCountb,game->colCountb,newItem);
            game->rowCountb+=1;
            }
            else{
            game->tableWidget->setItem( game->rowCountw,game->colCountw,newItem);

            game->rowCountw+=1;
            }
            qDebug()<<game->pieceToMove->getSide();
            //resetando la region previa
            game->pieceToMove->getCurrentCell()->setHasPiece(false);
            game->pieceToMove->getCurrentCell()->currentPiece = NULL;
            game->pieceToMove->getCurrentCell()->resetOriginalColor();
            placePiece(game->pieceToMove);

            game->pieceToMove = NULL;
            //cambiando el turno
            game->changeTurn();
            checkForCheck();

        }
        else if(this->getHasPiece())
        {
            this->currentPiece->mousePressEvent(event);
        }
}

//cambia el color por uno que se le indique
void Locker::setColor(QColor color)
{
    brush.setColor(color);
    setBrush(color);
}

//se encarga de poner las piezas en un lugar deseado del pixman
void Locker::placePiece(Piece *piece)
{
    piece->setPos(x()+40- piece->pixmap().width()/2  ,y()+40-piece->pixmap().width()/2);
    piece->setCurrentCell(this);
    setHasPiece(true,piece);
    currentPiece = piece;
}

//resetea el color al original
void Locker::resetOriginalColor()
{
    setColor(originalColor);
}


//cambia el color originar
void Locker::setOriginalColor(QColor value)
{
    originalColor = value;
    setColor(originalColor);
}

//returna si es que tiene o no una pieza
bool Locker::getHasPiece()
{
    return hasPiece;
}

//obtiene el valor del lugar de la pieza
void Locker::setHasPiece(bool value, Piece *piece)
{
    hasPiece = value;

    if(value){
        setPieceColor(piece->getSide());
    }else
        setPieceColor("NONE");
}

//se encarga de checkear continuamente si hay algun jake mate
void Locker::checkForCheck()
{
    int c = 0;
    int contrey=0;
        QList <Piece *> pList = game->piecesIngame;
        for(size_t i = 0,n=pList.size(); i < n; i++ ) {

            King * p = dynamic_cast<King *> (pList[i]);
            if(p){
                contrey++;
                continue;
            }

            pList[i]->move();
            pList[i]->recolor();
            QList <Locker *> bList = pList[i]->moveLocation();
            for(size_t j = 0,n = bList.size(); j < n; j ++) {
                King * p = dynamic_cast<King *> (bList[j]->currentPiece);
                if(p) {
                    if(p->getSide() == pList[i]->getSide())
                        continue;
                    bList[j]->setColor(Qt::blue);
                    pList[i]->getCurrentCell()->setColor(Qt::darkYellow);
                    if(!game->check->isVisible())
                        game->check->setVisible(true);
                    else{
                        bList[j]->resetOriginalColor();
                        pList[i]->getCurrentCell()->resetOriginalColor();

                        if(QString::compare(game->getTurn(),"WHITE")){

                            game->check->setPlainText("Negro ganador");
                            game->check->setVisible(true);
                            QMessageBox Msgbox;
                            Msgbox.setWindowTitle("¡El ganador es!");
                            Msgbox.setText("¡Equipo Negro!");
                            Msgbox.exec();
                        }
                        else if(QString::compare(game->getTurn(),"BLACK")){
                            game->check->setPlainText("Blanco Ganador");
                            game->check->setVisible(true);
                            QMessageBox Msgbox;
                            Msgbox.setWindowTitle("¡El ganador es!");
                            Msgbox.setText("¡Equipo blanco!");
                            Msgbox.exec();
                        }
                        game->gameOver();

                    }
                    c++;

                }
            }
        }
        if(contrey==1){
            if(QString::compare(game->getTurn(),"WHITE")){
                game->check->setVisible(true);
                game->check->setPlainText("Ganador Negro");
                QMessageBox Msgbox;
                Msgbox.setWindowTitle("¡Ganador es !");
                Msgbox.setText("¡Equipo Negro!");
                Msgbox.exec();
            }
            else if(QString::compare(game->getTurn(),"BLACK")){
                game->check->setVisible(true);
                game->check->setPlainText("Ganador blanco");
                QMessageBox Msgbox;
                Msgbox.setWindowTitle("¡ganador es!");
                Msgbox.setText("¡Equipo blanco!");
                Msgbox.exec();
            }
            game->gameOver();
        }
        if(!c){
            game->check->setVisible(false);
            for(size_t i = 0,n=pList.size(); i < n; i++ )
                pList[i]->getCurrentCell()->resetOriginalColor();
              }
        }

//obtener el color de la pieza que se contiene
QString Locker::getPieceColor()
{
    return PieceColor;
}

//cambiazo el color de la pieza que se contiene
void Locker::setPieceColor(QString value)
{
    PieceColor = value;
}
