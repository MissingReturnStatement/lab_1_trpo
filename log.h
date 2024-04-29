#ifndef LOG_H
#define LOG_H
#include <QTextStream>
#include "ilog.h"
class Log : public ILog
{
    Q_OBJECT
public:
    Log();
public slots:
    void log(QString str) override;
};

#endif // LOG_H
