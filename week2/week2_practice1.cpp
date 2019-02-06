
#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int posvalue;
	int squarednumber;
	
	cout << "Enter a positive integer\n";
	cin >> posvalue;
	
	while (posvalue < 0)
	{
		cout << "You did not enter a positive integer, please enter a positive integer" << endl;
		cin >> posvalue;
	}

	while (posvalue > 0)
	{
		cout << "Your number squared is: " << pow(posvalue, 2) << endl;
		cout << "Please enter a positive integer" << endl;
		cin >> posvalue;

		if (posvalue < 0)
		{
			cout << "You did not enter a positive integer, please enter a positive integer" << endl;
			cin >> posvalue;
		}
		continue;
	}
	
	if (posvalue == 0)
	{
		cout << "The program will now terminate" << endl;
		return 0;
	}

}

