#ifndef FILE_H
#define FILE_H

#include <QObject>
#include <QFileInfo>

class File : public QObject
{
    Q_OBJECT
private:
    int size;
    bool existing;
    QString path;
public:
    explicit File(const QString &path);
    int getSize(){
        return size;
    }
    bool getExisting(){
        return existing;
    }
    QString getPath(){
        return path;
    }
    void updateStatus();
signals:
    fileChanged();
};

#endif // FILE_H
