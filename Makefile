#The options –g and –Wall must be enabled in the Makefile
CFLAGS = -g -Wall 
CC = g++

objects = param.o parse.o myshell.o

myshell: $(objects)
	$(CC) -o myshell $(objects)

myshell.o: myshell.cpp
param.o: param.cpp param.hpp
parse.o: parse.cpp parse.hpp

.PHONY : clean
clean: 
	rm test $(objects)