#include "filemanager.h"

void FileManager::addFile(QString path)
{
    File *f= new File(path);
    for (File *file: files_on_checking){
        if (file->getPath() == path){
            QTextStream print_stream(stdout);
            print_stream<<"file already under checking"<<Qt::endl;
            return;
        }
    }
    if (f){
    files_on_checking.push_back(f);
    connect(f,&File::fileChanged,this,&FileManager::fileChanged);
    }
    else{
        QTextStream print_stream(stdout);
        print_stream<<"file nullptr"<<Qt::endl;
    }
}

void FileManager::updateFileStatus()
{
    for (File *f: files_on_checking){
        f->updateStatus();
    }

}

FileManager::FileManager(ILog *l)
{

    logger = l;
    if (logger){
    connect(this,&FileManager::writeChanges,logger,&ILog::log);
    }
    else{
        QTextStream print_stream(stdout);
        print_stream<<"logger is not initialized"<<Qt::endl;
    }
}

FileManager::~FileManager()
{
    for (File *f: files_on_checking){
        delete f;
    }
}

void FileManager::fileChanged(File *f, bool pref_exist)
{
    QString str;
    str.setNum(f->getSize());
    if (!f->getExisting()){
        emit writeChanges(f->getPath() + " file was deleted or replaced");
    }
    else if (f->getExisting() && !pref_exist){
        emit writeChanges(f->getPath() + " file was BORN");
    }
    else emit writeChanges(f->getPath() + " file size changed new size: "+str);
}
