#include <iostream>
#include <string>

void printStartup();

void displaySensor(const std::string &sensorName, int sensorValue);

int updateSensor(const std::string &sensorName);

void printNewLine();

int main() {
    printStartup();

    int temperature = 75;
    int pressure    = 1013;
    int humidity    = 50;

    displaySensor("Temperature", temperature);
    temperature = updateSensor("Temperature");
    printNewLine();

    displaySensor("Pressure", pressure);
    pressure = updateSensor("Pressure");
    printNewLine();

    displaySensor("Humidity", humidity);
    humidity = updateSensor("Humidity");
    printNewLine();

    displaySensor("Temperature", temperature);
    displaySensor("Pressure", pressure);
    displaySensor("Humidity", humidity);

    return 0;
}

void printStartup() {
    std::cout << "Starting up...\n";
    std::cout << "Program name: sensor-simulation\n";
    std::cout << "Program version: 0.0.1\n";
    std::cout << "Program author: Dylan\n";
    printNewLine();
}

void displaySensor(const std::string &sensorName, int sensorValue) {
    std::cout << sensorName << " reading: " << sensorValue << '\t' << '\n';
}

int updateSensor(const std::string &sensorName) {
    std::cout << "Enter new value for " << sensorName << ": ";
    int newValue{};
    std::cin >> newValue;
    return newValue;
}

void printNewLine() {
    std::cout << '\n';
}
