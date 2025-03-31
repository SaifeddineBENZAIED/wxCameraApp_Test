#include "TwitterFetcher.h"
#include <wx/log.h>

TwitterFetcher::TwitterFetcher() {
    // Initialisation si n�cessaire
}

std::vector<std::string> TwitterFetcher::FetchTweets(const std::string& username) {
    std::vector<std::string> tweets;
    wxLogMessage("Simulation de la r�cup�ration des tweets pour l'utilisateur: %s", username);

    // Simuler quelques tweets
    tweets.push_back(username + " : Tweet 1");
    tweets.push_back(username + " : Tweet 2");
    tweets.push_back(username + " : Tweet 3");

    return tweets;
}
