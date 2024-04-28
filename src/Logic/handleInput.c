// Return 0 to sucess
// Return 1 to error

#include <stdio.h> // scanf()
#include <ctype.h> // isdigit()

int handleInput(int boardSize, char gameBoard[boardSize][boardSize], char currentTurn ){
        
	char rowInput, columnInput;
	scanf(" %c %c", &rowInput, &columnInput);

	//If input is not a digit, return error
	if(!isdigit(rowInput) && !isdigit(columnInput)) return 1;

	// Get Decimal value of rowInput in ASCII table and substract
	// ASCII value of char "1" (49). Substract 1 to get a matrix index of gameBoard:
	int selectedRowIndex = rowInput-'1', selectedColumnIndex = columnInput-'1';

	if(
			(selectedRowIndex >= 0 && selectedRowIndex < boardSize) 
			&& (selectedColumnIndex >= 0 && selectedColumnIndex < boardSize)
	){
			if(gameBoard[selectedRowIndex][selectedColumnIndex]) return 1; //Error: Position not available 
			gameBoard[selectedRowIndex][selectedColumnIndex] = currentTurn;
			
			return 0; // No-error
	}
	return 1; // Error: Position not exist in game table
}