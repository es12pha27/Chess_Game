#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Game.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_start_game_clicked()
{
Game *game=new Game();
game->show();
close();
}
