# this is the make file for VanillaMain2. No use of Parameters class yet
# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++20 -I ../include/

# Source files
SRCS = ../source/PayOff3.cpp \
       ../source/PayOffBridge.cpp\
       ../source/Random1.cpp \
       ../source/SimpleMC5.cpp \
       ../source/PayOffPower2.cpp \
       ../source/Vanilla2.cpp \
       ../source/Parameters.cpp \
       ../source/PieceWiseConstParameters.cpp \
       Ex4.3Main.cpp

# Output executable
TARGET = Ex4.3Main

# Default rule
all: $(TARGET)

# Linking step
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)