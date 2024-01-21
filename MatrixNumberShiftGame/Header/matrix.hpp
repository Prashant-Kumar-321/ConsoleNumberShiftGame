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
	void shiftNumber(int dir) noexcept; 
	int remainingMoves() const; 
	
private: 
	// Matrix object can neither be assigned nor be copied 
	Matrix& operator=(const Matrix& other) = delete; 
	Matrix(const Matrix& other) = delete; 
private: 
	void intializeGameBoard(); 
	int getUniqueRandomNum(const int& min, const int& max, std::vector<bool>& generatedNums); 
	void placeEmptyCellRandomlyWithinBoard();
	bool isUpperTriangleArranged()const noexcept; 
	bool isLowerTriangleArraanged()const noexcept; 
	void updateIsArrange();

	void increaseTriedMoves();

	bool isValidMove(int dir)const noexcept;
	void shiftRight()noexcept; 
	void shiftLeft()noexcept; 
	void shiftUp()noexcept;
	void shiftDown()noexcept; 

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

