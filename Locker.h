#ifndef CHESSCELL_H
#define CHESSCELL_H
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include "chesspiece.h"
#include <QTextEdit>

class ChessPiece;
class ChessCell: public QObject, public QGraphicsRectItem
{
public:

    //Constructor
    ChessCell(QString text="",QGraphicsItem *parent=0);
    //destructor
    ~ChessCell();

    //se presione esa celda
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //cambiar de color
    void setColor(QColor color);
    //obtener el lugar de una pieza
    void placePiece(ChessPiece *piece);

    //resetear al color original
    void resetOriginalColor();
    //cambia el color original
    void setOriginalColor(QColor value);

    //verificar si una celda tiene una pieza
    bool getHasChessPiece();
    //cambia la pieza que tiene
    void setHasChessPiece(bool value,ChessPiece *piece = 0);

    void checkForCheck();

    //oobtiene el color de la pieza que contiene
    QString getChessPieceColor() ;
    void setChessPieceColor(QString value);
    int rowLoc;
    int colLoc;
    QString name=" ";
    ChessPiece * currentPiece;
    void setText(QString text);
private:
    QColor originalColor;
    bool hasChessPiece;
    QBrush brush;
    QString chessPieceColor;
    QTextEdit cabecera;
    QGraphicsTextItem *texto;


};

#endif // CHESSCELL_H
