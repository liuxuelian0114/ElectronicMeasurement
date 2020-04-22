/********************************************************************************
** Form generated from reading UI file 'ParaAgument.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAAGUMENT_H
#define UI_PARAAGUMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ParaAgument
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonDeleteAll;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonSave;

    void setupUi(QDialog *ParaAgument)
    {
        if (ParaAgument->objectName().isEmpty())
            ParaAgument->setObjectName(QStringLiteral("ParaAgument"));
        ParaAgument->resize(514, 590);
        ParaAgument->setMinimumSize(QSize(300, 400));
        gridLayout = new QGridLayout(ParaAgument);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new QTableView(ParaAgument);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButtonAdd = new QPushButton(ParaAgument);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));

        verticalLayout->addWidget(pushButtonAdd);

        pushButtonDelete = new QPushButton(ParaAgument);
        pushButtonDelete->setObjectName(QStringLiteral("pushButtonDelete"));

        verticalLayout->addWidget(pushButtonDelete);

        pushButtonDeleteAll = new QPushButton(ParaAgument);
        pushButtonDeleteAll->setObjectName(QStringLiteral("pushButtonDeleteAll"));

        verticalLayout->addWidget(pushButtonDeleteAll);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButtonSave = new QPushButton(ParaAgument);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));

        verticalLayout->addWidget(pushButtonSave);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);


        retranslateUi(ParaAgument);

        QMetaObject::connectSlotsByName(ParaAgument);
    } // setupUi

    void retranslateUi(QDialog *ParaAgument)
    {
        ParaAgument->setWindowTitle(QApplication::translate("ParaAgument", "Para\350\256\276\347\275\256", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButtonAdd->setToolTip(QApplication::translate("ParaAgument", "\345\220\221\344\270\213\344\270\200\350\241\214\346\267\273\345\212\240", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonAdd->setText(QApplication::translate("ParaAgument", "\346\267\273\345\212\240", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButtonDelete->setToolTip(QApplication::translate("ParaAgument", "\345\210\240\351\231\244\351\200\211\346\213\251\350\241\214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonDelete->setText(QApplication::translate("ParaAgument", "\345\210\240\351\231\244", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButtonDeleteAll->setToolTip(QApplication::translate("ParaAgument", "\345\210\240\351\231\244\346\211\200\346\234\211\350\241\214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonDeleteAll->setText(QApplication::translate("ParaAgument", "\345\210\240\351\231\244\345\205\250\351\203\250", Q_NULLPTR));
        pushButtonSave->setText(QApplication::translate("ParaAgument", "\344\277\235\345\255\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ParaAgument: public Ui_ParaAgument {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAAGUMENT_H
