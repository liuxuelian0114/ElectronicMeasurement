#ifndef PULSECOMPRESSIONIMAGE_H
#define PULSECOMPRESSIONIMAGE_H

#include <QObject>
#include <QVector>
#include <QColor>

class PulseCompressionImage : public QObject
{
    Q_OBJECT
public:
    explicit PulseCompressionImage(QObject *parent = 0);
    ~PulseCompressionImage();
    QImage *drawImage(float *data, int r, int c);
private:
    void initColorMap();

private:
    QVector<QColor *> m_colorMap;
};

#endif // PULSECOMPRESSIONIMAGE_H
