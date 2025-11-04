//
// Created by sokoban on 11/4/25.
//

#ifndef WEEK_9_MENUMANAGER_H
#define WEEK_9_MENUMANAGER_H

#include "SensorManager.h"
#include <optional>

namespace Menu {
    enum MenuState : std::size_t;

    class MenuManager {
    public:
        MenuManager();

        void displayMenu();

    private:
        std::optional<MenuState> menuState_;
        SensorManager            sensorManager_;
    };
}


#endif //WEEK_9_MENUMANAGER_H
