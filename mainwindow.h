#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Locker.h"
#include "Piece.h"
#include "Board.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Locker *collection[10][10];
    void showBoard();
    int num=5;
    Piece* pieceToMove;
    QList <Piece*> piecesInGame;
private:
    Ui::MainWindow *ui;
    Board *chess;
};
#endif // MAINWINDOW_H
