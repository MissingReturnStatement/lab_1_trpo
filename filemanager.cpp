#include "filemanager.h"

void FileManager::addFile(QString path)
{
    File *f= new File(path);
    files_on_checking.push_back(f);
    connect(f,&File::fileChanged,this,&FileManager::fileChanged);
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
    connect(this,&FileManager::writeChanges,logger,&ILog::log);
}

FileManager::~FileManager()
{
    for (File *f: files_on_checking){
        delete f;
    }
}

void FileManager::fileChanged(File *f)
{

    emit writeChanges(f->getPath());
}
