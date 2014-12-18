#ifndef TWITTER_HEADER
#define TWITTER_HEADER
#include <QObject>
#include "twitcurl.h"
#include <QByteArray>
#include <QDebug>
#include <QString>
#include <QVector>
#include <json.h>

class Twitter : public QObject
{
    Q_OBJECT

private:
    const std::string consumerKey;
    const std::string consumerSecret;
    std::string username;
    std::string password;
    std::string userID;
    QVector<QString>jsonTwits;
    std::string accessTokenKey;
    std::string accessTokenSecret;
    std::string authorizeUrl;
    twitCurl objTwit;
    QString outData;
public:
    Twitter():consumerKey("gHgu7FSS5Oo4x2eSekIEvrsHt"), consumerSecret("jMQD7I2ovMuZFkZNQEvh3yx1FB2omOKXOlTgg6tliOvVDeeKzY"),
        username("DrBagaev"), password("cogitoergosum23"), userID("2891789529"), jsonTwits(5000){}
    void setPersonalData(QString userID, QString username, QString password);
    void setID(std::string userID);
    void setUsername(std::string username);
    void setPassword(std::string password);
    void authorisingApp();
    void makeRequest();
    void parseStrToJson();
    QString writeTwitsInFile();
};

#endif
