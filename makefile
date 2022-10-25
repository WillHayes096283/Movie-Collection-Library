## Author: William Hayes, Kenneth Wallace, Jackson Horton
## Group: CULT OF THE EMACS
# Makefile for Group Project 3: Movie Collection Library
# Last Modified: 10-21-2022
#
# Used for quickly and automatically compiling an executable.
#
# Type 'make' to create an executable.


### VARIABLES

## Compiler variable
CC = g++

## Compiler Flag variable
# Compile with debugging features (-g) and all errors + warnings (-Wall + -Wextra).
CFLAGS = -g -Wall -Wextra

## Target Flag variable
# Defines the output name for the executable.
TARGET = library


### TARGETS

## all
# Using $(TARGET) it will link all object (*.o) files.
all: 	$(TARGET)

## Target
$(TARGET): 	main.o Library.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o Library.o

## Library.o
# Requires Library header and implementation file.
Library.o:  Library.cpp Library.h
	$(CC) $(CFLAGS) -c Library.cpp

## main.o
# Requires main.cpp and all header files.
main.o: 	main.cpp Library.h
	$(CC) $(CFLAGS) -c main.cpp

## clean
# Removes all unnecessary files including objects (*.o) and emacs backup (*~) files.
clean:
	$(RM) $(TARGET) -f *.o *~
