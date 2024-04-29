#include <QCoreApplication>
#include "log.h"
#include "filemanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ILog* l = new Log;
    //l->log(QString("hello"));
    FileManager::Instance(l);
    FileManager::Instance(l).addFile("C:\\trpo_labs\\lab_1_trpo\\something.txt");
    while (true){
        FileManager::Instance(l).updateFileStatus();
    }

    return a.exec();
}
