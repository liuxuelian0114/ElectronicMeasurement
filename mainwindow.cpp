#include <QDebug>
#include <QByteArray>
#include <QStyleFactory>
#include <QDateTime>
#include <QMessageBox>
#include <QRectF>
#include <QIntValidator>
#include <QProcess>
#include <QFtp>
#include <QPalette>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "statusbar.h"
#include "usermanagerdlg.h"
#include "configmanagerdlg.h"
#include "argumentmanagerdlg.h"
#include "choosetestdlg.h"
#include "showrcsdlg.h"
#include "model/glwidget.h"
#include "model/ScatterWidget.h"
#include "dbinterface.h"
#include "runtimeconfig.h"
#include "playbackdlg.h"
#include "pulse/PulseScene.h"
#include "localconfig.h"
#include "ParaAgument.h"
#include "dbinterface.h"
#include "aboutdlg.h"


//#define OPENGL_VIEW

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->selfCheckStatus();//提示实验人员自检

    qApp->setStyle(QStyleFactory::create("fusion"));
    this->setWindowTitle(QString(QStringLiteral("电子测量软件-[%1  %2]"))
                         .arg(g_runTimeConfig.getUserName())
                         .arg(g_runTimeConfig.getPermission()));
    m_pStatusBar = new StatusBar(this);
    this->setStatusBar(m_pStatusBar);
    //初始化FTP

#if OPENGL_VIEW
    m_pGLWidget = new GLWidget();
    m_pGLWidget->resize(800, 600);
    m_pGLWidget->setWindowTitle(QStringLiteral("三维点云图"));
    m_pGLWidget->hide();
#else
    m_pScatterWidget = new ScatterWidget(this);
    connect(m_pScatterWidget, SIGNAL(done()), m_pScatterWidget, SLOT(show()));
    m_pScatterWidget->resize(800, 600);
    m_pScatterWidget->setWindowTitle(QStringLiteral("三维点云图"));
    m_pScatterWidget->hide();
#endif
    m_pPulseScene = new PulseScene;
    ui->graphicsViewPulse->setScene(m_pPulseScene);
    ui->graphicsViewPulse->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsViewPulse->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->pushButtonStopTest->setEnabled(false);

    initInterface();
    loadStyle();

    if(QStringLiteral("普通用户") == g_runTimeConfig.getPermission())
    {
        ui->actionUser->setEnabled(false);
    }
    ui->action3dPoint->setEnabled(false);
    ui->actionRCS->setEnabled(false);

    connect(ui->actionUser, SIGNAL(triggered()), this, SLOT(onActionUserTriggered()));
    connect(ui->actionConfig, SIGNAL(triggered()), this, SLOT(onActionConfigTriggered()));
    connect(ui->actionArgument, SIGNAL(triggered()), this, SLOT(onActionArgumentTriggered()));
    connect(ui->actionChoose, SIGNAL(triggered()), this, SLOT(onActionChooseTriggered()));
    connect(ui->action3dPoint, SIGNAL(triggered()), this, SLOT(onAction3dPointTriggered()));
    connect(ui->actionRCS, SIGNAL(triggered()), this, SLOT(onRcsDataUpdated()));
    connect(ui->actionPlayBack, SIGNAL(triggered()), this, SLOT(onActionPlayBackTriggered()));
    connect(ui->actionPara, SIGNAL(triggered()),this,SLOT(onActionParaTriggered()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(onActionAboutTriggered()));

    connect(ui->action2Dduixiao, SIGNAL(triggered()),this,SLOT(runBat()));
    connect(ui->actionSysBC, SIGNAL(triggered()),this,SLOT(runBat()));
    connect(ui->actionJingTai1D, SIGNAL(triggered()),this,SLOT(runBat()));
    connect(ui->action3Dduixiao, SIGNAL(triggered()),this,SLOT(runBat()));
    connect(ui->actionBaoLuo, SIGNAL(triggered()),this,SLOT(runBat()));
    connect(ui->actionRCSChengXiang, SIGNAL(triggered()),this,SLOT(runBat()));
    connect(ui->actionJingTaiDuiXiao, SIGNAL(triggered()),this,SLOT(runBat()));
    connect(ui->action2D, SIGNAL(triggered()),this,SLOT(runBat()));
    connect(ui->action3D, SIGNAL(triggered()),this,SLOT(runBat()));
    connect(ui->actionReset,SIGNAL(triggered()),this,SLOT(runBat()));
    connect(ui->actionReport,SIGNAL(triggered()), this, SLOT(onActionReportTriggered()));
    connect(ui->actionCombinedWordReport,SIGNAL(triggered()),this,SLOT(onActionCombinedWordReportTriggered()));



//    connect(ui->actionReport, SIGNAL(triggered()),this,SLOT(runBat()));
//    connect(ui->pushButtonRFBegin, SIGNAL(clicked()), this, SLOT(onPushBtnRFBeginClicked()));
//    connect(ui->pushButtonRFStop, SIGNAL(clicked()), this, SLOT(onPushBtnRFStopClicked()));
//    connect(ui->pushButtonRFSelfTest, SIGNAL(clicked()), this, SLOT(onPushBtnRFSelfTsetClicked()));
//    connect(ui->pushButtonRFReset, SIGNAL(clicked()), this, SLOT(onPushBtnRFResetClicked()));
//    connect(ui->pushButtonRFAdjust, SIGNAL(clicked()), this, SLOT(onPushBtnRFAdjustClicked()));
    connect(ui->pushButtonServoContinue, SIGNAL(clicked()), this, SLOT(onPushBtnServoContinueClicked()));
    connect(ui->pushButtonServoDisContinue, SIGNAL(clicked()), this, SLOT(onPushBtnServoDisContinueClicked()));
//    connect(ui->pushButtonServoStop, SIGNAL(clicked()), this, SLOT(onPushBtnServoStopClicked()));
    connect(ui->pushButtonServoReturnRun, SIGNAL(clicked()), this, SLOT(onPushBtnServoReturnRunClicked()));
    connect(ui->pushButtonServoPauseRun, SIGNAL(clicked()), this, SLOT(onPushBtnServoPauseRunClicked()));
    connect(ui->pushButtonServoUnPauseRun, SIGNAL(clicked()), this, SLOT(onPushBtnServoUnPauseRunClicked()));
    connect(ui->pushButtonStartTest, SIGNAL(clicked()), this, SLOT(onPushBtnStartTestClicked()));
    connect(ui->pushButtonStopTest, SIGNAL(clicked()), this, SLOT(onPushBtnStopTestClicked()));
//    connect(ui->pushButtonNormalCollection, SIGNAL(clicked()), this, SLOT(onPushButtonNormalCollectionClicked()));
//    connect(ui->pushButtonEnvelopeCollection, SIGNAL(clicked()), this, SLOT(onpushButtonEnvelopeCollection()));

    //发送配置信息的线程
    m_configCmd.moveToThread(&m_configCmdThread);
    m_configCmdThread.start();
//    connect(this, SIGNAL(RFStarted(ushort,ushort,ushort)), &m_configCmd, SLOT(onRFStarted(ushort,ushort,ushort)));
//    connect(this, SIGNAL(RFStopped()), &m_configCmd, SLOT(onRFStopped()));
//    connect(this, SIGNAL(RFSelfTest(ushort)), &m_configCmd, SLOT(onRFSelfTest(ushort)));
//    connect(this, SIGNAL(RFReset(ushort)), &m_configCmd, SLOT(onRFReset(ushort)));
//    connect(this, SIGNAL(RFAdjust(ushort)), &m_configCmd, SLOT(onRFAdjust(ushort)));
    connect(this, SIGNAL(cmdChanged(bool,QStringList,QStringList)),&m_configCmd, SLOT(onCmdChanged(bool,QStringList,QStringList)));
    connect(this, SIGNAL(servoContinue(QStringList)), &m_configCmd, SLOT(onServoContinue(QStringList)));
    connect(this, SIGNAL(servoDisContine(QStringList)), &m_configCmd, SLOT(onServoDisContinue(QStringList)));
//    connect(this, SIGNAL(servoStopRun()), &m_configCmd, SLOT(onServoStopRun()));
    connect(this, SIGNAL(servoPauseRun()), &m_configCmd, SLOT(onServoPauseRun()));
    connect(this, SIGNAL(servoUnPauseRun()), &m_configCmd, SLOT(onServoUnPauseRun()));
    connect(this, SIGNAL(servoReturnRun(QStringList)), &m_configCmd, SLOT(onServoReturnRun(QStringList)));

    //发送给转发软件实验信息的线程
    m_forwordCmd.moveToThread(&m_forwordCmdThread);
    m_forwordCmdThread.start();
    connect(this, SIGNAL(testStarted(int,QString)), &m_forwordCmd, SLOT(onTestStart(int,QString)));

    //接收上行帧的线程
    m_upPacket.moveToThread(&m_upPacketThread);
    m_upPacketThread.start();
    connect(&m_upPacket, SIGNAL(RFStateChanged(uchar,ushort)), this, SLOT(onRFStateChanged(uchar,ushort)));
    connect(&m_upPacket, SIGNAL(servoStateChanged(ushort)), this, SLOT(onServoStateChanged(ushort)));
    connect(&m_upPacket, SIGNAL(servoCoorChanged(uint,uint)), this, SLOT(onServoCoorChanged(uint,uint)));
    connect(&m_upPacket, SIGNAL(servoTimeChanged(uint)), this, SLOT(onServoTimeChanged(uint)));
    connect(this, SIGNAL(startParseData(bool)), &m_upPacket, SLOT(onStartParseData(bool)));

    //解算数据的线程
    m_parseData.moveToThread(&m_parseDataThread);
    m_parseDataThread.start();
    connect(&m_upPacket, SIGNAL(dataChanged(QByteArray)), &m_parseData, SLOT(onDataChanged(QByteArray)));

    //处理回传图像信息的线程
    m_resolvResult.moveToThread(&m_resolvResultThread);
    m_resolvResultThread.start();
    connect(&m_resolvResult, SIGNAL(rcsDataupdated()), this, SLOT(onRcsDataUpdated()));
    connect(&m_resolvResult, SIGNAL(d3DataUpdated(D3Para)), this, SLOT(onD3DataUpdated(D3Para)));

    //处理脉压数据的线程
    m_pulseData.moveToThread(&m_pulseDataThread);
    m_pulseDataThread.start();
    connect(&m_pulseData, SIGNAL(pulseImageUpdated(QImage*, int, int)),
            this, SLOT(onPulseImageUpdated(QImage *, int, int)));
}

MainWindow::~MainWindow()
{
    if(m_configCmdThread.isRunning())
    {
        m_configCmdThread.quit();
        m_configCmdThread.wait(1000);
    }
    if(m_forwordCmdThread.isRunning())
    {
        m_forwordCmdThread.quit();
        m_forwordCmdThread.wait(1000);
    }
    if(m_upPacketThread.isRunning())
    {
        m_upPacketThread.quit();
        m_upPacketThread.wait(1000);
    }
    if(m_parseDataThread.isRunning())
    {
        m_parseDataThread.quit();
        m_parseDataThread.wait(1000);
    }
    if(m_resolvResultThread.isRunning())
    {
        m_resolvResultThread.quit();
        m_resolvResultThread.wait(1000);
    }
    if(m_pulseDataThread.isRunning())
    {
        m_pulseDataThread.quit();
        m_pulseDataThread.wait();
    }
#ifdef OPENGL_VIEW
    if(nullptr != m_pGLWidget)
    {
        m_pGLWidget->close();
        delete m_pGLWidget;
        m_pGLWidget = nullptr;
    }
#else
    if (nullptr != m_pScatterWidget)
    {
        m_pScatterWidget->close();
        delete m_pScatterWidget;
        m_pScatterWidget = nullptr;
    }
#endif
    delete ui;
}

void MainWindow::initInterface()
{
    m_testName.clear();
    //限定输入
    ui->lineEditSweepFStart->setValidator(new QIntValidator(1000,18000,this));
    ui->lineEditSweepFEnd->setValidator(new QIntValidator(1000,18000,this));
    ui->lineEditAtten->setValidator(new QIntValidator(this));
    ui->lineEditSpeedH->setValidator(new QIntValidator(0,999,this));
    ui->lineEditSpeedV->setValidator(new QIntValidator(0,999,this));
    ui->lineEditStartX->setValidator(new QIntValidator(0,5900,this));
    ui->lineEditStartY->setValidator(new QIntValidator(0,6000,this));
    ui->lineEditEndX->setValidator(new QIntValidator(0,5900,this));
    ui->lineEditEndY->setValidator(new QIntValidator(0,6000,this));
    ui->lineEditStepY->setValidator(new QIntValidator(0,1000,this));

    ui->comboBoxGather->setCurrentIndex(-1);
    ui->comboBoxSys_init->setCurrentIndex(-1);
    ui->comboBoxReset->setCurrentIndex(-1);
    ui->comboBoxCal->setCurrentIndex(-1);
    ui->lineEditSweepFStart->clear();
    ui->lineEditSweepFEnd->clear();
    ui->lineEditAtten->clear();
    ui->lineEditSpeedH->clear();
    ui->lineEditSpeedV->clear();
    ui->lineEditStartX->clear();
    ui->lineEditStartY->clear();
    ui->lineEditEndX->clear();
    ui->lineEditEndY->clear();
    ui->lineEditStepY->clear();
    ui->lineEdit_batch->clear();
    ui->lineEdit_bpXNum->clear();
    ui->lineEdit_bpXSize->clear();
    ui->lineEdit_bpXStartLocation->clear();
    ui->lineEdit_bpYNum->clear();
    ui->lineEdit_bpYSize->clear();
    ui->lineEdit_bpYStartLocation->clear();
    ui->lineEdit_bpZNum->clear();
    ui->lineEdit_bpZSize->clear();
    ui->lineEdit_bpZStartLocation->clear();
    ui->lineEdit_StartFrequency->clear();
    ui->lineEdit_EndFrequenncy->clear();

//    ui->comboBoxInit_done->setCurrentIndex(-1);
    ui->labelCurrentX->clear();
    ui->labelCurrentY->clear();
    ui->labelStime->clear();

    m_pStatusBar->initStatusBarInfo();
    ui->pushButtonServoDisContinue->setVisible(false);
    ui->pushButtonServoPauseRun->setVisible(false);
    ui->pushButtonServoReturnRun->setVisible(false);
    ui->pushButtonServoUnPauseRun->setVisible(false);

//        ui->actionBaoLuo->setVisible(false);
//        ui->actionDuiXiao->setVisible(false);
//        ui->actionJingTaiDuiXiao->setVisible(false);
//        ui->actionJingTaiDuiXiao->setVisible(false);
//        ui->actionRCSChengXiang->setVisible(false);
//        ui->actionSysBC->setVisible(false);
//        ui->actionJingTai1D->setVisible(false);
//        ui->actionReport->setVisible(false);

}

void MainWindow::selfCheckStatus()
{
    QString text = QString("%1\n\n%2\n\n%3\n\n%4\n\n%5")
            .arg(QStringLiteral("1、检查射频机箱是否正确连接、各射频端口是否安装衰减；"))
            .arg(QStringLiteral("2、射频机箱自检（此步骤不接天线，另外注意在进行射频自检步骤前重点检查射频机箱对应端口是否连接衰减器） 射频自检操作步骤:")
                 + QStringLiteral("\n\n    1) 分频段采集射频机箱环形器数据（1-2GHz、2-6GHz、6-18GHz）（10文件左右即可），文件命名为zj12_i.bin/zj26_i.bin/zj618_i.bin")
                 + QStringLiteral("\n\n    2) 采集得到环形器数据后，利用maichongyasuo_fft_old_80.exe进行脉冲压缩，脉冲压缩后的文件命名为zjfft12.bin/zjfft26.bin/zjfft618.bin")
                 + QStringLiteral("\n\n    3) 利用环形器脉冲压缩结果输出相位补偿文件phase.bin，并在界面软件显示 "))
            .arg(QStringLiteral("3、在开始展开平台之前，必须确定前舱舱门完全展开，否则不能展开平台；"))
            .arg(QStringLiteral("4、在正式开始实验时，必须确定各部件（射频、伺服）正常，人员处于安全区域，否则不能进行实验；"))
            .arg(QStringLiteral("5、在平台收起之前，必须确定前舱舱门以及实验人员处于安全状态，否则不能收起平台；"));
    QMessageBox box(QMessageBox::Information, QStringLiteral("提示"), text);
    box.setButtonText(QMessageBox::Ok, QStringLiteral("知道了"));
    box.exec();
}

void MainWindow::enableInterface(bool Value)
{
    ui->checkBoxGather->setEnabled(Value);
    ui->checkBoxRFSelfTest->setEnabled(Value);
    ui->checkBoxRFReset->setEnabled(Value);
    ui->checkBoxRFAdjust->setEnabled(Value);
    ui->comboBoxGather->setEnabled(Value);
    ui->comboBoxSys_init->setEnabled(Value);
    ui->comboBoxReset->setEnabled(Value);
    ui->comboBoxCal->setEnabled(Value);
    ui->lineEditSweepFStart->setEnabled(Value);
    ui->lineEditSweepFEnd->setEnabled(Value);
    ui->lineEditAtten->setEnabled(Value);
    ui->lineEditStartX->setEnabled(Value);
    ui->lineEditStartY->setEnabled(Value);
    ui->lineEditEndX->setEnabled(Value);
    ui->lineEditEndY->setEnabled(Value);
    ui->lineEditSpeedV->setEnabled(Value);
    ui->lineEditSpeedH->setEnabled(Value);
    ui->lineEditStepY->setEnabled(Value);
    ui->lineEdit_batch->setEnabled(Value);
    ui->lineEdit_bpXNum->setEnabled(Value);
    ui->lineEdit_bpXSize->setEnabled(Value);
    ui->lineEdit_bpXStartLocation->setEnabled(Value);
    ui->lineEdit_bpYNum->setEnabled(Value);
    ui->lineEdit_bpYSize->setEnabled(Value);
    ui->lineEdit_bpYStartLocation->setEnabled(Value);
    ui->lineEdit_bpZNum->setEnabled(Value);
    ui->lineEdit_bpZSize->setEnabled(Value);
    ui->lineEdit_bpZStartLocation->setEnabled(Value);
    ui->lineEdit_StartFrequency->setEnabled(Value);
    ui->lineEdit_EndFrequenncy->setEnabled(Value);
}

void MainWindow::loadStyle()
{
    QFile file(":/res/style.qss");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, QStringLiteral("错误"), QStringLiteral("加载样式文件出错."));
        return;
    }
    QString styles = file.readAll();
    qApp->setStyleSheet(styles);
    file.close();
}

void MainWindow::onActionAboutTriggered()
{
    AboutDlg dlg;

    dlg.exec();
}

void MainWindow::onActionUserTriggered()
{
    UserManagerDlg *pUserDlg = new UserManagerDlg(this);
    connect(pUserDlg, SIGNAL(rejected()), pUserDlg, SLOT(deleteLater()));
    pUserDlg->open();
}

void MainWindow::onActionConfigTriggered()
{
    ConfigManagerDlg *pConfigDlg = new ConfigManagerDlg(this);
    connect(pConfigDlg, SIGNAL(rejected()), pConfigDlg, SLOT(deleteLater()));
    connect(pConfigDlg, &ConfigManagerDlg::configChanged, [&]()
    {
        ui->actionPlayBack->setEnabled(true);
    });
    pConfigDlg->open();
}

void MainWindow::onActionArgumentTriggered()
{
    initInterface();
    ArgumentManagerDlg *pArgDlg = new ArgumentManagerDlg(this);
    connect(pArgDlg, SIGNAL(rejected()), pArgDlg, SLOT(deleteLater()));
    pArgDlg->open();
}

void MainWindow::onActionChooseTriggered()
{
    ChooseTestDlg *pChooseDlg = new ChooseTestDlg(this);
    connect(pChooseDlg, SIGNAL(rejected()), pChooseDlg, SLOT(deleteLater()));
    connect(pChooseDlg, SIGNAL(testNameChanged(QString)), this, SLOT(onTestNameChanged(QString)));
    pChooseDlg->open();
}

void MainWindow::onAction3dPointTriggered()
{
#ifdef OPENGL_VIEW
    m_pGLWidget->show();
#else
    m_pScatterWidget->show();
#endif
}

void MainWindow::onD3DataUpdated(D3Para para)
{
    ui->action3dPoint->setEnabled(true);
#ifdef OPENGL_VIEW
    m_pGLWidget->setDataRange(para.xb, para.ya, para.zc, 1);
    m_pGLWidget->setDataCount(para.xb, para.ya, para.zc);
    m_pGLWidget->setDataSource(para.pxMat, para.pyMat, para.pzMat, para.pBpp);
    m_pGLWidget->setWindowTitle(QStringLiteral("三维点云图"));
    m_pGLWidget->show();
#else
    m_pScatterWidget->setDataRange(para.xb, para.ya, para.zc);
    m_pScatterWidget->setDataCount(para.xb, para.ya, para.zc);
    m_pScatterWidget->setDataSource(para.pxMat, para.pyMat, para.pzMat, para.pBpp);
    m_pScatterWidget->setWindowTitle(QStringLiteral("三维点云图"));
#endif
}

void MainWindow::onRcsDataUpdated()
{
    ui->actionRCS->setEnabled(true);

    ShowRCSDlg *dialog = new ShowRCSDlg(this);
    connect(dialog, SIGNAL(rejected()), dialog, SLOT(deleteLater()));
    dialog->show();
}

void MainWindow::onActionPlayBackTriggered()
{
    PlayBackDlg dlg(this);
    connect(&dlg, SIGNAL(playbackExperiment(int,QString)), &m_forwordCmd, SLOT(onTestStart(int,QString)));
    connect(&m_forwordCmd, SIGNAL(playbackFinished(unsigned char)),&dlg, SLOT(onPalybackFinished(unsigned char)));
    dlg.exec();
}

void MainWindow::onActionParaTriggered()
{
    ParaAgument dlg(this);
    dlg.exec();
}

void MainWindow::onActionReportTriggered()
{
    SelectPath dlg(this, 4);
    connect(&dlg, SIGNAL(reportExperiment(int,QString)),this, SIGNAL(testStarted(int,QString)));
    dlg.exec();
}

void MainWindow::onActionCombinedWordReportTriggered()
{
    SelectPath dlg(this, 5);
    connect(&dlg, SIGNAL(reportExperiment(int,QString)),this, SIGNAL(testStarted(int,QString)));
    dlg.exec();
}

void MainWindow::onPushButtonNormalCollectionClicked()
{
    emit normalCollection();
}

void MainWindow::onpushButtonEnvelopeCollection()
{
    emit envelopeCollection();
}

void MainWindow::onPushBtnRFBeginClicked()
{
    //射频开始功能
    ushort start = ui->lineEditSweepFStart->text().toUShort();
    ushort end = ui->lineEditSweepFEnd->text().toUShort();
    ushort power = ui->lineEditAtten->text().toShort();
    emit RFStarted(start, end, power);
    int bandRange = ui->lineEditSweepFStart->text().toInt() - ui->lineEditSweepFEnd->text().toInt();
    localConfig.setBandRange(QString::number(bandRange));
}

void MainWindow::onPushBtnRFStopClicked()
{
    //射频停止功能
    emit RFStopped();
}

void MainWindow::onPushBtnRFSelfTsetClicked()
{
    //射频自检功能
    ushort state = (ushort)ui->comboBoxSys_init->currentIndex();
    emit RFSelfTest(state);
}

void MainWindow::onPushBtnRFResetClicked()
{
    //射频复位功能
    ushort state = (ushort)ui->comboBoxReset->currentIndex();
    emit RFReset(state);
}

void MainWindow::onPushBtnRFAdjustClicked()
{
    //射频校正功能
    ushort state = (ushort)ui->comboBoxCal->currentIndex();
    emit RFAdjust(state);
}

void MainWindow::onPushBtnServoContinueClicked()
{
    //伺服连续运动功能
    QStringList args;
    args.append(ui->lineEditSpeedH->text());
    args.append(ui->lineEditSpeedV->text());
    args.append(QString::number(ui->lineEditStartX->text().toUInt() * 100));
    args.append(QString::number(ui->lineEditStartY->text().toUInt() * 100));
    args.append(QString::number(ui->lineEditEndX->text().toUInt() * 100));
    args.append(QString::number(ui->lineEditEndY->text().toUInt() * 100));
    args.append(QString::number(ui->lineEditStepY->text().toUShort() * 100));
    emit servoContinue(args);
}

void MainWindow::onPushBtnServoDisContinueClicked()
{
    //伺服间断运动功能
    QStringList args;
    args.append(ui->lineEditSpeedH->text());
    args.append(ui->lineEditSpeedV->text());
    args.append(QString::number(ui->lineEditStartX->text().toUInt() * 100));
    args.append(QString::number(ui->lineEditStartY->text().toUInt() * 100));
    args.append(QString::number(ui->lineEditEndX->text().toUInt() * 100));
    args.append(QString::number(ui->lineEditEndY->text().toUInt() * 100));
    args.append(QString::number(ui->lineEditStepY->text().toUShort() * 100));
    emit servoDisContine(args);
}

void MainWindow::onPushBtnServoReturnRunClicked()
{
    //伺服回起点运动功能
    QStringList args;
    args.append(ui->lineEditSpeedH->text());
    args.append(ui->lineEditSpeedV->text());
    args.append(QString::number(ui->lineEditStartX->text().toUInt() * 100));
    args.append(QString::number(ui->lineEditStartY->text().toUInt() * 100));
    args.append(QString::number(ui->lineEditEndX->text().toUInt() * 100));
    args.append(QString::number(ui->lineEditEndY->text().toUInt() * 100));
    args.append(QString::number(ui->lineEditStepY->text().toUShort() * 100));
    emit servoReturnRun(args);
}

void MainWindow::onPushBtnServoPauseRunClicked()
{
    //伺服暂停运动功能
    emit servoPauseRun();
}

void MainWindow::onPushBtnServoUnPauseRunClicked()
{
    //伺服解除暂停功能
    emit servoUnPauseRun();
}

void MainWindow::onPushBtnServoStopClicked()
{
    //伺服停止功能
    emit servoStopRun();
}

void MainWindow::onPushBtnStartTestClicked()
{
    //    参数为空检测
        QStringList argsTemp;
        argsTemp.append(QString::number(ui->comboBoxGather->currentIndex()));
        argsTemp.append(QString::number(ui->comboBoxSys_init->currentIndex()));
        argsTemp.append(QString::number(ui->comboBoxReset->currentIndex()));
        argsTemp.append(QString::number(ui->comboBoxCal->currentIndex()));

        argsTemp.append(ui->lineEditSweepFStart->text());
        argsTemp.append(ui->lineEditSweepFEnd->text());
        argsTemp.append(ui->lineEditAtten->text());


        argsTemp.append(ui->lineEditSpeedH->text());
        argsTemp.append(ui->lineEditSpeedV->text());
        argsTemp.append(ui->lineEditStartX->text());
        argsTemp.append(ui->lineEditStartY->text());
        argsTemp.append(ui->lineEditStepY->text());
        argsTemp.append(ui->lineEditEndX->text());
        argsTemp.append(ui->lineEditEndY->text());

        argsTemp.append(ui->lineEdit_bpXNum->text());
        argsTemp.append(ui->lineEdit_bpYNum->text());
        argsTemp.append(ui->lineEdit_bpZNum->text());
        argsTemp.append(ui->lineEdit_batch->text());
        argsTemp.append(ui->lineEdit_bpXStartLocation->text());
        argsTemp.append(ui->lineEdit_bpYStartLocation->text());
        argsTemp.append(ui->lineEdit_bpZStartLocation->text());
        argsTemp.append(ui->lineEdit_bpXSize->text());
        argsTemp.append(ui->lineEdit_bpYSize->text());
        argsTemp.append(ui->lineEdit_bpZSize->text());
        argsTemp.append(ui->lineEdit_StartFrequency->text());
        argsTemp.append(ui->lineEdit_EndFrequenncy->text());

        QString varArgs;
        foreach (varArgs, argsTemp) {
            if(varArgs.isEmpty())
            {
                QMessageBox::warning(this, QStringLiteral("警告"),
                                     QStringLiteral("参数不能为空!"),
                                     QMessageBox::Ok);
                return ;
            }
        }

    //    检查扫频起点、扫频终点参数是否正确：（1-2或2-6或6-18）且（起点<终点）
        uint sweepFStart = ui->lineEditSweepFStart->text().toUInt();
        uint sweepFEnd = ui->lineEditSweepFEnd->text().toUInt();
        bool one = (sweepFStart >= 1000) && (sweepFStart <= 2000)
                   && (sweepFEnd >= 1000) && (sweepFEnd <= 2000)
                   && (sweepFStart < sweepFEnd);
        bool two = (sweepFStart >= 2000) && (sweepFStart <= 6000)
                && (sweepFEnd >= 2000) && (sweepFEnd <= 6000)
                && (sweepFStart < sweepFEnd);
        bool three = (sweepFStart >= 6000) && (sweepFStart <=18000)
                && (sweepFEnd >= 6000) && (sweepFEnd <= 18000)
                && (sweepFStart < sweepFEnd);
       if(!(one || two ||three))
       {
           QMessageBox::warning(this, QStringLiteral("警告"),
                                QStringLiteral("扫频起点为X，扫频终点为Y。X、Y均满足以下两个条件：\n1：X < Y\n2：X、Y ∈[1000,2000] 或者\n      X、Y ∈[2000,6000]或者\n      X、Y ∈[6000,18000]")
                                ,QMessageBox::Ok);
           return ;
       }

       if((ui->comboBoxGather->currentIndex() == -1) || (ui->checkBoxGather->checkState() != Qt::Checked))
       {
           QMessageBox::warning(this, QStringLiteral("警告"),
                                QStringLiteral("请选择采集模式(确认勾选右侧按钮，将向射频系统发送指令！！)")
                                ,QMessageBox::Ok);
           return;
       }

       QString saveArgs;
       saveArgs.append(ui->comboBoxGather->currentText()+ QString(","));
       saveArgs.append(ui->comboBoxSys_init->currentText() + QString(","));
       saveArgs.append(ui->comboBoxReset->currentText()+ QString(","));
       saveArgs.append(ui->comboBoxCal->currentText() + QString(","));
       for(int i = 4; i < argsTemp.length(); i++)
       {
           saveArgs.append(argsTemp.at(i) + QString(","));
       }
       qDebug() <<"saveArgs" <<saveArgs;

       localConfig.setStartArgs(saveArgs);

       QStringList argsCheck;
       argsCheck.append(QString::number(ui->checkBoxGather->checkState()));
       argsCheck.append(QString::number(ui->checkBoxRFSelfTest->checkState()));
       argsCheck.append(QString::number(ui->checkBoxRFReset->checkState()));
       argsCheck.append(QString::number(ui->checkBoxRFAdjust->checkState()));

       QStringList argsCmd;
       argsCmd.append(QString::number(ui->comboBoxGather->currentIndex()));
       argsCmd.append(ui->lineEditSweepFStart->text());
       argsCmd.append(ui->lineEditSweepFEnd->text());
       argsCmd.append(ui->lineEditAtten->text());
       argsCmd.append(QString::number(ui->comboBoxSys_init->currentIndex()));
       argsCmd.append(QString::number(ui->comboBoxReset->currentIndex()));
       argsCmd.append(QString::number(ui->comboBoxCal->currentIndex()));

        //保存生成脉压图需要的频带宽
       double bandRange = ui->lineEditSweepFEnd->text().toDouble() - ui->lineEditSweepFStart->text().toDouble();
       localConfig.setBandRange(QString::number(bandRange));
       enableInterface(false);

    //将界面数据更新到数据库的表para_arg中

    QString filed("field");
    dbInterface.upTable(QString("para_arg"),filed+QStringLiteral("载频") ,ui->lineEditSweepFStart->text());
    dbInterface.upTable(QString("para_arg"),filed+QStringLiteral("带宽") ,QString::number(bandRange));
    dbInterface.upTable(QString("para_arg"),filed+QStringLiteral("BP成像X方向网格数") ,ui->lineEdit_bpXNum->text());
    dbInterface.upTable(QString("para_arg"),filed+QStringLiteral("BP成像Y方向网格数") ,ui->lineEdit_bpYNum->text());
    dbInterface.upTable(QString("para_arg"),filed+QStringLiteral("BP成像Z方向网格数") ,ui->lineEdit_bpZNum->text());
    dbInterface.upTable(QString("para_arg"),filed+QStringLiteral("每个batch元素个数") ,ui->lineEdit_batch->text());
    dbInterface.upTable(QString("para_arg"),filed+QStringLiteral("BP成像X方向起始位置") ,ui->lineEdit_bpXStartLocation->text());
    dbInterface.upTable(QString("para_arg"),filed+QStringLiteral("BP成像Y方向起始位置") ,ui->lineEdit_bpYStartLocation->text());
    dbInterface.upTable(QString("para_arg"),filed+QStringLiteral("BP成像Z方向起始位置") ,ui->lineEdit_bpZStartLocation->text());
    dbInterface.upTable(QString("para_arg"),filed+QStringLiteral("BP成像X方向网格大小") ,ui->lineEdit_bpXSize->text());
    dbInterface.upTable(QString("para_arg"),filed+QStringLiteral("BP成像Y方向网格大小") ,ui->lineEdit_bpYSize->text());
    dbInterface.upTable(QString("para_arg"),filed+QStringLiteral("BP成像Z方向网格大小") ,ui->lineEdit_bpZSize->text());
    dbInterface.upTable(QString("para_arg"),filed+QStringLiteral("X方向运动速度") ,ui->lineEditSpeedH->text());
    dbInterface.upTable(QString("para_arg"),filed+QStringLiteral("X方向运动位置") ,ui->lineEditStartX->text());
    dbInterface.upTable(QString("para_arg"),filed+QStringLiteral("Y方向起始位置") ,ui->lineEditStartY->text());
    double xD =  ui->lineEditStartX->text().toDouble() - ui->lineEditEndX->text().toDouble();
    dbInterface.upTable(QString("para_arg"),filed+QStringLiteral("X方向运动距离") , QString::number(xD*(-1)));
    double yD =  ui->lineEditStartY->text().toDouble() - ui->lineEditEndY->text().toDouble();
    dbInterface.upTable(QString("para_arg"),filed+QStringLiteral("Y方向运动距离") ,QString::number(yD*(-1)));
//    dbInterface.upTable(QString("para_arg"),QStringLiteral("X方向运动加速度") ,QString::number(0));
    dbInterface.upTable(QString("para_arg"),filed+QStringLiteral("起始频率") ,ui->lineEdit_StartFrequency->text());
    dbInterface.upTable(QString("para_arg"),filed+QStringLiteral("终止频率") ,ui->lineEdit_EndFrequenncy->text());
    dbInterface.upTable(QString("para_arg"),filed+QStringLiteral("保留字段1") ,QString::number(bandRange/12.5));

    m_testName = QDateTime::currentDateTime().toString("yyyyMMddhhmmss")+ QString("_")+QString::number(ui->comboBoxGather->currentIndex());

    m_pStatusBar->onSetInfo(m_testName.section("_", 0, 0));

    //告知数据转发软件开始正常模式的任务,实验开始了
    emit testStarted(0, m_testName);
    emit startParseData(true);//开始解析数据
    emit cmdChanged(true, argsCheck, argsCmd);
    ui->actionPara->setEnabled(false);
    ui->actionChoose->setEnabled(false);
    ui->actionArgument->setEnabled(false);
    ui->pushButtonStopTest->setEnabled(true);
    ui->pushButtonStartTest->setEnabled(false);
    ui->actionReset->setEnabled(false);
}

void MainWindow::onPushBtnStopTestClicked()
{
    //结束解析数据
    emit startParseData(false);



    //告知转发软件停止了
    QStringList args;
    emit testStarted(2, m_testName);

    //向数据采集模块下发停止命令
    QStringList checkArgs;
    QStringList cmdArgs;
    emit cmdChanged(false, checkArgs, cmdArgs);

    localConfig.setReport(ui->textEdit_TestRecord->toPlainText());
    enableInterface(true);
    ui->actionPara->setEnabled(true);
    ui->actionChoose->setEnabled(true);
    ui->actionArgument->setEnabled(true);
    ui->comboBoxGather->setEnabled(true);
    ui->comboBoxGather->setCurrentIndex(-1);
    ui->pushButtonStopTest->setEnabled(false);
    ui->pushButtonStartTest->setEnabled(true);
    ui->actionReset->setEnabled(true);
    
//    initInterface();
}

void MainWindow::onRFStateChanged(const uchar &rAddr, const ushort &data)
{
//    qDebug() << "show RF eAddr:" << rAddr;
//    qDebug() << "show RF state:" << data;
    if(0 == rAddr)
    {
        //0x00 Init_done 寄存器，自检完成
//        ui->comboBoxInit_done->setCurrentIndex(data);
        if(0 == data)
        {
            //自检失败
            ui->label_Init_done->setText(QStringLiteral("自检失败"));
        }
        else if(1 == data)
        {
            //自检完成
            ui->label_Init_done->setText(QStringLiteral("自检完成"));
        }
    }
    else if(1 == rAddr)
    {
        //0x01 Err_Status 寄存器，故障状态
    }
}

void MainWindow::onServoStateChanged(ushort state)
{
    state += 1;
//    qDebug() << "on mainwindow, onServoStateChanged: " << state;
}

void MainWindow::onServoCoorChanged(unsigned int x, unsigned int y)
{
    if(0 == x && 0 == y)
    {
        ;//到达了原始点位置
    }
    else if(x == ui->lineEditEndX->text().toUInt() && x == ui->lineEditEndY->text().toUInt())
    {
        ;//到达终点提示
    }
    else
    {
        ;
    }

    float nowX = x / 1000.0;//  /100是恢复小数点， /10是从mm转换为cm
    float nowY = y / 1000.0;

    ui->graphicsView->setValueOfXY(nowX, nowY);
}

void MainWindow::onServoTimeChanged(uint time)
{
    ui->labelStime->setText(QString("%1 s").arg(time));
}

void MainWindow::onTestNameChanged(QString name)
{
    if(name.isEmpty())
    {
        return;
    }

    QStringList args;
    if(!dbInterface.getTestArg(args, name))
    {
        qWarning() << "on MainWindow, onTestNameChanged: " << dbInterface.errorString();
    }
//        QString str;
//        foreach (str, args) {
//            qDebug()<< str;
//        }

    if(!args.isEmpty())
    {
        args.takeFirst();
        args.takeFirst();
        ui->comboBoxGather->setCurrentIndex(args.takeFirst().toInt());
        ui->comboBoxSys_init->setCurrentIndex(args.takeFirst().toInt());
        ui->comboBoxReset->setCurrentIndex(args.takeFirst().toInt());
        ui->comboBoxCal->setCurrentIndex(args.takeFirst().toInt());
        ui->lineEditSweepFStart->setText(args.takeFirst());
        ui->lineEditSweepFEnd->setText(args.takeFirst());
        ui->lineEditAtten->setText(args.takeFirst());

        ui->lineEditSpeedH->setText(args.takeFirst());
        ui->lineEditSpeedV->setText(args.takeFirst());
        ui->lineEditStartX->setText(QString::number((args.takeFirst().toDouble()/* / 100*/)));
        ui->lineEditStartY->setText(QString::number((args.takeFirst().toDouble()/* / 100*/)));
        ui->lineEditEndX->setText(QString::number((args.takeFirst().toDouble()/* / 100*/)));
        ui->lineEditEndY->setText(QString::number((args.takeFirst().toDouble()/* / 100*/)));
        ui->lineEditStepY->setText(QString::number((args.takeFirst().toDouble()/* / 100*/)));

        ui->lineEdit_batch->setText(args.takeFirst());
        ui->lineEdit_bpXNum->setText(args.takeFirst());
        ui->lineEdit_bpXSize->setText(args.takeFirst());
        ui->lineEdit_bpXStartLocation->setText(args.takeFirst());
        ui->lineEdit_bpYNum->setText(args.takeFirst());
        ui->lineEdit_bpYSize->setText(args.takeFirst());
        ui->lineEdit_bpYStartLocation->setText(args.takeFirst());
        ui->lineEdit_bpZNum->setText(args.takeFirst());
        ui->lineEdit_bpZSize->setText(args.takeFirst());
        ui->lineEdit_bpZStartLocation->setText(args.takeFirst());
        ui->lineEdit_StartFrequency->setText(args.takeFirst());
        ui->lineEdit_EndFrequenncy->setText(args.takeFirst());
        ui->textEdit_TestRecord->setText(args.takeFirst());
    }
    else
    {
        qWarning() << "on MainWindow, onTestNameChanged, args is empty";
    }
}

void MainWindow::onPulseImageUpdated(QImage *image, int r, int c)
{
    m_pPulseScene->setBandRange(localConfig.getBandRange().toInt());
    m_pPulseScene->updateImage(image, r, c);
}

void MainWindow::runBat()
{
    qDebug() <<"batfoloder--->" << localConfig.getBatFolderAddress();
    if(this->sender()->objectName() == QString("action2Dduixiao"))
    {
        localConfig.setBatType(localConfig.getBatFolderAddress()+ QString("/2ddxcx.bat"));
        qDebug() <<"actionDuiXiao--->" << localConfig.getBatType();
        emit testStarted(3, m_testName);
    }
    else if(this->sender()->objectName() == QString("actionSysBC"))
    {
        localConfig.setBatType(localConfig.getBatFolderAddress()+ QString("/phase.bat"));
        emit testStarted(3, m_testName);
         qDebug() <<"actionSysBC--->" << localConfig.getBatType();
    }
    else if(this->sender()->objectName() == QString("actionJingTai1D"))
    {
        localConfig.setBatType(localConfig.getBatFolderAddress()+ QString("/jt1dcx.bat"));
        emit testStarted(3, m_testName);
        qDebug() <<"actionJingTai1D--->" << localConfig.getBatType();

    }
    else if(this->sender()->objectName() == QString("action3Dduixiao"))
    {
        localConfig.setBatType(localConfig.getBatFolderAddress()+ QString("/dxcx.bat"));
        emit testStarted(3, m_testName);
        qDebug() <<"actionDongTai2D--->" << localConfig.getBatType();

    }
    else if(this->sender()->objectName() == QString("actionBaoLuo"))
    {
        localConfig.setBatType(localConfig.getBatFolderAddress()+ QString("/baoluo.bat"));
        emit testStarted(3, m_testName);
        qDebug() <<"actionBaoLuo--->" << localConfig.getBatType();

    }
    else if(this->sender()->objectName() == QString("actionRCSChengXiang"))
    {
        localConfig.setBatType(localConfig.getBatFolderAddress()+ QString("/rcsfy.bat"));
        emit testStarted(3, m_testName);
        qDebug() <<"actionRCSChengXiang--->" << localConfig.getBatType();

    }
    else if(this->sender()->objectName() == QString("actionJingTaiDuiXiao"))
    {
        localConfig.setBatType(localConfig.getBatFolderAddress()+ QString("/jtdx.bat"));
        emit testStarted(3, m_testName);
        qDebug() <<"actionJingTaiDuiXiao--->" << localConfig.getBatType();

    }
    else if(this->sender()->objectName() == QString("action2D"))
    {
        localConfig.setBatType(localConfig.getBatFolderAddress()+ QString("/dj2dcx.bat"));
        emit testStarted(3, m_testName);
    }
    else if(this->sender()->objectName() == QString("action3D"))
    {
        localConfig.setBatType(localConfig.getBatFolderAddress()+ QString("/dj3dcx.bat"));
        emit testStarted(3, m_testName);
    }
    else if(this->sender()->objectName() == QString("actionReset"))
    {
        QString workingDirectory;
        QStringList working = localConfig.getReset().split("/");
        working.takeLast();
        for(int i = 0; i < working.length(); i++)
        {\
            workingDirectory.append(working.at(i) + QString("/"));
        }
//        qDebug() << "+++++++=======" << workingDirectory;
//        qDebug() << "+++++++=======" << localConfig.getReset();

        QStringList args;
        QProcess::startDetached(localConfig.getReset(),args,workingDirectory);
//        QProcess::startDetached(QString("D:/UltraEdit/uedit64.exe"),args,QString("D:/UltraEdit"));

    }
    else
    {

    }
}







