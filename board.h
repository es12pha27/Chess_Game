#ifndef BOARD_H
#define BOARD_H

//librerías externas QT
#include <QWidget>
#include <QPixmap>
#include <QPainter>

//libreria externa STL
#include <memory>

//librería local
#include "Piece.h"
namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();
    void paintEvent(QPaintEvent * event) override;
private:
    QPixmap BoardIcon;
    Ui::Board *ui;
    std::unique_ptr<Piece> piece;
};

#endif // BOARD_H
