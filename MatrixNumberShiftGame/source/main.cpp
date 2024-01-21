#include <iostream>
#include "matrix.hpp"


int main()
{
	//72 u
	//80 d
	//75 l
	//77 r

	const int Dimension = 4; 
	Matrix gameBoard(Dimension);
	gameBoard.show();
	//gameBoard.printEmptyCellLocation();
	//std::cout << gameBoard.getBoardDimension() << std::endl; 
	//std::cout << "Arranged = "<< gameBoard.isArrange() << std::endl;
		
	// **** Bug in shifting Numbers *****

	std::cout << gameBoard.remainingMoves() << std::endl; 
	gameBoard.shiftNumber(72);
	std::cout << gameBoard.remainingMoves() << std::endl; 

	//gameBoard.shiftNumber(80); // down 
	//gameBoard.shiftNumber(75); // left 
	//gameBoard.shiftNumber(77); // right 
	gameBoard.show(); 
	//std::cout << gameBoard.isArrange() << std::endl; 




	return 0; 
}
