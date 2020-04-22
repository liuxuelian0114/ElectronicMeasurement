#ifndef FORWORDCMDPACKET_H
#define FORWORDCMDPACKET_H

#include <QObject>

class QTcpSocket;
class QUdpSocket;

class ForwordCmdPacket : public QObject
{
    Q_OBJECT
public:
    explicit ForwordCmdPacket(QObject *parent = 0);
    ~ForwordCmdPacket();

signals:
    void playbackFinished(unsigned char model);

public slots:
    void onTestStart(const int &model, const QString &name);

private slots:
    void OnConnected();
    void onDisConnected();
    void onUdpReadyRead();

private:
    void forwardStartTestArgs(QString name);
    void forwardPalybackTestArgs(QString name);
    void forwardStopTestRecordArgs(QString name);
    void forwardBatArgs(QString name);
    void forwardProduceReportArgs(QString name);
    void forwardAddReportArgs(QString name);
    void chooseToSend(const int &model, const QString &name);

private:
    QTcpSocket *m_pTcpSocket;
    QUdpSocket *m_pUdpSocket;
    QByteArray m_datagram;
};

#endif // FORWORDCMDPACKET_H
