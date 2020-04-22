#include "ReceivePulseData.h"
#include <QByteArray>
#include <QDebug>

ReceivePulseData::ReceivePulseData(QObject *parent) :
    QObject(parent)
{
    m_bIsPulseHead = true;
    m_pPulseServer = new QTcpServer(this);
    m_pPulseServer->listen(QHostAddress::Any, 8900);
    connect(m_pPulseServer, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

ReceivePulseData::~ReceivePulseData()
{
    if(m_pPulseServer->isListening())
    {
        m_pPulseServer->close();
    }
}

void ReceivePulseData::onNewConnection()
{
    qDebug() << "pulse data coming";
    m_buf.clear();
    memset(&m_header, 0, sizeof(m_header));
    m_bIsPulseHead = true;
    m_pPulseSocket = m_pPulseServer->nextPendingConnection();
    connect(m_pPulseSocket, SIGNAL(disconnected()), m_pPulseSocket, SLOT(deleteLater()));
    connect(m_pPulseSocket, SIGNAL(readyRead()), this, SLOT(onPulseReadyRead()));
}

void ReceivePulseData::onPulseReadyRead()
{
    m_buf.append(m_pPulseSocket->readAll());
    if(m_buf.size() > sizeof(m_header) && m_bIsPulseHead)
    {
        memcpy(&m_header, m_buf.data(), sizeof(m_header));
        m_bIsPulseHead = false;
    }
    if(!m_bIsPulseHead && (m_header.flag != PULSE_FLAG))
    {
        m_buf.clear();
        return;
    }

    if((PULSE_FLAG == m_header.flag) && (m_buf.size() >= m_header.fileSize)) //数据读取完成
    {
        PulseCompressionImage pulse;
        QImage *image = pulse.drawImage((float*)(m_buf.data() + sizeof(m_header)), m_header.row, m_header.col);
        emit pulseImageUpdated(image, m_header.row, m_header.col);
        m_buf.clear();
        return;
    }
}
