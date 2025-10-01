//
// Created by ads on 9/28/25.
//


#ifndef WEEK_7_SENSOR_H

#define WEEK_7_SENSOR_H

#include <string>
#include <string_view>
#include <ostream>
#include <optional>
#include <cstdint>
#include <bitset>
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
        INACTIVE = 0,
        ACTIVE   = 1 << 0,
        DEGRADED = 1 << 1,
        ERROR    = 1 << 2,
    };

    class Sensor {
    public:
        Sensor() = default;

        Sensor(const std::string &name, SensorType type, double initialValue);

        std::string_view sensorName() const;

        SensorType sensorType() const;

        double sensorValue() const;

        std::string_view getSensorUnits() const;

        void updateSensorName(const std::string &newName);

        void updateSensorValue(double newValue);



    private:
        std::string    m_sensorName;
        SensorType     m_sensorType{};
        double         m_sensorValue{};
        std::bitset<4> m_sensorStatus{};
    };

    std::ostream &operator<<(std::ostream &out, const Sensor &sensor);

    std::ostream &operator<<(std::ostream &out, SensorType sensorType);

    char getSensorSelector(SensorType sensorType);

    std::optional<SensorType> getSensorTypeBySelector(char selector);

    std::string_view getSensorTypeDisplay(SensorType sensorType);

    std::vector<std::string>
}


#endif //WEEK_7_SENSOR_H
