#ifndef USERMANAGERDLG_H
#define USERMANAGERDLG_H

#include <QDialog>

namespace Ui {
class UserManagerDlg;
}

class UserManagerDlg : public QDialog
{
    Q_OBJECT

public:
    explicit UserManagerDlg(QWidget *parent = 0);
    ~UserManagerDlg();

private:
    void initInfo();

private slots:
    void onPushButtonAddClicked();
    void onPushButtonEditClicked();
    void onPushButtonDeleteClicked();

private:
    Ui::UserManagerDlg *ui;
};

#endif // USERMANAGERDLG_H
