#ifndef UNIQUEFILENAME_H
#define UNIQUEFILENAME_H

#include <QString>
#include <QFileInfo>
#include <QDir>

class UniqueFileName
{
    public:
    explicit UniqueFileName();
    static inline QString newName(QString str)
    {
        int index=1;
        QString fileName=str;
        QFileInfo fileinfo;
        fileinfo.setFile(fileName);
        while(fileinfo.exists()){
            QString completeName;
            completeName=fileinfo.completeBaseName();
            if(fileinfo.completeBaseName().endsWith( QString::number(index).prepend(" (").append(")") ))
            {
                completeName=completeName.left( completeName.lastIndexOf( QString::number(index).prepend(" (").append(")") ) );
                index++;
            }
            fileName=fileinfo.path()
                    .append(QDir::separator())
                    .append( completeName )
                    .append( QString::number(index).prepend(" (").append(")") )
                    .append( fileinfo.suffix().prepend(".") );
            fileinfo.setFile(fileName);
        }
        return fileName;
    }
};

#endif // UNIQUEFILENAME_H
