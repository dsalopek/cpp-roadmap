#include <iomanip>
#include <iostream>
#include <string>

// Declarations start
void printStartup();

std::string getSensorName(int sensorNumber);

int getSensorLimit(std::string_view sensorName, std::string_view bound);

int updateSensor(std::string_view sensorName, int lowerBound, int upperBound);

void displaySensor(int sensorNumber, std::string_view sensorName,
                   int sensorValue);

void displayMenuItems();

void displaySensorMenu(std::string_view sensorOperation,
                       std::string_view sensor1Name,
                       std::string_view sensor2Name,
                       std::string_view sensor3Name,
                       std::string_view sensor4Name);

void printNewLine();

// Declarations end

int main() {
    printStartup();
    //init sensors
    std::string sensor1Name{getSensorName(1)};
    int         sensor1LowerLimit{getSensorLimit(sensor1Name, "lower")};
    int         sensor1UpperLimit(getSensorLimit(sensor1Name, "upper"));
    int         sensor1Value{
        updateSensor(sensor1Name, sensor1LowerLimit, sensor1UpperLimit)
    };

    std::string sensor2Name{getSensorName(2)};
    int         sensor2LowerLimit{getSensorLimit(sensor2Name, "lower")};
    int         sensor2UpperLimit(getSensorLimit(sensor2Name, "upper"));
    int         sensor2Value{
        updateSensor(sensor2Name, sensor2LowerLimit, sensor2UpperLimit)
    };

    std::string sensor3Name{getSensorName(3)};
    int         sensor3LowerLimit{getSensorLimit(sensor3Name, "lower")};
    int         sensor3UpperLimit(getSensorLimit(sensor3Name, "upper"));
    int         sensor3Value{
        updateSensor(sensor3Name, sensor3LowerLimit, sensor3UpperLimit)
    };

    std::string sensor4Name{getSensorName(4)};
    int         sensor4LowerLimit{getSensorLimit(sensor4Name, "lower")};
    int         sensor4UpperLimit(getSensorLimit(sensor4Name, "upper"));
    int         sensor4Value{
        updateSensor(sensor4Name, sensor4LowerLimit, sensor4UpperLimit)
    };

    bool exit{false};


    while (!exit) {
        char operationSelection{};
        int  sensorSelection{};

        displayMenuItems();
        std::cin >> operationSelection;

        switch (operationSelection) {
            case 'a':
                displaySensorMenu("display", sensor1Name, sensor2Name,
                                  sensor3Name, sensor4Name);
                std::cin >> sensorSelection;
                while (sensorSelection < 1 || sensorSelection > 4) {
                    std::cout << "Sensor selection not value. Retry.";
                    std::cin >> sensorSelection;
                }
                switch (sensorSelection) {
                    case 1:
                        displaySensor(1, sensor1Name, sensor1Value);
                        break;
                    case 2:
                        displaySensor(2, sensor2Name, sensor2Value);
                        break;
                    case 3:
                        displaySensor(3, sensor3Name, sensor3Value);
                        break;
                    case 4:
                        displaySensor(4, sensor4Name, sensor4Value);
                        break;
                }
                break;
            case 'b':
                displaySensorMenu("update", sensor1Name, sensor2Name,
                                  sensor3Name, sensor4Name);
                std::cin >> sensorSelection;
                while (sensorSelection < 1 || sensorSelection > 4) {
                    std::cout << "Sensor selection not value. Retry.";
                    std::cin >> sensorSelection;
                }
                switch (sensorSelection) {
                    case 1:
                        sensor1Value = updateSensor(
                            sensor1Name, sensor1LowerLimit, sensor1UpperLimit);
                        break;
                    case 2:
                        sensor2Value = updateSensor(
                            sensor2Name, sensor2LowerLimit, sensor2UpperLimit);
                        break;
                    case 3:
                        sensor3Value = updateSensor(
                            sensor3Name, sensor3LowerLimit, sensor3UpperLimit);
                        break;
                    case 4:
                        sensor4Value = updateSensor(
                            sensor4Name, sensor4LowerLimit, sensor4UpperLimit);
                        break;
                }
                break;
            case 'c':
                displaySensor(1, sensor1Name, sensor1Value);
                displaySensor(2, sensor2Name, sensor2Value);
                displaySensor(3, sensor3Name, sensor3Value);
                displaySensor(4, sensor4Name, sensor4Value);
                break;
            case 'd':
                exit = true;
        }
    }


    return 0;
}

void printStartup() {
    const std::string_view name{"sensor-simulator-enhanced"};
    const std::string_view version{"0.0.3"};
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

void displayMenuItems() {
    std::cout << "== Select an operation ==" << '\n';
    std::cout << "a: display sensor" << '\n';
    std::cout << "b: update sensor" << '\n';
    std::cout << "c: display all sensors and values" << '\n';
    std::cout << "d: exit" << '\n';
}

void displaySensorMenu(std::string_view sensorOperation,
                       std::string_view sensor1Name,
                       std::string_view sensor2Name,
                       std::string_view sensor3Name,
                       std::string_view sensor4Name) {
    std::cout << "== Select a sensor to " << sensorOperation << "==\n";
    std::cout << "1: " << sensor1Name << '\n';
    std::cout << "2: " << sensor2Name << '\n';
    std::cout << "3: " << sensor3Name << '\n';
    std::cout << "4: " << sensor4Name << '\n';
}