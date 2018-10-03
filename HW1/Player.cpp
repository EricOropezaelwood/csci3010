#include "Player.h"
#include <string>
using namespace std;

// Constructor
Player::Player(const std::string name, const bool is_human)
{
	name_ = name;
	is_human_= is_human;

}

void Player::ChangePoints(const int x)
{
	points_ += x;
}

void Player::SetPosition(Position pos)
{
	pos_.row = pos.row;
	pos_.col = pos.col;
}