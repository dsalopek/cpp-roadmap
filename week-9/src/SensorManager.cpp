//
// Created by sokoban on 11/4/25.
//

#include "../include/Persistence.h"
#include "../include/Sensor.h"
#include "../include/SensorManager.h"
#include "../include/InputUtils.h"
#include <iostream>
#include <cstddef>

std::size_t displaySensorCreationMenu();

std::string getSensorNameInput(const Sensors::SensorMetadata &sensorMetadata);

double getSensorValueInput(std::string_view               sensorName,
                           const Sensors::SensorMetadata &sensorMetadata);

std::size_t
displaySensorUpdateMenu(const std::vector<Sensors::Sensor> &sensors);

std::size_t
displaySensorRemoveMenu(const std::vector<Sensors::Sensor> &sensors);

void updateSensorName(Sensors::Sensor &sensor);

void updateSensorValue(Sensors::Sensor &sensor);

std::size_t getSensorSelection(const std::vector<Sensors::Sensor> &sensors);

SensorManager::~SensorManager() {
    CSV::Persistence::saveSensorData(sensors_);
}

SensorManager::SensorManager() {
    CSV::Persistence::loadSensorData(sensors_);
}

void SensorManager::addSensor() {
    std::size_t selection{displaySensorCreationMenu()};
    if (selection == 0)
        return;
    //todo make less brittle
    const Sensors::SensorMetadata &sensorMetadata = Sensors::sensorMetadata[
        --selection];
    const std::string     sensorName = getSensorNameInput(sensorMetadata);
    const Sensors::Sensor sensor{
        sensorName, sensorMetadata,
        getSensorValueInput(sensorName, sensorMetadata)
    };

    std::cout << "Sensor added: " << sensor << "\n";
    sensors_.push_back(sensor);
    CSV::Persistence::saveSensorData(sensors_);
}

//todo
void SensorManager::removeSensor() {
    while (true) {
        const std::size_t sensorSelection{displaySensorRemoveMenu(sensors_)};
        if (sensorSelection == 0)
            break;

        sensors_.erase(sensors_.begin() + (sensorSelection - 1));
        std::cout << "Sensor removed.\n";
    }
    CSV::Persistence::saveSensorData(sensors_);
}

void SensorManager::updateSensor() {
    while (true) {
        const std::size_t sensorSelection{displaySensorUpdateMenu(sensors_)};
        if (sensorSelection == 0)
            break;

        Sensors::Sensor &sensor = sensors_[sensorSelection - 1];

        while (true) {
            std::cout << "\nSensor: " << sensor << "\n";
            std::cout << "Select an option\n";
            std::cout << "1=name\n2=value\n";
            std::cout << "3=";

            if (sensor.isEnabled())
                std::cout << "disable\n";
            else
                std::cout << "enable\n";
            const bool sensorInBadState = sensor.isSensorInBadState();
            if (sensorInBadState)
                std::cout << "4=repair\n";
            std::cout << "0=back\n> ";
            int updateSelection{};
            std::cin >> updateSelection;
            if (updateSelection == 0)
                return;
            if (updateSelection == 1) {
                updateSensorName(sensor);
                break;
            }
            if (updateSelection == 2) {
                updateSensorValue(sensor);
                break;
            }
            if (updateSelection == 3) {
                sensor.updateSensorStatus(Sensors::Status::enabled, true);
                break;
            }
            if (updateSelection == 4 && sensorInBadState) {
                sensor.resetSensorStatus();
                break;
            }
            InputUtils::clearInput();
            std::cout << "Invalid input. Try again\n> ";
        }

        std::cout << "Sensor updated: " << sensor << "\n";
        std::cout << '\n';
    }
    CSV::Persistence::saveSensorData(sensors_);
}

void SensorManager::displaySensors() const {
    std::cout << "== Active sensors ==\n";
    if (sensors_.empty()) {
        std::cout << "No sensors found. Please add one to view.\n";
    } else {
        for (const auto &sensor: sensors_) {
            std::cout << sensor << '\n';
        }
    }
}

std::size_t displaySensorCreationMenu() {
    std::cout << "== Select a sensor type to create ==\n";
    for (std::size_t ii{0}; ii < Sensors::sensorMetadata.size(); ++ii) {
        std::cout << ii + 1 << '=' << Sensors::sensorMetadata[ii].
                sensorDisplayName
                << '\n';
    }
    std::cout << "0=back\n";
    return InputUtils::getUnsignedNumericInput(Sensors::sensorMetadata.size());
}

std::size_t
displaySensorUpdateMenu(const std::vector<Sensors::Sensor> &sensors) {
    std::cout << "== Select a sensor to update ==\n";
    if (sensors.empty()) {
        std::cout << "No sensors found. Please add one to update.\n";
        //return 0 if sensors is empty so it emulates 'back'
        return 0;
    }
    return getSensorSelection(sensors);
}

std::size_t
displaySensorRemoveMenu(const std::vector<Sensors::Sensor> &sensors) {
    std::cout << "== Select a sensor to remove ==\n";
    if (sensors.empty()) {
        std::cout << "No sensors found. Please add one to update.\n";
        //return 0 if sensors is empty so it emulates 'back'
        return 0;
    }
    return getSensorSelection(sensors);
}

std::size_t getSensorSelection(const std::vector<Sensors::Sensor> &sensors) {
    for (std::size_t ii{0}; ii < sensors.size(); ++ii) {
        auto &sensor = sensors[ii];
        std::cout << ii + 1 << '=' << sensor.sensorName() << " (" << sensor.
                sensorMetadata().sensorDisplayName << ")\n";
    }
    std::cout << "0=back\n";
    return InputUtils::getUnsignedNumericInput(sensors.size());
}


void updateSensorName(Sensors::Sensor &sensor) {
    sensor.updateSensorName(getSensorNameInput(sensor.sensorMetadata()));
}

void updateSensorValue(Sensors::Sensor &sensor) {
    sensor.updateSensorValue(
        getSensorValueInput(sensor.sensorName(), sensor.sensorMetadata()));
}


std::string getSensorNameInput(const Sensors::SensorMetadata &sensorMetadata) {
    std::cout << "Enter a name for " << sensorMetadata.sensorDisplayName;
    std::cout << '\n';
    return InputUtils::getStringInputBounded(1, 20);
}


double getSensorValueInput(const std::string_view         sensorName,
                           const Sensors::SensorMetadata &sensorMetadata) {
    std::cout << "Enter a value for " << sensorName << " (" <<
            sensorMetadata.sensorDisplayName << " " << sensorMetadata.
            sensorUnits << ")\n";

    return InputUtils::getSignedDoubleInput();
}
