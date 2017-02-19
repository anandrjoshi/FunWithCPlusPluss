#include "Elevator.h"
#include <iostream>

using namespace std;

int main()
{
	Elevator elevator = Elevator(5);
	elevator.CallToFloor(elevator.floors.at(3));
	elevator.CallToFloor(elevator.floors.at(3));
	elevator.CallToFloor(elevator.floors.at(4));
	elevator.CallToFloor(elevator.floors.at(0));
	elevator.CallToFloor(elevator.floors.at(2));
	elevator.CallToFloor(elevator.floors.at(1));
	system("pause");
	return 0;
}