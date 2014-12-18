#ifndef FILE_HEADER
#define FILE_HEADER

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QByteArray>
#include <QDebug>

class FileManager : public QObject
{
    Q_OBJECT

public:
    QFile tweetsFile;
    const QString filepass = "../agregatorproject/tweetstream.txt";

    void createFile();
    void readMessageInFile(QString twitInfo);

    ~FileManager();
};

#endif
