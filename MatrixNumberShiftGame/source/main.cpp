#include <iostream>
#include <string>
#include "matrix.hpp"


int main()
{
	int LEVEL = 1; 
	std::string player = ""; 
	inputPlayer(player); 

	Game::Rule::display(); 
	Game::Rule::printHeading();
	displayPlayer(player); 

	return 0; 
}
