//
// Created by ads on 9/28/25.
//


#ifndef WEEK_7_SENSOR_H

#define WEEK_7_SENSOR_H

#include <string>
#include <string_view>
#include <ostream>
#include <cstdint>

namespace Sensors {
    enum SensorType : std::size_t {
        temperature,
        humidity,
        pressure,
        altitude,
        max_sensor_types,
    };

    enum class Status : std::uint8_t {
        ENABLED = 0b0001,
        HEALTHY = 0b0010,
        NOMINAL = 0b0100,
        ONLINE  = 0b1000,
    };

    struct SensorMetadata {
        const SensorType       sensorType{};
        const std::string_view sensorUnits{};
        const std::string_view sensorDisplayName{};
    };

    constexpr std::array<SensorMetadata, max_sensor_types> sensorMetadata{
        {
            {temperature, "°F", "temperature"},
            {humidity, "%", "humidity"},
            {altitude, "ft", "altitude"},
            {pressure, "inHg", "pressure"},
        }
    };

    class Sensor {
    public:
        Sensor() = default;

        Sensor(const std::string &name, const SensorMetadata &sensorMetadata,
               double             initialValue);

        std::string_view sensorName() const;

        double sensorValue() const;

        std::uint8_t sensorStatus() const;

        std::string sensorStatusDisplay() const;

        const SensorMetadata &sensorMetadata() const;

        void updateSensorName(const std::string &newName);

        void updateSensorValue(double newValue);

        void updateSensorStatus(Status option, bool flip);

        bool isEnabled() const;

        bool isSensorInBadState() const;

        void resetSensorStatus();

    private:
        std::string           m_sensorName;
        double                m_sensorValue{};
        std::uint8_t          m_sensorStatus{};
        const SensorMetadata *m_sensorMetadata{};
    };

    std::ostream &operator<<(std::ostream &out, const Sensor &sensor);
}


#endif //WEEK_7_SENSOR_H
