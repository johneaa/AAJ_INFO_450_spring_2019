
#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int num;
	int i;
	int count = 0;

	cout << "\nThis program checks if a number is prime, or not (enter 0 to exit)" << endl;
	cout << "Enter a number: " << endl;
	cin >> num;

	if (num == 0)
	{
		cout << "Program will now terminate" << endl;
		return 0;
	}
	else if (num == 1)
	{
		cout << num << " is not a prime number" << endl;
		return main();
	}
	else
	{
		for (i = 2; i < num; i++)

			if (num % i == 0)
			{
				count++;
			}
	}
	if (count > 1)
	{
		cout << num << " is not a prime number" << endl;
		return main();
	}
	else
	{
		cout << num << " is prime" << endl;
		return main();
	}
		
		
}
	
	



