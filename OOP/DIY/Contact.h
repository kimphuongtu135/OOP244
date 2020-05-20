/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: Sep 15th, 2019
This is header file of Contact, it contains all Contact related prototypes functions.
*/

#define _CRT_SECURE_NO_WARNINGS


#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H



namespace sdds
{
	struct Contact {
		char name[31];
		long long phoneNumber;
	};


void printContact(const Contact* C);

void getContact(Contact* C);

void printContacts(const Contact* C, int num);

void getName(char* name);

bool nameInContact(const struct Contact* C, const char* nameSubStr);

long long getPhoneNumber();
}
#endif