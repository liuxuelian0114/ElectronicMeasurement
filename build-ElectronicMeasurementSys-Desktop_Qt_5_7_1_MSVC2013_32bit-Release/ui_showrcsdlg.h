/********************************************************************************
** Form generated from reading UI file 'showrcsdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWRCSDLG_H
#define UI_SHOWRCSDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_ShowRCSDlg
{
public:
    QHBoxLayout *horizontalLayout;
    QCustomPlot *listWidget;

    void setupUi(QDialog *ShowRCSDlg)
    {
        if (ShowRCSDlg->objectName().isEmpty())
            ShowRCSDlg->setObjectName(QStringLiteral("ShowRCSDlg"));
        ShowRCSDlg->resize(770, 504);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/img/line_percentage.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ShowRCSDlg->setWindowIcon(icon);
        horizontalLayout = new QHBoxLayout(ShowRCSDlg);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        listWidget = new QCustomPlot(ShowRCSDlg);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout->addWidget(listWidget);


        retranslateUi(ShowRCSDlg);

        QMetaObject::connectSlotsByName(ShowRCSDlg);
    } // setupUi

    void retranslateUi(QDialog *ShowRCSDlg)
    {
        ShowRCSDlg->setWindowTitle(QApplication::translate("ShowRCSDlg", "RCS\345\233\276", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ShowRCSDlg: public Ui_ShowRCSDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWRCSDLG_H
