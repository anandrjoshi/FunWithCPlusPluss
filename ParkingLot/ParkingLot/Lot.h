#include "Slot.h"
#include <vector>

class Lot
{
	std::vector <Slot> slots_in_lot;
	unsigned int number_of_slots;
	unsigned int number_of_occupied_slots;

public:
	Lot(unsigned int _number_of_slots);
	~Lot();
	bool IsLotFull();
	void GetLotDetails();
	bool ParkVehicle(unsigned int _vehicle_number);
	bool UnParkVehicle(unsigned int _vehicle_number);

private:
	void InitializeSlots();
};