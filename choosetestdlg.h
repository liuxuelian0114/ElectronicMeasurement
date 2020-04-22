#ifndef CHOOSETESTDLG_H
#define CHOOSETESTDLG_H

#include <QDialog>

class QListWidgetItem;

namespace Ui {
class ChooseTestDlg;
}

class ChooseTestDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseTestDlg(QWidget *parent = 0);
    ~ChooseTestDlg();

signals:
    void testNameChanged(QString name);

private slots:
    void onLWitemDoubleClicked(QListWidgetItem *item);

private:
    Ui::ChooseTestDlg *ui;
};

#endif // CHOOSETESTDLG_H
