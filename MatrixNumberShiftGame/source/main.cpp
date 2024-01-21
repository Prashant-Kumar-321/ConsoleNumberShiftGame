#include <iostream>
#include "matrix.hpp"


int main()
{

	const int Dimension = 4; 
	Matrix gameBoard(Dimension);
	gameBoard.show();
	//gameBoard.printEmptyCellLocation();
	//std::cout << gameBoard.getBoardDimension() << std::endl; 
	//std::cout << "Arranged = "<< gameBoard.isArrange() << std::endl;
		
	// **** Bug in shifting Numbers *****

	std::cout << gameBoard.remainingMoves() << std::endl; 
	gameBoard.shiftNumber(readKey());
	std::cout << gameBoard.remainingMoves() << std::endl; 

	//gameBoard.shiftNumber(80); // down 
	//gameBoard.shiftNumber(75); // left 
	//gameBoard.shiftNumber(77); // right 
	gameBoard.show(); 
	//std::cout << gameBoard.isArrange() << std::endl; 




	return 0; 
}
