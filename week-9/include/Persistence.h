#ifndef WEEK_8_PERSISTENCE

#define WEEK_8_PERSISTENCE

#include "Sensor.h"
#include <vector>
#include <string>

namespace CSV {
    const std::string defaultFilename = "data.csv";

    class Persistence {
    public:
        Persistence() = default;

        static std::vector<Sensors::Sensor> &loadSensorData(
            std::vector<Sensors::Sensor> &sensors,
            const std::string &           filename = defaultFilename);

        static bool saveSensorData(const std::vector<Sensors::Sensor> &sensors,
                                   const std::string &filename =
                                           defaultFilename);
    };
}

#endif //WEEK_8_PERSISTENCE
