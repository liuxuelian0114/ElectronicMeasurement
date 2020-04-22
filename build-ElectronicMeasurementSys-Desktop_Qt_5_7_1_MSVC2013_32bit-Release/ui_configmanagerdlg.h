/********************************************************************************
** Form generated from reading UI file 'configmanagerdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGMANAGERDLG_H
#define UI_CONFIGMANAGERDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ConfigManagerDlg
{
public:
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_4;
    QLabel *label_6;
    QLineEdit *lineEditBatFolder;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditForword;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonSave;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditCollect;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditNAS;
    QLabel *label_4;
    QLineEdit *lineEditAccount;
    QLabel *label_5;
    QLineEdit *lineEditPassward;

    void setupUi(QDialog *ConfigManagerDlg)
    {
        if (ConfigManagerDlg->objectName().isEmpty())
            ConfigManagerDlg->setObjectName(QStringLiteral("ConfigManagerDlg"));
        ConfigManagerDlg->resize(271, 361);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/img/config.png"), QSize(), QIcon::Normal, QIcon::Off);
        ConfigManagerDlg->setWindowIcon(icon);
        gridLayout_6 = new QGridLayout(ConfigManagerDlg);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_6 = new QLabel(ConfigManagerDlg);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(120, 20));
        label_6->setMaximumSize(QSize(120, 20));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_6, 0, 0, 1, 1);

        lineEditBatFolder = new QLineEdit(ConfigManagerDlg);
        lineEditBatFolder->setObjectName(QStringLiteral("lineEditBatFolder"));
        lineEditBatFolder->setMinimumSize(QSize(100, 0));

        gridLayout_4->addWidget(lineEditBatFolder, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_4, 3, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(ConfigManagerDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(120, 20));
        label_2->setMaximumSize(QSize(120, 16777215));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        lineEditForword = new QLineEdit(ConfigManagerDlg);
        lineEditForword->setObjectName(QStringLiteral("lineEditForword"));
        lineEditForword->setMinimumSize(QSize(100, 0));

        gridLayout_2->addWidget(lineEditForword, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_2, 1, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        pushButtonSave = new QPushButton(ConfigManagerDlg);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));

        gridLayout_5->addWidget(pushButtonSave, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 5, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(ConfigManagerDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(120, 20));
        label->setMaximumSize(QSize(120, 16777215));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditCollect = new QLineEdit(ConfigManagerDlg);
        lineEditCollect->setObjectName(QStringLiteral("lineEditCollect"));
        lineEditCollect->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(lineEditCollect, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout, 0, 0, 1, 1);

        groupBox = new QGroupBox(ConfigManagerDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(120, 20));
        label_3->setMaximumSize(QSize(120, 16777215));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        lineEditNAS = new QLineEdit(groupBox);
        lineEditNAS->setObjectName(QStringLiteral("lineEditNAS"));
        lineEditNAS->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(lineEditNAS, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(120, 20));
        label_4->setMaximumSize(QSize(120, 20));

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);

        lineEditAccount = new QLineEdit(groupBox);
        lineEditAccount->setObjectName(QStringLiteral("lineEditAccount"));
        lineEditAccount->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(lineEditAccount, 1, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(120, 20));
        label_5->setMaximumSize(QSize(120, 20));

        gridLayout_3->addWidget(label_5, 2, 0, 1, 1);

        lineEditPassward = new QLineEdit(groupBox);
        lineEditPassward->setObjectName(QStringLiteral("lineEditPassward"));
        lineEditPassward->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(lineEditPassward, 2, 1, 1, 1);


        gridLayout_6->addWidget(groupBox, 4, 0, 1, 1);

        QWidget::setTabOrder(lineEditCollect, lineEditForword);
        QWidget::setTabOrder(lineEditForword, lineEditNAS);
        QWidget::setTabOrder(lineEditNAS, lineEditAccount);
        QWidget::setTabOrder(lineEditAccount, lineEditPassward);
        QWidget::setTabOrder(lineEditPassward, pushButtonSave);

        retranslateUi(ConfigManagerDlg);

        QMetaObject::connectSlotsByName(ConfigManagerDlg);
    } // setupUi

    void retranslateUi(QDialog *ConfigManagerDlg)
    {
        ConfigManagerDlg->setWindowTitle(QApplication::translate("ConfigManagerDlg", "\351\205\215\347\275\256\347\256\241\347\220\206", Q_NULLPTR));
        label_6->setText(QApplication::translate("ConfigManagerDlg", "\350\204\232\346\234\254\346\226\207\344\273\266\345\244\271\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("ConfigManagerDlg", "\346\225\260\346\215\256\350\275\254\345\217\221\350\275\257\344\273\266\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        pushButtonSave->setText(QApplication::translate("ConfigManagerDlg", "\344\277\235\345\255\230", Q_NULLPTR));
        label->setText(QApplication::translate("ConfigManagerDlg", "\346\225\260\346\215\256\351\207\207\351\233\206\346\250\241\345\235\227\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ConfigManagerDlg", "NAS", Q_NULLPTR));
        label_3->setText(QApplication::translate("ConfigManagerDlg", "<html><head/><body><p align=\"right\">\345\234\260\345\235\200\357\274\232</p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("ConfigManagerDlg", "<html><head/><body><p align=\"right\">\347\231\273\345\275\225\345\220\215\357\274\232</p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("ConfigManagerDlg", "<html><head/><body><p align=\"right\">\345\257\206\347\240\201\357\274\232</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConfigManagerDlg: public Ui_ConfigManagerDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGMANAGERDLG_H
