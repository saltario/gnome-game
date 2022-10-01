#include "Player.h"

Player::Player(string Name)
{
	this->Name = Name;
	this->Level = 0;
	this->Stars = 0;
}

Player::~Player()
{
}

int Player::getLevel()
{
	return Level;
}

void Player::setLevel(int Level)
{
	if (Level != 0) this->Level = Level;
	else cout << "Level is NULL";
}

int Player::getStars()
{
	return Stars;
}

void Player::setStars(int Stars)
{
	if (Stars != 0) this->Stars = Stars;
	else cout << "Stars is NULL";
}

string Player::getName()
{
	return Name;
}

void Player::setName(string Name)
{
	this->Name = Name;
}

void Player::printPlayer()
{
	cout << "Player: " << getName() << endl;
}
