#include "ScatterWidget.h"

#include <QVBoxLayout>
#include <QApplication>

ScatterWidget::ScatterWidget(QWidget *parent) :
    QDialog(parent),
    m_xCount(0), m_yCount(0), m_zCount(0),
    m_xRange(0), m_yRange(0), m_zRange(0),
    m_pxMat(Q_NULLPTR), m_pyMat(Q_NULLPTR), m_pzMat(Q_NULLPTR),
    m_bpp(Q_NULLPTR),
    m_pScatterDataArray(Q_NULLPTR)
{
    setWindowFlags(windowFlags() & (~Qt::WindowContextHelpButtonHint));

    iniGraph3D();
    resize(800, 600);
}

void ScatterWidget::setDataCount(int xCount, int yCount, int zCount)
{
    m_xCount = xCount;
    m_yCount = yCount;
    m_zCount = zCount;
}

void ScatterWidget::setDataRange(int xRange, int yRange, int zRange)
{
    m_xRange = xRange;
    m_yRange = yRange;
    m_zRange = zRange;
}

void ScatterWidget::setDataSource(float *x_mat, float *y_mat, float *z_mat, float *bpp)
{
    if(m_pxMat)
        delete [] m_pxMat;
    if(m_pyMat)
        delete [] m_pyMat;
    if(m_pzMat)
        delete [] m_pzMat;
    if(m_bpp)
        delete [] m_bpp;
    m_pxMat = x_mat;
    m_pyMat = y_mat;
    m_pzMat = z_mat;
    m_bpp = bpp;

    drawPointCloud();
}

void ScatterWidget::iniGraph3D()
{
    m_p3DScatter = new Q3DScatter();
    QWidget *graphContainer = QWidget::createWindowContainer(m_p3DScatter); //Q3DBars继承自QWindow，必须如此创建

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(graphContainer);

    //创建坐标轴
    m_p3DScatter->axisX()->setTitle("axis X");
    m_p3DScatter->axisX()->setTitleVisible(true);

    m_p3DScatter->axisY()->setTitle("axis Y");
    m_p3DScatter->axisY()->setTitleVisible(true);

    m_p3DScatter->axisZ()->setTitle("axis Z");
    m_p3DScatter->axisZ()->setTitleVisible(true);

    m_p3DScatter->activeTheme()->setLabelBackgroundEnabled(false);
    m_p3DScatter->setShadowQuality(QAbstract3DGraph::ShadowQualityNone);

    setLayout(layout);
}

void ScatterWidget::drawPointCloud()
{

    if(nullptr == m_pxMat || nullptr == m_pyMat || nullptr == m_pzMat || nullptr == m_bpp)
    {
        return;
    }
    QList<QScatter3DSeries *> seriesList = m_p3DScatter->seriesList();
    for (int i = 0; i < seriesList.size(); ++i)
    {
        m_p3DScatter->removeSeries(seriesList.at(i));
    }
    QLinearGradient linearGrad(QPointF(0, 0), QPointF(10, 10));
    for(int z = 0; z < m_zCount ;z++)
    {
        for(int y = 0; y < m_yCount ;y++)
        {
            for(int x = 0; x < m_xCount ;x++)
            {
                float value = m_bpp[z*m_yCount*m_xCount + y*m_xCount + x] * 100;
                if(value < 5)//过滤噪声点
                {
                    continue;
                }
                QColor color = m_colorMap.color(value);
                linearGrad.setColorAt(0, color);
                linearGrad.setColorAt(1, color);

                QScatterDataProxy *proxy = new QScatterDataProxy();
                m_p3DSeries = new QScatter3DSeries(proxy);  //创建序列
                m_p3DSeries->setItemLabelFormat("(@xLabel @yLabel @zLabel)");
                m_p3DSeries->setMeshSmooth(true);
                m_p3DSeries->setMesh(QAbstract3DSeries::MeshBevelCube);
                m_p3DSeries->setItemSize((float)0.07);
                m_p3DSeries->setBaseGradient(linearGrad);
                m_p3DSeries->setColorStyle(Q3DTheme::ColorStyle::ColorStyleObjectGradient);
                m_p3DScatter->addSeries(m_p3DSeries);

                m_pScatterDataArray = new QScatterDataArray;
                m_pScatterDataArray->append(QVector3D(m_pxMat[x], m_pyMat[y], m_pzMat[z]));

                m_p3DSeries->dataProxy()->resetArray(m_pScatterDataArray);

                linearGrad.setColorAt(0, QColor("red"));
                linearGrad.setColorAt(1, QColor("red"));
                m_p3DSeries->setSingleHighlightGradient(linearGrad);

                QApplication::processEvents();
            }
        }
    }

    emit done();
}
