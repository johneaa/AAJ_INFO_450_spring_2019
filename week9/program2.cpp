#include "pch.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <sstream> 

using namespace std;

class road_vehicle 
{

public:
	int wheels = 0;
	int passengers = 0;
	string vtype;
	road_vehicle() {}
	road_vehicle(int w, int p) : wheels(w), passengers(p) {}
	virtual void print()
	{
		cout << wheels << endl;
		cout << passengers << endl;
	}
	virtual void get()
	{
		cout << "How many wheels does this vehicle have?" << endl;
		cin >> wheels;
		cout << "How many passengers can this vehicle hold?" << endl;
		cin >> passengers;
	}

};

class truck : public road_vehicle
{

public:
	const string vtype = "truck";
	int cargo = 0;
	truck() {}
	truck(string const v, int w, int p, int c) : vtype(v), road_vehicle(w, p), cargo(c) {}
	void print()
	{
		cout << "{\"road_vehicle\": \"" << vtype << "\"";
		cout << ", \"wheels\": " << wheels;
		cout << ", \"passengers\": " << passengers;
		cout << ", \"cargo\": " << cargo << "}" << endl;
	}

};

class automobile : public road_vehicle
{

public:
	const string vtype = "automobile";
	string car_type;
	automobile(string const v, int w, int p, string c) : vtype(v), road_vehicle(w, p), car_type(c) {}
	automobile() {}
	void print() 
	{
		cout << "{\"road_vehicle\": \"" << vtype << "\"";
		cout << ", \"wheels\": " << wheels;
		cout << ", \"passengers\": " << passengers;
		cout << ", \"type\": " << car_type << "}" << endl;
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


int main()
{
	truck tr;
	automobile au;
	list l;
	string input;
	string line;
	int aw = 0;
	int ap = 0;
	int tw = 0;
	int tp = 0;
	int tc = 0;

	ifstream in;
	ifstream myfile("output.txt", ios::beg);
	
	while (!myfile.eof())
	{
		getline(myfile, input);

		if (input == "automobile")
		{
			string cartype;
			automobile *vauto = new automobile;

			getline(myfile, line);
			stringstream convert(line);
			convert >> aw;
			vauto->wheels = aw;
			
			getline(myfile, line);
			stringstream convert1(line);
			convert1 >> ap;
			vauto->passengers = ap;
			
			getline(myfile, line);
			cartype = line;
			vauto->car_type = cartype;
			
			l.createnode(vauto);
		}
		else if (input == "truck")
		{
			truck *vtruck = new truck;
			
			getline(myfile, line);
			stringstream convert2(line);
			convert2 >> tw;
			vtruck->wheels = tw;
			
			getline(myfile, line);
			stringstream convert3(line);
			convert3 >> tp;
			vtruck->passengers = tp;
			
			getline(myfile, line);
			stringstream convert4(line);
			convert4 >> tc;
			vtruck->cargo = tc;

			l.createnode(vtruck);
		}
	}
	l.display();
	myfile.close();
	



	return 0;
}
