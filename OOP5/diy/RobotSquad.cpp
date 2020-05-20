// RobotSquad.cpp
/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: OCT 12th, 2019
---------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Robot.h"
#include "RobotSquad.h"
#include "Parts.h"

using namespace std;
namespace sdds {

	RobotSquad::RobotSquad() {
		//Default "No Name" value for name
		strcpy(name, "No Name");
		roster = nullptr;
		count = 0;
	}

	RobotSquad::RobotSquad(const char* name1) {
			strcpy(name, name1);
			
			roster = nullptr;
			count = 0;
		
	}

	RobotSquad& RobotSquad::operator+=(Robot robot) {
		//Create a new variable with Robot for copying
		Robot* temp;
		//Set value for new variale 
		temp = roster;
		//Dynamically allocate memory for roster to new type Robot
		roster = new Robot[count+1];

		roster[count] = robot;
		
		for (int i = 0; i < count; i++) {
			roster[i] = temp[i];
		}

		// Delete dynamic allocation of temp
		delete[] temp;
		
		count++;

		return *this;
	}
	RobotSquad& RobotSquad::operator--() {
		
		if (count == 1) {
			//Makse sure roster has empty value
			delete[] roster;
			roster = nullptr;
			count = 0;
			strcpy(name, "No Name");
			return *this;
		}
		if (count == 0) {
			cout << "This squad **" << name << "** has no members or is uninitialized. Can't do --." << endl;
			return *this;
		}
		//Create new variable for doing copy
		Robot* temp;
		temp = roster;
		//Dynamically allocate memory for roster to new type Robot
		roster = new Robot[count - 1];

		for (int i = 0; i < count-1; i++) {
			roster[i] = temp[i];
		}

		// Delete dynamic allocation of temp
		delete[] temp;

		count--;

		return *this;

	}

	Robot* RobotSquad::getRoster() const {
		return roster;
	}

	ostream& RobotSquad::display()const {
		if (count == 0) {
			cout << "Squad **" << name << "** has no members" << endl;
			return cout;
		}
		else {
			cout << "***Squad Summary***" << endl;
			cout <<"Name: "<< name << endl;
			cout <<"Roster Count: "<< count << endl;
			cout << "Roster:" << endl;
			for (int i = 0; i < count; i++) {
				roster[i].display();
			}
		}
		return cout;
	}
	// Deconstruction for making sure no leaking memory
	RobotSquad::~RobotSquad() {
		if(roster != nullptr)
		delete[] roster;
	}
}