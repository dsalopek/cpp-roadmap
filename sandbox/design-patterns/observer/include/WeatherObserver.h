#ifndef SANDBOX_WEATHEROBSERVER_H

#define SANDBOX_WEATHEROBSERVER_H

#include "WeatherInfo.h"

class WeatherObserver {
public:
    virtual void update(WeatherInfo &weatherInfo) const = 0;
    virtual ~WeatherObserver() = default;
};

#endif //SANDBOX_WEATHEROBSERVER_H