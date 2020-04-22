/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "view/graphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConfig;
    QAction *actionArgument;
    QAction *actionUser;
    QAction *actionChoose;
    QAction *action3dPoint;
    QAction *actionRCS;
    QAction *actionAbout;
    QAction *actionPlayBack;
    QAction *actionPara;
    QAction *actionSysBC;
    QAction *actionBaoLuo;
    QAction *actionJingTai1D;
    QAction *actionJingTaiDuiXiao;
    QAction *action2Dduixiao;
    QAction *action3Dduixiao;
    QAction *actionRCSChengXiang;
    QAction *actionReport;
    QAction *action2D;
    QAction *action3D;
    QAction *actionReset;
    QAction *actionCombinedWordReport;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QFrame *framePicture;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayoutLeft;
    QGroupBox *groupBoxPose;
    QVBoxLayout *verticalLayout_8;
    GraphicsView *graphicsView;
    QGroupBox *groupBoxPulse;
    QVBoxLayout *verticalLayout_9;
    QGraphicsView *graphicsViewPulse;
    QFrame *frameControl;
    QGridLayout *gridLayout_11;
    QGroupBox *groupBoxDt;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonStartTest;
    QPushButton *pushButtonStopTest;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBoxRf;
    QGridLayout *gridLayout_8;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_29;
    QLabel *label_13;
    QLabel *label_30;
    QLineEdit *lineEditSweepFStart;
    QLineEdit *lineEditSweepFEnd;
    QLineEdit *lineEditAtten;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_6;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_10;
    QLabel *label_16;
    QLabel *label_Init_done;
    QLabel *label_18;
    QLabel *labelComm_Err;
    QLabel *label_17;
    QSpacerItem *verticalSpacer;
    QLabel *label_44;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout;
    QCheckBox *checkBoxGather;
    QComboBox *comboBoxGather;
    QLabel *label_2;
    QComboBox *comboBoxSys_init;
    QLabel *label_4;
    QLabel *label_31;
    QCheckBox *checkBoxRFSelfTest;
    QComboBox *comboBoxCal;
    QCheckBox *checkBoxRFReset;
    QLabel *label_3;
    QCheckBox *checkBoxRFAdjust;
    QComboBox *comboBoxReset;
    QSpacerItem *verticalSpacer_5;
    QGroupBox *groupBoxPara;
    QGridLayout *gridLayout_2;
    QLabel *label_43;
    QLineEdit *lineEdit_EndFrequenncy;
    QLineEdit *lineEdit_bpZNum;
    QLabel *label_35;
    QLineEdit *lineEdit_bpYNum;
    QLabel *label_34;
    QLabel *label_32;
    QLabel *label_33;
    QLineEdit *lineEdit_bpXNum;
    QLabel *label_39;
    QLineEdit *lineEdit_bpYStartLocation;
    QLabel *label_37;
    QLineEdit *lineEdit_bpZStartLocation;
    QLabel *label_38;
    QLineEdit *lineEdit_bpXStartLocation;
    QLabel *label_36;
    QLineEdit *lineEdit_batch;
    QLineEdit *lineEdit_StartFrequency;
    QLabel *label_41;
    QLabel *label_42;
    QLineEdit *lineEdit_bpYSize;
    QLineEdit *lineEdit_bpZSize;
    QLabel *label_40;
    QLineEdit *lineEdit_bpXSize;
    QGroupBox *groupBoxServ;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_9;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *lineEditSpeedH;
    QLabel *label_12;
    QLabel *label_23;
    QLabel *label_10;
    QLineEdit *lineEditSpeedV;
    QLineEdit *lineEditEndX;
    QLabel *label_8;
    QLabel *label_24;
    QLabel *label_28;
    QLineEdit *lineEditStartX;
    QLineEdit *lineEditStepY;
    QLabel *label_11;
    QLabel *label_27;
    QLineEdit *lineEditEndY;
    QLabel *label_7;
    QLabel *label_26;
    QLabel *label_25;
    QLineEdit *lineEditStartY;
    QLabel *label_9;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBoxState;
    QFormLayout *formLayout_2;
    QLabel *label_19;
    QLabel *labelReState;
    QLabel *label_20;
    QLabel *labelCurrentX;
    QLabel *label_21;
    QLabel *labelCurrentY;
    QLabel *label_22;
    QLabel *labelStime;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButtonServoContinue;
    QPushButton *pushButtonServoDisContinue;
    QPushButton *pushButtonServoReturnRun;
    QPushButton *pushButtonServoPauseRun;
    QPushButton *pushButtonServoUnPauseRun;
    QSpacerItem *horizontalSpacer_6;
    QGroupBox *groupBoxTestDesc;
    QGridLayout *gridLayout_7;
    QTextEdit *textEdit_TestRecord;
    QMenuBar *menuBar;
    QMenu *menu_E;
    QMenu *menu_V;
    QMenu *menu_H;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1400, 923);
        MainWindow->setMinimumSize(QSize(0, 0));
        actionConfig = new QAction(MainWindow);
        actionConfig->setObjectName(QStringLiteral("actionConfig"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/image/config.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfig->setIcon(icon);
        actionArgument = new QAction(MainWindow);
        actionArgument->setObjectName(QStringLiteral("actionArgument"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/res/image/parameters.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionArgument->setIcon(icon1);
        actionUser = new QAction(MainWindow);
        actionUser->setObjectName(QStringLiteral("actionUser"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/res/image/user_group.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUser->setIcon(icon2);
        actionChoose = new QAction(MainWindow);
        actionChoose->setObjectName(QStringLiteral("actionChoose"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/res/image/checked.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChoose->setIcon(icon3);
        action3dPoint = new QAction(MainWindow);
        action3dPoint->setObjectName(QStringLiteral("action3dPoint"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/res/image/3d.png"), QSize(), QIcon::Normal, QIcon::Off);
        action3dPoint->setIcon(icon4);
        actionRCS = new QAction(MainWindow);
        actionRCS->setObjectName(QStringLiteral("actionRCS"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/res/image/rcs.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRCS->setIcon(icon5);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/res/image/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon6);
        actionPlayBack = new QAction(MainWindow);
        actionPlayBack->setObjectName(QStringLiteral("actionPlayBack"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/res/image/reset.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlayBack->setIcon(icon7);
        actionPara = new QAction(MainWindow);
        actionPara->setObjectName(QStringLiteral("actionPara"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/res/image/para.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPara->setIcon(icon8);
        actionSysBC = new QAction(MainWindow);
        actionSysBC->setObjectName(QStringLiteral("actionSysBC"));
        actionBaoLuo = new QAction(MainWindow);
        actionBaoLuo->setObjectName(QStringLiteral("actionBaoLuo"));
        actionJingTai1D = new QAction(MainWindow);
        actionJingTai1D->setObjectName(QStringLiteral("actionJingTai1D"));
        actionJingTaiDuiXiao = new QAction(MainWindow);
        actionJingTaiDuiXiao->setObjectName(QStringLiteral("actionJingTaiDuiXiao"));
        action2Dduixiao = new QAction(MainWindow);
        action2Dduixiao->setObjectName(QStringLiteral("action2Dduixiao"));
        action3Dduixiao = new QAction(MainWindow);
        action3Dduixiao->setObjectName(QStringLiteral("action3Dduixiao"));
        actionRCSChengXiang = new QAction(MainWindow);
        actionRCSChengXiang->setObjectName(QStringLiteral("actionRCSChengXiang"));
        actionReport = new QAction(MainWindow);
        actionReport->setObjectName(QStringLiteral("actionReport"));
        action2D = new QAction(MainWindow);
        action2D->setObjectName(QStringLiteral("action2D"));
        action3D = new QAction(MainWindow);
        action3D->setObjectName(QStringLiteral("action3D"));
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QStringLiteral("actionReset"));
        actionCombinedWordReport = new QAction(MainWindow);
        actionCombinedWordReport->setObjectName(QStringLiteral("actionCombinedWordReport"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        framePicture = new QFrame(centralWidget);
        framePicture->setObjectName(QStringLiteral("framePicture"));
        framePicture->setFrameShape(QFrame::StyledPanel);
        framePicture->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(framePicture);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayoutLeft = new QVBoxLayout();
        verticalLayoutLeft->setSpacing(1);
        verticalLayoutLeft->setObjectName(QStringLiteral("verticalLayoutLeft"));
        groupBoxPose = new QGroupBox(framePicture);
        groupBoxPose->setObjectName(QStringLiteral("groupBoxPose"));
        groupBoxPose->setMinimumSize(QSize(600, 0));
        verticalLayout_8 = new QVBoxLayout(groupBoxPose);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        graphicsView = new GraphicsView(groupBoxPose);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        verticalLayout_8->addWidget(graphicsView);


        verticalLayoutLeft->addWidget(groupBoxPose);

        groupBoxPulse = new QGroupBox(framePicture);
        groupBoxPulse->setObjectName(QStringLiteral("groupBoxPulse"));
        groupBoxPulse->setMinimumSize(QSize(600, 0));
        verticalLayout_9 = new QVBoxLayout(groupBoxPulse);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        graphicsViewPulse = new QGraphicsView(groupBoxPulse);
        graphicsViewPulse->setObjectName(QStringLiteral("graphicsViewPulse"));

        verticalLayout_9->addWidget(graphicsViewPulse);


        verticalLayoutLeft->addWidget(groupBoxPulse);

        verticalLayoutLeft->setStretch(0, 1);
        verticalLayoutLeft->setStretch(1, 1);

        gridLayout_5->addLayout(verticalLayoutLeft, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(framePicture);

        frameControl = new QFrame(centralWidget);
        frameControl->setObjectName(QStringLiteral("frameControl"));
        frameControl->setFrameShape(QFrame::StyledPanel);
        frameControl->setFrameShadow(QFrame::Raised);
        gridLayout_11 = new QGridLayout(frameControl);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        groupBoxDt = new QGroupBox(frameControl);
        groupBoxDt->setObjectName(QStringLiteral("groupBoxDt"));
        groupBoxDt->setMinimumSize(QSize(0, 0));
        groupBoxDt->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_6 = new QGridLayout(groupBoxDt);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(40);
        horizontalSpacer = new QSpacerItem(210, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButtonStartTest = new QPushButton(groupBoxDt);
        pushButtonStartTest->setObjectName(QStringLiteral("pushButtonStartTest"));
        pushButtonStartTest->setMinimumSize(QSize(70, 70));
        pushButtonStartTest->setMaximumSize(QSize(70, 70));

        gridLayout_6->addWidget(pushButtonStartTest, 0, 1, 1, 1);

        pushButtonStopTest = new QPushButton(groupBoxDt);
        pushButtonStopTest->setObjectName(QStringLiteral("pushButtonStopTest"));
        pushButtonStopTest->setMinimumSize(QSize(70, 70));
        pushButtonStopTest->setMaximumSize(QSize(70, 70));

        gridLayout_6->addWidget(pushButtonStopTest, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(209, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_3, 0, 3, 1, 1);


        gridLayout_11->addWidget(groupBoxDt, 0, 0, 1, 2);

        groupBoxRf = new QGroupBox(frameControl);
        groupBoxRf->setObjectName(QStringLiteral("groupBoxRf"));
        groupBoxRf->setMinimumSize(QSize(0, 0));
        groupBoxRf->setMaximumSize(QSize(16777215, 16777215));
        groupBoxRf->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        gridLayout_8 = new QGridLayout(groupBoxRf);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(9, 15, 9, 9);
        groupBox_2 = new QGroupBox(groupBoxRf);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 0));
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        groupBox_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(20, 20));
        label->setMaximumSize(QSize(20, 20));

        gridLayout_3->addWidget(label, 2, 2, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(60, 0));
        label_6->setMaximumSize(QSize(60, 16777215));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_6, 2, 0, 1, 1);

        label_29 = new QLabel(groupBox_2);
        label_29->setObjectName(QStringLiteral("label_29"));
        sizePolicy.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy);
        label_29->setMinimumSize(QSize(20, 20));
        label_29->setMaximumSize(QSize(20, 20));

        gridLayout_3->addWidget(label_29, 1, 2, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(60, 0));
        label_13->setMaximumSize(QSize(60, 16777215));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_13, 1, 0, 1, 1);

        label_30 = new QLabel(groupBox_2);
        label_30->setObjectName(QStringLiteral("label_30"));
        sizePolicy.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy);
        label_30->setMinimumSize(QSize(20, 20));
        label_30->setMaximumSize(QSize(20, 20));

        gridLayout_3->addWidget(label_30, 0, 2, 1, 1);

        lineEditSweepFStart = new QLineEdit(groupBox_2);
        lineEditSweepFStart->setObjectName(QStringLiteral("lineEditSweepFStart"));
        lineEditSweepFStart->setMinimumSize(QSize(0, 0));
        lineEditSweepFStart->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(lineEditSweepFStart, 0, 1, 1, 1);

        lineEditSweepFEnd = new QLineEdit(groupBox_2);
        lineEditSweepFEnd->setObjectName(QStringLiteral("lineEditSweepFEnd"));
        lineEditSweepFEnd->setMinimumSize(QSize(0, 0));
        lineEditSweepFEnd->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(lineEditSweepFEnd, 1, 1, 1, 1);

        lineEditAtten = new QLineEdit(groupBox_2);
        lineEditAtten->setObjectName(QStringLiteral("lineEditAtten"));
        lineEditAtten->setMinimumSize(QSize(0, 0));
        lineEditAtten->setMaximumSize(QSize(16777215, 16777215));
        lineEditAtten->setFocusPolicy(Qt::WheelFocus);

        gridLayout_3->addWidget(lineEditAtten, 2, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(60, 0));
        label_5->setMaximumSize(QSize(60, 16777215));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_6, 3, 1, 1, 1);

        label_30->raise();
        lineEditSweepFEnd->raise();
        label_29->raise();
        lineEditAtten->raise();
        label->raise();
        label_13->raise();
        label_6->raise();
        label_5->raise();
        lineEditSweepFStart->raise();

        gridLayout_8->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_7 = new QGroupBox(groupBoxRf);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setMinimumSize(QSize(130, 0));
        groupBox_7->setMaximumSize(QSize(130, 16777215));
        gridLayout_10 = new QGridLayout(groupBox_7);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setVerticalSpacing(15);
        label_16 = new QLabel(groupBox_7);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_10->addWidget(label_16, 0, 0, 1, 1);

        label_Init_done = new QLabel(groupBox_7);
        label_Init_done->setObjectName(QStringLiteral("label_Init_done"));
        label_Init_done->setMinimumSize(QSize(70, 16));
        label_Init_done->setMaximumSize(QSize(70, 16));

        gridLayout_10->addWidget(label_Init_done, 0, 1, 1, 1);

        label_18 = new QLabel(groupBox_7);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_10->addWidget(label_18, 1, 0, 1, 1);

        labelComm_Err = new QLabel(groupBox_7);
        labelComm_Err->setObjectName(QStringLiteral("labelComm_Err"));
        labelComm_Err->setMinimumSize(QSize(70, 16));
        labelComm_Err->setMaximumSize(QSize(70, 16));
        labelComm_Err->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_10->addWidget(labelComm_Err, 1, 1, 1, 1);

        label_17 = new QLabel(groupBox_7);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_10->addWidget(label_17, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_10->addItem(verticalSpacer, 3, 0, 1, 1);

        label_44 = new QLabel(groupBox_7);
        label_44->setObjectName(QStringLiteral("label_44"));

        gridLayout_10->addWidget(label_44, 2, 1, 1, 1);


        gridLayout_8->addWidget(groupBox_7, 0, 1, 2, 1);

        groupBox_4 = new QGroupBox(groupBoxRf);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(0, 0));
        groupBox_4->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(groupBox_4);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        checkBoxGather = new QCheckBox(groupBox_4);
        checkBoxGather->setObjectName(QStringLiteral("checkBoxGather"));
        checkBoxGather->setMaximumSize(QSize(20, 16777215));

        gridLayout->addWidget(checkBoxGather, 0, 5, 1, 1);

        comboBoxGather = new QComboBox(groupBox_4);
        comboBoxGather->setObjectName(QStringLiteral("comboBoxGather"));
        comboBoxGather->setMinimumSize(QSize(87, 23));

        gridLayout->addWidget(comboBoxGather, 0, 2, 1, 3);

        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(60, 0));
        label_2->setMaximumSize(QSize(60, 16777215));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboBoxSys_init = new QComboBox(groupBox_4);
        comboBoxSys_init->setObjectName(QStringLiteral("comboBoxSys_init"));
        comboBoxSys_init->setMinimumSize(QSize(87, 23));
        comboBoxSys_init->setFocusPolicy(Qt::StrongFocus);

        gridLayout->addWidget(comboBoxSys_init, 1, 2, 1, 3);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(60, 0));
        label_4->setMaximumSize(QSize(60, 16777215));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_31 = new QLabel(groupBox_4);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setMinimumSize(QSize(60, 0));
        label_31->setMaximumSize(QSize(60, 16777215));
        label_31->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_31, 0, 0, 1, 1);

        checkBoxRFSelfTest = new QCheckBox(groupBox_4);
        checkBoxRFSelfTest->setObjectName(QStringLiteral("checkBoxRFSelfTest"));
        checkBoxRFSelfTest->setMaximumSize(QSize(20, 16777215));

        gridLayout->addWidget(checkBoxRFSelfTest, 1, 5, 1, 1);

        comboBoxCal = new QComboBox(groupBox_4);
        comboBoxCal->setObjectName(QStringLiteral("comboBoxCal"));
        comboBoxCal->setMinimumSize(QSize(87, 23));
        comboBoxCal->setFocusPolicy(Qt::StrongFocus);

        gridLayout->addWidget(comboBoxCal, 3, 2, 1, 3);

        checkBoxRFReset = new QCheckBox(groupBox_4);
        checkBoxRFReset->setObjectName(QStringLiteral("checkBoxRFReset"));
        checkBoxRFReset->setMaximumSize(QSize(20, 16777215));

        gridLayout->addWidget(checkBoxRFReset, 2, 5, 1, 1);

        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(60, 0));
        label_3->setMaximumSize(QSize(60, 16777215));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        checkBoxRFAdjust = new QCheckBox(groupBox_4);
        checkBoxRFAdjust->setObjectName(QStringLiteral("checkBoxRFAdjust"));
        checkBoxRFAdjust->setMaximumSize(QSize(20, 16777215));

        gridLayout->addWidget(checkBoxRFAdjust, 3, 5, 1, 1);

        comboBoxReset = new QComboBox(groupBox_4);
        comboBoxReset->setObjectName(QStringLiteral("comboBoxReset"));
        comboBoxReset->setMinimumSize(QSize(87, 23));
        comboBoxReset->setFocusPolicy(Qt::StrongFocus);

        gridLayout->addWidget(comboBoxReset, 2, 2, 1, 3);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 4, 2, 1, 1);


        gridLayout_8->addWidget(groupBox_4, 1, 0, 1, 1);


        gridLayout_11->addWidget(groupBoxRf, 1, 0, 1, 1);

        groupBoxPara = new QGroupBox(frameControl);
        groupBoxPara->setObjectName(QStringLiteral("groupBoxPara"));
        groupBoxPara->setMinimumSize(QSize(200, 0));
        groupBoxPara->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(groupBoxPara);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 15, -1, -1);
        label_43 = new QLabel(groupBoxPara);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setMinimumSize(QSize(140, 0));
        label_43->setMaximumSize(QSize(130, 16777215));
        label_43->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_43, 11, 0, 1, 1);

        lineEdit_EndFrequenncy = new QLineEdit(groupBoxPara);
        lineEdit_EndFrequenncy->setObjectName(QStringLiteral("lineEdit_EndFrequenncy"));

        gridLayout_2->addWidget(lineEdit_EndFrequenncy, 11, 1, 1, 1);

        lineEdit_bpZNum = new QLineEdit(groupBoxPara);
        lineEdit_bpZNum->setObjectName(QStringLiteral("lineEdit_bpZNum"));

        gridLayout_2->addWidget(lineEdit_bpZNum, 2, 1, 1, 1);

        label_35 = new QLabel(groupBoxPara);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setMinimumSize(QSize(140, 0));
        label_35->setMaximumSize(QSize(130, 16777215));
        label_35->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_35, 3, 0, 1, 1);

        lineEdit_bpYNum = new QLineEdit(groupBoxPara);
        lineEdit_bpYNum->setObjectName(QStringLiteral("lineEdit_bpYNum"));

        gridLayout_2->addWidget(lineEdit_bpYNum, 1, 1, 1, 1);

        label_34 = new QLabel(groupBoxPara);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setMinimumSize(QSize(140, 0));
        label_34->setMaximumSize(QSize(130, 16777215));
        label_34->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_34, 2, 0, 1, 1);

        label_32 = new QLabel(groupBoxPara);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setMinimumSize(QSize(140, 0));
        label_32->setMaximumSize(QSize(130, 16777215));
        label_32->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_32, 0, 0, 1, 1);

        label_33 = new QLabel(groupBoxPara);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setMinimumSize(QSize(140, 0));
        label_33->setMaximumSize(QSize(130, 16777215));
        label_33->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_33, 1, 0, 1, 1);

        lineEdit_bpXNum = new QLineEdit(groupBoxPara);
        lineEdit_bpXNum->setObjectName(QStringLiteral("lineEdit_bpXNum"));

        gridLayout_2->addWidget(lineEdit_bpXNum, 0, 1, 1, 1);

        label_39 = new QLabel(groupBoxPara);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setMinimumSize(QSize(140, 0));
        label_39->setMaximumSize(QSize(130, 16777215));
        label_39->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_39, 7, 0, 1, 1);

        lineEdit_bpYStartLocation = new QLineEdit(groupBoxPara);
        lineEdit_bpYStartLocation->setObjectName(QStringLiteral("lineEdit_bpYStartLocation"));

        gridLayout_2->addWidget(lineEdit_bpYStartLocation, 5, 1, 1, 1);

        label_37 = new QLabel(groupBoxPara);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setMinimumSize(QSize(140, 0));
        label_37->setMaximumSize(QSize(130, 16777215));
        label_37->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_37, 5, 0, 1, 1);

        lineEdit_bpZStartLocation = new QLineEdit(groupBoxPara);
        lineEdit_bpZStartLocation->setObjectName(QStringLiteral("lineEdit_bpZStartLocation"));

        gridLayout_2->addWidget(lineEdit_bpZStartLocation, 6, 1, 1, 1);

        label_38 = new QLabel(groupBoxPara);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setMinimumSize(QSize(140, 0));
        label_38->setMaximumSize(QSize(130, 16777215));
        label_38->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_38, 6, 0, 1, 1);

        lineEdit_bpXStartLocation = new QLineEdit(groupBoxPara);
        lineEdit_bpXStartLocation->setObjectName(QStringLiteral("lineEdit_bpXStartLocation"));

        gridLayout_2->addWidget(lineEdit_bpXStartLocation, 4, 1, 1, 1);

        label_36 = new QLabel(groupBoxPara);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setMinimumSize(QSize(140, 0));
        label_36->setMaximumSize(QSize(130, 16777215));
        label_36->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_36, 4, 0, 1, 1);

        lineEdit_batch = new QLineEdit(groupBoxPara);
        lineEdit_batch->setObjectName(QStringLiteral("lineEdit_batch"));

        gridLayout_2->addWidget(lineEdit_batch, 3, 1, 1, 1);

        lineEdit_StartFrequency = new QLineEdit(groupBoxPara);
        lineEdit_StartFrequency->setObjectName(QStringLiteral("lineEdit_StartFrequency"));

        gridLayout_2->addWidget(lineEdit_StartFrequency, 10, 1, 1, 1);

        label_41 = new QLabel(groupBoxPara);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setMinimumSize(QSize(140, 0));
        label_41->setMaximumSize(QSize(130, 16777215));
        label_41->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_41, 9, 0, 1, 1);

        label_42 = new QLabel(groupBoxPara);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setMinimumSize(QSize(140, 0));
        label_42->setMaximumSize(QSize(130, 16777215));
        label_42->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_42, 10, 0, 1, 1);

        lineEdit_bpYSize = new QLineEdit(groupBoxPara);
        lineEdit_bpYSize->setObjectName(QStringLiteral("lineEdit_bpYSize"));

        gridLayout_2->addWidget(lineEdit_bpYSize, 8, 1, 1, 1);

        lineEdit_bpZSize = new QLineEdit(groupBoxPara);
        lineEdit_bpZSize->setObjectName(QStringLiteral("lineEdit_bpZSize"));

        gridLayout_2->addWidget(lineEdit_bpZSize, 9, 1, 1, 1);

        label_40 = new QLabel(groupBoxPara);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setMinimumSize(QSize(140, 0));
        label_40->setMaximumSize(QSize(130, 16777215));
        label_40->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_40, 8, 0, 1, 1);

        lineEdit_bpXSize = new QLineEdit(groupBoxPara);
        lineEdit_bpXSize->setObjectName(QStringLiteral("lineEdit_bpXSize"));

        gridLayout_2->addWidget(lineEdit_bpXSize, 7, 1, 1, 1);


        gridLayout_11->addWidget(groupBoxPara, 1, 1, 1, 1);

        groupBoxServ = new QGroupBox(frameControl);
        groupBoxServ->setObjectName(QStringLiteral("groupBoxServ"));
        groupBoxServ->setMinimumSize(QSize(0, 0));
        groupBoxServ->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_4 = new QGridLayout(groupBoxServ);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(9, 15, 9, 9);
        groupBox = new QGroupBox(groupBoxServ);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 0));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_9 = new QGridLayout(groupBox);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(60, 0));
        label_14->setMaximumSize(QSize(60, 16777215));
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(label_14, 1, 0, 1, 1);

        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);
        label_15->setMinimumSize(QSize(20, 20));
        label_15->setMaximumSize(QSize(30, 20));

        gridLayout_9->addWidget(label_15, 0, 2, 1, 1);

        lineEditSpeedH = new QLineEdit(groupBox);
        lineEditSpeedH->setObjectName(QStringLiteral("lineEditSpeedH"));
        lineEditSpeedH->setMinimumSize(QSize(0, 0));
        lineEditSpeedH->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_9->addWidget(lineEditSpeedH, 0, 1, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(60, 0));
        label_12->setMaximumSize(QSize(60, 16777215));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(label_12, 0, 0, 1, 1);

        label_23 = new QLabel(groupBox);
        label_23->setObjectName(QStringLiteral("label_23"));
        sizePolicy.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy);
        label_23->setMinimumSize(QSize(20, 20));
        label_23->setMaximumSize(QSize(30, 20));

        gridLayout_9->addWidget(label_23, 1, 2, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(60, 0));
        label_10->setMaximumSize(QSize(60, 16777215));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(label_10, 2, 0, 1, 1);

        lineEditSpeedV = new QLineEdit(groupBox);
        lineEditSpeedV->setObjectName(QStringLiteral("lineEditSpeedV"));
        lineEditSpeedV->setMinimumSize(QSize(0, 0));
        lineEditSpeedV->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_9->addWidget(lineEditSpeedV, 1, 1, 1, 1);

        lineEditEndX = new QLineEdit(groupBox);
        lineEditEndX->setObjectName(QStringLiteral("lineEditEndX"));
        lineEditEndX->setMinimumSize(QSize(0, 0));
        lineEditEndX->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_9->addWidget(lineEditEndX, 4, 1, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(60, 0));
        label_8->setMaximumSize(QSize(60, 16777215));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(label_8, 4, 0, 1, 1);

        label_24 = new QLabel(groupBox);
        label_24->setObjectName(QStringLiteral("label_24"));
        sizePolicy.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy);
        label_24->setMinimumSize(QSize(20, 20));
        label_24->setMaximumSize(QSize(30, 20));

        gridLayout_9->addWidget(label_24, 2, 2, 1, 1);

        label_28 = new QLabel(groupBox);
        label_28->setObjectName(QStringLiteral("label_28"));
        sizePolicy.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy);
        label_28->setMinimumSize(QSize(20, 20));
        label_28->setMaximumSize(QSize(30, 20));

        gridLayout_9->addWidget(label_28, 6, 2, 1, 1);

        lineEditStartX = new QLineEdit(groupBox);
        lineEditStartX->setObjectName(QStringLiteral("lineEditStartX"));
        lineEditStartX->setMinimumSize(QSize(0, 0));
        lineEditStartX->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_9->addWidget(lineEditStartX, 2, 1, 1, 1);

        lineEditStepY = new QLineEdit(groupBox);
        lineEditStepY->setObjectName(QStringLiteral("lineEditStepY"));
        lineEditStepY->setMinimumSize(QSize(0, 0));
        lineEditStepY->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_9->addWidget(lineEditStepY, 6, 1, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(60, 0));
        label_11->setMaximumSize(QSize(60, 16777215));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(label_11, 6, 0, 1, 1);

        label_27 = new QLabel(groupBox);
        label_27->setObjectName(QStringLiteral("label_27"));
        sizePolicy.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy);
        label_27->setMinimumSize(QSize(20, 20));
        label_27->setMaximumSize(QSize(30, 20));

        gridLayout_9->addWidget(label_27, 5, 2, 1, 1);

        lineEditEndY = new QLineEdit(groupBox);
        lineEditEndY->setObjectName(QStringLiteral("lineEditEndY"));
        lineEditEndY->setMinimumSize(QSize(0, 0));
        lineEditEndY->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_9->addWidget(lineEditEndY, 5, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(60, 0));
        label_7->setMaximumSize(QSize(60, 16777215));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(label_7, 5, 0, 1, 1);

        label_26 = new QLabel(groupBox);
        label_26->setObjectName(QStringLiteral("label_26"));
        sizePolicy.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy);
        label_26->setMinimumSize(QSize(20, 20));
        label_26->setMaximumSize(QSize(30, 20));

        gridLayout_9->addWidget(label_26, 4, 2, 1, 1);

        label_25 = new QLabel(groupBox);
        label_25->setObjectName(QStringLiteral("label_25"));
        sizePolicy.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy);
        label_25->setMinimumSize(QSize(20, 20));
        label_25->setMaximumSize(QSize(30, 20));

        gridLayout_9->addWidget(label_25, 3, 2, 1, 1);

        lineEditStartY = new QLineEdit(groupBox);
        lineEditStartY->setObjectName(QStringLiteral("lineEditStartY"));
        lineEditStartY->setMinimumSize(QSize(0, 0));
        lineEditStartY->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_9->addWidget(lineEditStartY, 3, 1, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(60, 0));
        label_9->setMaximumSize(QSize(60, 16777215));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(label_9, 3, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer_4, 7, 1, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        groupBoxState = new QGroupBox(groupBoxServ);
        groupBoxState->setObjectName(QStringLiteral("groupBoxState"));
        groupBoxState->setMinimumSize(QSize(130, 0));
        groupBoxState->setMaximumSize(QSize(130, 16777215));
        formLayout_2 = new QFormLayout(groupBoxState);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_2->setVerticalSpacing(15);
        label_19 = new QLabel(groupBoxState);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMinimumSize(QSize(60, 0));
        label_19->setMaximumSize(QSize(60, 16777215));
        label_19->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_19);

        labelReState = new QLabel(groupBoxState);
        labelReState->setObjectName(QStringLiteral("labelReState"));
        labelReState->setMinimumSize(QSize(35, 0));
        labelReState->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, labelReState);

        label_20 = new QLabel(groupBoxState);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setMinimumSize(QSize(60, 0));
        label_20->setMaximumSize(QSize(60, 16777215));
        label_20->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_20);

        labelCurrentX = new QLabel(groupBoxState);
        labelCurrentX->setObjectName(QStringLiteral("labelCurrentX"));
        labelCurrentX->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, labelCurrentX);

        label_21 = new QLabel(groupBoxState);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setMinimumSize(QSize(60, 0));
        label_21->setMaximumSize(QSize(60, 16777215));
        label_21->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_21);

        labelCurrentY = new QLabel(groupBoxState);
        labelCurrentY->setObjectName(QStringLiteral("labelCurrentY"));
        labelCurrentY->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, labelCurrentY);

        label_22 = new QLabel(groupBoxState);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setMinimumSize(QSize(60, 0));
        label_22->setMaximumSize(QSize(60, 16777215));
        label_22->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_22);

        labelStime = new QLabel(groupBoxState);
        labelStime->setObjectName(QStringLiteral("labelStime"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, labelStime);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(4, QFormLayout::FieldRole, verticalSpacer_2);


        gridLayout_4->addWidget(groupBoxState, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(groupBoxServ);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(0, 0));
        groupBox_3->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        pushButtonServoContinue = new QPushButton(groupBox_3);
        pushButtonServoContinue->setObjectName(QStringLiteral("pushButtonServoContinue"));
        sizePolicy.setHeightForWidth(pushButtonServoContinue->sizePolicy().hasHeightForWidth());
        pushButtonServoContinue->setSizePolicy(sizePolicy);
        pushButtonServoContinue->setMinimumSize(QSize(60, 60));
        pushButtonServoContinue->setMaximumSize(QSize(60, 60));

        horizontalLayout->addWidget(pushButtonServoContinue);

        pushButtonServoDisContinue = new QPushButton(groupBox_3);
        pushButtonServoDisContinue->setObjectName(QStringLiteral("pushButtonServoDisContinue"));
        sizePolicy.setHeightForWidth(pushButtonServoDisContinue->sizePolicy().hasHeightForWidth());
        pushButtonServoDisContinue->setSizePolicy(sizePolicy);
        pushButtonServoDisContinue->setMinimumSize(QSize(60, 60));
        pushButtonServoDisContinue->setMaximumSize(QSize(60, 60));

        horizontalLayout->addWidget(pushButtonServoDisContinue);

        pushButtonServoReturnRun = new QPushButton(groupBox_3);
        pushButtonServoReturnRun->setObjectName(QStringLiteral("pushButtonServoReturnRun"));
        sizePolicy.setHeightForWidth(pushButtonServoReturnRun->sizePolicy().hasHeightForWidth());
        pushButtonServoReturnRun->setSizePolicy(sizePolicy);
        pushButtonServoReturnRun->setMinimumSize(QSize(60, 60));
        pushButtonServoReturnRun->setMaximumSize(QSize(60, 60));

        horizontalLayout->addWidget(pushButtonServoReturnRun);

        pushButtonServoPauseRun = new QPushButton(groupBox_3);
        pushButtonServoPauseRun->setObjectName(QStringLiteral("pushButtonServoPauseRun"));
        pushButtonServoPauseRun->setMinimumSize(QSize(60, 60));
        pushButtonServoPauseRun->setMaximumSize(QSize(60, 60));

        horizontalLayout->addWidget(pushButtonServoPauseRun);

        pushButtonServoUnPauseRun = new QPushButton(groupBox_3);
        pushButtonServoUnPauseRun->setObjectName(QStringLiteral("pushButtonServoUnPauseRun"));
        pushButtonServoUnPauseRun->setMinimumSize(QSize(60, 60));
        pushButtonServoUnPauseRun->setMaximumSize(QSize(60, 60));

        horizontalLayout->addWidget(pushButtonServoUnPauseRun);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_4->addWidget(groupBox_3, 1, 0, 1, 2);


        gridLayout_11->addWidget(groupBoxServ, 2, 0, 1, 1);

        groupBoxTestDesc = new QGroupBox(frameControl);
        groupBoxTestDesc->setObjectName(QStringLiteral("groupBoxTestDesc"));
        gridLayout_7 = new QGridLayout(groupBoxTestDesc);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 12, 0, 0);
        textEdit_TestRecord = new QTextEdit(groupBoxTestDesc);
        textEdit_TestRecord->setObjectName(QStringLiteral("textEdit_TestRecord"));

        gridLayout_7->addWidget(textEdit_TestRecord, 0, 0, 1, 1);


        gridLayout_11->addWidget(groupBoxTestDesc, 2, 1, 1, 1);


        horizontalLayout_2->addWidget(frameControl);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1400, 21));
        menu_E = new QMenu(menuBar);
        menu_E->setObjectName(QStringLiteral("menu_E"));
        menu_V = new QMenu(menuBar);
        menu_V->setObjectName(QStringLiteral("menu_V"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(pushButtonStartTest, pushButtonStopTest);
        QWidget::setTabOrder(pushButtonStopTest, lineEditSweepFStart);
        QWidget::setTabOrder(lineEditSweepFStart, lineEditSweepFEnd);
        QWidget::setTabOrder(lineEditSweepFEnd, comboBoxSys_init);
        QWidget::setTabOrder(comboBoxSys_init, comboBoxReset);
        QWidget::setTabOrder(comboBoxReset, comboBoxCal);
        QWidget::setTabOrder(comboBoxCal, lineEditSpeedH);
        QWidget::setTabOrder(lineEditSpeedH, lineEditSpeedV);
        QWidget::setTabOrder(lineEditSpeedV, lineEditStartX);
        QWidget::setTabOrder(lineEditStartX, lineEditStartY);
        QWidget::setTabOrder(lineEditStartY, lineEditEndX);
        QWidget::setTabOrder(lineEditEndX, lineEditEndY);
        QWidget::setTabOrder(lineEditEndY, lineEditStepY);
        QWidget::setTabOrder(lineEditStepY, pushButtonServoContinue);
        QWidget::setTabOrder(pushButtonServoContinue, pushButtonServoDisContinue);
        QWidget::setTabOrder(pushButtonServoDisContinue, pushButtonServoReturnRun);
        QWidget::setTabOrder(pushButtonServoReturnRun, graphicsViewPulse);

        menuBar->addAction(menu_E->menuAction());
        menuBar->addAction(menu_V->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu_E->addAction(actionUser);
        menu_E->addAction(actionConfig);
        menu_E->addAction(actionArgument);
        menu_E->addSeparator();
        menu_E->addAction(actionChoose);
        menu_E->addAction(actionPara);
        menu_V->addAction(action3dPoint);
        menu_V->addAction(actionRCS);
        menu_V->addSeparator();
        menu_V->addAction(actionPlayBack);
        menu_H->addAction(actionAbout);
        mainToolBar->addAction(actionChoose);
        mainToolBar->addAction(actionPara);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action3dPoint);
        mainToolBar->addAction(actionRCS);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionPlayBack);
        mainToolBar->addAction(actionAbout);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSysBC);
        mainToolBar->addAction(actionBaoLuo);
        mainToolBar->addAction(actionJingTai1D);
        mainToolBar->addAction(actionJingTaiDuiXiao);
        mainToolBar->addAction(action2D);
        mainToolBar->addAction(action2Dduixiao);
        mainToolBar->addAction(action3D);
        mainToolBar->addAction(action3Dduixiao);
        mainToolBar->addAction(actionRCSChengXiang);
        mainToolBar->addAction(actionReport);
        mainToolBar->addAction(actionCombinedWordReport);
        mainToolBar->addAction(actionReset);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\347\224\265\345\255\220\346\265\213\351\207\217\347\263\273\347\273\237", Q_NULLPTR));
        actionConfig->setText(QApplication::translate("MainWindow", "\351\205\215\347\275\256\347\256\241\347\220\206", Q_NULLPTR));
        actionArgument->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\347\256\241\347\220\206", Q_NULLPTR));
        actionUser->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\347\256\241\347\220\206", Q_NULLPTR));
        actionChoose->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\345\256\236\351\252\214", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionChoose->setToolTip(QApplication::translate("MainWindow", "\351\200\211\346\213\251\345\256\236\351\252\214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action3dPoint->setText(QApplication::translate("MainWindow", "\344\270\211\347\273\264\347\202\271\344\272\221\345\233\276", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action3dPoint->setToolTip(QApplication::translate("MainWindow", "\344\270\211\347\273\264\347\202\271\344\272\221\345\233\276", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionRCS->setText(QApplication::translate("MainWindow", "RCS\345\233\276", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
        actionPlayBack->setText(QApplication::translate("MainWindow", "\345\233\236\346\224\276", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionPlayBack->setToolTip(QApplication::translate("MainWindow", "\345\233\236\346\224\276", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionPara->setText(QApplication::translate("MainWindow", "\346\210\220\345\203\217\345\217\202\346\225\260", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionPara->setToolTip(QApplication::translate("MainWindow", "\346\210\220\345\203\217\345\217\202\346\225\260", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionSysBC->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\350\241\245\345\201\277", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSysBC->setToolTip(QApplication::translate("MainWindow", "\347\263\273\347\273\237\350\241\245\345\201\277", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionBaoLuo->setText(QApplication::translate("MainWindow", "\345\214\205\347\273\234\350\241\245\345\201\277", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionBaoLuo->setToolTip(QApplication::translate("MainWindow", "\345\214\205\347\273\234\350\241\245\345\201\277", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionJingTai1D->setText(QApplication::translate("MainWindow", "\351\235\231\346\200\2011D\346\210\220\345\203\217", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionJingTai1D->setToolTip(QApplication::translate("MainWindow", "\351\235\231\346\200\2011D\346\210\220\345\203\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionJingTaiDuiXiao->setText(QApplication::translate("MainWindow", "\351\235\231\346\200\201\345\257\271\346\266\210", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionJingTaiDuiXiao->setToolTip(QApplication::translate("MainWindow", "\351\235\231\346\200\201\345\257\271\346\266\210", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action2Dduixiao->setText(QApplication::translate("MainWindow", "\344\272\214\347\273\264\345\257\271\346\266\210 ", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action2Dduixiao->setToolTip(QApplication::translate("MainWindow", "\345\212\250\346\200\2012/3D\346\210\220\345\203\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action3Dduixiao->setText(QApplication::translate("MainWindow", "\344\270\211\347\273\264\345\257\271\346\266\210", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action3Dduixiao->setToolTip(QApplication::translate("MainWindow", "\345\257\271\346\266\210\346\210\220\345\203\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionRCSChengXiang->setText(QApplication::translate("MainWindow", "RCS\345\217\215\346\274\224", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionRCSChengXiang->setToolTip(QApplication::translate("MainWindow", "RCS\345\217\215\346\274\224", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionReport->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220\345\256\236\351\252\214\346\212\245\345\221\212", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionReport->setToolTip(QApplication::translate("MainWindow", "\347\224\237\346\210\220\345\256\236\351\252\214\346\212\245\345\221\212", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action2D->setText(QApplication::translate("MainWindow", "\344\272\214\347\273\264\346\210\220\345\203\217", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action2D->setToolTip(QApplication::translate("MainWindow", "\344\272\214\347\273\264\346\210\220\345\203\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action3D->setText(QApplication::translate("MainWindow", "\344\270\211\347\273\264\346\210\220\345\203\217", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action3D->setToolTip(QApplication::translate("MainWindow", "\344\270\211\347\273\264\346\210\220\345\203\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionReset->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256\344\274\240\350\276\223\351\200\232\351\201\223", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionReset->setToolTip(QApplication::translate("MainWindow", "\351\207\215\347\275\256\344\274\240\350\276\223\351\200\232\351\201\223", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionCombinedWordReport->setText(QApplication::translate("MainWindow", "\345\220\210\345\271\266\345\256\236\351\252\214\346\212\245\345\221\212", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionCombinedWordReport->setToolTip(QApplication::translate("MainWindow", "\346\213\274\346\216\245\345\256\236\351\252\214\346\212\245\345\221\212", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBoxPose->setTitle(QString());
        groupBoxPulse->setTitle(QString());
        groupBoxDt->setTitle(QApplication::translate("MainWindow", "\346\200\273\346\216\247\345\210\266", Q_NULLPTR));
        pushButtonStartTest->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\350\257\225\351\252\214", Q_NULLPTR));
        pushButtonStopTest->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\345\256\236\351\252\214", Q_NULLPTR));
        groupBoxRf->setTitle(QApplication::translate("MainWindow", "\345\260\204\351\242\221\345\217\202\346\225\260", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\237\272\346\234\254\345\217\202\346\225\260", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "dB", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\345\217\221\345\260\204\350\241\260\345\207\217\357\274\232", Q_NULLPTR));
        label_29->setText(QApplication::translate("MainWindow", "MHz", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "\346\211\253\351\242\221\347\273\210\346\255\242\357\274\232", Q_NULLPTR));
        label_30->setText(QApplication::translate("MainWindow", "MHz", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\346\211\253\351\242\221\350\265\267\345\247\213\357\274\232", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "\345\256\236\346\227\266\347\212\266\346\200\201\346\230\276\347\244\272", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "\350\207\252\346\243\200\347\212\266\346\200\201:", Q_NULLPTR));
        label_Init_done->setText(QString());
        label_18->setText(QApplication::translate("MainWindow", "\351\200\232\350\256\257\347\212\266\346\200\201:", Q_NULLPTR));
        labelComm_Err->setText(QString());
        label_17->setText(QApplication::translate("MainWindow", "\346\225\205\351\232\234\347\212\266\346\200\201:", Q_NULLPTR));
        label_44->setText(QString());
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\345\205\266\344\273\226", Q_NULLPTR));
        checkBoxGather->setText(QString());
        comboBoxGather->clear();
        comboBoxGather->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\232\227\347\256\261\351\207\207\351\233\206", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\350\203\214\346\231\257\351\207\207\351\233\206", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\233\256\346\240\207\351\207\207\351\233\206", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\233\270\344\275\215\351\207\207\351\233\206", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\214\205\347\273\234\351\207\207\351\233\206", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("MainWindow", "\350\207\252\346\243\200\357\274\232", Q_NULLPTR));
        comboBoxSys_init->clear();
        comboBoxSys_init->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\267\245\344\275\234\346\250\241\345\274\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\350\207\252\346\243\200\346\250\241\345\274\217", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\345\244\215\344\275\215\357\274\232", Q_NULLPTR));
        label_31->setText(QApplication::translate("MainWindow", "\351\207\207\351\233\206\346\250\241\345\274\217\357\274\232", Q_NULLPTR));
        checkBoxRFSelfTest->setText(QString());
        comboBoxCal->clear();
        comboBoxCal->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\240\241\346\255\243", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\255\243\345\270\270\345\267\245\344\275\234", Q_NULLPTR)
        );
        checkBoxRFReset->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "\346\240\241\346\255\243\346\250\241\345\274\217\357\274\232", Q_NULLPTR));
        checkBoxRFAdjust->setText(QString());
        comboBoxReset->clear();
        comboBoxReset->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\344\270\215\345\244\215\344\275\215", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\244\215\344\275\215", Q_NULLPTR)
        );
        groupBoxPara->setTitle(QApplication::translate("MainWindow", "\346\210\220\345\203\217\345\217\202\346\225\260", Q_NULLPTR));
        label_43->setText(QApplication::translate("MainWindow", "\346\210\220\345\203\217\347\273\210\346\255\242\351\242\221\347\216\207\357\274\210MHz\357\274\211\357\274\232", Q_NULLPTR));
        label_35->setText(QApplication::translate("MainWindow", "\346\257\217\344\270\252batch\345\205\203\347\264\240\344\270\252\346\225\260\357\274\232", Q_NULLPTR));
        label_34->setText(QApplication::translate("MainWindow", "\350\267\235\347\246\273\345\220\221\347\275\221\346\240\274\346\225\260\357\274\210\345\203\217\347\264\240\357\274\211\357\274\232", Q_NULLPTR));
        label_32->setText(QApplication::translate("MainWindow", "\346\260\264\345\271\263\345\220\221\347\275\221\346\240\274\346\225\260\357\274\210\345\203\217\347\264\240\357\274\211\357\274\232", Q_NULLPTR));
        label_33->setText(QApplication::translate("MainWindow", "\345\236\202\347\233\264\345\220\221\347\275\221\346\240\274\346\225\260\357\274\210\345\203\217\347\264\240\357\274\211\357\274\232", Q_NULLPTR));
        label_39->setText(QApplication::translate("MainWindow", "\346\260\264\345\271\263\345\220\221\347\275\221\346\240\274\345\244\247\345\260\217\357\274\210\347\261\263\357\274\211\357\274\232", Q_NULLPTR));
        label_37->setText(QApplication::translate("MainWindow", "\346\260\264\345\271\263\345\220\221\350\265\267\345\247\213\344\275\215\347\275\256\357\274\210\347\261\263\357\274\211\357\274\232", Q_NULLPTR));
        label_38->setText(QApplication::translate("MainWindow", "\345\236\202\347\233\264\345\220\221\350\265\267\345\247\213\344\275\215\347\275\256\357\274\210\347\261\263\357\274\211\357\274\232", Q_NULLPTR));
        label_36->setText(QApplication::translate("MainWindow", "\350\267\235\347\246\273\345\220\221\350\265\267\345\247\213\344\275\215\347\275\256\357\274\210\347\261\263\357\274\211\357\274\232", Q_NULLPTR));
        label_41->setText(QApplication::translate("MainWindow", "\350\267\235\347\246\273\345\220\221\347\275\221\346\240\274\345\244\247\345\260\217\357\274\210\347\261\263\357\274\211\357\274\232", Q_NULLPTR));
        label_42->setText(QApplication::translate("MainWindow", "\346\210\220\345\203\217\350\265\267\345\247\213\351\242\221\347\216\207\357\274\210MHz\357\274\211\357\274\232", Q_NULLPTR));
        label_40->setText(QApplication::translate("MainWindow", "\345\236\202\347\233\264\345\220\221\347\275\221\346\240\274\345\244\247\345\260\217\357\274\210\347\261\263\357\274\211\357\274\232", Q_NULLPTR));
        groupBoxServ->setTitle(QApplication::translate("MainWindow", "\344\274\272\346\234\215", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\345\237\272\346\234\254\345\217\202\346\225\260", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "\345\236\202\347\233\264\351\200\237\345\272\246\357\274\232", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "mm/s", Q_NULLPTR));
        lineEditSpeedH->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "\346\260\264\345\271\263\351\200\237\345\272\246\357\274\232", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "mm/s", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\346\260\264\345\271\263\350\265\267\345\247\213\357\274\232", Q_NULLPTR));
        lineEditSpeedV->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "\346\260\264\345\271\263\347\273\210\346\255\242\357\274\232", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "mm", Q_NULLPTR));
        label_28->setText(QApplication::translate("MainWindow", "mm", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "\345\236\202\347\233\264\346\255\245\351\225\277\357\274\232", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWindow", "mm", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\345\236\202\347\233\264\347\273\210\346\255\242\357\274\232", Q_NULLPTR));
        label_26->setText(QApplication::translate("MainWindow", "mm", Q_NULLPTR));
        label_25->setText(QApplication::translate("MainWindow", "mm", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\345\236\202\347\233\264\350\265\267\345\247\213\357\274\232", Q_NULLPTR));
        groupBoxState->setTitle(QApplication::translate("MainWindow", "\345\256\236\346\227\266\347\212\266\346\200\201", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "\345\233\236\344\274\240\347\212\266\346\200\201:", Q_NULLPTR));
        labelReState->setText(QString());
        label_20->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215X\345\235\220\346\240\207:", Q_NULLPTR));
        labelCurrentX->setText(QString());
        label_21->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215Y\345\235\220\346\240\207:", Q_NULLPTR));
        labelCurrentY->setText(QString());
        label_22->setText(QApplication::translate("MainWindow", "\350\277\220\345\212\250\346\227\266\351\227\264:", Q_NULLPTR));
        labelStime->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\346\216\247\345\210\266\346\235\277", Q_NULLPTR));
        pushButtonServoContinue->setText(QApplication::translate("MainWindow", "\350\277\236\347\273\255", Q_NULLPTR));
        pushButtonServoDisContinue->setText(QApplication::translate("MainWindow", "\351\227\264\346\226\255", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButtonServoReturnRun->setToolTip(QApplication::translate("MainWindow", "\345\244\215\344\275\215", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonServoReturnRun->setText(QApplication::translate("MainWindow", "\345\233\236\350\265\267\347\202\271", Q_NULLPTR));
        pushButtonServoPauseRun->setText(QApplication::translate("MainWindow", "\346\232\202\345\201\234", Q_NULLPTR));
        pushButtonServoUnPauseRun->setText(QApplication::translate("MainWindow", "\350\247\243\351\231\244\346\232\202\345\201\234", Q_NULLPTR));
        groupBoxTestDesc->setTitle(QApplication::translate("MainWindow", "\345\256\236\351\252\214\350\257\264\346\230\216", Q_NULLPTR));
        menu_E->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", Q_NULLPTR));
        menu_V->setTitle(QApplication::translate("MainWindow", "\346\237\245\347\234\213(&V)", Q_NULLPTR));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
