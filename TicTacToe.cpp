#include "stdafx.h"
#include<iostream>

using namespace std;

char matrix[4][4]; // grid
int x, y; // coordinates of the movement
int movement; // choice is made by NumPad and coodinates are set automaticaly
int turn = -1; // even value X's turn, odd value 0's turn
int scoreX = 0, score0 = 0; // X score, 0 score
int firstDiagonal = 0, secondDiagonal = 0, line[4] = { 0, 0, 0 }, column[4] = { 0, 0, 0 }; // if one of these variables is 3 then X wins
																						   // if one of them is -3 then 0 wins

void showGrid()
{
	system("cls");

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << matrix[i][j] << "\t" ;
		cout << endl << endl;
	}
}

void checkMove()
{
	if (turn % 2 == 0)
		cout << "It is X's turn. Pick your move: ";
	else
		cout << "It is 0's turn. Pick your move: ";
pick_move:
	cin >> movement;

	switch (movement)
	{
	case 1:
		x = 2;
		y = 0;
		// CHECKING IF IT IS OK TO PICK THAT SPOT
		if (matrix[x][y] != '*')
		{
			cout << "Oops... Somebody took this spot already :( Try again, please! ";
			cout << "\n Pick a free spot: ";
			goto pick_move;
		}
		break;
	case 2:
		x = 2;
		y = 1;
		// CHECKING IF IT IS OK TO PICK THAT SPOT
		if (matrix[x][y] != '*')
		{
			cout << "Oops... Somebody took this spot already :( Try again, please! ";
			cout << "\n Pick a free spot: ";
			goto pick_move;
		}
		break;
	case 3:
		x = 2;
		y = 2;
		// CHECKING IF IT IS OK TO PICK THAT SPOT
		if (matrix[x][y] != '*')
		{
			cout << "Oops... Somebody took this spot already :( Try again, please! ";
			cout << "\n Pick a free spot: ";
			goto pick_move;
		}
		break;
	case 4:
		x = 1;
		y = 0;
		// CHECKING IF IT IS OK TO PICK THAT SPOT
		if (matrix[x][y] != '*')
		{
			cout << "Oops... Somebody took this spot already :( Try again, please! ";
			cout << "\n Pick a free spot: ";
			goto pick_move;
		}
		break;
	case 5:
		x = 1;
		y = 1;
		// CHECKING IF IT IS OK TO PICK THAT SPOT
		if (matrix[x][y] != '*')
		{
			cout << "Oops... Somebody took this spot already :( Try again, please! ";
			cout << "\n Pick a free spot: ";
			goto pick_move;
		}
		break;
	case 6:
		x = 1;
		y = 2;
		// CHECKING IF IT IS OK TO PICK THAT SPOT
		if (matrix[x][y] != '*')
		{
			cout << "Oops... Somebody took this spot already :( Try again, please! ";
			cout << "\n Pick a free spot: ";
			goto pick_move;
		}
		break;
	case 7:
		x = 0;
		y = 0;
		// CHECKING IF IT IS OK TO PICK THAT SPOT
		if (matrix[x][y] != '*')
		{
			cout << "Oops... Somebody took this spot already :( Try again, please! ";
			cout << "\n Pick a free spot: ";
			goto pick_move;
		}
		break;
	case 8:
		x = 0;
		y = 1;
		// CHECKING IF IT IS OK TO PICK THAT SPOT
		if (matrix[x][y] != '*')
		{
			cout << "Oops... Somebody took this spot already :( Try again, please! ";
			cout << "\n Pick a free spot: ";
			goto pick_move;
		}
		break;
	case 9:
		x = 0;
		y = 2;
		// CHECKING IF IT IS OK TO PICK THAT SPOT
		if (matrix[x][y] != '*')
		{
			cout << "Oops... Somebody took this spot already :( Try again, please! ";
			cout << "\n Pick a free spot: ";
			goto pick_move;
		}
		break;
	default:	//IN CASE OF INVALID INPUT 
		cout << "Invalid move! Try again... " << endl;
		goto pick_move;
		break;
	}
}

void pick()
{
	if (turn % 2 == 0)
		matrix[x][y] = 'X';
	else
		matrix[x][y] = '0';
}

char checkWinner()
{
	if (x == y) // checking if the move is placed on the first diagonal
	{
		if (turn % 2 == 0)
		{
			if (x == 1)	// if the move is in the middle of the grid, increment both diagonals
				secondDiagonal++;
			firstDiagonal++;
		}
		else
		{
			if (x == 1) // if the move is in the middle of the grid, decrement both diagonals
				secondDiagonal--;
			firstDiagonal--;
		}
	}
	else
		if(x + y == 2) // checking if the move is placed on the second diagonal
	{
			if (turn % 2 == 0)
			{
				secondDiagonal++;
			}
			else
			{
				secondDiagonal--;
			}
	}

	if (turn % 2 == 0) // if X's move, then increment the line and column
	{
		line[x]++;
		column[y]++;
	}
	else // if 0's move, then decrement the line and column
	{
		line[x]--;
		column[y]--;
	}

	// CHECKING IF THERE IS A WINNER YET
	if (firstDiagonal == 3)
	{
		scoreX++;
		return 'X';
	}
	if (firstDiagonal == -3)
	{
		score0++;
		return '0';
	}
	if (secondDiagonal == 3)
	{
		scoreX++;
		return 'X';
	}
	if (secondDiagonal == -3)
	{
		score0++;
		return '0';
	}
	for (int i = 0; i < 3; i++)
	{
		if (line[i] == 3 || column[i] == 3)
		{
			scoreX++;
			return 'X';
		}
		if (line[i] == -3 || column[i] == -3)
		{
			score0++;
			return '0';
		}
	}

	//END OF CHECKING
	turn++;
	return 'N';
}

void initialize()
{
	firstDiagonal = 0;
	secondDiagonal = 0;
	turn = -1;

	for (int i = 0; i < 3; i++)
	{
		line[i] = 0;
		column[i] = 0;
	}
}

int main()
{
	bool reset = true;
	char winner = 'N', checkReset;

	//INITIALIZE
play_again:

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			matrix[i][j] = '*';

	//END_OF_INITIALIZE

	do
	{
		winner = checkWinner();
		showGrid();
		
		if (winner != 'N')
		{
			cout << endl << "Aaaaaand the winner is " << winner << "! Congrats!" << endl;
			cout << "Would you like to play again?(Y/N) ";
			cin >> checkReset;
			
			if (checkReset == 'N' || checkReset =='n')
			{
				cout << "The X won: " << scoreX << " time(s) and 0 won: " << score0 << " time(s). ";
				system("PAUSE");
				return 0;
			}
			else
			{
				initialize();
				goto play_again;
			}
		}

		checkMove();
		pick();

	} while (turn < 8);
	
	if (winner == 'N')
	{
		cout << endl << "No winner today!... :(" << endl;
		cout << "Would you like to play again?(Y/N) ";
		cin >> checkReset;

		if (checkReset == 'Y')
			goto play_again;
	}

	cout << "The X won: " << scoreX << " time(s) and 0 won: " << score0 << " time(s).";
	system("PAUSE");
	return 0;
}

