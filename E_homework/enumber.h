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

private:
    Ui::enumber *ui;

public slots:
    void start();
};

#endif // ENUMBER_H
