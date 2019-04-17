

// Feel like I'm really close with this, but I'm not fulling grasping the virtual function concept here...


#include "pch.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <fstream>

using namespace std;

class road_vehicle {

public:
	int wheels = NULL;
	int passengers = NULL;
	int cargo;
	char car_type[15];
	road_vehicle();
	road_vehicle(road_vehicle& theObject);
	virtual void print(ostream& os) {
		os << wheels << endl;
		os << passengers << endl;
	}
	virtual void get(istream& is) {
		cout << "How many wheels does this vehicle have?" << endl;
		is >> wheels;
		cout << "How many passengers can this vehicle hold?" << endl;
		is >> passengers;
	}
	friend istream& operator >>(istream& inStream, road_vehicle& object);
	friend ostream& operator <<(ostream& outStream, road_vehicle& object);
};
road_vehicle::road_vehicle() {

}


class truck : public road_vehicle {
private:
	
public:
	int cargo;
	truck();
	truck(truck& object);
	void print(ostream& os) {
		os << "truck";
		road_vehicle::print(os);
		os << cargo;
	}
	void get(istream& is) {

		road_vehicle::get(is);
		cout << "How much cargo (in pounds) can this vehicle hold?" << endl;
		is >> cargo;
	}

};
truck::truck() {

}


class automobile : public road_vehicle {
private:
	
public:
	char car_type[15];
	automobile();
	automobile(automobile& object);
	void print(ostream& os) {
		os << "automobile\n";
		road_vehicle::print(os);
		os << car_type;
	}
	void get(istream& is) {

		road_vehicle::get(is);
		cout << "What type of automobile is this?   Enter van, car or wagon" << endl;
		is >> car_type;
	}


};
automobile::automobile() {

}
class node
{
public:

	road_vehicle object;
	automobile a;
	truck t;
	
	node *next;
	friend ostream& operator<<(ostream& outStream, road_vehicle& object);
	node()
	{
		next = NULL;
	}
	void insert(road_vehicle &a);
	void print_data();
};
void node::print_data() {
	cout << object;

	if (next != NULL) {
		next->print_data();
	}
}
void node::insert(road_vehicle &v) {
	if (next == NULL) {
		next = new node;
		next->object = v;
	}
	else 
		next->insert(v);
}

istream& operator>>(istream& inStream, road_vehicle& object) {
	object.get(inStream);
	return inStream;
}

ostream& operator<<(ostream& outStream, road_vehicle& object) {
	object.print(outStream);
	return outStream;
}

int main() {
	
	road_vehicle v;
	truck tr;
	automobile au;
	node linkedlist;

	char input[15];
	char response[4];

	ofstream out;
	out.open("output.txt");


	do {

		cout << "Is this an automobile or a truck?" << endl;
		cin >> input;

		while (strcmp(input, "automobile") && (strcmp(input, "truck"))) {

			cout << "Input is case-sensitive. Enter 'automobile' or 'truck'";
			cin >> input;
		}


		if (!strcmp(input, "automobile")) {
			cin >> au;
			linkedlist.insert(au);
		}
		else {
			cin >> tr;
			linkedlist.insert(tr);


		}
		cout << "Would you like to enter another vehicle? yes or no " << endl;
		cin >> response;

	} while (strcmp(response, "no"));

	linkedlist.print_data();
	out.close();

	return 0;

}
