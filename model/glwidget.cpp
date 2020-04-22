#include <QDebug>
#include <QtMath>
#include <QMouseEvent>
#include <QWheelEvent>

#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    m_bIsDrawAll = true;
    m_rotationX = 0.0;
    m_rotationY = -45.0;//调整面对用户的一面
    m_rotationZ = 0.0;
    m_rotationStep = 150;
    m_gridCount = 10;
    m_zoom = 0.1;
    m_xRange = 100;
    m_yRange = 100;
    m_zRange = 100;
    m_xb = 0;
    m_ya = 0;
    m_zc = 0;
    m_pxMat = nullptr;
    m_pyMat = nullptr;
    m_pzMat = nullptr;
    m_pBpp = nullptr;
}

GLWidget::~GLWidget()
{
    if(m_pxMat)
    {
        delete []m_pxMat;
    }
    if(m_pyMat)
    {
        delete []m_pyMat;
    }
    if(m_pzMat)
    {
        delete []m_pzMat;
    }
    if(m_pBpp)
    {
        delete []m_pBpp;
    }
}

void GLWidget::setDataRange(int xRange, int yRange, int zRange, int gridCount)
{
    m_xRange = xRange;
    m_yRange = yRange;
    m_zRange = zRange;
    m_gridCount = gridCount;
}

void GLWidget::setDataCount(int xCount, int yCount, int zCount)
{
    m_xb = xCount;
    m_ya = yCount;
    m_zc = zCount;
}

void GLWidget::setDataSource(float *x_mat, float *y_mat, float *z_mat, float *bpp)
{
    if(m_pxMat)
    {
        delete []m_pxMat;
    }
    if(m_pyMat)
    {
        delete []m_pyMat;
    }
    if(m_pzMat)
    {
        delete []m_pzMat;
    }
    if(m_pBpp)
    {
        delete []m_pBpp;
    }
    m_pxMat = x_mat;
    m_pyMat = y_mat;
    m_pzMat = z_mat;
    m_pBpp = bpp;
    updateGL();//每次updateGl都会去调用paintGl函数
}

//此处开始对OpenGL进行所以设置
void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    qglClearColor(QColor(255, 255, 255));//设置背景
//    qglClearColor(QColor(50, 50, 50));
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);//启用深度测试
    glEnable(GL_CULL_FACE);
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLint)w, (GLint)h);               //重置当前的视口
    glMatrixMode(GL_PROJECTION);                        //选择投影矩阵
    glLoadIdentity();                                   //重置投影矩阵
    //设置视口的大小
    //gluPerspective()用来设置透视投影矩阵，这里设置视角为45°，纵横比为窗口的纵横比，最近的位置为0.1，最远的位置为100
    gluPerspective(45.0, (GLfloat)w/(GLfloat)h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);                         //选择模型观察矩阵
    glLoadIdentity();                                   //重置模型观察矩阵
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// 清屏及深度缓存
    glLoadIdentity();// 重置模型观察矩阵

    glTranslatef(0.0, -5.0, -20.0);//下移5个单位，移入屏幕20个单位
    glScalef(m_zoom, m_zoom, m_zoom);//整体缩放比例
    glRotatef(m_rotationX, 1.0, 0.0, 0.0);//绕x轴旋转
    glRotatef(m_rotationY, 0.0, 1.0, 0.0);//绕y轴旋转
    glRotatef(m_rotationZ, 0.0, 0.0, 1.0);//绕z轴旋转

    qglColor(QColor(0, 0, 0));
    drawAxis(0, 0, m_zRange, m_xRange, 0, m_zRange, "X/m");//x
    drawAxis(0, 0, m_zRange, 0, m_yRange, m_zRange, "Y/m");//y
    drawAxis(m_xRange, 0, m_zRange, m_xRange, 0, 0, "Z/m");//z

    qglColor(QColor(125, 125, 125));
    drawGrid(0, 0, 0, m_xRange, 0, m_zRange, m_gridCount);//网格x-z面
    drawGrid(0, 0, 0, 0, m_yRange, m_zRange, m_gridCount);//网格y-z面
    drawGrid(0, 0, 0, m_xRange, m_yRange, 0, m_gridCount);//网格x-y面

    drawPointCloud();//绘制三维云点成像图
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    GLdouble dx = GLdouble(event->x() - m_lastPos.x()) / QGLWidget::width();
    GLdouble dy = GLdouble(event->y() - m_lastPos.y()) / QGLWidget::height();
    if(event->buttons() & Qt::LeftButton)
    {
        m_rotationX += m_rotationStep * dy;
        m_rotationY += m_rotationStep * dx;
    }
    else if(event->buttons() & Qt::RightButton)
    {
        m_rotationZ += m_rotationStep * dy;
    }
    m_lastPos = event->pos();
    updateGL();//每次updateGl都会去调用paintGl函数
}

void GLWidget::wheelEvent(QWheelEvent *event)
{
    if(event->delta() > 0)
    {
            m_zoom += 0.05;
    }//滚轮往上滚
    else
    {
        if(0.11 < m_zoom)
            m_zoom -= 0.05;
    }//滚轮往下滚
    updateGL();//每次updateGl都会去调用paintGl函数
}

void GLWidget::drawAxis(double pt1x, double pt1y, double pt1z, double pt2x, double pt2y, double pt2z, const char *axisstr)
{
    const char *str = "XYZ";
    glEnable(GL_LINE_STIPPLE);
    glLineWidth(2.0f);//设置直线的宽度
    glLineStipple(1, 0xffff);
    glBegin(GL_LINES);
    glVertex3f(pt1x, pt1y, pt1z);
    glVertex3f(pt2x, pt2y, pt2z);
    glEnd();
    glDisable(GL_LINE_STIPPLE);//根据两点画X/Y/Z轴

    QFont font = QFont("Arial");
    font.setPointSize(10);
    renderText(pt2x, pt2y, pt2z, axisstr, font);

    if(str[0] == axisstr[0])
    {
        int xLen = m_xRange / m_gridCount;
        for(int x = pt1x; x < pt2x;)
        {
            renderText(x, pt1y, pt1z + 5, QString::number(x), font);
            x += xLen;
        }
    }
    if(str[1] == axisstr[0])
    {
        int yLen = m_yRange / m_gridCount;
        for(int y = pt1y + yLen; y < pt2y;)
        {
            renderText(pt1x, y, pt1z + 5, QString::number(y), font);
            y += yLen;
        }
    }
    if(str[2] == axisstr[0])
    {
        int zLen = m_zRange / m_gridCount;//间隔
        for(int z = pt2z + zLen; z < pt1z;)
        {
            renderText(pt1x + 3, pt1y, z, QString::number(z), font);
            z += zLen;
        }
    }
}

void GLWidget::drawGrid(double pt1x, double pt1y, double pt1z, double pt2x, double pt2y, double pt2z, int num)
{
    Q_ASSERT(num);
    double xLen = (pt2x - pt1x) / num;
    double yLen = (pt2y - pt1y) / num;
    double zLen = (pt2z - pt1z) / num;//间隔
    int xi = 0;
    int yi = 0;
    int zi = 0;

    glEnable(GL_LINE_STIPPLE);//开启画虚线功能。glEnable不能写在glBegin和glEnd两个函数中间。
    glLineWidth(0.1f);//设置直线的宽度
    //线条样式(第一个是重复的次数，第二个是用一个16-bit的数来控制，0表示不画，1表示画)
    glLineStipple(1, 0xffff);
    glBegin(GL_LINES);
    //绘制平行于X的直线
    for(zi = 0; zi <= num; zi++)
    {
        double z = zLen * zi + pt1z;
        for (yi = 0; yi <= num; yi++)
        {
            double y = yLen * yi + pt1y;
            glVertex3f(pt1x, y, z);
            glVertex3f(pt2x, y, z);
        }
    }
    //绘制平行于Y的直线
    for(zi = 0; zi <= num; zi++)
    {
        double z = zLen * zi + pt1z;
        for (xi = 0; xi <= num; xi++)
        {
            double x = xLen * xi + pt1x;
            glVertex3f(x, pt1y, z);
            glVertex3f(x, pt2y, z);
        }
    }
    //绘制平行于Z的直线
    for(yi = 0; yi <= num; yi++)
    {
        double y = yLen * yi + pt1y;
        for (xi = 0; xi <= num; xi++)
        {
            double x = xLen * xi + pt1x;
            glVertex3f(x, y, pt1z);
            glVertex3f(x, y, pt2z);
        }
    }
    glEnd();
    glDisable(GL_LINE_STIPPLE);//关闭画虚线功能。
}

void GLWidget::drawPointCloud()
{

    if(!m_pxMat || !m_pyMat || !m_pzMat || !m_pBpp)
    {
        return;
    }
    glPointSize(5);
    glBegin(GL_POINTS);
    for(int z = 0; z < m_zc ;z++)
    {
        for(int y = 0; y < m_ya ;y++)
        {
            for(int x = 0; x < m_xb ;x++)
            {
                float value = m_pBpp[z*m_ya*m_ya + y*m_xb + x] * 100;
                if(value < 5)//过滤噪声点
                {
                    continue;
                }
                QColor color = m_colorMap.color(value);
                qglColor(color);
                glVertex3f(m_pxMat[x], m_pyMat[y], m_pzMat[z]);
            }
        }
    }
    glEnd();
}

