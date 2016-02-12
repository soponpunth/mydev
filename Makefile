# the compiler: gcc for C program, define as g++ for C++
CC = c++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# define any directories containing header files
#
INCLUDES = -I/usr/local/Cellar/boost/1.50.0/include


# the build target executable:
TARGET = test

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(TARGET).cpp

clean:
	$(RM) $(TARGET)
	$(RM) -rf $(TARGET).dSYM