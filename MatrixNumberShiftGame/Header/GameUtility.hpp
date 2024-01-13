#pragma once
#include<random>
#include<vector>
#include<algorithm>
#include<iostream>
#include<iomanip>

namespace __random__
{
	int rand(int min, int max); 
}

void printLine(int nums, int spaceRate); 
void printNumbers(const std::vector<int>& row); 