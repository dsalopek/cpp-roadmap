//
// Created by ads on 9/28/25.
//
#include <array>
#include "Sensor.h"
#include <string>
#include <string_view>
#include <utility>
#include <iostream>
#include <optional>

namespace Sensors {
    constexpr std::array<SensorType, max_sensor_types> sensorTypes = {
        temperature, humidity, pressure, altitude
    };

    constexpr  std::array<std::string_view, max_sensor_types> sensorUnits = {
        "°F", "%", "inHg", "ft",
    };

    constexpr std::array<std::pair<char, std::string_view>, max_sensor_types>
    sensorSelectorAndDisplayNames{
        {
            {'t', "temperature"},
            {'h', "humidity"},
            {'p', "pressure"},
            {'a', "altitude"}
        }
    };

    char getSensorSelector(const SensorType sensorType) {
        return sensorSelectorAndDisplayNames[sensorType].first;
    }

    std::optional<SensorType> getSensorTypeBySelector(const char selector) {
        for (const auto sensorType: sensorTypes) {
            if (selector == sensorSelectorAndDisplayNames[sensorType].first)
                return sensorType;
        }
        return std::nullopt;
    }

    std::string_view getSensorTypeDisplay(const SensorType sensorType) {
        return sensorSelectorAndDisplayNames[sensorType].second;
    }

    std::string_view Sensor::getSensorUnits() const {
        return sensorUnits[sensorType()];
    }

    void Sensor::updateSensorName(const std::string &newName) {
        if (!newName.empty()) {
            m_sensorName = newName;
        }
    }

    void Sensor::updateSensorValue(const double newValue) {
        m_sensorValue = newValue;
    }

    std::ostream &operator<<(std::ostream &out, const Sensor &sensor) {
        return out << sensor.sensorType() << " (" << sensor.sensorName() <<
               ") | value: " << sensor.sensorValue() << sensor.getSensorUnits();
    }

    std::ostream & operator<<(std::ostream &out, const SensorType sensorType) {
        return out << getSensorTypeDisplay(sensorType);
    }
}
