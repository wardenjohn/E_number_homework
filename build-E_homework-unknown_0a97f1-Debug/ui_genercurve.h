/********************************************************************************
** Form generated from reading UI file 'genercurve.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERCURVE_H
#define UI_GENERCURVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_genercurve
{
public:

    void setupUi(QWidget *genercurve)
    {
        if (genercurve->objectName().isEmpty())
            genercurve->setObjectName(QStringLiteral("genercurve"));
        genercurve->resize(603, 500);

        retranslateUi(genercurve);

        QMetaObject::connectSlotsByName(genercurve);
    } // setupUi

    void retranslateUi(QWidget *genercurve)
    {
        genercurve->setWindowTitle(QApplication::translate("genercurve", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class genercurve: public Ui_genercurve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERCURVE_H
