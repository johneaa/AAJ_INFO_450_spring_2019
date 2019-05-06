// I did a thing!!

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

class road_vehicle {

public:
	int wheels = 0;
	int passengers = 0;
	int cargo;
	char car_type[15];
	road_vehicle() {}
	road_vehicle(int w, int p) : wheels(w), passengers(p) {}
	virtual void print() {
		cout << wheels << endl;
		cout << passengers << endl;
	}
	virtual void get() {
		cout << "How many wheels does this vehicle have?" << endl;
		cin >> wheels;
		cout << "How many passengers can this vehicle hold?" << endl;
		cin >> passengers;
	}

};

class truck : public road_vehicle {
private:

public:
	const string vtype = "truck\n";
	int cargo;
	truck() {}
	truck(string const v, int w, int p, int c) : vtype(v), road_vehicle(w, p), cargo(c) {}
	void print() {
		ofstream out;
		out.open("output.txt", ios::app);
		out << vtype;
		out << wheels << endl;
		out << passengers << endl;
		out << cargo << endl;
		return;
	}
	void get() {

		road_vehicle::get();
		cout << "How much cargo (in pounds) can this vehicle hold?" << endl;
		cin >> cargo;
	}

};

class automobile : public road_vehicle {
private:

public:
	const string vtype = "automobile\n";
	string car_type;
	automobile(string const v, int w, int p, string c) : vtype(v), road_vehicle(w, p), car_type(c) {}
	automobile() {}
	void print() {
		ofstream out;
		out.open("output.txt", ios::app);
		out << vtype;
		out << wheels << endl;
		out << passengers << endl;
		out << car_type << endl;
	}
	void get() {

		road_vehicle::get();
		cout << "What type of automobile is this?   Enter van, car or wagon" << endl;
		cin >> car_type;
	}

};

struct node
{
	road_vehicle *data;
	node *next;
};

class list
{
public:
	node *head, *tail;

	list()
	{
		head = NULL;
		tail = NULL;
	}

	void createnode(road_vehicle *v);
	void display();
};

void list::createnode(road_vehicle *v)
{
	node *temp = new node;
	temp->data = v;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}

void list::display()
{
	node *temp = new node;
	temp = head;
	while (temp != NULL)
	{
		temp->data->print();
		temp = temp->next;
	}

}

int main() {

	truck tr;
	automobile au;
	list l;

	char input[15];
	char response[4];

	do {

		cout << "Is this an automobile or a truck?" << endl;
		cin >> input;

		while (strcmp(input, "automobile") && (strcmp(input, "truck"))) {

			cout << "Input is case-sensitive. Enter 'automobile' or 'truck'";
			cin >> input;
		}


		if (!strcmp(input, "automobile")) {
			automobile *vauto = new automobile;
			vauto->get();
			l.createnode(vauto);
		}
		else {
			truck *vtruck = new truck;
			vtruck->get();
			l.createnode(vtruck);
		}
		cout << "Would you like to enter another vehicle? yes or no " << endl;
		cin >> response;

	} while (strcmp(response, "no"));
	
	l.display();

	ofstream out;
	out.close();

	cout << "\nYour vehicles have been saved in the file, 'output.txt'" << endl;



	return 0;

}
