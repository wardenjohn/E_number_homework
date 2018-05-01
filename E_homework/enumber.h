#ifndef ENUMBER_H
#define ENUMBER_H

#include <QMainWindow>
#include <QDialog>
#include <iostream>
#include <vector>
#include <queue>

namespace Ui {
class enumber;
}

typedef struct node{
    int disk[3][3];
    int parent;
    int dir;
}node;


class enumber : public QDialog
{
    Q_OBJECT

public:
    explicit enumber(QWidget *parent = 0);
    ~enumber();
    void init_pic();
    void eight_number();
    void run_deep();
    void run_width();
    int count=0;
    int pos_closed=0;
private:
    Ui::enumber *ui;
    std::vector<QImage> imgstack;
    std::vector<node *> open;
    std::vector<node *> closed;
    std::vector<node *> ans;
    int desk[9]={-1};
    std::string show_terminal;
    std::string end = "123804765";
public slots:
    void start();
    void loadp(node *n);

public:
    bool isEnd(node *n);
    int findZero(node *n);
    int move();
    void init();
    void print();
};

#endif // ENUMBER_H
