# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++20 -I ../include/

# Source files
SRCS = ../source/PayOff2.cpp \
       ../source/Random1.cpp \
       ../source/SimpleMC2.cpp \
       ../source/PayOffPower.cpp \
       ex3.2.cpp

# Output executable
TARGET = ex3.2main

# Default rule
all: $(TARGET)

# Linking step
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)