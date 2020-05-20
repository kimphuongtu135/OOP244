/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: Sep 15th, 2019
This is header file of File, it contains data file management functions prototypes.
*/

#define _CRT_SECURE_NO_WARNINGS


#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include "Contact.h"

namespace sdds
{

	bool readContact(Contact* C, FILE* fptr);

	void writeContact(FILE* fptr, const Contact* C);

	int readContacts(Contact* contacts, const char* filename);

	void writeContacts(Contact* contacts, int cntno, const char* filename);




}
#endif
