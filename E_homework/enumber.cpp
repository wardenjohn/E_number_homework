#include "enumber.h"
#include "ui_enumber.h"
#include <vector>
#include <QImage>
#include <QTime>
#define NUM_UNIT 9
#define UP 1
#define LEFT 2
#define RIGHT 3
#define DOWN 4
#define MAX_DEPT 5
    enumber::enumber(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::enumber)
    {
        ui->setupUi(this);
        setWindowTitle("小小八数码");
        connect(ui->close,SIGNAL(clicked(bool)),this,SLOT(close()));
        connect(ui->start,SIGNAL(clicked(bool)),this,SLOT(start()));
        connect(ui->load,SIGNAL(clicked(bool)),this,SLOT(loadp()));
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

void enumber::init(){

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

//    int count=0;
//    while(count<9){
//        int tem = rand()%9;
//        if(flags[tem] == 0){//it means that this number is not been created
//            flags[tem]=1;
//            if(desk[count] == -1){
//                desk[count]=tem;
//                count++;
//            }
//        }
//    }
    desk[0]=2;desk[1]=8;desk[2]=3;desk[3]=1;desk[4]=6;desk[5]=4;desk[6]=7;desk[7]=0;desk[8]=5;
    //initial the first disk,which is the initial status of the running,giving the first status in randomly

    node first;
    for(int i=0;i<9;i++){
        first.disk[i/3][i%3] = desk[i];
    }
    first.dir=-1;
    first.parent=-1;
    open.push_back(&first);
    //初始化S，并且把方向设为-1，加入表中
    init_pic();//put the picture into a list
    loadp(&first);
    if(ui->deep_first->isChecked()){
        run_deep();
    }
    else if(ui->width_first->isChecked()){
        run_width();
    }
    else{
        std::cout<<"no"<<std::endl;
    }

}

void enumber::run_deep()
{
    open.clear();
    closed.clear();
    ans.clear();
    count=0;
    pos_closed=-1;
    check=0;
    //initial all the parameters
    init_deep();
    int flag=0;
    while((flag = move_deep()) == 0);

    if(flag == 1){
        node *p = open.back();
        while(p->parent!=0){
            ans.push_back(p);
            p=closed[p->parent];
        }
        ans.push_back(p);
    }

    for(int i=ans.size()-1;i>=0;i--){
        for(int j=0;j<NUM_UNIT;j++){
            if(j%3==0)
                std::cout<<std::endl;
            std::cout<<ans[i]->disk[j/3][j%3]<<" ";
        }
        std::cout<<std::endl;
    }
    QTime t;
    std::string s;
    for(int i=ans.size()-1;i>=0;i--){
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

void enumber::run_width()
{
    open.clear();
    closed.clear();
    ans.clear();

    int flag=0;
    while((flag=move()) == 0);
    std::cout<<flag<<std::endl;
    if(flag == 2){
        ui->textBrowser->setText(QString::fromStdString(std::string("Too Large\n")));
        return;
    }
    if(flag == 1){
        ans.push_back(open.front());
        node *p=ans.front();

        while(p->dir != -1){
            p=closed[p->parent];
            ans.push_back(p);
        }
        std::cout<<ans.size()<<std::endl;

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
    QTime t;
    while(true){
        t.start();
        //loadp();
        while(t.elapsed()<1000)
            QCoreApplication::processEvents();
    }
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

bool enumber::inClosed(node *n)
{
    for(int i=0;i<closed.size();i++){
        if(strcmp(n->targ.c_str(), closed[i]->targ.c_str()) == 0){
            check++;
            return true;
        }
    }
    return false;
}

void enumber::init_deep()
{
    node *first = new node();
    first->disk[0][0] = 2;
    first->disk[0][1] = 8;
    first->disk[0][2] = 3;
    first->disk[1][0] = 1;
    first->disk[1][1] = 4;
    first->disk[1][2] = 0;
    first->disk[2][0] = 7;
    first->disk[2][1] = 6;
    first->disk[2][2] = 5;

    first->parent=-1;
    first->dir=-1;
    first->dept=0;

    open.push_back(first);
}

int enumber::move_deep()
{
    if(open.empty()){
        return -1;
    }//If open list is null

    node *now = new node();
    for(int i=0;i<NUM_UNIT;i++)
        now->disk[i/3][i%3] = open.back()->disk[i/3][i%3];//copy into node

    now->dir = open.back()->dir;
    now->parent=open.back()->parent;
    now->dept=open.back()->dept;
    now->targ = open.back()->targ;

    closed.push_back(open.back());//把pop出去的那个放入close表中
    open.pop_back();//把尾部删去，相当于是删去open的头，open是反过来看的，把vector的尾部看成open的头
    pos_closed++;
    if(now->dept>=MAX_DEPT){//if it is out of the max dept,no longer create its child state
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
    return 0;
}

