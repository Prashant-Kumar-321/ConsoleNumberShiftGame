#pragma once
#include<random>
#include<vector>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<conio.h>

constexpr int PREFIX_CODE = -32;
constexpr int UP = 72;
constexpr int DOWN = 80;
constexpr int LEFT = 75;
constexpr int RIGHT = 77;



namespace __random__
{
	int rand(int min, int max); 
}

void printLine(int nums, int spaceRate); 
void printNumbers(const std::vector<int>& row); 

char readKey(); 