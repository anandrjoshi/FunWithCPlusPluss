#include "Floor.h"
#include <vector>

class Elevator
{
public:
	std::vector <Floor> floors;
private:
	int number_of_floors;
	int at_floor;

public:
	Elevator(int _number_of_floors);
	void CallToFloor(Floor _floor);
private:
	void MoveUp(int _floor_number);
	void MoveDown(int _floor_number);
	void InitializeFloors();
	 
};