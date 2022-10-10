#include "Player.h"

Player::Player()
{
	this->name = "Player";
	this->level = 0;
	this->stars = 0;
	this->hero = Hero();
}
Player::~Player(){}

int Player::getLevel() { return level; }
void Player::setLevel(int Level) { this->level = Level; }

int Player::getStars() { return stars; }
void Player::setStars(int Stars) { this->stars = Stars; }

string Player::getName() { return name; }
void Player::setName(string Name) { this->name = Name; }

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
