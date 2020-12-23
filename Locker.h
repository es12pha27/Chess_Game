#ifndef Locker_H
#define Locker_H
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include "Piece.h"
#include <QTextEdit>

class Piece;
class Locker: public QObject, public QGraphicsRectItem
{
public:

    //Constructor
    Locker(QString text="",QGraphicsItem *parent=0);
    //destructor
    ~Locker();

    //se presione esa celda
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //cambiar de color
    void setColor(QColor color);
    //obtener el lugar de una pieza
    void placePiece(Piece *piece);

    //resetear al color original
    void resetOriginalColor();
    //cambia el color original
    void setOriginalColor(QColor value);

    //verificar si una celda tiene una pieza
    bool getHasPiece();
    //cambia la pieza que tiene
    void setHasPiece(bool value,Piece *piece = 0);

    void checkForCheck();

    //oobtiene el color de la pieza que contiene
    QString getPieceColor() ;
    void setPieceColor(QString value);
    int rowLoc;
    int colLoc;
    QString name=" ";
    Piece * currentPiece;
    void setText(QString text);
private:
    QColor originalColor;
    bool hasPiece;
    QBrush brush;
    QString PieceColor;
    QTextEdit cabecera;
    QGraphicsTextItem *texto;


};

#endif // Locker_H
