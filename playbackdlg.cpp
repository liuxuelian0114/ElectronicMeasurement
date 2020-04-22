#include <QDebug>
#include <QFtp>
#include <QtMath>
#include <QMessageBox>
#include <QDir>


#include "playbackdlg.h"
#include "ui_playbackdlg.h"
#include "localconfig.h"
#include "runtimeconfig.h"
#include "Packet.h"

PlayBackDlg::PlayBackDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayBackDlg)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & (~Qt::WindowContextHelpButtonHint));
    if(localConfig.getPlaybackMode())
    {
        this->setWindowTitle(QStringLiteral("实验——%1 正在回放").arg(localConfig.getWindowTitle()));
        ui->pushButtonStart->setEnabled(false);
    }
    else
    {
        ui->pushButtonStop->setEnabled(false);
    }
    ui->lineEditDownLoad->setText(QDir::toNativeSeparators(localConfig.getPlaybackAddress()));


    m_pFtp = new QFtp(this);
    connect(m_pFtp, SIGNAL(listInfo(QUrlInfo)), this, SLOT(onFtpListInfo(QUrlInfo)));
    connect(m_pFtp, SIGNAL(commandFinished(int,bool)), this, SLOT(onCommandFinished(int,bool)));
    m_pFtp->connectToHost(localConfig.getNASIp());
    m_pFtp->login(localConfig.getNASAccount(),localConfig.getNASPassword());
    m_pFtp->cd("/recall");
//    m_pFtp->cd("/Bunfly_FTP/recall");
    m_pFtp->list();

    connect(ui->pushButtonStart,SIGNAL(clicked()),this, SLOT(onPushButtonStartClicked()));
    connect(ui->pushButtonStop, SIGNAL(clicked()), this, SLOT(onPushButtonStopClicked()));
    connect(ui->lineEditDownLoad, SIGNAL(textChanged(QString)),this,SLOT(onPlaybackFolderAddressChanged(QString)));
}

PlayBackDlg::~PlayBackDlg()
{
    delete ui;
}

void PlayBackDlg::onPushButtonStartClicked()
{
    if(ui->listWidget->currentItem())
    {
        emit playbackExperiment(1, ui->listWidget->currentItem()->text()+ QString("/1"));
        this->setWindowTitle(QStringLiteral("实验 - %1 正在回放").arg(ui->listWidget->currentItem()->text()));
        localConfig.setPlaybackMode(true);
        localConfig.setWindowTitle(ui->listWidget->currentItem()->text());
        ui->pushButtonStart->setEnabled(false);
        ui->pushButtonStop->setEnabled(true);
    }
    else
    {
        QMessageBox::information(this, QStringLiteral("提示"),
                              QStringLiteral("请选择需要下载的文件"),QMessageBox::Ok);
    }
}

void PlayBackDlg::onPushButtonStopClicked()
{
    emit playbackExperiment(1, ui->listWidget->currentItem()->text()+ QString("/0"));
    this->setWindowTitle(QStringLiteral("选择实验"));
    localConfig.setPlaybackMode(false);
    localConfig.setWindowTitle(QString(""));
    ui->pushButtonStart->setEnabled(true);
    ui->pushButtonStop->setEnabled(false);
}

void PlayBackDlg::onPlaybackFolderAddressChanged(QString str)
{
    localConfig.setPlaybackAddress(QDir::fromNativeSeparators(str));
}

void PlayBackDlg::onFtpListInfo(const QUrlInfo &urlInfo)
{
    if((urlInfo.name() == QString(".")) || (urlInfo.name() == QString("..")))
    {
        return;
    }
    else
    {
        ui->listWidget->addItem(QString::fromLocal8Bit(urlInfo.name().toLatin1()));
    }
}

void PlayBackDlg::onCommandFinished(int id, const bool type)
{
    if(QFtp::ConnectToHost == m_pFtp->currentCommand())
    {
        if(type)
        {
            QMessageBox::warning(this, QStringLiteral("NAS连接失败!"),
                                 m_pFtp->errorString(),QMessageBox::Ok);
            return;
        }
    }
    if(QFtp::Login == m_pFtp->currentCommand())
    {
        if(type)
        {
            QMessageBox::warning(this, QStringLiteral("NAS用户名或者密码错误!"),
                                 m_pFtp->errorString(),QMessageBox::Ok);
            return;
        }
    }
    if(QFtp::Cd == m_pFtp->currentCommand())
    {
        if(type)
        {
            QMessageBox::warning(this, QStringLiteral("目录错误!"),
                                 m_pFtp->errorString(),QMessageBox::Ok);
            return;
        }
    }
}

void PlayBackDlg::onPalybackFinished(unsigned char model)
{
    if(model == EMS_PACKET_MODEL1)
    {
        this->setWindowTitle(QStringLiteral("选择实验"));
        ui->pushButtonStart->setEnabled(true);
        ui->pushButtonStop->setEnabled(false);
    }
    if(model == EMS_PACKET_MODEL2)
    {
        this->setWindowTitle(QStringLiteral("选择实验"));
        ui->pushButtonStart->setEnabled(true);
        ui->pushButtonStop->setEnabled(false);
        QMessageBox::about(this,QStringLiteral("提示"),
                           QStringLiteral("实验：%1已存在，下载失败，请修改回放文件存放地址").arg(localConfig.getWindowTitle()));
    }

}
