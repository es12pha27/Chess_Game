#include "ajedrez.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ajedrez w;
    w.show();
    return a.exec();
}
