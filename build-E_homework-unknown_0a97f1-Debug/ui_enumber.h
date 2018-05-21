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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_enumber
{
public:
    QPushButton *close;
    QPushButton *start;
    QLabel *num00;
    QPushButton *pic;
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
    QRadioButton *deep_first;
    QRadioButton *width_first;
    QLabel *label;
    QTextBrowser *textBrowser;
    QRadioButton *a_star;
    QRadioButton *compare;
    QLabel *label_6;
    QLineEdit *widthTime;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *deeptTime;
    QLineEdit *ATime;

    void setupUi(QDialog *enumber)
    {
        if (enumber->objectName().isEmpty())
            enumber->setObjectName(QStringLiteral("enumber"));
        enumber->resize(551, 627);
        close = new QPushButton(enumber);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(420, 20, 113, 32));
        start = new QPushButton(enumber);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(420, 60, 113, 32));
        num00 = new QLabel(enumber);
        num00->setObjectName(QStringLiteral("num00"));
        num00->setGeometry(QRect(80, 90, 71, 81));
        num00->setPixmap(QPixmap(QString::fromUtf8(":/image/1")));
        pic = new QPushButton(enumber);
        pic->setObjectName(QStringLiteral("pic"));
        pic->setGeometry(QRect(420, 100, 113, 32));
        num01 = new QLabel(enumber);
        num01->setObjectName(QStringLiteral("num01"));
        num01->setGeometry(QRect(160, 90, 71, 81));
        num01->setPixmap(QPixmap(QString::fromUtf8(":/image/2")));
        num02 = new QLabel(enumber);
        num02->setObjectName(QStringLiteral("num02"));
        num02->setGeometry(QRect(240, 90, 71, 81));
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
        num10->setGeometry(QRect(80, 210, 71, 81));
        num10->setPixmap(QPixmap(QString::fromUtf8(":/image/3")));
        num20 = new QLabel(enumber);
        num20->setObjectName(QStringLiteral("num20"));
        num20->setGeometry(QRect(80, 330, 71, 81));
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
        num12->setGeometry(QRect(240, 210, 71, 81));
        num12->setPixmap(QPixmap(QString::fromUtf8(":/image/5")));
        num22 = new QLabel(enumber);
        num22->setObjectName(QStringLiteral("num22"));
        num22->setGeometry(QRect(240, 330, 71, 81));
        num22->setPixmap(QPixmap(QString::fromUtf8(":/image/8")));
        deep_first = new QRadioButton(enumber);
        deep_first->setObjectName(QStringLiteral("deep_first"));
        deep_first->setGeometry(QRect(430, 150, 100, 20));
        width_first = new QRadioButton(enumber);
        width_first->setObjectName(QStringLiteral("width_first"));
        width_first->setGeometry(QRect(430, 180, 100, 20));
        label = new QLabel(enumber);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 450, 81, 16));
        textBrowser = new QTextBrowser(enumber);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 470, 411, 141));
        a_star = new QRadioButton(enumber);
        a_star->setObjectName(QStringLiteral("a_star"));
        a_star->setGeometry(QRect(430, 210, 100, 20));
        compare = new QRadioButton(enumber);
        compare->setObjectName(QStringLiteral("compare"));
        compare->setGeometry(QRect(430, 240, 100, 20));
        label_6 = new QLabel(enumber);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(430, 270, 91, 16));
        widthTime = new QLineEdit(enumber);
        widthTime->setObjectName(QStringLiteral("widthTime"));
        widthTime->setGeometry(QRect(430, 290, 101, 21));
        label_7 = new QLabel(enumber);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(430, 320, 91, 16));
        label_8 = new QLabel(enumber);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(430, 370, 81, 16));
        deeptTime = new QLineEdit(enumber);
        deeptTime->setObjectName(QStringLiteral("deeptTime"));
        deeptTime->setGeometry(QRect(430, 340, 101, 21));
        ATime = new QLineEdit(enumber);
        ATime->setObjectName(QStringLiteral("ATime"));
        ATime->setGeometry(QRect(430, 390, 101, 21));

        retranslateUi(enumber);

        QMetaObject::connectSlotsByName(enumber);
    } // setupUi

    void retranslateUi(QDialog *enumber)
    {
        enumber->setWindowTitle(QApplication::translate("enumber", "Dialog", Q_NULLPTR));
        close->setText(QApplication::translate("enumber", "\345\205\263\351\227\255\347\252\227\345\217\243", Q_NULLPTR));
        start->setText(QApplication::translate("enumber", "\345\274\200\345\247\213", Q_NULLPTR));
        num00->setText(QString());
        pic->setText(QApplication::translate("enumber", "\345\212\240\350\275\275", Q_NULLPTR));
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
        deep_first->setText(QApplication::translate("enumber", "\346\267\261\345\272\246\344\274\230\345\205\210\346\220\234\347\264\242", Q_NULLPTR));
        width_first->setText(QApplication::translate("enumber", "\345\271\277\345\272\246\344\274\230\345\205\210\346\220\234\347\264\242", Q_NULLPTR));
        label->setText(QApplication::translate("enumber", "\350\257\246\347\273\206\350\276\223\345\207\272\357\274\232", Q_NULLPTR));
        a_star->setText(QApplication::translate("enumber", "A*\347\256\227\346\263\225", Q_NULLPTR));
        compare->setText(QApplication::translate("enumber", "\345\257\271\346\257\224\350\277\220\350\241\214", Q_NULLPTR));
        label_6->setText(QApplication::translate("enumber", "\345\256\275\345\272\246\346\227\266\351\227\264", Q_NULLPTR));
        label_7->setText(QApplication::translate("enumber", "\346\267\261\345\272\246\346\227\266\351\227\264", Q_NULLPTR));
        label_8->setText(QApplication::translate("enumber", "A*\346\227\266\351\227\264", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class enumber: public Ui_enumber {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENUMBER_H
