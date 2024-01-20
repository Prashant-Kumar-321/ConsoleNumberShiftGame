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
	int temp=0;
	std::cout << '|';
	for (int i = 0; i < row.size(); ++i)
	{
		if (row[i] == 0) // Empty cell of game board 
		{
			temp = i; 
			std::cout << std::setw(3) << std::setfill(' ') << std::right << 
				SPACE << GAP << '|';
		}
		else { // Non Empty Cell 
			std::cout << std::setw(3) << std::setfill(' ') << std::right <<
				row[i] << GAP << '|';
		}
	}

	std::cout << "\t\t\t " << temp << std::endl;
}

char readKey()
{
	char arrow; 
	arrow = _getch(); 
	if (arrow == PREFIX_CODE) {
		arrow = _getch(); // read extended code 
	}
	else {
		arrow = '\0'; // put null character to avoid collision with same ascii value of alpha character
	}

	return arrow; 
}

