#ifndef CXTIME_H
#define CXTIME_H
#include"cxtime.h"
#include <QObject>

class CXTime : public QObject
{
    Q_OBJECT
private:
    double Num;
public:
    explicit CXTime(QObject *parent = 0);

signals:

public slots:
    void Add(){++Num;};
    double Value();
};

#endif // CXTIME_H
