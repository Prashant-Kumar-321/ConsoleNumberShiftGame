#include "matrix.hpp"

Matrix::Matrix(int dimension)
	: boardDimension(dimension), 
	empty_C(dimension-1), empty_R(dimension-1), /*This wil get updated*/
	isArranged(false)
{
	// Intitialize member variable
	moveTried = 0; 
	totalMoves = 500; 

	// Create a board of desired Dimension 
	gameBoard.resize(dimension, std::vector<int>(dimension));

	intializeGameBoard(); 

	// making sure that number will be not arranged after intialization
	while (isArrange()) {
		intializeGameBoard(); 
	}
}

int Matrix::getUniqueRandomNum(const int& min, const int& max, std::vector<bool>& generatedNums)
{
	int randomNumber; 
	
	do{
		randomNumber = __random__::rand(min, max); 
	} while (generatedNums[randomNumber]);  

	generatedNums[randomNumber] = true; // marked as generated Number  

	return randomNumber; 
}

// Fill my Matrix with unique random values 
void Matrix::intializeGameBoard()
{
	const int cells = boardDimension*boardDimension; // number of cells in the gameBoard 
	
	// Range of random numbers board should be filled with 
	int minNum = 1, maxNum = cells-1; 

	// Keep track what are the random values we have filled our gameBoard with
	std::vector<bool> generatedNums(cells, false); 

	// filling gameBaord with unique random number in the range [1, maxNum]
	for (int i = 0; i < boardDimension; ++i)
	{
		for (int j = 0; j < boardDimension; ++j) 
		{
			// Last cell 
			if (i == empty_R && j == empty_C) {
				continue;
			}

			int randomNum = getUniqueRandomNum(minNum, maxNum, generatedNums); 
			gameBoard[i][j] = randomNum;
		}
	}

	// Last cell will be empty 
	// 0 is representing empty cell 
	gameBoard[empty_R][empty_C] = 0; 

	placeEmptyCellRandomlyWithinBoard();

	updateIsArrange(); 
}

void Matrix::placeEmptyCellRandomlyWithinBoard()
{
	int new_EmptyRow = __random__::rand(0, empty_R); 
	int new_EmptyCol = __random__::rand(0, empty_C); 

	std::swap(gameBoard[new_EmptyRow][new_EmptyCol], gameBoard[empty_R][empty_C]);

	// update empty cell 
	empty_R = new_EmptyRow; 
	empty_C = new_EmptyCol; 
}

/*Check is Matrix is Arranged */
bool Matrix::isUpperTriangleArranged() const noexcept 
{
	for (int row = 0; row < boardDimension; ++row)
	{
		for (int col = row+1; col < boardDimension; ++col) {
			int desiredNumber = row * boardDimension + col; 
			if (gameBoard[row][col] != desiredNumber) { return false; }
		}
	}
	return true;
}

bool Matrix::isLowerTriangleArraanged()const noexcept
{
	for (int row = 0; row < boardDimension; ++row)
	{
		for (int col = 0; col <= row; ++col) {
			int desiredNumber = row * boardDimension + col; 
			if (gameBoard[row][col] != desiredNumber) { return false; }
		}
	}

	return true; 
}

void Matrix::updateIsArrange()
{
	if ( !isUpperTriangleArranged()) {
		isArranged = false; 
	}
	else {
		isArranged = isLowerTriangleArraanged(); 
	}
	 
}

bool Matrix::isArrange()const noexcept { return isArranged; }

void Matrix::show()const noexcept(true)
{
	std::cout << std::endl;
	const int& nums = boardDimension; // total number of numbers in a row 
	const int spaceRate = 4;        // How space a number will take
	std::string initialHorizontalSapce = "\t\t\t"; 

	for (int i = 0; i < boardDimension; i++) {
		std::cout << initialHorizontalSapce;
		printLine(nums, spaceRate);
		std::cout << std::endl;

		std::cout << initialHorizontalSapce;
		printNumbers(gameBoard[i]);
		std::cout << std::endl;
	}
	std::cout << initialHorizontalSapce;
	printLine(nums, spaceRate);
	std::cout << std::endl; 

}


//********************** Moves Count ***********************************
void Matrix::increaseTriedMoves()
{
	moveTried++;
}

int Matrix::remainingMoves() const
{
	return totalMoves - moveTried;
}




// Test purpose Function 
void Matrix::printEmptyCellLocation() const
{
	std::cout << "emtpt Row = "<< empty_R << " , Empty Col = " << empty_C << std::endl;
}

int Matrix::getBoardDimension() const
{
	return boardDimension;
}