//
// Created by ads on 9/28/25.
//
#include <array>
#include "Sensor.h"
#include <string>
#include <string_view>
#include <iostream>
#include <cstdint>
#include <vector>
#include <bitset>

namespace Sensors {
    std::string_view Sensor::sensorName() const {
        return m_sensorName;
    }

    double Sensor::sensorValue() const {
        return m_sensorValue;
    }

    void Sensor::updateSensorStatus(const Status option, const bool flip) {
        if (flip) {
            m_sensorStatus ^= static_cast<std::uint8_t>(option);
        } else {
            m_sensorStatus |= static_cast<std::uint8_t>(option);
        }
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

    std::uint8_t operator|(const std::uint8_t lhs, const Status rhs) {
        return lhs | static_cast<std::uint8_t>(rhs);
    }

    bool Sensor::isEnabled() const {
        return m_sensorStatus & Status::ENABLED;
    }

    void Sensor::resetSensorStatus() {
        m_sensorStatus = {
            Status::ENABLED |
            Status::ONLINE |
            Status::HEALTHY |
            Status::NOMINAL
        };
    }


    std::uint8_t Sensor::sensorStatus() const {
        return m_sensorStatus;
    }

    static std::string getStatusDisplay(const Sensor &     sensor,
                                        const Status       status,
                                        const std::string &positive,
                                        const std::string &negative) {
        if (sensor.sensorStatus() & status)
            return positive;
        return negative;
    }

    std::string Sensor::sensorStatusDisplay() const {
        std::vector<std::string> statusDisplay{};
        statusDisplay.emplace_back(getStatusDisplay(
            *this, Status::ENABLED, "Enabled",
            "Disabled"));
        statusDisplay.emplace_back(getStatusDisplay(
            *this, Status::ONLINE, "Online",
            "Offline"));
        statusDisplay.emplace_back(getStatusDisplay(
            *this, Status::HEALTHY, "Healthy",
            "Degraded"));
        statusDisplay.emplace_back(
            getStatusDisplay(*this, Status::NOMINAL, "Nominal", "Error"));

        std::string separator;
        std::string statusDisplayString{"["};
        for (const auto &status: statusDisplay) {
            statusDisplayString += separator + status;
            separator = ", ";
        }
        statusDisplayString += "]";

        return statusDisplayString;
    }

    const SensorMetadata &Sensor::sensorMetadata() const {
        return *m_sensorMetadata;
    }

    constexpr std::array<SensorType, max_sensor_types> sensorTypes = {
        temperature, humidity, pressure, altitude
    };

    void Sensor::updateSensorName(const std::string &newName) {
        if (!newName.empty()) {
            m_sensorName = newName;
        }
    }

    void Sensor::updateSensorValue(const double newValue) {
        m_sensorValue = newValue;
    }

    std::ostream &operator<<(std::ostream &out, const Sensor &sensor) {
        return out << sensor.sensorMetadata().sensorDisplayName << " (" <<
               sensor.
               sensorName() << ") | value: " << sensor.sensorValue() << sensor.
               sensorMetadata().sensorUnits << " | status flags: " << sensor.
               sensorStatusDisplay();
    }

    Sensor::Sensor(const std::string &   name,
                   const SensorMetadata &sensorMetadata,
                   const double          initialValue) : m_sensorName{name},
                                                m_sensorValue{initialValue},
                                                m_sensorStatus{
                                                    Status::ENABLED |
                                                    Status::ONLINE |
                                                    Status::HEALTHY |
                                                    Status::NOMINAL
                                                },
                                                m_sensorMetadata{
                                                    &sensorMetadata
                                                } {
    }

    constexpr std::uint8_t operator~(Status status) {
        return static_cast<std::uint8_t>(~static_cast<std::uint8_t>(status));
    }

    std::uint8_t getBit(Status status) {
        return static_cast<std::uint8_t>(status);
    }

    bool Sensor::isSensorInBadState() const {
        std::cout << std::bitset<8>(m_sensorStatus);
        return !(m_sensorStatus & (getBit(Status::ONLINE) | getBit(Status::NOMINAL) | getBit(Status::HEALTHY)));
    }
}
