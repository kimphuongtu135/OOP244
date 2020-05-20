// Metal.cpp
/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: Nov 14th, 2019
---------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include<iomanip>
#include "Metal.h"



using namespace std;
namespace sdds
{
	Metal::Metal() {
		name = nullptr;
		mohs = 0.0;

		
	}

	Metal::Metal(double weight2,int purity2,const char* classic, const char* name1,double mohs1) :Ore(weight2, purity2, classic) {
		if (name1 == nullptr || name1[0] == '\0') {
			name = nullptr;
			mohs = 0.0;
		}
		else {
			name = new char[NAME_LEN + 1];
			strcpy(name, name1);

			if (mohs1 > 0)
				mohs = mohs1;
			else
				mohs = DEFAULT_MOHS;

			
			
		}
		
	}
	

	void Metal::refine() {
		Ore::refine();
		
			mohs += 1;
	}

	ostream& Metal::display(ostream& os) const {
		if (name == nullptr && mohs==0.0) 
			cout << "This metal is imaginary" << endl;
		
		else {
			cout << "Name: " << name << endl;
			Ore::display(os);
			cout << "Mohs: " << mohs << endl;
		}
		return os;
	}
	istream& Metal::input(istream& is) {

		//Set value for the name
		char arr[NAME_LEN + 1];
		cout << "Enter a value for this metal's name: ";
		
		is.clear();
		is.getline(arr, 11);
		if (name != nullptr)
			delete[] name;

		
			name = new char[NAME_LEN + 1];
			strcpy(name, arr);
		

		//Set value for the mohs
		double temp;
		cout << "Enter a value for this metal's mohs: ";
		is.clear();
		is >> temp;
		if (temp > 0)
			mohs = temp;
		else
			mohs = DEFAULT_MOHS;
		Ore::input(is);

		return is;
	}


	ostream& operator<<(ostream& os, const Metal& met) {
		cout << "Metal" << endl;
		met.display(os);
		return os;
	}


		istream& operator>>(istream & is, Metal & met) {
			met.input(is);
			return is;
	}


		Metal::~Metal() {
			delete[] name;
		}
}
