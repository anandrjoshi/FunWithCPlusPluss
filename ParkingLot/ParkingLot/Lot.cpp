#include "Lot.h"
#include <iostream>

using namespace std;

Lot::Lot(unsigned int _number_of_slots)
{
	number_of_slots = _number_of_slots;
	number_of_occupied_slots = 0;

	InitializeSlots();
}

void Lot::InitializeSlots()
{
	for(int i = 0; i < number_of_slots; i++)
	{
		Slot slot = Slot(i+1);
		slots_in_lot.push_back(slot);
	}
}

Lot::~Lot()
{
	for(int i = 0; i < number_of_slots; i++)
		slots_in_lot.pop_back();
}

void Lot::GetLotDetails()
{
	for(int i = 0; i < number_of_slots; i++)
		slots_in_lot.at(i).GetSlotDetails();
}

bool Lot::ParkVehicle(unsigned int _vehicle_number)
{
	if(IsLotFull())
	{
		cout <<"Vehicle cannot be parked as Lot is full." << endl;
		return false;
	}
	for(int i = 0; i < number_of_slots; i ++)
	{
		if(slots_in_lot.at(i).IsVacant())
		{
			slots_in_lot.at(i).FillSlot(_vehicle_number);
			number_of_occupied_slots++;
			return true;
		}
	}
}

bool Lot::IsLotFull()
{
	return (number_of_slots==number_of_occupied_slots);
}


bool Lot::UnParkVehicle(unsigned int _vehicle_number)
{
	if(number_of_occupied_slots == 0)
	{
		cout <<"Lot is Empty." << endl;
		return false;
	}
	for(int i = 0; i < number_of_slots; i ++)
	{
		if(!slots_in_lot.at(i).IsVacant() && slots_in_lot.at(i).GetVehicleNumber() == _vehicle_number)
		{
			cout << "Vehicle number: " << slots_in_lot.at(i).GetVehicleNumber() << " has left the lot. " << endl;
			slots_in_lot.at(i).VacateSlot();
			number_of_occupied_slots--;
			return true;
		}
	}
	cout <<"Vehicle number: " << _vehicle_number << " not in parking lot." << endl;
	return false;
}