#include <iomanip>
#include <iostream>
#include <string>

void printStartup();

std::string getSensorName(int sensorNumber);

int getSensorLimit(std::string_view sensorName, std::string_view bound);

int updateSensor(std::string_view sensorName, int lowerBound, int upperBound);

void displaySensor(int sensorNumber, std::string_view sensorName,
                   int sensorValue);

void printNewLine();

int main() {
    printStartup();

    std::string sensor1Name{getSensorName(1)};
    int         sensor1LowerLimit{getSensorLimit(sensor1Name, "lower")};
    int         sensor1UpperLimit(getSensorLimit(sensor1Name, "upper"));
    printNewLine();

    std::string sensor2Name{getSensorName(2)};
    int         sensor2LowerLimit{getSensorLimit(sensor2Name, "lower")};
    int         sensor2UpperLimit(getSensorLimit(sensor2Name, "upper"));
    printNewLine();

    std::string sensor3Name{getSensorName(3)};
    int         sensor3LowerLimit{getSensorLimit(sensor3Name, "lower")};
    int         sensor3UpperLimit(getSensorLimit(sensor3Name, "upper"));
    printNewLine();

    std::string sensor4Name{getSensorName(4)};
    int         sensor4LowerLimit{getSensorLimit(sensor4Name, "lower")};
    int         sensor4UpperLimit(getSensorLimit(sensor4Name, "upper"));
    printNewLine();

    int sensor1Value{
        updateSensor(sensor1Name, sensor1LowerLimit, sensor1UpperLimit)
    };
    printNewLine();

    int sensor2Value{
        updateSensor(sensor2Name, sensor2LowerLimit, sensor2UpperLimit)
    };
    printNewLine();

    int sensor3Value{
        updateSensor(sensor3Name, sensor3LowerLimit, sensor3UpperLimit)
    };
    printNewLine();

    int sensor4Value{
        updateSensor(sensor4Name, sensor4LowerLimit, sensor4UpperLimit)
    };
    printNewLine();

    displaySensor(1, sensor1Name, sensor1Value);
    displaySensor(2, sensor2Name, sensor2Value);
    displaySensor(3, sensor3Name, sensor3Value);
    displaySensor(4, sensor4Name, sensor4Value);

    return 0;
}

void printStartup() {
    const std::string_view name{"sensor-simulator-enhanced"};
    const std::string_view version{"0.0.2"};
    const std::string_view author{"Dylan"};

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

int getSensorLimit(std::string_view sensorName, std::string_view bound) {
    std::cout << "Enter the " << bound << " bound (inclusive) for " <<
            sensorName << ": ";
    int value{};
    std::cin >> value;
    return value;
}

int updateSensor(std::string_view sensorName, int lowerBound, int upperBound) {
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

void displaySensor(int sensorNumber, const std::string_view sensorName,
                   int sensorValue) {
    std::cout << std::setw(20);
    std::cout << sensorNumber << " (" << sensorName << ")" << " reading: " <<
            sensorValue << '\n';
}

void printNewLine() {
    std::cout << '\n';
}
