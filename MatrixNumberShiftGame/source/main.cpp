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
	std::cout << gameBoard.isArrange() << std::endl;
		
	gameBoard.shiftNumber(72); 
	gameBoard.show(); 
	std::cout << gameBoard.isArrange() << std::endl; 




	return 0; 
}
