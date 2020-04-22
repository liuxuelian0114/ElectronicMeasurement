#ifndef USERINFODLG_H
#define USERINFODLG_H

#include <QDialog>

namespace Ui {
class UserInfoDlg;
}

class UserInfoDlg : public QDialog
{
    Q_OBJECT

public:
    explicit UserInfoDlg(QWidget *parent = 0);
    ~UserInfoDlg();

    void setEditUserInfo(const QStringList &infos, const bool &ok);
    void setComboxPermission(const bool &ok);

signals:
    void userInfoChanged(QStringList infos);

private slots:
    void onPushButtonOkClicked();

private:
    Ui::UserInfoDlg *ui;
};

#endif // USERINFODLG_H
