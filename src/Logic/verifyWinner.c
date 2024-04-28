
int verifyWinner(int boardSize, char gameBoard[boardSize][boardSize]){

	int hasWinner = 0;
	char winner = ' ';

	// Find winners in columns and rows
	for( int primaryIndex = 0; (primaryIndex < boardSize && !hasWinner);  primaryIndex++){

		int allTestedValuesOfRowIsEqual = 1, allTestedValuesOfColumnIsEqual = 1;
		for( 
			int secondaryIndex = 1; 
			(secondaryIndex < boardSize && (allTestedValuesOfRowIsEqual || allTestedValuesOfColumnIsEqual)); 
			secondaryIndex++
		){
			allTestedValuesOfRowIsEqual = allTestedValuesOfRowIsEqual? (
					((gameBoard[primaryIndex][secondaryIndex] == gameBoard[primaryIndex][secondaryIndex-1]) ) &&
					gameBoard[primaryIndex][secondaryIndex] != 0
			):0;

			allTestedValuesOfColumnIsEqual = allTestedValuesOfColumnIsEqual? (
				(gameBoard[secondaryIndex][primaryIndex] == gameBoard[secondaryIndex-1][primaryIndex]) && 
				gameBoard[secondaryIndex][primaryIndex] != 0
			):0;
		}

		if(allTestedValuesOfRowIsEqual || allTestedValuesOfColumnIsEqual) hasWinner = 1;
	}

	if(hasWinner) return 1; // If found winner in columns or rows, don't need test in diagonal;

	// Find winners in diagonals
	int allPrimaryDiagonalValuesIsEqual = 1, allSecondaryDiagonalValuesIsEqual = 1;
	for(int diagonalIndex = 1;  diagonalIndex < boardSize; diagonalIndex++){
		allSecondaryDiagonalValuesIsEqual = allSecondaryDiagonalValuesIsEqual? (
			gameBoard[diagonalIndex][boardSize - (diagonalIndex+1)] == gameBoard[diagonalIndex -1][boardSize - diagonalIndex] && 
			gameBoard[diagonalIndex][boardSize - (diagonalIndex+1)]
		):0; 
		
		allPrimaryDiagonalValuesIsEqual = allPrimaryDiagonalValuesIsEqual? (
				gameBoard[diagonalIndex][diagonalIndex] == gameBoard[diagonalIndex- 1][diagonalIndex-1] &&
				gameBoard[diagonalIndex][diagonalIndex]
		):0;
	}

	hasWinner = allPrimaryDiagonalValuesIsEqual || allSecondaryDiagonalValuesIsEqual;
	if(hasWinner) return 1;
	return (0); //If not found winner, return 0
}