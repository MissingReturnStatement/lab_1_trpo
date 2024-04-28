#include "log.h"

Log::Log() {}

void Log::log(QString str)
{
    QTextStream print_stream(stdout);
    print_stream <<str<<Qt::endl;
}
