cmake_minimum_required(VERSION 3.14)
project(week_7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
set(CMAKE_LINK_WARNING_AS_ERROR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Wshadow -Wconversion -Wpedantic)

add_executable(week_7 src/main.cpp include/Sensor.h src/Sensor.cpp)

#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        # v1.17.0
#        URL https://github.com/google/googletest/archive/52eb8108c5bdec04579160ae17225d66034bd723.zip
#)
#FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        sensor_test
        test/SensorTest.cpp
        src/Sensor.cpp
)

add_subdirectory(external/googletest-1.17.0)
target_link_libraries(
        sensor_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(sensor_test)
