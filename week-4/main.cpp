#include <iomanip>
#include <iostream>
#include <optional>
#include <string>

// Declarations start
void printStartup();

std::string getSensorName(int sensorNumber);

int getSensorLimit(const std::string &sensorName, const std::string &bound);

int updateSensorValue(const std::string &sensorName, int lowerBound,
                      int                upperBound);

void displaySensor(int sensorNumber, const std::string &sensorName,
                   int sensorValue);

int displayMenuItems(const std::optional<std::string> &extraSensorName);

int displaySensorMenu(const std::string &sensorOperation,
                      const std::string &sensor1Name,
                      const std::string &sensor2Name,
                      const std::string &sensor3Name,
                      const std::string &sensor4Name,
                      const std::optional<std::string> &sensor5Name);

void printNewLine();

// Declarations end

int main() {
    printStartup();
    //init sensors
    std::string sensor1Name{getSensorName(1)};
    std::cout << &sensor1Name;
    int sensor1LowerLimit{getSensorLimit(sensor1Name, "lower")};
    int sensor1UpperLimit(getSensorLimit(sensor1Name, "upper"));
    int sensor1Value{
        updateSensorValue(sensor1Name, sensor1LowerLimit, sensor1UpperLimit)
    };

    std::string sensor2Name{getSensorName(2)};
    int         sensor2LowerLimit{getSensorLimit(sensor2Name, "lower")};
    int         sensor2UpperLimit(getSensorLimit(sensor2Name, "upper"));
    int         sensor2Value{
        updateSensorValue(sensor2Name, sensor2LowerLimit, sensor2UpperLimit)
    };

    std::string sensor3Name{getSensorName(3)};
    int         sensor3LowerLimit{getSensorLimit(sensor3Name, "lower")};
    int         sensor3UpperLimit(getSensorLimit(sensor3Name, "upper"));
    int         sensor3Value{
        updateSensorValue(sensor3Name, sensor3LowerLimit, sensor3UpperLimit)
    };

    std::string sensor4Name{getSensorName(4)};
    int         sensor4LowerLimit{getSensorLimit(sensor4Name, "lower")};
    int         sensor4UpperLimit(getSensorLimit(sensor4Name, "upper"));
    int         sensor4Value{
        updateSensorValue(sensor4Name, sensor4LowerLimit, sensor4UpperLimit)
    };

    std::optional<std::string> sensor5Name{};
    std::optional<int>         sensor5lowerLimit{};
    std::optional<int>         sensor5UpperLimit{};
    std::optional<int>         sensor5Value{};

    bool exit{false};

    std::optional<int> operationSelection{};
    std::optional<int> sensorSelection{};
    while (!exit) {
        if (!operationSelection) {
            operationSelection = displayMenuItems(sensor5Name);
            sensorSelection    = {};
        }

        switch (*operationSelection) {
            case 1:
                if (!sensorSelection) {
                    sensorSelection = displaySensorMenu(
                        "display", sensor1Name, sensor2Name, sensor3Name,
                        sensor4Name, sensor5Name);
                }
                switch (*sensorSelection) {
                    case 1:
                        displaySensor(1, sensor1Name, sensor1Value);
                        sensorSelection = {};
                        break;
                    case 2:
                        displaySensor(2, sensor2Name, sensor2Value);
                        sensorSelection = {};
                        break;
                    case 3:
                        displaySensor(3, sensor3Name, sensor3Value);
                        sensorSelection = {};
                        break;
                    case 4:
                        displaySensor(4, sensor4Name, sensor4Value);
                        sensorSelection = {};
                        break;
                    case 5:
                        if (sensor5Name && sensor5Value) {
                            displaySensor(5, *sensor5Name, *sensor5Value);
                            sensorSelection = {};
                        }
                        break;
                    case 0:
                        sensorSelection = {};
                        operationSelection = {};
                        break;
                    default:
                        std::cout << "Invalid entry. Please retry.\n";
                        break;
                }
                break;
            case 2:
                if (!sensorSelection) {
                    sensorSelection = displaySensorMenu(
                        "update", sensor1Name, sensor2Name, sensor3Name,
                        sensor4Name, sensor5Name);
                }
                switch (*sensorSelection) {
                    case 1:
                        sensor1Value = updateSensorValue(
                            sensor1Name, sensor1LowerLimit, sensor1UpperLimit);
                        sensorSelection = {};
                        break;
                    case 2:
                        sensor2Value = updateSensorValue(
                            sensor2Name, sensor2LowerLimit, sensor2UpperLimit);
                        sensorSelection = {};
                        break;
                    case 3:
                        sensor3Value = updateSensorValue(
                            sensor3Name, sensor3LowerLimit, sensor3UpperLimit);
                        sensorSelection = {};
                        break;
                    case 4:
                        sensor4Value = updateSensorValue(
                            sensor4Name, sensor4LowerLimit, sensor4UpperLimit);
                        sensorSelection = {};
                        break;
                    case 5:
                        if (sensor5Name && sensor5Value) {
                            sensor5Value = updateSensorValue(
                                *sensor5Name, *sensor5lowerLimit,
                                *sensor5UpperLimit);
                            sensorSelection = {};
                        }
                        break;
                    case 0:
                        sensorSelection = {};
                        operationSelection = {};
                        break;
                    default:
                        std::cout << "Invalid entry. Please retry.\n";
                        break;
                }
                break;
            case 3:
                displaySensor(1, sensor1Name, sensor1Value);
                displaySensor(2, sensor2Name, sensor2Value);
                displaySensor(3, sensor3Name, sensor3Value);
                displaySensor(4, sensor4Name, sensor4Value);
                if (sensor5Name) displaySensor(5, *sensor5Name, *sensor5Value);
                operationSelection = {};
                break;
            case 4:
                sensor5Name = getSensorName(5);
                sensor5lowerLimit = getSensorLimit(*sensor5Name, "lower");
                sensor5UpperLimit = getSensorLimit(*sensor5Name, "upper");
                sensor5Value      = updateSensorValue(
                    *sensor5Name, *sensor5lowerLimit, *sensor5UpperLimit);
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
    const std::string version{"0.0.4"};
    const std::string author{"Dylan"};

    std::cout << "Starting up...\n";
    std::cout << "Program name: " << name << '\n';
    std::cout << "Program version: " << version << '\n';
    std::cout << "Program author: " << author << '\n';
    printNewLine();
}

std::string getSensorName(int sensorNumber) {
    std::cout << "Enter a name for sensor #" << sensorNumber << ": ";
    std::string sensorName{};
    std::getline(std::cin >> std::ws, sensorName);
    while (static_cast<int>(sensorName.length()) == 0 || static_cast<int>(
               sensorName.length()) > 20) {
        std::cout <<
                "Sensor name must be between 1 and 20 characters (inclusive). You inputted "
                << sensorName << ", which is " << static_cast<int>(sensorName.
                    length()) << "characters. Try again: ";
        std::getline(std::cin >> std::ws, sensorName);
    }

    return sensorName;
}

int getSensorLimit(const std::string &sensorName, const std::string &bound) {
    std::cout << "Enter the " << bound << " bound (inclusive) for " <<
            sensorName << ": ";
    int value{};
    std::cin >> value;
    return value;
}

int updateSensorValue(const std::string &sensorName, int lowerBound,
                      int                upperBound) {
    std::cout << "Enter the value for " << sensorName << ": ";
    int value{};
    std::cin >> value;

    while (value < lowerBound || value > upperBound) {
        std::cout << "You must input a value between " << lowerBound << " and "
                << upperBound << " (inclusive). Try again: ";
        std::cin >> value;
    }

    return value;
}

void displaySensor(int sensorNumber, const std::string &sensorName,
                   int sensorValue) {
    std::cout << sensorName << " (# " << sensorNumber << ")" << " reading: " <<
            sensorValue << '\n';
}

void printNewLine() {
    std::cout << '\n';
}

int displayMenuItems(const std::optional<std::string> &extraSensorName) {
    std::cout << "== Select an operation ==" << '\n';
    std::cout << "1: display sensor" << '\n';
    std::cout << "2: update sensor" << '\n';
    std::cout << "3: display all sensors and values" << '\n';
    if (!extraSensorName) {
        std::cout << "4: add another sensor " << '\n';
    }
    std::cout << "0: exit" << '\n';
    int operationSelection{};
    std::cin >> operationSelection;
    return operationSelection;
}

int displaySensorMenu(const std::string &               sensorOperation,
                      const std::string &               sensor1Name,
                      const std::string &               sensor2Name,
                      const std::string &               sensor3Name,
                      const std::string &               sensor4Name,
                      const std::optional<std::string> &sensor5Name) {
    std::cout << "== Select a sensor to " << sensorOperation << "==\n";
    std::cout << "1: " << sensor1Name << '\n';
    std::cout << "2: " << sensor2Name << '\n';
    std::cout << "3: " << sensor3Name << '\n';
    std::cout << "4: " << sensor4Name << '\n';
    if (sensor5Name) std::cout << "5: " << *sensor5Name << '\n';
    std::cout << "0: back\n";
    int sensorSelection{};
    std::cin >> sensorSelection;
    return sensorSelection;
}
