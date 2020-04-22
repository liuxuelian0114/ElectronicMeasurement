/********************************************************************************
** Form generated from reading UI file 'userinfodlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFODLG_H
#define UI_USERINFODLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_UserInfoDlg
{
public:
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditUserName;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditPassword;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QComboBox *comboBoxPermission;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonOk;

    void setupUi(QDialog *UserInfoDlg)
    {
        if (UserInfoDlg->objectName().isEmpty())
            UserInfoDlg->setObjectName(QStringLiteral("UserInfoDlg"));
        UserInfoDlg->resize(191, 169);
        gridLayout_5 = new QGridLayout(UserInfoDlg);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(UserInfoDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditUserName = new QLineEdit(UserInfoDlg);
        lineEditUserName->setObjectName(QStringLiteral("lineEditUserName"));

        gridLayout->addWidget(lineEditUserName, 0, 1, 1, 1);

        gridLayout->setColumnStretch(0, 3);
        gridLayout->setColumnStretch(1, 7);

        gridLayout_5->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(UserInfoDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        lineEditPassword = new QLineEdit(UserInfoDlg);
        lineEditPassword->setObjectName(QStringLiteral("lineEditPassword"));

        gridLayout_2->addWidget(lineEditPassword, 0, 1, 1, 1);

        gridLayout_2->setColumnStretch(0, 3);
        gridLayout_2->setColumnStretch(1, 7);

        gridLayout_5->addLayout(gridLayout_2, 1, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_3 = new QLabel(UserInfoDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        comboBoxPermission = new QComboBox(UserInfoDlg);
        comboBoxPermission->setObjectName(QStringLiteral("comboBoxPermission"));

        gridLayout_3->addWidget(comboBoxPermission, 0, 1, 1, 1);

        gridLayout_3->setColumnStretch(0, 3);
        gridLayout_3->setColumnStretch(1, 7);

        gridLayout_5->addLayout(gridLayout_3, 2, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButtonOk = new QPushButton(UserInfoDlg);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));

        gridLayout_4->addWidget(pushButtonOk, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 3, 0, 1, 1);


        retranslateUi(UserInfoDlg);

        QMetaObject::connectSlotsByName(UserInfoDlg);
    } // setupUi

    void retranslateUi(QDialog *UserInfoDlg)
    {
        UserInfoDlg->setWindowTitle(QApplication::translate("UserInfoDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("UserInfoDlg", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("UserInfoDlg", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("UserInfoDlg", "\346\235\203\351\231\220\357\274\232", Q_NULLPTR));
        comboBoxPermission->clear();
        comboBoxPermission->insertItems(0, QStringList()
         << QApplication::translate("UserInfoDlg", "\346\231\256\351\200\232\347\224\250\346\210\267", Q_NULLPTR)
         << QApplication::translate("UserInfoDlg", "\351\253\230\347\272\247\347\224\250\346\210\267", Q_NULLPTR)
         << QApplication::translate("UserInfoDlg", "\350\266\205\347\272\247\347\224\250\346\210\267", Q_NULLPTR)
        );
        pushButtonOk->setText(QApplication::translate("UserInfoDlg", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserInfoDlg: public Ui_UserInfoDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFODLG_H
