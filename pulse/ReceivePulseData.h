#ifndef RECEIVEPULSEDATA_H
#define RECEIVEPULSEDATA_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "PulseCompressionImage.h"
#include "../Packet.h"

class ReceivePulseData : public QObject
{
    Q_OBJECT
public:
    explicit ReceivePulseData(QObject *parent = 0);
    ~ReceivePulseData();
signals:
    void pulseImageUpdated(QImage *, int, int);

public slots:
    void onNewConnection();
    void onPulseReadyRead();

private:
    QTcpServer *m_pPulseServer;
    QTcpSocket *m_pPulseSocket;
    PulseHeader m_header;
    bool m_bIsPulseHead;
    QByteArray m_buf;
};

#endif // RECEIVEPULSEDATA_H
