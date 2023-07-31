# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -std=c++11 -Wall -Wextra

# Directories
SRC_DIR := src
BIN_DIR := bin

# Source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)

# Object files (exclude main.o)
OBJ_FILES := $(filter-out $(BIN_DIR)/main.o, $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%.o, $(SRC_FILES)))

# Executable
EXECUTABLE := $(BIN_DIR)/contact_management_system

# Phony targets (non-file targets)
.PHONY: all clean

# Default target
all: $(EXECUTABLE)

# Create the 'bin' directory if it doesn't exist
$(shell mkdir -p $(BIN_DIR))

# Build executable
$(EXECUTABLE): $(BIN_DIR)/main.o $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Build main object file
$(BIN_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build other object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(BIN_DIR)/*.o $(EXECUTABLE)
