CXX := g++
CXXFLAGS := --std=c++17 -Werror -Wall

SRCS :=$(wildcard *.cc)
OBJS := $(SRCS:%.cc=%.o)

TARGET := application

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $< -o $(TARGET)

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@rm -rf $(TARGET)