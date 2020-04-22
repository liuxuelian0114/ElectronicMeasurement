/********************************************************************************
** Form generated from reading UI file 'argumentinfodlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARGUMENTINFODLG_H
#define UI_ARGUMENTINFODLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ArgumentInfoDlg
{
public:
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_17;
    QPushButton *pushButtonSave;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox_Para;
    QGridLayout *gridLayout_4;
    QLabel *label_27;
    QLineEdit *lineEdit_bpXNum;
    QLabel *label_29;
    QLineEdit *lineEdit_bpYNum;
    QLabel *label_31;
    QLineEdit *lineEdit_bpZNum;
    QLabel *label_33;
    QLineEdit *lineEdit_batch;
    QLabel *label_35;
    QLineEdit *lineEdit_bpXStartLocation;
    QLabel *label_37;
    QLineEdit *lineEdit_bpYStartLocation;
    QLabel *label_39;
    QLineEdit *lineEdit_bpZStartLocation;
    QLabel *label_41;
    QLineEdit *lineEdit_bpXSize;
    QLabel *label_42;
    QLineEdit *lineEdit_bpYSize;
    QLabel *label_43;
    QLineEdit *lineEdit_bpZSize;
    QLabel *label_44;
    QLineEdit *lineEdit_StartFrequency;
    QLabel *label_45;
    QLineEdit *lineEdit_EndFrequenncy;
    QGroupBox *groupBox_TestRecord;
    QGridLayout *gridLayout_5;
    QTextEdit *textEdit_TestRecord;
    QGroupBox *groupBox_Servo;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_10;
    QLineEdit *lineEditSpeedV;
    QLabel *label_3;
    QLabel *label_12;
    QLineEdit *lineEditStartX;
    QLabel *label_5;
    QLabel *label_14;
    QLineEdit *lineEditStartY;
    QLabel *label_11;
    QLabel *label_16;
    QLineEdit *lineEditEndX;
    QLabel *label_7;
    QLabel *label_18;
    QLineEdit *lineEditEndY;
    QLabel *label_19;
    QLabel *label_20;
    QLineEdit *lineEditStepY;
    QLabel *label_21;
    QLabel *label_8;
    QLineEdit *lineEditSpeedH;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_3;
    QLabel *label_24;
    QLineEdit *lineEditTestName;
    QLineEdit *lineEditIdentifying;
    QLabel *label_25;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBox_RF;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEditSweepFStart;
    QLineEdit *lineEditSweepFEnd;
    QLabel *label_23;
    QLabel *label_15;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_9;
    QLineEdit *lineEditAtten;
    QLabel *label_13;
    QLabel *label_4;
    QLabel *label_17;
    QLabel *label_22;
    QComboBox *comboBoxGather;
    QLabel *label_26;
    QSpacerItem *verticalSpacer;
    QComboBox *comboBoxSys_init;
    QComboBox *comboBoxReset;
    QComboBox *comboBoxCal;

    void setupUi(QDialog *ArgumentInfoDlg)
    {
        if (ArgumentInfoDlg->objectName().isEmpty())
            ArgumentInfoDlg->setObjectName(QStringLiteral("ArgumentInfoDlg"));
        ArgumentInfoDlg->setEnabled(true);
        ArgumentInfoDlg->resize(583, 704);
        ArgumentInfoDlg->setMinimumSize(QSize(0, 0));
        ArgumentInfoDlg->setMaximumSize(QSize(1000, 1000));
        gridLayout_7 = new QGridLayout(ArgumentInfoDlg);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_17 = new QGridLayout();
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        pushButtonSave = new QPushButton(ArgumentInfoDlg);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));

        gridLayout_17->addWidget(pushButtonSave, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_17->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_17->addItem(verticalSpacer_3, 0, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_17, 3, 0, 1, 2);

        groupBox_Para = new QGroupBox(ArgumentInfoDlg);
        groupBox_Para->setObjectName(QStringLiteral("groupBox_Para"));
        gridLayout_4 = new QGridLayout(groupBox_Para);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_27 = new QLabel(groupBox_Para);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setMinimumSize(QSize(135, 20));
        label_27->setMaximumSize(QSize(60, 20));
        label_27->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_27, 0, 0, 1, 1);

        lineEdit_bpXNum = new QLineEdit(groupBox_Para);
        lineEdit_bpXNum->setObjectName(QStringLiteral("lineEdit_bpXNum"));
        lineEdit_bpXNum->setMinimumSize(QSize(0, 20));
        lineEdit_bpXNum->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(lineEdit_bpXNum, 0, 1, 1, 1);

        label_29 = new QLabel(groupBox_Para);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setMinimumSize(QSize(135, 20));
        label_29->setMaximumSize(QSize(60, 20));
        label_29->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_29, 1, 0, 1, 1);

        lineEdit_bpYNum = new QLineEdit(groupBox_Para);
        lineEdit_bpYNum->setObjectName(QStringLiteral("lineEdit_bpYNum"));
        lineEdit_bpYNum->setMinimumSize(QSize(0, 20));
        lineEdit_bpYNum->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(lineEdit_bpYNum, 1, 1, 1, 1);

        label_31 = new QLabel(groupBox_Para);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setMinimumSize(QSize(135, 20));
        label_31->setMaximumSize(QSize(60, 20));
        label_31->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_31, 2, 0, 1, 1);

        lineEdit_bpZNum = new QLineEdit(groupBox_Para);
        lineEdit_bpZNum->setObjectName(QStringLiteral("lineEdit_bpZNum"));
        lineEdit_bpZNum->setMinimumSize(QSize(0, 20));
        lineEdit_bpZNum->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(lineEdit_bpZNum, 2, 1, 1, 1);

        label_33 = new QLabel(groupBox_Para);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setMinimumSize(QSize(135, 20));
        label_33->setMaximumSize(QSize(60, 20));
        label_33->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_33, 3, 0, 1, 1);

        lineEdit_batch = new QLineEdit(groupBox_Para);
        lineEdit_batch->setObjectName(QStringLiteral("lineEdit_batch"));
        lineEdit_batch->setMinimumSize(QSize(0, 20));
        lineEdit_batch->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(lineEdit_batch, 3, 1, 1, 1);

        label_35 = new QLabel(groupBox_Para);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setMinimumSize(QSize(135, 20));
        label_35->setMaximumSize(QSize(60, 20));
        label_35->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_35, 4, 0, 1, 1);

        lineEdit_bpXStartLocation = new QLineEdit(groupBox_Para);
        lineEdit_bpXStartLocation->setObjectName(QStringLiteral("lineEdit_bpXStartLocation"));
        lineEdit_bpXStartLocation->setMinimumSize(QSize(0, 20));
        lineEdit_bpXStartLocation->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(lineEdit_bpXStartLocation, 4, 1, 1, 1);

        label_37 = new QLabel(groupBox_Para);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setMinimumSize(QSize(135, 20));
        label_37->setMaximumSize(QSize(60, 20));
        label_37->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_37, 5, 0, 1, 1);

        lineEdit_bpYStartLocation = new QLineEdit(groupBox_Para);
        lineEdit_bpYStartLocation->setObjectName(QStringLiteral("lineEdit_bpYStartLocation"));
        lineEdit_bpYStartLocation->setMinimumSize(QSize(0, 20));
        lineEdit_bpYStartLocation->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(lineEdit_bpYStartLocation, 5, 1, 1, 1);

        label_39 = new QLabel(groupBox_Para);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setMinimumSize(QSize(135, 20));
        label_39->setMaximumSize(QSize(60, 20));
        label_39->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_39, 6, 0, 1, 1);

        lineEdit_bpZStartLocation = new QLineEdit(groupBox_Para);
        lineEdit_bpZStartLocation->setObjectName(QStringLiteral("lineEdit_bpZStartLocation"));
        lineEdit_bpZStartLocation->setMinimumSize(QSize(0, 20));
        lineEdit_bpZStartLocation->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(lineEdit_bpZStartLocation, 6, 1, 1, 1);

        label_41 = new QLabel(groupBox_Para);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setMinimumSize(QSize(135, 20));
        label_41->setMaximumSize(QSize(60, 20));
        label_41->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_41, 7, 0, 1, 1);

        lineEdit_bpXSize = new QLineEdit(groupBox_Para);
        lineEdit_bpXSize->setObjectName(QStringLiteral("lineEdit_bpXSize"));
        lineEdit_bpXSize->setMinimumSize(QSize(0, 20));
        lineEdit_bpXSize->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(lineEdit_bpXSize, 7, 1, 1, 1);

        label_42 = new QLabel(groupBox_Para);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setMinimumSize(QSize(135, 20));
        label_42->setMaximumSize(QSize(60, 20));
        label_42->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_42, 8, 0, 1, 1);

        lineEdit_bpYSize = new QLineEdit(groupBox_Para);
        lineEdit_bpYSize->setObjectName(QStringLiteral("lineEdit_bpYSize"));
        lineEdit_bpYSize->setMinimumSize(QSize(0, 20));
        lineEdit_bpYSize->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(lineEdit_bpYSize, 8, 1, 1, 1);

        label_43 = new QLabel(groupBox_Para);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setMinimumSize(QSize(135, 20));
        label_43->setMaximumSize(QSize(60, 20));
        label_43->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_43, 9, 0, 1, 1);

        lineEdit_bpZSize = new QLineEdit(groupBox_Para);
        lineEdit_bpZSize->setObjectName(QStringLiteral("lineEdit_bpZSize"));
        lineEdit_bpZSize->setMinimumSize(QSize(0, 20));
        lineEdit_bpZSize->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(lineEdit_bpZSize, 9, 1, 1, 1);

        label_44 = new QLabel(groupBox_Para);
        label_44->setObjectName(QStringLiteral("label_44"));
        label_44->setMinimumSize(QSize(135, 20));
        label_44->setMaximumSize(QSize(60, 20));
        label_44->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_44, 10, 0, 1, 1);

        lineEdit_StartFrequency = new QLineEdit(groupBox_Para);
        lineEdit_StartFrequency->setObjectName(QStringLiteral("lineEdit_StartFrequency"));
        lineEdit_StartFrequency->setMinimumSize(QSize(0, 20));
        lineEdit_StartFrequency->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(lineEdit_StartFrequency, 10, 1, 1, 1);

        label_45 = new QLabel(groupBox_Para);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setMinimumSize(QSize(135, 20));
        label_45->setMaximumSize(QSize(60, 20));
        label_45->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_45, 11, 0, 1, 1);

        lineEdit_EndFrequenncy = new QLineEdit(groupBox_Para);
        lineEdit_EndFrequenncy->setObjectName(QStringLiteral("lineEdit_EndFrequenncy"));
        lineEdit_EndFrequenncy->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(lineEdit_EndFrequenncy, 11, 1, 1, 1);


        gridLayout_7->addWidget(groupBox_Para, 1, 1, 1, 1);

        groupBox_TestRecord = new QGroupBox(ArgumentInfoDlg);
        groupBox_TestRecord->setObjectName(QStringLiteral("groupBox_TestRecord"));
        gridLayout_5 = new QGridLayout(groupBox_TestRecord);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        textEdit_TestRecord = new QTextEdit(groupBox_TestRecord);
        textEdit_TestRecord->setObjectName(QStringLiteral("textEdit_TestRecord"));

        gridLayout_5->addWidget(textEdit_TestRecord, 0, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_TestRecord, 2, 1, 1, 1);

        groupBox_Servo = new QGroupBox(ArgumentInfoDlg);
        groupBox_Servo->setObjectName(QStringLiteral("groupBox_Servo"));
        gridLayout = new QGridLayout(groupBox_Servo);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(groupBox_Servo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(30, 20));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label_10 = new QLabel(groupBox_Servo);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(60, 20));
        label_10->setMaximumSize(QSize(60, 20));
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        lineEditSpeedV = new QLineEdit(groupBox_Servo);
        lineEditSpeedV->setObjectName(QStringLiteral("lineEditSpeedV"));
        lineEditSpeedV->setMinimumSize(QSize(100, 0));
        lineEditSpeedV->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lineEditSpeedV, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox_Servo);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(30, 20));

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        label_12 = new QLabel(groupBox_Servo);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(60, 20));
        label_12->setMaximumSize(QSize(60, 20));
        label_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_12, 2, 0, 1, 1);

        lineEditStartX = new QLineEdit(groupBox_Servo);
        lineEditStartX->setObjectName(QStringLiteral("lineEditStartX"));
        lineEditStartX->setMinimumSize(QSize(100, 0));
        lineEditStartX->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lineEditStartX, 2, 1, 1, 1);

        label_5 = new QLabel(groupBox_Servo);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(30, 20));

        gridLayout->addWidget(label_5, 2, 2, 1, 1);

        label_14 = new QLabel(groupBox_Servo);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(60, 20));
        label_14->setMaximumSize(QSize(60, 20));
        label_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_14, 3, 0, 1, 1);

        lineEditStartY = new QLineEdit(groupBox_Servo);
        lineEditStartY->setObjectName(QStringLiteral("lineEditStartY"));
        lineEditStartY->setMinimumSize(QSize(100, 0));
        lineEditStartY->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lineEditStartY, 3, 1, 1, 1);

        label_11 = new QLabel(groupBox_Servo);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMaximumSize(QSize(30, 20));

        gridLayout->addWidget(label_11, 3, 2, 1, 1);

        label_16 = new QLabel(groupBox_Servo);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMinimumSize(QSize(60, 20));
        label_16->setMaximumSize(QSize(60, 20));
        label_16->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_16, 4, 0, 1, 1);

        lineEditEndX = new QLineEdit(groupBox_Servo);
        lineEditEndX->setObjectName(QStringLiteral("lineEditEndX"));
        lineEditEndX->setMinimumSize(QSize(100, 0));
        lineEditEndX->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lineEditEndX, 4, 1, 1, 1);

        label_7 = new QLabel(groupBox_Servo);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(30, 20));

        gridLayout->addWidget(label_7, 4, 2, 1, 1);

        label_18 = new QLabel(groupBox_Servo);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMinimumSize(QSize(60, 20));
        label_18->setMaximumSize(QSize(60, 20));
        label_18->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_18, 5, 0, 1, 1);

        lineEditEndY = new QLineEdit(groupBox_Servo);
        lineEditEndY->setObjectName(QStringLiteral("lineEditEndY"));
        lineEditEndY->setMinimumSize(QSize(100, 0));
        lineEditEndY->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lineEditEndY, 5, 1, 1, 1);

        label_19 = new QLabel(groupBox_Servo);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMaximumSize(QSize(30, 20));

        gridLayout->addWidget(label_19, 5, 2, 1, 1);

        label_20 = new QLabel(groupBox_Servo);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setMinimumSize(QSize(60, 20));
        label_20->setMaximumSize(QSize(60, 20));
        label_20->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_20, 6, 0, 1, 1);

        lineEditStepY = new QLineEdit(groupBox_Servo);
        lineEditStepY->setObjectName(QStringLiteral("lineEditStepY"));
        lineEditStepY->setMinimumSize(QSize(100, 0));
        lineEditStepY->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lineEditStepY, 6, 1, 1, 1);

        label_21 = new QLabel(groupBox_Servo);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setMaximumSize(QSize(30, 20));

        gridLayout->addWidget(label_21, 6, 2, 1, 1);

        label_8 = new QLabel(groupBox_Servo);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(60, 20));
        label_8->setMaximumSize(QSize(60, 20));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        lineEditSpeedH = new QLineEdit(groupBox_Servo);
        lineEditSpeedH->setObjectName(QStringLiteral("lineEditSpeedH"));
        lineEditSpeedH->setMinimumSize(QSize(100, 0));
        lineEditSpeedH->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lineEditSpeedH, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 7, 1, 1, 1);


        gridLayout_7->addWidget(groupBox_Servo, 2, 0, 1, 1);

        groupBox = new QGroupBox(ArgumentInfoDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_6 = new QGridLayout(groupBox);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(163, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(163, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_24 = new QLabel(groupBox);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setMinimumSize(QSize(60, 20));
        label_24->setMaximumSize(QSize(60, 20));

        gridLayout_3->addWidget(label_24, 0, 0, 1, 1);

        lineEditTestName = new QLineEdit(groupBox);
        lineEditTestName->setObjectName(QStringLiteral("lineEditTestName"));
        lineEditTestName->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(lineEditTestName, 0, 1, 1, 1);

        lineEditIdentifying = new QLineEdit(groupBox);
        lineEditIdentifying->setObjectName(QStringLiteral("lineEditIdentifying"));
        lineEditIdentifying->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(lineEditIdentifying, 1, 1, 1, 1);

        label_25 = new QLabel(groupBox);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setMinimumSize(QSize(60, 20));
        label_25->setMaximumSize(QSize(60, 20));

        gridLayout_3->addWidget(label_25, 1, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_3, 0, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_4, 1, 1, 1, 1);


        gridLayout_7->addWidget(groupBox, 0, 0, 1, 2);

        groupBox_RF = new QGroupBox(ArgumentInfoDlg);
        groupBox_RF->setObjectName(QStringLiteral("groupBox_RF"));
        gridLayout_2 = new QGridLayout(groupBox_RF);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lineEditSweepFStart = new QLineEdit(groupBox_RF);
        lineEditSweepFStart->setObjectName(QStringLiteral("lineEditSweepFStart"));
        lineEditSweepFStart->setMinimumSize(QSize(100, 0));
        lineEditSweepFStart->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(lineEditSweepFStart, 1, 1, 1, 1);

        lineEditSweepFEnd = new QLineEdit(groupBox_RF);
        lineEditSweepFEnd->setObjectName(QStringLiteral("lineEditSweepFEnd"));
        lineEditSweepFEnd->setMinimumSize(QSize(100, 0));
        lineEditSweepFEnd->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(lineEditSweepFEnd, 2, 1, 1, 1);

        label_23 = new QLabel(groupBox_RF);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setMaximumSize(QSize(20, 20));

        gridLayout_2->addWidget(label_23, 1, 2, 1, 1);

        label_15 = new QLabel(groupBox_RF);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMinimumSize(QSize(60, 20));
        label_15->setMaximumSize(QSize(60, 20));
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_15, 2, 0, 1, 1);

        label = new QLabel(groupBox_RF);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(20, 20));

        gridLayout_2->addWidget(label, 3, 2, 1, 1);

        label_6 = new QLabel(groupBox_RF);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(60, 20));
        label_6->setMaximumSize(QSize(60, 20));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 6, 0, 1, 1);

        label_9 = new QLabel(groupBox_RF);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(60, 20));
        label_9->setMaximumSize(QSize(60, 20));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_9, 7, 0, 1, 1);

        lineEditAtten = new QLineEdit(groupBox_RF);
        lineEditAtten->setObjectName(QStringLiteral("lineEditAtten"));
        lineEditAtten->setMinimumSize(QSize(100, 0));
        lineEditAtten->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(lineEditAtten, 3, 1, 1, 1);

        label_13 = new QLabel(groupBox_RF);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(60, 20));
        label_13->setMaximumSize(QSize(60, 20));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_13, 1, 0, 1, 1);

        label_4 = new QLabel(groupBox_RF);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(60, 20));
        label_4->setMaximumSize(QSize(60, 20));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 5, 0, 1, 1);

        label_17 = new QLabel(groupBox_RF);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMinimumSize(QSize(60, 20));
        label_17->setMaximumSize(QSize(60, 20));
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_17, 3, 0, 1, 1);

        label_22 = new QLabel(groupBox_RF);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setMaximumSize(QSize(20, 20));

        gridLayout_2->addWidget(label_22, 2, 2, 1, 1);

        comboBoxGather = new QComboBox(groupBox_RF);
        comboBoxGather->setObjectName(QStringLiteral("comboBoxGather"));
        comboBoxGather->setMinimumSize(QSize(100, 20));

        gridLayout_2->addWidget(comboBoxGather, 4, 1, 1, 1);

        label_26 = new QLabel(groupBox_RF);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout_2->addWidget(label_26, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 8, 1, 1, 1);

        comboBoxSys_init = new QComboBox(groupBox_RF);
        comboBoxSys_init->setObjectName(QStringLiteral("comboBoxSys_init"));
        comboBoxSys_init->setMinimumSize(QSize(100, 20));
        comboBoxSys_init->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(comboBoxSys_init, 5, 1, 1, 1);

        comboBoxReset = new QComboBox(groupBox_RF);
        comboBoxReset->setObjectName(QStringLiteral("comboBoxReset"));
        comboBoxReset->setMinimumSize(QSize(100, 20));
        comboBoxReset->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(comboBoxReset, 6, 1, 1, 1);

        comboBoxCal = new QComboBox(groupBox_RF);
        comboBoxCal->setObjectName(QStringLiteral("comboBoxCal"));
        comboBoxCal->setMinimumSize(QSize(100, 20));
        comboBoxCal->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(comboBoxCal, 7, 1, 1, 1);


        gridLayout_7->addWidget(groupBox_RF, 1, 0, 1, 1);

        QWidget::setTabOrder(lineEditSweepFStart, lineEditSweepFEnd);
        QWidget::setTabOrder(lineEditSweepFEnd, lineEditAtten);
        QWidget::setTabOrder(lineEditAtten, comboBoxSys_init);
        QWidget::setTabOrder(comboBoxSys_init, comboBoxReset);
        QWidget::setTabOrder(comboBoxReset, comboBoxCal);
        QWidget::setTabOrder(comboBoxCal, lineEditSpeedH);
        QWidget::setTabOrder(lineEditSpeedH, lineEditSpeedV);
        QWidget::setTabOrder(lineEditSpeedV, lineEditStartX);
        QWidget::setTabOrder(lineEditStartX, lineEditStartY);
        QWidget::setTabOrder(lineEditStartY, lineEditEndX);
        QWidget::setTabOrder(lineEditEndX, lineEditEndY);
        QWidget::setTabOrder(lineEditEndY, lineEditStepY);
        QWidget::setTabOrder(lineEditStepY, pushButtonSave);
        QWidget::setTabOrder(pushButtonSave, lineEditIdentifying);

        retranslateUi(ArgumentInfoDlg);

        QMetaObject::connectSlotsByName(ArgumentInfoDlg);
    } // setupUi

    void retranslateUi(QDialog *ArgumentInfoDlg)
    {
        ArgumentInfoDlg->setWindowTitle(QApplication::translate("ArgumentInfoDlg", "\345\217\202\346\225\260\351\205\215\347\275\256", Q_NULLPTR));
        pushButtonSave->setText(QApplication::translate("ArgumentInfoDlg", "\344\277\235\345\255\230", Q_NULLPTR));
        groupBox_Para->setTitle(QApplication::translate("ArgumentInfoDlg", "\346\210\220\345\203\217\345\217\202\346\225\260", Q_NULLPTR));
        label_27->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\346\260\264\345\271\263\345\220\221\347\275\221\346\240\274\346\225\260\357\274\210\345\203\217\347\264\240\357\274\211\357\274\232</p></body></html>", Q_NULLPTR));
        label_29->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\345\236\202\347\233\264\345\220\221\347\275\221\346\240\274\346\225\260\357\274\210\345\203\217\347\264\240\357\274\211\357\274\232</p></body></html>", Q_NULLPTR));
        label_31->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\350\267\235\347\246\273\345\220\221\347\275\221\346\240\274\346\225\260\357\274\210\345\203\217\347\264\240\357\274\211\357\274\232</p></body></html>", Q_NULLPTR));
        label_33->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\346\257\217\344\270\252batch\345\205\203\347\264\240\344\270\252\346\225\260\357\274\232</p></body></html>", Q_NULLPTR));
        label_35->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\350\267\235\347\246\273\345\220\221\350\265\267\345\247\213\344\275\215\347\275\256\357\274\210\347\261\263\357\274\211\357\274\232</p></body></html>", Q_NULLPTR));
        label_37->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\346\260\264\345\271\263\345\220\221\350\265\267\345\247\213\344\275\215\347\275\256\357\274\210\347\261\263\357\274\211\357\274\232</p></body></html>", Q_NULLPTR));
        label_39->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\345\236\202\347\233\264\345\220\221\350\265\267\345\247\213\344\275\215\347\275\256\357\274\210\347\261\263\357\274\211\357\274\232</p></body></html>", Q_NULLPTR));
        label_41->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\346\260\264\345\271\263\345\220\221\347\275\221\346\240\274\345\244\247\345\260\217\357\274\210\347\261\263\357\274\211\357\274\232</p></body></html>", Q_NULLPTR));
        label_42->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\345\236\202\347\233\264\345\220\221\347\275\221\346\240\274\345\244\247\345\260\217\357\274\210\347\261\263\357\274\211\357\274\232</p></body></html>", Q_NULLPTR));
        label_43->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\350\267\235\347\246\273\345\220\221\347\275\221\346\240\274\345\244\247\345\260\217\357\274\210\347\261\263\357\274\211\357\274\232</p></body></html>", Q_NULLPTR));
        label_44->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\346\210\220\345\203\217\350\265\267\345\247\213\351\242\221\347\216\207\357\274\210MHz\357\274\211\357\274\232</p></body></html>", Q_NULLPTR));
        label_45->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\346\210\220\345\203\217\347\273\210\346\255\242\351\242\221\347\216\207\357\274\210MHz\357\274\211\357\274\232</p></body></html>", Q_NULLPTR));
        groupBox_TestRecord->setTitle(QApplication::translate("ArgumentInfoDlg", "\345\256\236\351\252\214\350\257\264\346\230\216", Q_NULLPTR));
        groupBox_Servo->setTitle(QApplication::translate("ArgumentInfoDlg", "\344\274\272\346\234\215\347\263\273\347\273\237\351\205\215\347\275\256", Q_NULLPTR));
        label_2->setText(QApplication::translate("ArgumentInfoDlg", "mm/s", Q_NULLPTR));
        label_10->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\345\236\202\347\233\264\351\200\237\345\272\246\357\274\232</p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("ArgumentInfoDlg", "mm/s", Q_NULLPTR));
        label_12->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\350\265\267\347\202\271X\345\235\220\346\240\207\357\274\232</p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("ArgumentInfoDlg", "mm", Q_NULLPTR));
        label_14->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\350\265\267\347\202\271Y\345\235\220\346\240\207\357\274\232</p></body></html>", Q_NULLPTR));
        label_11->setText(QApplication::translate("ArgumentInfoDlg", "mm", Q_NULLPTR));
        label_16->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\347\273\210\347\202\271X\345\235\220\346\240\207\357\274\232</p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("ArgumentInfoDlg", "mm", Q_NULLPTR));
        label_18->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\347\273\210\347\202\271Y\345\235\220\346\240\207\357\274\232</p></body></html>", Q_NULLPTR));
        label_19->setText(QApplication::translate("ArgumentInfoDlg", "mm", Q_NULLPTR));
        label_20->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">Y\350\275\264\346\255\245\351\225\277\357\274\232</p></body></html>", Q_NULLPTR));
        label_21->setText(QApplication::translate("ArgumentInfoDlg", "mm", Q_NULLPTR));
        label_8->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\346\260\264\345\271\263\351\200\237\345\272\246\357\274\232</p></body></html>", Q_NULLPTR));
        groupBox->setTitle(QString());
        label_24->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p>\346\250\241\346\235\277\345\220\215\357\274\232 </p></body></html>", Q_NULLPTR));
        label_25->setText(QApplication::translate("ArgumentInfoDlg", "\346\240\207\350\257\206\345\217\267\357\274\232", Q_NULLPTR));
        groupBox_RF->setTitle(QApplication::translate("ArgumentInfoDlg", "\345\260\204\351\242\221\347\263\273\347\273\237\351\205\215\347\275\256", Q_NULLPTR));
        label_23->setText(QApplication::translate("ArgumentInfoDlg", "MHz", Q_NULLPTR));
        label_15->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\346\211\253\351\242\221\347\273\210\347\202\271\357\274\232</p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("ArgumentInfoDlg", "db", Q_NULLPTR));
        label_6->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\347\263\273\347\273\237\345\244\215\344\275\215\357\274\232</p></body></html>", Q_NULLPTR));
        label_9->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\346\240\241\346\255\243\346\250\241\345\274\217\357\274\232</p></body></html>", Q_NULLPTR));
        label_13->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\346\211\253\351\242\221\350\265\267\347\202\271\357\274\232</p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\350\207\252    \346\243\200\357\274\232</p></body></html>", Q_NULLPTR));
        label_17->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\345\217\221\345\260\204\345\212\237\347\216\207:</p></body></html>", Q_NULLPTR));
        label_22->setText(QApplication::translate("ArgumentInfoDlg", "MHz", Q_NULLPTR));
        comboBoxGather->clear();
        comboBoxGather->insertItems(0, QStringList()
         << QApplication::translate("ArgumentInfoDlg", "\346\232\227\347\256\261\351\207\207\351\233\206", Q_NULLPTR)
         << QApplication::translate("ArgumentInfoDlg", "\350\203\214\346\231\257\351\207\207\351\233\206", Q_NULLPTR)
         << QApplication::translate("ArgumentInfoDlg", "\347\233\256\346\240\207\351\207\207\351\233\206", Q_NULLPTR)
         << QApplication::translate("ArgumentInfoDlg", "\347\233\270\344\275\215\351\207\207\351\233\206", Q_NULLPTR)
         << QApplication::translate("ArgumentInfoDlg", "\345\214\205\347\273\234\351\207\207\351\233\206", Q_NULLPTR)
        );
        label_26->setText(QApplication::translate("ArgumentInfoDlg", "<html><head/><body><p align=\"right\">\351\207\207\351\233\206\346\250\241\345\274\217\357\274\232</p></body></html>", Q_NULLPTR));
        comboBoxSys_init->clear();
        comboBoxSys_init->insertItems(0, QStringList()
         << QApplication::translate("ArgumentInfoDlg", "\345\267\245\344\275\234\346\250\241\345\274\217", Q_NULLPTR)
         << QApplication::translate("ArgumentInfoDlg", "\350\207\252\346\243\200\346\250\241\345\274\217", Q_NULLPTR)
        );
        comboBoxReset->clear();
        comboBoxReset->insertItems(0, QStringList()
         << QApplication::translate("ArgumentInfoDlg", "\344\270\215\345\244\215\344\275\215", Q_NULLPTR)
         << QApplication::translate("ArgumentInfoDlg", "\345\244\215\344\275\215", Q_NULLPTR)
        );
        comboBoxCal->clear();
        comboBoxCal->insertItems(0, QStringList()
         << QApplication::translate("ArgumentInfoDlg", "\346\240\241\346\255\243", Q_NULLPTR)
         << QApplication::translate("ArgumentInfoDlg", "\346\255\243\345\270\270\345\267\245\344\275\234", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class ArgumentInfoDlg: public Ui_ArgumentInfoDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARGUMENTINFODLG_H
