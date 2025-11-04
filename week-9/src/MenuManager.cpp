//
// Created by sokoban on 11/4/25.
//

#include "../include/MenuManager.h"
#include "../include/InputUtils.h"
#include <iostream>

void printStartup();

std::size_t displayMainMenu();

namespace Menu {
    enum MenuState : std::size_t {
        exit     = 0,
        create   = 1,
        update   = 2,
        remove   = 3,
        display  = 4,
        maxItems = 5,
    };

    constexpr std::array<std::pair<MenuState, std::string_view>, maxItems>
    mainMenuItems = {
        {
            {create, "add new sensor"},
            {update, "update sensors"},
            {remove, "remove sensors"},
            {display, "display all sensors"},
            {exit, "exit"},
        }
    };

    MenuManager::MenuManager() = default;

    void MenuManager::displayMenu() {
        printStartup();
        bool exit{false};

        std::optional<std::size_t> mainMenuSelection{};
        while (!exit) {
            if (!mainMenuSelection) {
                mainMenuSelection = displayMainMenu();
                std::cout << '\n';
            }

            switch (*mainMenuSelection) {
                case create:
                    sensorManager_.addSensor();
                    mainMenuSelection = {};
                    break;
                case update:
                    sensorManager_.updateSensor();
                    mainMenuSelection = {};
                    break;
                case remove:
                    sensorManager_.removeSensor();
                    mainMenuSelection = {};
                    break;
                case display:
                    sensorManager_.displaySensors();
                    mainMenuSelection = {};
                    break;
                case MenuState::exit:
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
    }
}

void printStartup() {
    const std::string name{"main"};
    const std::string version{"0.0.9"};
    const std::string author{"Dylan"};

    std::cout << "Starting up...\n";
    std::cout << "Program name: " << name << '\n';
    std::cout << "Program version: " << version << '\n';
    std::cout << "Program author: " << author << '\n';
    std::cout << '\n';
}

std::size_t displayMainMenu() {
    std::cout << "== Select an operation ==" << '\n';

    for (const std::pair<Menu::MenuState, std::string_view> &
         mainMenuItem: Menu::mainMenuItems) {
        std::cout << mainMenuItem.first << '=' << mainMenuItem.second << '\n';
    }

    return InputUtils::getUnsignedNumericInput(Menu::mainMenuItems.size() - 1);
}
