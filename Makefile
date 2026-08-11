CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude $(shell sdl2-config --cflags)
LDFLAGS := $(shell sdl2-config --libs)

BUILD_DIR := build
TARGET := $(BUILD_DIR)/engine

SRCS := $(shell find src -name '*.cpp')
OBJS := $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

MATH_SRCS := $(shell find src/math -name '*.cpp')
MATH_OBJS := $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(MATH_SRCS))

MODEL_SRCS := src/Mesh.cpp src/Triangle.cpp src/Color.cpp
MODEL_OBJS := $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(MODEL_SRCS))

TEST_SRCS := $(shell find tests -name '*.cpp')
TEST_OBJS := $(patsubst tests/%.cpp,$(BUILD_DIR)/tests/%.o,$(TEST_SRCS))
TEST_DEPS := $(TEST_OBJS:.o=.d)
TEST_TARGET := $(BUILD_DIR)/tests/run_tests

GTEST_PREFIX := $(shell brew --prefix googletest)
GTEST_CXXFLAGS := -I$(GTEST_PREFIX)/include
GTEST_LDFLAGS := -L$(GTEST_PREFIX)/lib -lgtest -lgtest_main -pthread

.PHONY: all run clean test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

run: $(TARGET)
	./$(TARGET)

$(BUILD_DIR)/tests/%.o: tests/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(GTEST_CXXFLAGS) -MMD -MP -c $< -o $@

$(TEST_TARGET): $(MATH_OBJS) $(MODEL_OBJS) $(TEST_OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(MATH_OBJS) $(MODEL_OBJS) $(TEST_OBJS) -o $@ $(GTEST_LDFLAGS)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)
-include $(TEST_DEPS)
