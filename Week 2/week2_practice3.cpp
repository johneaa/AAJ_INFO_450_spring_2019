

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int year;

	cout << "\nThis program determines if a year is a leap year" << endl;
	cout << "Enter a year:" << endl;
	cin >> year;

	if (year % 4 == 0)
	{
		cout << "\n" << year << " is a leap year!" << endl;
		return main();
	}
	else if (year % 100 != 0 && year % 400 == 0)
	{
		cout << "\n" << year << " is a leap year!" << endl;
		return main();
	}
	else if (year == 2000 || year == 2400)
	{
		cout << "\n" << year << " is a leap year!" << endl;
		return main();
	}
	else if (year == 1800 || year == 1900)
	{
		cout << "\n" << year << " is not a leap year." << endl;
		return main();
	}
	else
		cout << "\n" << year << " is not a leap year." << endl;
		return main();
}

