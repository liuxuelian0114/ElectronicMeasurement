/********************************************************************************
** Form generated from reading UI file 'playbackdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYBACKDLG_H
#define UI_PLAYBACKDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_PlayBackDlg
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditDownLoad;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonStop;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *PlayBackDlg)
    {
        if (PlayBackDlg->objectName().isEmpty())
            PlayBackDlg->setObjectName(QStringLiteral("PlayBackDlg"));
        PlayBackDlg->resize(323, 415);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/img/replay.ico"), QSize(), QIcon::Normal, QIcon::Off);
        PlayBackDlg->setWindowIcon(icon);
        gridLayout = new QGridLayout(PlayBackDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(PlayBackDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(100, 20));

        horizontalLayout->addWidget(label);

        lineEditDownLoad = new QLineEdit(PlayBackDlg);
        lineEditDownLoad->setObjectName(QStringLiteral("lineEditDownLoad"));
        lineEditDownLoad->setMinimumSize(QSize(0, 20));

        horizontalLayout->addWidget(lineEditDownLoad);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        listWidget = new QListWidget(PlayBackDlg);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout->addWidget(listWidget, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonStart = new QPushButton(PlayBackDlg);
        pushButtonStart->setObjectName(QStringLiteral("pushButtonStart"));

        horizontalLayout_2->addWidget(pushButtonStart);

        pushButtonStop = new QPushButton(PlayBackDlg);
        pushButtonStop->setObjectName(QStringLiteral("pushButtonStop"));

        horizontalLayout_2->addWidget(pushButtonStop);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        retranslateUi(PlayBackDlg);

        QMetaObject::connectSlotsByName(PlayBackDlg);
    } // setupUi

    void retranslateUi(QDialog *PlayBackDlg)
    {
        PlayBackDlg->setWindowTitle(QApplication::translate("PlayBackDlg", "\351\200\211\346\213\251\345\256\236\351\252\214", Q_NULLPTR));
        label->setText(QApplication::translate("PlayBackDlg", "\345\233\236\346\224\276\346\226\207\344\273\266\345\255\230\346\224\276\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        pushButtonStart->setText(QApplication::translate("PlayBackDlg", "\345\274\200\345\247\213\345\233\236\346\224\276", Q_NULLPTR));
        pushButtonStop->setText(QApplication::translate("PlayBackDlg", "\345\201\234\346\255\242\345\233\236\346\224\276", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PlayBackDlg: public Ui_PlayBackDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYBACKDLG_H
