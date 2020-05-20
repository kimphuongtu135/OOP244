// Pencil.cpp
/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: Nov 14th, 2019
---------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include<iomanip>
#include "Pencil.h"



using namespace std;
namespace sdds
{
	Pencil::Pencil() {
		scale[0] = '\0';
		graphite = 0;
	}
	Pencil::Pencil(const char* scale1, int graphite1) {
		if (scale1 == nullptr || scale1[0] == '\0') {
			scale[0] = '\0';
			graphite = 0;
		}
		else {
			graphite = graphite1;
			strncpy(scale, scale1, HB_MAX+1);
			if (graphite1 < 1 || graphite1 >100)
				graphite = GRAPHITE_MAX;
		}
	}
	void Pencil::write(const char* text) {
		if (graphite == 0)
			cout << "We can't write without graphite!" << endl;
		else {
			cout << "Writing out the following: " << text << " with a Pencil!" << endl;
			int count = 0;
			int length = strlen(text);

			for (int i = 0; i < length; i++) {
				if (text[i] == ' ')
					++count;
			}

			graphite -= count * 5;
			if (graphite < 0)
				graphite = 0;
		}

	}

	void Pencil::refill(int number) {
		graphite += number;
		if (graphite > GRAPHITE_MAX)
			graphite = GRAPHITE_MAX;
		cout << "Refilling the pencil with graphite" << endl;
	}

	bool Pencil::filled() const {
		if (graphite == 0)
			return false;
		else
			return true;
	}
	ostream& Pencil::display(ostream & os) const {
		if (graphite == 0 && scale[0] == '\0')
			cout << "This is an empty Pencil" << endl;
		else {
			cout << "Pencil Details" << endl;
			cout << "HB Value: " << scale << endl;
			cout << "Graphite Remaining: " << graphite << endl;

		}
		return os;
	}
}