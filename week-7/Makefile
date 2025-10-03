CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Werror -Iinclude

BUILD_DIR := build
SRC_DIR := src

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
# replaces the SRC file extensions .cpp to .o as a new value
# the comman SRCS:$(SRC_DIR)... means that on the SRCS variable, perform pattern substitution
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

TARGET := $(BUILD_DIR)/week_7

# first target has prerequisite of the executable. so make will look for the executable target (build/week_7)
all: $(TARGET)

# the executable target has a prerequisite of $(OBJS), which at the time of writing is build/main.o and build/Sensor.o.
# so expanded, this looks like: week_7: build/main.o build/Sensor.o. So make will look for these targets
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# the target is any file that starts with build/ and ends with .o, which has a prerequisite of a file with extension .cpp. (filename must match)
# the prerequisite (.cpp) file is checked by make if it is out-of-date (ie updated) since it was last run. ie if the prerequisite is newer tha the target
 # If so, the command is run. In this case, `g++ -std=c++17 -Wall -Wextra -Werror -c src/filename.cpp -o build/filename.o`
# $< symbol represents the first prerequisite value. $@ represents the target value
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR) # makes the build dir if not present
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)