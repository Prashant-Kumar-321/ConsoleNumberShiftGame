#include <iostream>
#include <string>
#include <memory>
#include<ncurses.h>

#include "../Header/matrix.hpp"

int main()
{
	setupNcurses();

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
			int key = readKey();

			// user wants to end the game 
			if (key == ESC) { // Esc key; 
				tearNcurses(); 
				exit(0);
			}

			gameBoard->shiftNumber(key);
		}

		// Decision after game loop 
		if (gameBoard->isArrange()) {

			printw("Congratulations \"%s\"\n", player.c_str());
			refresh();

			if (askWinnerIfWantsToLevelUp() == NO) {
				tearNcurses(); 
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

			printw("You Loose the Game \n");
			refresh(); 
			if (askLooserIfWantsToRetry() == false) {
				tearNcurses(); 
				exit(0); // clsoe game
			}
		}
    }

	printw("Program has ended"); 
	refresh(); 
	tearNcurses();
	return 0; 
}

/* TO DO: 

	1. Change the color of text
	2. Make it more attractive visually
*/
