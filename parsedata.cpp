#include <QDebug>

#include "parsedata.h"

ParseData::ParseData(QObject *parent) :
    QObject(parent)
{
}

ParseData::~ParseData()
{

}

void ParseData::onDataChanged(QByteArray data)
{
//    qDebug() << "on ParseData, onDataChanged: " << QString::number(data[0]);
}
