#ifndef SANDBOX_WEATHERINFO_H

#define SANDBOX_WEATHERINFO_H

class WeatherInfo
{
public:
    WeatherInfo() = delete;
    WeatherInfo(double tempC, double humidityP, double pressureInMg);

    double getTemperatureC();
    double getHumidityP();
    double getPressureInMg();

private:
    double m_temperatureC;
    double m_humidityP;
    double m_pressureInMg;
};

#endif //SANDBOX_WEATHERINFO_H