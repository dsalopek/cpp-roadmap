#include "../include/WeatherInfo.h"

WeatherInfo::WeatherInfo(double tempC, double humidityP, double pressureInMg) : m_temperatureC{tempC}, m_humidityP{humidityP}, m_pressureInMg{pressureInMg} {};

double WeatherInfo::getTemperatureC() {
    return m_temperatureC;
}

double WeatherInfo::getHumidityP() {
    return m_humidityP;
}

double WeatherInfo::getPressureInMg() {
    return m_pressureInMg;
}