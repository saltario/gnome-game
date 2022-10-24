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

int Player::getHeroId() { return heroId; }
void Player::setHeroId(int heroId) { this->heroId = heroId; }

int Player::getStars() { return Stars; }
void Player::setStars(int Stars) { this->Stars = Stars; }

string Player::getName() { return Name; }
void Player::setName(string Name) { this->Name = Name; }

Hero Player::getPlayerHero() { return hero; }

void Player::setPlayerHero(int heroId) { this->hero = Hero(heroId); this->heroId = heroId; }
void Player::setPlayerHero(Hero hero) { this->hero = hero; }

void Player::printPlayer()
{
	string str1 = "| �����: ";
	string str2 = " |";

	printSeparator();

	setConsoleColor(yellowTextColor);
	cout.fill(' ');

	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << getName();

	cout.width(str2.length());
	cout << str2 << endl;
}

void Player::printProfile()
{
	string str1;
	string str2 = " |";

	printSeparator();

	setConsoleColor(yellowTextColor);
	cout.fill(' ');

	////////////////////////////////

	str1 = "| �����: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << getName();

	cout.width(str2.length());
	cout << str2 << endl;

	////////////////////////////////

	str1 = "| �������: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << getLevel();

	cout.width(str2.length());
	cout << str2 << endl;

	////////////////////////////////

	str1 = "| ������: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << getStars();

	cout.width(str2.length());
	cout << str2 << endl;

	printSeparator();

	////////////////////////////////

}

void Player::savePlayer()
{
	ofstream fin;
	string path = "../Resources/data.txt";

	fin.open(path, ios::out);
	fin << this->Name << endl;
	fin << this->Level << endl;
	fin << this->Stars << endl;
	fin << this->heroId;
	fin.close();
}

void Player::loadPlayer()
{
	ifstream file("../Resources/data.txt");

	while (file >> this->Name >> this->Level >> this->Stars >> this->heroId);
}

void Player::setEnemy()
{
	srand(time(0));
	int nameId = 1 + rand() % 6;

	switch (nameId)
	{
	case 1:
		this->Name = "������";
		this->Level = 10;
		this->Stars = 120;
		break;

	case 2:
		this->Name = "�������";
		this->Level = 15;
		this->Stars = 10;
		break;

	case 3:
		this->Name = "�����";
		this->Level = 2;
		this->Stars = 10;
		break;

	case 4:
		this->Name = "�������";
		this->Level = 7;
		this->Stars = 150;
		break;

	case 5:
		this->Name = "�������";
		this->Level = 80;
		this->Stars = 1000;
		break;

	case 6:
		this->Name = "���������";
		this->Level = 1;
		this->Stars = 10;
		break;

	default:
		this->Name = "�����������";
		this->Level = 10;
		this->Stars = 120;
		break;
	}
}
