
class Slot
{
	unsigned int slot_number;
	bool is_vacant;
	unsigned int vehicle_number;

public:
	Slot(unsigned int _slot_number);
	bool IsVacant(){return is_vacant;};
	unsigned int GetVehicleNumber(){return vehicle_number;};
	bool FillSlot(unsigned int _vehicle_number);
	bool VacateSlot();
	void GetSlotDetails();
};