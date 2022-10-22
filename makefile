##/**
## * @file makefile
## * @author William Hayes
## * @date 2022-10-20
## * @brief makefile for compiling
## * 
## * long descript
## */

CC = g++

CFLAGS = -g -Wall -Wextra

default: library

library: Library.o main.o
	$(CC) $(CFLAGS) -o library Library.o main.o

Library.o:	Library.cpp Library.h
	$(CC) $(CFLAGS) -c Library.cpp

main.o:		main.cpp Library.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) library *.o *~ *#
