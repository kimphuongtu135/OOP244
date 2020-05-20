
/*-------------------------
Name: Kim Phuong Tu
Student Number: 148886179
Date: Sep 15th, 2019
This contains the main functions.
*/


#define _CRT_SECURE_NO_WARNINGS
#define MAX_REC_NO 100

#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include "Contact.h"
#include "Tools.h"
#include "File.h"
#include "PhoneDir.h"
using namespace std;
using namespace sdds; // calling the namespace sdds



int main() {
	phoneDir("SDDS Phone Directory", "phones.txt");
	return 0;
}
