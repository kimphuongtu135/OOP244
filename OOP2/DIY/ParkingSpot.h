
#ifndef SDDS_PARKINGSPOT_H__
#define SDDS_PARKINGSPOT_H__

namespace sdds {
	struct ParkingSpot {
		char license [9];
		char* mode;
};
	void setEmpty(ParkingSpot&);
	bool isEmpty(const ParkingSpot&);
	void freeSpot(ParkingSpot&);
	void print(const ParkingSpot&);
	void parkCar(ParkingSpot&);

}
#endif // !