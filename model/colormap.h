#ifndef COLORMAP_H
#define COLORMAP_H
#include <QColor>
#include <QVector>

class ColorMap
{
public:
    ColorMap();
    QColor color(int);
private:
    void initColorMap();
private:
    QVector<QColor> m_colorMap;
};

#endif // COLORMAP_H
