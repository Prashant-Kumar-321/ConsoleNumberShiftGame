#pragma once
#include<iostream>
#include<iomanip>
#include <vector>

#include "GameUtility.hpp"

class Matrix
{
public:
	Matrix(int dimension);
	void show() const noexcept(true); 
	bool isArrange() const noexcept; 

private: 
	// Matrix object can neither be assigned nor be copied 
	Matrix& operator=(const Matrix& other) = delete; 
	Matrix(const Matrix& other) = delete; 
private: 
	int getUniqueRandomNum(const int& min, const int& max, std::vector<bool>& generatedNums); 
	void placeEmptyCellRandomlyWithinBoard();
	bool isUpperTriangleArranged()const noexcept; 
	bool isLowerTriangleArraanged()const noexcept; 
	void updateIsArranged(); 

private:
	void intializeGameBoard(); 

private: 
	int boardDimension; 
	int empty_R; 
	int empty_C; 
	int totalMoves; 
	int moveTried; 
	bool isArranged; 

	// Actual Game Board 
	std::vector<std::vector<int>> gameBoard; 

};

