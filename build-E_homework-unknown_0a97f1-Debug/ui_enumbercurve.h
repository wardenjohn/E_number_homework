/********************************************************************************
** Form generated from reading UI file 'enumbercurve.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENUMBERCURVE_H
#define UI_ENUMBERCURVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_enumbercurve
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *enumbercurve)
    {
        if (enumbercurve->objectName().isEmpty())
            enumbercurve->setObjectName(QStringLiteral("enumbercurve"));
        enumbercurve->resize(955, 860);
        label = new QLabel(enumbercurve);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 310, 42, 19));
        label_2 = new QLabel(enumbercurve);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(290, 640, 91, 19));
        label_3 = new QLabel(enumbercurve);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(700, 300, 111, 19));

        retranslateUi(enumbercurve);

        QMetaObject::connectSlotsByName(enumbercurve);
    } // setupUi

    void retranslateUi(QWidget *enumbercurve)
    {
        enumbercurve->setWindowTitle(QApplication::translate("enumbercurve", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("enumbercurve", "A*\347\256\227\346\263\225", Q_NULLPTR));
        label_2->setText(QApplication::translate("enumbercurve", "\345\271\277\345\272\246\344\274\230\345\205\210\347\256\227\346\263\225", Q_NULLPTR));
        label_3->setText(QApplication::translate("enumbercurve", "\346\267\261\345\272\246\344\274\230\345\205\210\347\256\227\346\263\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class enumbercurve: public Ui_enumbercurve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENUMBERCURVE_H
