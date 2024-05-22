#ifndef WEATHER_DATA_PROVIDER_H
#define WEATHER_DATA_PROVIDER_H

#include <string>

using namespace std;

// Abstract class for weather data providers
class WeatherDataProvider {
public:
    // Pure virtual function to fetch weather data for a given city
    // Parameters:
    // - city: The name of the city for which weather data is requested
    // - apiKey: The API key required to access weather data from the provider
    // Returns:
    // - A string containing the fetched weather data
    // - An empty string if the request fails or no data is available
    virtual string fetchData(const string& city, const string& apiKey) = 0;

    // Virtual destructor (to allow proper cleanup in derived classes)
    virtual ~WeatherDataProvider() {}

    // Pure virtual function to get the name of the data provider
    // Returns:
    // - A string representing the name of the data provider
    virtual string getProviderName() const = 0;
};

#endif /* WEATHER_DATA_PROVIDER_H */
