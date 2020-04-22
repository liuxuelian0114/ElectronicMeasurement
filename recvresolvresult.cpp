#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QFile>
#include <QtMath>
#include <QtEndian>

#include "recvresolvresult.h"
#include "runtimeconfig.h"



RecvResolvResult::RecvResolvResult(QObject *parent) :
    QObject(parent)
{
    m_p3dSocket = nullptr;
    m_bIs3dHead = true;
    m_p3dServer = new QTcpServer(this);
    m_p3dServer->listen(QHostAddress::Any, 8902);
    connect(m_p3dServer, SIGNAL(newConnection()), this, SLOT(on3dNewConnection()));

    m_pRcsSocket = nullptr;
    m_bIsRcsHead = true;
    m_pRCSServer = new QTcpServer(this);
    m_pRCSServer->listen(QHostAddress::Any, 8903);
    connect(m_pRCSServer, SIGNAL(newConnection()), this, SLOT(onRcsNewConnection()));
}

RecvResolvResult::~RecvResolvResult()
{
}

void RecvResolvResult::onRcsNewConnection()
{
    m_bIsRcsHead = true;
    m_rcsBuf.clear();
    memset(&m_rcsHeader, 0, sizeof(m_rcsHeader));
    m_pRcsSocket = m_pRCSServer->nextPendingConnection();
    connect(m_pRcsSocket, SIGNAL(disconnected()), m_pRcsSocket, SLOT(deleteLater()));
    connect(m_pRcsSocket, SIGNAL(readyRead()), this, SLOT(onRcsReadyRead()));
    qDebug() << "rcs data coming";
}
void RecvResolvResult::onRcsReadyRead()
{
    m_rcsBuf.append(m_pRcsSocket->readAll());
    if(m_rcsBuf.size() > sizeof(m_rcsHeader) && m_bIsRcsHead)
    {
        memcpy(&m_rcsHeader, m_rcsBuf.data(), sizeof(m_rcsHeader));
        m_rcsHeader.fileSize = 14504; //for debug
        m_bIsRcsHead = false;
    }
    if(!m_bIsRcsHead && (m_rcsHeader.flag != RCS_FLAG))
    {
        m_rcsBuf.clear();
        return;
    }

    if((RCS_FLAG == m_rcsHeader.flag) && (m_rcsBuf.size() >= m_rcsHeader.fileSize)) //数据读取完成
    {
        g_runTimeConfig.rcsFreq.resize(m_rcsHeader.xb);
        g_runTimeConfig.rcs1.resize(m_rcsHeader.xb);
        g_runTimeConfig.rcs2.resize(m_rcsHeader.xb);
        g_runTimeConfig.rcs3.resize(m_rcsHeader.xb);

        char *pByte = m_rcsBuf.data() + sizeof(m_rcsHeader);
        float *pDat = (float *)pByte;

        for(int i = 0; i < m_rcsHeader.xb; i++)
        {
            g_runTimeConfig.rcsFreq[i] = pDat[i * m_rcsHeader.ya + 1];
            g_runTimeConfig.rcs1[i] = pDat[i * m_rcsHeader.ya + 2];
            g_runTimeConfig.rcs2[i] = pDat[i * m_rcsHeader.ya + 3];
            g_runTimeConfig.rcs3[i] = pDat[i * m_rcsHeader.ya + 4];
        }
        m_rcsBuf.clear();
        emit rcsDataupdated();
        qDebug() << "rcs data updated";
    }
}

void RecvResolvResult::on3dNewConnection()
{
    m_bIs3dHead = true;
    m_3dBuf.clear();
    memset(&m_3dHeader, 0, sizeof(m_3dHeader));
    m_p3dSocket = m_p3dServer->nextPendingConnection();
    connect(m_p3dSocket, SIGNAL(disconnected()), m_p3dSocket, SLOT(deleteLater()));
    connect(m_p3dSocket, SIGNAL(readyRead()), this, SLOT(on3dReadyRead()));
    qDebug() << "3d data coming";
}

void RecvResolvResult::on3dReadyRead()
{

    m_3dBuf.append(m_p3dSocket->readAll());
    if(m_3dBuf.size() > sizeof(m_3dHeader) && m_bIs3dHead)
    {
        memcpy(&m_3dHeader, m_3dBuf.data(), sizeof(m_3dHeader));
        m_bIs3dHead = false;
    }
    if(!m_bIs3dHead && (m_3dHeader.flag != D3_FLAG))
    {
        m_3dBuf.clear();
        return;
    }

    if((D3_FLAG == m_3dHeader.flag) && (m_3dBuf.size() >= m_3dHeader.fileSize)) //数据读取完成
    {
        int dataCount = m_3dHeader.xb * m_3dHeader.ya * m_3dHeader.zc;
        float *pxMat = new float[m_3dHeader.xb];
        float *pyMat = new float[m_3dHeader.ya];
        float *pzMat = new float[m_3dHeader.zc];
        float *pBpp =   new float[dataCount];


        memcpy(pxMat, m_3dBuf.data() + sizeof(m_3dHeader), m_3dHeader.xb * sizeof(float));

        memcpy(pyMat,
               m_3dBuf.data() + sizeof(m_3dHeader) + m_3dHeader.xb * sizeof(float),
               m_3dHeader.ya * sizeof(float));

        memcpy(pzMat,
               m_3dBuf.data() + sizeof(m_3dHeader) + m_3dHeader.xb * sizeof(float) + m_3dHeader.ya * sizeof(float),
               m_3dHeader.zc * sizeof(float));

        float real = 0;
        float imag = 0;
        float max = 0;
        char *pByte = m_3dBuf.data() + sizeof(m_3dHeader) + (m_3dHeader.xb + m_3dHeader.ya + m_3dHeader.zc) * sizeof(float);
        float *pDat = (float *)pByte;

        for(int i = 0; i < dataCount; i++)
        {
            real = pDat[i * 2];
            imag = pDat[i * 2 + 1];
            pBpp[i] = qSqrt(real * real + imag * imag);
            if(0 == i)
            {
                max = pBpp[i];
            }
            if(pBpp[i] > max)
            {
                max = pBpp[i];
            }
        }
        //量化
        for(int i = 0; i < dataCount; i++)
        {
            pBpp[i] = pBpp[i] / max;
        }
        D3Para d3Para;

        d3Para.xMax = m_3dHeader.xb;
        d3Para.yMax = m_3dHeader.ya;
        d3Para.zMax = m_3dHeader.zc;

        d3Para.xb = m_3dHeader.xb;
        d3Para.ya = m_3dHeader.ya;
        d3Para.zc = m_3dHeader.zc;
        d3Para.pxMat = pxMat;
        d3Para.pyMat = pyMat;
        d3Para.pzMat = pzMat;
        d3Para.pBpp = pBpp;
        m_3dBuf.clear();
        emit d3DataUpdated(d3Para);
        qDebug() << "3d data updated";
   }

}
