#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>

#include "configcmdpacket.h"
#include "forwordcmdpacket.h"
#include "recvuppacket.h"
#include "parsedata.h"
#include "recvresolvresult.h"
#include "view/graphicsview.h"
#include "pulse/ReceivePulseData.h"
#include "pulse/PulseScene.h"
#include "SelectPath.h"

class StatusBar;
class GLWidget;
class ScatterWidget;
class QFtp;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    //是否开始解析数据
    void startParseData(bool ok);
    //转发软件实验开始
    void testStarted(int model, QString name);
    void cmdChanged(bool state, QStringList checkArgs, QStringList cmdArgs);

    //射频开始
    void RFStarted(ushort start, ushort end, ushort power);
    //射频停止
    void RFStopped();
    //射频自检
    void RFSelfTest(ushort state);
    //射频复位
    void RFReset(ushort state);
    //射频校正
    void RFAdjust(ushort state);
    //正常采集
    void normalCollection();
    //包络采集
    void envelopeCollection();

    //伺服连续运动
    void servoContinue(QStringList args);
    //伺服间断运动
    void servoDisContine(QStringList args);
    //伺服回起点运动
    void servoReturnRun(QStringList args);
    //伺服暂停运动
    void servoPauseRun();
    //伺服解除暂停
    void servoUnPauseRun();
    //伺服停止
    void servoStopRun();

private:
    void initInterface();
    void selfCheckStatus();
    void enableInterface(bool Value);
    void loadStyle();
private slots:
    void onActionAboutTriggered();
    //用户管理
    void onActionUserTriggered();
    //配置IP
    void onActionConfigTriggered();
    //配置参数
    void onActionArgumentTriggered();
    //选择实验模板
    void onActionChooseTriggered();
    //3d显示
    void onAction3dPointTriggered();
    void onD3DataUpdated(D3Para para);
    //rcs显示
    void onRcsDataUpdated();
    //回放模式
    void onActionPlayBackTriggered();
    //Para参数
    void onActionParaTriggered();
    //生成实验报告
    void onActionReportTriggered();
    //拼接实验报告
    void onActionCombinedWordReportTriggered();

    //正常采集
    void onPushButtonNormalCollectionClicked();
    //包络采集
    void onpushButtonEnvelopeCollection();

    //射频开始功能
    void onPushBtnRFBeginClicked();
    //射频停止功能
    void onPushBtnRFStopClicked();
    //射频自检功能
    void onPushBtnRFSelfTsetClicked();
    //射频复位功能
    void onPushBtnRFResetClicked();
    //射频校正功能
    void onPushBtnRFAdjustClicked();

    //伺服连续运动功能
    void onPushBtnServoContinueClicked();
    //伺服间断运动功能
    void onPushBtnServoDisContinueClicked();
    //伺服回起点运动功能
    void onPushBtnServoReturnRunClicked();
    //伺服暂停运动功能
    void onPushBtnServoPauseRunClicked();
    //伺服解除暂停功能
    void onPushBtnServoUnPauseRunClicked();
    //伺服停止功能
    void onPushBtnServoStopClicked();

    //数据转发软件开始试验
    void onPushBtnStartTestClicked();
    //数据转发软件开始试验
    void onPushBtnStopTestClicked();

    //射频状态改变
    void onRFStateChanged(const uchar &rAddr, const ushort &data);
    //伺服状态改变
    void onServoStateChanged(ushort state);
    //伺服xy改变
    void onServoCoorChanged(unsigned int x, unsigned int y);
    //伺服运动时间改变
    void onServoTimeChanged(uint time);
    //实验名改变
    void onTestNameChanged(QString name);


    //脉压图
    void onPulseImageUpdated(QImage *image, int r, int c);

//运行脚本文件
    void runBat();

private:
    Ui::MainWindow *ui;
    StatusBar *m_pStatusBar;
    GLWidget *m_pGLWidget;
    ScatterWidget *m_pScatterWidget;
    QString m_testName;//记录实验名称

    ConfigCmdPacket m_configCmd;//发送配置信息的线程
    QThread m_configCmdThread;
    ForwordCmdPacket m_forwordCmd;//发送给转发软件实验信息的线程
    QThread m_forwordCmdThread;
    RecvUpPacket m_upPacket;//接收上行帧的线程
    QThread m_upPacketThread;
    ParseData m_parseData;//解算数据的线程
    QThread m_parseDataThread;
    RecvResolvResult m_resolvResult;//处理回传图像信息的线程
    QThread m_resolvResultThread;
    ReceivePulseData m_pulseData; //处理脉压图的线程
    QThread m_pulseDataThread;

    PulseScene *m_pPulseScene; //脉压视图
};

#endif // MAINWINDOW_H
