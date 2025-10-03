//
// Created by ads on 9/28/25.
//
#include "Sensor.h"
#include <string>
#include <string_view>
#include <iostream>
#include <cstdint>
#include <vector>

namespace {
    std::uint8_t toUint8(Sensors::Status status) {
        return static_cast<std::uint8_t>(status);
    }

    Sensors::Status toStatus(std::uint8_t status) {
        return static_cast<Sensors::Status>(status);
    }

    Sensors::Status operator|(const Sensors::Status lhs,
                              const Sensors::Status rhs) {
        return toStatus(toUint8(lhs) | toUint8(rhs));
    }

    const std::uint8_t sensorGoodState{
        toUint8(Sensors::Status::healthy |
                Sensors::Status::nominal |
                Sensors::Status::online)
    };
    const std::uint8_t sensorDefaultState{
        toUint8(Sensors::Status::enabled |
                Sensors::Status::healthy |
                Sensors::Status::nominal |
                Sensors::Status::online)
    };
}

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

    bool Sensor::isEnabled() const {
        return m_sensorStatus & toUint8(Status::enabled);
    }

    void Sensor::resetSensorStatus() {
        m_sensorStatus = {
            sensorDefaultState
        };
    }


    std::uint8_t Sensor::sensorStatus() const {
        return m_sensorStatus;
    }

    static std::string getStatusDisplay(const Sensor &     sensor,
                                        const Status       status,
                                        const std::string &positive,
                                        const std::string &negative) {
        if (sensor.sensorStatus() & toUint8(status)) { return positive; }
        return negative;
    }

    std::string Sensor::sensorStatusDisplay() const {
        std::vector<std::string> statusDisplay{};
        statusDisplay.emplace_back(getStatusDisplay(
            *this, Status::enabled, "Enabled",
            "Disabled"));
        statusDisplay.emplace_back(getStatusDisplay(
            *this, Status::online, "Online",
            "Offline"));
        statusDisplay.emplace_back(getStatusDisplay(
            *this, Status::healthy, "Healthy",
            "Degraded"));
        statusDisplay.emplace_back(
            getStatusDisplay(*this, Status::nominal, "Nominal", "Error"));

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
                                                    sensorDefaultState
                                                },
                                                m_sensorMetadata{
                                                    &sensorMetadata
                                                } {
    }

    std::uint8_t getBit(Status status) {
        return static_cast<std::uint8_t>(status);
    }

    bool Sensor::isSensorInBadState() const {
        return (m_sensorStatus & sensorGoodState) != sensorGoodState;
    }
}
