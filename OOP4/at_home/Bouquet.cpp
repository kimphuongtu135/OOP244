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
	//Set empty state for Bouquet
	Bouquet::Bouquet() {
		b_price = 0.0;
		b_message = nullptr;
		b_flower = nullptr;
		b_flowerCount = 0;
	}

	Bouquet::Bouquet(const Flower*flower,int numOf,const char* message) {
		double sum=0.0;
	
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

			//Dynamic allocation for message that we can copy the message to b_message
			b_message = new char[strlen(message) + 1];
			strcpy(b_message, message);
		}
		else {
			setEmpty();
		}
	}
	
	

	Bouquet::~Bouquet() {

		if (isEmpty()) {
			cout << "An unknown bouquet has departed..." << endl;
		}
		else {
			cout << "A bouquet has departed with the following flowers..." << endl;
		}
		// Delete dynamic allocation
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
		
		if (b_flower == nullptr || b_message== nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	void Bouquet::setEmpty() {
		// Set whole variable to safe empty state
		b_price = 0.0;
		b_message = nullptr;
		b_flower = nullptr;
		b_flowerCount = 0;
	}
	void Bouquet::setMessage(const char* prompt) {
		cout << prompt;

		char message[MESS_MAX_LEN+1];

		
		read(message, MESS_MAX_LEN, "A bouquets's message (non-empty) is limited to 30 characters... Try again: ");

		// Dynamic allocation for b_message and save the value of message to b_message
		b_message = new char[strlen(message) + 1];
		strcpy(b_message, message);
	}

	void Bouquet::discardBouquet() {

		cout << "Discarding the current bouquet..." << endl;

		delete[] b_message;
		delete[] b_flower;
		setEmpty();
	}
	void Bouquet::arrangeBouquet() {
		
		char yes;
		bool ok = true;
		
		cout << "Arranging a new bouquet..." << endl;

		if (!isEmpty()) {
			cout << "This bouquet has an arrangement currently, discard it? (Y/N): ";
			
			do {
				yes = cin.get();
				cin.ignore(1000, '\n');
				if (yes == 'Y' || yes == 'N')
					ok = true;
			} while (!ok && cout << "The decision is either Y or N... Try again: ");

			if (yes == 'Y') {
				discardBouquet();
			}
			else {
				cout << "No new arrangement performed..." << endl;
			}
		}
		if (isEmpty() || yes=='Y') {
			int val;
			double sum = 0.0;

			cout << "Enter the number of flowers in this bouquet (Valid: 1-3)... : ";

			read(val, 1, MAX_FLOWERS, "The valid range is 1-3... Try again: ");

			b_flowerCount = val;

			// Dynamic allocation b_flower with range based on b_flowerCount valaue
			b_flower = new Flower[b_flowerCount];


			for (int i = 0; i < b_flowerCount; i++) {
				b_flower[i].setFlower();						//calling setFlower function which located in Flower class
				sum += b_flower[i].price();
			}

			b_price = sum;

				cin.clear();

			
			cout << "A bouquet has been arranged..." << endl;
			setMessage("Enter a message to send with the bouquet...: ");
			
		}
		
	}

		ostream& Bouquet::display() const {
			
			if (isEmpty()) {
				cout << "This is an empty bouquet..." << endl;
			}
			else {
				cout << "This bouquet worth " << fixed << setprecision(2)<< b_price << " has the following flowers..." << endl;				//fixed and setprecision(2) help for showing two decimal number of float number
				
				for (int i = 0; i < b_flowerCount; i++) {
					b_flower[i].display();
				}
				cout << "with a message of: " << b_message;
				cout << endl;
			}
			return cout;
		}
}