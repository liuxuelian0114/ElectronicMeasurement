#ifndef PLAYBACKDLG_H
#define PLAYBACKDLG_H

#include <QDialog>
#include <QListWidgetItem>
#include <QUrlInfo>
#include <QString>

namespace Ui {
class PlayBackDlg;
}

class QFtp;

class PlayBackDlg : public QDialog
{
    Q_OBJECT

public:
    explicit PlayBackDlg(QWidget *parent = 0);
    ~PlayBackDlg();

signals:
    void playbackExperiment(const int &model, const QString &name);

private slots:
    void onPushButtonStartClicked();
    void onPushButtonStopClicked();
    void onPlaybackFolderAddressChanged(QString str);
    void onFtpListInfo(const QUrlInfo &urlInfo);
    void onCommandFinished(int id,const bool type);
    void onPalybackFinished(unsigned char model);

private:
    Ui::PlayBackDlg *ui;
    QFtp *m_pFtp;
};

#endif // PLAYBACKDLG_H
