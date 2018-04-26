#ifndef ENUMBER_H
#define ENUMBER_H

#include <QDialog>
#include <iostream>
namespace Ui {
class enumber;
}

class enumber : public QDialog
{
    Q_OBJECT

public:
    explicit enumber(QWidget *parent = 0);
    ~enumber();
    void init_pic();
    void eight_number();
private:
    Ui::enumber *ui;
    std::vector<QImage> imgstack;
public slots:
    void start();
    void loadp();
};

#endif // ENUMBER_H
