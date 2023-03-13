# compiler = gcc
CC = g++
CFLAGS = -Wall -Wextra -pedantic

main: ./src/main.cpp ./include/commands.hpp ./include/databases.hpp ./include/helpers.hpp
	$(CC) $(CFLAGS) -o main ./src/main.cpp

clean: 
	rm -f main *.o