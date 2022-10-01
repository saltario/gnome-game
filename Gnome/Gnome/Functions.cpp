#include "Functions.h"

void printSeparator() {

	// ����������� ����� ������� � �������
	SetConsoleTextAttribute(hConsole, blueTextColor);

	// ������� 20 ��� =
	cout.setf(ios::left);
	cout.width(separatorTextWidth); // 20
	cout.fill('=');
	cout << "=" << endl;
}

void printEmptySeparator()
{
	cout.setf(ios::left);
	cout.width(SeparatorWidth);
	cout.fill(' ');
	cout << " ";
}

void printSeparatorForBattle() {

	SetConsoleTextAttribute(hConsole, blueTextColor);

	cout.setf(ios::left);
	cout.width(separatorTextWidth);
	cout.fill('=');
	cout << "=";

	printEmptySeparator();

	SetConsoleTextAttribute(hConsole, cyanTextColor);

	cout.setf(ios::left);
	cout.width(separatorTextWidth);
	cout.fill('=');
	cout << "=" << endl;
}
