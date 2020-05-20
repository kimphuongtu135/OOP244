/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: OCT 3rd, 2019
---------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include "Flower.h"
#include "utils.h"


using namespace std;
namespace sdds
{


	Flower::Flower() {
		f_name = nullptr;
		f_colour = nullptr;
		f_price = 0.0;
	}

	Flower::Flower(const char* name, const char* colour, double price) {
		if ((name != nullptr && name[0] != '\0') && (price > 0) && (colour != nullptr && colour[0] != '\0') != 0) {

			f_name = new char[strlen(name) + 1];
			strcpy(f_name, name);


			f_colour = new char[strlen(colour) + 1];
			strcpy(f_colour, colour);

			f_price = price;
		}
		else {
			f_name = nullptr;
			f_colour = nullptr;
			f_price = 0.0;
		}
	}
	Flower::~Flower() {

		if (!isEmpty()) {
			cout << f_colour << " " << f_name << " has departed..." << endl;
		}
		else
			cout << "An unknown flower has departed..." << endl;
		delete[] f_name;
		delete[] f_colour;
	}

	const char* Flower::name()const {
		return f_name;
	}
	const char* Flower::colour()const {
		return f_colour;
	}
	double Flower::price()const {
		return f_price;
	}
	bool Flower::isEmpty() const {
		if (f_name == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	void Flower::setEmpty() {
		if (f_name != nullptr) {
			delete[] f_name;
		}
		if (f_colour != nullptr) {
			delete[] f_colour;
		}
		f_name = nullptr;
		f_colour = nullptr;
		f_price = 0.0;
	}
	void Flower::setName(const char* prompt) {

		cout << prompt;
		char name[26];

		read(name, NAME_MAX_LEN, "A flower's name is limited to 25 characters... Try again: ");

		if (f_name != nullptr) {
			delete[]f_name;
		}
		f_name = new char[strlen(name) + 1];
		strcpy(f_name, name);
	}

	void Flower::setColour(const char* prompt) {

		cout << prompt;
		char colour[16];

		read(colour, COL_MAX_LEN, "A flower's colour is limited to 15 characters... Try again: ");

		delete[]f_colour;

		f_colour = new char[strlen(colour) + 1];
		strcpy(f_colour, colour);
	}

	void Flower::setPrice(const char* prompt) {
		bool ok;
		char newline;
		cout << prompt;
		do {
			cin >> f_price;
			newline = cin.get();
			if (cin.fail() || newline != '\n') {
				ok = false;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else {
				ok = f_price > 0.0;
			}
		} while (!ok && cout << "A flower's price is a non-negative number... Try again: ");
	}

	void Flower::setFlower() {
		setName("Beginning the birth of a new flower...\nEnter the flower's name... : ");
		setColour("Enter the flower's colour... : ");
		setPrice("Enter the flower's price... : ");

		cout << "The flower's current details..." << endl;
		display();
	}


	ostream& Flower::display() const {
		if (isEmpty()) {
			cout << "This is an empty flower..." << endl;
		}
		else {
			cout << "Flower: " << f_colour << " " << f_name << " Price: " << f_price << endl;
		}
		return cout;


	}


	void Flower::setName(const char* name1, int len) {

		
		f_name = new char[strlen(name1) + 1];
		strcpy(f_name, name1);
}
	void Flower::setColour(const char* colour1, int len) {
		
	
		f_colour = new char[strlen(colour1) + 1];
		strcpy(f_colour, colour1);
	}

	void Flower::setPrice(double price1) {
		

		if (price1 < 0.0) 
			f_price = 1.0;
		else
			f_price = price1;
	}
}

