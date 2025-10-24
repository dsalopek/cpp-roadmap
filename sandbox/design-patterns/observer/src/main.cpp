#include <cstdint>
#include <iostream>
#include <bitset>
#include <memory>

#include "../include/WeatherData.h"
#include "../include/RealTimeWeatherObserver.h"

int main()
{
    WeatherData weatherData{100, 15, 32};

    
    RealTimeWeatherObserver realTimeObserver{};

    weatherData.registerObserver(std::make_unique<RealTimeWeatherObserver>());
    weatherData.updateTemperature(150.00);
    weatherData.updateTemperature(114.00);
    weatherData.updateTemperature(112.00);


    return 0;
}