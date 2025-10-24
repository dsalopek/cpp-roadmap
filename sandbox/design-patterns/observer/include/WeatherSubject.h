#ifndef SANDBOX_WEATHERSUBJECT_H

#define SANDBOX_WEATHERSUBJECT_H

#include "WeatherObserver.h"

class WeatherSubject
{
    virtual void registerObserver(std::unique_ptr<WeatherObserver> weatherObserver) = 0;
    virtual void removeObserver(std::unique_ptr<WeatherObserver> weatherObserver) = 0;
    virtual void notifyObservers() = 0;
};

#endif // SANDBOX_WEATHERSUBJECT_H