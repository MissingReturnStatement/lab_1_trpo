#include <QCoreApplication>
#include "log.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ILog* l = new Log;
    l->log(QString("hello"));

    return a.exec();
}
