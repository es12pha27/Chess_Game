#include "ajedrez.h"
#include "./ui_ajedrez.h"

Ajedrez::Ajedrez(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Ajedrez)
{
    ui->setupUi(this);
}
//ajedrez

Ajedrez::~Ajedrez()
{
    delete ui;
}

