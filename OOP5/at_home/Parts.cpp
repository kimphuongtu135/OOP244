// Parts.cpp
// Parts.cpp
/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: OCT 12th, 2019
---------------------------*/
#include <iostream>
#include "Parts.h"

using namespace std;
namespace sdds {
	Arms::Arms() {
		force = 0;
	}

	Arms::Arms(int num) {
		if (num < 1)
			force = MIN_FORCE;
		else
			force = num;
	}
	int Arms::getForce()const {
		return force;
	}

	Arms& Arms::operator++() {

		force += 10;
		return *this;
	}
	Arms Arms::operator++(int n) {
		Arms temp = *this;
		force += 10;
		return temp;
	}
	Arms& Arms::operator+=(int num) {

		force += num;
		if (force < 1)
			force = 0;
		return *this;
	}

	Legs::Legs() {
		speed = 0;
	}

	Legs::Legs(int num) {
		if (num < 1)
			speed = MIN_SPEED;
		else
			speed = num;
	}
	int Legs::getSpeed() const {
		return speed;
	}
	Legs& Legs::operator-=(int num) {
		speed -= num;
		if (speed < 1)
			speed = 0;
		return *this;
	}
	bool operator>(const Legs& legs1, const Legs& legs2) {
		if (legs1.getSpeed() > legs2.getSpeed())
			return true;
		else
			return false;
	}

	bool operator<(const Legs& legs3, const Legs& legs4) {
		if(operator>(legs3, legs4) == true)
			return false;
		else 
			return true;
		
		
	}
	bool operator>(const Arms& arms1, const Arms& arms2) {
		if (arms1.getForce() > arms2.getForce())
			return true;
		else
			return false;
	}

	bool operator<(const Arms& arms1, const Arms& arms2) {
		if (operator >(arms1, arms2) == true)
			return false;
		else
			return true;
	}

}
