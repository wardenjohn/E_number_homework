#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("模拟小玩具");
    connect(ui->eight_number,SIGNAL(clicked(bool)),this,SLOT(enter_eigth_number()));
    //connect(ui->traveler,SIGNAL(clicked(bool)),this,SLOT(enter_traveler()));
    connect(ui->Neonet,SIGNAL(clicked(bool)),this,SLOT(enter_neonet()));
}

void MainWindow::enter_eigth_number()
{
    numWin = new enumber();
    numWin->show();
}

void MainWindow::enter_traveler()
{

}

void MainWindow::enter_neonet()
{
    bp *neo = new bp();
    neo->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
