#include "enumbercurve.h"
#include "ui_enumbercurve.h"
#include <QImage>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QLabel>
#include <QtGui>
#include <cstdlib>
#include <ctime>

enumbercurve::enumbercurve(std::vector<float> timeA,std::vector<float> timeW,std::vector<float> timeD,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::enumbercurve)
{
    ui->setupUi(this);
    setWindowTitle("时间折线图");
    for(int i=0;i<timeA.size();i++){
        TA.push_back(timeA[i]);
        std::cout<<"time "<<timeA[i]<<std::endl;
    }
    for(int i=0;i<timeW.size();i++)
        TW.push_back(timeW[i]);
    for(int i=0;i<timeD.size();i++)
        TD.push_back(timeD[i]);
    image = QImage(1000,800,QImage::Format_RGB32);  //画布的初始化大小设为600*500，使用32位颜色
    QColor backColor = qRgb(255,255,255);    //画布初始化背景色使用白色
    image.fill(backColor);//对画布进行填充
    Paint();
}

enumbercurve::~enumbercurve()
{
    delete ui;
}

void enumbercurve::Paint()
{
    QPainter painter(&image);
        painter.setRenderHint(QPainter::Antialiasing, true);//设置反锯齿模式，好看一点


        int pointx=100,pointy=280;//确定坐标轴起点坐标，这里定义(35,280)
        int width=480-pointx,height=260;//确定坐标轴宽度跟高度 上文定义画布为600X300，宽高依此而定。

        //绘制坐标轴 坐标轴原点(35，280)
        //painter.drawRect(5,5,600-10,300-10);//外围的矩形，从(5,5)起，到(590,290)结束，周围留了5的间隙。

        painter.drawLine(pointx,pointy,width+pointx,pointy);//坐标轴x宽度为width
        painter.drawLine(pointx,pointy-height,pointx,pointy);//坐标轴y高度为height


        srand(time(NULL));

        //获得数据中最大值和最小值、平均数
        int n=30;//n为数据个数
        double sum=0;
        int _ma=0;//数组里的最大值
        int _mi=99999;

        for(int i=0;i<TA.size();i++)
            if(maxtimea<TA[i])
                maxtimea=TA[i];

        double kx=(double)width/(TA.size()-1); //x轴的系数
        double ky=(double)height/maxtimea;//y方向的比例系数
        QPen pen,penPoint;
        pen.setColor(Qt::black);
        pen.setWidth(2);

        penPoint.setColor(Qt::blue);
        penPoint.setWidth(5);
        for(int i=0;i<TA.size()-1;i++)
        {
            //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数
            painter.setPen(pen);//黑色笔用于连线
            painter.drawLine(pointx+kx*i,pointy-TA[i]*ky,pointx+kx*(i+1),pointy-TA[i+1]*ky);
            painter.setPen(penPoint);//蓝色的笔，用于标记各个点
            painter.drawPoint(pointx+kx*i,pointy-TA[i]*ky);
        }
        painter.drawPoint(pointx+kx*(TA.size()-1),pointy-TA[TA.size()-1]*ky);//绘制最后一个点


        //绘制刻度线
        QPen penDegree;
        penDegree.setColor(Qt::black);
        penDegree.setWidth(2);
        painter.setPen(penDegree);
        //画上x轴刻度线
        for(int i=0;i<TA.size();i++)//分成10份
        {
            //选取合适的坐标，绘制一段长度为4的直线，用于表示刻度
            painter.drawLine(pointx+(i)*kx,pointy,pointx+(i)*kx,pointy+4);
            painter.drawText(pointx+(i)*kx,
                             pointy+10,QString::number(i+1));
        }
        //y轴刻度线
        double _maStep=(double)maxtimea/10;//y轴刻度间隔需根据最大值来表示
        for(int i=0;i<10;i++)
        {
            //主要就是确定一个位置，然后画一条短短的直线表示刻度。
            painter.drawLine(pointx,pointy-(i+1)*height/10,
                             pointx-4,pointy-(i+1)*height/10);
            painter.drawText(pointx-80,pointy-(i+0.85)*height/10,
                             QString::number((float)(_maStep*(i+1))));
        }


        //TW
         pointx=100,pointy=600;//确定坐标轴起点坐标，这里定义(35,280)
         width=480-pointx,height=260;//确定坐标轴宽度跟高度 上文定义画布为600X300，宽高依此而定。

        //绘制坐标轴 坐标轴原点(35，280)
        //painter.drawRect(5,5,600-10,300-10);//外围的矩形，从(5,5)起，到(590,290)结束，周围留了5的间隙。

        painter.drawLine(pointx,pointy,width+pointx,pointy);//坐标轴x宽度为width
        painter.drawLine(pointx,pointy-height,pointx,pointy);//坐标轴y高度为height


        srand(time(NULL));

        //获得数据中最大值和最小值、平均数
        n=30;//n为数据个数
        sum=0;
        _ma=0;//数组里的最大值
        _mi=99999;

        for(int i=0;i<TW.size();i++)
            if(maxtimew<TW[i])
                maxtimew=TW[i];

        kx=(double)width/(TW.size()-1); //x轴的系数
        ky=(double)height/maxtimew;//y方向的比例系数
//        QPen pen,penPoint;
        pen.setColor(Qt::black);
        pen.setWidth(2);

        penPoint.setColor(Qt::blue);
        penPoint.setWidth(5);
        for(int i=0;i<TW.size()-1;i++)
        {
            //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数
            painter.setPen(pen);//黑色笔用于连线
            painter.drawLine(pointx+kx*i,pointy-TW[i]*ky,pointx+kx*(i+1),pointy-TW[i+1]*ky);
            painter.setPen(penPoint);//蓝色的笔，用于标记各个点
            painter.drawPoint(pointx+kx*i,pointy-TW[i]*ky);
        }
        painter.drawPoint(pointx+kx*(TW.size()-1),pointy-TW[TW.size()-1]*ky);//绘制最后一个点


        //绘制刻度线
//        QPen penDegree;
        penDegree.setColor(Qt::black);
        penDegree.setWidth(2);
        painter.setPen(penDegree);
        //画上x轴刻度线
        for(int i=0;i<TW.size();i++)
        {
            painter.drawLine(pointx+(i)*kx,pointy,pointx+(i)*kx,pointy+4);
            painter.drawText(pointx+(i)*kx,
                             pointy+10,QString::number(i+1));
        }
        //y轴刻度线
        _maStep=(double)maxtimew/10;//y轴刻度间隔需根据最大值来表示
        for(int i=0;i<10;i++)
        {
            //主要就是确定一个位置，然后画一条短短的直线表示刻度。
            painter.drawLine(pointx,pointy-(i+1)*height/10,
                             pointx-4,pointy-(i+1)*height/10);
            painter.drawText(pointx-80,pointy-(i+0.85)*height/10,
                             QString::number((float)(_maStep*(i+1))));
        }


        //TD
        pointx=500,pointy=280;//确定坐标轴起点坐标，这里定义(35,280)
        width=pointx-100,height=260;//确定坐标轴宽度跟高度 上文定义画布为600X300，宽高依此而定。

        //绘制坐标轴 坐标轴原点(35，280)
        //painter.drawRect(5,5,600-10,300-10);//外围的矩形，从(5,5)起，到(590,290)结束，周围留了5的间隙。

        painter.drawLine(pointx,pointy,width+pointx,pointy);//坐标轴x宽度为width
        painter.drawLine(pointx,pointy-height,pointx,pointy);//坐标轴y高度为height


        srand(time(NULL));

        //获得数据中最大值和最小值、平均数
        n=30;//n为数据个数
        sum=0;
        _ma=0;//数组里的最大值
        _mi=99999;

        for(int i=0;i<TD.size();i++)
            if(maxtimed<TD[i])
                maxtimed=TD[i];

        kx=(double)width/(TD.size()-1); //x轴的系数
        ky=(double)height/maxtimed;//y方向的比例系数
        //QPen pen,penPoint;
        pen.setColor(Qt::black);
        pen.setWidth(2);

        penPoint.setColor(Qt::blue);
        penPoint.setWidth(5);
        for(int i=0;i<TD.size()-1;i++)
        {
            //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数
            painter.setPen(pen);//黑色笔用于连线
            painter.drawLine(pointx+kx*i,pointy-TD[i]*ky,pointx+kx*(i+1),pointy-TD[i+1]*ky);
            painter.setPen(penPoint);//蓝色的笔，用于标记各个点
            painter.drawPoint(pointx+kx*i,pointy-TD[i]*ky);
        }
        painter.drawPoint(pointx+kx*(TD.size()-1),pointy-TD[TD.size()-1]*ky);//绘制最后一个点


        //绘制刻度线
        //QPen penDegree;
        penDegree.setColor(Qt::black);
        penDegree.setWidth(2);
        painter.setPen(penDegree);
        //画上x轴刻度线
        for(int i=0;i<TD.size();i++)//分成10份
        {
            //选取合适的坐标，绘制一段长度为4的直线，用于表示刻度
            painter.drawLine(pointx+(i)*kx,pointy,pointx+(i)*kx,pointy+4);
            painter.drawText(pointx+(i)*kx,
                             pointy+10,QString::number(i));
        }
        //y轴刻度线
        _maStep=(double)maxtimed/10;//y轴刻度间隔需根据最大值来表示
        for(int i=0;i<10;i++)
        {
            //主要就是确定一个位置，然后画一条短短的直线表示刻度。
            painter.drawLine(pointx,pointy-(i+1)*height/10,
                             pointx-4,pointy-(i+1)*height/10);
            painter.drawText(pointx-80,pointy-(i+0.85)*height/10,
                             QString::number((float)(_maStep*(i+1))));
        }
        QLabel *ed = new QLabel();
        ed->setText("深度优先");

}
