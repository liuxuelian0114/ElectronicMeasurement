#include "PulseScene.h"
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <QGraphicsView>
PulseScene::PulseScene(QObject *parent) :
    QGraphicsScene(parent)
{
    m_pImage = nullptr;
    m_row = 0;
    m_col = 0;
}

PulseScene::~PulseScene()
{
    if(m_pImage)
    {
        delete m_pImage;
    }
}

void PulseScene::updateImage(QImage *image, int r, int c)
{
    if(m_pImage)
    {
        delete m_pImage;
    }
    m_pImage = image;
    m_row = r;
    m_col = c;
    update();
}



void PulseScene::setBandRange(int band)
{
    m_bandRange = band;
}

void PulseScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(painter);
    Q_UNUSED(rect);
    if(this->views().size() > 0)
    {
        QGraphicsView *view = this->views().at(0);
        this->setSceneRect(0, 0, view->width(), view->height());
    }

}

void PulseScene::drawForeground(QPainter *painter, const QRectF &rect)
{
    if(!m_pImage)
    {
        return;
    }
    Q_UNUSED(rect);
    float x = 40;
    float y = 40;
    float w = sceneRect().width() - 80;
    float h = sceneRect().height() - 80;

    QImage image = m_pImage->scaled(w, h, Qt::IgnoreAspectRatio);
    painter->drawImage(x, y, image);

    painter->setPen(Qt::black);
    painter->setBrush(Qt::white);

    int ySpace = 5;
    float yDelta = h / (float)ySpace;
    int band = m_bandRange;
    QTextOption option;

    option.setAlignment(Qt::AlignRight | Qt::AlignBottom);
    for(int i = 0; i < ySpace + 1; i++)
    {
        float yPos = y + i * yDelta;
        QRectF textRect(x - 40, yPos - 20, 40, 20);
//        painter->drawRect(textRect);
        painter->drawText(textRect, QString::number(band), option);

        band = band - m_bandRange / (float)ySpace ;
    }

    int xSpace = 5;
    int xDelta = m_col / xSpace;
    QString xStr = QString::number(xDelta);
    for(int i = 1; i < xStr.length(); i++)
    {
        xStr = xStr.replace(i, 1, QChar('0'));
    }
    xDelta = xStr.toInt();
    int xLabel = 0;
    option.setAlignment(Qt::AlignTop | Qt::AlignLeft);
    for(int i = 0; i < xSpace; i++)
    {
        float xPos = x + i * w / (float)xSpace;
        QRectF textRect(xPos, y + h, 40, 20);
//        painter->drawRect(textRect);
        painter->drawText(textRect, QString::number(xLabel), option);
        xLabel += xDelta;
    }

}
