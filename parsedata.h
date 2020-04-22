#ifndef PARSEDATA_H
#define PARSEDATA_H

#include <QObject>

class ParseData : public QObject
{
    Q_OBJECT
public:
    explicit ParseData(QObject *parent = 0);
    ~ParseData();

signals:

public slots:
    void onDataChanged(QByteArray data);

};

#endif // PARSEDATA_H
