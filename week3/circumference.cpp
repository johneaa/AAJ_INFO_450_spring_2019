
#include "pch.h"
#include <iostream>
using namespace std;

const double PI = 3.14;

double calculateCircumference(double radius);

int main() {
	double userinput = 0;
	double functionout = 0;
	char response;

	do {

		cout << "Enter radius: ";
		cin >> userinput;

		functionout = calculateCircumference(userinput);

		cout << "The circumference of the circle is: " << functionout << endl;
		cout << "Enter another radius? Y or N" << endl;
		cin >> response;

	} while ((response == 'Y') || (response == 'y'));

	return 0;
}

double calculateCircumference(double radius) {

	double circ = (2 * PI * radius);

	return circ;

}