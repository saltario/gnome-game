#include "Player.h"

Player::Player()
{
	this->Name = "Player";
	this->Level = 0;
	this->Stars = 0;
}

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
	string str1 = "| Игрок: ";
	string str2 = " |";

	printSeparator();

	SetConsoleTextAttribute(hConsole, yellowTextColor);
	cout.fill(' ');

	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << getName();

	cout.width(str2.length());
	cout << str2 << endl;
}
