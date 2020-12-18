#include "mainwindow.h"
#include "Board.h"
#include <QApplication>

MainWindow *qmain;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    qmain = new MainWindow();
    qmain->show();
    return a.exec();
}
