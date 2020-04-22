/********************************************************************************
** Form generated from reading UI file 'logindlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDLG_H
#define UI_LOGINDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_LoginDlg
{
public:
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonQuit;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QFrame *line;
    QGridLayout *gridLayout;
    QLineEdit *lineEditUser;
    QLineEdit *lineEditPassword;
    QSpacerItem *horizontalSpacer;
    QLabel *labelImg;

    void setupUi(QDialog *LoginDlg)
    {
        if (LoginDlg->objectName().isEmpty())
            LoginDlg->setObjectName(QStringLiteral("LoginDlg"));
        LoginDlg->resize(297, 147);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/img/User_login.png"), QSize(), QIcon::Normal, QIcon::Off);
        LoginDlg->setWindowIcon(icon);
        gridLayout_5 = new QGridLayout(LoginDlg);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        pushButtonOk = new QPushButton(LoginDlg);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));

        gridLayout_3->addWidget(pushButtonOk, 0, 1, 1, 1);

        pushButtonQuit = new QPushButton(LoginDlg);
        pushButtonQuit->setObjectName(QStringLiteral("pushButtonQuit"));

        gridLayout_3->addWidget(pushButtonQuit, 0, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 1, 0, 1, 1);

        groupBox = new QGroupBox(LoginDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEditUser = new QLineEdit(groupBox);
        lineEditUser->setObjectName(QStringLiteral("lineEditUser"));

        gridLayout->addWidget(lineEditUser, 0, 0, 1, 2);

        lineEditPassword = new QLineEdit(groupBox);
        lineEditPassword->setObjectName(QStringLiteral("lineEditPassword"));
        lineEditPassword->setStyleSheet(QStringLiteral(""));
        lineEditPassword->setMaxLength(15);
        lineEditPassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEditPassword, 1, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 4, 1, 1);

        labelImg = new QLabel(groupBox);
        labelImg->setObjectName(QStringLiteral("labelImg"));
        labelImg->setPixmap(QPixmap(QString::fromUtf8(":/res/image/user_login.png")));

        gridLayout_2->addWidget(labelImg, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);


        retranslateUi(LoginDlg);

        QMetaObject::connectSlotsByName(LoginDlg);
    } // setupUi

    void retranslateUi(QDialog *LoginDlg)
    {
        LoginDlg->setWindowTitle(QApplication::translate("LoginDlg", "\347\224\250\346\210\267\347\231\273\345\275\225", Q_NULLPTR));
        pushButtonOk->setText(QApplication::translate("LoginDlg", "\347\231\273\345\275\225", Q_NULLPTR));
        pushButtonQuit->setText(QApplication::translate("LoginDlg", "\351\200\200\345\207\272", Q_NULLPTR));
        groupBox->setTitle(QString());
        lineEditUser->setText(QApplication::translate("LoginDlg", "admin", Q_NULLPTR));
        lineEditUser->setPlaceholderText(QApplication::translate("LoginDlg", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        lineEditPassword->setText(QApplication::translate("LoginDlg", "123456", Q_NULLPTR));
        lineEditPassword->setPlaceholderText(QApplication::translate("LoginDlg", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", Q_NULLPTR));
        labelImg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginDlg: public Ui_LoginDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDLG_H
