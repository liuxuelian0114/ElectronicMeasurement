#include "runtimeconfig.h"

#include <QDebug>

RunTimeConfig g_runTimeConfig;

RunTimeConfig::RunTimeConfig()
{

}

RunTimeConfig::~RunTimeConfig()
{

}

unsigned char RunTimeConfig::checkBCC8(char *data, int length)
{
    unsigned char bccdata = 0;
    bccdata = data[0] ^ data[1];
    for(int i = 2; i < length; i++)
    {
        bccdata ^= data[i];
    }
    return bccdata;
}

unsigned short RunTimeConfig::checkBCC16(short *data, int length)
{
    unsigned short bccdata = 0;
    bccdata = data[0] ^ data[1];
    for(int i = 2; i < length / 2; i++)
    {
        bccdata ^= data[i];
    }
    return bccdata;
}

void RunTimeConfig::setUserInfo(const QString &userName, const QString &permission)
{
    m_userName = userName;
    m_permission = permission;
}
