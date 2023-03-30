#include <iostream>
#include <string>
#include <curl/curl.h>
#include <sstream>
#include <iterator>
#include <regex>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string *)userp)->append((char *)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    std::string api_key = "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";
    std::string prompt = "mac m1pro怎么安装nlohmann/json库?";

    CURL *curl = curl_easy_init();
    std::string readBuffer;

    if (curl) {
        struct curl_slist *headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, ("Authorization: Bearer " + api_key).c_str());

        std::stringstream request_data;
        request_data << R"({"prompt":")" << prompt << R"(","max_tokens":50,"n":1,"temperature":0.7})";

        curl_easy_setopt(curl, CURLOPT_URL, "https://api.openai.com/v1/engines/davinci-codex/completions");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, request_data.str().c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);

        if (res != CURLE_OK) {
            std::cerr << "Error: API request failed with error code " << res << std::endl;
            return 1;
        }
    }

    std::regex answer_regex(R"("text":\s*\"(.*?)\")");
    std::smatch match;

    if (std::regex_search(readBuffer, match, answer_regex)) {
        std::string answer = match[1].str();
        std::cout << "Answer: " << answer << std::endl;
    } else {
        std::cerr << "Error: Failed to parse JSON response" << std::endl;
        return 1;
    }

    return 0;
}
