#ifndef BP_H
#define BP_H

#include "mainwindow.h"
#include <QMainWindow>
#include <QDialog>
#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include "curve.h"
#include "genercurve.h"
#define INNODE 2
#define HIDNODE 2
#define OUTNODE 2
#define TESTCASE 2
#define SAMPLE 25
#define SAM_UIT 2
namespace Ui {
    class bp;
}


class bp : public QWidget{
    Q_OBJECT
public:
    explicit bp(QWidget *parent = 0);
    ~bp();
    void paint_line(QPaintEvent *event);
    void bp_run_sin();
    void bp_run();
    void bp_run_add();
    void bp_run_square();
    void paint_pic();
private:
    Ui::bp *ui;
    int draw=1;
    QImage image;
public slots:
    void start();
    void show_curve();
    void show_mimic();
protected:
    void paintEvent(QPaintEvent *){
        QPainter painter(this);
        painter.drawImage(0,0,image);
    }
};

class innode{
public:
    float input;
};

class hidnode{
public:
    float output;
    float weight[HIDNODE];
    float net(innode in[], int innode_number);
    float out(float net, int hidnode_number);
    float out_max(float net,int hidnode_number);
    friend class Neo;
};

class outnode{
public:
     float output;
     float weight[HIDNODE];
     float net(hidnode hid[HIDNODE], int hidnnode_number);
     float out(float net,int outnode_number);
     float out_max(float net,int outnode_numebr);
     friend class Neo;
};

class Neo {
private:
    innode in[INNODE];
    hidnode hid[HIDNODE];
    outnode out[OUTNODE];
    float sample[INNODE][SAM_UIT];
    float Etotal;
    float nita;

public:
    int innodeN;
    int hidnodeN;
    int outnodeN;
    int max;
    int min;
    void run(float input[SAMPLE][SAM_UIT]);
    //void run(float input[SAMPLE][INNODE]);
    void caculate(float test[TESTCASE]);
    Neo(){
        Etotal=0;
        nita=0.001;
        max=-1000;
        min=9999;
    }
};

#endif // BP_H
