#include <stdio.h>
#include <ctype.h>

// Logic
#include "Logic/verifyWinner.h"
#include "Logic/handleInput.h"

// Tools
#include "Tools/printBoard.h"
#include "Tools/clearTerminal.h"

int main(){

	clearTerminal();

	int boardSize = 3, hasAWinner = 0, turnsCounter = 0, exitGame = 0;
	char *errorMessage = "", currentTurn = 'X';

	while (!exitGame){
		errorMessage = ""; currentTurn = 'X';

		char gameBoard[boardSize][boardSize];
		// Set all gameBoard datas to 0
		for(int ir=0; ir< boardSize; ir++){
			for(int ic=0; ic< boardSize; ic++){
				gameBoard[ir][ic] = 0;
			}
		}

		printf("\n==================================================\n");
		printf("   Seja bem vindo ao Jogo da Velha de terminal!\n");
		printf("--------------------------------------------------\n");
		printf("Para  jogar é simples. Basta, na sua vez, escolher  \n");
		printf("a cordenada do tabuleiro desejada .\n");
		printf("A cordenada deve seguir o seguinte padrão:\n");
		printf("linha coluna. EXEMPLO: 1 1\n");
		printf("\nTamanho do tabuleiro: %dx%d\n", boardSize, boardSize);
		printf("\n===============O que deseja fazer?================\n");
		printf("J: jogar; \n");
		printf("E: editar o tamanho do tabuleiro\n");
		printf("S: sair do jogo\n");
		printf("==================================================\n");
		char menuInput;
		scanf(" %c", &menuInput);
		clearTerminal();

		switch (menuInput){
			case 'S'://Exit
			case 's': 
				printf("Foi bom ter você por aqui! S2\n");
				exitGame = 1;
				break;
			case 'E': //Edit a gameBoard size
			case 'e':
				char boardSizeInput = 0;
				int boardSizeInputInt = 0;

				while(boardSizeInputInt > 9 || boardSizeInputInt < 2){
					printf("Dimensão do tabuleiro (n): ");
					scanf(" %c", &boardSizeInput);
					while(getchar() != '\n');
					boardSizeInputInt = boardSizeInput -'0';
					clearTerminal();
					if(boardSizeInputInt > 9 || boardSizeInputInt <2) printf("Tamanho invalido!\n");
				}
				boardSize = boardSizeInputInt;
				break;

			case 'J': 
			case 'j':// Play
				hasAWinner = 0; turnsCounter = 0;
				while (!hasAWinner && turnsCounter < boardSize * boardSize){
					clearTerminal();
					putchar('\n');
					printBoard(boardSize, gameBoard);
					putchar('\n');

					if (errorMessage){
						printf("%s\n", errorMessage);
						errorMessage = "";
					}
					printf("É a vez de %c, qual sera a jogada? ", currentTurn);

					int inputError = handleInput(boardSize, gameBoard, currentTurn);
					if (inputError){
						errorMessage = "Não foi possivel jogar na posição informada!";
						continue;
					}

					hasAWinner = verifyWinner(boardSize, gameBoard);
					if (!hasAWinner){
						turnsCounter++;
						currentTurn = currentTurn == 'X' ? 'O' : 'X';
					};
				}
				clearTerminal();
				printBoard(boardSize, gameBoard);

				if (!hasAWinner){
					printf("Empate.");
					continue;
				}
				printf("\n==================================================\n");
				printf("          O ganhador foi: %c. Parabens!\n", currentTurn);
				break;
		}
	}
}