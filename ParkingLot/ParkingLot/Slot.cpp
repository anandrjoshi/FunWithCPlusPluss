#include "Slot.h"
#include <iostream>

using namespace std;

Slot::Slot(unsigned int _slot_number)
{
	slot_number = _slot_number;
	is_vacant = true;
	vehicle_number = 0;
}

bool Slot::FillSlot(unsigned int _vehicle_number)
{
	vehicle_number = _vehicle_number;
	is_vacant = false;
	return true;
}

bool Slot::VacateSlot()
{
	vehicle_number = 0;
	is_vacant = true;
	return true;
}

void Slot::GetSlotDetails()
{
	cout << "Slot Number: " << slot_number << endl;
	cout << "Is Vacant: " << is_vacant<< endl;
	if(!is_vacant)
		cout << "Vehicle at this slot: " << vehicle_number << endl;
}