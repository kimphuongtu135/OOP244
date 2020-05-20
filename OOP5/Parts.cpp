// Parts.cpp
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

	Arms& Arms::operator++(){
		
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
}
