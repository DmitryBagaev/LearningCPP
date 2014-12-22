#include "twitter.h"

Twitter::Twitter():consumerKey("gHgu7FSS5Oo4x2eSekIEvrsHt"), consumerSecret("jMQD7I2ovMuZFkZNQEvh3yx1FB2omOKXOlTgg6tliOvVDeeKzY"),
    userID("2891789529"), jsonTwits(5000)
{
        QObject::connect(this, &Twitter::userDataIsSet, this, &Twitter::authorise);
}


void Twitter::authorise()
{
    this->authorisingApp();
    this->makeRequest();
    this->parseJsonToStr();
    finalData = this->makeStringForWritingIntoFile();
    FileManager fileWithTwits;
    fileWithTwits.createFile();
    fileWithTwits.readMessageInFile(finalData);
}


void Twitter::setPersonalData(QString username, QString password)
{
    std::string usernamestd = username.toStdString();
    std::string passwordstd = password.toStdString();
    setUsername(usernamestd);
    setPassword(passwordstd);
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

void Twitter::makeRequest()
{
    std::string outWebResp;

    objTwit.timelineHomeGet(userID);
    objTwit.getLastWebResponse(outWebResp);
    outData = QString::fromStdString(outWebResp);
}

void Twitter::parseJsonToStr()
{
    int position(1);
    int beginningPosition(0);
    int twitLength;
    int iter(0);

    outData.remove(0,1);
    outData.remove(outData.length()-1,1);

    while (position < (outData.length()) )
    {
        if ( (outData[position] == '}') && ( (outData[position+1]== ',')&& (outData[position+2] == '{'&& (outData[position+3] == '"')) ) )
        {
            twitLength = position + 1 - beginningPosition;
            jsonTwits[iter] = outData.mid(beginningPosition, twitLength);
            beginningPosition = position + 2;
            iter++;
        }
        position++;
    }
}

QString Twitter::makeStringForWritingIntoFile()
{

    QString textOfTwits("");
    int iter(0);

    while(!jsonTwits[iter].isEmpty())
    {

        QtJson::JsonObject result = QtJson::parse(jsonTwits[iter]).toMap();
        QtJson::JsonObject userInfo = result["user"].toMap();

        textOfTwits += "Date of publication: " + result["created_at"].toString() +"\n";
        textOfTwits +=  "Author: " + userInfo["name"].toString() +"\n";
        textOfTwits += "text: " + result["text"].toString() +"\n";
        textOfTwits += "\n";
        iter++;
    }
    return textOfTwits;
}
