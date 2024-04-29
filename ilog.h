#ifndef ILOG_H
#define ILOG_H

#include <QObject>

class ILog : public QObject
{
    Q_OBJECT
public slots:
    virtual void log(QString str)=0;
};


#endif // ILOG_H
