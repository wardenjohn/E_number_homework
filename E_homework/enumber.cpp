#include "enumber.h"
#include "ui_enumber.h"
#include "enumbercurve.h"
#include <vector>
#include <QImage>
#include <QTime>
#include <sys/time.h>

    enumber::enumber(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::enumber)
    {
        ui->setupUi(this);
        setWindowTitle("小小八数码");
        connect(ui->close,SIGNAL(clicked(bool)),this,SLOT(close()));
        connect(ui->start,SIGNAL(clicked(bool)),this,SLOT(start()));
        connect(ui->pic,SIGNAL(clicked(bool)),this,SLOT(eight_number()));
        flag_sample=0;
    }

//initial the picture
void enumber::init_pic()
{
    QImage *ice;
    ice= new QImage(":/image/0");
    imgstack.push_back(*ice);
    ice= new QImage(":/image/1");
    imgstack.push_back(*ice);
    ice= new QImage(":/image/2");
    imgstack.push_back(*ice);
    ice= new QImage(":/image/3");
    imgstack.push_back(*ice);
    ice= new QImage(":/image/4");
    imgstack.push_back(*ice);
    ice= new QImage(":/image/5");
    imgstack.push_back(*ice);
    ice= new QImage(":/image/6");
    imgstack.push_back(*ice);
    ice= new QImage(":/image/7");
    imgstack.push_back(*ice);
    ice= new QImage(":/image/8");
    imgstack.push_back(*ice);

    //loadp(open[0]);
}

int enumber::find_small(int x,int desk[])
{
    int count=0;
    for(int i=0;i<NUM_UNIT;i++){
        if(desk[i] == x)
            return count;
        if(desk[i]<x)
            count++;
    }
}

bool enumber::have_slove()
{
    int target=0,init_status=0;
    int pool_end[NUM_UNIT];
    for(int i=0;i<NUM_UNIT;i++)
        pool_end[i]=end[i]-'0';

    for(int i=1;i<NUM_UNIT;i++)
        init_status+=find_small(i,desk);

    for(int i=1;i<NUM_UNIT;i++)
        target+=find_small(i,pool_end);

    if(target%2==0 && init_status%2==0)
        return true;
    else if(target%2 == 1 && init_status%2==1)
        return true;
    else
        return false;
}

void enumber::init(){
    //desk[0]=2;desk[1]=8;desk[2]=3;desk[3]=1;desk[4]=6;desk[5]=4;desk[6]=7;desk[7]=0;desk[8]=5;
    //initial the first disk,which is the initial status of the running,giving the first status in randomly
    open.clear();
    closed.clear();
    ans.clear();
    int count=0;
    int pos_closed=0;
    int check=0;
    node first;
    for(int i=0;i<9;i++){
        first.disk[i/3][i%3] = desk[i];
    }
    first.dir=-1;
    first.parent=-1;
    open.push_back(&first);
    loadp(open.back());
}

void enumber::start()
{
    srand((unsigned)time(NULL));
    int flags[NUM_UNIT]={0};

    //initial the diks and flag into zero
    for(int i=0;i<NUM_UNIT;i++){
        desk[i]=-1;
        flags[i]=0;
    }

    int count_flag=0;//这个为产生的数所放的位置
    flags[5]=1;flags[6]=1;flags[7]=1;
    desk[6]=7;desk[7]=6;desk[8]=5;
    while(count_flag<5){
        int tem = rand()%5;
        if(flags[tem] == 0){//it means that this number is not been created
            flags[tem]=1;
            if(desk[count_flag] == -1){
                desk[count_flag]=tem;
                count_flag++;
            }
        }
        std::cout<<count_flag<<std::endl;
    }
    desk[count_flag]=8;

    //random completely
//    while(count_flag<9){
//        int tem=rand()%9;
//        if(flags[tem]==0){
//            flags[tem]=1;
//            if(desk[count_flag]==-1)
//            {
//                desk[count_flag]=tem;
//                count_flag++;
//            }
//        }
//    }

//    desk[0]=2;desk[1]=8;desk[2]=3;desk[3]=1;desk[4]=6;desk[5]=4;desk[6]=7;desk[7]=0;desk[8]=5;
//    //initial the first disk,which is the initial status of the running,giving the first status in randomly

//    node first;
//    for(int i=0;i<9;i++){
//        first.disk[i/3][i%3] = desk[i];
//    }
//    first.dir=-1;
//    first.parent=-1;
//    open.push_back(&first);
    //初始化S，并且把方向设为-1，加入表中

    init_pic();//put the picture into a list
    if(ui->deep_first->isChecked()){
        show_terminal.clear();
        open.clear();
        closed.clear();
        ans.clear();
        run_deep();
    }
    else if(ui->width_first->isChecked()){
        show_terminal.clear();
        open.clear();
        closed.clear();
        ans.clear();
        run_width();
    }
    else if(ui->a_star->isChecked()){
        show_terminal.clear();
        open.clear();
        ans.clear();
        closed.clear();
        run_star();
    }
    else if(ui->compare->isChecked()){
        show_terminal.clear();
        open.clear();
        closed.clear();
        ans.clear();
        ui->deeptTime->clear();
        ui->ATime->clear();
        ui->widthTime->clear();
        run_compare();
    }
    else{
        std::cout<<"no"<<std::endl;
    }

}

void enumber::run_compare()
{
    if(flag_sample%3==0){
        desk[0]=0;desk[1]=2;desk[2]=4;
        desk[3]=3;desk[4]=7;desk[5]=6;
        desk[6]=1;desk[7]=5;desk[8]=8;
    }
    else if(flag_sample%3==1){
        desk[0]=8;desk[1]=5;desk[2]=0;
        desk[3]=4;desk[4]=3;desk[5]=6;
        desk[6]=2;desk[7]=1;desk[8]=7;
    }else if(flag_sample%3==2){
        desk[0]=2;desk[1]=3;desk[2]=0;
        desk[3]=4;desk[4]=1;desk[5]=8;
        desk[6]=7;desk[7]=6;desk[8]=5;
    }else{
        desk[0]=0;desk[1]=3;desk[2]=1;
        desk[3]=4;desk[4]=2;desk[5]=8;
        desk[6]=7;desk[7]=6;desk[8]=5;
    }

    run_deep();
    ans.clear();
    open.clear();
    closed.clear();
    pos_closed=0;
    count=0;

    run_width();
    ans.clear();
    open.clear();
    closed.clear();
    pos_closed=0;
    count=0;

    run_star();
    flag_sample++;
}

void enumber::run_deep()
{
    //initial all the parameters
    init_deep();
    int flag=0;
    double clock_start=(double)clock();
    if(have_slove())
        while((flag = move_deep()) == 0);
    else
        flag=-1;
    std::cout<<flag<<std::endl;
    double clock_end = (double)clock();
    ui->deeptTime->setText(QString::number((clock_end-clock_start),10,1));
    timed.push_back(clock_end-clock_start);//input the vec time

    if(flag == 1){
        node *p = open.back();
        while(p->parent!=0){
            ans.push_back(p);
            p=closed[p->parent];
        }
        ans.push_back(p);
    }

    if(flag == -1){
        show_terminal += "\nNo Answer!";
        ui->textBrowser->setText(QString::fromStdString(show_terminal));
        ui->deeptTime->setText(QString::fromStdString("Nan"));
    }else if(flag == -2){
        show_terminal+="the Open table is NULL , found no answer!";
        ui->textBrowser->setText(QString::fromStdString(show_terminal));
        ui->deeptTime->setText(QString::fromStdString("Nan"));
    }
    else if(flag == 2){
        show_terminal+="\nToo Larg";
        ui->textBrowser->setText(QString::fromStdString(show_terminal));

    }else{
        for(int i=ans.size()-1;i>=0;i--){
            for(int j=0;j<NUM_UNIT;j++){
                if(j%3==0)
                    std::cout<<std::endl;
                std::cout<<ans[i]->disk[j/3][j%3]<<" ";
            }
            std::cout<<std::endl;
        }
        QTime t;
        show_terminal += "-------start showing --------";
        for(int i=ans.size()-1;i>=0;i--){
            t.start();
            for(int j=0;j<NUM_UNIT;j++){
                if(j%3==0)
                    show_terminal+='\n';
                show_terminal+=(ans[i]->disk[j/3][j%3]+'0');
                show_terminal+=' ';
            }
            std::cout<<"outside"<<std::endl;
            std::cout<<std::endl;
            show_terminal+='\n';
            loadp(ans[i]);
            ui->textBrowser->setText(QString::fromStdString(show_terminal));
            while(t.elapsed()<1000)
                QCoreApplication::processEvents();
        }
    }

}

void enumber::run_width()
{
    init();
    int flag=0;
    double clock_start = (double)clock();
    if(have_slove())
        while((flag=move()) == 0);
    else
        flag=-1;
    std::cout<<flag<<std::endl;
    double clock_end = (double)clock();
    ui->widthTime->setText(QString::number((clock_end-clock_start),10,1));
    timew.push_back(clock_end-clock_start);

    if(flag==-1){
        ui->textBrowser->setText(QString::fromStdString(std::string("No Answer!\n")));
        ui->widthTime->setText(QString::fromStdString("Nan"));
        return;
    }
    if(flag == -1){
        ui->textBrowser->setText(QString::fromStdString(std::string("Open Table is null , no answer")));
        ui->widthTime->setText(QString::fromStdString("Nan"));
        return ;
    }
    if(flag == 2){
        ui->textBrowser->setText(QString::fromStdString(std::string("Too Large\n")));
        return;
    }
    if(flag == 1){
        ans.push_back(open.front());
        node *p=ans.front();

        while(p->parent != 0){
            p=closed[p->parent];
            ans.push_back(p);
        }
        std::cout<<ans.size()<<std::endl;
        std::cout<<"hi"<<std::endl;
        for(int i=ans.size()-2;i>=0;i--){
                for(int j=0;j<NUM_UNIT;j++){
                    if(j%3==0)
                        std::cout<<std::endl;
                    std::cout<<ans[i]->disk[j/3][j%3]<<" ";
                }
                std::cout<<"outside"<<std::endl;
                std::cout<<std::endl;
         }
        std::string s;
        QTime t;
        for(int i=ans.size()-2;i>=0;i--){
            t.start();
            for(int j=0;j<NUM_UNIT;j++){
                if(j%3==0)
                    s+='\n';
                s+=(ans[i]->disk[j/3][j%3]+'0');
                s+=' ';
            }
            std::cout<<"outside"<<std::endl;
            std::cout<<std::endl;
            s+='\n';
            loadp(ans[i]);
            ui->textBrowser->setText(QString::fromStdString(s));
            while(t.elapsed()<1000)
                QCoreApplication::processEvents();
        }
    }
}

void enumber::eight_number()
{
    //this run number which its aim is to get a disk=[1,2,3,8,0,4,7,6,5]
    enumbercurve *ec = new enumbercurve(timeA,timew,timed);
    ec->show();
}

//using a count to change picture,this is a loading picture function
void enumber::loadp(node *n)
{
    int width = ui->num00->width();
    int height = ui->num00->height();
    ui->num00->setPixmap(QPixmap::fromImage(imgstack[n->disk[0][0]]).scaled(width,height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->num01->setPixmap(QPixmap::fromImage(imgstack[n->disk[0][1]]).scaled(width,height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->num02->setPixmap(QPixmap::fromImage(imgstack[n->disk[0][2]]).scaled(width,height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->num10->setPixmap(QPixmap::fromImage(imgstack[n->disk[1][0]]).scaled(width,height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->num11->setPixmap(QPixmap::fromImage(imgstack[n->disk[1][1]]).scaled(width,height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->num12->setPixmap(QPixmap::fromImage(imgstack[n->disk[1][2]]).scaled(width,height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->num20->setPixmap(QPixmap::fromImage(imgstack[n->disk[2][0]]).scaled(width,height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->num21->setPixmap(QPixmap::fromImage(imgstack[n->disk[2][1]]).scaled(width,height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->num22->setPixmap(QPixmap::fromImage(imgstack[n->disk[2][2]]).scaled(width,height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

}

enumber::~enumber()
{
    delete ui;
}


////////////////////Width Search First //////////////////
bool enumber::isEnd(node *n)
{
    std::string end = "123804765";
    for(int i=0;i<end.length();i++)
        if(n->disk[i/3][i%3] != end[i]-'0')
            return false;
    return true;
}

int enumber::findZero(node *n)
{
    for(int i=0;i<NUM_UNIT;i++)
        if(n->disk[i/3][i%3] == 0)
            return i;
    return -1;
}

int enumber::move()
{
    count++;

    if(count>=100000)
        return 2;
    if(open.empty()){
        return -1;
    }

    node *now = new node();
    for(int i=0;i<NUM_UNIT;i++)
        now->disk[i/3][i%3] = open[0]->disk[i/3][i%3];
    now->dir = open[0]->dir;
    now->parent=open[0]->parent;

    for(int i=0;i<NUM_UNIT;i++){
        if(i%3==0)
            show_terminal+='\n';
        show_terminal+=now->disk[i/3][i%3]+'0';
        show_terminal+=' ';
    }
    show_terminal+='\n';

    if(isEnd(now)){
        for(int i=0;i<NUM_UNIT;i++){
            if(i%3==0)
                std::cout<<std::endl;
            std::cout<<now->disk[i/3][i%3]<<" ";
        }
        std::cout<<"in side"<<std::endl;
        return 1;
    }

    int from = now->dir;
    int pos = findZero(now);
    int x=pos/3;
    int y=pos%3;
    closed.push_back(open.front());//把pop出去的那个放入close表中
    open.erase(open.begin());//把开头删去
    //移过来的那个方向就不要移回去了,
    if(from == UP){//从上移下来的
        node *p = new node();
        *p=*now;
        if(y-1>=0){
            int temp = p->disk[x][y-1];
            p->disk[x][y-1] = 0;
            p->disk[x][y] = temp;
            p->dir=RIGHT;
            p->parent=pos_closed;
            open.push_back(p);
        }//左移
        p = new node();
        *p=*now;
        if(y+1<3){
            int temp=p->disk[x][y+1];
            p->disk[x][y+1] = 0;
            p->disk[x][y]=temp;
            p->dir=LEFT;
            p->parent=pos_closed;
            open.push_back(p);
        }//右移
        p=new node();
        *p=*now;
        if(x+1<3){
            int temp =p->disk[x+1][y];
            p->disk[x+1][y]=0;
            p->disk[x][y]=temp;
            p->dir=UP;
            p->parent=pos_closed;
            open.push_back(p);
        }//下移
    }else if(from == LEFT){
        node *p=new node();
        *p=*now;
        if(x-1>0){
            int temp = p->disk[x-1][y];
            p->disk[x-1][y]=0;
            p->disk[x][y]=temp;
            p->dir=DOWN;
            p->parent=pos_closed;
            open.push_back(p);
        }//上移
        p=new node();
        *p=*now;
        if(x+1<3){
            int temp=p->disk[x+1][y];
            p->disk[x+1][y]=0;
            p->disk[x][y]=temp;
            p->dir=UP;p->parent=pos_closed;
            open.push_back(p);
        }//下移
        p=new node();
        *p=*now;
        if(y+1<3){
            int temp=p->disk[x][y+1];
            p->disk[x][y+1]=0;
            p->disk[x][y]=temp;
            p->dir=LEFT;p->parent=pos_closed;
            open.push_back(p);
        }//右移
    }else if(from == RIGHT){
        node *p = new node();
        *p=*now;
        if(x-1>=0){
            int temp=p->disk[x-1][y];
            p->disk[x-1][y]=0;
            p->disk[x][y]=temp;
            p->dir=DOWN;p->parent=pos_closed;
            open.push_back(p);
        }//上移
        p=new node();
        *p=*now;
        if(x+1<3){
            int temp=p->disk[x+1][y];
            p->disk[x+1][y]=0;
            p->disk[x][y]=temp;
            p->dir=UP;p->parent=pos_closed;
            open.push_back(p);
        }//下移
        p=new node();
        *p=*now;
        if(y-1>=0){
            int temp=p->disk[x][y-1];
            p->disk[x][y-1]=0;
            p->disk[x][y]=temp;
            p->dir=RIGHT;p->parent=pos_closed;
            open.push_back(p);
        }//左移
    }else if(from == DOWN){
        node *p=new node();
        *p=*now;
        if(x-1>=0){
            int temp=p->disk[x-1][y];
            p->disk[x-1][y]=0;
            p->disk[x][y]=temp;
            p->dir=DOWN;p->parent=pos_closed;
            open.push_back(p);
        }//上移
        p=new node();
        *p=*now;
        if(y+1<3){
            int temp=p->disk[x][y+1];
            p->disk[x][y+1]=0;
            p->disk[x][y]=temp;
            p->dir=UP;p->parent=pos_closed;
            open.push_back(p);
        }//右移
        p=new node();
        *p=*now;
        if(y-1>=0){
            int temp=p->disk[x][y-1];
            p->disk[x][y-1]=0;
            p->disk[x][y]=temp;
            p->dir=RIGHT;p->parent=pos_closed;
            open.push_back(p);
        }//左移
    }else{//四个方向都需要移
        node *p=new node();
        *p=*now;
        if(x-1>=0){
            int temp=p->disk[x-1][y];
            p->disk[x-1][y]=0;
            p->disk[x][y]=temp;
            p->dir=DOWN;p->parent=pos_closed;
            open.push_back(p);
        }//上移
        p=new node();
        *p=*now;
        if(x+1<3){
            int temp=p->disk[x+1][y];
            p->disk[x+1][y]=0;
            p->disk[x][y]=temp;
            p->dir=UP;p->parent=pos_closed;
            open.push_back(p);
        }//下移
        p=new node();
        *p=*now;
        if(y-1>=0){
            int temp=p->disk[x][y-1];
            p->disk[x][y-1]=0;
            p->disk[x][y]=temp;
            p->dir=RIGHT;p->parent=pos_closed;
            open.push_back(p);
        }//左移
        p=new node();
        *p=*now;
        if(y+1<3){
            int temp=p->disk[x][y+1];
            p->disk[x][y+1]=0;
            p->disk[x][y]=temp;
            p->dir=LEFT;p->parent=pos_closed;
            open.push_back(p);;
        }//右移
    }
    pos_closed++;
    return 0;

}
void enumber::print()
{
    node *now = open.back();
    for(int i=0;i<end.length();i++){
        if(i%3 == 0)
            show_terminal += '\n';
        show_terminal += now->disk[i/3][i%3]+'0';
    }
    ui->textBrowser->setText(QString::fromStdString(show_terminal));

}

///////////////////   Deep Search First ///////////////////////////////////////////

//same chech is end
//same in finding zero
void enumber::creat_targ(node *n)
{
    n->targ.clear();
    for(int i=0;i<NUM_UNIT;i++){
        n->targ += n->disk[i/3][i%3] + '0';
    }
}

node *enumber::inClosed(node *n)
{
    for(int i=0;i<closed.size();i++){
        if(strcmp(n->targ.c_str(), closed[i]->targ.c_str()) == 0){
            check++;
            return closed[i];
        }
    }
    return NULL;
}

void enumber::init_deep()
{
    open.clear();
    closed.clear();
    ans.clear();
    count=0;
    pos_closed=0;
    check=0;
    show_terminal.clear();
    node *first = new node();

    for(int i=0;i<NUM_UNIT;i++)
        first->disk[i/3][i%3] = desk[i];

    for(int i=0;i<NUM_UNIT;i++)
        std::cout<<first->disk[i/3][i%3]<<" ";
    first->parent=-1;
    first->dir=-1;
    first->dept=0;

    open.push_back(first);
    loadp(first);
    QTime t;
    t.start();
    while(t.elapsed()<WAIT)
        QCoreApplication::processEvents();
}

int enumber::move_deep()
{
    if(open.empty()){
        std::cout<<"open is null"<<std::endl;
        return -2;
    }//If open list is null
    node *now = new node();
    for(int i=0;i<NUM_UNIT;i++)
        now->disk[i/3][i%3] = open.back()->disk[i/3][i%3];//copy into node

    now->dir = open.back()->dir;
    now->parent=open.back()->parent;
    now->dept=open.back()->dept;
    now->targ = open.back()->targ;

    for(int i=0;i<NUM_UNIT;i++){
        if(i%3==0)
            show_terminal+='\n';
        show_terminal+=now->disk[i/3][i%3]+'0';
        show_terminal+=' ';
    }
    show_terminal+='\n';

    closed.push_back(now);//把pop出去的那个放入close表中
    open.pop_back();//把尾部删去，相当于是删去open的头，open是反过来看的，把vector的尾部看成open的头

    if(now->dept>=MAX_DEPT){//if it is out of the max dept,no longer create its child state
        pos_closed++;
        return 0;
    }

    int from = now->dir;
    int pos = findZero(now);
    int x=pos/3;
    int y=pos%3;

    //移过来的那个方向就不要移回去了,
    if(from == UP){//从上移下来的
        node *p = new node();
        *p=*now;
        if(y-1>=0){
            int temp = p->disk[x][y-1];
            p->disk[x][y-1] = 0;
            p->disk[x][y] = temp;
            p->dir=RIGHT;
            p->dept++;
            p->parent=pos_closed;
            creat_targ(p);
            if(!inClosed(p))
                open.push_back(p);
            if(isEnd(p))
                return 1;
        }//左移
        p = new node();
        *p=*now;
        if(y+1<3){
            int temp=p->disk[x][y+1];
            p->disk[x][y+1] = 0;
            p->disk[x][y]=temp;
            p->dir=LEFT;
            p->dept++;
            p->parent=pos_closed;
            creat_targ(p);
            if(!inClosed(p))
                open.push_back(p);
            if(isEnd(p))
                return 1;
        }//右移
        p=new node();
        *p=*now;
        if(x+1<3){
            int temp =p->disk[x+1][y];
            p->disk[x+1][y]=0;
            p->disk[x][y]=temp;
            p->dir=UP;
            p->dept++;
            p->parent=pos_closed;
            creat_targ(p);
            if(!inClosed(p))
                open.push_back(p);

            if(isEnd(p))
                return 1;
        }//下移
    }else if(from == LEFT){
        node *p=new node();
        *p=*now;
        if(x-1>=0){
            int temp = p->disk[x-1][y];
            p->disk[x-1][y]=0;
            p->disk[x][y]=temp;
            p->dir=DOWN;
            p->dept++;
            p->parent=pos_closed;
            creat_targ(p);
            if(!inClosed(p))
                open.push_back(p);

            if(isEnd(p))
                return 1;
        }//上移
        p=new node();
        *p=*now;
        if(x+1<3){
            int temp=p->disk[x+1][y];
            p->disk[x+1][y]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=UP;p->parent=pos_closed;
            creat_targ(p);
            if(!inClosed(p))
                open.push_back(p);

            if(isEnd(p))
                return 1;
        }//下移
        p=new node();
        *p=*now;
        if(y+1<3){
            int temp=p->disk[x][y+1];
            p->disk[x][y+1]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=LEFT;p->parent=pos_closed;
            creat_targ(p);
            if(!inClosed(p))
                open.push_back(p);

            if(isEnd(p))
                return 1;
        }//右移
    }else if(from == RIGHT){
        node *p = new node();
        *p=*now;
        if(x-1>=0){
            int temp=p->disk[x-1][y];
            p->disk[x-1][y]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=DOWN;p->parent=pos_closed;
            creat_targ(p);
            if(!inClosed(p))
                open.push_back(p);

            if(isEnd(p))
                return 1;
        }//上移
        p=new node();
        *p=*now;
        if(x+1<3){
            int temp=p->disk[x+1][y];
            p->disk[x+1][y]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=UP;p->parent=pos_closed;
            creat_targ(p);
            if(!inClosed(p))
                open.push_back(p);

            if(isEnd(p))
                return 1;
        }//下移
        p=new node();
        *p=*now;
        if(y-1>=0){
            int temp=p->disk[x][y-1];
            p->disk[x][y-1]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=RIGHT;p->parent=pos_closed;
            creat_targ(p);
            if(!inClosed(p))
                open.push_back(p);

            if(isEnd(p))
                return 1;
        }//左移
    }else if(from == DOWN){
        node *p=new node();
        *p=*now;
        if(x-1>=0){
            int temp=p->disk[x-1][y];
            p->disk[x-1][y]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=DOWN;p->parent=pos_closed;
            creat_targ(p);
            if(!inClosed(p))
                open.push_back(p);

            if(isEnd(p))
                return 1;
        }//上移
        p=new node();
        *p=*now;
        if(y+1<3){
            int temp=p->disk[x][y+1];
            p->disk[x][y+1]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=LEFT;p->parent=pos_closed;
            creat_targ(p);
            if(!inClosed(p))
                open.push_back(p);

            if(isEnd(p))
                return 1;
        }//右移
        p=new node();
        *p=*now;
        if(y-1>=0){
            int temp=p->disk[x][y-1];
            p->disk[x][y-1]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=RIGHT;p->parent=pos_closed;
            creat_targ(p);
            if(!inClosed(p))
                open.push_back(p);

            if(isEnd(p))
                return 1;
        }//左移
    }else{//四个方向都需要移
        node *p=new node();
        *p=*now;
        if(x-1>=0){
            int temp=p->disk[x-1][y];
            p->disk[x-1][y]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=DOWN;p->parent=pos_closed;
            creat_targ(p);
            if(!inClosed(p))
                open.push_back(p);

            if(isEnd(p))
                return 1;
        }//上移
        p=new node();
        *p=*now;
        if(x+1<3){
            int temp=p->disk[x+1][y];
            p->disk[x+1][y]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=UP;p->parent=pos_closed;
            creat_targ(p);
            if(!inClosed(p))
                open.push_back(p);

            if(isEnd(p))
                return 1;
        }//下移
        p=new node();
        *p=*now;
        if(y-1>=0){
            int temp=p->disk[x][y-1];
            p->disk[x][y-1]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=RIGHT;p->parent=pos_closed;
            creat_targ(p);
            if(!inClosed(p))
                open.push_back(p);

            if(isEnd(p))
                return 1;
        }//左移
        p=new node();
        *p=*now;
        if(y+1<3){
            int temp=p->disk[x][y+1];
            p->disk[x][y+1]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=LEFT;p->parent=pos_closed;
            creat_targ(p);
            if(!inClosed(p))
                open.push_back(p);

            if(isEnd(p))
                return 1;
        }//右移
    }
    pos_closed++;
    return 0;
}


void enumber::on_textBrowser_textChanged()
{
    ui->textBrowser->moveCursor(QTextCursor::End);
}
