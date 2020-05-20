/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: OCT 3rd, 2019
---------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include <iomanip>
#include "Flower.h"
#include "utils.h"
#include "Bouquet.h"


using namespace std;
namespace sdds
{
	Bouquet::Bouquet() {
		b_price = 0.0;
		b_message = nullptr;
		b_flower = nullptr;
		b_flowerCount = 0;
	}
	Bouquet::Bouquet(const Flower*flower,int numOf,const char* message) {
		double sum=0.0;
		//setEmpty();
		if (flower != nullptr) {
			if (numOf < MAX_FLOWERS) 
				b_flowerCount = numOf;
			
			else 
				b_flowerCount = MAX_FLOWERS;
			

			b_flower = new Flower[b_flowerCount];
			for (int i = 0; i < b_flowerCount; i++) {
				b_flower[i].setName(flower[i].name(), NAME_MAX_LEN);
				b_flower[i].setColour(flower[i].colour(), COL_MAX_LEN);
				b_flower[i].setPrice(flower[i].price());
				sum += flower[i].price();
			}

			b_price = sum;


			b_message = new char(strlen(message) + 1);
			strcpy(b_message, message);
		}
		else {
			setEmpty();
		}
	}
	
	

	Bouquet::~Bouquet() {

		if (isEmpty()) {
			cout << "An unknown flower has departed..." << endl;
		}
		else {
			cout << "A bouquet has departed with the following flowers..." << endl;
		}
		delete[] b_flower;
		delete[] b_message;
		
	}

	const char*Bouquet::message()const {
		return b_message;
	}

	double Bouquet::price()const {
		return b_price;
	}

	bool Bouquet::isEmpty()const {
		
		if (b_flower == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	void Bouquet::setEmpty() {
		if (b_flower != nullptr) {
			delete[] b_flower;
		}
		
		b_price = 0.0;
		b_message = nullptr;
		b_flower = nullptr;
		b_flowerCount = 0;
	}
	void Bouquet::setMessage(const char* prompt) {
		cout << prompt;
		char message[31];

		read(message, MESS_MAX_LEN, "A bouquets's message (non-empty) is limited to 30 characters... Try again: ");

		b_message = new char[strlen(message) + 1];
		strcpy(b_message, message);
	}

	void Bouquet::discardBouquet() {
		delete[] b_message;
		delete[] b_flower;
		setEmpty();
		cout << "Discarding the current bouquet..." << endl;
	}
	void Bouquet::arrangeBouquet() {
		char yes;
		cout << "Arranging a new bouquet..." << endl;
		if (!isEmpty()) {
			bool success = true;
			while (success == true) {
				cout << "This bouquet has an arrangement currently, discard it? (Y/N): ";
				cin >> yes;
				if (cin.fail()) {
					cin.clear();
					setEmpty();
				}
				else {
					success = false;
				}
			}

			if (yes != 'Y' || yes != 'N') {
				cout << "The decision is either Y or N... Try again: ";
			}
			if (yes == 'Y') {
				discardBouquet();
			}
			else {
				cout << "No new arrangement performed..." << endl;
			}
		}
		if (isEmpty()) {
			int val;
			double sum = 0.0;

			cout << "Enter the number of flowers in this bouquet(Valid: 1 - 3)... : ";

			read(val, 1, MAX_FLOWERS, "The valid range is 1-3... Try again: ");

			b_flowerCount = val;
			b_flower = new Flower[b_flowerCount];
			for (int i = 0; i < b_flowerCount; i++) {
				b_flower[i].setFlower();
				sum += b_flower[i].price();
			}
			b_price = sum;

			if (cin.fail()) {
				cin.clear();
				setEmpty();

			}
			cout << "A bouquet has been arranged..." << endl;
			setMessage("Enter a message to send with the bouquet...: ");
			
		}
		
	}

		ostream& Bouquet::display() const {
			
			if (isEmpty()) {
				cout << "This is an empty flower..." << endl;
			}
			else {
				cout << "This bouquet worth " << fixed << setprecision(2)<< b_price << " has the following flowers..." << endl;
				for (int i = 0; i < b_flowerCount; i++) {
					b_flower[i].display();
				}
				cout << "with a message of: " << b_message;
				cout << endl;
			}
			return cout;
		}
}