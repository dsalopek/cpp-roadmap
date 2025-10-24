#include "../include/WeatherData.h"
#include <iostream> //todo remove

WeatherData::WeatherData(double temp, double hum, double press) : m_temperature{temp}, m_humidty{hum}, m_pressure{press}, m_observers{} {}

void WeatherData::updateTemperature(double temp) {
    m_temperature = temp;
    weatherChanged();
}

double WeatherData::getTemperature()
{
    return m_temperature;
}

void WeatherData::updateHumidity(double humidity) {
    m_humidty = humidity;
    weatherChanged();
}

double WeatherData::getHumidity()
{
    return m_humidty;
}

void WeatherData::updatePressure(double pressure) {
    m_pressure = pressure;
    weatherChanged();
}

double WeatherData::getPressure()
{
    return m_pressure;
}

void WeatherData::weatherChanged()
{
    notifyObservers();
}

void WeatherData::registerObserver(std::unique_ptr<WeatherObserver> weatherObserver)
{
    m_observers.emplace_back(std::move(weatherObserver));
}

void WeatherData::removeObserver([[maybe_unused]] std::unique_ptr<WeatherObserver> weatherObserver)
{
    //todo
    std::cout << "Remove observer called.";
}

void WeatherData::notifyObservers() {
    WeatherInfo weatherInfo{getTemperature(), getHumidity(), getPressure()};

    for(auto &observer : m_observers) {
        observer->update(weatherInfo);
    }
}