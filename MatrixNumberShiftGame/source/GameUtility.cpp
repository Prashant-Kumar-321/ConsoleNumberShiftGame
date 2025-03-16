#include<ncurses.h>
#include "../Header/GameUtility.hpp"

constexpr auto SPACE = ' ';
constexpr auto GAP = ' ';


int __random__::rand(int min, int max)
{
	std::random_device rd; 
	std::mt19937 gen(rd());		

	std::uniform_int_distribution<> dis(min, max); 

	return dis(gen); 
}

void printLine(int nums, int spaceRate)
{
	addch('+');
	// std::cout << '+';
	for (int i = 1; i < (nums * spaceRate + nums); i++) {
		// std::cout << '-';
		addch('-');
	}
	// std::cout << '+';
	addch('+');
}

void printNumbers(const std::vector<int>& row)
{
	addch('|');
	for (int i = 0; i < row.size(); ++i)
	{
		if (row[i] == 0) // Empty cell of game board 
		{
			printw("%3c%c|", SPACE, GAP);
		}
		else { // Non Empty Cell 
			printw("%3d%c|", row[i], GAP);
		}
	}
}

void clearScreen(){
	clear();
	// system("cls"); 
}

void setupNcurses(){
	initscr();            // Start ncurses mode
    cbreak();             // Disable line buffering
    noecho();             // Don't echo input
    keypad(stdscr, TRUE); // Enable arrow key input
    mousemask(ALL_MOUSE_EVENTS, NULL); // Enable mouse events
    curs_set(0);          // Hide the cursor
}

void tearNcurses(){
	endwin();
}

int readKey(){
	int key; 
	do{	
		key = getch(); 
	}while(key == KEY_MOUSE);

	return key; 
}

void Rule::displayArrangedMatrix(int dim)
{
	std::vector<int> row(dim); 
	std::string horizontalSpace = "\t\t"; 

	for (int i = 0; i < dim; ++i) {
		printw("%s", horizontalSpace.c_str()); 
		printLine(dim, 4); // total nums = 3, space per number = 4; 
		addch('\n');  
		
		// prepare my row numbers
		for (int j = 0; j < dim; ++j) 
		{
			if (i == dim-1 && j == dim-1)// last cell 
			{
				row[j] = 0; 
			}
			else
			{
				row[j] = (i * dim + j) + 1; // (row x total_nums + col) + 1
			}
		}
		printw("%s", horizontalSpace.c_str()); 
		printNumbers(row); 
		addch('\n');  
	}
	printw("%s", horizontalSpace.c_str()); 
	printLine(dim, 4); 
	addch('\n');  
}

void Rule::printHeading()
{
	printw("%50s\n", "MATRIX PUZZLE");
	printw("%50s\n", "--------------");
}

void Rule::display()
{
	printHeading(); 
	for (int i = 0; i < 4; ++i) { addch('\n'); } // print 4 new lines 

	printw("\tGAME RULES \n\n");
	printw("\t1. You can Move Number only by one(1) CELL at a time by Arrow Keys !\n\n");
	printw("\t\t%-16s: HIT Up Arrow key\n", "TO Move Up");
	printw("\t\t%-16s: HIT Down Arrow key\n", "TO Move Down");
	printw("\t\t%-16s: HIT Left Arrow Key \n", "TO Move Left");
	printw("\t\t%-16s: HIT Right Arrow key\n\n", "TO Move Right");

	printw("\t2. You can move Number only at empty position  \n\n");

	printw("\t3. For each valid Move : Your total number of moves will be decreased by 1. \n\n");

	printw("\t4. You have to order Numbers of Matrix in Increasing order; for 3 X 3 Puzzle : \n\n");
	
	printw("\t\tArranged matrix is \n"); 
	displayArrangedMatrix(3); // print arranged 3x3 matrix 
	
	addch('\n'); 
	printw("\t5. You can exit the Game at any time by pressing ESC \n\n");
	printw("\tTry to arrange in minimum possible number of moves \n");
	printw("\tBest of Luck !!\n"); 
	printw("\tEnter any key to start Game.... \n\a");

	if(readKey() == ESC){tearNcurses; exit(0);}
}

//  *******************Player information**************************
void inputPlayer(std::string& player) {
	printw("Player Name : ");
	char name[50];
	echo();
	getnstr(name, 50);
	noecho();
	player = std::string(name);
}

void displayStatusofPlayer(std::string& playerName, int level, int remMoves) {
	// print everything in a single line 
	printw("Player Name: %-30s", playerName.c_str());
	printw("Level : %-10d", level);
	printw("Remaining Moves : %d\n", remMoves);

	// expected output 
	// Player Name: Prashant Kumar Gupta     Level : 1         Remaining Moves: 5 

}

bool askLooserIfWantsToRetry()
{
	printw("Press 'ESC' to Quit\n");
	printw("Press any key to Retry the Level\n");
	int userChoice = readKey();
	if (userChoice == ESC) {
		return false; 
	}
	return true;
}

bool askWinnerIfWantsToLevelUp()
{
	printw("Press 'ESC' to Quit\n");
	printw("Press any key to Enter in next level\n");

	int userChoice = readKey();
	if (userChoice == ESC) {
		return false; 
	}
	return true;
}
