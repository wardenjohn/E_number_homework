#include "bp.h"
#include "ui_bp.h"
#include <iostream>
#include <QPainter>
#include <QTime>
#include <QMessageBox>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <fstream>
#define LAY_NUM 3
#define LOOP 300

static std::vector<float> errorStack;


bp::bp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bp)
{
    ui->setupUi(this);
    setWindowTitle("BP神经网络");
    connect(ui->start,SIGNAL(clicked()),this,SLOT(start()));
    connect(ui->close,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->error,SIGNAL(clicked()),this,SLOT(show_curve()));
    connect(ui->mimic,SIGNAL(clicked()),this,SLOT(show_mimic()));
    image = QImage(700,600,QImage::Format_RGB32);  //画布的初始化大小设为600*500，使用32位颜色
    QColor backColor = qRgb(255,255,255);    //画布初始化背景色使用白色
    image.fill(backColor);//对画布进行填充
}

bp::~bp()
{
    delete ui;
}

void bp::paint_pic()
{
    int waitime=100;
    waitime=ui->waittime->text().toInt();
    std::cout<<waitime<<std::endl;
    for(int i=0;i<errorStack.size();i++)
        std::cout<<errorStack[i]<<"???"<<std::endl;

    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing, true);//设置反锯齿模式，好看一点


    int pointx=100,pointy=400;//确定坐标轴起点坐标，这里定义(35,280)
    int width=580-pointx,height=300;//确定坐标轴宽度跟高度 上文定义画布为600X300，宽高依此而定。

        //绘制坐标轴 坐标轴原点(35，280)
        //painter.drawRect(5,5,600-10,300-10);//外围的矩形，从(5,5)起，到(590,290)结束，周围留了5的间隙。

    painter.drawLine(pointx,pointy,width+pointx,pointy);//坐标轴x宽度为width
    painter.drawLine(pointx,pointy-height,pointx,pointy);//坐标轴y高度为height
    int max=-1000;//数组里的最大值

    for(int i=0;i<errorStack.size();i++)
        if(errorStack[i]>max)
            max=errorStack[i];

    double kx=(double)width/(errorStack.size()); //x轴的系数
    double ky=(double)height/max;//y方向的比例系数
    QPen pen,penPoint;
    pen.setColor(Qt::black);
    pen.setWidth(2);

        penPoint.setColor(Qt::blue);
        penPoint.setWidth(5);
        //绘制刻度线
        QPen penDegree;
        penDegree.setColor(Qt::black);
        penDegree.setWidth(2);
        painter.setPen(penDegree);
        //画上x轴刻度线
        for(int i=0;i<errorStack.size();i++)
        {
            //选取合适的坐标，绘制一段长度为4的直线，用于表示刻度
            painter.drawLine(pointx+(i+1)*width/10,pointy,pointx+(i+1)*width/10,pointy+4);
            painter.drawText(pointx+(i+0.65)*width/10,
                             pointy+10,QString::number((int)((i+1)*((double)errorStack.size()))));
        }
        //y轴刻度线
        double _maStep=(double)max/10;//y轴刻度间隔需根据最大值来表示
        for(int i=0;i<10;i++)
        {
            //主要就是确定一个位置，然后画一条短短的直线表示刻度。
            painter.drawLine(pointx,pointy-(i+1)*height/10,
                             pointx-4,pointy-(i+1)*height/10);
            painter.drawText(pointx-80,pointy-(i+0.85)*height/10,
                             QString::number((float)(_maStep*(i+1))));
        }
        update();
        QTime t;
        for(int i=0;i<errorStack.size()-1;i++)
        {
            //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数
            t.start();
            while(t.elapsed()<waitime)
                QCoreApplication::processEvents();
            painter.setPen(pen);//黑色笔用于连线
            painter.drawLine(pointx+kx*i,pointy-errorStack[i]*ky,pointx+kx*(i+1),pointy-errorStack[i+1]*ky);
            painter.setPen(penPoint);//蓝色的笔，用于标记各个点
            painter.drawPoint(pointx+kx*i,pointy-errorStack[i]*ky);
            update();
        }
        painter.drawPoint(pointx+kx*(errorStack.size()-1),pointy-errorStack[errorStack.size()-1]*ky);//绘制最后一个点
}

void bp::show_mimic()
{
    genercurve *gen = new genercurve();
    gen->show();
}

void bp::show_curve()
{
    curve *cu = new curve(errorStack);
    cu->show();
}

void bp::start()
{
    bp_run();
}

void Neo::caculate(float test[])
{

}

void bp::bp_run()
{
    if(ui->addfun->isChecked()){
        errorStack.clear();
        bp_run_add();
    }
    else if(ui->sinfun->isChecked()){
        errorStack.clear();
        bp_run_sin();
    }else if(ui->squarefun->isChecked()){
        errorStack.clear();
        bp_run_square();
    }else{
        QMessageBox::critical(0,"no function selected","No function selected",
                              QMessageBox::Ok|QMessageBox::Default,QMessageBox::Cancel|QMessageBox::Escape,0);
    }
}

void bp::bp_run_add()
{
    Neo neo;
    std::fstream file;
    neo.innodeN=2;
    neo.hidnodeN=2;
    neo.outnodeN=1;
    file.open("/Users/zhangyongde/Desktop/DEEP/sample_add.txt");
    if(!file.is_open()){
        std::cout<<"open file failed "<<std::endl;
        return ;
    }

    int sample_number=30;
    float sample[sample_number][3];
    for(int i=0;i<sample_number;i++){
        file>>sample[i][0]>>sample[i][1]>>sample[i][2];
    }

    //归一化
    float max=-1000;
    float min=9999;
    for(int i=0;i<sample_number;i++){

    }
}

void bp::bp_run_square()
{
    Neo neo;
    neo.innodeN=1;
    neo.outnodeN=1;
    neo.hidnodeN=2;
    float sample[SAMPLE][SAM_UIT];
        std::fstream file;
        file.open("/Users/zhangyongde/Desktop/DEEP/sample_squ.txt");
        if(!file.is_open()){
            std::cout<<"open file failed"<<std::endl;
            return ;
        }

        float testcase[TESTCASE];

        for(int i=0;i<SAMPLE;i++){
            file>>sample[i][0]>>sample[i][1];
        }

        float tem=0;
        for(int i=0;i<TESTCASE;i++)
            file>>testcase[i]>>tem;

        for(int i=0;i<SAMPLE;i++){
            if(sample[i][0]>neo.max)
                neo.max=sample[i][0];
        }
        for (int i=0; i<SAMPLE; i++) {
            if(sample[i][0]<neo.min)
                neo.min=sample[i][0];
        }

        //归一化
        for(int i=0;i<SAMPLE;i++){
            sample[i][0] =(sample[i][0]-neo.min)/(neo.max-neo.min);
        }

        for(int i=0;i<SAMPLE;i++){
            std::cout<<sample[i][0]<<std::endl;
        }

        for(int i=0;i<TESTCASE;i++){
            std::cout<<testcase[i]<<std::endl;
            testcase[i]=(testcase[i]-neo.min)/(neo.max-neo.min);
        }

        neo.run(sample);
        neo.caculate(testcase);

        paint_pic();
}

void bp::bp_run_sin()
{
    Neo neo;
    neo.innodeN=1;
    neo.hidnodeN=2;
    neo.outnodeN=1;
    float sample[SAMPLE][SAM_UIT];
        std::fstream file;
        file.open("/Users/zhangyongde/Desktop/DEEP/sample_raw.txt");
        if(!file.is_open()){
            std::cout<<"open file failed"<<std::endl;
            return ;
        }

        float testcase[TESTCASE];

        for(int i=0;i<SAMPLE;i++){
            file>>sample[i][0]>>sample[i][1];
        }

        float tem=0;
        for(int i=0;i<TESTCASE;i++)
            file>>testcase[i]>>tem;

        for(int i=0;i<SAMPLE;i++){
            if(sample[i][0]>neo.max)
                neo.max=sample[i][0];
        }
        for (int i=0; i<SAMPLE; i++) {
            if(sample[i][0]<neo.min)
                neo.min=sample[i][0];
        }

        //归一化
        for(int i=0;i<SAMPLE;i++){
            sample[i][0] =(sample[i][0]-neo.min)/(neo.max-neo.min);
        }

        for(int i=0;i<SAMPLE;i++){
            std::cout<<sample[i][0]<<std::endl;
        }

        for(int i=0;i<TESTCASE;i++){
            std::cout<<testcase[i]<<std::endl;
            testcase[i]=(testcase[i]-neo.min)/(neo.max-neo.min);
        }

        neo.run(sample);
        neo.caculate(testcase);

        paint_pic();
}

/*void Neo::run(float input[SAMPLE][INNODE])
{
        hid[0].weight[0]=0.15;
        hid[0].weight[1]=0.2;
        hid[1].weight[0]=0.25;
        hid[1].weight[1]=0.3;
        out[0].weight[0]=0.4;
        out[0].weight[1]=0.45;
        out[1].weight[0]=0.5;
        out[1].weight[1]=0.55;
    for(int i=0;i<HIDNODE;i++)
        for(int j=0;j<INNODE;j++)
            hid[i].weight[j]=0.5;//inital the weight to innode for each hidnode
    for(int i=0;i<OUTNODE;i++)
        for(int j=0;j<HIDNODE;j++)
            out[i].weight[j]=0.5;
    srand((unsigned int)time(NULL));
    //反复训练LOOP次
    for(int looping=0;looping<LOOP;looping++){
        for(int sam=0;sam<SAMPLE/2;sam++){
            in[0].input=input[sam][0];
            in[1].input=input[sam+25][0];
            for(int i=0;i<INNODE;i++){
                float net = hid[i].net(in);
                hid[i].out(net);
            }//逐层向前计算
            for(int i=0;i<OUTNODE;i++){
                float net = out[i].net(hid);
                out[i].out(net);
            }
            float tem=0;
            for(int i=0;i<OUTNODE;i++){
                tem+= 0.5*(input[i][1] - out[i].output)*(input[i][1]-out[i].output);//0.5 sqrt
            }//计算总体误差

            Etotal=tem;
            if(looping%100==0)
                errorStack.push_back(Etotal);

            float epxino = -(input[0][1]-out[0].output)*out[0].output*(1-out[0].output)*hid[0].output;
            out[0].weight[0] = out[0].weight[0]-nita*epxino;
            epxino=-(input[0][1]-out[0].output)*out[0].output*(1-out[0].output)*hid[1].output;
            out[0].weight[1] = out[0].weight[1]-nita*epxino;

            epxino=-(input[1][1]-out[1].output)*(1-out[1].output)*out[1].output*hid[0].output;
            out[1].weight[0]=out[1].weight[0]-nita*epxino;//sample[1][1] 为第二个sample的output
            epxino=-(input[1][1]-out[1].output)*out[1].output*(1-out[1].output)*hid[1].output;
            out[1].weight[1]+=-nita*epxino;

            //从隐藏层到隐藏层
            epxino=((-(input[0][1]-out[0].output)*out[0].output*(1-out[0].output))+(-(input[1][1]-out[1].output)*out[1].output*(1-out[1].output)))*hid[0].output*(1-hid[0].output)*in[0].input;
            hid[0].weight[0] = hid[0].weight[0]-nita*epxino;
            epxino=((-(input[0][1]-out[0].output)*out[0].output*(1-out[0].output))+(-(input[1][1]-out[1].output)*out[1].output*(1-out[1].output)))*hid[0].output*(1-hid[0].output)*in[1].input;
            hid[0].weight[1]=hid[0].weight[1]-nita*epxino;
            epxino=((-(input[1][1]-out[1].output)*out[0].output*(1-out[0].output))+(-(input[1][1]-out[1].output)*out[1].output*(1-out[1].output)))*hid[1].output*(1-hid[1].output)*in[0].input;
            hid[1].weight[0]=hid[1].weight[0]-nita*epxino;
            epxino=((-(input[0][1]-out[0].output)*out[0].output*(1-out[0].output))+(-(input[1][1]-out[1].output)*out[1].output*(1-out[1].output)))*hid[1].output*(1-hid[1].output)*in[1].input;
            hid[1].weight[1]=hid[1].weight[1]-nita*epxino;

        }
    }

    for(int i=0;i<HIDNODE;i++){
        std::cout<<hid[i].output<<std::endl;
    }
}*/
/*
void Neo::run(float input[SAMPLE][INNODE])
{
        hid[0].weight[0]=0.15;
        hid[0].weight[1]=0.2;
        hid[1].weight[0]=0.25;
        hid[1].weight[1]=0.3;
        out[0].weight[0]=0.4;
        out[0].weight[1]=0.45;
        out[1].weight[0]=0.5;
        out[1].weight[1]=0.55;//initial the weight
    for(int looping=0;looping<LOOP;looping++){
        for(int sam=0;sam<SAMPLE/2;sam++){
            in[0].input=input[0][0];
            in[1].input=input[1][0];

            for(int i=0;i<INNODE;i++){
                float net = hid[i].net(in);
                hid[i].out(net);
            }//逐层向前计算
            for(int i=0;i<OUTNODE;i++){
                float net = out[i].net(hid);
                out[i].out(net);
            }
            float tem=0;
            for(int i=0;i<OUTNODE;i++){
                tem+= 0.5*(input[i][1] - out[i].output)*(input[i][1]-out[i].output);//0.5 sqrt
            }//计算总体误差
            Etotal=tem;
            if(looping%100==0)
                errorStack.push_back(Etotal);
            //输出层到隐藏层
            for(int i=0;i<OUTNODE;i++){
                for(int j=0;j<HIDNODE;j++){
                    float exip=hid[j].output*out[i].output*(1-out[i].output)*(input[i][1]-hid[i].output);
                    out[i].weight[j] = out[i].weight[j] - nita*exip;
                }
            }

            float dao1=-(input[0][1]-out[0].output)*out[0].output*(1-out[0].output)*out[0].weight[0];
            float dao2=-(input[1][1]-out[1].output)*out[1].output*(1-out[1].output)*out[1].weight[0];
            float mut=hid[0].output*(1-hid[0].output)*in[0].input;
            hid[0].weight[0]=hid[0].weight[0]-nita*(dao1+dao2)*mut;

            mut=hid[0].output*(1-hid[0].output)*in[1].input;
            hid[0].weight[1]=hid[0].weight[1]-nita*(dao1+dao2)*mut;

            dao1=-(input[0][1]*out[1].output)*out[1].output*(1-out[1].output)*out[0].weight[1];
            dao2=-(input[1][1]*out[1].output)*out[1].output*(1-out[1].output)*out[1].weight[1];
            mut=hid[1].output*(1-hid[1].output)*in[0].input;

            hid[1].weight[0]=hid[1].weight[0]-nita*(dao1+dao2)*mut;

            mut=hid[1].output*(1-hid[1].output)*in[1].input;
            hid[1].weight[0]=hid[1].weight[0]-nita*(dao1+dao2)*mut;
        }
    }
}*/


void Neo::run(float input[SAMPLE][SAM_UIT])
{
    hid[0].weight[0]=0.4;hid[0].weight[1]=0.5;
        hid[1].weight[0]=0.3;hid[1].weight[1]=-0.5;
        out[0].weight[0]=0.25;out[0].weight[1]=-0.3;

        for(int looping=0;looping<LOOP;looping++){//循环loop次
            float tot=0;
            for(int sam=0;sam<SAMPLE;sam++){//遍历样本
                in[0].input = input[sam][0];
                //正向计算
                for(int i=0;i<hidnodeN;i++){
                    float net = hid[i].net(in,innodeN);
                    hid[i].out(net,hidnodeN);
                }
                for(int i=0;i<outnodeN;i++){
                    float net = out[i].net(hid,hidnodeN);
                    out[i].out(net,outnodeN);
                }
                //反向传播
                out[0].weight[0] = out[0].weight[0] - nita*hid[0].output*out[0].output*(1-out[0].output)*(input[sam][1]-out[0].output);
                out[0].weight[1] = out[0].weight[1] - nita*hid[1].output*out[0].output*(1-out[0].output)*(input[sam][1]-out[0].output);

                float tem=0;
                for(int i=0;i<outnodeN;i++){
                    tem+= 0.5*(input[sam][1] - out[i].output)*(input[sam][1]-out[i].output);//0.5 sqrt
                }//计算总体误差
                tot+=tem;
                Etotal=tem;
                std::cout<<Etotal<<"}}}"<<std::endl;
                if(looping%100==0)
                    errorStack.push_back(Etotal);

                float mut = out[0].weight[0]*out[0].output*(1-out[0].output)*(input[sam][1]-out[0].output);
                hid[0].weight[0]=hid[0].weight[0]-nita*hid[0].output*(1-hid[0].output)*mut*in[0].input;
                mut = out[0].weight[1]*out[0].output*(1-out[0].output)*(input[sam][1]-out[0].output);
                hid[1].weight[0]=hid[1].weight[0]-nita*hid[1].output*(1-hid[1].output)*mut*in[0].input;
            }

        }
        std::cout<<out[0].output<<std::endl;
}


//hidnode function
float hidnode::net(innode in[],int innode_number)
{
    float net=0;
    for(int i=0;i<innode_number;i++){
        net += in[i].input*weight[i];//secific weight to the node
    }
    return net;
}

float hidnode::out(float net, int hidnode_number)
{
    float out=0;
    out = 1.0/(1+exp(-net));
    output=out;
    return out;
}

float outnode::net(hidnode hid[],int hidnnode_number)
{
    float net=0;
    for(int i=0;i<hidnnode_number;i++)
        net += weight[i]*hid[i].output;
    return net;
}

float outnode::out(float net, int outnode_number)
{
    float out=0;
    for(int i=0;i<outnode_number;i++){
        out=1.0/(1+exp(-net));
    }
    float a=0.25;
    output=out;
    return out;
}


float outnode::out_max(float net, int outnode_numebr)
{
    float a=0.25;
    float out=0;
    if(a*net>net)
        out=a*net;
    else
        out=net;
    output=net;
    return out;
}

float hidnode::out_max(float net, int hidnode_number)
{
    float a=0.25;
    float out=0;
    if(a*net>net)
        out=a*net;
    else
        out=net;
    output=net;
    return out;
}
