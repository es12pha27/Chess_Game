
#include <QApplication>
#include "core.h"
Core* core;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    core = new Core();
    core->show();
    core->displayMainMenu();
    return a.exec();
}
