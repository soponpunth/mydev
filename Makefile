# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -O2

# INCLUDE BASE DIRECTORY AND BOOST DIRECTORY FOR HEADERS
IFLAGS = -I/usr/local/Cellar/boost/1.50.0/include -I/usr/local/include

# FINAL FLAGS -- TO BE USED THROUGHOUT
ARMADILLO_FLAGS = -L/usr/local/lib -larmadillo

BOOST_FLAGS = -L/usr/local/Cellar/boost/1.50.0/lib -lboost_thread -lboost_system


# the build target executable:
TARGET = test

all:
	$(CC) -c $(CFLAGS) -o car_state.o car_state.cpp
	$(CC) $(CFLAGS) $(IFLAGS) $(ARMADILLO_FLAGS) $(BOOST_FLAGS) -o server server.cpp car_state.o 
	$(CC) $(CFLAGS) $(IFLAGS) $(ARMADILLO_FLAGS) $(BOOST_FLAGS) -o client client.cpp


$(TARGET): $(TARGET).cpp
	$(CC) $(IFLAGS) $(ARMADILLO_FLAGS) $(BOOST_FLAGS) -o $(TARGET) $(TARGET).cpp

clean:
	$(RM) $(TARGET) client server
	$(RM) -rf *.dSYM