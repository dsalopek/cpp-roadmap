#include <array>
#include <iostream>
#include <limits>
#include <optional>
#include <string>
#include <vector>
#include <cstddef>
#include "Sensor.h"

namespace MenuItems {
    enum MainMenuItems : std::size_t {
        exit     = 0,
        create   = 1,
        update   = 2,
        display  = 3,
        maxItems = 4,
    };

    constexpr std::array<std::pair<MainMenuItems, std::string_view>, maxItems>
    mainMenuItems = {
        {
            {create, "add new sensor"},
            {update, "update sensors"},
            {display, "display all sensors"},
            {exit, "exit"},
        }
    };
}

// Declarations start
void printStartup();

void createSensor(std::vector<Sensors::Sensor> &sensors);

std::size_t displayMainMenu();

std::string getSensorNameInput(const Sensors::SensorMetadata &sensorMetadata);

double getSensorValueInput(std::string_view               sensorName,
                           const Sensors::SensorMetadata &sensorMetadata);

void updateSensorValue(Sensors::Sensor &sensor);

void updateSensorName(Sensors::Sensor &sensor);

std::size_t displaySensorCreationMenu();

std::size_t
displaySensorUpdateMenu(const std::vector<Sensors::Sensor> &sensors);

std::size_t getUnsignedNumericInput(std::size_t max);

double getSignedDoubleInput(double min = std::numeric_limits<double>::min(),
                            double max = std::numeric_limits<double>::max());

std::string getStringInput(bool emptyInputAllowed = false);

void displayAllSensors(const std::vector<Sensors::Sensor> &sensors);

void updateSensors(std::vector<Sensors::Sensor> &sensors);

void updateSensorStatus(Sensors::Sensor &sensor);

void clearInput();

// Declarations end


int main() {
    std::vector<Sensors::Sensor> activeSensors{};
    printStartup();

    std::vector<Sensors::Sensor> sensors{};

    bool exit{false};

    std::optional<std::size_t> mainMenuSelection{};
    while (!exit) {
        if (!mainMenuSelection) {
            mainMenuSelection = displayMainMenu();
            std::cout << '\n';
        }

        switch (*mainMenuSelection) {
            case MenuItems::create:
                createSensor(sensors);
                mainMenuSelection = {};
                break;
            case MenuItems::update:
                updateSensors(sensors);
                mainMenuSelection = {};
                break;
            case MenuItems::display:
                displayAllSensors(sensors);
                mainMenuSelection = {};
                break;
            case MenuItems::exit:
                std::cout << "Exiting...\n";
                exit = true;
                break;
            default:
                std::cout << "Invalid selection. Retry.";
                mainMenuSelection = {};
                break;
        }
        std::cout << '\n';
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

void createSensor(std::vector<Sensors::Sensor> &sensors) {
    std::size_t selection{displaySensorCreationMenu()};
    if (selection == 0)
        return;
    const Sensors::SensorMetadata &sensorMetadata = Sensors::sensorMetadata[
        --selection];
    const std::string sensorName = getSensorNameInput(sensorMetadata);
    Sensors::Sensor   sensor{
        sensorName, sensorMetadata,
        getSensorValueInput(sensorName, sensorMetadata)
    };

    std::cout << "Sensor added: " << sensor << "\n";
    sensors.push_back(sensor);
}

void updateSensors(std::vector<Sensors::Sensor> &sensors) {
    std::optional<std::size_t> sensorSelection{};

    while (true) {
        if (!sensorSelection) {
            *sensorSelection = displaySensorUpdateMenu(sensors);
        }
        if (*sensorSelection == 0)
            break;

        Sensors::Sensor &sensor = sensors[*sensorSelection - 1];

        while (true) {
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
            std::cout << "0=back\n>";
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
                sensor.updateSensorStatus(Sensors::Status::ENABLED, true);
                break;
            }
            if (updateSelection == 4 && sensorInBadState) {
                updateSensorStatus(sensor);
                break;
            }
            clearInput();
            std::cout << "Invalid input. Try again\n> ";
        }

        sensor.updateSensorStatus(Sensors::Status::HEALTHY, true);

        std::cout << "Sensor updated: " << sensor << "\n";
        std::cout << '\n';
    }
}

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string getStringInput(const bool emptyInputAllowed) {
    std::string sensorName{};
    std::cout << "> ";
    while (true) {
        clearInput();
        std::getline(std::cin, sensorName);
        if ((!emptyInputAllowed && sensorName.empty()) || sensorName.length() >
            20) {
            std::cout <<
                    "Sensor name must be between 1 and 20 characters (inclusive). You inputted "
                    << sensorName << ", which is " << sensorName.length() <<
                    " characters. Try again: ";
        } else if (!std::cin) {
            clearInput();
            std::cout << "Invalid input. Try again: ";
        } else {
            break;
        }
    }

    return sensorName;
}

std::string getSensorNameInput(const Sensors::SensorMetadata &sensorMetadata) {
    std::cout << "Enter a name for " << sensorMetadata.sensorDisplayName;
    std::cout << '\n';
    return getStringInput(true);
}

double getSignedDoubleInput(const double min, const double max) {
    double value{};
    std::cout << "> ";
    while (true) {
        std::cin >> value;
        if (value >= min && value <= max) {
            break;
        }
        clearInput();
        std::cout << "Invalid input. Try again\n> ";
    }

    return value;
}

double getSensorValueInput(const std::string_view         sensorName,
                           const Sensors::SensorMetadata &sensorMetadata) {
    std::cout << "Enter a value for " << sensorName << " (" <<
            sensorMetadata.sensorDisplayName << " " << sensorMetadata.
            sensorUnits << ")\n";

    return getSignedDoubleInput();
}

void updateSensorName(Sensors::Sensor &sensor) {
    sensor.updateSensorName(getSensorNameInput(sensor.sensorMetadata()));
}

void updateSensorValue(Sensors::Sensor &sensor) {
    sensor.updateSensorValue(
        getSensorValueInput(sensor.sensorName(), sensor.sensorMetadata()));
}

void updateSensorStatus(Sensors::Sensor &sensor) {
    sensor.resetSensorStatus();
}

std::size_t getUnsignedNumericInput(const std::size_t max) {
    std::size_t sensorSelection{};
    std::cout << "> ";
    while (true) {
        std::cin >> sensorSelection;
        if (sensorSelection == 0 || sensorSelection <= max) {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again\n> ";
    }
    return sensorSelection;
}

std::size_t displayMainMenu() {
    std::cout << "== Select an operation ==" << '\n';

    for (const std::pair<MenuItems::MainMenuItems, std::string_view> &
         mainMenuItem: MenuItems::mainMenuItems) {
        std::cout << mainMenuItem.first << '=' << mainMenuItem.second << '\n';
    }

    return getUnsignedNumericInput(MenuItems::mainMenuItems.size() - 1);
}

std::size_t displaySensorCreationMenu() {
    std::cout << "== Select a sensor type to create ==\n";
    for (std::size_t ii{0}; ii < Sensors::sensorMetadata.size(); ++ii) {
        std::cout << ii + 1 << '=' << Sensors::sensorMetadata[ii].
                sensorDisplayName
                << '\n';
    }
    std::cout << "0=back\n";
    return getUnsignedNumericInput(Sensors::sensorMetadata.size());
}

std::size_t
displaySensorUpdateMenu(const std::vector<Sensors::Sensor> &sensors) {
    std::cout << "== Select a sensor to update ==\n";
    if (sensors.empty()) {
        //return 0 if sensors is empty so it emulates 'back'
        return 0;
    }
    for (std::size_t ii{0}; ii < sensors.size(); ++ii) {
        auto &sensor = sensors[ii];
        std::cout << ii + 1 << '=' << sensor.sensorName() << " (" << sensor.
                sensorMetadata().sensorDisplayName << ")\n";
    }
    std::cout << "0=back\n";
    return getUnsignedNumericInput(sensors.size());
}

void displayAllSensors(const std::vector<Sensors::Sensor> &sensors) {
    std::cout << "== Active sensors ==\n";
    if (sensors.empty()) {
        std::cout << "No sensors found. Please add one to view.\n";
    } else {
        for (const auto &sensor: sensors) {
            std::cout << sensor << '\n';
        }
    }
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
