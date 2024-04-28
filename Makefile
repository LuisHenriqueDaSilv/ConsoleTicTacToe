CC =gcc

all: ./run 
	@echo "\nCompilado"
run: 
	$(CC) ./src/main.c ./src/Logic/verifyWinner.c ./src/Tools/printBoard.c ./src/Logic/handleInput.c ./src/Tools/clearTerminal.c -o ./run