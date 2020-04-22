/********************************************************************************
** Form generated from reading UI file 'SelectPath.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTPATH_H
#define UI_SELECTPATH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_SelectPath
{
public:
    QFormLayout *formLayout;
    QLabel *labelPrompt;
    QLineEdit *lineEditPath;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonDetermine;

    void setupUi(QDialog *SelectPath)
    {
        if (SelectPath->objectName().isEmpty())
            SelectPath->setObjectName(QStringLiteral("SelectPath"));
        SelectPath->resize(314, 134);
        formLayout = new QFormLayout(SelectPath);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        labelPrompt = new QLabel(SelectPath);
        labelPrompt->setObjectName(QStringLiteral("labelPrompt"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelPrompt);

        lineEditPath = new QLineEdit(SelectPath);
        lineEditPath->setObjectName(QStringLiteral("lineEditPath"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditPath);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(1, QFormLayout::LabelRole, verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(57, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonDetermine = new QPushButton(SelectPath);
        pushButtonDetermine->setObjectName(QStringLiteral("pushButtonDetermine"));

        horizontalLayout->addWidget(pushButtonDetermine);


        formLayout->setLayout(2, QFormLayout::SpanningRole, horizontalLayout);


        retranslateUi(SelectPath);

        QMetaObject::connectSlotsByName(SelectPath);
    } // setupUi

    void retranslateUi(QDialog *SelectPath)
    {
        SelectPath->setWindowTitle(QApplication::translate("SelectPath", "Dialog", Q_NULLPTR));
        labelPrompt->setText(QApplication::translate("SelectPath", "<html><head/><body><p align=\"right\">\351\200\211\346\213\251\350\267\257\345\276\204\357\274\232</p></body></html>", Q_NULLPTR));
        pushButtonDetermine->setText(QApplication::translate("SelectPath", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SelectPath: public Ui_SelectPath {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTPATH_H
