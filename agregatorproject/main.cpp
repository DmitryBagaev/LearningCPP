#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QByteArray>
#include "twitter.h"
#include "file.h"
#include "twitcurl.h"
#include <QBuffer>
#include <QIODevice>
#include <QTextStream>
#include <json.h>
#include <QVector>


QT_USE_NAMESPACE

const std::string consumerKey="gHgu7FSS5Oo4x2eSekIEvrsHt";
const std::string consumerSecret="jMQD7I2ovMuZFkZNQEvh3yx1FB2omOKXOlTgg6tliOvVDeeKzY";

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileManager fileWithTwits;
    fileWithTwits.createFile();

    Twitter agregator;
    agregator.setPersonalData("2889529", "DrBagaev", "cogitoergosum23");
    agregator.authorisingApp();
    agregator.makeRequest();
    agregator.parseStrToJson();
    fileWithTwits.readMessageInFile(agregator.writeTwitsInFile());

    return 0;
    return a.exec();
}
