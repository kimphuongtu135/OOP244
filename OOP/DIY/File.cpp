/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: Sep 15th, 2019
This is implementation file of File, it contains data file management functions.
*/


#define _CRT_SECURE_NO_WARNINGS
#define MAX_REC_NO 100

#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include "File.h"
#include "Contact.h"
#include "Tools.h"
using namespace std;

namespace sdds
{

	bool readContact(Contact* C, FILE* fptr) {
		return fscanf(fptr, "%[^,],%lld", C->name, &C->phoneNumber) == 2;
	}

	void writeContact(FILE* fptr, const Contact* C) {
		fprintf(fptr, "%s,%lld", C->name, C->phoneNumber);
	}

	int readContacts(Contact* contacts, const char* filename) {
		FILE* fptr = fopen(filename, "r");
		Contact C;
		int num;
		for (num = 0; fptr && num < MAX_REC_NO && readContact(&C, fptr); num++) {
			contacts[num] = C;
		}
		return num;
	}

	void writeContacts(Contact* contacts, int cntno, const char* filename) {
		FILE* fptr = fopen(filename, "w");
		int num;
		for (num = 0; num < cntno; num++) {
			writeContact(fptr, &contacts[num]);
		}
		fclose(fptr);
	}
	
	
}