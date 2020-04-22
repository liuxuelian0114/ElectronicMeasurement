#ifndef RECVUPPACKET_H
#define RECVUPPACKET_H

#include <QObject>

class QUdpSocket;
class QFile;
#include <QDataStream>
#include <QFile>

class RecvUpPacket : public QObject
{
    Q_OBJECT
public:
    explicit RecvUpPacket(QObject *parent = 0);
    ~RecvUpPacket();

signals:
    void dataChanged(QByteArray data);
    void RFStateChanged(uchar rAddr, ushort data);
    void servoStateChanged(ushort state);
    void servoCoorChanged(unsigned int x, unsigned int y);
    void servoTimeChanged(uint time);

public slots:
    void onStartParseData(bool ok);

private:
    void dealData();

private slots:
    void onReadyRead();

private:
    QUdpSocket *m_pUdpSocket;
    QByteArray m_datagram;
    bool m_isStartParseData;//true开始解析数据   false结束解析数据
};

#endif // RECVUPPACKET_H
