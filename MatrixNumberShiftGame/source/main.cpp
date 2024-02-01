#include <iostream>
#include <string>
#include <memory>

#include "matrix.hpp"


int main()
{
	int LEVEL = 1;
	int TOTALMOVES = 700;
	std::string player = "Prashant";
	inputPlayer(player);

	clearScreen();
	Rule::display();

	while (true)
	{
		// Creating a game Object 
		std::unique_ptr<Matrix> gameBoard = std::make_unique<Matrix>(LEVEL + 3); // dim = LEVEL+3.  
		gameBoard->setTotalMoves(TOTALMOVES);

		// Main game Loop 
		while (!gameBoard->isArrange() && gameBoard->remainingMoves() != 0)
		{
			clearScreen();
			Rule::printHeading();
			displayStatusofPlayer(player, LEVEL, gameBoard->remainingMoves());

			gameBoard->show();
			char key = readKey();

			// user wants to end the game 
			if (key == ESC) { // Esc key; 
				exit(0);
			}

			gameBoard->shiftNumber(key);
		}

		// Decision after game loop 
		if (gameBoard->isArrange()) {

			std::cout << "congratulation \""<< player << "\" " << std::endl;

			if (askWinnerIfWantsToLevelUp() == NO) {
				std::exit(0); 
			}
			else {
				LEVEL += 1; 
				TOTALMOVES *= 2; 
			}
		}
		else //Moves ran out 
		{
			clearScreen();
			Rule::printHeading();
			displayStatusofPlayer(player, LEVEL, gameBoard->remainingMoves());
			gameBoard->show();

			std::cout << "You Loose the Game" << std::endl;
			if (askLooserIfWantsToRetry() == false) {
				exit(0); // clsoe game
			}
		}
    }

	std::cout << "Prgram has ended " << std::endl;
	std::cout<< _getch(); 
	return 0; 
}
