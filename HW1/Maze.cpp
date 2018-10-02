#include "Maze.h"
#include <string>
#include <sstream>
#include <iostream>
#include <ctime>
using namespace std;

// Constructor
Board::Board()
{
	//
}

/**
    Fills up a 4x4 board with a player, walls and an exit

    @param player and amount of bad guys
*/

void Board::newBoard(Player *hero, const int badGuys)
{
	int randNum = 0;
	// seed the random function
	srand(time(NULL));

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			// random!!
			randNum = rand()%101+0;

			// player start
			if (board_[i][j] == board_[0][0])
			{

				board_[i][j] = Human;
			}
			// exit
			else if(board_[i][j] == board_[3][3])
			{
				board_[i][j] = Exit;
			}
			else if (board_[i][j] == board_[1][2])
			{
				board_[i][j] = Enemy;
			}
			// prevent impossible win condition
			else if((board_[i][j] == board_[0][1]) || (board_[i][j] == board_[1][1]) || (board_[i][j] == board_[3][2]) || (board_[i][j] == board_[2][3]))
			{
				board_[i][j] = Empty;
			}
			else if(randNum < 10)
			{
				board_[i][j] = Treasure;
			}
			// walls
			else if (randNum < 20)
			{
				board_[i][j] = Wall;	
			}
			//empty space
			else
			{
				board_[i][j] = Empty;	
			}
		}
	}
}

/**
    Print out the 4x4 board
*/
void Board::printBoard()
{
	for(int r = 0; r < 4; r++)
	{
		cout << board_[r][0] << board_[r][1] << board_[r][2] << board_[r][3] << endl;
	}
}

/**
    Get the value of the input swaure

    @param position
*/
const char* Board::get_square_value(Position pos)
{

	const char* output = board_[pos.row][pos.col];
	return output;
	
}

/**
    Set the value of a wanted square

    @param position to be filled and value to be used to fill in square
*/
void Board::SetSquareValue(Position pos, const char* value)
{
	board_[pos.row][pos.col] = value;
}

/**
    Print out the available moves for the player

    @param Current player
*/
void Board::GetMoves(Player *p)
{
	int currentRow = (p->get_position().row);
	int currentCol = (p->get_position().col);
	int downOne = (p->get_position().row+1);
	int rightOne = (p->get_position().col+1);
	int upOne = (p->get_position().row-1);
	int leftOne = (p->get_position().col-1);

	cout << "You can go: ";

	// starting position
	if((p->get_position().row == 0) && (p->get_position().col == 0) )
	{
		// enemy BELOW
		if((board_[downOne][currentCol] != Empty))
		{
			if(board_[currentRow][rightOne] == Empty)
			{
				cout << "RIGHT ";
			}		
		}
		// enemy RIGHT
		else if((board_[currentRow][rightOne] != Empty))
		{
			if(board_[downOne][currentCol] == Empty)
			{
				cout << "DOWN ";
			}		
		}
		else
		{
			cout << "RIGHT DOWN" << endl;
		}
	}
	// top row
	else if(p->get_position().row == 0)
	{
		// enemy BELOW
		if((board_[downOne][currentCol] != Empty))
		{
			if(board_[currentRow][leftOne] == Empty)
			{
				cout << "LEFT "; 
			}
			if(board_[currentRow][rightOne] == Empty)
			{
				cout << "RIGHT ";
			}
			if(board_[downOne][currentCol] == Treasure)
			{
				cout << "DOWN ";
			}	
		}
		// enemy RIGHT
		else if((board_[currentRow][rightOne] != Empty))
		{
			if(board_[currentRow][leftOne] == Empty)
			{
				cout << "LEFT "; 
			}
			if(board_[downOne][currentCol] == Empty)
			{
				cout << "DOWN ";
			}		
			if(board_[currentRow][rightOne] == Treasure)
			{
				cout << "RIGHT ";
			}
		}
		// enemy LEFT
		else if((board_[currentRow][rightOne] != Empty))
		{
			if(board_[currentRow][rightOne] == Empty)
			{
				cout << "RIGHT "; 
			}
			if(board_[downOne][currentCol] == Empty)
			{
				cout << "DOWN ";
			}		
			if(board_[currentRow][leftOne] == Treasure)
			{
				cout << "LEFT ";
			}	
		}
		else
		{
			cout << "RIGHT LEFT DOWN" << endl;
		}

	}

	// leftmost column
	else if(p->get_position().col == 0)
	{
		// enemy BELOW
		if((board_[downOne][currentCol] != Empty))
		{
			if(board_[currentRow][rightOne] == Empty)
			{
				cout << "RIGHT ";
			}
			if(board_[upOne][currentCol] == Empty)
			{
				cout << "UP ";
			}
			if(board_[downOne][currentCol] == Treasure)
			{
				cout << "DOWN ";
			}
		}
		// enemy RIGHT
		else if((board_[currentRow][rightOne] != Empty))
		{
			if(board_[downOne][currentCol] == Empty)
			{
				cout << "DOWN ";
			}
			if(board_[upOne][currentCol] == Empty)
			{
				cout << "UP ";
			}
			if(board_[currentRow][rightOne] == Treasure)
			{
				cout << "RIGHT ";
			}	
		}
		// enemy UP
		else if((board_[upOne][currentCol] != Empty))
		{
			if(board_[currentRow][rightOne] == Empty)
			{
				cout << "RIGHT "; 
			}
			if(board_[downOne][currentCol] == Empty)
			{
				cout << "DOWN ";
			}
			if(board_[currentRow][leftOne] == Empty)
			{
				cout << "LEFT ";
			}
			if(board_[upOne][currentCol] == Treasure)
			{
				cout << "UP ";
			}	
		}
		else
		{
			cout << "Up Right DOWN" << endl;
		}

	}

	// middle of the board
	else if((p->get_position().col != 0) && (p->get_position().row != 0))
	{
		// enemy BELOW
		if((board_[downOne][currentCol] != Empty))
		{
			if(board_[currentRow][leftOne] == Empty)
			{
				cout << "LEFT "; 
			}
			if(board_[currentRow][rightOne] == Empty)
			{
				cout << "RIGHT ";
			}
			if(board_[upOne][currentCol] == Empty)
			{
				cout << "UP ";
			}
			if(board_[downOne][currentCol] == Treasure)
			{
				cout << "DOWN ";
			}
		}
		// enemy RIGHT
		else if((board_[currentRow][rightOne] != Empty))
		{
			if(board_[currentRow][leftOne] == Empty)
			{
				cout << "LEFT "; 
			}
			if(board_[downOne][currentCol] == Empty)
			{
				cout << "DOWN ";
			}
			if(board_[upOne][currentCol] == Empty)
			{
				cout << "UP ";
			}
			if(board_[currentRow][rightOne] == Treasure)
			{
				cout << "RIGHT ";
			}	
		}
		// enemy LEFT
		else if((board_[currentRow][rightOne] != Empty))
		{
			if(board_[currentRow][rightOne] == Empty)
			{
				cout << "RIGHT "; 
			}
			if(board_[downOne][currentCol] == Empty)
			{
				cout << "DOWN ";
			}
			if(board_[upOne][currentCol] == Empty)
			{
				cout << "UP ";
			}
			if(board_[currentRow][leftOne] == Treasure)
			{
				cout << "LEFT ";
			}		
		}
		// enemy UP
		else if((board_[upOne][currentCol] != Empty))
		{
			if(board_[currentRow][rightOne] == Empty)
			{
				cout << "RIGHT "; 
			}
			if(board_[downOne][currentCol] == Empty)
			{
				cout << "DOWN ";
			}
			if(board_[currentRow][leftOne] == Empty)
			{
				cout << "LEFT ";
			}
			if(board_[upOne][currentCol] == Treasure)
			{
				cout << "UP ";
			}		
		}
		else
		{
			cout << "RIGHT LEFT UP DOWN" << endl;
		}
		if(board_[downOne][currentCol] == Exit)
		{
			cout << "DOWN " << endl;
		}
		if(board_[currentRow][rightOne] == Exit)
		{
			cout << "RIGHT " << endl;
		}

	}

	//cout <<"end of GetMoves():" << endl;
}

/**
    Move the given player to the desired spot on board

    @param player, position and desired motion
*/
bool Board::MovePlayer(Player *p, Position pos, std::string where)
{

	// RIGHT
	if(where == "RIGHT")
	{
		if((board_[pos.row][pos.col+1] == Empty) || (board_[pos.row][pos.col+1] == Exit) || (board_[pos.row][pos.col+1] == Treasure))
		{
			pos.col = pos.col+1;
			SetSquareValue(pos,Human);
			board_[pos.row][pos.col-1] = Empty;
			cout << "player successesfully moved" << endl;
			p->SetPosition(pos);
			return true;
		}
	}
	// LEFT
	if(where == "LEFT")
	{
		if((board_[pos.row][pos.col-1] == Empty) || (board_[pos.row][pos.col-1] == Treasure))
		{
			pos.col = pos.col-1;
			SetSquareValue(pos,Human);
			board_[pos.row][pos.col+1] = Empty;
			cout << "player successesfully moved" << endl;
			p->SetPosition(pos);
			return true;
		}
	}
	// DOWN
	if(where == "DOWN")
	{
		if((board_[pos.row+1][pos.col] == Empty) || (board_[pos.row+1][pos.col] == Exit) || (board_[pos.row+1][pos.col] == Treasure))
		{
			pos.row = pos.row+1;
			SetSquareValue(pos,Human);
			board_[pos.row-1][pos.col] = Empty;
			cout << "player successesfully moved" << endl;
			p->SetPosition(pos);
			return true;
		}
	}

	// UP
	if(where == "UP")
	{
		if((board_[pos.row-1][pos.col] == Empty) || (board_[pos.row-1][pos.col] == Treasure))
		{
			pos.row = pos.row-1;
			SetSquareValue(pos,Human);
			board_[pos.row+1][pos.col] = Empty;
			cout << "player successesfully moved" << endl;
			p->SetPosition(pos);
			return true;
		}
	}

	else
	{
		cout << "try again" << endl;
		return false;
	}
	if((pos.row == 3) && (pos.col == 3))
	{
		p->ChangePoints(1);
	}
}

/**
    Get the exit character
**/
const char* Board::GetExitOccupant()
{
	return Exit;
}

/**
    Initialize the board

    @param player and amount of bad guys
*/
void Board::NewGame(Player *human, const int enemies)
{
	newBoard(human,enemies);
}

/**
    Take the given character and fill up the board

    @param player
*/
void Board::TakeTurn(Player *pl)
{
	GetMoves(pl);
	string input;
	cin >> input;
	MovePlayer(pl,pl->get_position(),input);
}

Player * Board::GetNextPlayer()
{
	//
}

/**
    Check whether or not the game has ended and return a bool value
*/
bool Board::IsGameOver()
{
	if(board_[3][3] == Human)
	{
		
		return true;
	}
	else
	{
		return false;
	}
}