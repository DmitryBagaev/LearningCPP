#include "file.h"

void FileManager::createFile()
{
    tweetsFile.setFileName(filepass);
    tweetsFile.open(QIODevice::WriteOnly | QIODevice::Truncate);
    if (!tweetsFile.exists())
        qDebug() << "File hasn\'t been created.";

}

void FileManager::readMessageInFile(QString data)
{
    QTextStream outStream(&tweetsFile);
    outStream << data;
}


FileManager::~FileManager()
{
    tweetsFile.close();
}
