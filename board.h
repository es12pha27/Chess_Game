#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>

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

};

#endif // BOARD_H
