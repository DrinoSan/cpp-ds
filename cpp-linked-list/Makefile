# Compiler and compiler flags
CXX = clang++
CXXFLAGS = -std=c++17 -Wall

# Target executable
TARGET = linked-list

# Source file
SRC = linked-list.cpp

# Object file
OBJ = $(SRC:.cpp=.o)

# Rule to build the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files from source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean rule
clean:
	rm -f $(OBJ) $(TARGET)
