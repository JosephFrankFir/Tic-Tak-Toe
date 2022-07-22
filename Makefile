FILES = ./src/lib/CheckTie.c ./src/lib/CheckWinner.c ./src/lib/DrawBoard.c ./src/lib/Game.c ./src/lib/GetHelp.c ./src/lib/MarkBoard.c ./src/lib/UserInput.c ./src/tik-tak-toe.c

all:
	mkdir build
	gcc $(FILES) -o ./build/Tik-Tak-Toe
clean:
	rm -rf ./build
