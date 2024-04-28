#include <stdio.h>

void printBoard(int boardSize,char gameBoard[boardSize][boardSize]){

	//Print board header (Column identifier)
	printf("       ");
	for(int i=1; i<=boardSize; i++){
		printf("%d   ", i);
	}
	printf("\n");

	for(int rowIndex = 0; rowIndex < boardSize; rowIndex++){

		for(int columnIndex = 0; columnIndex < boardSize; columnIndex++){
      if(columnIndex == 0)printf("%d     ", rowIndex+1);
      printf(" %c ", gameBoard[rowIndex][columnIndex]? gameBoard[rowIndex][columnIndex]:' ');
      if(columnIndex != boardSize -1) printf("|");
    };

		if(rowIndex != boardSize - 1){
			printf("\n      ");
			for(int i = 0; i<((boardSize*4)-1); i++)printf("-");
			printf("\n");
		}
	};
	printf("\n");
}