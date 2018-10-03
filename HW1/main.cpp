/**
Author: Eric Oropezaelwood
A fun little game whiere the player must reach the exit.

**/

#include <iostream>
#include <sstream>
#include "Player.h"
#include "Maze.h"

using namespace std;

int main()
{

	// set initial player position
	Position po;
	po.row = 0;
	po.col = 0;

	string name;
	cout << "Please enter your name: " << endl;
	cin >> name;

	Player hero(name,true);

	hero.SetPosition(po);

	Board bd;
	bd.NewGame(&hero,3);

	// Run the game until it ends
	while(bd.IsGameOver() != true)
	{
		bd.printBoard();
		bd.TakeTurn(&hero);
		//bd.MovePlayer(&hero,po);
	}
	cout << "Name has " << 1 << " points" << endl;

	return 0;
}