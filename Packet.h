#ifndef PACKET_H
#define PACKET_H

#pragma pack(push)
#pragma pack(1)

#define FORWORD_PACKET_HEADER   (0x5B5B)
#define FORWORD_PACKET_MODEL0   (0x00)//开始，发送成像参数
#define FORWORD_PACKET_MODEL1   (0x01)//回放
#define FORWORD_PACKET_MODEL2   (0x02)//停止，发送实验记录
#define FORWORD_PACKET_MODEL3   (0x03)//运行脚本文件
#define FORWORD_PACKET_MODEL4   (0x04)//生成报告
#define FORWORD_PACKET_MODEL5   (0x05)//合并报告
#define FORWORD_PACKET_TAIL     (0x5D5D)

#define SERVO_CONFIG_HEADER     (0x7b7b)
#define SERVO_CONFIG_TYPE1      (0x0001)
#define SERVO_CONFIG_TYPE2      (0x0002)
#define SERVO_CONFIG_TYPE3      (0x0003)
#define SERVO_CONFIG_TAIL       (0x7d7d)

#define RF_CONFIG_HEADER        (0x7B7B)
#define RF_CONFIG_TAIL          (0x7D7D)

#define UP_PACKET_PORT          (8888)
#define UP_PACKET_HEADER        (0x5555555555555555)
#define UP_PACKET_TAIL          (0xAAAAAAAAAAAAAAAA)

#define SERVO_REPORT_HEADER     (0x5b5b)
#define SERVO_REPORT_TAIL       (0x5d5d)

#define RF_REPORT_HEADER        (0x3c3c)
#define RF_REPORT_TAIL          (0x3e3e)

#define D3_FLAG         555
#define RCS_FLAG        666
#define PULSE_FLAG      777

#define EMS_PACKET_HEADER   (0x5A5A)
#define EMS_PACKET_MODEL1   (0x01)//下载完成
#define EMS_PACKET_MODEL2   (0x02)//
#define EMS_PACKET_TAIL     (0x5F5F)

//数据转发软件配置帧
struct ForwordPacket{
    unsigned short header;
    unsigned char model;
    unsigned char name[64];
    unsigned int argsLength;
    unsigned short checkCRC;
    unsigned short tail;
};

//电子测量软件配置帧
struct EmsPacket{
    unsigned short header;
    unsigned char model;
    unsigned short checkCRC;
    unsigned short tail;
};
//伺服状态配置帧
struct ServoConfigPacket{
    unsigned short header;
    unsigned short type;
    unsigned short speedH;
    unsigned short speedV;
    unsigned long long startXY;
    unsigned long long endXY;
    unsigned short stepY;
    unsigned short checkCRC;
    unsigned short tail;
};
//伺服间断运动帧
struct ServoDisMotionPacket{
    unsigned short header;
    unsigned short type;
    unsigned short control;
    unsigned long long startXY;
    unsigned long long endXY;
    unsigned short stepY;
    unsigned short checkCRC;
    unsigned short tail;
};
//射频状态配置帧
struct RFConfigPacket{
    unsigned short header;
    unsigned char registerAddr;
    unsigned short data;
    unsigned char checkBCC;
    unsigned short tail;
};

//伺服状态上报帧
struct ServoReportPacket{
    unsigned short header;
    unsigned short type;
    unsigned short state;
    unsigned int nowX;
    unsigned int nowY;
    unsigned int sportTime;
    unsigned short checkCRC;
    unsigned short tail;
};
//射频状态上报帧
struct RFReportPacket{
    unsigned short header;
    unsigned char registerAddr;
    unsigned short data;
    unsigned char checkBCC;
    unsigned short tail;
};
//上行通讯帧
struct UpPacket{
    unsigned long long header;
    unsigned int beiyong1;
    unsigned int dataLabel;
    int data[2048];
//    unsigned int count1;
    unsigned char servoState[sizeof(ServoReportPacket)];
    unsigned char RFState[sizeof(RFReportPacket)];
//    unsigned int count2;
    unsigned int label2;
    char beiyong2[6];
    unsigned long long tail;
};

struct D3Header
{
    unsigned int flag;
    unsigned int fileSize;
    unsigned int ya;
    unsigned int xb;
    unsigned int zc;
    char reserve[1004];
};

struct RcsHeader
{
    unsigned int flag;
    unsigned int fileSize;
    unsigned int ya;
    unsigned int xb;
    char reserve[1008];
};
struct PulseHeader
{
    unsigned int flag;
    unsigned int fileSize;
    int row;
    int col;
    char reserve[112]; //头大小128bytes
};

struct D3Para
{
    unsigned int xMax;
    unsigned int yMax;
    unsigned int zMax;
    unsigned int ya;
    unsigned int xb;
    unsigned int zc;
    float *pxMat;
    float *pyMat;
    float *pzMat;
    float *pBpp;
};

#pragma pack()
#endif // PACKET_H
