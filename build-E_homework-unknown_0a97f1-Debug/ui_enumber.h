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
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_enumber
{
public:
    QPushButton *close;
    QPushButton *start;

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

        retranslateUi(enumber);

        QMetaObject::connectSlotsByName(enumber);
    } // setupUi

    void retranslateUi(QDialog *enumber)
    {
        enumber->setWindowTitle(QApplication::translate("enumber", "Dialog", Q_NULLPTR));
        close->setText(QApplication::translate("enumber", "\345\205\263\351\227\255\347\252\227\345\217\243", Q_NULLPTR));
        start->setText(QApplication::translate("enumber", "\345\274\200\345\247\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class enumber: public Ui_enumber {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENUMBER_H
