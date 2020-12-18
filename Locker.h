#ifndef LOCKER_H
#define LOCKER_H

#include <QToolButton>
#include <QtWidgets>

#include <memory>

namespace Ui {
class Locker;
}

class Locker:public QToolButton
{
    Q_OBJECT
private:

    int x;
    int y;
    QString name=" "; //Nombre de la celda
    bool status=false;  //Indicara si esta ocupado o desocupado
    Locker* direccion=this;


public:
    //Los contructores
    Locker(int ib,int jb,const QString &text, QWidget *parent = nullptr);
    Locker();
    //Seters
    void setName(QString n);
    void setX(int x);
    void setY(int y);
    void setStatus(bool s);

    //Geters
    int getX();
    int getY();
    QString getName();
    bool getStatus();

    //Movimiento piezas
    void mousePressEvent(QMouseEvent *event);
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;

};

#endif // LOCKER_H
