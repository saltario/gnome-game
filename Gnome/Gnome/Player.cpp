#include "Player.h"

Player::Player()
{
	this->Name = "Player";
	this->Level = 0;
	this->Stars = 0;
}
Player::~Player() {}

int Player::getLevel() {return Level; }
void Player::setLevel(int Level) { this->Level = Level; }

int Player::getStars() { return Stars; }
void Player::setStars(int Stars) { this->Stars = Stars; }

string Player::getName() { return Name; }
void Player::setName(string Name) { this->Name = Name; }

Hero Player::getPlayerHero() { return hero; }

void Player::setPlayerHero(int heroId) { this->hero = Hero(heroId); }
void Player::setPlayerHero(Hero hero) { this->hero = hero; }

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
