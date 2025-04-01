#ifndef TWITTER_API_H
#define TWITTER_API_H

#include <string>

class TwitterAPI {
public:
    static std::string GetTweets(const std::string& bearerToken, const std::string& query);
};

#endif
