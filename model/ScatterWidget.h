#ifndef SCATTERWIDGET_H
#define SCATTERWIDGET_H

#include <QDialog>
#include <QtDataVisualization>

#include "colormap.h"

using namespace QtDataVisualization;

class ScatterWidget : public QDialog
{
    Q_OBJECT
public:
    explicit ScatterWidget(QWidget *parent = 0);
    void setDataCount(int xCount, int yCount, int zCount);
    void setDataRange(int xRange, int yRange, int zRange);
    void setDataSource(float *x_mat, float *y_mat, float *z_mat, float *bpp);

public slots:
    void drawPointCloud();  //绘制三维点云

signals:
    void done();

private:
    void iniGraph3D();      //初始化绘图

private:
    Q3DScatter  *m_p3DScatter;       //散点图
    QScatter3DSeries *m_p3DSeries;   //散点序列
    QScatterDataArray *m_pScatterDataArray;

    int m_xCount;
    int m_yCount;
    int m_zCount;

    int m_xRange;
    int m_yRange;
    int m_zRange;//X*Y*Z

    float *m_pxMat;//数据源
    float *m_pyMat;
    float *m_pzMat;
    float *m_bpp;

    ColorMap m_colorMap;//色图
};

#endif // SCATTERWIDGET_H
