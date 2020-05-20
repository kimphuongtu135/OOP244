/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: Nov 27th, 2019
---------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include<iomanip>
#include "PubRecord.h"

using namespace std;
namespace sdds
{
	void PubRecord::name(const char*name1) {
		nameOfPub = new char[strlen(name1) + 1]; 
		strcpy(nameOfPub, name1);
		nameOfPub[strlen(name1)] = '\0';
	}
	const char* PubRecord::name()const {
		return nameOfPub;
	}
	PubRecord::PubRecord() {
		nameOfPub = nullptr;
		noOfPub = 0;
		type = 0;

	}

	PubRecord::~PubRecord() {
		delete[] nameOfPub;
	}
	PubRecord& PubRecord::operator=(const PubRecord&pub) {
		if (this != &pub) {
			delete[] nameOfPub;
			noOfPub = pub.noOfPub;
			type = pub.type;
			nameOfPub = new char[strlen(pub.nameOfPub) + 1];
			int length = strlen(pub.nameOfPub);
			for (int i = 0; i <length ; i++)
				nameOfPub[i] = pub.nameOfPub[i];
		}
		
		return *this;
	}

	void PubRecord::mediaType(int media) {
		if (media == SDDS_CONSOLE)
			type = SDDS_CONSOLE;
		if (media == SDDS_FILE)
			type = SDDS_FILE;
		else
			type = 0;

	}
	int PubRecord::mediaType()const {
		return type;
	}

	int PubRecord::shelfNo()const {
		return noOfPub;
	}

	int PubRecord::readShelfNo() {
		int digit;
		bool ok;
		char newline;
		do {
			cin >> digit;
			newline = cin.get();
			if (cin.fail() || newline != '\n') {
				ok = false;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else {
				ok = digit <=3 && digit >= 0;
			}
		} while (!ok && cout << "Invalid Shelf Number, Enter again : " );
		return digit;
	}
	bool PubRecord::operator==(char value)const {
		return (recID() == value);
	}
	bool PubRecord::operator==(const char* value)const {
		if (strstr(nameOfPub, value) == nullptr)
			return false;
		else
			return true;
	}

	PubRecord::operator bool()const {
		return(noOfPub != 0);
	}
}

