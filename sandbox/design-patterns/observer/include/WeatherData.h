#ifndef SANDBOX_WEATHERDATA_H

#define SANDBOX_WEATHERDATA_H

#include <vector>
#include "WeatherObserver.h"
#include "WeatherSubject.h"

class WeatherData : public WeatherSubject
{

public:
    WeatherData() = delete;
    WeatherData(double temp, double hum, double press);

    void updateTemperature(double temp);
    double getTemperature();
    void updateHumidity(double humidity);
    double getHumidity();
    void updatePressure(double pressure);
    double getPressure();
    void weatherChanged();

    void registerObserver(std::unique_ptr<WeatherObserver> weatherObserver) override;
    void removeObserver(std::unique_ptr<WeatherObserver> weatherObserver) override;
    void notifyObservers() override;


private:
    double m_temperature;
    double m_humidty;
    double m_pressure;
    std::vector<std::unique_ptr<WeatherObserver>> m_observers;
};

#endif // SANDBOX_WEATHERDATA_H