// Ore.cpp
/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: Nov 14th, 2019
---------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include<iomanip>
#include "Ore.h"



using namespace std;
namespace sdds
{
	Ore::Ore() {
		weight = 0.0;
		purity = 0;
		classification[0] = '\0';
	}

	Ore::Ore(double weight1, int purity1, const char* classi) {

		//Set the value for the weight
		if (weight1 < 1)
			weight = DEFAULT_WEIGHT;
		else
			weight = weight1;


		//Set the value for the purity
		if (purity1 < 1 || purity1 >100)
			purity = DEFAULT_PURITY;
		else
			purity = purity1;


		//Set the value for the classification
		strncpy(classification, classi, CLASS_LEN);
	}

	bool Ore::refine() {
		bool value = false;

		if (purity == 100) {
			cout << "Can no longer be refined" << endl;
			return true;
		}

		weight -= 20;
		purity += 10;

		if (purity > 100) {
			purity = 100;
			value = true;
		}
		return value;

	}

	ostream& Ore::display(ostream & os)const {
		if (weight == 0.0 && purity == 0 && classification[0] == '\0')
			os << "This ore is imaginary" << endl;
		else {
			os << "Weight: " << fixed << setprecision(2) << weight << endl;
			os << "Purity: " << purity << endl;
			os << "Classification: " << classification << endl;

		}
		return os;
	}

	istream& Ore::input(istream & is) {
		double temp;
		cout << "Enter a value for this ore's weight: ";
		is >> temp;
		weight = temp;

		int temp1;
		cout << "Enter a value for this ore's purity: ";
		is >> temp1;
		purity = temp1;

		char temp2[31];
		cout << "Enter a classification for the ore (MAX 30 chars): ";
		is.ignore();
		is.getline(temp2, 31);


		*this = Ore(temp, temp1, temp2);

		return is;
	}
	ostream& operator<<(ostream & os, const Ore & ore) {
		cout << "Ore" << endl;
		ore.display(os);
		return os;
	}
	istream& operator>>(istream & is, Ore & ore) {
		ore.input(is);
		return is;
	}


}
