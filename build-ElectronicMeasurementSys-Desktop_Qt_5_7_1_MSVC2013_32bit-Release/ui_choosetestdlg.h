/********************************************************************************
** Form generated from reading UI file 'choosetestdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSETESTDLG_H
#define UI_CHOOSETESTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ChooseTestDlg
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QListWidget *listWidget;
    QGridLayout *gridLayout;

    void setupUi(QDialog *ChooseTestDlg)
    {
        if (ChooseTestDlg->objectName().isEmpty())
            ChooseTestDlg->setObjectName(QStringLiteral("ChooseTestDlg"));
        ChooseTestDlg->resize(333, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/img/checked.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ChooseTestDlg->setWindowIcon(icon);
        gridLayout_3 = new QGridLayout(ChooseTestDlg);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(ChooseTestDlg);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        listWidget = new QListWidget(ChooseTestDlg);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout_3->addWidget(listWidget, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        gridLayout_3->addLayout(gridLayout, 2, 0, 1, 1);


        retranslateUi(ChooseTestDlg);

        QMetaObject::connectSlotsByName(ChooseTestDlg);
    } // setupUi

    void retranslateUi(QDialog *ChooseTestDlg)
    {
        ChooseTestDlg->setWindowTitle(QApplication::translate("ChooseTestDlg", "\345\256\236\351\252\214\351\200\211\346\213\251", Q_NULLPTR));
        label->setText(QApplication::translate("ChooseTestDlg", "\351\200\211\346\213\251\350\257\225\351\252\214\345\217\202\346\225\260\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChooseTestDlg: public Ui_ChooseTestDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSETESTDLG_H
