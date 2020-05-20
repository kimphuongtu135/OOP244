// Pen.cpp
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
#include "Pen.h"



using namespace std;
namespace sdds
{
	Pen::Pen() {
		style = nullptr;
		ink = 0;
	}
	Pen::Pen(const char* style1, int ink1) {
		if (style1 == nullptr || style1[0] == '\0') {
			style = nullptr;
			ink = 0;
		}
		else {
			ink = ink1;
			style = new char[strlen(style1) + 1];
			strncpy(style, style1, strlen(style1) + 1);
			if (ink1 < 1 || ink1 >50)
				ink = INK_MAX;
		}
	}
	Pen::~Pen() {
		delete[] style;
	}

	void Pen::write(const char* text) {
		if (ink == 0)
			cout << "We can't write without ink!" << endl;
		else {
			cout << "Writing out the following: " << text << " with a Pen!" << endl;
			int count = 0;
			int length = strlen(text);

			for (int i = 0; i < length; i++) {
				if (text[i] != ' ')
					count++;
			}

			ink -= count * 2;
			if (ink < 0)
				ink = 0;
		}

	}

	void Pen::refill(int number) {
		ink += number;
		if (ink > INK_MAX)
			ink = INK_MAX;
		cout << "Refilling the pen with ink" << endl;
	}

	bool Pen::filled() const {
		if (ink == 0)
			return false;
		else
			return true;
	}
	ostream& Pen::display(ostream & os) const {
		if (ink == 0 && style == nullptr)
			os << "This is an empty Pen" << endl;
		else {
			os << "Pen Details" << endl;
			os << "Style: " << style << endl;
			os << "Ink Remaining: " << ink << endl;

		}
		return os;
	}
}