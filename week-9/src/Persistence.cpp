#include "../include/Persistence.h"
#include "../include/Sensor.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string_view>
#include <optional>

namespace CSV {
    constexpr std::string_view header = "sensorType,sensorName,value,status";

    std::vector<Sensors::Sensor> &Persistence::loadSensorData(
        std::vector<Sensors::Sensor> &sensors, const std::string &filename) {
        std::fstream file{filename, (std::ios::in | std::ios::out)};
        std::cout << "Attempting to load existing sensor data from file: " <<
                filename << '\n';
        if (file.is_open()) {
            std::cout << "File already exists\n";
        } else {
            std::cout << "File does not exist. Skipping.\n";
            return sensors;
        }


        std::string str{};
        //skip header
        std::getline(file, str);

        std::cout << "Read\n";

        while (std::getline(file, str)) {
            try {
                std::stringstream line{str};
                std::string       sensorType{};
                std::getline(line, sensorType, ',');
                std::string sensorName{};
                std::getline(line, sensorName, ',');
                std::string sensorValue{};
                std::getline(line, sensorValue, ',');
                std::string sensorStatus{};
                std::getline(line, sensorStatus, ',');

                for (const auto &sm: Sensors::sensorMetadata) {
                    if (sm.sensorDisplayName == sensorType) {
                        Sensors::Sensor sensor{
                            sensorName, sm, std::stod(sensorValue),
                            static_cast<std::uint8_t>(std::stoi(sensorStatus))
                        };
                        std::cout << "Adding sensor\n";
                        sensors.emplace_back(sensor);
                    }
                }
            } catch (std::exception &e) {
                std::cout << "Unable to parse line, skipping. Cause: " << e.
                        what() << '\n';
            }
        }

        std::cout << '\n';

        return sensors;
    }

    bool Persistence::saveSensorData(
        const std::vector<Sensors::Sensor> &sensors,
        const std::string &                 filename) {
        if (sensors.empty()) {
            return false;
        }

        std::cout << "Saving sensor data to file: " << filename << '\n';
        std::fstream file{filename, (std::ios::in | std::ios::out)};
        if (!file.is_open()) {
            std::cout << "File does not exist. Creating it.\n";
            file.open(filename, std::ios::out);
        }
        file << header;
        for (const auto &sensor: sensors) {
            file << '\n' << sensor.sensorMetadata().sensorDisplayName << ',' <<
                    sensor.sensorName() << ',' << sensor.sensorValue() << ',' <<
                    static_cast<int>(sensor.sensorStatus());
        }

        const bool success = file.good();
        file.clear();
        file.close();

        std::cout << "Save was " << (success ? "successful" : "unsuccessful") <<
                ".\n";

        return success;
    }
}
