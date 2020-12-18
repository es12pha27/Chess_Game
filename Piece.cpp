#include "Piece.h"
#include <QDebug>
 Piece::Piece(QWidget *parent): QLabel(parent)
{
}
QString Piece::getName(){

     return name;
 }

QDataStream& operator>>(QDataStream &s, Piece *&piece_ptr){
    qulonglong ptrval;
    s>>ptrval;
    piece_ptr = reinterpret_cast<Piece*>(ptrval);
    return s;
}

QDataStream& operator<<(QDataStream &s, const Piece *piece_ptr){
    qulonglong ptrval=reinterpret_cast<qulonglong>(piece_ptr);
    return s<<ptrval;
}
bool Piece::getColor(){
    return color;
}
//si se capturó o no
bool Piece::getStatus(){
    return status;
}
//verifica si me encuentro
//en posición muerta
bool Piece::getCan_move(){
    return can_move;
}
void Piece::movePiece(){

};

//los posibles caminos
void Piece::getPath(){};
