#include "Game.h"
#include "ui_Game.h"

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
}

Game::~Game()
{
    delete ui;
}
