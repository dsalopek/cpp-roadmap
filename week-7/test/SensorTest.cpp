#include <gtest/gtest.h>

#include "../include/Sensor.h"

// Demonstrate some basic assertions.
TEST(SensorTest, SensorCreation) {
    // Expect equality.
    Sensors::SensorMetadata sensor_metadata = Sensors::sensorMetadata[0];
    Sensors::Sensor         sensor{"t1", sensor_metadata, 100};
    EXPECT_EQ(100, sensor.sensorValue()) << "Sensor value is not expected";
}
