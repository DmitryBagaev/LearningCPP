#ifndef TWITTER_HEADER
#define TWITTER_HEADER
#include "twitcurl.h"
#include <QJsonDocument>
#include <QJsonObject>
#include  <QJsonArray>
#include <QJsonValue>
#include "mainwindow.h"
#include "file.h"

class Twitter : public QObject
{
    Q_OBJECT

private:
    const std::string consumerKey;
    const std::string consumerSecret;
    QString username;
    QString password;
    std::string userID;
    std::string accessTokenKey;
    std::string accessTokenSecret;
    std::string authorizeUrl;
    twitCurl objTwit;

public:
    QString finalData;

public:
    Twitter();
    void authorise();
    void setPersonalData (QString username, QString password);
    void setUsername(std::string username);
    void setPassword(std::string password);
    void authorisingApp();
    QString makeRequest();
    QString parseJsonToStr();

signals:
    void userDataIsSet();
    void authorizationCompleted();
};

#endif
