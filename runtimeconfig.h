#ifndef RUNTIMECONFIG_H
#define RUNTIMECONFIG_H

#include <QString>
#include <QVector>

class RunTimeConfig
{
public:
    RunTimeConfig();
    ~RunTimeConfig();

public:
    /*
     * 8位校验和码
     */
    unsigned char checkBCC8(char *data, int length);
    /*
     * 16位校验和码
     */
    unsigned short checkBCC16(short *data, int length);

    void setUserInfo(const QString &userName, const QString &permission);
    QString getUserName() const {return m_userName;}
    QString getPermission() const {return m_permission;}

    QVector<double> rcsFreq;
    QVector<double> rcs1;
    QVector<double> rcs2;
    QVector<double> rcs3;

private:
    QString m_userName;
    QString m_permission;
};

extern RunTimeConfig g_runTimeConfig;

#endif // RUNTIMECONFIG_H
