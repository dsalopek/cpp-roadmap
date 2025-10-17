#include "Sensor.h"
#include <vector>
#include <string>

namespace CSV {
    constexpr std::string_view header = "sensorType,sensorName,value,status";
    const std::string defaultFilename = "data.csv";

    std::vector<Sensors::Sensor>& loadSensorData(std::vector<Sensors::Sensor>& sensors, const std::string& filename = defaultFilename);
    bool saveSensorData(const std::vector<Sensors::Sensor>& sensors, const std::string& filename = defaultFilename);
}