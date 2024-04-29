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
    bool pref_exist = existing;
    int new_size = file_info.size();
    int pref_size = size;
    if (size != new_size || existing != existance){
        size = new_size;
        existing = existance;
        emit fileChanged(this,pref_exist);
        //QTextStream print_stream(stdout);
        //print_stream<<pref_exist<<" existance"<<Qt::endl;
    }

}
