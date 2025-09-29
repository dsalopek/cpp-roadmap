//
// Created by ads on 9/28/25.
//


#ifndef WEEK_6_SENSOR_H

#define WEEK_6_SENSOR_H

#include <string>
#include <string_view>
#include <ostream>
#include <optional>

namespace Sensors {
    enum SensorType : std::size_t {
        temperature,
        humidity,
        pressure,
        altitude,
        max_sensor_types,
    };

    class Sensor {
    public:
        Sensor() = default;

        Sensor(const std::string &name, const SensorType type,
               const double       initialValue) : m_sensorName(name),
                                            m_sensorType(type),
                                            m_sensorValue(initialValue) {
        }

        std::string_view sensorName() const {
            return m_sensorName;
        }

        SensorType sensorType() const {
            return m_sensorType;
        }

        double sensorValue() const {
            return m_sensorValue;
        }

        std::string_view getSensorUnits() const;

        void updateSensorName(const std::string &newName);

        void updateSensorValue(double newValue);

    private:
        std::string m_sensorName;
        SensorType  m_sensorType;
        double      m_sensorValue;
    };

    std::ostream &operator<<(std::ostream &out, const Sensor &sensor);

    std::ostream &operator<<(std::ostream &out, const SensorType sensorType);

    char getSensorSelector(SensorType sensorType);

    std::optional<SensorType> getSensorTypeBySelector(char selector);

    std::string_view getSensorTypeDisplay(SensorType sensorType);
}


#endif //WEEK_6_SENSOR_H
