#ifndef TWITTERFETCHER_H
#define TWITTERFETCHER_H

#include <string>
#include <vector>

class TwitterFetcher {
public:
    TwitterFetcher();
    std::vector<std::string> FetchTweets(const std::string& username);
};

#endif // TWITTERFETCHER_H
