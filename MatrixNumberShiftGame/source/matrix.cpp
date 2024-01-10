#include "matrix.hpp"

Matrix::Matrix(int dimension)
	: boardDimension(dimension), empty_C(dimension-1), empty_R(dimension-1), /*This wil get updated*/
	isArranged(false)
{
	// Intitialize member variable

	// Create a board of desired Dimension 
	gameBoard.resize(dimension, std::vector<int>(dimension));

	intializeGameBoard(); 
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



	// test whether board is getting intialized properly or not 
	for (int i = 0; i < boardDimension; ++i) {
		for (int j = 0; j < boardDimension; ++j) {
			std::cout << gameBoard[i][j] << "      ";
		}
		std::cout << std::endl; 
	}
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
