#include "Locker.h"
#include <QDebug>
#include <iostream>
#include "Piece.h"
#include <QWidget>
Locker::Locker(int ib,int jb,const QString &text, QWidget *parent)
    : QToolButton(parent)
{
    setAcceptDrops(true);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    setText(text);
    x=ib;
    y=jb;
}
Locker::Locker():QToolButton(nullptr){
    setAcceptDrops(true);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    setText("");
}
//Seters
void Locker::setName(QString n){
        name=n;
}
void Locker::setX(int x){
        this->x=x;
}
void Locker::setY(int y){
        this->y=y;
}
void Locker::setStatus(bool s){
        status=s;
}

//Geters
int Locker::getX(){
    return x;
}
int Locker::getY(){
    return y;
}
QString Locker::getName(){
       return name;
}
bool Locker::getStatus(){
        return status;
}
void Locker::mousePressEvent(QMouseEvent *event)
{
auto child = static_cast<Piece*>(childAt(event->pos()));
if(child == nullptr)
{
    //std::cout<<"null\n";
    return;
}
//std::cout<<"child\n";
QByteArray data;
QDataStream dataStream(&data,QIODevice::WriteOnly);
QPixmap pixmap = *(child)->pixmap();
dataStream <<child<<pixmap;

QMimeData *mimeData=new QMimeData();
mimeData->setData("application/x-dnditemdata",data);

QDrag * drag=new QDrag(this);
drag->setMimeData(mimeData);
drag->setPixmap(pixmap);
drag->setHotSpot(event->pos() - child->pos());
drag->exec(Qt::CopyAction |Qt::MoveAction,Qt::CopyAction);
}


void Locker::dragMoveEvent(QDragMoveEvent *event) {
    std::cout<<"llego a DragMoveEvent\n";
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
            if (event->source() == this) {
                event->setDropAction(Qt::MoveAction);
                event->accept();
            } else {
                event->acceptProposedAction();
            }
        } else {
            event->ignore();
        }
}
void Locker::dropEvent(QDropEvent *event) {
      std::cout<<"llego a dropEvent\n";
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
           QByteArray data = event->mimeData()->data("application/x-dnditemdata");
           QDataStream dataStream(&data, QIODevice::ReadOnly);

           Piece* piece;
           QPixmap pixmap;
           dataStream>>piece>>pixmap;
           piece->setParent(this);
           piece->show();
        if (event->source() == this) {
                    event->setDropAction(Qt::MoveAction);
                    event->accept();
                } else {
                    event->acceptProposedAction();
                }
            } else {
                event->ignore();
            }
        }
void Locker::dragEnterEvent(QDragEnterEvent *event) {
    std::cout<<"llego a dragEnterEvent\n";

    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
            if (event->source() == this) {
                event->setDropAction(Qt::MoveAction);
                event->accept();
            } else {
                event->acceptProposedAction();
            }
        } else {
            event->ignore();
        }
}



