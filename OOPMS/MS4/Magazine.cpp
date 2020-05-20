/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: Nov 27th, 2019
---------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include<iomanip>
#include "Utils.h"
#include "Magazine.h"
#include "PubRecord.h"

using namespace std;
namespace sdds {

	Magazine::Magazine() {
		volume = 0;
		noIssue = 0;
	}

	Magazine::Magazine(const Magazine& mag) : PubRecord(mag){
		
		volume = mag.volume;
		noIssue = mag.noIssue;

	}
	Magazine::~Magazine() {

	}
	Magazine& Magazine::operator= (const Magazine& mag) {
		PubRecord::operator=(mag);
		volume = mag.volume;
		noIssue = mag.noIssue;

		return *this;
	}
	char Magazine::recID()const {
		return 'M';
	}
	void Magazine::checkIn() {
		cout << "Magazines cannot be checked in or out!" << endl;
	}
	void Magazine::checkOut() {
		cout << "Magazines cannot be checked in or out!" << endl;
	}
	std::istream& Magazine::read(std::istream& is ) {
		if (mediaType() == SDDS_CONSOLE) {
			char temp2[41];
			int vol;
			int issu;
			cout << "Magazine Name: ";
			read1(temp2, 40, "Magazine name too long, Enter again: ");


			cout << "Volume: ";
			vol = read2(1, 99, "Invalid Volume number, Enter again: ");

			cout << "Issue: ";
			issu = read2(1, 99, "Invalid Issue number, Enter again: ");

			cout << "Shelf Number: ";
			readShelfNo();

			name(temp2);
			volume = vol;
			noIssue = issu;
		}
		else if (mediaType() == SDDS_FILE) {
			char temp[41];
			int vol;
			int issu;
			int shelf;
			is.getline(temp, 40, '\t');

			is >> vol;
			is.ignore();

			is >> issu;
			is.ignore();

			is >> shelf;
			is.ignore(1000,'\n');

			if (is.fail())
			{
				cout << " Magazine string is invalid" << temp << "****" << vol << "****" << issu << "****" << shelf << endl;
				is.clear();
				is.ignore(3000, '\n');
			}
			else {
				name(temp);
				volume = vol;
				noIssue = issu;
				shelfNo(shelf);
			}
		}
		else {
			cout << "No define media type" << endl;
		}
		return is;
	}
	std::ostream& Magazine::write(std::ostream& os ) const {
		if (mediaType() == SDDS_CONSOLE) {
			os.fill(' ');
			os.width(41);
			os << std::left << name();

			os << "       ";
			os.fill('0');
			os.width(2);
			os << std::right << volume;

			os << "(";

			os.width(2);
			os << std::right << noIssue;

			os << ")  ";

			os << shelfNo();
			os.fill(' ');
		}
		else if (mediaType() == SDDS_FILE) {
			os << recID() << name() << "\t" << volume << "\t" << noIssue << "\t" << shelfNo() << endl;
		}
		else {
			os << "No media type defined!" << endl;
		}
		return os;
	}
}