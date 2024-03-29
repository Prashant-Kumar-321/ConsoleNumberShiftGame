#pragma once
#include<random>
#include<vector>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<iomanip> // std::setw(), std::fill()
#include<string>

constexpr int PREFIX_CODE = -32;
constexpr int UP = 72;
constexpr int DOWN = 80;
constexpr int LEFT = 75;
constexpr int RIGHT = 77;
constexpr int ESC = 27;
constexpr bool NO = false; 


namespace __random__
{
	int rand(int min, int max); 
}

void clearScreen(); 

void printLine(int nums, int spaceRate); 
void printNumbers(const std::vector<int>& row); 

char readKey(); 


//  *******************Player information**************************
void inputPlayer(std::string& player); 
void displayStatusofPlayer(std::string& playerName, int level, int remMoves); 

// Looser or winneer Player 
bool askLooserIfWantsToRetry(); 
bool askWinnerIfWantsToLevelUp(); 

class Rule
{
public:
	static void printHeading(); 
	static void display();
	static void displayArrangedMatrix(int dim); 
};
