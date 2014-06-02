/*
http://xkcd.com/832/
http://en.wikipedia.org/wiki/Tic-tac-toe
*/


#include <iostream>
#include <string>


using namespace std;


const string HEADER1 = "Welcome to Tic-Tac-Toe!";
const string HEADER2 = "Please use the number pad as a guide to input locations, in this layout:";
const string HEADER3 = "\n   789\n   456\n   123\n";
const string HEADER4 = "Player 'X' will begin, followed by player 'O'.";
const string PROMPT1 = "Player 'X', enter your choice:";	// Prompt player 'X' to choose a position.
const string PROMPT2 = "Player 'O', enter your choice:";	// Prompt player 'O' to choose a position.
const string ERROR1 = "That position is already taken.";	// What to display when the chosen place is taken.
const string WINX = "Player 'X' has won!";				// What to display when player 'X' wins.
const string WINO = "Player 'O' has won!";				// What to display when player 'O' wins.
const string DRAW = "The game has ended in a draw.";		// What to display when neither player wins.


int main()
{
	// For simplicity, position zero in this array will not be used.
	int tttGrid[10] = {0,1,1,1,2,1,2,2,1,2};		// A zero represents unclaimed, a one represents 'X', a two represents 'O'.
	char gridChoice = '0';

	cout << HEADER1 << endl;
	cout << HEADER2 << endl;
	cout << HEADER3 << endl;
	cout << HEADER4 << endl;
	cout << PROMPT1 << endl;
	std::cin.get(char);

	// Victory on row 1.
	if( tttGrid[1] != 0 && tttGrid[1] == tttGrid[2] && tttGrid[1] == tttGrid[3] )
	{
		// Victory for player 'X'.
		if ( tttGrid[1] == 1 )
		{
			cout << WINX << endl;
		}
		// Victory for player 'O'.
		else if ( tttGrid[1] == 2 )
		{
			cout << WINO << endl;
		}
		// Invalid data stored in the array.
		else
		{
			cout << "There was an error with row 1.";
		}
	}

	// Victory on row 2.
	else if( tttGrid[4] != 0 && tttGrid[4] == tttGrid[5] && tttGrid[4] == tttGrid[6] )
	{
		// Victory for player 'X'.
		if ( tttGrid[1] == 1 )
		{
			cout << WINX << endl;
		}
		// Victory for player 'O'.
		else if ( tttGrid[1] == 2 )
		{
			cout << WINO << endl;
		}
		// Invalid data stored in the array.
		else
		{
			cout << "There was an error with row 2.";
		}
	}

	// Victory on row 3.
	else if( tttGrid[7] != 0 && tttGrid[7] == tttGrid[8] && tttGrid[7] == tttGrid[9] )
	{
		// Victory for player 'X'.
		if ( tttGrid[1] == 1 )
		{
			cout << WINX << endl;
		}
		// Victory for player 'O'.
		else if ( tttGrid[1] == 2 )
		{
			cout << WINO << endl;
		}
		// Invalid data stored in the array.
		else
		{
			cout << "There was an error with row 3.";
		}
	}

	// Victory on column 1.
	else if( tttGrid[1] != 0 && tttGrid[1] == tttGrid[4] && tttGrid[1] == tttGrid[7] )
	{
		// Victory for player 'X'.
		if ( tttGrid[1] == 1 )
		{
			cout << WINX << endl;
		}
		// Victory for player 'O'.
		else if ( tttGrid[1] == 2 )
		{
			cout << WINO << endl;
		}
		// Invalid data stored in the array.
		else
		{
			cout << "There was an error with column 1.";
		}
	}

	// Victory on column 2.
	else if( tttGrid[2] != 0 && tttGrid[2] == tttGrid[5] && tttGrid[2] == tttGrid[8] )
	{
		// Victory for player 'X'.
		if ( tttGrid[1] == 1 )
		{
			cout << WINX << endl;
		}
		// Victory for player 'O'.
		else if ( tttGrid[1] == 2 )
		{
			cout << WINO << endl;
		}
		// Invalid data stored in the array.
		else
		{
			cout << "There was an error with column 2.";
		}
	}

	// Victory on column 3.
	else if( tttGrid[3] != 0 && tttGrid[3] == tttGrid[6] && tttGrid[3] == tttGrid[9] )
	{
		// Victory for player 'X'.
		if ( tttGrid[1] == 1 )
		{
			cout << WINX << endl;
		}
		// Victory for player 'O'.
		else if ( tttGrid[1] == 2 )
		{
			cout << WINO << endl;
		}
		// Invalid data stored in the array.
		else
		{
			cout << "There was an error with column 3.";
		}
	}

	// Victory on diagonal backslash.
	else if( tttGrid[1] != 0 && tttGrid[1] == tttGrid[5] && tttGrid[1] == tttGrid[9] )
	{
		// Victory for player 'X'.
		if ( tttGrid[1] == 1 )
		{
			cout << WINX << endl;
		}
		// Victory for player 'O'.
		else if ( tttGrid[1] == 2 )
		{
			cout << WINO << endl;
		}
		// Invalid data stored in the array.
		else
		{
			cout << "There was an error with backslash.";
		}
	}

	// Victory on diagonal forward slash.
	else if( tttGrid[3] != 0 && tttGrid[3] == tttGrid[5] && tttGrid[3] == tttGrid[7] )
	{
		// Victory for player 'X'.
		if ( tttGrid[1] == 1 )
		{
			cout << WINX << endl;
		}
		// Victory for player 'O'.
		else if ( tttGrid[1] == 2 )
		{
			cout << WINO << endl;
		}
		// Invalid data stored in the array.
		else
		{
			cout << "There was an error with forward slash.";
		}
	}

	return 0;
}
