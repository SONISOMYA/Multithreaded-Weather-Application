#include <iostream>
#include <cassert>
#include "WeatherData.h"
using namespace std;

// Function to test the WeatherData class
void testWeatherData() {
    // Create a WeatherData object for temperature with an initial value of 25.5
    WeatherData<double> tempData(25.5);
    // Assert that the initial temperature value is 25.5
    assert(tempData.getData() == 25.5);

    // Set a new temperature value of 30.0
    tempData.setData(30.0);
    // Assert that the temperature value is updated to 30.0
    assert(tempData.getData() == 30.0);

    // Create a WeatherData object for humidity with an initial value of 80
    WeatherData<int> humidityData(80);
    // Assert that the initial humidity value is 80
    assert(humidityData.getData() == 80);

    // Set a new humidity value of 75
    humidityData.setData(75);
    // Assert that the humidity value is updated to 75
    assert(humidityData.getData() == 75);
}

// Main function to run the test
int main() {
    // Call the testWeatherData function to run the tests
    testWeatherData();
    // Print "All tests passed!" if all assertions succeed
    cout << "All tests passed!" << endl;
    return 0;
}
