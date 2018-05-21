#include "enumber.h"
#include "ui_enumber.h"
#include <QTime>
void enumber::init_star()
{
    open.clear();
    closed.clear();
    ans.clear();
    count=0;
    pos_closed=0;//指向betstnode的位置的标识，在closed表中

    node *first = new node();
    for(int i=0;i<NUM_UNIT;i++){
        first->disk[i/3][i%3]=desk[i];
    }
    first->dept=0;
    first->dir=-1;
    first->parent=-1;
    creat_targ(first);
    first->f=caculate_f(first);
    loadp(first);
    open.push_back(first);
}

int enumber::caculate_f(node *n)//计算f，f为放错棋子数+深度
{
    int misschar=0;
    for(int i=0;i<NUM_UNIT;i++)
        if(n->disk[i/3][i%3] != end[i]-'0')
            misschar++;
    return n->dept+misschar;
}

node* enumber::inOpen(node *n)
{
    for(int i=0;i<open.size();i++)
        if(strcmp(n->targ.c_str(),open[i]->targ.c_str()) == 0)
            return open[i];
    return NULL;
}

node* enumber::find_f()
{
    int min=9999;
    int i=0;
    int remember=0;
    node *p;
    for(i=0;i<open.size();i++){
        if(open[i]->f<min){
            p=open[i];
            min=p->f;
            remember=i;
        }
    }
    closed.push_back(p);//把找到的最小的f放进去close里面去
    open.erase(open.begin()+remember);//把open表里面的删去
    return p;
}

int enumber::inCloseOrOpen(node *p,node *bestnode)
{
    node *old=NULL;
    std::cout<<count<<std::endl;
    count++;
    if((old=inOpen(p)) != NULL){
        free(p);
        p=old;
        bestnode->child.push_back(p);
        if(p->dept<old->dept){
            old->parent=pos_closed;
            old->dept=p->dept;
            old->f=caculate_f(old);//update the parameter of old
        }
    }else if((old=inClosed(p))!=NULL){
        free(p);
        p=old;
        bestnode->child.push_back(p);
        if(p->dept<old->dept){
            old->parent=pos_closed;
            old->dept=p->dept;
            old->f=caculate_f(old);
        }
    }else{
        open.push_back(p);
        bestnode->child.push_back(p);
        p->f=caculate_f(p);
    }
    return 0;
}


int enumber::move_star()
{
    if(open.empty())
        return -1;
    node *bestnode = find_f();//return the smallest f node , f is the sum of depth and amount of missing character
    if(isEnd(bestnode)){
        ans.push_back(bestnode);
        return 1;
    }
    //Create SUCCESSOR
    int from = bestnode->dir;
    int pos = findZero(bestnode);
    int x=pos/3;
    int y=pos%3;

    //移过来的那个方向就不要移回去了,对于每一个SUCCESSOR

    if(from == UP){//从上移下来的
        node *p = new node();
        node *old;
        *p=*bestnode;
        if(y-1>=0){
            int temp = p->disk[x][y-1];
            p->disk[x][y-1] = 0;
            p->disk[x][y] = temp;
            p->dir=RIGHT;
            p->dept++;//dept is the g(SUC)
            p->parent=pos_closed;//建立从SUCCESSOR返回到bestnode的指针
            creat_targ(p);
            inCloseOrOpen(p,bestnode);
        }//左移
        p = new node();
        *p=*bestnode;
        if(y+1<3){
            int temp=p->disk[x][y+1];
            p->disk[x][y+1] = 0;
            p->disk[x][y]=temp;
            p->dir=LEFT;
            p->dept++;
            p->parent=pos_closed;
            creat_targ(p);
            inCloseOrOpen(p,bestnode);
        }//右移
        p=new node();
        *p=*bestnode;
        if(x+1<3){
            int temp =p->disk[x+1][y];
            p->disk[x+1][y]=0;
            p->disk[x][y]=temp;
            p->dir=UP;
            p->dept++;
            p->parent=pos_closed;
            creat_targ(p);
           inCloseOrOpen(p,bestnode);
        }//下移
    }else if(from == LEFT){
        node *p=new node();
        *p=*bestnode;
        if(x-1>=0){
            int temp = p->disk[x-1][y];
            p->disk[x-1][y]=0;
            p->disk[x][y]=temp;
            p->dir=DOWN;
            p->dept++;
            p->parent=pos_closed;
            creat_targ(p);
            inCloseOrOpen(p,bestnode);
        }//上移
        p=new node();
        *p=*bestnode;
        if(x+1<3){
            int temp=p->disk[x+1][y];
            p->disk[x+1][y]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=UP;p->parent=pos_closed;
            creat_targ(p);
           inCloseOrOpen(p,bestnode);
        }//下移
        p=new node();
        *p=*bestnode;
        if(y+1<3){
            int temp=p->disk[x][y+1];
            p->disk[x][y+1]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=LEFT;p->parent=pos_closed;
            creat_targ(p);
            inCloseOrOpen(p,bestnode);
        }//右移
    }else if(from == RIGHT){
        node *p = new node();
        *p=*bestnode;
        if(x-1>=0){
            int temp=p->disk[x-1][y];
            p->disk[x-1][y]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=DOWN;p->parent=pos_closed;
            creat_targ(p);
            inCloseOrOpen(p,bestnode);
        }//上移
        p=new node();
        *p=*bestnode;
        if(x+1<3){
            int temp=p->disk[x+1][y];
            p->disk[x+1][y]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=UP;p->parent=pos_closed;
            creat_targ(p);
            inCloseOrOpen(p,bestnode);
        }//下移
        p=new node();
        *p=*bestnode;
        if(y-1>=0){
            int temp=p->disk[x][y-1];
            p->disk[x][y-1]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=RIGHT;p->parent=pos_closed;
            creat_targ(p);
            inCloseOrOpen(p,bestnode);
        }//左移
    }else if(from == DOWN){
        node *p=new node();
        *p=*bestnode;
        if(x-1>=0){
            int temp=p->disk[x-1][y];
            p->disk[x-1][y]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=DOWN;p->parent=pos_closed;
            creat_targ(p);
            inCloseOrOpen(p,bestnode);
        }//上移
        p=new node();
        *p=*bestnode;
        if(y+1<3){
            int temp=p->disk[x][y+1];
            p->disk[x][y+1]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=LEFT;p->parent=pos_closed;
            creat_targ(p);
            inCloseOrOpen(p,bestnode);
        }//右移
        p=new node();
        *p=*bestnode;
        if(y-1>=0){
            int temp=p->disk[x][y-1];
            p->disk[x][y-1]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=RIGHT;p->parent=pos_closed;
            creat_targ(p);
            inCloseOrOpen(p,bestnode);
        }//左移
    }else{//四个方向都需要移
        node *p=new node();
        *p=*bestnode;
        if(x-1>=0){
            int temp=p->disk[x-1][y];
            p->disk[x-1][y]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=DOWN;p->parent=pos_closed;
            creat_targ(p);
            inCloseOrOpen(p,bestnode);
        }//上移
        p=new node();
        *p=*bestnode;
        if(x+1<3){
            int temp=p->disk[x+1][y];
            p->disk[x+1][y]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=UP;p->parent=pos_closed;
            creat_targ(p);
            inCloseOrOpen(p,bestnode);
        }//下移
        p=new node();
        *p=*bestnode;
        if(y-1>=0){
            int temp=p->disk[x][y-1];
            p->disk[x][y-1]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=RIGHT;p->parent=pos_closed;
            creat_targ(p);
            inCloseOrOpen(p,bestnode);
        }//左移
        p=new node();
        *p=*bestnode;
        if(y+1<3){
            int temp=p->disk[x][y+1];
            p->disk[x][y+1]=0;
            p->disk[x][y]=temp;p->dept++;
            p->dir=LEFT;p->parent=pos_closed;
            creat_targ(p);
            inCloseOrOpen(p,bestnode);
        }//右移
    }
    pos_closed++;
    if(count>=10000)
        return -2;
    return 0;
}

void enumber::run_star()
{
    ui->textBrowser->setText(QString::fromStdString(""));
    init_star();
    int flag=0;
    double clock_start=(double)clock();
    if(have_slove()){
        std::cout<<"have slove"<<std::endl;
        while((flag=move_star()) == 0){
           // std::cout<<flag<<std::endl;
        }
    }
    else
        flag=-1;
    double clock_end = (double)clock();
    ui->ATime->setText(QString::number((clock_end-clock_start),10,1));
    timeA.push_back((clock_end-clock_start));

    if(flag==1){
        std::cout<<"OK !!!!!"<<std::endl;
        node *p;
        show_terminal.clear();
        while(ans.back()->parent != -1)
        {
            p=closed[ans.back()->parent];
            ans.push_back(p);
        }

        QTime t;
        for(int i=ans.size()-1;i>=0;i--){
            t.start();
            loadp(ans[i]);
            for(int j=0;j<NUM_UNIT;j++){
                if(j%3==0)
                    show_terminal+='\n';
                show_terminal+=(ans[i]->disk[j/3][j%3]+'0');
                show_terminal+=' ';
            }
            show_terminal+='\n';
            ui->textBrowser->setText(QString::fromStdString(show_terminal));
            while(t.elapsed()<WAIT)
                QCoreApplication::processEvents();
        }
    }
    if(flag==-1 || flag == -2){
        ui->textBrowser->setText(QString::fromStdString("NO Answer"));
        ui->ATime->setText(QString::fromStdString("Nan"));
    }
    else
        std::cout<<"end all"<<std::endl;

    ans.clear();
    open.clear();
    closed.clear();
    pos_closed=0;
    count=0;

}
