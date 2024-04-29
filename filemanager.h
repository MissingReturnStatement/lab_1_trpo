#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QVector>
#include "log.h"
#include "file.h"
class FileManager : public QObject
{
    Q_OBJECT
public:
    static FileManager& Instance(ILog* l){
        static FileManager file_manager(l);
        return file_manager;
    }
    void addFile(QString path);
    void updateFileStatus();
 private:
    ILog* logger;
    QVector<File*> files_on_checking;
    FileManager(ILog *l);
    FileManager(const FileManager &);
    FileManager & operator=(const FileManager &);
    ~FileManager();
signals:
    writeChanges(QString str);
public slots:
    void fileChanged(File*,bool);
};

#endif // FILEMANAGER_H
