

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int gallons;
	int liters;

	cout << "Enter number of gallons: ";
	cin >> gallons;

	liters = gallons * 4;

	cout << gallons, " gallons is equal to ", liters, " liters";

	return 0;
}
