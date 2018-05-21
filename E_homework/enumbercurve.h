#ifndef ENUMBERCURVE_H
#define ENUMBERCURVE_H

#include <QWidget>
#include "enumber.h"
#include <iostream>
#include <vector>
#include <QPainter>

namespace Ui {
    class enumbercurve;
}

class enumbercurve : public QWidget{
    Q_OBJECT
public:
    explicit enumbercurve(std::vector<float> timeA,std::vector<float> timeW,std::vector<float> timeD,QWidget *parent = 0);
    ~enumbercurve();
    double maxtimew=-1000;
    double maxtimed=-1000;
    double maxtimea=-1000;
    std::vector<float> TA;
    std::vector<float> TW;
    std::vector<float> TD;
    void Paint();
private:
    Ui::enumbercurve *ui;
    QImage image;
protected:
    void paintEvent(QPaintEvent *){
        QPainter painter(this);
        painter.drawImage(0,0,image);
    }
};
#endif // ENUMBERCURVE_H
