/********************************************************************************
** Form generated from reading UI file 'argumentmanagerdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARGUMENTMANAGERDLG_H
#define UI_ARGUMENTMANAGERDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ArgumentManagerDlg
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QFrame *frame;
    QGridLayout *gridLayout;
    QPushButton *pushButtonAddTemplate;
    QPushButton *pushButtonDeleteTemplete;
    QPushButton *pushButtonSetTemplate;
    QTabWidget *tabWidget;

    void setupUi(QDialog *ArgumentManagerDlg)
    {
        if (ArgumentManagerDlg->objectName().isEmpty())
            ArgumentManagerDlg->setObjectName(QStringLiteral("ArgumentManagerDlg"));
        ArgumentManagerDlg->resize(700, 750);
        ArgumentManagerDlg->setMinimumSize(QSize(700, 750));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/img/parameters.png"), QSize(), QIcon::Normal, QIcon::Off);
        ArgumentManagerDlg->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(ArgumentManagerDlg);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listWidget = new QListWidget(ArgumentManagerDlg);
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferAntialias);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qlistwidgetitem->setFont(font);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        frame = new QFrame(ArgumentManagerDlg);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButtonAddTemplate = new QPushButton(frame);
        pushButtonAddTemplate->setObjectName(QStringLiteral("pushButtonAddTemplate"));

        gridLayout->addWidget(pushButtonAddTemplate, 1, 0, 1, 1);

        pushButtonDeleteTemplete = new QPushButton(frame);
        pushButtonDeleteTemplete->setObjectName(QStringLiteral("pushButtonDeleteTemplete"));

        gridLayout->addWidget(pushButtonDeleteTemplete, 2, 0, 1, 1);

        pushButtonSetTemplate = new QPushButton(frame);
        pushButtonSetTemplate->setObjectName(QStringLiteral("pushButtonSetTemplate"));

        gridLayout->addWidget(pushButtonSetTemplate, 3, 0, 1, 1);


        verticalLayout->addWidget(frame);

        verticalLayout->setStretch(0, 5);

        horizontalLayout->addLayout(verticalLayout);

        tabWidget = new QTabWidget(ArgumentManagerDlg);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));

        horizontalLayout->addWidget(tabWidget);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);

        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(ArgumentManagerDlg);

        QMetaObject::connectSlotsByName(ArgumentManagerDlg);
    } // setupUi

    void retranslateUi(QDialog *ArgumentManagerDlg)
    {
        ArgumentManagerDlg->setWindowTitle(QApplication::translate("ArgumentManagerDlg", "\345\217\202\346\225\260\347\256\241\347\220\206", Q_NULLPTR));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("ArgumentManagerDlg", "\346\250\241\346\235\277", Q_NULLPTR));
        listWidget->setSortingEnabled(__sortingEnabled);

        pushButtonAddTemplate->setText(QApplication::translate("ArgumentManagerDlg", "\346\267\273\345\212\240\346\250\241\346\235\277", Q_NULLPTR));
        pushButtonDeleteTemplete->setText(QApplication::translate("ArgumentManagerDlg", "\345\210\240\351\231\244\346\250\241\346\235\277", Q_NULLPTR));
        pushButtonSetTemplate->setText(QApplication::translate("ArgumentManagerDlg", "\350\256\276\347\275\256\346\250\241\346\235\277", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ArgumentManagerDlg: public Ui_ArgumentManagerDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARGUMENTMANAGERDLG_H
