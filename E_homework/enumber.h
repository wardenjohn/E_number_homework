#ifndef ENUMBER_H
#define ENUMBER_H

#include <QMainWindow>
#include <QDialog>
#include <iostream>
#include <vector>
#include <queue>

#define NUM_UNIT 9
#define UP 1
#define LEFT 2
#define RIGHT 3
#define DOWN 4
#define MAX_DEPT 25
#define WAIT 1000

namespace Ui {
class enumber;
}

typedef struct node{
    int disk[3][3];
    int parent;
    int dir;
    int dept;
    int f;
    std::vector<node *> child;
    std::string targ;
}node;


class enumber : public QDialog
{
    Q_OBJECT

public:
    explicit enumber(QWidget *parent = 0);
    ~enumber();
    void init_pic();
    void run_deep();
    void run_width();
    void run_star();
    void run_compare();
    bool have_slove();
    int find_small(int x,int desk[]);
    int count=0;
    int pos_closed=0;//show the location of the top of the close table,which is count from 0
    int check=0;//to record how many is the same as one in the close table
    std::vector<float> timeA;
    std::vector<float> timew;
    std::vector<float> timed;
private:
    Ui::enumber *ui;
    std::vector<QImage> imgstack;
    std::vector<node *> open;
    std::vector<node *> closed;
    std::vector<node *> ans;
    int desk[9]={-1};
    std::string show_terminal;
    std::string end = "123804765";
    int flag_sample;
public slots:
    void start();
    void loadp(node *n);
    void eight_number();
public:
    bool isEnd(node *n);
    int findZero(node *n);
    int move();
    void init();
    void print();
    //deep search
    void init_deep();
    int move_deep();
    void creat_targ(node *n);
    node* inClosed(node *n);
    int inCloseOrOpen(node *p, node *bestnode);
    //A*
    void init_star();
    int move_star();
    node* find_f();
    int caculate_f(node *n);
    node* inOpen(node *n);
private slots:
    void on_textBrowser_textChanged();

};

#endif // ENUMBER_H
