#ifndef SANDBOX_REALTIMEOBSERVER_H

#define SANDBOX_REALTIMEOBSERVER_H

#include "../include/WeatherObserver.h"
#include <iostream>

class RealTimeWeatherObserver : public WeatherObserver {
    void update(WeatherInfo &weatherInfo) const override;
};

#endif //SANDBOX_REALTIMEOBSERVER_H