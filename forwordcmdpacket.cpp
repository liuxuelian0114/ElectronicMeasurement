#include <QTcpSocket>
#include <QThread>
#include <QDebug>
#include <QtEndian>
#include <QHostAddress>
#include <QMessageBox>
#include <QWidget>
#include <QUdpSocket>

#include "forwordcmdpacket.h"
#include "Packet.h"
#include "runtimeconfig.h"
#include "localconfig.h"
#include "dbinterface.h"

ForwordCmdPacket::ForwordCmdPacket(QObject *parent) :
    QObject(parent)
{
    m_pTcpSocket = new QTcpSocket(this);
    connect(m_pTcpSocket,SIGNAL(disconnected()), this, SLOT(onDisConnected()));

    m_pUdpSocket = new QUdpSocket(this);
    m_pUdpSocket->bind(QHostAddress::Any, 10001, QAbstractSocket::ShareAddress);
    connect(m_pUdpSocket, SIGNAL(readyRead()), this, SLOT(onUdpReadyRead()));
}

ForwordCmdPacket::~ForwordCmdPacket()
{
    if(m_pTcpSocket)
    {
        m_pTcpSocket->close();
        delete m_pTcpSocket;
        m_pTcpSocket = Q_NULLPTR;
    }
}

void ForwordCmdPacket::onTestStart(const int &model, const QString &name)
{
    if(QAbstractSocket::ConnectedState == m_pTcpSocket->state())
    {
    //    connect(m_pTcpSocket, SIGNAL(disconnected()),m_pTcpSocket, SLOT(deleteLater()));
        this->chooseToSend(model, name);
    }
    else if(QAbstractSocket::UnconnectedState == m_pTcpSocket->state())
    {

        m_pTcpSocket->connectToHost(QHostAddress(localConfig.getForwordIp()), 9001);
        bool ok = m_pTcpSocket->waitForConnected(5000);
        if(!ok)
        {
            //TODo:界面是否提示错误信息
            qDebug() << "=========" <<m_pTcpSocket->errorString();
            return;
        }
        else
        {
            //ToDo::连接数据转发软件成功，是否提示
            this->chooseToSend(model, name);
        }
    }
}

void ForwordCmdPacket::OnConnected()
{
    qDebug() << "ForwordCmdPacket Tcp is connected";
}

void ForwordCmdPacket::onDisConnected()
{
    qDebug() <<" ForwordCmdPacket is DisConnected ";
}

void ForwordCmdPacket::onUdpReadyRead()
{
    qDebug() << QStringLiteral("接收结束Udp............");
    QByteArray buffer;
    while(m_pUdpSocket->hasPendingDatagrams())
    {
        buffer.resize(m_pUdpSocket->pendingDatagramSize());
        m_pUdpSocket->readDatagram(buffer.data(), buffer.size());
        m_datagram.append(buffer);
        if(sizeof(EmsPacket) <= m_datagram.size())
        {
            EmsPacket packet;
            memcpy((char *)&packet, m_datagram.data(), sizeof(EmsPacket));
            packet.header = qFromBigEndian(packet.header);
            packet.tail = qFromBigEndian(packet.tail);
            packet.model = qFromBigEndian(packet.model);
            packet.checkCRC = qFromBigEndian(packet.checkCRC);
            //检验上行帧
            qDebug() << "=========";
            qDebug() << packet.header;
            qDebug() << packet.model;
            qDebug() << packet.checkCRC;
            qDebug() << packet.tail;

            if(packet.checkCRC == qChecksum(reinterpret_cast<char *>(&packet) + sizeof(packet.header),
                                               sizeof(packet.model)))
            {

            }
            else
            {
                 qDebug() << QStringLiteral("EmsPacket 校验错误");
                 return;
            }
            if(packet.header == EMS_PACKET_HEADER && packet.tail == EMS_PACKET_TAIL)
            {
                if(packet.model == EMS_PACKET_MODEL1)
                {
                    qDebug() << QStringLiteral("下载完成");
                    emit playbackFinished(EMS_PACKET_MODEL1);
                    localConfig.setPlaybackMode(true);
                }
                if(packet.model == EMS_PACKET_MODEL2)
                {
                    qDebug() << QStringLiteral("下载失败");
                    emit playbackFinished(EMS_PACKET_MODEL2);
                    localConfig.setPlaybackMode(true);
                }

            }
            qDebug() << "=========";

            m_datagram.remove(0, sizeof(EmsPacket));
        }
    }
}

void ForwordCmdPacket::forwardStartTestArgs(QString name)
{
    QString sendData(localConfig.getStartArgs() + QString("/,/"));
    QStringList para;
    dbInterface.getTablePara(para, QString("para_arg"));
    para.takeFirst();
    for(int i = 0; i < para.size(); i++)
    {
        sendData.append(para.at(i) + ",");
    }

    ForwordPacket forWordPacket;
    memset(&forWordPacket, 0, sizeof(forWordPacket));
    forWordPacket.header = FORWORD_PACKET_HEADER;
    forWordPacket.model = FORWORD_PACKET_MODEL0;
    memcpy(forWordPacket.name, name.toLocal8Bit().constData(), name.toLocal8Bit().length());
    forWordPacket.tail = FORWORD_PACKET_TAIL;
    forWordPacket.argsLength = sendData.toUtf8().length();

    forWordPacket.checkCRC = qChecksum(reinterpret_cast<char *>(&forWordPacket) + sizeof(forWordPacket.header),
                                       sizeof(forWordPacket.model) + sizeof(forWordPacket.name) + sizeof(forWordPacket.argsLength));

    forWordPacket.header = qToBigEndian(forWordPacket.header);
    forWordPacket.tail = qToBigEndian(forWordPacket.tail);
    forWordPacket.checkCRC = qToBigEndian(forWordPacket.checkCRC);
    forWordPacket.argsLength = qToBigEndian(forWordPacket.argsLength);

    char *cmd = reinterpret_cast<char *>(&forWordPacket);
    int length = sizeof(forWordPacket);

    //ToDo::错误信息怎么处理？
    qDebug() << "forword cmd start sent to forword: " << m_pTcpSocket->write(cmd, length);
    m_pTcpSocket->waitForBytesWritten(500);

    qDebug() << "forword cmd para sent to forword: " << m_pTcpSocket->write(sendData.toUtf8().data(), sendData.toUtf8().size());
    m_pTcpSocket->waitForBytesWritten(500);
}

void ForwordCmdPacket::forwardPalybackTestArgs(QString name)
{
    ForwordPacket forWordPacket;
    memset(&forWordPacket, 0, sizeof(forWordPacket));
    forWordPacket.header = FORWORD_PACKET_HEADER;
    forWordPacket.model = FORWORD_PACKET_MODEL1;
    memcpy(forWordPacket.name, name.toLocal8Bit().constData(), name.toLocal8Bit().length());
    forWordPacket.tail = FORWORD_PACKET_TAIL;
    forWordPacket.argsLength = localConfig.getPlaybackAddress().toUtf8().length();
    forWordPacket.checkCRC = qChecksum(reinterpret_cast<char *>(&forWordPacket) + sizeof(forWordPacket.header),
                                       sizeof(forWordPacket.model) + sizeof(forWordPacket.name) + sizeof(forWordPacket.argsLength));


    forWordPacket.header = qToBigEndian(forWordPacket.header);
    forWordPacket.tail = qToBigEndian(forWordPacket.tail);
    forWordPacket.checkCRC = qToBigEndian(forWordPacket.checkCRC);
    forWordPacket.argsLength = qToBigEndian(forWordPacket.argsLength);

    char *cmd = reinterpret_cast<char *>(&forWordPacket);
    int length = sizeof(forWordPacket);

    //ToDo::错误信息怎么处理？
    qDebug() << "forword cmd palyback sent to forword: " << m_pTcpSocket->write(cmd, length);
    m_pTcpSocket->waitForBytesWritten(500);
    qDebug() << "forword cmd palybackAddress sent to forword: " << m_pTcpSocket->write(localConfig.getPlaybackAddress().toUtf8().data()
                                                                            ,localConfig.getPlaybackAddress().toUtf8().size());
    m_pTcpSocket->waitForBytesWritten(500);
//    qDebug() << QStringLiteral("回放实验名：") << (char*)&(forWordPacket.name);
//    qDebug() << QStringLiteral("回放路径：") << localConfig.getPlaybackAddress().toUtf8().data();
}


void ForwordCmdPacket::forwardStopTestRecordArgs(QString name)
{

    ForwordPacket forWordPacket;
    memset(&forWordPacket, 0, sizeof(forWordPacket));
    forWordPacket.header = FORWORD_PACKET_HEADER;
    forWordPacket.model = FORWORD_PACKET_MODEL2;
    memcpy(forWordPacket.name, name.toLocal8Bit().constData(), name.toLocal8Bit().length());
    forWordPacket.tail = FORWORD_PACKET_TAIL;
    forWordPacket.argsLength = localConfig.getReport().toUtf8().size();
    forWordPacket.checkCRC = qChecksum(reinterpret_cast<char *>(&forWordPacket) + sizeof(forWordPacket.header),
                                       sizeof(forWordPacket.model) + sizeof(forWordPacket.name) + sizeof(forWordPacket.argsLength));

    forWordPacket.header = qToBigEndian(forWordPacket.header);
    forWordPacket.tail = qToBigEndian(forWordPacket.tail);
    forWordPacket.checkCRC = qToBigEndian(forWordPacket.checkCRC);
    forWordPacket.argsLength = qToBigEndian(forWordPacket.argsLength);

    char *cmd = reinterpret_cast<char *>(&forWordPacket);
    int length = sizeof(forWordPacket);

    //ToDo::错误信息怎么处理？
    qDebug() << "forword cmd stop sent to forword: " << m_pTcpSocket->write(cmd, length);
    m_pTcpSocket->waitForBytesWritten(500);
    qDebug() << "forword cmd report sent to forword: " << m_pTcpSocket->write(localConfig.getReport().toUtf8().data()
                                                                       , localConfig.getReport().toUtf8().size());
    m_pTcpSocket->waitForBytesWritten(500);
}

void ForwordCmdPacket::forwardBatArgs(QString name)
{
    ForwordPacket forWordPacket;
    memset(&forWordPacket, 0, sizeof(forWordPacket));
    forWordPacket.header = FORWORD_PACKET_HEADER;
    forWordPacket.model = FORWORD_PACKET_MODEL3;
    memcpy(forWordPacket.name, name.toLocal8Bit().constData(), name.toLocal8Bit().length());
    forWordPacket.tail = FORWORD_PACKET_TAIL;
    forWordPacket.argsLength = localConfig.getBatType().toUtf8().size();
    forWordPacket.checkCRC = qChecksum(reinterpret_cast<char *>(&forWordPacket) + sizeof(forWordPacket.header),
                                       sizeof(forWordPacket.model) + sizeof(forWordPacket.name) + sizeof(forWordPacket.argsLength));


    forWordPacket.header = qToBigEndian(forWordPacket.header);
    forWordPacket.tail = qToBigEndian(forWordPacket.tail);
    forWordPacket.checkCRC = qToBigEndian(forWordPacket.checkCRC);
    forWordPacket.argsLength = qToBigEndian(forWordPacket.argsLength);

    char *cmd = reinterpret_cast<char *>(&forWordPacket);
    int length = sizeof(forWordPacket);

    //ToDo::错误信息怎么处理？
    qDebug() << "forword cmd stop sent to forword: " << m_pTcpSocket->write(cmd, length);
    m_pTcpSocket->waitForBytesWritten(500);
    qDebug() << "forword cmd report sent to forword: " << m_pTcpSocket->write(localConfig.getBatType().toUtf8().data()
                                                                       , localConfig.getBatType().toUtf8().size());
    m_pTcpSocket->waitForBytesWritten(500);
//    qDebug() <<"\\-------->" << localConfig.getBatType().toUtf8().data();
}

void ForwordCmdPacket::forwardProduceReportArgs(QString name)
{
    ForwordPacket forWordPacket;
    memset(&forWordPacket, 0, sizeof(forWordPacket));
    forWordPacket.header = FORWORD_PACKET_HEADER;
    forWordPacket.model = FORWORD_PACKET_MODEL4;
    memcpy(forWordPacket.name, name.toLocal8Bit().constData(), name.toLocal8Bit().length());
    forWordPacket.tail = FORWORD_PACKET_TAIL;
    forWordPacket.argsLength = 0;
    forWordPacket.checkCRC = qChecksum(reinterpret_cast<char *>(&forWordPacket) + sizeof(forWordPacket.header),
                                       sizeof(forWordPacket.model) + sizeof(forWordPacket.name) + sizeof(forWordPacket.argsLength));


    forWordPacket.header = qToBigEndian(forWordPacket.header);
    forWordPacket.tail = qToBigEndian(forWordPacket.tail);
    forWordPacket.checkCRC = qToBigEndian(forWordPacket.checkCRC);
    forWordPacket.argsLength = qToBigEndian(forWordPacket.argsLength);

    char *cmd = reinterpret_cast<char *>(&forWordPacket);
    int length = sizeof(forWordPacket);

    //ToDo::错误信息怎么处理？
    qDebug() << "forword cmd ProduceReportArgs sent to forword: " << m_pTcpSocket->write(cmd, length);
    m_pTcpSocket->waitForBytesWritten(500);
}

void ForwordCmdPacket::forwardAddReportArgs(QString name)
{
    ForwordPacket forWordPacket;
    memset(&forWordPacket, 0, sizeof(forWordPacket));
    forWordPacket.header = FORWORD_PACKET_HEADER;
    forWordPacket.model = FORWORD_PACKET_MODEL5;
    memcpy(forWordPacket.name, name.toLocal8Bit().constData(), name.toLocal8Bit().length());
    forWordPacket.tail = FORWORD_PACKET_TAIL;
    forWordPacket.argsLength = 0;
    forWordPacket.checkCRC = qChecksum(reinterpret_cast<char *>(&forWordPacket) + sizeof(forWordPacket.header),
                                       sizeof(forWordPacket.model) + sizeof(forWordPacket.name) + sizeof(forWordPacket.argsLength));


    forWordPacket.header = qToBigEndian(forWordPacket.header);
    forWordPacket.tail = qToBigEndian(forWordPacket.tail);
    forWordPacket.checkCRC = qToBigEndian(forWordPacket.checkCRC);
    forWordPacket.argsLength = qToBigEndian(forWordPacket.argsLength);

    char *cmd = reinterpret_cast<char *>(&forWordPacket);
    int length = sizeof(forWordPacket);
    //ToDo::错误信息怎么处理？
    qDebug() << "forword cmd palyback sent to forword: " << m_pTcpSocket->write(cmd, length);
    m_pTcpSocket->waitForBytesWritten(500);
}

void ForwordCmdPacket::chooseToSend(const int &model, const QString &name)
{
    if(0 == model)
    {
        forwardStartTestArgs(name);
    }
    else if(1 == model)
    {
        forwardPalybackTestArgs(name);
    }
    else if(2 == model)
    {
        forwardStopTestRecordArgs(name);
    }
    else if(3 == model)
    {
        forwardBatArgs(name);
    }
    else if(4 == model)
    {
        forwardProduceReportArgs(name);
    }
    else if(5 == model)
    {
        forwardAddReportArgs(name);
    }
    else
    {
        return;
    }
}
