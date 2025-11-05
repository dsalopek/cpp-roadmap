//
// Created by sokoban on 11/4/25.
//

#ifndef WEEK_9_SENSORMANAGER_H
#define WEEK_9_SENSORMANAGER_H

#include "Sensor.h"
#include <vector>

class SensorManager {
public:

    SensorManager();
    ~SensorManager();

    void addSensor();

    void removeSensor();

    void updateSensor();

    void displaySensors() const;

private:
    std::vector<Sensors::Sensor> sensors_;
};

#endif //WEEK_9_SENSORMANAGER_H
