#include <gtest/gtest.h>

#include "../include/Sensor.h"
#include "../include/Persistence.h"
#include <string>
#include <cstdint>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>

void removeFile(const std::string& filepath);
CSV::Persistence persistence{};
constexpr std::string_view header = "sensorType,sensorName,value,status";


TEST(PersistenceTest, SensorRead) {

    std::string filepath = "test/data/static_test_data_read.csv";
    std::vector<Sensors::Sensor> sensors{};

    std::fstream f {filepath, std::ios::out};
    f << header << '\n';
    f << "temperature,T1,100,15\nhumidity,h1,10,15\npressure,P1,29.92,15";
    f.close();

    sensors = persistence.loadSensorData(sensors, filepath);
    ASSERT_EQ(static_cast<std::size_t>(3), sensors.size()) << "Sensors size is not 3";

    removeFile(filepath);
}

TEST(PersistenceTest, BadSensorDataInFile) {

    std::string filepath = "test/data/static_test_data_read.csv";
    std::vector<Sensors::Sensor> sensors{};

    std::fstream f {filepath, std::ios::out};
    f << header << '\n';
    f << "notarealsensortype,T1,ABC,3000\ntemperature,T1,ABC,ABC";
    f.close();

    sensors = persistence.loadSensorData(sensors, filepath);
    ASSERT_EQ(static_cast<std::size_t>(0), sensors.size()) << "Sensors size is not 0";

    removeFile(filepath);
}

TEST(PersistenceTest, BadLineSensorDataInFile) {

    std::string filepath = "test/data/static_test_data_read.csv";
    std::vector<Sensors::Sensor> sensors{};

    std::fstream f {filepath, std::ios::out};
    f << header << '\n';
    f << "temperature,T1,212,15\ntemperature,T1,ABC,ABC";
    f.close();

    sensors = persistence.loadSensorData(sensors, filepath);
    ASSERT_EQ(static_cast<std::size_t>(1), sensors.size()) << "Sensors size is not 1";

    removeFile(filepath);
}

TEST(PersistenceTest, NewSensorSave) {

    std::string filepath = "test/data/static_test_data_save.csv";
    std::vector<Sensors::Sensor> sensors{};
    Sensors::Sensor sensor {"Test Sensor", Sensors::sensorMetadata[0], 212};
    sensors.emplace_back(sensor);
    ASSERT_TRUE(persistence.saveSensorData(sensors, filepath)) << "CSV sensor data was not saved as expected";

    std::vector<Sensors::Sensor> fetchedSensors{};
    fetchedSensors = persistence.loadSensorData(fetchedSensors, filepath);
    ASSERT_EQ(static_cast<std::size_t>(1), sensors.size()) << "Sensors size is not 3";
    Sensors::Sensor s = fetchedSensors[0];
    ASSERT_EQ("Test Sensor", s.sensorName()) << "Sensor name is not expected";
    ASSERT_EQ(212, s.sensorValue()) << "Sensor value is not expected";
    ASSERT_EQ(Sensors::sensorMetadata[0].sensorType, s.sensorMetadata().sensorType) << "Sensor metadata is not expected";
    ASSERT_EQ(0b00001111, s.sensorStatus()) << "Sensor status is not expected";

    removeFile(filepath);
}

TEST(PersistenceTest, InvalidFileNameToRead) {
    std::string filepath = "test/data/some_invalid_sensor_data.csv";
    std::vector<Sensors::Sensor> sensors{};

    sensors = persistence.loadSensorData(sensors, filepath);
    ASSERT_EQ(static_cast<std::size_t>(0), sensors.size()) << "Sensors size is not 0";

    removeFile(filepath);
}

TEST(PersistenceTest, NoSensorDataToSave) {
    std::string filepath = "test/data/sensor_data.csv";
    std::vector<Sensors::Sensor> sensors{};

    ASSERT_FALSE(persistence.saveSensorData(sensors, filepath)) << "File was created";

    std::fstream f{filepath};
    ASSERT_FALSE(f.is_open()) << "File was created";
    removeFile(filepath);
}

void removeFile(const std::string& filepath) {
    std::remove(filepath.c_str());
}