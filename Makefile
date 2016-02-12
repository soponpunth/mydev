# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall


# INCLUDE BASE DIRECTORY AND BOOST DIRECTORY FOR HEADERS
LDFLAGS = -I/usr/local/Cellar/boost/1.50.0/include

# INCLUDE BASE DIRECTORY AND BOOST DIRECTORY FOR LIB FILES
LLIBFLAGS = -L/usr/local/Cellar/boost/1.50.0/lib

# SPECIFIY LINK OPTIONS
LINKFLAGS = -lboost_thread-mt -lboost_system-mt

# FINAL FLAGS -- TO BE USED THROUGHOUT
FLAGS = $(CFLAGS) $(LLIBFLAGS) $(LDFLAGS) $(LINKFLAGS)


# the build target executable:
TARGET = test

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(FLAGS) -o $(TARGET) $(TARGET).cpp

clean:
	$(RM) $(TARGET)
	$(RM) -rf $(TARGET).dSYM