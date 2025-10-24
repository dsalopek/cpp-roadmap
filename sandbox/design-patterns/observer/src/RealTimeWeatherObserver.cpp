#include "../include/RealTimeWeatherObserver.h"
#include <iostream>

void RealTimeWeatherObserver::update(WeatherInfo &weatherInfo) const 
{
    std::cout << "Update from RealTimeWeatherObserver was called.\n" << "WeatherInfo: temp=" << weatherInfo.getTemperatureC() << ", humidity=" << weatherInfo.getHumidityP() << ", pressure=" << weatherInfo.getPressureInMg() << "\n";
}