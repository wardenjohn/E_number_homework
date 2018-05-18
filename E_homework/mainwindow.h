#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bp.h"
#include "enumber.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    enumber *numWin;
public slots:
    void enter_eigth_number();
    void enter_traveler();
    void enter_neonet();
};

#endif // MAINWINDOW_H
