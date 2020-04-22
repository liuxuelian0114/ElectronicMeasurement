#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QOpenGLFunctions>
#include <gl/GLU.h>

#include "colormap.h"

using namespace std;

class GLWidget : public QGLWidget,public QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();

    void setDataRange(int xRange, int yRange, int zRange, int gridCount);
    void setDataCount(int xCount, int yCount, int zCount);
    void setDataSource(float *x_mat, float *y_mat, float *z_mat, float *bpp);

signals:

protected:
    //对3个纯虚函数的重定义
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void mousePressEvent(QMouseEvent *event);//鼠标按下的时候调用该函数
    void mouseMoveEvent(QMouseEvent *event);//鼠标按下状态中，移动的时候调用
    void wheelEvent(QWheelEvent *event);//鼠标上下滚轮的时候会调用

private:
    //绘制坐标轴
    void drawAxis(double pt1x, double pt1y, double pt1z,
                  double pt2x, double pt2y, double pt2z, const char *axisstr);
    //绘制网格
    void drawGrid(double pt1x, double pt1y, double pt1z,
                  double pt2x, double pt2y, double pt2z, int num);
    //绘制三维点云
    void drawPointCloud();

public slots:

private:
    bool m_bIsDrawAll;//是否绘制全部数据
    GLdouble m_rotationX;
    GLdouble m_rotationY;
    GLdouble m_rotationZ;//XYZ旋转刻度
    int m_rotationStep;//旋转步长(旋转快慢)
    QPoint m_lastPos;//记录上一次点位
    int m_gridCount;//网格的条数
    GLdouble m_zoom;//整体缩放比例
    int m_xRange;
    int m_yRange;
    int m_zRange;//X*Y*Z

    int m_xb;
    int m_ya;
    int m_zc;
    float *m_pxMat;//数据源
    float *m_pyMat;
    float *m_pzMat;
    float *m_pBpp;

    ColorMap m_colorMap;//色图
};

#endif // GLWIDGET_H
