/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: Sep 15th, 2019
This is implementation file of Contact, it contains all Contact related functions.
*/


#define _CRT_SECURE_NO_WARNINGS
#define MAX_REC_NO 100

#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include "Contact.h"
#include "File.h"
#include "Tools.h"

using namespace std;


namespace sdds
{
	void getContact(Contact* C) {
		cout << "Name: ";
		getName(C->name); // calling getName function
		cout << "Phone Number: ";
		C->phoneNumber = getPhoneNumber(); // set the  new value with the value of getPhoneNumber function return 
	}



	void printContact(const Contact* C) {
		cout << setw(35) << setfill('.') << setiosflags(ios::left) << C->name << C->phoneNumber << endl;
	}


	void printContacts(const Contact* C, int num) {
		for (int i = 0; i < num; i++) {
			printContact(&C[i]);
		}
	}

	void getName(char* name) {
		getStr(name, 30);
	}

	bool nameInContact(const Contact* C, const char* nameSubStr) {
		char name[31];
		char subName[31];
		toLowerCase(name, C->name);
		toLowerCase(subName, nameSubStr);
		return strstr(name, subName) != nullptr;
	}

	long long getPhoneNumber() {
		return getLongLong(1000000000LL, 9999999999LL, "Phone Number");
	}
}