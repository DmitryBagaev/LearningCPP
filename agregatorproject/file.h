#ifndef FILE_HEADER
#define FILE_HEADER

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <twitter.h>

class FileManager : public QObject
{
    Q_OBJECT

public:
    QFile tweetsFile;
    const QString filepass = "../agregatorproject/tweetstream.txt";

    void createFile();
    void readMessageInFile(QString data);

    ~FileManager();
};

#endif
