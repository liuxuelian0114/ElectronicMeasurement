#ifndef SHOWRCSDLG_H
#define SHOWRCSDLG_H

#include <QDialog>

namespace Ui {
class ShowRCSDlg;
}

class ShowRCSDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ShowRCSDlg(QWidget *parent = 0);
    ~ShowRCSDlg();

private:
    void plot();
    //找一个队列中最大的数
    double findMax(const QVector<double> &vector);
    //找一个队列中最小的数
    double findMin(const QVector<double> &vector);

private:
    Ui::ShowRCSDlg *ui;
};

#endif // SHOWRCSDLG_H
