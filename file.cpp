#include "file.h"

File::File(const QString &path):path(path){
    QFileInfo file_info(path);
    existing = file_info.exists();
    size = file_info.size();

}
void File::updateStatus()
{
    QFileInfo file_info(path);
    bool existance = file_info.exists();
    int new_size = file_info.size();
    if (size != new_size || existing != existance){
        emit fileChanged(this);
        size = new_size;
        existing = existance;
    }

}
