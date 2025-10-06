# ==============
# Compiler flags
CXX := g++
CXX_FLAGS := -std=c++17 -Wall -Wextra -Werror -Iinclude
# ==============
# Compiler flags

# =================
# Main build config
BUILD_DIR := build
SRC_DIR := src
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
# replaces the SRC file extensions .cpp to .o as a new value using pattern substitution
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
TARGET := $(BUILD_DIR)/application
# Main build config
# =================

# =================
# Test build config
TEST_DIR := test
TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)
# rename src files in test directory from .cpp to .o
TEST_OBJS := $(TEST_SRCS:$(TEST_DIR)/%.cpp=$(BUILD_DIR)/%.o)
# share sensor object from build config to avoid compiling twice
SENSOR_OBJ := $(BUILD_DIR)/Sensor.o
TEST_TARGET := $(BUILD_DIR)/application_test
# Test build config
# =================

# ==========
# GoogleTest
# Test information
EXTERNAL_DIR := external
# GTEST
GTEST_DIR := $(EXTERNAL_DIR)/googletest-1.17.0
# gtest source directory
GTEST_SRC_DIR := $(GTEST_DIR)/googletest/src
# gtest header directory
GTEST_INCLUDE_DIR := $(GTEST_DIR)/googletest/include
# other files/dirs for linker
GTEST_INTERNAL_INCLUDE := $(GTEST_DIR)/googletest
# GTEST object files
GTEST_OBJ := $(BUILD_DIR)/gtest-all.o
GTEST_MAIN_OBJ := $(BUILD_DIR)/gtest_main.o
# GTEST compiler options
# -I$(GTEST_INCLUDE_DIR): public API headers (gtest/gtest.h)
# -I$(GTEST_INTERNAL_INCLUDE): Internal headers needed to compile gtest-all.cc
# -pthread = Enable threading support
GTEST_CXX_FLAGS := -I$(GTEST_INCLUDE_DIR) -I$(GTEST_INTERNAL_INCLUDE) -pthread
# GTEST linker flag
GTEST_LDFLAGS := -pthread
# GoogleTest
# ==========

# ===========
# Build rules
# first target has prerequisite of the executable. so make will look for the executable target (build/application)
build: $(TARGET)

# the executable target has a prerequisite of $(OBJS), which at the time of writing is build/main.o and build/Sensor.o.
# so expanded, this looks like: application: build/main.o build/Sensor.o. So make will look for these targets
$(TARGET): $(OBJS) # link objects to target
	$(CXX) $(OBJS) -o $(TARGET)

# the target is any file that starts with build/ and ends with .o, which has a prerequisite of a file with extension .cpp. (filename must match)
# the prerequisite (.cpp) file is checked by make if it is out-of-date (ie updated) since it was last run. ie if the prerequisite is newer tha the target
 # If so, the command is run. In this case, `g++ -std=c++17 -Wall -Wextra -Werror -c src/filename.cpp -o build/filename.o`
# $< symbol represents the first prerequisite value. $@ represents the target value
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR) # makes the build dir if not present
	$(CXX) $(CXX_FLAGS) -c $< -o $@
# Build rules
# ===========

# =================
# GTest build rules
$(GTEST_OBJ): $(GTEST_SRC_DIR)/gtest-all.cc
	@echo $<
	@mkdir -p $(BUILD_DIR) # create build dir if not present
	$(CXX) $(CXX_FLAGS) $(GTEST_CXX_FLAGS) -c $< -o $@ # compile gtest-all

$(GTEST_MAIN_OBJ): $(GTEST_SRC_DIR)/gtest_main.cc
	@mkdir -p $(BUILD_DIR) # create build dir if not present
	$(CXX) $(CXX_FLAGS) $(GTEST_CXX_FLAGS) -c $< -o $@ # compile gtest_main
# GTest build rules
# =================

# ================
# Test build rules
build-test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS) $(SENSOR_OBJ) $(GTEST_OBJ) $(GTEST_MAIN_OBJ)
	# link objects to test target
	$(CXX) $(TEST_OBJS) $(SENSOR_OBJ) $(GTEST_OBJ) $(GTEST_MAIN_OBJ) $(GTEST_LDFLAGS) -o $(TEST_TARGET)

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	# compile cpp test source files into object files
	$(CXX) $(CXX_FLAGS) $(GTEST_CXX_FLAGS) -c $< -o $@
# Test build rules
# ================

# ===========
# Run targets
run: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)
# Run targets
# ===========

# ===============
# Utility targets
clean:
	rm -rf $(BUILD_DIR)

info:
	@echo "Build sources: " $(SRCS)
	@echo "Build objects: " $(OBJS)
	@echo "Build target: " $(TARGET)
	@echo ""
	@echo "Test sources: " $(SRCS)
	@echo "Test objects: " $(OBJS)
	@echo "Test target: " $(TARGET)
	@echo ""
	@echo "GoogleTest: " $(GTEST_DIR)
	@echo ""
	@echo "Test sources: " $(TEST_SRCS)
	@echo "Test objects: " $(TEST_OBJS)
# Utility targets
# ===============