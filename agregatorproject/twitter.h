#ifndef TWITTER_HEADER
#define TWITTER_HEADER
#include "twitcurl.h"
#include <QString>
#include <QVector>
#include <json.h>
#include <mainwindow.h>
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
    QVector<QString>jsonTwits;
    std::string accessTokenKey;
    std::string accessTokenSecret;
    std::string authorizeUrl;
    twitCurl objTwit;
    QString outData;

public:
    QString finalData;

public:
    Twitter():consumerKey("gHgu7FSS5Oo4x2eSekIEvrsHt"), consumerSecret("jMQD7I2ovMuZFkZNQEvh3yx1FB2omOKXOlTgg6tliOvVDeeKzY"),
        userID("2891789529"), jsonTwits(5000){}
    void authorise();
    void setPersonalData (MainWindow* window);
    void setUsername(std::string username);
    void setPassword(std::string password);
    void authorisingApp();
    void makeRequest();
    void parseStrToJson();
    QString writeTwitsInFile();

signals:
    void userDataIsSet();
    void authorizationCompleted();
};

#endif
