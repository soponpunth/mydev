# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# define any directories containing header files
#
INCLUDES = -I/Users/snewper/Downloads/boost_1_60_0


# the build target executable:
TARGET = test

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(TARGET).cpp

clean:
	$(RM) $(TARGET)
	$(RM) -rf $(TARGET).dSYM