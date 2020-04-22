/********************************************************************************
** Form generated from reading UI file 'usermanagerdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMANAGERDLG_H
#define UI_USERMANAGERDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_UserManagerDlg
{
public:
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidgetUserInfo;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonEdit;
    QPushButton *pushButtonDelete;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *UserManagerDlg)
    {
        if (UserManagerDlg->objectName().isEmpty())
            UserManagerDlg->setObjectName(QStringLiteral("UserManagerDlg"));
        UserManagerDlg->resize(438, 345);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/img/user_group.png"), QSize(), QIcon::Normal, QIcon::Off);
        UserManagerDlg->setWindowIcon(icon);
        gridLayout_4 = new QGridLayout(UserManagerDlg);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tableWidgetUserInfo = new QTableWidget(UserManagerDlg);
        if (tableWidgetUserInfo->columnCount() < 3)
            tableWidgetUserInfo->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetUserInfo->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetUserInfo->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetUserInfo->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidgetUserInfo->setObjectName(QStringLiteral("tableWidgetUserInfo"));

        gridLayout_3->addWidget(tableWidgetUserInfo, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButtonAdd = new QPushButton(UserManagerDlg);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));

        gridLayout->addWidget(pushButtonAdd, 0, 0, 1, 1);

        pushButtonEdit = new QPushButton(UserManagerDlg);
        pushButtonEdit->setObjectName(QStringLiteral("pushButtonEdit"));

        gridLayout->addWidget(pushButtonEdit, 1, 0, 1, 1);

        pushButtonDelete = new QPushButton(UserManagerDlg);
        pushButtonDelete->setObjectName(QStringLiteral("pushButtonDelete"));

        gridLayout->addWidget(pushButtonDelete, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);


        retranslateUi(UserManagerDlg);

        QMetaObject::connectSlotsByName(UserManagerDlg);
    } // setupUi

    void retranslateUi(QDialog *UserManagerDlg)
    {
        UserManagerDlg->setWindowTitle(QApplication::translate("UserManagerDlg", "\347\224\250\346\210\267\347\256\241\347\220\206", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetUserInfo->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("UserManagerDlg", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetUserInfo->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("UserManagerDlg", "\345\257\206\347\240\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetUserInfo->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("UserManagerDlg", "\346\235\203\351\231\220", Q_NULLPTR));
        pushButtonAdd->setText(QApplication::translate("UserManagerDlg", "\346\267\273\345\212\240", Q_NULLPTR));
        pushButtonEdit->setText(QApplication::translate("UserManagerDlg", "\347\274\226\350\276\221", Q_NULLPTR));
        pushButtonDelete->setText(QApplication::translate("UserManagerDlg", "\345\210\240\351\231\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserManagerDlg: public Ui_UserManagerDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGERDLG_H
