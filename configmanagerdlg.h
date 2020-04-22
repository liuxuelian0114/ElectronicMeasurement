#ifndef CONFIGMANAGERDLG_H
#define CONFIGMANAGERDLG_H

#include <QDialog>

namespace Ui {
class ConfigManagerDlg;
}

class ConfigManagerDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigManagerDlg(QWidget *parent = 0);
    ~ConfigManagerDlg();

signals:
    void configChanged();
private slots:
    void onPushButtonSaveClicked();

private:
    Ui::ConfigManagerDlg *ui;
};

#endif // CONFIGMANAGERDLG_H
