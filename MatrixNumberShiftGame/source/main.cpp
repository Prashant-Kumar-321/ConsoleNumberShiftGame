#include <iostream>
#include <string>
#include<Windows.h>

#include "matrix.hpp"


int main()
{
	int LEVEL = 1; 
	std::string player = "Prashant"; 
/*	inputPlayer(player);

	clearScreen(); 
	Game::Rule::display()*/; 

	// Creating a game Object 
	Matrix *game = new Matrix(LEVEL + 3); // dim = LEVEL+3.  
	game->setTotalMoves(5); 

	// Main game Loop 
	while (!game->isArrange() && game->remainingMoves() != 0)
	{
		clearScreen(); 
		Game::Rule::printHeading();
		displayPlayer(player);

		game->show(); 
		char key = readKey();
		// user wants to end the game 
		if (key == 27) { // Esc key; 
			exit(0); 
		} 

		game->shiftNumber(key);
	}

	if (game->isArrange()) {
		std::cout << "User solved the puzzle" << std::endl; 
	}
	else // moves finished
	{
		std::cout << "Player could not arrange in the given moves"<< std::endl; 
	}



	delete game; 

	return 0; 
}
