//****************************************************************************************************
//
//      File:                Queens.cpp
//
//      Student:             Leon Krugliakov
//
//      Assignment:          Program #1
//
//      Course Name:         Data Structures II
//
//      Course Number:       COSC 3100 - 11
//
//      Due:                 October 27th, 2020
//
//
//      This program outputs a chess board with optimal placements of queens so that 
//		they can't attack each other.
//
//      Other files required:
//
//****************************************************************************************************

#include <iostream>

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

const int N = 10;

//****************************************************************************************************

void printBoard(const int board[N][N]);
bool isValid(const int board[N][N], int row, int col);
bool placeQueens(int board[N][N], int col);
bool organizeBoard();

//****************************************************************************************************

int main()
{
	organizeBoard();

	return 0;
}

//****************************************************************************************************

void printBoard(const int board[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) 
		{
			cout << board[i][j] << " ";
		}

		cout << endl;
	}
}

//****************************************************************************************************

bool isValid(const int board[N][N], int row, int col)
{
	bool valid = true;

	for (int i = 0; i < N; i++)
	{
		if (board[row][i] == 1)
		{
			valid = false;
		}
	}

	for (int i = row, j = col; i >= 0, j >= 0; i--, j--)
	{
		if (board[i][j] == 1)
		{
			valid = false;
		}
	}

	for (int i = row, j = col;i <= N - 1, j >= 0; i++, j--)
	{
		if (board[i][j] == 1)
		{
			valid = false;
		}
	}

	return valid;
}

//****************************************************************************************************

bool placeQueens(int board[N][N], int col)
{
	if (col >= N)
	{
		return true;
	}

	for (int i = 0; i < N; i++)
	{
		if (isValid(board, i, col))
		{
			board[i][col] = 1;

			if (placeQueens(board, col + 1))
			{
				return true;
			}

			board[i][col] = 0;
		}
	}

	return false;
}

//****************************************************************************************************

bool organizeBoard()
{
	bool success = false;

	int board[N][N];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] = 0;
		}
	}

	if (placeQueens(board, 0))
	{
		success = true;
	}

	printBoard(board);

	return success;
}

//****************************************************************************************************

/*
1 0 0 0 0
0 0 0 1 0
0 1 0 0 0
0 0 0 0 1
0 0 1 0 0
*/