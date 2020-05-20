/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: Sep 25th, 2019
---------------------------*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include"ParkingSpot.h"
#include "ParkingLot.h"
#include"utils.h"

using namespace std;
namespace sdds {
	void setEmpty(ParkingLot& park ) {

		park.noOfParkingSpots = 0;
		park.ParkingSpots = nullptr;
	}	

	bool isEmpty(const ParkingLot& empty) {

		if (empty.ParkingSpots == nullptr) {
			return true;
	}
		else {
			return false;
		}
	}
	void openParking(ParkingLot& park, int noOfSpots) {

		park.noOfParkingSpots = noOfSpots;
		park.ParkingSpots = new ParkingSpot[noOfSpots]; // dymanical allocation the value of parkingSpots from structure to array
		for (int i = 0; i < noOfSpots; i++) {
			setEmpty(park.ParkingSpots[i]);	// calling the setEmpty function for set the spot to be empty
		}
	}

		int parkCar(ParkingLot & lot) {
			

			for (int i = 0; i < lot.noOfParkingSpots; i++) {
				if (isEmpty(lot.ParkingSpots[i])) {
					parkCar(lot.ParkingSpots[i]);
					return i;
				}
			}
			return -1;
		}

			bool returnCar(ParkingLot& lot, int spotNo) {
				if (spotNo >=0 && !isEmpty(lot.ParkingSpots[spotNo]) && spotNo < lot.noOfParkingSpots) {
					
					cout << "Returning ";
					print(lot.ParkingSpots[spotNo]);
					freeSpot(lot.ParkingSpots[spotNo]);
						return true;
					}
					else 
						return false;
					
			}
	
			void closeParking(ParkingLot& close) {
				for (int i = 0; i < close.noOfParkingSpots; i++) {
					if (!isEmpty(close.ParkingSpots[i])) {
						returnCar(close, i);
					}
				}
				delete[] close.ParkingSpots;
				setEmpty(close);
	}
}