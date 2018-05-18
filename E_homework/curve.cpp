#include "curve.h"
#include "ui_curve.h"
#include <QImage>
#include <QMainWindow>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QtGui>
#include<cstdlib>
#include<ctime>

curve::curve(std::vector<float> errorStack, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::curve)
{
    ui->setupUi(this);
    setWindowTitle("误差曲线");
    for(int i=0;i<errorStack.size();i++){
        std::cout<<errorStack[i]<<std::endl;
        if(errorStack[i]>max)
            max=errorStack[i];
        err.push_back(errorStack[i]);
    }
    image = QImage(600,500,QImage::Format_RGB32);  //画布的初始化大小设为600*500，使用32位颜色
    QColor backColor = qRgb(255,255,255);    //画布初始化背景色使用白色
    image.fill(backColor);//对画布进行填充
    Paint();
}

curve::~curve()
{
    delete ui;
}

//void curve::paintEvent(QPaintEvent *event)
//{

//}
void curve::Paint()
{
    QPainter painter(&image);
        painter.setRenderHint(QPainter::Antialiasing, true);//设置反锯齿模式，好看一点


        int pointx=100,pointy=280;//确定坐标轴起点坐标，这里定义(35,280)
        int width=580-pointx,height=260;//确定坐标轴宽度跟高度 上文定义画布为600X300，宽高依此而定。

        //绘制坐标轴 坐标轴原点(35，280)
        painter.drawRect(5,5,600-10,300-10);//外围的矩形，从(5,5)起，到(590,290)结束，周围留了5的间隙。

        painter.drawLine(pointx,pointy,width+pointx,pointy);//坐标轴x宽度为width
        painter.drawLine(pointx,pointy-height,pointx,pointy);//坐标轴y高度为height


        srand(time(NULL));

        //获得数据中最大值和最小值、平均数
        int n=30;//n为数据个数
        double sum=0;
        double ave=0;
        int _ma=0;//数组里的最大值
        int _mi=99999;

        int a[n];//数据储存在数组a中，大小为n

        for(int i=0;i<n;i++)
            a[i]=rand()%40+20;
        int maxpos=0,minpos=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            if(a[i]>_ma){
                _ma=a[i];
                maxpos=i;
            }
            if(a[i]<_mi){
                _mi=a[i];
                minpos=i;
            }
        }
        ave=sum/n;//平均数

        double kx=(double)width/(err.size()-1); //x轴的系数
        double ky=(double)height/max;//y方向的比例系数
        QPen pen,penPoint;
        pen.setColor(Qt::black);
        pen.setWidth(2);

        penPoint.setColor(Qt::blue);
        penPoint.setWidth(5);
        for(int i=0;i<err.size();i++)
        {
            //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数
            painter.setPen(pen);//黑色笔用于连线
            painter.drawLine(pointx+kx*i,pointy-err[i]*ky,pointx+kx*(i+1),pointy-err[i+1]*ky);
            painter.setPen(penPoint);//蓝色的笔，用于标记各个点
            painter.drawPoint(pointx+kx*i,pointy-err[i]*ky);
        }
        painter.drawPoint(pointx+kx*(err.size()-1),pointy-err[err.size()-1]*ky);//绘制最后一个点

        //绘制平均线
//        QPen penAve;
//        penAve.setColor(Qt::red);//选择红色
//        penAve.setWidth(2);
//        penAve.setStyle(Qt::DotLine);//线条类型为虚线
//        painter.setPen(penAve);
//        painter.drawLine(pointx,pointy-ave*ky,pointx+width,pointy-ave*ky);

//        //绘制最大值和最小值
//        QPen penMaxMin;
//        penMaxMin.setColor(Qt::darkGreen);//暗绿色
//        painter.setPen(penMaxMin);
//        painter.drawText(pointx+kx*maxpos-kx,pointy-a[maxpos]*ky-5,
//                         "最大值"+QString::number(_ma));
//        painter.drawText(pointx+kx*minpos-kx,pointy-a[minpos]*ky+15,
//                         "最小值"+QString::number(_mi));

//        penMaxMin.setColor(Qt::red);
//        penMaxMin.setWidth(7);
//        painter.setPen(penMaxMin);
//        painter.drawPoint(pointx+kx*maxpos,pointy-a[maxpos]*ky);//标记最大值点
//        painter.drawPoint(pointx+kx*minpos,pointy-a[minpos]*ky);//标记最小值点


        //绘制刻度线
        QPen penDegree;
        penDegree.setColor(Qt::black);
        penDegree.setWidth(2);
        painter.setPen(penDegree);
        //画上x轴刻度线
        for(int i=0;i<err.size();i++)//分成10份
        {
            //选取合适的坐标，绘制一段长度为4的直线，用于表示刻度
            painter.drawLine(pointx+(i+1)*width/10,pointy,pointx+(i+1)*width/10,pointy+4);
            painter.drawText(pointx+(i+0.65)*width/10,
                             pointy+10,QString::number((int)((i+1)*((double)err.size()))));
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
}
