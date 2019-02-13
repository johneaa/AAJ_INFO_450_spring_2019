

#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int userset[10];
	int i = 0;
	int sum = 0;
	double mean = 0;
	int stddevsum = 0;
	double stddevsummean = 0;
	double stddev = 0;
	
	cout << "This program will ask you for a set of 10 whole numbers" << endl;
	
	for (i = 0; i < 10; i++) {
		
		cout << i + 1  << ". Enter number: ";
		cin >> userset[i];
		sum += userset[i];

	}
	
	mean = sum / 10;

	cout << "The mean for this set of data is: " << mean << endl;

	for (i = 0; i < 10; i++) {

		stddevsum += pow((userset[i] - mean), 2);

	}

	stddevsummean = stddevsum / 10;
	stddev = sqrt(stddevsummean);

	cout << "The standard deviation for this set of data is: " << stddev << endl;

return 0;
}
