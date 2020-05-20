/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: Sep 25th, 2019
---------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include"ParkingSpot.h"
#include "ParkingLot.h"
#include"utils.h"



using namespace std;
namespace sdds {
	void setEmpty(ParkingSpot& spot) {
		spot.license[0] = '\0';
		spot.mode = nullptr;
	}

	bool isEmpty(const ParkingSpot& spot) {
		if (spot.mode == nullptr) {
			return true;
		}
		else {
			return false;
		}
		
	}
	void freeSpot(ParkingSpot& pkspot) {
		delete[] pkspot.mode;
		setEmpty(pkspot);
	}

	void print(const ParkingSpot& printspot) {
		cout << printspot.mode <<", plate number: "<< printspot.license << endl;
	}
	void parkCar(ParkingSpot& park) {

		char make[61];
		char plate[9];

		cout << "Make and Model: ";
		read(make, 60, "Too long, Make and model must be shorter than 60 characters\nRedo Entry: ");
		cout << "License Plate: ";
		read(plate, 8, "Too long, License Plate must be shorter than 8 characters\nRedo Entry: ");

		
		strcpy(park.license, plate);

		park.mode = new char[strlen(make) + 1];
		strcpy(park.mode, make);
		
	}

}
