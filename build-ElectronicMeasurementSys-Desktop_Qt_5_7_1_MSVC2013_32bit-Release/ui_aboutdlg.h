/********************************************************************************
** Form generated from reading UI file 'aboutdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDLG_H
#define UI_ABOUTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutDlg
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *labelName;
    QLabel *labelSoftName;
    QLabel *labelVersion;
    QLabel *labelSoftVersion;

    void setupUi(QDialog *AboutDlg)
    {
        if (AboutDlg->objectName().isEmpty())
            AboutDlg->setObjectName(QStringLiteral("AboutDlg"));
        AboutDlg->resize(370, 142);
        label = new QLabel(AboutDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(29, 34, 91, 71));
        label->setPixmap(QPixmap(QString::fromUtf8(":/res/image/logo.ico")));
        layoutWidget = new QWidget(AboutDlg);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(135, 42, 201, 61));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(3);
        formLayout->setVerticalSpacing(15);
        formLayout->setContentsMargins(6, 6, 6, 6);
        labelName = new QLabel(layoutWidget);
        labelName->setObjectName(QStringLiteral("labelName"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelName);

        labelSoftName = new QLabel(layoutWidget);
        labelSoftName->setObjectName(QStringLiteral("labelSoftName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, labelSoftName);

        labelVersion = new QLabel(layoutWidget);
        labelVersion->setObjectName(QStringLiteral("labelVersion"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelVersion);

        labelSoftVersion = new QLabel(layoutWidget);
        labelSoftVersion->setObjectName(QStringLiteral("labelSoftVersion"));

        formLayout->setWidget(1, QFormLayout::FieldRole, labelSoftVersion);


        retranslateUi(AboutDlg);

        QMetaObject::connectSlotsByName(AboutDlg);
    } // setupUi

    void retranslateUi(QDialog *AboutDlg)
    {
        AboutDlg->setWindowTitle(QApplication::translate("AboutDlg", "Dialog", Q_NULLPTR));
        label->setText(QString());
        labelName->setText(QApplication::translate("AboutDlg", "\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        labelSoftName->setText(QApplication::translate("AboutDlg", "\347\224\265\345\255\220\346\265\213\351\207\217\350\275\257\344\273\266", Q_NULLPTR));
        labelVersion->setText(QApplication::translate("AboutDlg", "\347\211\210\346\234\254\357\274\232", Q_NULLPTR));
        labelSoftVersion->setText(QApplication::translate("AboutDlg", "1.0.0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AboutDlg: public Ui_AboutDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDLG_H
