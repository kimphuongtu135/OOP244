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
#include "Book.h"
#include "PubRecord.h"

using namespace std;
namespace sdds {

	Book::Book() {
		ISBN = 0;
		id = 0;

	}

	Book::Book(const Book& bk) : PubRecord(bk) {
		
		ISBN = bk.ISBN;
		id = 0;
	}
	Book::~Book() {

	}

	Book& Book::operator= (const Book& bk) {
		PubRecord::operator=(bk);
		ISBN = bk.ISBN;
		id = 0;
		date = bk.date;
		return *this;
	}
	char Book::recID()const {
		return 'B';

	}

	int Book::memberId()const {
		return id;
	}
	void Book::checkIn() {
		id = 0;
		cout << *this;
		cout << " checked in!" << endl;
	}
	void Book::checkOut() {
		int tempId;
		cout << "Enter Member id: ";
		tempId = read2(10000, 99999, "Invalid Member ID, Enter again: ");
		id = tempId;

		cout << "Enter return date: ";
		cin >> date;
		while (date.errCode() != NO_ERROR) {
			cout << date.dateStatus() << "." << endl;
			cin >> date;
		}

		Date today;
		while ((date - today) < 0) {
			cout << "Please enter a future date.";
			

			cout << "Enter return date: ";
			cin >> date;
			while (date.errCode() != NO_ERROR) {
				cout << date.dateStatus() << "." << endl;
				cin >> date;
			}
		}

		while ((date - today) > 30) {
			cout << "The return date must be earlier than 30 days away from today.";
			cin >> date;
		}

	}
	std::istream& Book::read(std::istream& is) {
		if (mediaType() == SDDS_CONSOLE) {
			id = 0;
			char temp2[41];
			long long int tempIsbn;
			cout << "Book Name: ";
			read1(temp2, 40, "Book name too long, Enter again: ");
			name(temp2);

			cout << "ISBN: ";
			tempIsbn = read2(1,9999999999999, "Invalid ISBN, Enter again: ");
			ISBN = tempIsbn;

			cout << "Shelf Number: ";
			readShelfNo();
		}
		else if (mediaType() == SDDS_FILE) {
			char temp[41];
			long long int tempIsbn;
			int tempId;
			int shelf;
			is.getline(temp, 40, '\t');

			is >> tempIsbn;
			is.ignore();

			is >> shelf;
			is.ignore();

			is >> tempId;
			//is.ignore();

			if (is.fail())
			{
				cout << "Book string is invalid" << temp << endl;
				is.clear();
				is.ignore(3000, '\n');
			}
			else {
				name(temp);
				ISBN = tempIsbn;
				id = tempId;
				shelfNo(shelf);
			}

			if (tempId == 0) {
				is.ignore();
				id = tempId;
			}
			else {
				id = tempId;
				is.ignore();
				is >> date;
			}
		}
		else {
			cout << "No define media type" << endl;
		}
		return is;
	}
	std::ostream& Book::write(std::ostream& os) const {
		if (mediaType() == SDDS_CONSOLE) {
			os.fill(' ');
			os.width(41);
			os << std::left << name();


			os.fill('0');
			os.width(13);
			os << std::right << ISBN;

			os << "  ";
			os << shelfNo();
			os.fill(' ');

			if (id != 0) {
				os << " ";
				os.fill('0');
				os.width(5);
				os << std::right << id;
				os << "   " << date;
			}
		}
		else if (mediaType() == SDDS_FILE) {
			os << recID();
			os << name();
			os << "\t";
			os << ISBN;
			os << "\t";
			os << shelfNo();
			os << "\t";
			os << id;
			if (id != 0) {
				os << "\t";
				os << date;
			}
			os << endl;
		}
		else {
			os << "No media type defined!" << endl;
		}
		return os;

	}
}