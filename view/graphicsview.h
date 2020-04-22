 #ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphicsView(QWidget *parent = 0);

    void setValueOfXY(const float &nowX, const float &nowY);

signals:

public slots:

private:
    QGraphicsScene *m_pScene;
    QGraphicsTextItem *m_pTextItem;
    QGraphicsLineItem *m_pXLineItem;
    QGraphicsLineItem *m_pYLineItem;
    QGraphicsRectItem *m_pRectItem;

    int m_beforeX;
    int m_beforeY;

    qreal m_stepRectX;
    qreal m_stepRectY;

    qreal m_stepLineX;
};

#endif // GRAPHICSVIEW_H
