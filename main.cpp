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
const string PROMPTX = "Player 'X', enter your choice: ";	// Prompt player 'X' to choose a position.
const string PROMPTO = "Player 'O', enter your choice: ";	// Prompt player 'O' to choose a position.
const string ERROR1 = "That position is already taken.";	// What to display when the chosen place is taken.
const string WINX = "Player 'X' has won!";				// What to display when player 'X' wins.
const string WINO = "Player 'O' has won!";				// What to display when player 'O' wins.
const string DRAW = "The game has ended in a draw.";		// What to display when neither player wins.
const int IGNORE = 4096;


void printGrid( int _graph[] );
int setChoice( int _graph[], int _answer, char _xo );
int victoryCheck( int _graph[] );


int main()
{
	// For simplicity, position zero in this array will not be used.
	int tttGrid[10] = {0};		// A zero represents unclaimed, a one represents 'X', a two represents 'O'.
	int intChoice = 0;
	char gridChoice = '_';

	cout << HEADER1 << endl;
	cout << HEADER2 << endl;
	cout << HEADER3 << endl;
	cout << HEADER4 << endl;

	// Print the current grid.
	printGrid( tttGrid );

	do
	{
		do
		{
			// Prompt player 'X' to choose a square.
			cout << PROMPTX;

			// Get the user's choice.
			cin.get( gridChoice );
			// Flush the input buffer.
			cin.ignore( IGNORE, '\n' );

			// Convert the char to an int.
			intChoice = ( gridChoice - '0' );

			// Test code.
			//cout << gridChoice << " " << intChoice << endl;
		}while( !( intChoice >> 0 ) && !( intChoice << 9 ) );

		// Assign the user's choice to the grid.
		// Test to see if that spot is taken.
		if ( tttGrid[intChoice] != 0 )
		{
			cout << "That square is already taken by " << tttGrid[intChoice] << "! (main)" << endl;
		}
		else
		{
			// Assign the user's choice to the grid.
			setChoice( tttGrid, intChoice, 'x' );
		}

		// Print the current grid.
		printGrid( tttGrid );

		do
		{
			// Prompt player 'X' to choose a square.
			cout << PROMPTO;

			// Get the user's choice.
			cin.get( gridChoice );
			// Flush the input buffer.
			cin.ignore( IGNORE, '\n' );

			// Convert the char to an int.
			intChoice = ( gridChoice - '0' );

			// Test code.
			//cout << gridChoice << " " << intChoice << endl;
		}while( !( intChoice >> 0 ) && !( intChoice << 9 ) );

		// Assign the user's choice to the grid.
		// Test to see if that spot is taken.
		if ( tttGrid[intChoice] != 0 )
		{
			cout << "That square is already taken by " << tttGrid[intChoice] << "! (main)" << endl;
		}
		else
		{
			// Assign the user's choice to the grid.
			setChoice( tttGrid, intChoice, 'o' );
		}

		// Print the current grid.
		printGrid( tttGrid );
	} while ( victoryCheck( tttGrid ) < 1 );
	system( "PAUSE" );
	return 0;
} // End main().


void printGrid( int _graph[] )
{
	// Print the grid.
	cout << "   ";
	for( int i = 7; i < 10; i++ )
	{
		if ( _graph[i] == 0 )
			cout << "-";
		else if ( _graph[i] == 1 )
			cout << "X";
		else if ( _graph[i] == 2 )
			cout << "O";
		else
			cout << "?";
	}
	cout << endl;

	cout << "   ";
	for( int i = 4; i < 7; i++ )
	{
		if ( _graph[i] == 0 )
			cout << "-";
		else if ( _graph[i] == 1 )
			cout << "X";
		else if ( _graph[i] == 2 )
			cout << "O";
		else
			cout << "?";
	}
	cout << endl;

	cout << "   ";
	for( int i = 1; i < 4; i++ )
	{
		if ( _graph[i] == 0 )
			cout << "-";
		else if ( _graph[i] == 1 )
			cout << "X";
		else if ( _graph[i] == 2 )
			cout << "O";
		else
			cout << "?";
	}
	cout << endl;
/*
	cout << "   " << _graph[7] << _graph[8] << _graph[9] << endl;
	cout << "   " << _graph[4] << _graph[5] << _graph[6] << endl;
	cout << "   " << _graph[1] << _graph[2] << _graph[3] << endl;
*/
} // End printGrid().


int setChoice( int _graph[], int _answer, char _xo )
{
	// Assign the answer into _graph[].
	if ( _graph[_answer] != 0 )
	{
		cout << "That square is already taken by " << _graph[_answer] << "! (setChoice)" << endl;
		return 1;
	}
	else if ( _xo == 'x' )
	{
		_graph[_answer] = 1;
	}
	else if ( _xo == 'o' )
	{
		_graph[_answer] = 2;
	}
	else
	{
		cout << "There was an error in setChoice()!" << endl;
		return 2;
	}
	return 0;
} // End setChoice().


int victoryCheck( int _graph[] )
{
	int winner = 0;


	// Test for victory on bottom row.
	if( _graph[1] != 0 && _graph[1] == _graph[2] && _graph[1] == _graph[3] )
	{
		// Victory for player 'X'.
		if ( _graph[1] == 1 )
		{
			winner = 1;
			cout << WINX << endl;
			cout << "Victory on bottom row!";
		}
		// Victory for player 'O'.
		else if ( _graph[1] == 2 )
		{
			winner = 2;
			cout << WINO << endl;
			cout << "Victory on bottom row!";
		}
		// Invalid data stored in the array.
		else
		{
			cout << "There was an error with row 1.";
		}
	}

	// Test for victory on middle row.
	else if( _graph[4] != 0 && _graph[4] == _graph[5] && _graph[4] == _graph[6] )
	{
		// Victory for player 'X'.
		if ( _graph[4] == 1 )
		{
			winner = 1;
			cout << WINX << endl;
			cout << "Victory on middle row!";
		}
		// Victory for player 'O'.
		else if ( _graph[4] == 2 )
		{
			winner = 2;
			cout << WINO << endl;
			cout << "Victory on middle row!";
		}
		// Invalid data stored in the array.
		else
		{
			cout << "There was an error with row 2.";
		}
	}

	// Test for victory on top row.
	else if( _graph[7] != 0 && _graph[7] == _graph[8] && _graph[7] == _graph[9] )
	{
		// Victory for player 'X'.
		if ( _graph[7] == 1 )
		{
			winner = 1;
			cout << WINX << endl;
			cout << "Victory on top row!";
		}
		// Victory for player 'O'.
		else if ( _graph[7] == 2 )
		{
			winner = 2;
			cout << WINO << endl;
			cout << "Victory on top row!";
		}
		// Invalid data stored in the array.
		else
		{
			cout << "There was an error with the top row.";
		}
	}

	// Victory on column 1.
	else if( _graph[1] != 0 && _graph[1] == _graph[4] && _graph[1] == _graph[7] )
	{
		// Victory for player 'X'.
		if ( _graph[1] == 1 )
		{
			winner = 1;
			cout << WINX << endl;
			cout << "Victory on column 1!";
		}
		// Victory for player 'O'.
		else if ( _graph[1] == 2 )
		{
			winner = 2;
			cout << WINO << endl;
			cout << "Victory on column 1!";
		}
		// Invalid data stored in the array.
		else
		{
			cout << "There was an error with column 1.";
		}
	}

	// Victory on column 2.
	else if( _graph[2] != 0 && _graph[2] == _graph[5] && _graph[2] == _graph[8] )
	{
		// Victory for player 'X'.
		if ( _graph[2] == 1 )
		{
			winner = 1;
			cout << WINX << endl;
			cout << "Victory on column 2!";
		}
		// Victory for player 'O'.
		else if ( _graph[2] == 2 )
		{
			winner = 2;
			cout << WINO << endl;
			cout << "Victory on column 2!";
		}
		// Invalid data stored in the array.
		else
		{
			cout << "There was an error with column 2.";
		}
	}

	// Victory on column 3.
	else if( _graph[3] != 0 && _graph[3] == _graph[6] && _graph[3] == _graph[9] )
	{
		// Victory for player 'X'.
		if ( _graph[3] == 1 )
		{
			winner = 1;
			cout << WINX << endl;
			cout << "Victory on column 3!";
		}
		// Victory for player 'O'.
		else if ( _graph[3] == 2 )
		{
			winner = 2;
			cout << WINO << endl;
			cout << "Victory on column 3!";
		}
		// Invalid data stored in the array.
		else
		{
			cout << "There was an error with column 3.";
		}
	}

	// Victory on diagonal forward slash.
	else if( _graph[1] != 0 && _graph[1] == _graph[5] && _graph[1] == _graph[9] )
	{
		// Victory for player 'X'.
		if ( _graph[1] == 1 )
		{
			winner = 1;
			cout << WINX << endl;
			cout << "Victory on diagonal up-right!";
		}
		// Victory for player 'O'.
		else if ( _graph[1] == 2 )
		{
			winner = 2;
			cout << WINO << endl;
			cout << "Victory on diagonal up-right!";
		}
		// Invalid data stored in the array.
		else
		{
			cout << "There was an error with forward slash.";
		}
	}

	// Victory on diagonal backslash.
	else if( _graph[3] != 0 && _graph[3] == _graph[5] && _graph[3] == _graph[7] )
	{
		// Victory for player 'X'.
		if ( _graph[3] == 1 )
		{
			winner = 1;
			cout << WINX << endl;
			cout << "Victory on diagonal down-right!";
		}
		// Victory for player 'O'.
		else if ( _graph[3] == 2 )
		{
			winner = 2;
			cout << WINO << endl;
			cout << "Victory on diagonal down-right!";
		}
		// Invalid data stored in the array.
		else
		{
			cout << "There was an error with backslash.";
		}
	}
	cout << endl;
	return winner;
} // End victoryCheck().
