#include "file.h"

void FileManager::createFile()
{
    tweetsFile.setFileName(filepass);
 tweetsFile.open(QIODevice::ReadWrite);
    if (!tweetsFile.exists())
        qDebug() << "File hasn\'t been created.";

}


FileManager::~FileManager()
{
    tweetsFile.close();
}
