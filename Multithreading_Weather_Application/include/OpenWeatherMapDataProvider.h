// OpenWeatherMapDataProvider.h
#ifndef OPEN_WEATHER_MAP_DATA_PROVIDER_H
#define OPEN_WEATHER_MAP_DATA_PROVIDER_H

#include "WeatherDataProvider.h" // Include the base class header
#include <string>

// Class declaration for the OpenWeatherMapDataProvider, which inherits from WeatherDataProvider
class OpenWeatherMapDataProvider : public WeatherDataProvider {
public:
    // Override the fetchData method from the base class
    // Fetches weather data for a given city using the OpenWeatherMap API
    // Parameters:
    // - city: The name of the city for which weather data is requested
    // - apiKey: The API key required to access weather data from OpenWeatherMap
    // Returns:
    // - A string containing the fetched weather data
    // - An empty string if the request fails or no data is available
    string fetchData(const string& city, const string& apiKey) override;

    // Override the getProviderName method from the base class
    // Gets the name of the weather data provider (OpenWeatherMap)
    // Returns:
    // - A string representing the name of the data provider (OpenWeatherMap)
    string getProviderName() const override;
};

#endif // OPEN_WEATHER_MAP_DATA_PROVIDER_H
