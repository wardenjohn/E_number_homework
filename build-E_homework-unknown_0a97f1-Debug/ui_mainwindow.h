/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *title;
    QPushButton *eight_number;
    QPushButton *traveler;
    QLabel *declear;
    QLabel *Unit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(538, 283);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        title = new QLabel(centralWidget);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(40, 30, 171, 21));
        eight_number = new QPushButton(centralWidget);
        eight_number->setObjectName(QStringLiteral("eight_number"));
        eight_number->setGeometry(QRect(60, 80, 113, 32));
        traveler = new QPushButton(centralWidget);
        traveler->setObjectName(QStringLiteral("traveler"));
        traveler->setGeometry(QRect(220, 80, 113, 32));
        declear = new QLabel(centralWidget);
        declear->setObjectName(QStringLiteral("declear"));
        declear->setGeometry(QRect(170, 190, 181, 20));
        Unit = new QLabel(centralWidget);
        Unit->setObjectName(QStringLiteral("Unit"));
        Unit->setGeometry(QRect(120, 210, 281, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 538, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        title->setText(QApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\351\234\200\350\246\201\350\247\243\345\206\263\347\232\204\351\227\256\351\242\230\357\274\232", Q_NULLPTR));
        eight_number->setText(QApplication::translate("MainWindow", "\345\205\253\346\225\260\347\240\201\351\227\256\351\242\230", Q_NULLPTR));
        traveler->setText(QApplication::translate("MainWindow", "\346\227\205\350\241\214\345\256\266\351\227\256\351\242\230", Q_NULLPTR));
        declear->setText(QApplication::translate("MainWindow", "CS1505 Wraden John \302\2512018 ", Q_NULLPTR));
        Unit->setText(QApplication::translate("MainWindow", "Beijing University Of Chemicial Technology", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
