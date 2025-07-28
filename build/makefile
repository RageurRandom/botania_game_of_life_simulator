CFLAGS = -Wall
CC = g++


botania_game_of_life : main.o cell.o game.o
	$(CC) $(CFLAGS) $? -o $@

main.o : ../src/main.cpp
	$(CC) $(CFLAGS) -c $? -o $@

cell.o : ../src/cell.cpp
	$(CC) $(CFLAGS) -c $? -o $@

game.o : ../src/game.cpp
	$(CC) $(CFLAGS) -c $? -o $@