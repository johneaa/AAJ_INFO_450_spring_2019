
#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	char names[30][50];
	int i = 0;
	int t = 0;

	for (int i = 0; i < 30; i++) {
		
		cout << "Enter Name: " << endl;
		cin.getline(names[i], 30);

	}

	for (int i = 0; i < 30; i++) {

		for (int t = 0; t < 50; t++) {
			
			if (names[i][t] != '\0')

				cout << names[i][t] << endl;

			else if (names[i][t] == ' ') {
				
				cout << "\n";
				break;

			}

			else {
				
				cout << "\n";
				break;

			}
		}
	}
}