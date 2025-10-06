#include <gtest/gtest.h>

#include "../include/Sensor.h"
#include <string>
#include <cstdint>

// Demonstrate some basic assertions.
TEST(SensorTest, SensorCreation) {
    const std::string                 sensorName{"t1"};
    constexpr double                  sensorValue{100};
    constexpr std::uint8_t            defaultSensorState{0b00001111};
    constexpr Sensors::SensorMetadata sensorMetadata = Sensors::sensorMetadata[
        0];

    const Sensors::Sensor sensor{sensorName, sensorMetadata, sensorValue};
    EXPECT_EQ(sensorName, sensor.sensorName()) << "Sensor name is not expected";
    EXPECT_EQ(sensorMetadata.sensorType,
              sensor.sensorMetadata().
              sensorType) << "Sensor type is not expected";
    EXPECT_EQ(sensorValue,
              sensor.sensorValue()) << "Sensor value is not expected";
    EXPECT_FALSE(sensor.isSensorInBadState()) << "Sensor is in bad state";
    EXPECT_TRUE(sensor.isEnabled()) << "Sensor is not enabled";
    EXPECT_EQ(defaultSensorState,
              sensor.sensorStatus()) << "Sensor status is not expected";
}
