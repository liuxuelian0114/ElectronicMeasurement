#include "graphicsview.h"
#include <QDebug>

GraphicsView::GraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{
    m_pScene = new QGraphicsScene();
//    m_pScene->setSceneRect(this->rect());

    m_pTextItem = new QGraphicsTextItem("x: 0 cm   y: 0 cm");
    m_pScene->addItem(m_pTextItem);
    m_pTextItem->setPos(190, -160);

    m_pXLineItem = new QGraphicsLineItem();
    QPen pen;

    m_pYLineItem = new QGraphicsLineItem();
    pen.setColor(QColor("green"));
    pen.setWidth(26);
    m_pYLineItem->setPen(pen);
    m_pYLineItem->setLine(0, -160, 0, 160);
    m_pScene->addItem(m_pYLineItem);

    pen.setWidth(2);
    pen.setColor(QColor("white"));
    QGraphicsLineItem *verticalSlot = new QGraphicsLineItem(m_pYLineItem);
    verticalSlot->setLine(-4, -169, -4, 140);
    verticalSlot->setPen(pen);

    verticalSlot = new QGraphicsLineItem(m_pYLineItem);
    verticalSlot->setLine(4, -169, 4, 140);
    verticalSlot->setPen(pen);

    pen.setWidth(14);
    pen.setColor(QColor("green"));
    m_pXLineItem->setPen(pen);
    m_pXLineItem->setLine(170, 150, -170, 150);
    m_pScene->addItem(m_pXLineItem);

    m_pRectItem = new QGraphicsRectItem;
    m_pRectItem->setRect(0, 0, 22, 22);
    QBrush brush;
    brush.setColor("black");
    brush.setStyle(Qt::Dense4Pattern);
    pen.setColor(QColor("black"));
    pen.setWidth(2);
    pen.setStyle(Qt::SolidLine);
    m_pRectItem->setPen(pen);
    m_pRectItem->setBrush(brush);
    m_pScene->addItem(m_pRectItem);
    m_pRectItem->setPos(-160, 140);

    this->setScene(m_pScene);

    m_beforeX = 0;
    m_beforeY = 0;
    m_stepRectX = -140;
    m_stepRectY = 130;
    m_stepLineX = 0;
}

void GraphicsView::setValueOfXY(const float &nowX, const float &nowY)
{
    m_pTextItem->setPlainText(QString("x: %1 cm   y: %2 cm").arg(nowX).arg(nowY));

//    m_stepRectX += ((nowX - m_beforeX) * 0.5);
//    m_stepRectY -= ((nowY - m_beforeY) * 0.5);
//    m_pRectItem->setPos(m_stepRectX, m_stepRectY);

//    m_stepLineX -= ((nowY - m_beforeY) * 0.5);
//    m_pXLineItem->setPos(0, m_stepLineX);

//    m_beforeX = nowX;
//    m_beforeY = nowY;
    m_pRectItem->setPos(-160+(nowX/2), 140-(nowY/2));
    m_pXLineItem->setLine(170, 150-(nowY/2),-170, 150-(nowY/2));
    qDebug() <<"m_pRectItem:" <<m_pRectItem->pos().rx() <<","<<m_pRectItem->pos().ry();
    qDebug() <<"m_pXLineItem:" <<m_pXLineItem->pos().rx() <<","<<m_pXLineItem->pos().ry();

}
