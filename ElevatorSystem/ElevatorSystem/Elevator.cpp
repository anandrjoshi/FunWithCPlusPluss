#include "Elevator.h"
#include <Windows.h>
#include <iostream>

using namespace std;

Elevator::Elevator(int _number_of_floors)
{
	number_of_floors = _number_of_floors;
	at_floor = 1;

	InitializeFloors();
}

void Elevator::InitializeFloors()
{
	for(int i = 0; i< number_of_floors; i++)
	{
		Floor floor = Floor(i+1);
		floors.push_back(floor);
	}
}

void Elevator::MoveUp(int _floor_number)
{
	while(at_floor != _floor_number)
	{
		cout <<" going up to " << at_floor+1 << endl;
		at_floor++;
		Sleep(1000);
	}
	cout <<"Elevator at "<< _floor_number << endl;
}

void Elevator::MoveDown(int _floor_number)
{
	while(at_floor != _floor_number)
	{
		cout <<" going down to " << at_floor-1 << endl;
		at_floor--;
		Sleep(1000);
	}
	cout <<"Elevator at "<< _floor_number << endl;
}

void Elevator::CallToFloor(Floor _floor)
{
	int floor_number = _floor.GetFloorNumber();
	if(floor_number == at_floor)
		cout << "Elevator at " << floor_number << endl;

	else if(floor_number > at_floor)
		MoveUp(floor_number);

	else
		MoveDown(floor_number);
}