#ifndef GENERCURVE_H
#define GENERCURVE_H

#include <QWidget>
#include "bp.h"
#include <iostream>
#include <vector>
#include <QPainter>

namespace Ui {
    class genercurve;
}

class genercurve : public QWidget{
    Q_OBJECT
public:
    explicit genercurve(QWidget *parent = 0);
    ~genercurve();
    //void paint_line(QPaintEvent *event);
    std::vector<float> err;
    double max=-1000;
    void Paint();
private:
    Ui::genercurve *ui;
    QImage image;
protected:
    void paintEvent(QPaintEvent *){
        QPainter painter(this);
        painter.drawImage(0,0,image);
    }
};


#endif // GENERCURVE_H
