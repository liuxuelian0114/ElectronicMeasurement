#ifndef LOCALCONFIG_H
#define LOCALCONFIG_H

#include <QString>

class LocalConfig
{
public:
    LocalConfig();
    ~LocalConfig();

    /*
     * API
     * 读配置文件当中的信息
     */
    void setForwordIp(const QString &ip) {m_forwordIp = ip;}
    void setCollectIp(const QString &ip) {m_collectIp = ip;}
    void setNASIp(const QString &ip) {m_NASIp = ip;}
    void setNASAccount(const QString &account){m_NASAccount = account;}
    void setNASPassword(const QString &password){m_NASPassword = password;}
    void setBandRange(const QString &range) {m_bandRange = range;}
    void setSoftwareOperationMode(const QString &mode){m_SoftwareOperationMode = mode;}
    void setBatFolderAddress(const QString &folderAddress){m_batFolder = folderAddress;}
    void setBatType(const QString &type){m_batType = type;}
    void setPlaybackAddress(const QString &folderAddress){m_playbackAddress = folderAddress;}
    void setReport(const QString &text){m_report = text;}
    void setWindowTitle(const QString &title){m_windowTitle = title;}
    void setPlaybackMode(const bool &mode) {m_bIsPlayback = mode;}
    void setReset(const QString &address){m_reset = address;}
    void setStartArgs(const QString &str){m_startArgs.clear();m_startArgs.append(str);}

    QString getForwordIp() const {return m_forwordIp;}
    QString getCollectIp() const {return m_collectIp;}
    QString getNASIp() const {return m_NASIp;}
    QString getNASAccount()const {return m_NASAccount;}
    QString getNASPassword()const{return m_NASPassword;}
    QString getBandRange() {return m_bandRange;}
    QString getSoftwareOperationMode(){return m_SoftwareOperationMode;}
    QString getBatFolderAddress(){return m_batFolder;}
    QString getBatType(){return m_batType;}
    QString getPlaybackAddress(){return m_playbackAddress;}
    QString getReport(){return m_report;}
    QString getWindowTitle(){return m_windowTitle;}
    bool getPlaybackMode() {return m_bIsPlayback;}
    QString getReset(){return m_reset;}
    QString getStartArgs()const{return m_startArgs;}

    /*
     * 读配置文件当中的信息
     */
    void readConfig();
    /*
     * 将信息写入配置文件
     */
    void saveConfig();


private:
    QString m_forwordIp;
    QString m_collectIp;
    QString m_NASIp;
    QString m_NASAccount;
    QString m_NASPassword;
    QString m_bandRange;
    QString m_SoftwareOperationMode;
    QString m_batFolder; //需要运行的脚本文件夹地址
    QString m_batType;//需要运行的脚本文件
    QString m_playbackAddress;
    QString m_report;
    QString m_windowTitle;
    bool m_bIsPlayback;
    QString m_reset;
    QString m_startArgs;//保存界面参数

};

extern LocalConfig localConfig;

#endif // LOCALCONFIG_H
