#include <QCoreApplication>
#include "log.h"
#include "filemanager.h"
#include <thread>

void input_files(ILog *l){
    QTextStream input_stream(stdin),print_stream(stdout);
    int n;
    input_stream >> n;
    for (int i=0; i<n;i++){
        QString file_path;
        print_stream << "input " << n-i << " file paths" <<Qt::endl;
        input_stream >> file_path;
        FileManager::Instance(l).addFile(file_path);
    }
     print_stream <<"files paths added"<<Qt::endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ILog* l = new Log;
    //l->log(QString("hello"));
    FileManager::Instance(l);
    input_files(l);
    //FileManager::Instance(l).addFile("C:\\trpo_labs\\lab_1_trpo\\something.txt");
    while (true){
        FileManager::Instance(l).updateFileStatus();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return a.exec();
}
