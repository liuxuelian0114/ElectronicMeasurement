#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>

namespace Ui {
class LoginDlg;
}

class LoginDlg : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDlg(QWidget *parent = 0);
    ~LoginDlg();

signals:

private slots:
    /*
     *  登录验证
     */
    void pushButtonOkClicked();

private:
    Ui::LoginDlg *ui;
};

#endif // LOGINDLG_H
