#ifndef PULSESCENE_H
#define PULSESCENE_H

#include <QGraphicsScene>


class PulseScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PulseScene(QObject *parent = 0);
    ~PulseScene();
    void setBandRange(int band);
    void updateImage(QImage *image, int r, int c);
protected:
    virtual void drawBackground(QPainter *painter, const QRectF &rect);
    virtual void drawForeground(QPainter *painter, const QRectF &rect);
private:
    QImage *m_pImage;
    int m_row;
    int m_col;
    int m_bandRange;
};

#endif // PULSESCENE_H
