#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QByteArray>
#include "twitter.h"
#include "file.h"
#include "twitcurl.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

QT_USE_NAMESPACE

const std::string consumerKey="gHgu7FSS5Oo4x2eSekIEvrsHt";
const std::string consumerSecret="jMQD7I2ovMuZFkZNQEvh3yx1FB2omOKXOlTgg6tliOvVDeeKzY";

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileManager fileWithTwits;
    fileWithTwits.createFile();

/*
    Twitter agregator;
    agregator.setPersonalData("DrBagaev", "cogitoergosum23", "2891789529");
    agregator.authorisingApp();
    agregator.makeRequest();
*/
///*
      twitCurl objTwit;

    std::string username("DrBagaev");
    std::string password("cogitoergosum23");
    std::string accessTokenKey;
    std::string accessTokenSecret;
    std::string userID("2891789529");
    std::string authorizeUrl;


    objTwit.getOAuth().setConsumerKey(consumerKey);
    objTwit.getOAuth().setConsumerSecret(consumerSecret);
    objTwit.setTwitterUsername(username);
    objTwit.setTwitterPassword(password);

    objTwit.oAuthRequestToken(authorizeUrl);
    objTwit.oAuthHandlePIN(authorizeUrl);
    objTwit.oAuthAccessToken();
    objTwit.getOAuth().getOAuthTokenKey(accessTokenKey);
    objTwit.getOAuth().getOAuthTokenSecret(accessTokenSecret);

    objTwit.timelineHomeGet(userID);

    std::string outWebResp;
    objTwit.getLastWebResponse(outWebResp);

    QString outData = QString::fromStdString( outWebResp);
    qDebug() << outData.toUtf8();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(outData.toUtf8());
    qDebug() << jsonDoc.toBinaryData();

    qDebug() << jsonDoc.isObject() << endl;

    QJsonObject jsonObject = jsonDoc.object();

    qDebug() << jsonObject.contains("created at");

    QJsonArray jsonArray = jsonObject["created_at"].toArray();

    for(auto iter = jsonArray.begin(); iter != jsonArray.end();  ++iter)
    {
        qDebug()<<(*iter).toString();
    }

    //*/


    return 0;
    return a.exec();
}
