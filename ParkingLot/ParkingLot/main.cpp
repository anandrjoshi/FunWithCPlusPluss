#include "Lot.h"
#include <iostream>

using namespace std;

int main()
{
	Lot parking_lot = Lot(6);
	parking_lot.UnParkVehicle(111);
	parking_lot.ParkVehicle(111);
	parking_lot.ParkVehicle(222);
	parking_lot.ParkVehicle(333);
	parking_lot.ParkVehicle(444);
	parking_lot.ParkVehicle(555);
	parking_lot.ParkVehicle(666);
	parking_lot.UnParkVehicle(111);
	parking_lot.ParkVehicle(777);
	cout << "============================" << endl;
	parking_lot.GetLotDetails();
	system("pause");
	return 0;
}