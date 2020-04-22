#include <QLabel>
#include <QDateTime>
#include <QTimer>
#include <QSize>
#include <QDebug>

#include "statusbar.h"

StatusBar::StatusBar(QWidget *parent) :
    QStatusBar(parent)
{
    m_pNameLabel = new QLabel(this);
    this->addWidget(m_pNameLabel, 1);
    m_pBeginLabel = new QLabel(this);
    this->addWidget(m_pBeginLabel, 1);
    m_pTimeLabel = new QLabel(this);
    this->addWidget(m_pTimeLabel, 1);//添加到状态栏最右侧

    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(onTimeout()));

    initStatusBarInfo();
}

StatusBar::~StatusBar()
{

}

void StatusBar::initStatusBarInfo()
{
    m_pNameLabel->setText(QStringLiteral("当前实验："));
    m_pBeginLabel->setText(QStringLiteral("开始时间："));
    m_pTimeLabel->setText(QStringLiteral("实验时间："));
    m_pTimer->stop();
}

void StatusBar::onSetInfo(QString name)
{
    m_pTimer->stop();
    m_pNameLabel->setText(QStringLiteral("当前实验：") + name);
    QString timeStr = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    m_pBeginLabel->setText(QStringLiteral("开始时间：") + timeStr);
    m_time.setHMS(0, 0, 0);
    timeStr = m_time.toString("hh:mm:ss");
    m_pTimeLabel->setText(QStringLiteral("实验时间：") + timeStr);
    m_pTimer->start(1000);
}



void StatusBar::onTimeout()
{
    m_time = m_time.addMSecs(1000);
    m_pTimeLabel->setText(QStringLiteral("实验时间：") + m_time.toString("hh:mm:ss"));
}
