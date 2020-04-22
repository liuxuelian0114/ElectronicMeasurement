#include <QUdpSocket>
#include <QDebug>
#include <QtEndian>
#include <QHostAddress>
#include <QStringList>
#include <QThread>
#include <QTime>

#include "configcmdpacket.h"
#include "dbinterface.h"
#include "Packet.h"
#include "runtimeconfig.h"
#include "localconfig.h"

ConfigCmdPacket::ConfigCmdPacket(QObject *parent) :
    QObject(parent)
{
    m_pUdpSocket = nullptr;
    m_pTimer = nullptr;
    m_pServoContinueTimer = nullptr;
    m_pServoReturnRunTimer = nullptr;
}

ConfigCmdPacket::~ConfigCmdPacket()
{
    if(nullptr != m_pUdpSocket)
    {
        m_pUdpSocket->deleteLater();
    }
    if(nullptr != m_pTimer)
    {
        m_pTimer->deleteLater();
    }
    if(nullptr != m_pServoContinueTimer)
    {
        m_pServoContinueTimer->deleteLater();
    }
    if(nullptr != m_pServoReturnRunTimer)
    {
        m_pServoReturnRunTimer->deleteLater();
    }
}

void ConfigCmdPacket::onCmdChanged(bool state, const QStringList &checkArgs, const QStringList &cmdArgs)
{
//    qDebug() << "+++++++++++++";
//        QString str;
//        foreach (str, checkArgs) {
//            qDebug()<< str;
//        }

//        QString strh;
//        foreach (strh, cmdArgs) {
//            qDebug()<< strh;
//        }
    if(state)
    {
        onRFStopped();
        QThread::sleep(2);
        if(checkArgs.at(0).toUInt() == 2)
        {
            quint32 garther = cmdArgs.at(0).toUInt();

            if(garther == 4)
            {
                onRFEnvelopeCollect();
                onRFStarted(cmdArgs.at(1).toUShort(), cmdArgs.at(2).toUShort(), cmdArgs.at(3).toUShort());
            }
            if((garther == 0) ||(garther == 1) ||(garther == 2) ||(garther == 3))
            {
                onRFNormalCollect();
                onRFStarted(cmdArgs.at(1).toUShort(), cmdArgs.at(2).toUShort(), cmdArgs.at(3).toUShort());
            }
        }
        else
        {
            onRFStarted(cmdArgs.at(1).toUShort(), cmdArgs.at(2).toUShort(), cmdArgs.at(3).toUShort());
        }
        if(checkArgs.at(1).toUInt() == 2)
        {
            onRFSelfTest(cmdArgs.at(4).toUShort());
        }
        if(checkArgs.at(2).toUInt() == 2)
        {
            onRFReset(cmdArgs.at(5).toUShort());
        }
        if(checkArgs.at(3).toUInt() == 2)
        {
            onRFAdjust(cmdArgs.at(6).toUShort());
        }
    }
    else
    {
        onRFStopped();
    }
}

void ConfigCmdPacket::onRFStarted(ushort start, ushort end, ushort power)
{
    //打包发送射频开始码
    RFConfigPacket RFPacket;
    memset(&RFPacket, 0, sizeof(RFPacket));
    RFPacket.header = RF_CONFIG_HEADER;
    RFPacket.tail = RF_CONFIG_TAIL;
    RFPacket.header = qToBigEndian(RFPacket.header);
    RFPacket.tail = qToBigEndian(RFPacket.tail);
    //扫频起点
    RFPacket.registerAddr = 0x04;
    RFPacket.data = start;
    RFPacket.checkBCC = g_runTimeConfig.checkBCC8(reinterpret_cast<char *>(&RFPacket) + sizeof(RFPacket.header),
                                                sizeof(RFPacket.registerAddr) + sizeof(RFPacket.data));
    RFPacket.data = qToBigEndian(RFPacket.data);
    sentDatagrame(reinterpret_cast<char *>(&RFPacket), sizeof(RFPacket));
    //扫频终点
    RFPacket.registerAddr = 0x05;
    RFPacket.data = end;
    RFPacket.checkBCC = g_runTimeConfig.checkBCC8(reinterpret_cast<char *>(&RFPacket) + sizeof(RFPacket.header),
                                                sizeof(RFPacket.registerAddr) + sizeof(RFPacket.data));
    RFPacket.data = qToBigEndian(RFPacket.data);
    QThread::sleep(3);//每一包命令间隔3s以便底层处理
    sentDatagrame(reinterpret_cast<char *>(&RFPacket), sizeof(RFPacket));
    //功率
    RFPacket.registerAddr = 0x06;
    RFPacket.data = power;
    RFPacket.checkBCC = g_runTimeConfig.checkBCC8(reinterpret_cast<char *>(&RFPacket) + sizeof(RFPacket.header),
                                                sizeof(RFPacket.registerAddr) + sizeof(RFPacket.data));
    RFPacket.data = qToBigEndian(RFPacket.data);
    QThread::sleep(3);//每一包命令间隔3s以便底层处理
    sentDatagrame(reinterpret_cast<char *>(&RFPacket), sizeof(RFPacket));
    //开始工作
    RFPacket.registerAddr = 0x00;
    RFPacket.data = 1;
    RFPacket.checkBCC = g_runTimeConfig.checkBCC8(reinterpret_cast<char *>(&RFPacket) + sizeof(RFPacket.header),
                                                sizeof(RFPacket.registerAddr) + sizeof(RFPacket.data));
    RFPacket.data = qToBigEndian(RFPacket.data);
    QThread::sleep(3);//每一包命令间隔3s以便底层处理
    sentDatagrame(reinterpret_cast<char *>(&RFPacket), sizeof(RFPacket));
}

void ConfigCmdPacket::onRFStopped()
{
    //打包发送射频停止码
    RFConfigPacket RFPacket;
    memset(&RFPacket, 0, sizeof(RFPacket));
    RFPacket.header = RF_CONFIG_HEADER;
    RFPacket.tail = RF_CONFIG_TAIL;
    RFPacket.header = qToBigEndian(RFPacket.header);
    RFPacket.tail = qToBigEndian(RFPacket.tail);
    RFPacket.registerAddr = 0x00;
    RFPacket.data = 0;
    RFPacket.checkBCC = g_runTimeConfig.checkBCC8(reinterpret_cast<char *>(&RFPacket) + sizeof(RFPacket.header),
                                                sizeof(RFPacket.registerAddr) + sizeof(RFPacket.data));
    RFPacket.data = qToBigEndian(RFPacket.data);
    sentDatagrame(reinterpret_cast<char *>(&RFPacket), sizeof(RFPacket));
}

void ConfigCmdPacket::onRFSelfTest(ushort state)
{
    //打包发送射频自检码
    RFConfigPacket RFPacket;
    memset(&RFPacket, 0, sizeof(RFPacket));
    RFPacket.header = RF_CONFIG_HEADER;
    RFPacket.tail = RF_CONFIG_TAIL;
    RFPacket.header = qToBigEndian(RFPacket.header);
    RFPacket.tail = qToBigEndian(RFPacket.tail);
    RFPacket.registerAddr = 0x01;
    RFPacket.data = state;
    RFPacket.checkBCC = g_runTimeConfig.checkBCC8(reinterpret_cast<char *>(&RFPacket) + sizeof(RFPacket.header),
                                                sizeof(RFPacket.registerAddr) + sizeof(RFPacket.data));
    RFPacket.data = qToBigEndian(RFPacket.data);
    sentDatagrame(reinterpret_cast<char *>(&RFPacket), sizeof(RFPacket));
}

void ConfigCmdPacket::onRFReset(ushort state)
{
    //打包发送射频复位码
    RFConfigPacket RFPacket;
    memset(&RFPacket, 0, sizeof(RFPacket));
    RFPacket.header = RF_CONFIG_HEADER;
    RFPacket.tail = RF_CONFIG_TAIL;
    RFPacket.header = qToBigEndian(RFPacket.header);
    RFPacket.tail = qToBigEndian(RFPacket.tail);
    RFPacket.registerAddr = 0x02;
    RFPacket.data = state;
    RFPacket.checkBCC = g_runTimeConfig.checkBCC8(reinterpret_cast<char *>(&RFPacket) + sizeof(RFPacket.header),
                                                sizeof(RFPacket.registerAddr) + sizeof(RFPacket.data));
    RFPacket.data = qToBigEndian(RFPacket.data);
    sentDatagrame(reinterpret_cast<char *>(&RFPacket), sizeof(RFPacket));
}

void ConfigCmdPacket::onRFAdjust(ushort state)
{
    //打包发送射频校验码
    RFConfigPacket RFPacket;
    memset(&RFPacket, 0, sizeof(RFPacket));
    RFPacket.header = RF_CONFIG_HEADER;
    RFPacket.tail = RF_CONFIG_TAIL;
    RFPacket.header = qToBigEndian(RFPacket.header);
    RFPacket.tail = qToBigEndian(RFPacket.tail);
    RFPacket.registerAddr = 0x03;
    RFPacket.data = state;
    RFPacket.checkBCC = g_runTimeConfig.checkBCC8(reinterpret_cast<char *>(&RFPacket) + sizeof(RFPacket.header),
                                                sizeof(RFPacket.registerAddr) + sizeof(RFPacket.data));
    RFPacket.data = qToBigEndian(RFPacket.data);
    sentDatagrame(reinterpret_cast<char *>(&RFPacket), sizeof(RFPacket));
}

void ConfigCmdPacket::onServoContinue(const QStringList &list)
{
    QStringList args = list;
//    qDebug() << list;
    //打包发送伺服连续运动码
    ServoConfigPacket servoPacket;
    memset(&servoPacket, 0, sizeof(servoPacket));
    servoPacket.header = SERVO_CONFIG_HEADER;
    servoPacket.tail = SERVO_CONFIG_TAIL;
    servoPacket.header = qToBigEndian(servoPacket.header);
    servoPacket.tail = qToBigEndian(servoPacket.tail);

    servoPacket.type = SERVO_CONFIG_TYPE1;
    servoPacket.speedH = (args.takeFirst().toUShort() << 4) | (0x0001);
    servoPacket.speedV = (args.takeFirst().toUShort() << 4) | (0x000F);
    servoPacket.startXY = (args.takeFirst().toULongLong() << 32) | (args.takeFirst().toULongLong());
    servoPacket.endXY = (args.takeFirst().toULongLong() << 32) | (args.takeFirst().toULongLong());
    servoPacket.stepY = args.takeFirst().toUShort();
    servoPacket.checkCRC = g_runTimeConfig.checkBCC16(reinterpret_cast<short *>(&servoPacket),
                                                       sizeof(servoPacket) - sizeof(servoPacket.checkCRC) - sizeof(servoPacket.tail));

//    qDebug() << "onServoContinue -----> " << servoPacket.checkCRC;

    servoPacket.type = qToBigEndian(servoPacket.type);
    servoPacket.speedH = qToBigEndian(servoPacket.speedH);
    servoPacket.speedV = qToBigEndian(servoPacket.speedV);
    servoPacket.startXY = qToBigEndian(servoPacket.startXY);
    servoPacket.endXY = qToBigEndian(servoPacket.endXY);
    servoPacket.stepY = qToBigEndian(servoPacket.stepY);
    servoPacket.checkCRC = qToBigEndian(servoPacket.checkCRC);

    if(m_pServoContinueTimer)
    {
        delete m_pServoContinueTimer;
    }
    m_pServoContinueTimer = new QTimer;
    connect(m_pServoContinueTimer, SIGNAL(timeout()), this, SLOT(onServoContinueTimeout()));
    sentDatagrame(reinterpret_cast<char *>(&servoPacket), sizeof(servoPacket));
    m_pServoContinueTimer->start(2000);
}

void ConfigCmdPacket::onServoContinueTimeout()
{
//    qDebug() << list;
    //打包发送伺服连续运动码
    m_pServoContinueTimer->stop();
    ServoConfigPacket servoPacket;
    memset(&servoPacket, 0, sizeof(servoPacket));
    servoPacket.header = SERVO_CONFIG_HEADER;
    servoPacket.tail = SERVO_CONFIG_TAIL;
    servoPacket.header = qToBigEndian(servoPacket.header);
    servoPacket.tail = qToBigEndian(servoPacket.tail);

    servoPacket.type = SERVO_CONFIG_TYPE1;
    servoPacket.speedH = (servoPacket.speedH << 4) | (0x0000);

    servoPacket.checkCRC = g_runTimeConfig.checkBCC16(reinterpret_cast<short *>(&servoPacket),
                                                       sizeof(servoPacket) - sizeof(servoPacket.checkCRC) - sizeof(servoPacket.tail));

//    qDebug() << "onServoContinue -----> " << servoPacket.checkCRC;

    servoPacket.type = qToBigEndian(servoPacket.type);
    servoPacket.speedH = qToBigEndian(servoPacket.speedH);
    servoPacket.speedV = qToBigEndian(servoPacket.speedV);
    servoPacket.startXY = qToBigEndian(servoPacket.startXY);
    servoPacket.endXY = qToBigEndian(servoPacket.endXY);
    servoPacket.stepY = qToBigEndian(servoPacket.stepY);
    servoPacket.checkCRC = qToBigEndian(servoPacket.checkCRC);

    sentDatagrame(reinterpret_cast<char *>(&servoPacket), sizeof(servoPacket));
}

void ConfigCmdPacket::onServoDisContinue(const QStringList &list)
{
    QStringList args = list;
    //打包发送伺服间断运动码
    ServoDisMotionPacket disMotionPacket;
    memset(&disMotionPacket, 0, sizeof(disMotionPacket));
    disMotionPacket.header = SERVO_CONFIG_HEADER;
    disMotionPacket.tail = SERVO_CONFIG_TAIL;

    disMotionPacket.type = SERVO_CONFIG_TYPE1;
    disMotionPacket.control = (args.takeFirst().toUShort() << 4) | (0x0002);
    //按界面上的参数 此处应该跳过垂直速度这一参数
    ushort speedV = args.takeFirst().toUShort();
    speedV = (speedV << 4) | (0x000f);
    disMotionPacket.startXY = (args.takeFirst().toULongLong() << 32) | (args.takeFirst().toULongLong());
    disMotionPacket.endXY = (args.takeFirst().toULongLong() << 32) | (args.takeFirst().toULongLong());
    disMotionPacket.stepY = args.takeFirst().toUShort();
    disMotionPacket.checkCRC = g_runTimeConfig.checkBCC16(reinterpret_cast<short *>(&disMotionPacket),
                                                       sizeof(disMotionPacket) - sizeof(disMotionPacket.checkCRC) - sizeof(disMotionPacket.tail));

    disMotionPacket.header = qToBigEndian(disMotionPacket.header);
    disMotionPacket.type = qToBigEndian(disMotionPacket.type);
    disMotionPacket.control = qToBigEndian(disMotionPacket.control);
    disMotionPacket.startXY = qToBigEndian(disMotionPacket.startXY);
    disMotionPacket.endXY = qToBigEndian(disMotionPacket.endXY);
    disMotionPacket.stepY = qToBigEndian(disMotionPacket.stepY);
    disMotionPacket.checkCRC = qToBigEndian(disMotionPacket.checkCRC);
    disMotionPacket.tail = qToBigEndian(disMotionPacket.tail);
    sentDatagrame(reinterpret_cast<char *>(&disMotionPacket), sizeof(disMotionPacket));
}

void ConfigCmdPacket::onServoReturnRun(const QStringList &list)
{
    QStringList args = list;
    //打包发送伺服回起点运动码
    ServoConfigPacket servoPacket;
    memset(&servoPacket, 0, sizeof(servoPacket));
    servoPacket.header = SERVO_CONFIG_HEADER;
    servoPacket.tail = SERVO_CONFIG_TAIL;
    servoPacket.header = qToBigEndian(servoPacket.header);
    servoPacket.tail = qToBigEndian(servoPacket.tail);

    servoPacket.type = SERVO_CONFIG_TYPE1;
    servoPacket.speedH = (args.takeFirst().toUShort() << 4) | (0x0003);
    servoPacket.speedV = (args.takeFirst().toUShort() << 4) | (0x000F);
    servoPacket.startXY = (args.takeFirst().toULongLong() << 32) | (args.takeFirst().toULongLong());
    servoPacket.endXY = (args.takeFirst().toULongLong() << 32) | (args.takeFirst().toULongLong());
    servoPacket.stepY = args.takeFirst().toUShort();
    servoPacket.checkCRC = g_runTimeConfig.checkBCC16(reinterpret_cast<short *>(&servoPacket),
                                                       sizeof(servoPacket) - sizeof(servoPacket.checkCRC) - sizeof(servoPacket.tail));

    servoPacket.type = qToBigEndian(servoPacket.type);
    servoPacket.speedH = qToBigEndian(servoPacket.speedH);
    servoPacket.speedV = qToBigEndian(servoPacket.speedV);
    servoPacket.startXY = qToBigEndian(servoPacket.startXY);
    servoPacket.endXY = qToBigEndian(servoPacket.endXY);
    servoPacket.stepY = qToBigEndian(servoPacket.stepY);
    servoPacket.checkCRC = qToBigEndian(servoPacket.checkCRC);

    if(m_pServoReturnRunTimer)
    {
        delete m_pServoReturnRunTimer;
    }
    m_pServoReturnRunTimer = new QTimer;
    connect(m_pServoReturnRunTimer, SIGNAL(timeout()), this, SLOT(onServoReturnRunTimeOut()));
    sentDatagrame(reinterpret_cast<char *>(&servoPacket), sizeof(servoPacket));
    m_pServoReturnRunTimer->start(2000);
}

void ConfigCmdPacket::onServoReturnRunTimeOut()
{
    m_pServoReturnRunTimer->stop();
    ServoConfigPacket servoPacket;
    memset(&servoPacket, 0, sizeof(servoPacket));
    servoPacket.header = SERVO_CONFIG_HEADER;
    servoPacket.tail = SERVO_CONFIG_TAIL;
    servoPacket.header = qToBigEndian(servoPacket.header);
    servoPacket.tail = qToBigEndian(servoPacket.tail);

    servoPacket.type = SERVO_CONFIG_TYPE1;
    servoPacket.speedH = (servoPacket.speedH << 4) | (0x0000);
    servoPacket.checkCRC = g_runTimeConfig.checkBCC16(reinterpret_cast<short *>(&servoPacket),
                                                       sizeof(servoPacket) - sizeof(servoPacket.checkCRC) - sizeof(servoPacket.tail));

    servoPacket.type = qToBigEndian(servoPacket.type);
    servoPacket.speedH = qToBigEndian(servoPacket.speedH);
    servoPacket.speedV = qToBigEndian(servoPacket.speedV);
    servoPacket.startXY = qToBigEndian(servoPacket.startXY);
    servoPacket.endXY = qToBigEndian(servoPacket.endXY);
    servoPacket.stepY = qToBigEndian(servoPacket.stepY);
    servoPacket.checkCRC = qToBigEndian(servoPacket.checkCRC);
    sentDatagrame(reinterpret_cast<char *>(&servoPacket), sizeof(servoPacket));
}

void ConfigCmdPacket::onServoPauseRun()
{
    //打包发送伺服暂停运动码
    ServoConfigPacket servoPacket;
    memset(&servoPacket, 0, sizeof(servoPacket));
    servoPacket.header = SERVO_CONFIG_HEADER;
    servoPacket.tail = SERVO_CONFIG_TAIL;
    servoPacket.header = qToBigEndian(servoPacket.header);
    servoPacket.tail = qToBigEndian(servoPacket.tail);

    servoPacket.type = SERVO_CONFIG_TYPE2;
    servoPacket.speedH = (servoPacket.speedH << 4) | (0x0001);
    servoPacket.checkCRC = g_runTimeConfig.checkBCC16(reinterpret_cast<short *>(&servoPacket),
                                                       sizeof(servoPacket) - sizeof(servoPacket.checkCRC) - sizeof(servoPacket.tail));

    servoPacket.type = qToBigEndian(servoPacket.type);
    servoPacket.speedH = qToBigEndian(servoPacket.speedH);
    servoPacket.speedV = qToBigEndian(servoPacket.speedV);
    servoPacket.startXY = qToBigEndian(servoPacket.startXY);
    servoPacket.endXY = qToBigEndian(servoPacket.endXY);
    servoPacket.stepY = qToBigEndian(servoPacket.stepY);
    servoPacket.checkCRC = qToBigEndian(servoPacket.checkCRC);
    sentDatagrame(reinterpret_cast<char *>(&servoPacket), sizeof(servoPacket));
}

void ConfigCmdPacket::onServoUnPauseRun()
{
    //打包发送伺服解除暂停码
    ServoConfigPacket servoPacket;
    memset(&servoPacket, 0, sizeof(servoPacket));
    servoPacket.header = SERVO_CONFIG_HEADER;
    servoPacket.tail = SERVO_CONFIG_TAIL;
    servoPacket.header = qToBigEndian(servoPacket.header);
    servoPacket.tail = qToBigEndian(servoPacket.tail);

    servoPacket.type = SERVO_CONFIG_TYPE2;
    servoPacket.speedH = (servoPacket.speedH << 4) | (0x0002);
    servoPacket.checkCRC = g_runTimeConfig.checkBCC16(reinterpret_cast<short *>(&servoPacket),
                                                       sizeof(servoPacket) - sizeof(servoPacket.checkCRC) - sizeof(servoPacket.tail));

    servoPacket.type = qToBigEndian(servoPacket.type);
    servoPacket.speedH = qToBigEndian(servoPacket.speedH);
    servoPacket.speedV = qToBigEndian(servoPacket.speedV);
    servoPacket.startXY = qToBigEndian(servoPacket.startXY);
    servoPacket.endXY = qToBigEndian(servoPacket.endXY);
    servoPacket.stepY = qToBigEndian(servoPacket.stepY);
    servoPacket.checkCRC = qToBigEndian(servoPacket.checkCRC);
    sentDatagrame(reinterpret_cast<char *>(&servoPacket), sizeof(servoPacket));
}

void ConfigCmdPacket::onServoStopRun()
{
    //打包发送伺服停止运动码
    ServoConfigPacket servoPacket;
    memset(&servoPacket, 0, sizeof(servoPacket));
    servoPacket.header = SERVO_CONFIG_HEADER;
    servoPacket.tail = SERVO_CONFIG_TAIL;
    servoPacket.header = qToBigEndian(servoPacket.header);
    servoPacket.tail = qToBigEndian(servoPacket.tail);

    servoPacket.type = SERVO_CONFIG_TYPE2;
    servoPacket.speedH = (servoPacket.speedH << 4) | (0x0003);
    servoPacket.checkCRC = g_runTimeConfig.checkBCC16(reinterpret_cast<short *>(&servoPacket),
                                                       sizeof(servoPacket) - sizeof(servoPacket.checkCRC) - sizeof(servoPacket.tail));

    servoPacket.type = qToBigEndian(servoPacket.type);
    servoPacket.speedH = qToBigEndian(servoPacket.speedH);
    servoPacket.speedV = qToBigEndian(servoPacket.speedV);
    servoPacket.startXY = qToBigEndian(servoPacket.startXY);
    servoPacket.endXY = qToBigEndian(servoPacket.endXY);
    servoPacket.stepY = qToBigEndian(servoPacket.stepY);
    servoPacket.checkCRC = qToBigEndian(servoPacket.checkCRC);

    if(m_pTimer != nullptr)
    {
        delete m_pTimer;
    }
    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(onServoStopRunTimeOut()));
    sentDatagrame(reinterpret_cast<char *>(&servoPacket), sizeof(servoPacket));
    m_pTimer->start(2000);
}

void ConfigCmdPacket::onServoStopRunTimeOut()
{
    m_pTimer->stop();
    ServoConfigPacket servoPacket;
    memset(&servoPacket, 0, sizeof(servoPacket));
    servoPacket.header = SERVO_CONFIG_HEADER;
    servoPacket.tail = SERVO_CONFIG_TAIL;
    servoPacket.header = qToBigEndian(servoPacket.header);
    servoPacket.tail = qToBigEndian(servoPacket.tail);

    servoPacket.type = SERVO_CONFIG_TYPE2;
    servoPacket.speedH = (servoPacket.speedH << 4) | (0x0000);
    servoPacket.checkCRC = g_runTimeConfig.checkBCC16(reinterpret_cast<short *>(&servoPacket),
                                                       sizeof(servoPacket) - sizeof(servoPacket.checkCRC) - sizeof(servoPacket.tail));

    servoPacket.type = qToBigEndian(servoPacket.type);
    servoPacket.speedH = qToBigEndian(servoPacket.speedH);
    servoPacket.speedV = qToBigEndian(servoPacket.speedV);
    servoPacket.startXY = qToBigEndian(servoPacket.startXY);
    servoPacket.endXY = qToBigEndian(servoPacket.endXY);
    servoPacket.stepY = qToBigEndian(servoPacket.stepY);
    servoPacket.checkCRC = qToBigEndian(servoPacket.checkCRC);

    sentDatagrame(reinterpret_cast<char *>(&servoPacket), sizeof(servoPacket));
}

void ConfigCmdPacket::onRFNormalCollect()
{
    RFConfigPacket RFPacket;
    memset(&RFPacket, 0, sizeof(RFPacket));
    RFPacket.header = RF_CONFIG_HEADER;
    RFPacket.tail = RF_CONFIG_TAIL;
    RFPacket.header = qToBigEndian(RFPacket.header);
    RFPacket.tail = qToBigEndian(RFPacket.tail);
    RFPacket.registerAddr = 0x08;
    RFPacket.data = 1;
    RFPacket.checkBCC = g_runTimeConfig.checkBCC8(reinterpret_cast<char *>(&RFPacket) + sizeof(RFPacket.header),
                                                sizeof(RFPacket.registerAddr) + sizeof(RFPacket.data));
    RFPacket.data = qToBigEndian(RFPacket.data);
    sentDatagrame(reinterpret_cast<char *>(&RFPacket), sizeof(RFPacket));
}

void ConfigCmdPacket::onRFEnvelopeCollect()
{
    RFConfigPacket RFPacket;
    memset(&RFPacket, 0, sizeof(RFPacket));
    RFPacket.header = RF_CONFIG_HEADER;
    RFPacket.tail = RF_CONFIG_TAIL;
    RFPacket.header = qToBigEndian(RFPacket.header);
    RFPacket.tail = qToBigEndian(RFPacket.tail);
    RFPacket.registerAddr = 0x08;
    RFPacket.data = 0;
    RFPacket.checkBCC = g_runTimeConfig.checkBCC8(reinterpret_cast<char *>(&RFPacket) + sizeof(RFPacket.header),
                                                sizeof(RFPacket.registerAddr) + sizeof(RFPacket.data));
    RFPacket.data = qToBigEndian(RFPacket.data);
    sentDatagrame(reinterpret_cast<char *>(&RFPacket), sizeof(RFPacket));
}

void ConfigCmdPacket::sentDatagrame(const char *datagram, const int length)
{
    if(nullptr == m_pUdpSocket)
    {
        m_pUdpSocket = new QUdpSocket();
    }
    qDebug() << "ConfigCmd sent: "
             << m_pUdpSocket->writeDatagram(datagram, length, QHostAddress(localConfig.getCollectIp()), 9001);
}
