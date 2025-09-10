# this is the make file for VanillaMain2. No use of Parameters class yet
# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++20 -I ../../include/

# Source files
SRCS = ../../source/PayOff3.cpp \
       ../../source/PayOffBridge.cpp \
       ../../source/PayOffPower2.cpp \
       ../../source/Vanilla2.cpp \
       ../../source/Parameters.cpp \
       ../../source/PieceWiseConstParameters.cpp \
       ../../source/Random1.cpp \
       ../../source/SimpleMC6_smart.cpp \
       ../../source/MCStatistics.cpp \
       ../../source/ConvergenceTable_smart.cpp \
       StatsMain2.cpp

# SimpleMC6_smart is made out of SimpleMC6.cpp for smart version with no Wrapper

# Object files (replace .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Output executable
TARGET = StatsMain2

# Default rule
all: $(TARGET)

# Linking step
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Compilation step (pattern rule)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(TARGET)