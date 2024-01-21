#include"matrix.hpp"

// handle wrong dir as well as not possible shift 
bool Matrix::isValidMove(int dir) const noexcept 
{
	switch (dir)
	{
	case UP: 
		return empty_R != boardDimension - 1; // not last row 
	case DOWN: 
		return empty_R != 0; // first row 
	case RIGHT: 
		return empty_C != 0; // first col
	case LEFT: 
		return empty_C != boardDimension - 1; // last col 
	}

	// dummy 
	return false;
}

void Matrix::shiftRight()noexcept
{
	int& emptyCell = gameBoard[empty_R][empty_C]; 
	int& leftCell = gameBoard[empty_R][empty_C - 1]; 

	std::swap(emptyCell, leftCell); 
	
	empty_C -= 1; // empty cell has shifted left by one cell; 
}

void Matrix::shiftLeft()noexcept
{
	int& emptyCell = gameBoard[empty_R][empty_C]; 
	int& rightCell = gameBoard[empty_R][empty_C + 1]; 

	std::swap(emptyCell, rightCell); 
	
	empty_C += 1; // empty Cell shifted right by one cell 
}

void Matrix::shiftUp()noexcept
{
	int& emptyCell = gameBoard[empty_R][empty_C];
	int& downCell = gameBoard[empty_R+1][empty_C];

	std::swap(emptyCell, downCell);

	empty_R += 1;  // empty cell came one cell down 
}

void Matrix::shiftDown()noexcept
{
	int& emptyCell = gameBoard[empty_R][empty_C];
	int& upCell = gameBoard[empty_R - 1][empty_C];

	std::swap(emptyCell, upCell);

	empty_R -= 1;  // empty cell came one cell down 
}

void Matrix::shiftNumber(int dir) noexcept
{
	if ( isValidMove(dir))
	{
		switch (dir)
		{
		case UP:
			shiftUp();
			break; 
		case DOWN: 
			shiftDown(); 
			break; 
		case LEFT: 
			shiftLeft();
			break; 
		case RIGHT: 
			shiftRight(); 
			break; 
		}
		updateIsArrange(); // check whether arranged or not and update isArranged 
		increaseTriedMoves(); 
	}
	else
	{
		std::cout << "Invalid Move" << std::endl; 
	}
}
