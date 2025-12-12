CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -O2
SRC = src
BUILD = bin
EXEC = out

# find all cpp files in src/
SRC_FILES := $(wildcard $(SRC)/*.cpp)
OBJ_FILES := $(patsubst $(SRC)/%.cpp,$(BUILD)/%.o,$(SRC_FILES))

# default target
all: $(EXEC)

# link executable
$(EXEC): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

# compile object files
$(BUILD)/%.o: $(SRC)/%.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# make sure bin folder exists
$(BUILD):
	mkdir -p $(BUILD)

# clean
clean:
	rm -rf $(BUILD)/*.o $(EXEC)

