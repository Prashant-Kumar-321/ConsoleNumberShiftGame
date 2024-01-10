#include "matrix.hpp"

Matrix::Matrix(int dimension)
{
	// Create a board of desired Dimension 
	gameBoard.resize(dimension, std::vector<int>(dimension));

	// print Dimension for test purpose
	std::cout << gameBoard[3].size() << std::endl;
	
	// intialize the board
	// -----Implement 
}