FILES = ./src/lib/CheckTie.c ./src/lib/CheckWinner.c ./src/lib/DrawBoard.c ./src/lib/Game.c ./src/lib/GetHelp.c ./src/lib/MarkBoard.c ./src/lib/UserInput.c ./src/tik-tak-toe.c

linux:
	mkdir build
	gcc $(FILES) -o ./build/Tik-Tak-Toe
windows:
	mkdir build 
	gcc $(FILES) -o ./build/Tik-Tak-Toe.exe
clean-linux:
	rm -rf ./build
clean-windows:
	rmdir /s build