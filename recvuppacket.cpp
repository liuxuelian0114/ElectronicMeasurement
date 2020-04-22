#include <QUdpSocket>
#include <QThread>
#include <QDebug>
#include <QtEndian>
#include <QFile>
#include <QDataStream>

#include "recvuppacket.h"
#include "Packet.h"
#include "runtimeconfig.h"

RecvUpPacket::RecvUpPacket(QObject *parent) :
    QObject(parent)
{
    m_pUdpSocket = new QUdpSocket(this);
    m_pUdpSocket->bind(UP_PACKET_PORT);

    connect(m_pUdpSocket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

    m_isStartParseData = true;
}

RecvUpPacket::~RecvUpPacket()
{

}

void RecvUpPacket::onStartParseData(bool ok)
{
    //true开始解析数据   false结束解析数据
    m_isStartParseData = ok;
}

void RecvUpPacket::dealData()
{
    if(false == m_isStartParseData)
    {
        return;
    }
    //打开解帧文件的描述符


    UpPacket upPacket;
    memcpy((char *)&upPacket, m_datagram.data(), sizeof(UpPacket));

//    qDebug() << "on RecvUpPacket dealData, upPacket header " << upPacket.header;
//     qDebug() << "on RecvUpPacket dealData, upPacket tail " << upPacket.tail;

    upPacket.header = qFromBigEndian(upPacket.header);
    upPacket.tail = qFromBigEndian(upPacket.tail);
    //检验上行帧

    if(upPacket.header == UP_PACKET_HEADER && upPacket.tail == UP_PACKET_TAIL)
    {
        //将4k数据发送给数据解析
        emit dataChanged(QByteArray(reinterpret_cast<char *>(upPacket.data), sizeof(upPacket.data)));
        int *pInt = (int *)(((UpPacket*)&upPacket));
        for(int i = 0; i < 2064; i++)
        {
            pInt[i] = qFromBigEndian(pInt[i]);
        }
        //提取伺服状态上报帧
        ServoReportPacket servoPacket;
        memcpy(reinterpret_cast<char *>(&servoPacket), &(upPacket.servoState), sizeof(servoPacket));
        servoPacket.header = qFromBigEndian(servoPacket.header);
        servoPacket.type = qFromBigEndian(servoPacket.type);
        servoPacket.state = qFromBigEndian(servoPacket.state);
        servoPacket.nowX = qFromBigEndian(servoPacket.nowX);
        servoPacket.nowY = qFromBigEndian(servoPacket.nowY);
        servoPacket.sportTime = qFromBigEndian(servoPacket.sportTime);
        servoPacket.checkCRC = qFromBigEndian(servoPacket.checkCRC);
        servoPacket.tail = qFromBigEndian(servoPacket.tail);

        qDebug() << "servoPacket.header--->" << servoPacket.nowX << "  servoPacket.nowY--->"<< servoPacket.tail;
//      数据采集模块实际依然采用7b7b做的校验,协议中已经改为5d5d，
        servoPacket.header = 0x7b7b;
        //检验伺服上报帧校验码是否一致
//        qDebug() << "on RecvUpPacket dealData, servo check: " << servoPacket.checkCRC
//                 << runTimeConfig.checkBCC16(reinterpret_cast<short *>(&servoPacket),
//                                                sizeof(servoPacket) - sizeof(servoPacket.tail) - sizeof(servoPacket.checkCRC));


        if(servoPacket.checkCRC == g_runTimeConfig.checkBCC16(reinterpret_cast<short *>(&servoPacket),
                                                                  sizeof(ServoReportPacket) - sizeof(servoPacket.tail) - sizeof(servoPacket.checkCRC)))
        {
//            qDebug() << "RecvUpPacket on checkCRC OK!!! " ;
            emit servoStateChanged(servoPacket.state);
            emit servoCoorChanged(servoPacket.nowX, servoPacket.nowY);
            emit servoTimeChanged(servoPacket.sportTime);
        }
        else
        {
            qDebug() << QStringLiteral("RecvUpPacket类中：伺服校验错误") ;

        }

        //提取射频状态上报帧，射频的校验待定
        RFReportPacket RFPacket;
        memcpy(&RFPacket, upPacket.RFState, sizeof(upPacket.RFState));
        RFPacket.header = qFromBigEndian(RFPacket.header);
        RFPacket.data = qFromBigEndian(RFPacket.data);
        RFPacket.tail = qFromBigEndian(RFPacket.tail);

//        检验射频上报帧校验码是否一致
//        qDebug() << "on RecvUpPacket dealData, RF check: " << RFPacket.checkBCC
//                 << runTimeConfig.checkBCC8(reinterpret_cast<char *>(&(RFPacket.registerAddr)),
//                                           sizeof(RFPacket.registerAddr) + sizeof(RFPacket.data));



        if(RFPacket.checkBCC == g_runTimeConfig.checkBCC8(reinterpret_cast<char *>(&(RFPacket.registerAddr)),
                                                        sizeof(RFPacket.registerAddr) + sizeof(RFPacket.data)))
        {
//            qDebug() << "RecvUpPacket on RFPacket.checkBCC ok !!" ;
            emit RFStateChanged(RFPacket.registerAddr, RFPacket.data);
        }
        else
        {
            qDebug() << QStringLiteral("RecvUpPacket类中：射频校验错误") ;
        }
    }
}

void RecvUpPacket::onReadyRead()
{
//    qDebug() << "RecvUpPacket " << "has data: " << m_pUdpSocket->hasPendingDatagrams() << "data size: " << m_pUdpSocket->pendingDatagramSize();
    QByteArray buffer;
    while(m_pUdpSocket->hasPendingDatagrams())
    {
        buffer.resize(m_pUdpSocket->pendingDatagramSize());
        m_pUdpSocket->readDatagram(buffer.data(), buffer.size());

        m_datagram.append(buffer);

        if(sizeof(UpPacket) <= m_datagram.size())
        {
            dealData();
            m_datagram.remove(0, sizeof(UpPacket));
        }
    }
}
