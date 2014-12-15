#include "twitter.h"

void Twitter::setPersonalData(std::string userID, std::string username, std::string password)
{
    setID(userID);
    setUsername(username);
    setPassword(password);
}

void Twitter::setID(std::string userID)
{
    this->userID = userID;
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
    objTwit.timelineHomeGet(userID);
    std::string outWebResp;

    objTwit.getLastWebResponse(outWebResp);
    std::cout << outWebResp;
    if (!outWebResp.length())
    {
        qDebug() << "Error";
    }
}
