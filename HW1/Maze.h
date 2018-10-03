#ifndef _MAZE_H_
#define _MAZE_H_

#include <vector>
#include <sstream>
#include "Player.h"

// you may change this enum as you need
// enum class SquareType { Wall, Exit, Empty, Human, Enemy, Treasure };

// TODO: implement
// std::string SquareTypeStringify(SquareType sq);

class Board {
public:
	// TODO: implement
	Board();
	void newBoard(Player *hero, const int badGuys);
	
	// already implemented in line
	int get_rows() const {return 4; }  // you should be able to change the size of your 
	int get_cols() const {return 4; }  // board by changing these numbers and the numbers in the arr_ field

	void printBoard();
//	// TODO: you MUST implement the following functions
	const char* get_square_value(Position pos); 
//
//	// set the value of a square to the given SquareType
	void SetSquareValue(Position pos, const char* value);
//
//	// get the possible Positions that a Player could move to
//	// (not off the board or into a wall)
	void GetMoves(Player *p);
//
//	// Move a player to a new position on the board. Return
//	// true if they moved successfully, false otherwise.
	bool MovePlayer(Player *p, Position pos, std::string where);
//
//	// Get the square type of the exit square
	const char* GetExitOccupant();

//	// initialize a new game, given one human player and 
//	// a number of enemies to generate
	void NewGame(Player *human, const int enemies);

//	// have the given Player take their turn
	void TakeTurn(Player *pl);

//	// Get the next player in turn order
	Player * GetNextPlayer();

//	// or the enemies ate all the humans
	bool IsGameOver();

//	// You probably want to implement this
//	friend std::ostream& operator<<(std::ostream& os, const Board &b);


private:
	//SquareType arr_[4][4];
	
	int rows_; // might be convenient but not necessary
	int cols_;
	
	// you may add more fields, as needed
	const char* board_[4][4];
	const char* Human = u8"\xF0\x9F\x98\xBC";
	const char* Exit = u8"\xF0\x9F\x9A\xAA";
	const char* Wall = u8"\xF0\x9F\x9A\xA7";
	const char* Empty = u8"\xE2\xAC\x9C";
	const char* Treasure = u8"\xF0\x9F\x8D\x89";
	const char* Enemy = u8"\xF0\x9F\x90\x99";

};  // class Board
/**
class Maze {
public:
//	// TODO: implement these functions
	Maze(); // constructor
//
//	// initialize a new game, given one human player and 
//	// a number of enemies to generate
	void NewGame(Player *human, const int enemies);
//
//	// have the given Player take their turn
//	void TakeTurn(Player *p);
//
//	// Get the next player in turn order
//	Player * GetNextPlayer();
//
//	// return true iff the human made it to the exit 
//	// or the enemies ate all the humans
//	bool IsGameOver();
//
//	// You probably want to implement these functions as well
//	// string info about the game's conditions after it is over
//	std::string GenerateReport();
//	friend std::ostream& operator<<(std::ostream& os, const Maze &m);
//
private:
	Board *board_h; 
	//std::vector<Player *> players_;
//	int turn_count_;
//
//	// you may add more fields, as needed
//
};  // class Maze
**/


#endif  // _MAZE_H_
