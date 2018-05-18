/********************************************************************************
** Form generated from reading UI file 'bp.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BP_H
#define UI_BP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bp
{
public:
    QPushButton *start;
    QPushButton *close;
    QLineEdit *waittime;
    QLabel *label;
    QRadioButton *addfun;
    QRadioButton *sinfun;
    QRadioButton *squarefun;
    QPushButton *error;
    QPushButton *mimic;

    void setupUi(QWidget *bp)
    {
        if (bp->objectName().isEmpty())
            bp->setObjectName(QStringLiteral("bp"));
        bp->resize(663, 550);
        start = new QPushButton(bp);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(280, 510, 91, 21));
        close = new QPushButton(bp);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(390, 510, 91, 21));
        waittime = new QLineEdit(bp);
        waittime->setObjectName(QStringLiteral("waittime"));
        waittime->setGeometry(QRect(90, 480, 81, 21));
        label = new QLabel(bp);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 480, 60, 16));
        addfun = new QRadioButton(bp);
        addfun->setObjectName(QStringLiteral("addfun"));
        addfun->setGeometry(QRect(100, 510, 81, 20));
        sinfun = new QRadioButton(bp);
        sinfun->setObjectName(QStringLiteral("sinfun"));
        sinfun->setGeometry(QRect(10, 510, 81, 20));
        squarefun = new QRadioButton(bp);
        squarefun->setObjectName(QStringLiteral("squarefun"));
        squarefun->setGeometry(QRect(180, 510, 71, 20));
        error = new QPushButton(bp);
        error->setObjectName(QStringLiteral("error"));
        error->setGeometry(QRect(500, 510, 91, 21));
        mimic = new QPushButton(bp);
        mimic->setObjectName(QStringLiteral("mimic"));
        mimic->setGeometry(QRect(280, 470, 91, 21));

        retranslateUi(bp);

        QMetaObject::connectSlotsByName(bp);
    } // setupUi

    void retranslateUi(QWidget *bp)
    {
        bp->setWindowTitle(QApplication::translate("bp", "Form", Q_NULLPTR));
        start->setText(QApplication::translate("bp", "\345\274\200\345\247\213\346\274\224\347\244\272", Q_NULLPTR));
        close->setText(QApplication::translate("bp", "\345\205\263\351\227\255", Q_NULLPTR));
        label->setText(QApplication::translate("bp", "\345\273\266\350\277\237\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        addfun->setText(QApplication::translate("bp", "y=x1+x2", Q_NULLPTR));
        sinfun->setText(QApplication::translate("bp", "y=sin(x)", Q_NULLPTR));
        squarefun->setText(QApplication::translate("bp", "y=x^2", Q_NULLPTR));
        error->setText(QApplication::translate("bp", "\350\257\257\345\267\256\346\233\262\347\272\277", Q_NULLPTR));
        mimic->setText(QApplication::translate("bp", "\346\263\233\345\214\226\346\233\262\347\272\277", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class bp: public Ui_bp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BP_H
