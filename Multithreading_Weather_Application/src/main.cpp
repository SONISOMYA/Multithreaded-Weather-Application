#include <iostream>
#include <string>
#include <thread>
#include "OpenWeatherMapDataProvider.h"
#include "ErrorHandler.h"
#include "WeatherData.h"
using namespace std;

// Function template to extract data from JSON response
template<typename T>
string extractData(const string& response, const string& key) {
    // Find the position of the key in the response
    size_t pos = response.find("\"" + key + "\":");
    // If key not found, print error and return empty string
    if (pos == string::npos) {
        ErrorHandler::printError(key + " not found in response");
        return "";
    }
    // Find the start and end positions of the data corresponding to the key
    size_t start = pos + key.length() + 3; 
    size_t end = response.find(',', start);
    // If end not found, print error and return empty string
    if (end == string::npos) {
        ErrorHandler::printError("Invalid response format");
        return "";
    }
    // Extract data and convert it to the appropriate type
    double data = stod(response.substr(start, end - start));
    // Convert temperature from Kelvin to Celsius if key is "temp"
    if (key == "temp") {
        data -= 273.15;
    }
    // Convert data to string and return
    return to_string(data);
}

int main() {
    // API key for OpenWeatherMap
    string apiKey = "47ab828dc2ac1fb153563b9422fab35b";
    // Variable to store the city entered by the user
    string city;
    // Prompt user to enter the city
    cout << "Enter the city: ";
    getline(cin, city);
    // Buffer to store response from API
    string responseBuffer;
    // Object to fetch weather data from OpenWeatherMap API
    OpenWeatherMapDataProvider weatherDataProvider;
    // Thread to fetch data asynchronously
    thread t([&]() {
        try {
            // Fetch weather data for the city using the API key
            responseBuffer = weatherDataProvider.fetchData(city, apiKey);
        } catch (const exception& e) {
            // Print exception if any occurs during data fetching
            ErrorHandler::printException(e);
        }
    });
    // Wait for the thread to finish execution
    t.join();
    // If response buffer is empty, print error and return
    if (responseBuffer.empty()) {
        ErrorHandler::printError("Empty response received");
        return 1;
    }
    // Create WeatherData objects for temperature, humidity, and wind speed
    WeatherData<double> temperature(stod(extractData<double>(responseBuffer, "temp")));
    WeatherData<int> humidity(stoi(extractData<int>(responseBuffer, "humidity")));
    WeatherData<double> windSpeed(stod(extractData<double>(responseBuffer, "speed")));
    // If any of the weather data is zero, print error and return
    if (temperature.getData() == 0 || humidity.getData() == 0 || windSpeed.getData() == 0) {
        ErrorHandler::printError("Failed to extract weather data");
        return 1;
    }
    // Print weather information for the city
    cout << "Weather in " << city << ":" << endl;
    cout << "Temperature: " << temperature.getData() << " °C" << endl;
    cout << "Humidity: " << humidity.getData() << "%" << endl;
    cout << "Wind Speed: " << windSpeed.getData() << " m/s" << endl;
    return 0;
}
