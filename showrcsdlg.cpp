#include <QDebug>

#include "showrcsdlg.h"
#include "ui_showrcsdlg.h"
#include "qcustomplot.h"
#include "runtimeconfig.h"

ShowRCSDlg::ShowRCSDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowRCSDlg)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & (~Qt::WindowContextHelpButtonHint));
//    this->layout()->setSizeConstraint(QLayout::SetFixedSize);//限定窗口大小
//    this->setFixedSize(this->size());//限定窗口大小

    plot();
}

ShowRCSDlg::~ShowRCSDlg()
{
    delete ui;
}

void ShowRCSDlg::plot()
{
    //获取数据
    const QVector<double> &freq = g_runTimeConfig.rcsFreq;
    const QVector<double> &rcs1 = g_runTimeConfig.rcs1;
    const QVector<double> &rcs2 = g_runTimeConfig.rcs2;
    const QVector<double> &rcs3 = g_runTimeConfig.rcs3;

    //找出y轴最大最小值
    double maxFreq = findMax(freq);
    double minFreq = findMin(freq);

    //找x轴最大值
    double maxRcs = findMax(rcs1);

    double tmp = findMax(rcs2);
    if(tmp > maxRcs)
    {
        maxRcs = tmp;
    }
    tmp = findMax(rcs3);
    if(tmp > maxRcs)
    {
        maxRcs = tmp;
    }

    double minRcs = findMin(rcs1);
    tmp = findMin(rcs2);
    if(tmp < minRcs)
    {
        minRcs = tmp;
    }
    tmp = findMin(rcs3);
    if(tmp < minRcs)
    {
        minRcs = tmp;
    }

    //CustomPlot的基础功能设置    1、轴可拖动     2、通过鼠标滚轮改变轴显示范围
    ui->listWidget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    ui->listWidget->xAxis->setLabel("f/Hz");
    ui->listWidget->yAxis->setLabel("RCS");
    ui->listWidget->xAxis->setRange(minFreq, maxFreq);
    ui->listWidget->yAxis->setRange(minRcs, maxRcs);
    ui->listWidget->addGraph();
    ui->listWidget->graph(0)->setPen(QPen(Qt::red));
    ui->listWidget->graph(0)->setName("RCS1");
    ui->listWidget->graph(0)->setData(freq, rcs1);

    ui->listWidget->addGraph();
    ui->listWidget->graph(1)->setPen(QPen(Qt::green));
    ui->listWidget->graph(1)->setName("RCS2");
    ui->listWidget->graph(1)->setData(freq, rcs2);

    ui->listWidget->addGraph();
    ui->listWidget->graph(2)->setPen(QPen(Qt::blue));
    ui->listWidget->graph(2)->setName("RCS3");
    ui->listWidget->graph(2)->setData(freq, rcs3);

    ui->listWidget->legend->setVisible(true);
    ui->listWidget->replot();
}

double ShowRCSDlg::findMax(const QVector<double> &vector)
{
    double max = 0;
    for(int i = 0; i < vector.size(); i++)
    {
        if(0 == i)
        {
            max = vector.at(i);
        }
        if(vector.at(i) > max)
        {
            max = vector.at(i);
        }
    }

    return max;
}

double ShowRCSDlg::findMin(const QVector<double> &vector)
{
    double min = 0;
    for(int i = 0; i < vector.size(); i++)
    {
        if(0 == i)
        {
            min = vector.at(i);
        }
        if(vector.at(i) < min)
        {
            min = vector.at(i);
        }
    }

    return min;
}
