#include "twitter.h"

Twitter::Twitter():consumerKey("gHgu7FSS5Oo4x2eSekIEvrsHt"), consumerSecret("jMQD7I2ovMuZFkZNQEvh3yx1FB2omOKXOlTgg6tliOvVDeeKzY"),
    userID("2891789529"), accessTokenKey(""), accessTokenSecret(""), authorizeUrl("")
{
    QObject::connect(this, &Twitter::userDataIsSet, this, &Twitter::authorise);
}

void Twitter::setPersonalData(QString username, QString password)
{
    setUsername(username.toStdString());
    setPassword(password.toStdString());
    emit userDataIsSet();
}

void Twitter::setUsername(std::string username)
{
    objTwit.setTwitterUsername(username);
}

void Twitter::setPassword(std::string password)
{
    objTwit.setTwitterPassword(password);
}

void Twitter::authorise()
{
    this->authorisingApp();
    this->makeRequest();

    finalData = this->parseJsonToStr();

    FileManager fileWithTwits;
    fileWithTwits.createFile();
    fileWithTwits.readMessageInFile(finalData);
}

void Twitter::authorisingApp()
{
    objTwit.getOAuth().setConsumerKey(consumerKey);
    objTwit.getOAuth().setConsumerSecret(consumerSecret);
    objTwit.oAuthRequestToken(authorizeUrl);
    objTwit.oAuthHandlePIN(authorizeUrl);
    objTwit.oAuthAccessToken();
    objTwit.getOAuth().getOAuthTokenKey(accessTokenKey);
    objTwit.getOAuth().getOAuthTokenSecret(accessTokenSecret);
}

QString Twitter::makeRequest()
{
    std::string outWebResp;

    objTwit.timelineHomeGet(userID);
    objTwit.getLastWebResponse(outWebResp);
    return QString::fromStdString(outWebResp);
}

QString Twitter::parseJsonToStr()
{
    QString textOfTwits("");

    QString textOfFullRequest = this->makeRequest();
    QJsonDocument documentWithTwits = QJsonDocument::fromJson(textOfFullRequest.toUtf8());
    QJsonArray jsonArray = documentWithTwits.array();

    foreach (const QJsonValue & value, jsonArray)
    {
        QJsonObject singleTwit = value.toObject();
        QJsonObject userInfo = singleTwit["user"].toObject();
        textOfTwits += "Date of publication: " + singleTwit["created_at"].toString() +"\n";
        textOfTwits +=  "Author: " + userInfo["name"].toString() +"\n";
        textOfTwits += "text: " + singleTwit["text"].toString() +"\n";
        textOfTwits += "\n";
    }

    return textOfTwits;
}
