#pragma once
#include<iostream>
#include <vector>

class Matrix
{
public:
	Matrix(int dimension);

	// Matrix object can neither be assigned nor be coied 
	Matrix& operator=(const Matrix& other) = delete; 
	Matrix(const Matrix& other) = delete; 

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
