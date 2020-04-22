#include "PulseCompressionImage.h"
#include "math.h"
#include <QByteArray>

#include <QFile>
#include <QString>
#include <QDebug>
#include <QImage>
#include <QtMath>

PulseCompressionImage::PulseCompressionImage(QObject *parent) :
    QObject(parent)
{
    initColorMap();
}

PulseCompressionImage::~PulseCompressionImage()
{
    qDeleteAll(m_colorMap);
    m_colorMap.clear();
}

QImage *PulseCompressionImage::drawImage(float* data, int r, int c)
{
    float max = 0;
    float min = 0;

    for(int i = 0; i < r * c; i++)
    {
        float real = data[i * 2];
        float imag = data[i * 2 + 1];
        data[i * 2] = qSqrt(real * real + imag * imag);
        float tmp = fabsf(data[i * 2]);
        data[i * 2] = tmp;
        if(tmp > max)
        {
            max = tmp;
        }
        if(tmp < min)
        {
            min = tmp;
        }

    }

    QImage *image = new QImage(c, r, QImage::Format_ARGB32);

    for(int i = 0; i < c; i++)
    {
        for(int j = 0; j < r; j++)
        {
            int index = (j + i * r)*2;
            float v = data[index];
            image->setPixel(i, j, m_colorMap.at(v / max * 63.0f)->rgb());
        }
    }
    return image;
}

void PulseCompressionImage::initColorMap()
{
    for(int i = 0; i < 64; i++)
    {
        QColor* color = new QColor;
        m_colorMap.append(color);
    }

    m_colorMap.at(0)->setRgbF(0.2422 ,0.1504 ,0.6603);
    m_colorMap.at(1)->setRgbF(0.2504 ,0.1650 ,0.7076 );
    m_colorMap.at(2)->setRgbF(0.2578 ,0.1818 ,0.7511);
    m_colorMap.at(3)->setRgbF(0.2647 ,0.1978 ,0.7952 );
    m_colorMap.at(4)->setRgbF(0.2706 	,	0.2147 	,	0.8364 );
    m_colorMap.at(5)->setRgbF(0.2751 	,	0.2342 	,	0.8710 );
    m_colorMap.at(6)->setRgbF(0.2783 	,	0.2559 	,	0.8991);
    m_colorMap.at(7)->setRgbF(0.2803 	,	0.2782 	,	0.9221);
    m_colorMap.at(8)->setRgbF(0.2813 	,	0.3006 	,	0.9414);
    m_colorMap.at(9)->setRgbF(0.2810 	,	0.3228 	,	0.9579 );

    m_colorMap.at(10)->setRgbF(0.2795 	,	0.3447 	,	0.9717);
    m_colorMap.at(11)->setRgbF(0.2760 	,	0.3667 	,	0.9829);
    m_colorMap.at(12)->setRgbF(0.2699 	,	0.3892 	,	0.9906);
    m_colorMap.at(13)->setRgbF(0.2602 	,	0.4123 	,	0.9952);
    m_colorMap.at(14)->setRgbF(0.2440 	,	0.4358 	,	0.9988 );
    m_colorMap.at(15)->setRgbF(0.2206 	,	0.4603 	,	0.9973 );
    m_colorMap.at(16)->setRgbF(0.1963 	,	0.4847 	,	0.9892 );
    m_colorMap.at(17)->setRgbF(0.1834 	,	0.5074 	,	0.9798 );
    m_colorMap.at(18)->setRgbF(0.1786 	,	0.5289 	,	0.9682 );
    m_colorMap.at(19)->setRgbF(0.1764 	,	0.5499 	,	0.9520 );

    m_colorMap.at(20)->setRgbF(0.1687 	,	0.5703 	,	0.9359 );
    m_colorMap.at(21)->setRgbF(0.1540 	,	0.5902 	,	0.9218 );
    m_colorMap.at(22)->setRgbF(0.1460 	,	0.6091 	,	0.9079 );
    m_colorMap.at(23)->setRgbF(0.1380 	,	0.6276 	,	0.8973 );
    m_colorMap.at(24)->setRgbF(0.1248 	,	0.6459 	,	0.8883 );
    m_colorMap.at(25)->setRgbF(0.1113 	,	0.6635 	,	0.8763 );
    m_colorMap.at(26)->setRgbF(0.0952 	,	0.6798 	,	0.8598 );
    m_colorMap.at(27)->setRgbF(0.0689 	,	0.6948 	,	0.8394 );
    m_colorMap.at(28)->setRgbF(0.0297 	,	0.7082 	,	0.8163 );
    m_colorMap.at(29)->setRgbF(0.0036 	,	0.7203 	,	0.7917 );

    m_colorMap.at(30)->setRgbF(0.0067 	,	0.7312 	,	0.7660 );
    m_colorMap.at(31)->setRgbF(0.0433 	,	0.7411 	,	0.7394 );
    m_colorMap.at(32)->setRgbF(0.0964 	,	0.7500 	,	0.7120 );
    m_colorMap.at(33)->setRgbF(0.1408 	,	0.7584 	,	0.6842 );
    m_colorMap.at(34)->setRgbF(0.1717 	,	0.7670 	,	0.6554 );
    m_colorMap.at(35)->setRgbF(0.1938 	,	0.7758 	,	0.6251 );
    m_colorMap.at(36)->setRgbF(0.2161 	,	0.7843 	,	0.5923 );
    m_colorMap.at(37)->setRgbF(0.2470 	,	0.7918 	,	0.5567 );
    m_colorMap.at(38)->setRgbF(0.2906 	,	0.7973 	,	0.5188 );
    m_colorMap.at(39)->setRgbF(0.3406 	,	0.8008 	,	0.4789 );

    m_colorMap.at(40)->setRgbF(0.3909 	,	0.8029 	,	0.4354 );
    m_colorMap.at(41)->setRgbF(0.4456 	,	0.8024 	,	0.3909 );
    m_colorMap.at(42)->setRgbF(0.5044 	,	0.7993 	,	0.3480 );
    m_colorMap.at(43)->setRgbF(0.5616 	,	0.7942 	,	0.3045 );
    m_colorMap.at(44)->setRgbF(0.6174 	,	0.7876 	,	0.2612 );
    m_colorMap.at(45)->setRgbF(0.6720 	,	0.7793 	,	0.2227 );
    m_colorMap.at(46)->setRgbF(0.7242 	,	0.7698 	,	0.1910 );
    m_colorMap.at(47)->setRgbF(0.7738 	,	0.7598 	,	0.1646 );
    m_colorMap.at(48)->setRgbF(0.8203 	,	0.7498 	,	0.1535 );
    m_colorMap.at(49)->setRgbF(0.8634 	,	0.7406 	,	0.1596 );

    m_colorMap.at(50)->setRgbF(0.9035 	,	0.7330 	,	0.1774 );
    m_colorMap.at(51)->setRgbF(0.9393 	,	0.7288 	,	0.2100 );
    m_colorMap.at(52)->setRgbF(0.9728 	,	0.7298 	,	0.2394 );
    m_colorMap.at(53)->setRgbF(0.9956 	,	0.7434 	,	0.2371 );
    m_colorMap.at(54)->setRgbF(0.9970 	,	0.7659 	,	0.2199 );
    m_colorMap.at(55)->setRgbF(0.9952 	,	0.7893 	,	0.2028 );
    m_colorMap.at(56)->setRgbF(0.9892 	,	0.8136 	,	0.1885 );
    m_colorMap.at(57)->setRgbF(0.9786 	,	0.8386 	,	0.1766 );
    m_colorMap.at(58)->setRgbF(0.9676 	,	0.8639 	,	0.1643 );
    m_colorMap.at(59)->setRgbF(0.9610 	,	0.8890 	,	0.1537 );

    m_colorMap.at(60)->setRgbF(0.9597, 0.9135, 0.1423);
    m_colorMap.at(61)->setRgbF(0.9628, 0.9373, 0.1265);
    m_colorMap.at(62)->setRgbF(0.9691, 0.9606, 0.1064);
    m_colorMap.at(63)->setRgbF(0.9769, 0.9839, 0.0805);
}

