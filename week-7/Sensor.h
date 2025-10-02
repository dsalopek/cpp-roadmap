//
// Created by ads on 9/28/25.
//


#ifndef WEEK_7_SENSOR_H

#define WEEK_7_SENSOR_H

#include <string>
#include <string_view>
#include <ostream>
#include <optional>
#include <vector>

namespace Sensors {
    enum SensorType : std::size_t {
        temperature,
        humidity,
        pressure,
        altitude,
        max_sensor_types,
    };

    enum class Status : std::uint8_t {
        ENABLED  = 0b0001,
        DEGRADED = 0b0010,
        ERROR    = 0b0100,
        ONLINE    = 0b1000,
    };

    class Sensor {
    public:
        Sensor() = default;

        Sensor(const std::string &name, SensorType type, double initialValue);

        std::string_view sensorName() const;

        SensorType sensorType() const;

        double sensorValue() const;

        std::string_view sensorValueUnits() const;

        std::uint8_t sensorStatus() const;

        std::string sensorStatusDisplay() const;

        void updateSensorName(const std::string &newName);

        void updateSensorValue(double newValue);

        void updateSensorStatus(Status option, bool flip);

        void resetSensorStatus();

    private:
        std::string  m_sensorName;
        SensorType   m_sensorType{};
        double       m_sensorValue{};
        std::uint8_t m_sensorStatus{};
    };

    std::ostream &operator<<(std::ostream &out, const Sensor &sensor);

    std::ostream &operator<<(std::ostream &out, SensorType sensorType);

    char getSensorSelector(SensorType sensorType);

    std::optional<SensorType> getSensorTypeBySelector(char selector);

    std::string_view getSensorTypeDisplay(SensorType sensorType);
}


#endif //WEEK_7_SENSOR_H
