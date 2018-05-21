/********************************************************************************
** Form generated from reading UI file 'curve.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURVE_H
#define UI_CURVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_curve
{
public:

    void setupUi(QWidget *curve)
    {
        if (curve->objectName().isEmpty())
            curve->setObjectName(QStringLiteral("curve"));
        curve->resize(618, 796);

        retranslateUi(curve);

        QMetaObject::connectSlotsByName(curve);
    } // setupUi

    void retranslateUi(QWidget *curve)
    {
        curve->setWindowTitle(QApplication::translate("curve", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class curve: public Ui_curve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVE_H
