#include <QSettings>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QApplication>

#include "localconfig.h"

LocalConfig localConfig;

LocalConfig::LocalConfig()
{
    m_bIsPlayback = false;
}

LocalConfig::~LocalConfig()
{
    saveConfig();
}

void LocalConfig::readConfig()
{
    QFileInfo info(QDir(QApplication::applicationDirPath()), "config.ini");

    QSettings configIniRead(info.absoluteFilePath(), QSettings::IniFormat);
    configIniRead.setIniCodec("GB2312");

    setForwordIp(configIniRead.value("forword/Ip").toString());
    setCollectIp(configIniRead.value("collect/Ip").toString());
    setNASIp(configIniRead.value("NAS/Ip").toString());
    setNASAccount(configIniRead.value("NAS/Account","admin").toString());
    setNASPassword(configIniRead.value("NAS/Password","admin").toString());
    setBandRange(configIniRead.value("band/Range").toString());
    setSoftwareOperationMode(configIniRead.value("SoftwareOperationMode/mode").toString());
    setBatFolderAddress(configIniRead.value("SCRIPT/bat", "C:/").toString());
    setPlaybackAddress(configIniRead.value("PlaybackAddress/address", "E:/resolvedata").toString());
    setReset(configIniRead.value("PROCESS/address", "C:/").toString());
//    qDebug()<< "----------->" << m_SoftwareOperationMode;
}

void LocalConfig::saveConfig()
{
    QFileInfo info(QDir(QApplication::applicationDirPath()), "config.ini");

    QSettings configIniWrite(info.absoluteFilePath(), QSettings::IniFormat);
    configIniWrite.setIniCodec("GB2312");

    configIniWrite.setValue("forword/Ip", getForwordIp());
    configIniWrite.setValue("collect/Ip", getCollectIp());
    configIniWrite.setValue("NAS/Ip", getNASIp());
    configIniWrite.setValue("NAS/Account", getNASAccount());
    configIniWrite.setValue("NAS/Password", getNASPassword());
    configIniWrite.setValue("band/Range", getBandRange());
    configIniWrite.setValue("SoftwareOperationMode/mode", getSoftwareOperationMode());
    configIniWrite.setValue("SCRIPT/bat",getBatFolderAddress());
    configIniWrite.setValue("PlaybackAddress/address",getPlaybackAddress());
    configIniWrite.setValue("PROCESS/address",getReset());
}
