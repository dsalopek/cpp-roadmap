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
    std::string_view Sensor::sensorName() const {
        return m_sensorName;
    }

    SensorType Sensor::sensorType() const {
        return m_sensorType;
    }

    double Sensor::sensorValue() const {
        return m_sensorValue;
    }

    void Sensor::updateSensorStatus(const Status option, const bool flip) {
        if (flip) {
            m_sensorStatus ^= ~static_cast<std::uint8_t>(option);
        } else {
            m_sensorStatus |= static_cast<std::uint8_t>(option);
        }
    }

    void Sensor::resetSensorStatus() {
        m_sensorStatus = static_cast<std::uint8_t>(Status::ENABLED);
    }

    std::uint8_t operator|(const Status lhs, const Status rhs) {
        return static_cast<std::uint8_t>(lhs) | static_cast<std::uint8_t>(rhs);
    }

    std::uint8_t operator&(const Status lhs, const Status rhs) {
        return static_cast<std::uint8_t>(lhs) & static_cast<std::uint8_t>(rhs);
    }

    std::uint8_t operator&(const std::uint8_t lhs, const Status rhs) {
        return lhs & static_cast<std::uint8_t>(rhs);
    }

    std::uint8_t Sensor::sensorStatus() const {
        return static_cast<std::uint8_t>(m_sensorType);
    }

    std::string Sensor::sensorStatusDisplay() const {
        std::vector<std::string> statusDisplay{};
        if (m_sensorStatus & Status::ENABLED) {
            statusDisplay.emplace_back("Enabled");
        } else {
            statusDisplay.emplace_back("Disabled");
        }
        if (m_sensorStatus & Status::ONLINE) {
            statusDisplay.emplace_back("Online");
        } else {
            statusDisplay.emplace_back("Offline");
        }
        if (m_sensorStatus & Status::DEGRADED) {
            statusDisplay.emplace_back("Degraded");
        } else {
            statusDisplay.emplace_back("Healthy");
        }
        if (m_sensorStatus & Status::ERROR) {
            statusDisplay.emplace_back("Error");
        } else {
            statusDisplay.emplace_back("No error");
        }

        std::string separator;
        std::string statusDisplayString{"["};
        for (const auto &status: statusDisplay) {
            statusDisplayString += separator + status;
            separator = ", ";
        }
        statusDisplayString += "]";

        return statusDisplayString;
    }

    constexpr std::array<SensorType, max_sensor_types> sensorTypes = {
        temperature, humidity, pressure, altitude
    };

    constexpr std::array<std::string_view, max_sensor_types> sensorUnits = {
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

    std::string_view Sensor::sensorValueUnits() const {
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
               ") | value: " << sensor.sensorValue() << sensor.
               sensorValueUnits() << " | status flags: " << sensor.
               sensorStatusDisplay();
    }

    std::ostream &operator<<(std::ostream &out, const SensorType sensorType) {
        return out << getSensorTypeDisplay(sensorType);
    }

    Sensor::Sensor(const std::string &name, const SensorType type,
                   const double       initialValue) : m_sensorName{name},
        m_sensorType{type},
        m_sensorValue{initialValue},
        m_sensorStatus{
            Status::ENABLED |
            Status::ONLINE
        } {
    }
}
