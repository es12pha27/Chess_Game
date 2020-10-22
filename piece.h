#ifndef PIECE_H
#define PIECE_H
#include <QLabel>
#include <QPixmap>
namespace ui{
class Piece;
}

class Piece :public QLabel{

    Q_OBJECT
public:
   explicit Piece(QWidget *parent =nullptr);
    virtual ~Piece(){};
private:
    ui::Piece *ui;
    QPixmap PieceIcon;
};

#endif // PIECE_H


