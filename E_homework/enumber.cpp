#include "enumber.h"
#include "ui_enumber.h"
#include <vector>
#include <QImage>
#include <QTime>

enumber::enumber(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enumber)
{
    ui->setupUi(this);
    setWindowTitle("小小八数码");
    init_pic();
    connect(ui->close,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->start,SIGNAL(clicked(bool)),this,SLOT(start()));
    connect(ui->load,SIGNAL(clicked(bool)),this,SLOT(loadp()));
}

void enumber::start()
{
    std::cout<<"hello world"<<std::endl;
    eight_number();
}

void enumber::eight_number()
{
    QTime t;
    while(true){
        t.start();
        loadp();
        while(t.elapsed()<1000)
            QCoreApplication::processEvents();
    }
}


//initial the picture
void enumber::init_pic()
{
    QImage *ice;
    ice = new QImage("/Users/zhangyongde/Desktop/E_number_homework/E_homework/element/0.png");
    imgstack.push_back(*ice);
    ice= new QImage("/Users/zhangyongde/Desktop/E_number_homework/E_homework/element/1.png");
    imgstack.push_back(*ice);
    ice= new QImage("/Users/zhangyongde/Desktop/E_number_homework/E_homework/element/2.png");
    imgstack.push_back(*ice);
    ice= new QImage("/Users/zhangyongde/Desktop/E_number_homework/E_homework/element/3.png");
    imgstack.push_back(*ice);
    ice= new QImage("/Users/zhangyongde/Desktop/E_number_homework/E_homework/element/4.png");
    imgstack.push_back(*ice);
    ice= new QImage("/Users/zhangyongde/Desktop/E_number_homework/E_homework/element/5.png");
    imgstack.push_back(*ice);
    ice= new QImage("/Users/zhangyongde/Desktop/E_number_homework/E_homework/element/6.png");
    imgstack.push_back(*ice);
    ice= new QImage("/Users/zhangyongde/Desktop/E_number_homework/E_homework/element/7.png");
    imgstack.push_back(*ice);
    ice= new QImage("/Users/zhangyongde/Desktop/E_number_homework/E_homework/element/8.png");
    imgstack.push_back(*ice);
}

//using a count to change picture,this is a loading picture function
int count=0;
void enumber::loadp()
{
    int width = ui->num00->width();
    int height = ui->num00->height();
    ui->num00->setPixmap(QPixmap::fromImage(imgstack[count%8]).scaled(width,height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->num01->setPixmap(QPixmap::fromImage(imgstack[(count+1)%8]).scaled(width,height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->num02->setPixmap(QPixmap::fromImage(imgstack[(count+2)%8]).scaled(width,height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->num10->setPixmap(QPixmap::fromImage(imgstack[(count+3)%8]).scaled(width,height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->num11->setPixmap(QPixmap::fromImage(imgstack[(count+4)%8]).scaled(width,height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->num12->setPixmap(QPixmap::fromImage(imgstack[(count+5)%8]).scaled(width,height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->num20->setPixmap(QPixmap::fromImage(imgstack[(count+6)%8]).scaled(width,height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->num21->setPixmap(QPixmap::fromImage(imgstack[(count+7)%8]).scaled(width,height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->num22->setPixmap(QPixmap::fromImage(imgstack[(count+8)%8]).scaled(width,height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    count++;
}

enumber::~enumber()
{
    delete ui;
}
