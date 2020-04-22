#ifndef CONFIGCMDPACKET_H
#define CONFIGCMDPACKET_H

#include <QObject>
#include <QTimer>

class QUdpSocket;

class ConfigCmdPacket : public QObject
{
    Q_OBJECT
public:
    explicit ConfigCmdPacket(QObject *parent = 0);
    ~ConfigCmdPacket();

signals:

public slots:
    void onCmdChanged(bool state, const QStringList &checkArgs, const QStringList &cmdArgs);
    //处理射频功能按钮被点击后通过UDP发送对应控制码给另一方
    void onRFStarted(ushort start, ushort end, ushort power);
    void onRFStopped();
    void onRFSelfTest(ushort state);
    void onRFReset(ushort state);
    void onRFAdjust(ushort state);
    //处理伺服功能按钮被点击后通过UDP发送对应控制码给另一方
    void onServoContinue(const QStringList &list);
    void onServoContinueTimeout();

    void onServoDisContinue(const QStringList &list);

    void onServoReturnRun(const QStringList &list);
    void onServoReturnRunTimeOut();

    void onServoPauseRun();
    void onServoUnPauseRun();

    void onServoStopRun();
    void onServoStopRunTimeOut();

    //射频的正常采集和包络采集
    void onRFNormalCollect();
    void onRFEnvelopeCollect();

private:
    void sentDatagrame(const char *datagram, const int length);

private:
    QUdpSocket *m_pUdpSocket;
    QTimer *m_pTimer;
    QTimer *m_pServoContinueTimer;
    QTimer *m_pServoReturnRunTimer;
};

#endif // CONFIGCMDPACKET_H
