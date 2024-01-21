#include "GameUtility.hpp"

constexpr auto SPACE = ' ';
constexpr auto GAP = ' ';


int __random__::rand(int min, int max)
{
	std::random_device rd; 
	std::mt19937 gen(rd());		

	std::uniform_int_distribution<> dis(min, max); 

	return dis(gen); 
}

void clearScreen()
{
	system("cls"); 
}

void printLine(int nums, int spaceRate)
{
	std::cout << '+';
	for (int i = 1; i < (nums * spaceRate + nums); i++) {
		std::cout << '-';
	}
	std::cout << '+';
}

void printNumbers(const std::vector<int>& row)
{
	std::cout << '|';
	for (int i = 0; i < row.size(); ++i)
	{
		if (row[i] == 0) // Empty cell of game board 
		{
			std::cout << std::setw(3) << std::setfill(' ') << std::right << 
				SPACE << GAP << '|';
		}
		else { // Non Empty Cell 
			std::cout << std::setw(3) << std::setfill(' ') << std::right <<
				row[i] << GAP << '|';
		}
	}
}

char readKey()
{
	char arrow; 
	arrow = _getch(); 
	if (arrow == PREFIX_CODE) {
		arrow = _getch(); // read extended code 
	}
	else if (arrow == 27) { // Esc key 
		arrow = 27; 
	}
	else {
		arrow = '\0'; // put null character to avoid collision with same ascii value of alpha character
	}

	return arrow; 
}

void Game::Rule::displayArrangedMatrix(int dim)
{
	std::vector<int> row(dim); 
	std::string horizontalSpace = "\t\t"; 

	for (int i = 0; i < dim; ++i) {
		std::cout << horizontalSpace; 
		printLine(dim, 4); // total nums = 3, space per number = 4; 
		std::cout << "\n"; 
		
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
		std::cout << horizontalSpace; 
		printNumbers(row); 
		std::cout << "\n"; 
	}
	std::cout << horizontalSpace; 
	printLine(dim, 4); 
	std::cout << std::endl; 
}

void Game::Rule::printHeading()
{
	std::cout << std::setw(50) << "MATRIX PUZZLE" << std::endl;
	std::cout << std::setw(50) << "--------------" << std::endl;
}

void Game::Rule::display()
{
	printHeading(); 
	for (int i = 0; i < 4; ++i) { std::cout << "\n"; } // print 4 new lines 

	std::cout << "Game Rules :" << std::endl; 
	std::cout<< "\t1. You can Move Number only by one(1) CELL at a time by Arrow Keys !\n\n" << std::endl;
	std::cout<< "\t\tTO Move up : HIT Up Arrow key\n" << std::endl;
	std::cout<< "\t\tTO Move Down : HIT Down Arrow key\n" << std::endl;
	std::cout<< "\t\tTO Move Left : HIT Left Arrow Key \n" << std::endl;
	std::cout<< "\t\tTO Move Right : HIT Right Arrow key\n\n" << std::endl;

	std::cout<< "\t2. You can move Number only at empty position  \n\n" << std::endl;

	std::cout<< "\t3. For each valid Move : Your total number of moves will be decreased by 1. \n\n" << std::endl;

	std::cout<< "\t4. You have to order Numbers of Matrix in Increaing order; for 3 X 3 Puzzle : \n\n" << std::endl;
	
	std::cout << "\t\tArranged matrix is \n" << std::endl; 
	displayArrangedMatrix(3); // print arranged 3x3 matrix 
	
	std::cout << "\n"; 
	std::cout<< "\t5. You can exit the Game at any time by pressing \'E\' or \'e\'\n\n"<< std::endl;
	std::cout<< "\tTry to arrange in minimimum possible number of moves \n"<< std::endl;
	std::cout << "\tEnter any key to start Game.... \n\a" << std::endl;
	int temp = _getch(); //ignore i don't have to do anything with the return value
	 
}

//  *******************Player information**************************
void inputPlayer(std::string& player) {
	std::cout << "Player Name : ";
	std::getline(std::cin, player);
}
void displayPlayer(std::string& player) {
	std::cout << "Player Name: "<< player << std::endl;
}
