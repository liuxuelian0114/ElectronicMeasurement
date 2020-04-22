#ifndef RECVRESOLVRESULT_H
#define RECVRESOLVRESULT_H

#include <QObject>
#include <QFile>
#include "Packet.h"
class QTcpServer;
class QTcpSocket;

class RecvResolvResult : public QObject
{
    Q_OBJECT
public:
    explicit RecvResolvResult(QObject *parent = 0);
    ~RecvResolvResult();

signals:
    void rcsDataupdated();
    void d3DataUpdated(D3Para);

public slots:

private slots:
    void onRcsNewConnection();
    void onRcsReadyRead();

    void on3dNewConnection();
    void on3dReadyRead();

private:
    QTcpServer *m_p3dServer;
    QTcpSocket *m_p3dSocket;
    QFile m_3dFile;

    QTcpServer *m_pRCSServer;
    QTcpSocket *m_pRcsSocket;

    bool m_bIs3dHead;
    QByteArray m_3dBuf;
    D3Header m_3dHeader;

    bool m_bIsRcsHead;
    QByteArray m_rcsBuf;
    RcsHeader m_rcsHeader;
};

#endif // RECVRESOLVRESULT_H
