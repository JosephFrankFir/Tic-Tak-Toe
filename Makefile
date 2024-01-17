FILES = ./src/lib/Clean.c ./src/lib/SetDifficulty.c ./src/lib/MiniMax.c ./src/lib/EvaluateBoard.c ./src/lib/ClearBoard.c ./src/lib/CheckTie.c ./src/lib/CheckWinner.c ./src/lib/DrawBoard.c ./src/lib/Game.c ./src/lib/GetHelp.c ./src/lib/MarkBoard.c ./src/lib/UserInput.c ./src/tic-tak-toe.c
FLAGS = -g -ffreestanding -falign-jumps -falign-functions -falign-labels -falign-loops -fstrength-reduce -fomit-frame-pointer -finline-functions -Wno-unused-function -fno-builtin -Werror -Wno-unused-label -Wno-cpp -Wno-unused-parameter -Wall
linux:
	mkdir build
	gcc $(FLAGS) $(FILES) -o ./build/Tic-Tak-Toe
windows:
	mkdir build 
	gcc $(FLAGS) $(FILES) -o ./build/Tic-Tak-Toe.exe
clean-linux:
	rm -rf ./build
clean-windows:
	rmdir /s build
