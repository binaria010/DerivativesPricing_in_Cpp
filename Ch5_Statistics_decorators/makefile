# this is the make file for VanillaMain2. No use of Parameters class yet
# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++20 -I ../include/

# Source files
SRCS = ../source/PayOff3.cpp \
       ../source/PayOffBridge.cpp\
       ../source/PayOffPower2.cpp \
       ../source/Vanilla2.cpp \
       ../source/Parameters.cpp \
       ../source/PieceWiseConstParameters.cpp \
	   ../source/Random1.cpp \
       ../source/SimpleMC6.cpp \
	   ../source/MCStatistics.cpp \
       StatsMain1.cpp

# Output executable
TARGET = StatsMain1

# Default rule
all: $(TARGET)

# Linking step
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)