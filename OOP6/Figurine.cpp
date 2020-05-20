// Figurine.cpp
/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: Nov 11th, 2019
---------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include<iomanip>
#include "Figurine.h"



using namespace std;
namespace sdds
{
	Figurine::Figurine() {
		 name[0] = '\0';
		 pose = nullptr;
		 price = 0.0;
	}
	Figurine::Figurine(const char* uname, const char* upose, double p) {
		if (uname == nullptr || uname[0] == '\0' || upose == nullptr || upose[0] == '\0') {
			name[0] = '\0';
			pose = nullptr;
			price = 0.0;
		}
		else {
			//set value for name
			if (strlen(uname) > MAX_NAME_LEN)
				strncpy(name, uname, MAX_NAME_LEN);
			else
				strcpy(name, uname);

			//set value for pose
			pose = new char[strlen(upose) + 1];
			strcpy(pose, upose);

			//set value for price
			if (p < 1)
				price = DEFAULT_PRICE;
			else
			price = p;
		}
	}

	Figurine::Figurine(const Figurine& fig) {

		//Shadow copying the static resource
		strncpy(name, fig.name, MAX_NAME_LEN);
		price = fig.price;

		//Check if pose is empty
		if (fig.pose != nullptr) {
			pose = new char[strlen(fig.pose) + 1];
			int len = strlen(fig.pose);
			for (int i = 0; i < len; i++) {
				pose[i] = fig.pose[i];
			}
			pose[strlen(fig.pose)] = '\0';
		}
		else 
			pose = nullptr;
	}
	void Figurine::setName(const char* uname) {
		strncpy(name, uname, MAX_NAME_LEN + 1);
	}

	void Figurine::setPose(const char* upose) {
		if (pose != nullptr)
			delete[] pose;

		pose = new char[strlen(upose) + 1];
		strcpy(pose, upose);
	}
	void Figurine::setPrice(double p) {
		if (p < 1)
			price = DEFAULT_PRICE;
		else
			price = p;
	}

	ostream& Figurine::display()const {
		if (name[0] == '\0' || pose == nullptr || price == 0.0) {
			cout << "This Figurine has not yet been sculpted" << endl;
		}
		else {
			cout << "Figurine Details" << endl;
			cout << "Name: " << name << endl;
			cout << "Pose: " << pose << endl;
			cout << "Price: " << fixed << setprecision(2) << price << endl;
		}

		return cout;
	}
	Figurine::operator bool()const {
		if (name[0] == '\0' || name == nullptr)
			return true;
		else
			return false;
	}
	Figurine::~Figurine() {
		delete[] pose;
	}
}