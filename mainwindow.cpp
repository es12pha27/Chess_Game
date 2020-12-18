#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showBoard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showBoard()
{
    chess = new Board();
    chess->initializeBoard();

}
