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
#include "Utils.h"

using namespace std;
namespace sdds
{
	PubRecord::PubRecord() {
		nameOfPub = nullptr;
		noOfPub = 0;
		type = 0;

	}

	PubRecord::PubRecord(const PubRecord& pub) {
		name(pub.name());
		type = pub.mediaType();
		noOfPub = pub.shelfNo();
	}

	PubRecord::~PubRecord() {
		delete[] nameOfPub;
	
	}
	void PubRecord::name(const char*name1) {
		if (name1==nullptr) {
			nameOfPub = nullptr;
		}
			else {
				nameOfPub = new char[strlen(name1) + 1];
				strcpy(nameOfPub, name1);
				nameOfPub[strlen(name1)] = '\0';
			}
		
	}
	const char* PubRecord::name()const {
		return nameOfPub;
	}
	

	
	PubRecord& PubRecord::operator=(const PubRecord&pub) {
		if (this != &pub) {
			delete[] nameOfPub;
			noOfPub = pub.shelfNo();
			type = pub.mediaType();
			nameOfPub = new char[strlen(pub.name()) + 1];
			strcpy(nameOfPub, pub.name());
			nameOfPub[strlen(pub.name())] = '\0';

		}
		
		return *this;
	}

	void PubRecord::mediaType(int media) {
		type = media;

	}
	int PubRecord::mediaType()const {
		return type;
	}

	int PubRecord::shelfNo()const {
		return noOfPub;
	}

	void PubRecord::readShelfNo() {
		noOfPub= sdds::read(100, 999, "Invalid Shelf Number, Enter again: ");
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
		return(nameOfPub != 0);
	}
}

