#include "enumber.h"
#include "ui_enumber.h"

enumber::enumber(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enumber)
{
    ui->setupUi(this);
    setWindowTitle("小小八数码");
    connect(ui->close,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->start,SIGNAL(clicked(bool)),this,SLOT(start()));
}

void enumber::start()
{
    std::cout<<"hello world"<<std::endl;
}

enumber::~enumber()
{
    delete ui;
}
