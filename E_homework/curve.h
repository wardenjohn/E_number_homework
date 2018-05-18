#ifndef CURVE_H
#define CURVE_H

#include <QWidget>
#include "bp.h"
#include <iostream>
#include <vector>
#include <QPainter>

namespace Ui {
    class curve;
}

class curve : public QWidget{
    Q_OBJECT
public:
    explicit curve(std::vector<float> errorStack,QWidget *parent = 0);
    ~curve();
    //void paint_line(QPaintEvent *event);
    std::vector<float> err;
    double max=-1000;
    void Paint();
private:
    Ui::curve *ui;
    QImage image;protected:
protected:
    void paintEvent(QPaintEvent *){
        QPainter painter(this);
        painter.drawImage(0,0,image);
    }
};


#endif // CURVE_H
