// WeatherData.h
#ifndef WEATHER_DATA_H
#define WEATHER_DATA_H

// Template class for storing weather data of type T
template<typename T>
class WeatherData {
private:
    T data; // Data member to store weather data
public:
    // Default constructor
    WeatherData() {}

    // Parameterized constructor with explicit conversion
    explicit WeatherData(const T& newData) : data(newData) {}

    // Getter method to retrieve the weather data
    T getData() const { return data; }

    // Setter method to set the weather data
    void setData(const T& newData) { data = newData; }
};

#endif // WEATHER_DATA_H
