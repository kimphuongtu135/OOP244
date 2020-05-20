/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: Sep 15th, 2019
This is header file of PhoneDir, it contains the user interface functions prototypes.
*/

#define _CRT_SECURE_NO_WARNINGS


#ifndef SDDS_PHONEDIR_H
#define SDDS_PHONEDIR_H
#include "Contact.h"
 
namespace sdds
{

	int menu();

	void sort(Contact c[], int n);

	int search(Contact* found, const Contact* C, const char* name, int noOfRecs);


	void phoneDir(const char* title, const char* filename);

}
#endif