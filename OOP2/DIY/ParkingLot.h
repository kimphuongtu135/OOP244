#ifndef SDDS_PARKINGLOT_H__
#define SDDS_PARKINGLOT_H__
#include"ParkingSpot.h"
namespace sdds {
	struct ParkingLot {
		int noOfParkingSpots;
		struct ParkingSpot* ParkingSpots;
	};
	void setEmpty(ParkingLot&);
	bool isEmpty(const ParkingLot&);
	void openParking(ParkingLot&, int );
	int parkCar(ParkingLot&);
	bool returnCar(ParkingLot&, int );
	void closeParking(ParkingLot&);
}

#endif // !