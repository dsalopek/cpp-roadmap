//
// Created by sokoban on 11/4/25.
//

#ifndef WEEK_9_INPUTUTILS_H
#define WEEK_9_INPUTUTILS_H

#include <iostream>
#include <limits>
#include <cstddef>

namespace InputUtils {
    double getSignedDoubleInput(
        double min = std::numeric_limits<double>::lowest(),
        double max = std::numeric_limits<double>::max());

    std::string getStringInputBounded(int lower = 0, int upper = 255);

    void clearInput();

    inline std::string getStringInputBounded(const int lower, const int upper) {
        std::string sensorName{};
        std::cout << "> ";
        while (true) {
            std::getline(std::cin >> std::ws, sensorName);
            if (std::cin && sensorName.length() >= static_cast<std::size_t>(
                    lower) && sensorName.length()
                <= static_cast<std::size_t>(upper)) {
                break;
            }
            clearInput();
            std::cout <<
                    "Invalid input. Name must be between " << lower << " and "
                    <<
                    upper << " characters. Try again\n> ";
        }

        return sensorName;
    }

    inline double getSignedDoubleInput(const double min, const double max) {
        double value{};
        std::cout << "> ";
        while (true) {
            std::cin >> value;
            if (std::cin && value >= min && value <= max) {
                break;
            }
            clearInput();
            std::cout << "Invalid input. Try again\n> ";
        }

        return value;
    }

    inline std::size_t getUnsignedNumericInput(const std::size_t max) {
        std::size_t sensorSelection{};
        std::cout << "> ";
        while (true) {
            std::cin >> sensorSelection;
            if (std::cin && (sensorSelection == 0 || sensorSelection <= max)) {
                break;
            }
            clearInput();

            std::cout << "Invalid input. Try again\n> ";
        }
        return sensorSelection;
    }

    inline void clearInput() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

#endif //WEEK_9_INPUTUTILS_H
