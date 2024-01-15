#include <iostream>
#include "matrix.hpp"


int main()
{
	//const int Dimension = 4; 
	//Matrix gameBoard(Dimension); 
	//gameBoard.show();
	//std::cout << gameBoard.isArrange() << std::endl; 

	auto arrow = readKey(); 
	std::cout << (int)arrow << std::endl; 
	
	return 0; 
}
