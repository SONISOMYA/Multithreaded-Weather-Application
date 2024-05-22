#include "OpenWeatherMapDataProvider.h"
#include "ErrorHandler.h"
#include <curl/curl.h>
using namespace std;

// Function to handle the writing of data received from CURL
size_t writeCallback(void* contents, size_t size, size_t nmemb, string* data) {
    // Append received data to the string buffer
    data->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// Fetch weather data from OpenWeatherMap API
string OpenWeatherMapDataProvider::fetchData(const string& city, const string& apiKey) {
    // Construct the API URL
    string apiUrl = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + apiKey;
    // Initialize libcurl
    CURL* curl = curl_easy_init();
    // Check if libcurl initialization was successful
    if (!curl) {
        throw runtime_error("Error initializing libcurl");
    }
    // Set the URL to fetch data from
    curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());
    // Allow libcurl to follow HTTP redirects
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    // Buffer to store the response data
    string responseBuffer;
    // Set the write callback function to handle received data
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    // Set the data pointer to the buffer for writing
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);
    // Perform the HTTP request
    CURLcode res = curl_easy_perform(curl);
    // Check if the request was successful
    if (res != CURLE_OK) {
        // Cleanup libcurl handle
        curl_easy_cleanup(curl);
        // Throw an exception with the error message
        throw runtime_error("Error performing HTTP request: " + string(curl_easy_strerror(res)));
    }
    // Cleanup libcurl handle
    curl_easy_cleanup(curl);
    // Return the received response data
    return responseBuffer;
}

// Get the name of the data provider
string OpenWeatherMapDataProvider::getProviderName() const {
    return "OpenWeatherMap";
}
