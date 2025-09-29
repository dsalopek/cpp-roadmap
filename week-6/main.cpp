#include <array>
#include <iostream>
#include <limits>
#include <optional>
#include <string>
#include <vector>
#include <cstddef>
#include "Sensor.h"

namespace SensorBank {
    // track the sensors that are in use by a flag array
    std::array<bool, Sensors::max_sensor_types>        activeSensors{};
    static std::array<char, Sensors::max_sensor_types> sensorSelectors = {
        't', 'h', 'p', 'a',
    };
}

// Declarations start
void printStartup();

Sensors::Sensor createSensor();

int displayMenuItems();

std::string getSensorNameInput(Sensors::SensorType sensorType);

double getSensorValueInput(std::string_view    sensorName,
                           Sensors::SensorType sensorType);

void updateSensorValue(Sensors::Sensor &sensor);

void updateSensorName(Sensors::Sensor &sensor);

char displaySensorMenu(const std::string &                 sensorOperation,
                       const std::vector<Sensors::Sensor> &sensors);

// Declarations end

void displayAllSensors(const std::vector<Sensors::Sensor> &sensors) {
    std::cout << "== Active sensors ==\n";
    for (const auto &sensor: sensors) {
        std::cout << sensor << '\n';
    }
}

int main() {
    printStartup();

    std::vector<Sensors::Sensor> sensors{};

    bool exit{false};

    std::optional<int>  operationSelection{};
    std::optional<char> sensorSelection{};
    sensors.push_back(createSensor());
    while (!exit) {
        std::cout << '\n';
        if (!operationSelection) {
            operationSelection = displayMenuItems();
            sensorSelection    = {};
            std::cout << '\n';
        }

        switch (*operationSelection) {
            case 1:
                if (!sensorSelection) {
                    sensorSelection = displaySensorMenu("display", sensors);
                }

                if (auto sensorType = Sensors::getSensorTypeBySelector(
                    *sensorSelection)) {
                    for (const auto &sensor: sensors) {
                        if (*sensorType == sensor.sensorType()) {
                            sensorSelection = {};
                            std::cout << sensor << '\n';
                            break;
                        }
                    }
                } else if (sensorSelection == '0') {
                    sensorSelection    = {};
                    operationSelection = {};
                } else {
                    std::cout << "Invalid entry. Please retry.\n";
                }
                break;
            case 2:
                if (!sensorSelection) {
                    sensorSelection = displaySensorMenu("update", sensors);
                }
                if (auto sensorType = Sensors::getSensorTypeBySelector(
                    *sensorSelection)) {
                    for (auto &sensor: sensors) {
                        if (*sensorType == sensor.sensorType()) {
                            updateSensorValue(sensor);
                            sensorSelection = {};
                            std::cout << sensor << '\n';
                            break;
                        }
                    }
                } else if (sensorSelection == '0') {
                    sensorSelection    = {};
                    operationSelection = {};
                } else {
                    std::cout << "Invalid entry. Please retry.\n";
                }
                break;
            case 3:
                displayAllSensors(sensors);
                operationSelection = {};
                break;
            case 4:
                sensors.emplace_back(createSensor());
                operationSelection = {};
                break;
            case 0:
                exit = true;
                break;
            default:
                std::cout << "Invalid selection. Retry.";
                operationSelection = {};
                break;
        }
    }


    return 0;
}

void printStartup() {
    const std::string name{"main"};
    const std::string version{"0.0.6"};
    const std::string author{"Dylan"};

    std::cout << "Starting up...\n";
    std::cout << "Program name: " << name << '\n';
    std::cout << "Program version: " << version << '\n';
    std::cout << "Program author: " << author << '\n';
    std::cout << '\n';
}

Sensors::Sensor createSensor() {
    std::cout << "== Create a new sensor ==\n(";
    auto separator{""};
    for (std::size_t ii{0}; ii < SensorBank::activeSensors.size(); ++ii) {
        if (!SensorBank::activeSensors[ii]) {
            const auto sensorType = static_cast<Sensors::SensorType>(ii);
            std::cout << separator << SensorBank::sensorSelectors[sensorType] <<
                    "=" << sensorType;
            separator = ", ";
        }
    }

    std::cout << "): ";

    char selection{};

    std::string         sensorName{};
    Sensors::SensorType sensorType{};
    double              sensorValue{};

    Sensors::Sensor sensor;
    while (true) {
        std::cin >> selection;
        const auto selectedSensorType = Sensors::getSensorTypeBySelector(
            selection);
        if (selectedSensorType && !SensorBank::activeSensors[*
                selectedSensorType]) {
            sensorType  = *selectedSensorType;
            sensorName  = getSensorNameInput(sensorType);
            sensorValue = getSensorValueInput(sensorName, sensorType);
            sensor      = Sensors::Sensor(sensorName, sensorType, sensorValue);
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid selection. Try again: ";
    }

    std::cout << "Sensor added: " << sensor << "\n";
    SensorBank::activeSensors[sensor.sensorType()] = true;

    return sensor;
}

std::string getSensorNameInput(const Sensors::SensorType sensorType) {
    std::cout << "Enter a name for " << sensorType << ": ";
    std::string sensorName{};
    while (true) {
        std::getline(std::cin >> std::ws, sensorName);
        if (sensorName.empty() || sensorName.length() > 20) {
            std::cout <<
                    "Sensor name must be between 1 and 20 characters (inclusive). You inputted "
                    << sensorName << ", which is " << sensorName.length() <<
                    " characters. Try again: ";
        } else if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again: ";
        } else {
            break;
        }
    }

    return sensorName;
}

double getSensorValueInput(const std::string_view    sensorName,
                           const Sensors::SensorType sensorType) {
    std::cout << "Enter the value for " << sensorName << " (" << sensorType <<
            "): ";
    double value{};

    while (true) {
        std::cin >> value;

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again: ";
        } else {
            break;
        }
    }

    return value;
}

void updateSensorName(Sensors::Sensor &sensor) {
    sensor.updateSensorName(getSensorNameInput(sensor.sensorType()));
}

void updateSensorValue(Sensors::Sensor &sensor) {
    sensor.updateSensorValue(
        getSensorValueInput(sensor.sensorName(), sensor.sensorType()));
}


int displayMenuItems() {
    std::cout << "== Select an operation ==" << '\n';
    std::cout <<
            "(1=display sensor, 2=update sensor, 3=display all sensors and values, 4=add another sensor, 0=exit): ";
    int operationSelection{};
    std::cin >> operationSelection;
    return operationSelection;
}

char displaySensorMenu(const std::string &                 sensorOperation,
                       const std::vector<Sensors::Sensor> &sensors) {
    std::cout << "== Select a sensor to " << sensorOperation << " ==\n(";
    for (std::size_t ii{0}; ii < sensors.size(); ++ii) {
        const auto sensorType = sensors[ii].sensorType();
        std::cout << Sensors::getSensorSelector(sensorType) << "=" << sensorType
                << ", ";
    }
    std::cout << "0=back): ";
    char sensorSelection{};
    while (true) {
        std::cin >> sensorSelection;
        const auto sensorType = Sensors::getSensorTypeBySelector(
            sensorSelection);
        if ((!sensorType && sensorSelection != '0') || (
                sensorType && !SensorBank::activeSensors[*sensorType])) {
            std::cout << "Not a selection. Try again: ";
        } else if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again: ";
        } else {
            break;
        }
    }
    return sensorSelection;
}

std::string getSensorDisplay(const Sensors::SensorType sensorType) {
    switch (sensorType) {
        case Sensors::temperature:
            return "temperature";
        case Sensors::humidity:
            return "humidity";
        case Sensors::pressure:
            return "pressure";
        case Sensors::altitude:
            return "altitude";
        default:
            return "???";
    }
}

std::string getSensorUnits(const Sensors::SensorType sensorType) {
    switch (sensorType) {
        case Sensors::temperature:
            return "C";
        case Sensors::humidity:
            return "%";
        case Sensors::pressure:
            return "hPa";
        case Sensors::altitude:
            return "m";
        default:
            return "???";
    }
}

std::ostream &operator<<(std::ostream &            out,
                         const Sensors::SensorType sensorType) {
    return out << getSensorDisplay(sensorType);
}
