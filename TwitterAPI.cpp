#include "TwitterAPI.h"
#include <curl/curl.h>
#include <wx/jsonval.h>
#include <wx/msgdlg.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userData) {
    size_t totalSize = size * nmemb;
    userData->append((char*)contents, totalSize);
    return totalSize;
}

std::string TwitterAPI::GetTweets(const std::string& bearerToken, const std::string& query) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        wxMessageBox("Erreur d'initialisation de cURL", "Erreur", wxICON_ERROR);
        return "";
    }

    std::string url = "https://api.twitter.com/2/tweets/search/recent?query=" + query;
    std::string response;

    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, ("Authorization: Bearer " + bearerToken).c_str());

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);

    return response;
}
