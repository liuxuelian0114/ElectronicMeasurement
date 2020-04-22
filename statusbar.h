#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QWidget>
#include <QStatusBar>
#include <QTime>
#include <QPalette>

class QLabel;
class QTimer;

class StatusBar : public QStatusBar
{
    Q_OBJECT
public:
    explicit StatusBar(QWidget *parent = 0);
    ~StatusBar();

    /*
     * 初始化显示信息
     */
    void initStatusBarInfo();

signals:

public slots:
    /*
     *  设置状态栏显示信息
     */
    void onSetInfo(QString name);

private slots:
    /*
     *  "实验用时"定时器的运作
     */
    void onTimeout();

private:
    QLabel *m_pNameLabel;
    QLabel *m_pBeginLabel;
    QLabel *m_pTimeLabel;

    QTime m_time;
    QTimer *m_pTimer;
};

#endif // STATUSBAR_H
