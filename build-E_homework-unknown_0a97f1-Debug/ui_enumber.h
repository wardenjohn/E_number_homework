/********************************************************************************
** Form generated from reading UI file 'enumber.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENUMBER_H
#define UI_ENUMBER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_enumber
{
public:
    QPushButton *close;
    QPushButton *start;
    QLabel *num00;
    QPushButton *load;
    QLabel *num01;
    QLabel *num02;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *num10;
    QLabel *num20;
    QLabel *num11;
    QLabel *num21;
    QLabel *num12;
    QLabel *num22;

    void setupUi(QDialog *enumber)
    {
        if (enumber->objectName().isEmpty())
            enumber->setObjectName(QStringLiteral("enumber"));
        enumber->resize(570, 503);
        close = new QPushButton(enumber);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(420, 20, 113, 32));
        start = new QPushButton(enumber);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(420, 60, 113, 32));
        num00 = new QLabel(enumber);
        num00->setObjectName(QStringLiteral("num00"));
        num00->setGeometry(QRect(40, 90, 71, 81));
        num00->setPixmap(QPixmap(QString::fromUtf8(":/image/1")));
        load = new QPushButton(enumber);
        load->setObjectName(QStringLiteral("load"));
        load->setGeometry(QRect(420, 100, 113, 32));
        num01 = new QLabel(enumber);
        num01->setObjectName(QStringLiteral("num01"));
        num01->setGeometry(QRect(160, 90, 71, 81));
        num01->setPixmap(QPixmap(QString::fromUtf8(":/image/2")));
        num02 = new QLabel(enumber);
        num02->setObjectName(QStringLiteral("num02"));
        num02->setGeometry(QRect(280, 90, 71, 81));
        num02->setPixmap(QPixmap(QString::fromUtf8(":/image/3")));
        label_2 = new QLabel(enumber);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 411, 16));
        label_3 = new QLabel(enumber);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 180, 411, 16));
        label_4 = new QLabel(enumber);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 300, 411, 16));
        label_5 = new QLabel(enumber);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 420, 411, 16));
        num10 = new QLabel(enumber);
        num10->setObjectName(QStringLiteral("num10"));
        num10->setGeometry(QRect(40, 210, 71, 81));
        num10->setPixmap(QPixmap(QString::fromUtf8(":/image/3")));
        num20 = new QLabel(enumber);
        num20->setObjectName(QStringLiteral("num20"));
        num20->setGeometry(QRect(40, 330, 71, 81));
        num20->setPixmap(QPixmap(QString::fromUtf8(":/image/0")));
        num11 = new QLabel(enumber);
        num11->setObjectName(QStringLiteral("num11"));
        num11->setGeometry(QRect(160, 210, 71, 81));
        num11->setPixmap(QPixmap(QString::fromUtf8(":/image/4")));
        num21 = new QLabel(enumber);
        num21->setObjectName(QStringLiteral("num21"));
        num21->setGeometry(QRect(160, 330, 71, 81));
        num21->setPixmap(QPixmap(QString::fromUtf8(":/image/7")));
        num12 = new QLabel(enumber);
        num12->setObjectName(QStringLiteral("num12"));
        num12->setGeometry(QRect(280, 210, 71, 81));
        num12->setPixmap(QPixmap(QString::fromUtf8(":/image/5")));
        num22 = new QLabel(enumber);
        num22->setObjectName(QStringLiteral("num22"));
        num22->setGeometry(QRect(280, 330, 71, 81));
        num22->setPixmap(QPixmap(QString::fromUtf8(":/image/8")));

        retranslateUi(enumber);

        QMetaObject::connectSlotsByName(enumber);
    } // setupUi

    void retranslateUi(QDialog *enumber)
    {
        enumber->setWindowTitle(QApplication::translate("enumber", "Dialog", Q_NULLPTR));
        close->setText(QApplication::translate("enumber", "\345\205\263\351\227\255\347\252\227\345\217\243", Q_NULLPTR));
        start->setText(QApplication::translate("enumber", "\345\274\200\345\247\213", Q_NULLPTR));
        num00->setText(QString());
        load->setText(QApplication::translate("enumber", "\345\212\240\350\275\275", Q_NULLPTR));
        num01->setText(QString());
        num02->setText(QString());
        label_2->setText(QApplication::translate("enumber", "--------------------------------------------------------------------", Q_NULLPTR));
        label_3->setText(QApplication::translate("enumber", "--------------------------------------------------------------------", Q_NULLPTR));
        label_4->setText(QApplication::translate("enumber", "--------------------------------------------------------------------", Q_NULLPTR));
        label_5->setText(QApplication::translate("enumber", "--------------------------------------------------------------------", Q_NULLPTR));
        num10->setText(QString());
        num20->setText(QString());
        num11->setText(QString());
        num21->setText(QString());
        num12->setText(QString());
        num22->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class enumber: public Ui_enumber {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENUMBER_H
